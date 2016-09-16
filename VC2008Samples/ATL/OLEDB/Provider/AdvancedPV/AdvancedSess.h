// AdvancedSess.h : Declaration of the CAdvancedSession
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#pragma once

#include "resource.h"       // main symbols
#include "AdvancedRS.h"

class CAdvancedSessionTRSchemaRowset;
class CAdvancedSessionColSchemaRowset;
class CAdvancedSessionPTSchemaRowset;

#define array_count(x) sizeof(x)/sizeof(x[0])
// CAdvancedSession
class ATL_NO_VTABLE CAdvancedSession : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IGetDataSourceImpl<CAdvancedSession>,
	public IOpenRowsetImpl<CAdvancedSession>,
	public ISessionPropertiesImpl<CAdvancedSession>,
	public IObjectWithSiteSessionImpl<CAdvancedSession>,
	public IDBSchemaRowsetImpl<CAdvancedSession>,
	public IDBCreateCommandImpl<CAdvancedSession, CAdvancedCommand>
{
public:
	CAdvancedSession()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return FInit();
	}
	
	void FinalRelease() 
	{
	}

	STDMETHOD(OpenRowset)(IUnknown *pUnk, DBID *pTID, DBID *pInID, REFIID riid,
					   ULONG cSets, DBPROPSET rgSets[], IUnknown **ppRowset)
	{
		CAdvancedRowset* pRowset;
		return CreateRowset(pUnk, pTID, pInID, riid, cSets, rgSets, ppRowset, pRowset);
	}

	void SetRestrictions(ULONG cRestrictions, GUID* rguidSchema, ULONG* rgRestrictions)
	{
		for (ULONG l=0; l<cRestrictions; l++)
		{
			// We support restrictions on the table name but nothing else
			if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_TABLES))
				rgRestrictions[l] = 0x04;
			else if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_COLUMNS))
				rgRestrictions[l] = 0x04;
			else if (InlineIsEqualGUID(rguidSchema[l], DBSCHEMA_PROVIDER_TYPES))
				rgRestrictions[l] = 0x00;
		}
	}

BEGIN_PROPSET_MAP(CAdvancedSession)
	BEGIN_PROPERTY_SET(DBPROPSET_SESSION)
		PROPERTY_INFO_ENTRY(SESS_AUTOCOMMITISOLEVELS)
	END_PROPERTY_SET(DBPROPSET_SESSION)
END_PROPSET_MAP()

BEGIN_COM_MAP(CAdvancedSession)
	COM_INTERFACE_ENTRY(IGetDataSource)
	COM_INTERFACE_ENTRY(IOpenRowset)
	COM_INTERFACE_ENTRY(ISessionProperties)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IDBCreateCommand)
	COM_INTERFACE_ENTRY(IDBSchemaRowset)
END_COM_MAP()

BEGIN_SCHEMA_MAP(CAdvancedSession)
	SCHEMA_ENTRY(DBSCHEMA_TABLES, CAdvancedSessionTRSchemaRowset)
	SCHEMA_ENTRY(DBSCHEMA_COLUMNS, CAdvancedSessionColSchemaRowset)
	SCHEMA_ENTRY(DBSCHEMA_PROVIDER_TYPES, CAdvancedSessionPTSchemaRowset)
END_SCHEMA_MAP()

};

