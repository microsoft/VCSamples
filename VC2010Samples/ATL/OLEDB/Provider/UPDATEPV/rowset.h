// rowset.h : Declaration of the RUpdateRowset
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#ifndef __RUpdateRowset_H_
#define __RUpdateRowset_H_
#include <stdio.h>
#include "resource.h"       // main symbols
#include "rowscrll.h"


///////////////////////////////////////////////////////////////////////////
// Forward declarations

class RUpdateRowset;
class CUpdateCommand;

///////////////////////////////////////////////////////////////////////////
// Definitions

#define ADD_COLUMN_ENTRY(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member) \
	_rgColumns[ulCols].pwszName = (LPOLESTR)name; \
	_rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \
	_rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \
	_rgColumns[ulCols].dwFlags = 0; \
	_rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \
	_rgColumns[ulCols].wType = (DBTYPE)type; \
	_rgColumns[ulCols].bPrecision = (BYTE)precision; \
	_rgColumns[ulCols].bScale = (BYTE)scale; \
	_rgColumns[ulCols].cbOffset = offsetof(dataClass, member); \
	memset(&(_rgColumns[ulCols].columnid), 0, sizeof(DBID)); \
	_rgColumns[ulCols].columnid.uName.pwszName = (LPOLESTR)name;

#define ADD_COLUMN_ENTRY_EX(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member, flags) \
	_rgColumns[ulCols].pwszName = (LPOLESTR)name; \
	_rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \
	_rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \
	_rgColumns[ulCols].dwFlags = flags; \
	_rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \
	_rgColumns[ulCols].wType = (DBTYPE)type; \
	_rgColumns[ulCols].bPrecision = (BYTE)precision; \
	_rgColumns[ulCols].bScale = (BYTE)scale; \
	_rgColumns[ulCols].cbOffset = offsetof(dataClass, member); \
	memset(&(_rgColumns[ulCols].columnid), 0, sizeof(DBID)); \
	_rgColumns[ulCols].columnid.uName.pwszName = (LPOLESTR)name;


///////////////////////////////////////////////////////////////////////////
// class CAgentMan

#define array_count(x) sizeof(x)/sizeof(x[0])

class CAgentMan
{
public:
	CAgentMan()
	{
		dwCommandStatus = DBSTATUS_S_OK;
		dwTextStatus = DBSTATUS_S_OK;
		dwCommand2Status = DBSTATUS_S_OK;
		dwText2Status = DBSTATUS_S_OK;
	}

	DBBKMARK dwBookmark;
	TCHAR szCommand[17];
	TCHAR szText[17];
	TCHAR szCommand2[17];
	TCHAR szText2[17];
	DWORD dwFixed;

	DWORD dwCommandStatus;
	DWORD dwTextStatus;
	DWORD dwCommand2Status;
	DWORD dwText2Status;

	static ATLCOLUMNINFO* GetColumnInfo(RUpdateRowset* pThis, DBORDINAL* pcCols);
	static ATLCOLUMNINFO* GetColumnInfo(CUpdateCommand* pThis, DBORDINAL* pcCols);
};


///////////////////////////////////////////////////////////////////////////
// class CUpdateCommand

class ATL_NO_VTABLE CUpdateCommand : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IAccessorImpl<CUpdateCommand>,
	public ICommandTextImpl<CUpdateCommand>,
	public ICommandPropertiesImpl<CUpdateCommand>,
	public IObjectWithSiteImpl<CUpdateCommand>,
	public IConvertTypeImpl<CUpdateCommand>,
	public IColumnsInfoImpl<CUpdateCommand>,
	public IInternalCommandConnectionImpl<CUpdateCommand>
{
public:
BEGIN_COM_MAP(CUpdateCommand)
	COM_INTERFACE_ENTRY(ICommand)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IAccessor)
	COM_INTERFACE_ENTRY(ICommandProperties)
	COM_INTERFACE_ENTRY2(ICommandText, ICommand)
	COM_INTERFACE_ENTRY(IColumnsInfo)
	COM_INTERFACE_ENTRY(IConvertType)
	COM_INTERFACE_ENTRY(IInternalConnection)
