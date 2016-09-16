// AdvancedRS.h : Declaration of the CAdvancedRowset
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
#include "ROWSCRLL.H"
#include "FileArray.h"

///////////////////////////////////////////////////////////////////////////
// Forward declarations

class CAdvancedRowset;
class CAdvancedRecord;
class CAdvancedCommand;

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
// class CAdvancedRecord

class CAdvancedRecord
{
public:

	DBBKMARK dwBookmark;
	TCHAR szCommand[17];
	TCHAR szText[17];
	TCHAR szCommand2[17];
	TCHAR szText2[17];
	DWORD dwFixed;

	static ATLCOLUMNINFO* GetColumnInfo(CAdvancedRowset* pThis, DBORDINAL* pcCols);
	static ATLCOLUMNINFO* GetColumnInfo(CAdvancedCommand* pThis, DBORDINAL* pcCols);
};

///////////////////////////////////////////////////////////////////////////
// CAdvancedCommand
class ATL_NO_VTABLE CAdvancedCommand : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public IAccessorImpl<CAdvancedCommand>,
	public ICommandTextImpl<CAdvancedCommand>,
	public ICommandPropertiesImpl<CAdvancedCommand>,
	public IObjectWithSiteImpl<CAdvancedCommand>,
	public IConvertTypeImpl<CAdvancedCommand>,
	public IColumnsInfoImpl<CAdvancedCommand>,
	public IInternalCommandConnectionImpl<CAdvancedCommand>

{
public:
BEGIN_COM_MAP(CAdvancedCommand)
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
		hr = IAccessorImpl<CAdvancedCommand>::FinalConstruct();
		if (FAILED(hr))
			return hr;
		return CUtlProps<CAdvancedCommand>::FInit();
	}
	void FinalRelease()
	{
		IAccessorImpl<CAdvancedCommand>::FinalRelease();
	}

	HRESULT WINAPI Execute(IUnknown * pUnkOuter, REFIID riid, DBPARAMS * pParams, 
						  DBROWCOUNT * pcRowsAffected, IUnknown ** ppRowset);

	static ATLCOLUMNINFO* GetColumnInfo(CAdvancedCommand* pv, DBORDINAL* pcInfo)
	{
		return CAdvancedRecord::GetColumnInfo(pv,pcInfo);
	}

BEGIN_PROPSET_MAP(CAdvancedCommand)
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
		PROPERTY_INFO_ENTRY_EX(OTHERINSERT, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_TRUE, 0)		// IRowsetChange
		PROPERTY_INFO_ENTRY_EX(OTHERUPDATEDELETE, VT_BOOL, DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ, VARIANT_TRUE, 0)	// IRowsetChange
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
// class CAdvancedRowset
class CAdvancedRowset : 
	public CRowsetImpl< CAdvancedRowset, CAdvancedRecord, CAdvancedCommand, 
			CFileArray< CAdvancedRecord >, CSimpleRow, 
			IRowsetScrollImpl< CAdvancedRowset, IRowsetScroll > >,
		//public IRowsetUpdateImpl< CAdvancedRowset, CAdvancedRecord >,
		public IConnectionPointContainerImpl<CAdvancedRowset>,
		public IRowsetNotifyCP<CAdvancedRowset>
{
public:

BEGIN_COM_MAP(CAdvancedRowset)
	COM_INTERFACE_ENTRY(IRowsetLocate)
	COM_INTERFACE_ENTRY(IRowsetScroll)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)	
END_COM_MAP()	

BEGIN_CONNECTION_POINT_MAP(CAdvancedRowset)
	CONNECTION_POINT_ENTRY(__uuidof(IRowsetNotify))
END_CONNECTION_POINT_MAP()

HRESULT Execute(DBPARAMS * /*pParams*/, DBROWCOUNT* pcRowsAffected)
{
	USES_CONVERSION;
	TCHAR szFile[MAX_PATH];
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
		ATLTRACE("CAdvancedRowset::Execute -- No filename specified\n");
		return E_FAIL;
	}

	// Open the file
	_tcscpy_s(szFile, MAX_PATH, COLE2T(m_strCommandText));
	if( !m_rgRowData.OpenFile( szFile, offsetof(CAdvancedRecord, szCommand), sizeof(CAdvancedRecord)-sizeof(DBBKMARK), offsetof(CAdvancedRecord, dwBookmark) ) )
	{
		ATLTRACE("CAdvancedRowset::Execute -- Failed to open file\n");
		return E_FAIL;
	}

	size_t rowCount = m_rgRowData.GetCount();
	for( size_t i = 0; i < rowCount; i++ )
	{
		// The value of the bookmark contains the row index to m_rgRowData
		m_rgBookmarks.Add((DBBKMARK)i);	
	}

	if (pcRowsAffected != NULL)
		*pcRowsAffected = (LONG)rowCount;
	return S_OK;
}

CComBSTR m_bstrFile;
};