class CAdvancedSessionTRSchemaRowset : 
	public CSchemaRowsetImpl< CAdvancedSessionTRSchemaRowset, CTABLESRow, CAdvancedSession>
{
public:
BEGIN_PROPSET_MAP(CAdvancedSessionTRSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions, 
				const VARIANT* rgRestrictions)
	{
		USES_CONVERSION;
		CTABLESRow trData;
		FILE* pFile = NULL;
		TCHAR szFile[255];
		bool bNameSet = false;

		// Handle any restrictions sent to us.  We only handle
		// the TABLE_NAME & TABLE_TYPE restictions (the 3rd and 4th 
		// restrictions in DBSCHEMA_TABLES...look in IDBSchemaRowsets 
		// in part 2 of the prog. ref) so our restrictions are 0x08 & 0x04 
		// for a total of (0x0C)
		if (cRestrictions >= 3 && rgRestrictions[2].vt != VT_EMPTY)
		{
			CComBSTR bstrName = rgRestrictions[2].bstrVal;
			if ((rgRestrictions[2].vt == VT_BSTR) && (bstrName != (BSTR)NULL))
			{
				// Check to see if the file exists
				_tcscpy_s(szFile, array_count(szFile), COLE2T(bstrName));
				if (szFile[0] == _T('\0') || (_tfopen_s(&pFile, szFile, _T("r")) != 0))
				{
					return S_OK;	// Their restriction was invalid return no data
				}
				else
				{
					fclose(pFile);
					bNameSet = true;
				}
			}
		}

		// TABLE_TYPE restriction
		if (cRestrictions >=4 && rgRestrictions[3].vt != VT_EMPTY)
		{
			CComBSTR bstrType = rgRestrictions[3].bstrVal;
			if ((rgRestrictions[3].vt == VT_BSTR) && (bstrType != (BSTR)NULL))
			{
				// This is kind of a blind restriction.  We only really support
				// TABLES so if we get anything else, we just return an empty
				// rowset
				if (_tcscmp(_T("TABLE"), COLE2T(bstrType)) != 0)
					return S_OK;
			}
		}
		
		// The user didn't specify a TABLE_NAME restriction
		if (bNameSet == false)
		{
			// Use the property in DBPROP_INIT_CATALOG.  To do so first call
			// IGetDataSource::GetDataSource for the pointer to the data
			// source object's IDBProperties interface
			CComPtr<IGetDataSource> spGetSource;
			CComPtr<IDBProperties> spProps;
			CDBPropIDSet set(DBPROPSET_DBINIT);
			set.AddPropertyID(DBPROP_INIT_CATALOG);
			DBPROPSET* pPropSet = NULL;
			ULONG ulPropSet = 0;

			// Get a pointer back to our session object
			HRESULT hr = GetSite(__uuidof(IGetDataSource), (void**)&spGetSource);
			if (FAILED(hr))
				return hr;
			
			// Now get a pointer to the IDBProperties interface on the data source
			hr = spGetSource->GetDataSource(__uuidof(IDBProperties), (IUnknown**)&spProps);
			if (FAILED(hr))
				return hr;

			hr = spProps->GetProperties(1, &set, &ulPropSet, &pPropSet);
			if (FAILED(hr))
				return hr;

			if (pPropSet != NULL)
			{
				CComVariant varCatalog = pPropSet->rgProperties[0].vValue;
				_tcscpy_s(szFile, array_count(szFile), COLE2T(varCatalog.bstrVal));
				::CoTaskMemFree(pPropSet->rgProperties);
				::CoTaskMemFree(pPropSet);
			}
			else
				_tcscpy_s(szFile, array_count(szFile),
					  _T(""));
		}


		// Bring over the data
		wcscpy_s(trData.m_szType, 129, OLESTR("TABLE"));
		wcscpy_s(trData.m_szDesc, 129, OLESTR("The Directory Table"));
		wcsncpy_s(trData.m_szTable, 129, CT2OLE(szFile), _TRUNCATE);

		_ATLTRY
		{
			m_rgRowData.Add(trData);
		}
		_ATLCATCHALL()
		{
			return E_OUTOFMEMORY;
		}
		//if (!m_rgRowData.Add(trData))
		//	return E_OUTOFMEMORY;
		*pcRowsAffected = 1;
		return S_OK;
	}

	virtual DBSTATUS GetDBStatus(CSimpleRow* , ATLCOLUMNINFO* pColInfo)
	{
		ATLENSURE(pColInfo != NULL);

		switch(pColInfo->iOrdinal)
		{
		case 3:
		case 4:
		case 6:
			return DBSTATUS_S_OK;
			break;
		default:
			return DBSTATUS_S_ISNULL;
			break;
		}
	}
};