END_COM_MAP()
// ICommand
public:
	HRESULT FinalConstruct()
	{
		HRESULT hr = CConvertHelper::FinalConstruct();
		if (FAILED (hr))
			return hr;
		hr = IAccessorImpl<CUpdateCommand>::FinalConstruct();
		if (FAILED(hr))
			return hr;
		return CUtlProps<CUpdateCommand>::FInit();
	}
	void FinalRelease()
	{
		IAccessorImpl<CUpdateCommand>::FinalRelease();
	}
	HRESULT WINAPI Execute(IUnknown * pUnkOuter, REFIID riid, DBPARAMS * pParams, 
						  DBROWCOUNT * pcRowsAffected, IUnknown ** ppRowset);
	static ATLCOLUMNINFO* GetColumnInfo(CUpdateCommand* pv, DBORDINAL* pcInfo)
	{
		return CAgentMan::GetColumnInfo(pv,pcInfo);
	}

	///////////////////////////////////////////////////////////////////////
	// OLE DB Conformance Test Functions:  Necessary for compliance

	virtual HRESULT	IsValidValue(ULONG /*iCurSet*/, DBPROP* pDBProp)
	{
		ATLENSURE(pDBProp != NULL);
		DWORD dwPropertyID = pDBProp->dwPropertyID;
		CComVariant var = pDBProp->vValue;

		if (var.vt == VT_BOOL)
		{
			if (var.boolVal != VARIANT_TRUE && var.boolVal != VARIANT_FALSE)
				return S_FALSE;
		}

		// Check our own properties
		switch(dwPropertyID)
		{
		case DBPROP_MAXOPENROWS:
		case DBPROP_MAXROWS:
			{
				if (var.lVal < 0)	// it doesn't make sense to set rows to < 0
				{
					return S_FALSE;
				}
			}
			break;
		default:
			break;
		}

		return S_OK;
	}

