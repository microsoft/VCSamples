// Implementation of the CUpdateCommand
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#include "stdafx.h"
#include "UpdatePv.h"
#include "rowset.h"
/////////////////////////////////////////////////////////////////////////////
// CUpdateCommand
HRESULT CUpdateCommand::Execute(IUnknown * pUnkOuter, REFIID riid, DBPARAMS * pParams, 
								 DBROWCOUNT * pcRowsAffected, IUnknown ** ppRowset)
{
	RUpdateRowset* pRowset;
	return CreateRowset(pUnkOuter, riid, pParams, pcRowsAffected, ppRowset, pRowset);
}

ATLCOLUMNINFO* CommonGetColInfo(IUnknown* /*pPropsUnk*/, DBORDINAL* pcCols, bool bBookmark)
{
	static ATLCOLUMNINFO _rgColumns[6];
	ULONG ulCols = 0;

	if (bBookmark)
	{
		ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0, sizeof(DBBKMARK), DBTYPE_BYTES,
			0, 0, GUID_NULL, CAgentMan, dwBookmark, DBCOLUMNFLAGS_ISBOOKMARK)
		ulCols++;
	}

	// Next set the other columns up.
	ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Fixed"), 1, 4, DBTYPE_UI4, 10, 255,
		GUID_NULL, CAgentMan, dwFixed, 
		DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISFIXEDLENGTH | DBCOLUMNFLAGS_ISNULLABLE)
	ulCols++;
	
	ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Command"), 2, 16, DBTYPE_STR, 255, 255,
		GUID_NULL, CAgentMan, szCommand, 
		DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
	ulCols++;
	ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Text"), 3, 16, DBTYPE_STR, 255, 255,
		GUID_NULL, CAgentMan, szText, 
		DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
	ulCols++;

	ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Command2"), 4, 16, DBTYPE_STR, 255, 255,
		GUID_NULL, CAgentMan, szCommand2, 
		DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
	ulCols++;
	ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Text2"), 5, 16, DBTYPE_STR, 255, 255,
		GUID_NULL, CAgentMan, szText2, 
		DBCOLUMNFLAGS_WRITE | DBCOLUMNFLAGS_ISNULLABLE)
	ulCols++;

	if (pcCols != NULL)
		*pcCols = ulCols;

	return _rgColumns;
}


ATLCOLUMNINFO* CAgentMan::GetColumnInfo(CUpdateCommand* pThis, DBORDINAL* pcCols)
{
	CComQIPtr<ICommandProperties> spProps = pThis;
	bool bBookmark = false;

	CDBPropIDSet set(DBPROPSET_ROWSET);
	set.AddPropertyID(DBPROP_BOOKMARKS);
	DBPROPSET* pPropSet = NULL;
	ULONG ulPropSet = 0;
	HRESULT hr;

	if (spProps)
	{
		hr = spProps->GetProperties(1, &set, &ulPropSet, &pPropSet);

		if (pPropSet)
		{
			CComVariant var = pPropSet->rgProperties[0].vValue;
			CoTaskMemFree(pPropSet->rgProperties);
			CoTaskMemFree(pPropSet);

			if ((SUCCEEDED(hr) && (var.boolVal == VARIANT_TRUE)))
				bBookmark = true;
		}
	}
	return CommonGetColInfo(pThis->GetUnknown(), pcCols, bBookmark);
}


ATLCOLUMNINFO* CAgentMan::GetColumnInfo(RUpdateRowset* pThis, DBORDINAL* pcCols)
{
	CComQIPtr<IRowsetInfo> spProps = pThis;
	bool bBookmark = false;

	CDBPropIDSet set(DBPROPSET_ROWSET);
	set.AddPropertyID(DBPROP_BOOKMARKS);
	DBPROPSET* pPropSet = NULL;
	ULONG ulPropSet = 0;
	HRESULT hr;

	if (spProps)
	{
		hr = spProps->GetProperties(1, &set, &ulPropSet, &pPropSet);

		if (pPropSet)
		{
			CComVariant var = pPropSet->rgProperties[0].vValue;
			CoTaskMemFree(pPropSet->rgProperties);
			CoTaskMemFree(pPropSet);

			if ((SUCCEEDED(hr) && (var.boolVal == VARIANT_TRUE)))
				bBookmark = true;
		}
	}

	return CommonGetColInfo(pThis->GetUnknown(), pcCols, bBookmark);
}