class CAdvancedSessionColSchemaRowset : 
	public CSchemaRowsetImpl< CAdvancedSessionColSchemaRowset, CCOLUMNSRow, CAdvancedSession>
{
public:
BEGIN_PROPSET_MAP(CAdvancedSessionColSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG cRestrictions, 
				const VARIANT* rgRestrictions)
	{

		USES_CONVERSION;
		CCOLUMNSRow* trData = NULL;
		FILE* pFile = NULL;
		TCHAR szFile[255];
		bool bNameSet = false;

		trData = new CCOLUMNSRow[5];

		// Note, we don't describe the bookmark column here because it may or may
		// not be returned.

		// Handle any restrictions sent to us.  Note, we only handle
		// the TABLE_NAME restiction 
		if (cRestrictions >= 3 && rgRestrictions[2].vt != VT_EMPTY)
		{
			CComBSTR bstrName = rgRestrictions[2].bstrVal;
			if ((rgRestrictions[2].vt == VT_BSTR) && (bstrName != (BSTR)NULL))
			{
				// Check to see if the file exists
				_tcscpy_s(szFile, array_count(szFile), COLE2T(bstrName));
				if (szFile[0] == _T('\0') || (_tfopen_s(&pFile, szFile, _T("r")) != 0))
				{
					return S_OK;	// Their restriction was invalid return no data
				}
				else
				{
					fclose(pFile);
					bNameSet = true;
				}
			}
		}

		// The user didn't specify a TABLE_NAME restriction
		if (bNameSet == false)
			_tcscpy_s(szFile, array_count(szFile), _T("C:\\public\\DataFile.dat")); // modify the path to point to your default data file


		// Setup column names
		wcscpy_s(trData[0].m_szColumnName, 129, OLESTR("Fixed"));
		wcscpy_s(trData[1].m_szColumnName, 129, OLESTR("Command"));
		wcscpy_s(trData[2].m_szColumnName, 129, OLESTR("Text"));
		wcscpy_s(trData[3].m_szColumnName, 129, OLESTR("Command2"));
		wcscpy_s(trData[4].m_szColumnName, 129, OLESTR("Text2"));

		// Set up description columns
		wcscpy_s(trData[0].m_szDescription, 129, OLESTR("Fixed"));
		wcscpy_s(trData[1].m_szDescription, 129, OLESTR("Command"));
		wcscpy_s(trData[2].m_szDescription, 129, OLESTR("Text"));
		wcscpy_s(trData[3].m_szDescription, 129, OLESTR("Command2"));
		wcscpy_s(trData[4].m_szDescription, 129, OLESTR("Text2"));
		// Set up column names
		long l;
		for (l=0; l<=4; l++)
			wcscpy_s(trData[l].m_szTableName, 129, CT2OLE(szFile));

		// Set up column 1
		trData[0].m_ulOrdinalPosition = 1;
		trData[0].m_bIsNullable = VARIANT_FALSE;
		trData[0].m_bColumnHasDefault = VARIANT_TRUE;
		trData[0].m_nDataType = DBTYPE_UI4;
		trData[0].m_nNumericPrecision = 10;
		trData[0].m_ulColumnFlags = DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISFIXEDLENGTH;
		wcscpy_s(trData[0].m_szColumnDefault, 129, OLESTR("0"));
		m_rgRowData.Add(trData[0]);

		// Fill out common fields between columns
		for (l=1; l<=4; l++)
		{
			trData[l].m_ulOrdinalPosition = l+1;
			trData[l].m_bIsNullable = VARIANT_TRUE;
			trData[l].m_bColumnHasDefault = VARIANT_TRUE;
			trData[l].m_ulCharMaxLength = 16;
			trData[l].m_ulCharOctetLength = 16;
			trData[l].m_ulColumnFlags = DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE;
			trData[l].m_nDataType = DBTYPE_STR;
			wcscpy_s(trData[l].m_szColumnDefault, 129, OLESTR("Default"));

			// Add to the row data									   
			m_rgRowData.Add(trData[l]);
		}

		delete[] trData;
		*pcRowsAffected = 5;		// for the five columns

		return S_OK;

	}

	virtual DBSTATUS GetDBStatus(CSimpleRow* pRow, ATLCOLUMNINFO* pColInfo)
	{
		ATLENSURE(pColInfo != NULL);

		switch(pColInfo->iOrdinal)
		{
		case 3:		// TABLE_NAME
		case 4:		// COLUMN_NAME
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			return DBSTATUS_S_OK;
			break;

		case 14:	// CHARACTER_MAXIMUM_LENGTH
		case 15:	// CHARACTER_OCTET_LENGTH
			// The first column is fixed so we return a NULL for the character &
			// octet lengths
			if (pRow->m_iRowset == 0)
				return DBSTATUS_S_ISNULL;
			else
				return DBSTATUS_S_OK;
			break;

		case 16:	// NUMERIC_PRECISION
			if (pRow->m_iRowset == 0)
				return DBSTATUS_S_OK;
			else
				return DBSTATUS_S_ISNULL;
			break;

		case 28:
			return DBSTATUS_S_OK;
			break;
		default:
			return DBSTATUS_S_ISNULL;
			break;
		}
	}
};