BEGIN_PROPSET_MAP(CUpdateCommand)
	BEGIN_PROPERTY_SET(DBPROPSET_ROWSET)
		PROPERTY_INFO_ENTRY(IAccessor)
		PROPERTY_INFO_ENTRY(IColumnsInfo)
		PROPERTY_INFO_ENTRY(IConvertType)
		PROPERTY_INFO_ENTRY(IRowset)
		PROPERTY_INFO_ENTRY(IRowsetIdentity)
		PROPERTY_INFO_ENTRY(IRowsetInfo)
		PROPERTY_INFO_ENTRY_VALUE(IRowsetLocate, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY_VALUE(IRowsetScroll, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY_VALUE(BOOKMARKS, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY_EX(BOOKMARKSKIPPED, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, 0, 0)
		PROPERTY_INFO_ENTRY_EX(BOOKMARKTYPE, VT_I4, DBPROPFLAGS_ROWSET| DBPROPFLAGS_READ, DBPROPVAL_BMK_NUMERIC, 0)
		PROPERTY_INFO_ENTRY(CANFETCHBACKWARDS)
		PROPERTY_INFO_ENTRY(CANHOLDROWS)
		PROPERTY_INFO_ENTRY(CANSCROLLBACKWARDS)
		PROPERTY_INFO_ENTRY_EX(LITERALBOOKMARKS, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE, VARIANT_TRUE, 0)
		PROPERTY_INFO_ENTRY_EX(ORDEREDBOOKMARKS, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ | DBPROPFLAGS_WRITE, VARIANT_TRUE, 0)
		PROPERTY_INFO_ENTRY_VALUE(IRowsetChange, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY_VALUE(UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE)
		PROPERTY_INFO_ENTRY_VALUE(MAXOPENROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXROWS, 0)
		PROPERTY_INFO_ENTRY_VALUE(MAXPENDINGROWS, 0) // For IRowsetDelete conformance test bugs
		PROPERTY_INFO_ENTRY_VALUE(CHANGEINSERTEDROWS, VARIANT_TRUE) // IRowsetChange
		PROPERTY_INFO_ENTRY_VALUE(IMMOBILEROWS, VARIANT_TRUE)		// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(OWNINSERT, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_TRUE, 0)			// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(OWNUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_TRUE, 0)	// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(OTHERINSERT, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_FALSE, 0)		// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(OTHERUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_FALSE, 0)	// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(REMOVEDELETED, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_TRUE, 0)
		PROPERTY_INFO_ENTRY_VALUE(IRowsetUpdate, VARIANT_FALSE)
		PROPERTY_INFO_ENTRY_VALUE(IConnectionPointContainer, VARIANT_TRUE)
		PROPERTY_INFO_ENTRY(NOTIFICATIONGRANULARITY)
		PROPERTY_INFO_ENTRY(NOTIFICATIONPHASES)
		PROPERTY_INFO_ENTRY(NOTIFYCOLUMNSET)
		PROPERTY_INFO_ENTRY(NOTIFYROWDELETE)
		PROPERTY_INFO_ENTRY(NOTIFYROWINSERT)
		PROPERTY_INFO_ENTRY(NOTIFYROWSETFETCHPOSITIONCHANGE)
		PROPERTY_INFO_ENTRY(NOTIFYROWFIRSTCHANGE)
		PROPERTY_INFO_ENTRY(NOTIFYROWSETRELEASE)
		PROPERTY_INFO_ENTRY(NOTIFYROWUNDOCHANGE)
		PROPERTY_INFO_ENTRY(NOTIFYROWUNDODELETE)
		PROPERTY_INFO_ENTRY(NOTIFYROWUNDOINSERT)
		PROPERTY_INFO_ENTRY(NOTIFYROWUPDATE)
	END_PROPERTY_SET(DBPROPSET_ROWSET)
END_PROPSET_MAP()
};


///////////////////////////////////////////////////////////////////////////
// class RUpdateRowset

class RUpdateRowset : 
public CRowsetImpl< RUpdateRowset, CAgentMan, CUpdateCommand, 
			CAtlArray< CAgentMan >, CSimpleRow, 
			IRowsetScrollImpl< RUpdateRowset, IRowsetScroll > >,
		public IRowsetUpdateImpl< RUpdateRowset, CAgentMan >,
		public IConnectionPointContainerImpl<RUpdateRowset>,
		public IRowsetNotifyCP<RUpdateRowset>

{
public:
	typedef CRowsetImpl< RUpdateRowset, CAgentMan, CUpdateCommand, CAtlArray<CAgentMan>, CSimpleRow, IRowsetScrollImpl< RUpdateRowset, IRowsetScroll > > _RowsetBaseClass;

BEGIN_COM_MAP(RUpdateRowset)
	COM_INTERFACE_ENTRY(IRowsetLocate)
	COM_INTERFACE_ENTRY(IRowsetScroll)
	COM_INTERFACE_ENTRY(IRowsetChange)
	COM_INTERFACE_ENTRY(IRowsetUpdate)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)	
END_COM_MAP()	

BEGIN_CONNECTION_POINT_MAP(RUpdateRowset)
	CONNECTION_POINT_ENTRY(__uuidof(IRowsetNotify))
END_CONNECTION_POINT_MAP()


	///////////////////////////////////////////////////////////////////////
	// Execute function

	HRESULT Execute(DBPARAMS * /*pParams*/, DBROWCOUNT* pcRowsAffected)
	{
		USES_CONVERSION;
		FILE* pFile;
		TCHAR szString[24];
		TCHAR szFile[MAX_PATH];
		size_t nLength;
		ObjectLock lock(this);

		// get the value of the DBPROP_MAXROWS property
		CComVariant varMaxRows;
		long nMaxRows = 0;
		if (SUCCEEDED(GetPropValue(&DBPROPSET_ROWSET, DBPROP_MAXROWS, &varMaxRows)))
		{
			nMaxRows = varMaxRows.lVal;
		}

		// get the value of the DBPROP_IRowsetChange property
		CComVariant varIRowsetChange;
		bool bIRowsetChange = false;
		if (SUCCEEDED(GetPropValue(&DBPROPSET_ROWSET, DBPROP_IRowsetChange, &varIRowsetChange)))
		{
			if( varIRowsetChange.boolVal == ATL_VARIANT_TRUE )
				bIRowsetChange = true;
		}

		// get the value of the DBPROP_IRowsetUpdate property
		CComVariant varIRowsetUpdate;
		bool bIRowsetUpdate = false;
		if (SUCCEEDED(GetPropValue(&DBPROPSET_ROWSET, DBPROP_IRowsetUpdate, &varIRowsetUpdate)))
		{
			if( varIRowsetUpdate.boolVal == ATL_VARIANT_TRUE )
				bIRowsetUpdate = true;
		}

		// if the user set DBPROP_IRowsetChange or DBPROP_IRowsetUpdate to true, we will
		// ignore the value of the DBPROP_MAXROWS property.
		if( bIRowsetUpdate || bIRowsetChange )
		{
			nMaxRows = false;
		}

		// From a filename, passed in as a command text, scan the file placing data
		// in the data array.
		if (m_strCommandText == (BSTR)NULL)
		{
			ATLTRACE("No filename specified\n");
			return E_FAIL;
		}

		// Open the file
		_tcscpy_s(szFile, MAX_PATH, COLE2T(m_strCommandText));
		if (szFile[0] == _T('\0') || (_tfopen_s(&pFile, szFile, _T("r")) != 0))
		{
			ATLTRACE("RUpdateRowset::Execute -- Could not open file\n");
			return DB_E_NOTABLE;
		}

		m_bstrFile = m_strCommandText;

		// scan and parse the file.  The file should contain a DWORD and four strings 
		// per record.  We use 18 for a 16 character string + NULL terminator + 
		// trailing CR/LF
		LONG cFiles = 0;

		while (!feof(pFile) && (( nMaxRows == 0 ) || (cFiles < nMaxRows)))
		{
			CAgentMan am;
			memset(&am, 0, sizeof(CAgentMan));

			// Fetch the fixed DWORD
			am.dwFixed = (DWORD)_getw(pFile);

			// It is possible on an empty file to do a _getw but return an error.
			// In this case, we should aboard the process.
			if (ferror(pFile) || feof(pFile))
			{
				ATLTRACE("RUpdateRowset::Execute -- Couldn't read data probably empty file or end of file\n");
				break;
			}

			// Read in the four strings, be sure to check for NULL to indicate a NULL
			// string.  This is an arbitrary value on our part.

			for (int i=0; i<4; i++)
			{
				if (_fgetts(szString, 18, pFile) == NULL)
				{
					break;
				}
				szString[18] = 0;
				nLength = _tcslen(szString);
				szString[nLength-1] = '\0';

				switch (i)
				{
				case 0:
					_tcscpy_s(am.szCommand, array_count(am.szCommand), szString);
					if (_tcscmp(szString, _T("NULL")) == 0)
						memset((void*)am.szCommand, 0, 16);
					break;
				case 1:
					_tcscpy_s(am.szText, array_count(am.szText), szString);
					if (_tcscmp(szString, _T("NULL")) == 0)
						memset((void*)am.szText, 0, 16);
					break;
				case 2:
					_tcscpy_s(am.szCommand2, array_count(am.szCommand2), szString);
					if (_tcscmp(szString, _T("NULL")) == 0)
						memset((void*)am.szCommand2, 0, 16);
					break;
				case 3:
					_tcscpy_s(am.szText2, array_count(am.szText2), szString);
					if (_tcscmp(szString, _T("NULL")) == 0)
						memset((void*)am.szText2, 0, 16);
					break;
				}
			}


			// Bookmark field contains the index of the number
			am.dwBookmark = (DBBKMARK)m_rgBookmarks.GetCount();	

			// The value of the bookmark contains the row index to m_rgRowData
			m_rgBookmarks.Add(++cFiles);	
			_ATLTRY
			{
				m_rgRowData.Add(am);
			}
			_ATLCATCHALL()
			{
				ATLTRACE("RUpdateRowset::Execute -- Couldn't add data to array\n");
				if (fclose(pFile) == EOF)
					ATLTRACE("RUpdateRowset::Execute -- Error closing file\n");
				return E_FAIL;
			}
		}

		// Close the file
		if (fclose(pFile) == EOF)
			ATLTRACE("RUpdateRowset::Execute -- Error closing file\n");

		if (pcRowsAffected != NULL)
			*pcRowsAffected = cFiles;
		return S_OK;
	}


	///////////////////////////////////////////////////////////////////////
	// OLE DB Conformance Test Functions:  Necessary for compliance
	virtual HRESULT	IsValidValue(ULONG /*iCurSet*/, DBPROP* pDBProp)
	{
		ATLENSURE(pDBProp != NULL);
		DWORD dwPropertyID = pDBProp->dwPropertyID;
		CComVariant var = pDBProp->vValue;

		if (var.vt == VT_BOOL)
		{
			if (var.boolVal != VARIANT_TRUE && var.boolVal != VARIANT_FALSE)
				return S_FALSE;
		}

		// Check our own properties
		switch(dwPropertyID)
		{
		case DBPROP_MAXOPENROWS:
		case DBPROP_MAXROWS:
			{
				if (var.lVal < 0)	// it doesn't make sense to set rows to < 0
				{
					return S_FALSE;
				}
			}
			break;
		default:
			break;
		}

		return S_OK;
	}

	HRESULT ValidateCommandID(DBID* pTableID, DBID* pIndexID)
	{
		HRESULT hr = _RowsetBaseClass::ValidateCommandID(pTableID, pIndexID);
		if (hr != S_OK)
			return hr;

		if (pIndexID != NULL)
			return DB_E_NOINDEX;    // We don't support indexes

		return S_OK;
	}

	virtual DBSTATUS GetDBStatus(CSimpleRow* pRow, ATLCOLUMNINFO* pColumn)
	{
		ATLENSURE(pRow != NULL);
		ATLENSURE(pColumn != NULL);

		void* pData = (void*)&(m_rgRowData[pRow->m_iRowset]);
		BYTE* pColData = (BYTE*)pData + pColumn->cbOffset;

		if (*pColData == NULL && (pColumn->wType == DBTYPE_STR))
			return DBSTATUS_S_ISNULL;
		else
			return DBSTATUS_S_OK;
	}

	///////////////////////////////////////////////////////////////////////
	// Functions used for writing data

	HRESULT FlushData(HROW, HACCESSOR)
	{
		ATLTRACE2(atlTraceDBProvider, 0, "RUpdateRowset::FlushData\n");

		USES_CONVERSION;
		FILE* pFile;
		TCHAR szString[256];
		TCHAR szFile[MAX_PATH];
		ObjectLock lock(this);

		// From a filename, passed in as a command text, scan the file placing data
		// in the data array.
		if (m_strCommandText == (BSTR)NULL)
		{
			ATLTRACE("RRowsetUpdate::FlushData -- No filename specified\n");
			return E_FAIL;
		}

		// Open the file
		_tcscpy_s(szFile, MAX_PATH, COLE2T(m_strCommandText));
		if (szFile[0] == _T('\0') || (_tfopen_s(&pFile, szFile, _T("w"))) != 0)
		{
			ATLTRACE("RUpdateRowset::FlushData -- Could not open file\n");
			return DB_E_NOTABLE;
		}

		// Iterate through the row data and store it.
		for (size_t l=0; l<m_rgRowData.GetCount(); l++)
		{
			CAgentMan am = m_rgRowData[l];

			_putw((int)am.dwFixed, pFile);

			if (_tcscmp(&am.szCommand[0], _T("")) != 0)
				_stprintf_s(szString, array_count(szString), _T("%s\n"), am.szCommand);
			else
				_stprintf_s(szString, array_count(szString), _T("%s\n"), _T("NULL"));
			_fputts(szString, pFile);

			if (_tcscmp(&am.szText[0], _T("")) != 0)
				_stprintf_s(szString, array_count(szString), _T("%s\n"), am.szText);
			else
				_stprintf_s(szString, array_count(szString), _T("%s\n"), _T("NULL"));
			_fputts(szString, pFile);

			if (_tcscmp(&am.szCommand2[0], _T("")) != 0)
				_stprintf_s(szString, array_count(szString), _T("%s\n"), am.szCommand2);
			else
				_stprintf_s(szString, array_count(szString), _T("%s\n"), _T("NULL"));
			_fputts(szString, pFile);

			if (_tcscmp(&am.szText2[0], _T("")) != 0)
				_stprintf_s(szString, array_count(szString), _T("%s\n"), am.szText2);
			else
				_stprintf_s(szString, array_count(szString), _T("%s\n"), _T("NULL"));
			_fputts(szString, pFile);
		}

		if (fflush(pFile) == EOF || fclose(pFile) == EOF)
			ATLTRACE("RRowsetUpdate::FlushData -- Couldn't flush or close file\n");
		return S_OK;
	}

	virtual HRESULT SetDBStatus(DBSTATUS* pdbStatus, CSimpleRow* pRow, 
		ATLCOLUMNINFO* pColInfo)
	{
		ATLENSURE(pRow != NULL && pColInfo != NULL && pdbStatus != NULL);
		
		void* pData = NULL;
		char* pDefaultData = NULL;
		DWORD* pFixedData = NULL;

		switch (*pdbStatus)
		{
			case DBSTATUS_S_DEFAULT:
				pData = (void*)&m_rgRowData[pRow->m_iRowset];
				if (pColInfo->wType == DBTYPE_STR)
				{
					pDefaultData = (char*)pData + pColInfo->cbOffset;
					strcpy_s(pDefaultData, sizeof("Default"), "Default");
				}
				else
				{
					pFixedData = (DWORD*)((BYTE*)pData + pColInfo->cbOffset);
					*pFixedData = 0;
					return S_OK;
				}

				break;

			case DBSTATUS_S_ISNULL:
			default:
				break;
		}

		return S_OK;
	}

	CComBSTR m_bstrFile;

};
#endif //__RUpdateRowset_H_