class CAdvancedSessionPTSchemaRowset : 
	public CSchemaRowsetImpl< CAdvancedSessionPTSchemaRowset, CPROVIDER_TYPERow, CAdvancedSession>
{
public:
BEGIN_PROPSET_MAP(CAdvancedSessionPTSchemaRowset)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()

	HRESULT Execute(DBROWCOUNT* pcRowsAffected, ULONG, const VARIANT*)
	{
		USES_CONVERSION;
		CPROVIDER_TYPERow trData[2];

		memset(&trData[0], 0, sizeof(CPROVIDER_TYPERow) * 2);

		wcscpy_s(trData[0].m_szName, 129, OLESTR("String"));
		trData[0].m_nType = DBTYPE_STR;
		trData[0].m_ulSize = 16;
		trData[0].m_bIsLong = VARIANT_FALSE;
		trData[0].m_bIsNullable = VARIANT_FALSE;
		trData[0].m_bCaseSensitive = VARIANT_FALSE;
		trData[0].m_ulSearchable = DB_UNSEARCHABLE;
		trData[0].m_bBestMatch = VARIANT_TRUE;	// required for SQL Server DTS

		m_rgRowData.Add(trData[0]);

		wcscpy_s(trData[1].m_szName, 129, OLESTR("Long"));
		trData[1].m_nType = DBTYPE_UI4;
		trData[1].m_ulSize = 4;
		trData[1].m_bIsLong = VARIANT_FALSE;
		trData[1].m_bIsNullable = VARIANT_FALSE;
		trData[1].m_bCaseSensitive = VARIANT_FALSE;
		trData[1].m_ulSearchable = DB_UNSEARCHABLE;
		trData[1].m_bBestMatch = VARIANT_TRUE;	// required for SQL Server DTS

		m_rgRowData.Add(trData[1]);
		
		*pcRowsAffected = 2;
		return S_OK;
	}

	virtual DBSTATUS GetDBStatus(CSimpleRow* , ATLCOLUMNINFO* pColInfo)
	{
		ATLENSURE(pColInfo != NULL);

		switch(pColInfo->iOrdinal)
		{
		case 1:		// TYPE_NAME
		case 2:		// DATA_TYPE
		case 3:		// COLUMN_SIZE
		case 7:		// IS_NULLABLE
		case 8:		// CASE_SENSITIVE
		case 9:		// SEARCHABLE
		case 19:	// IS_LONG
		case 20:	// BEST_MATCH
			return DBSTATUS_S_OK;
			break;
		default:
			return DBSTATUS_S_ISNULL;
			break;
		}
	}
};

