// DBListVw.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "DBViewer.h"
#include "DBListVw.h"
#include "editdlg.h"
#include "errordlg.h"
#include "dbexcept.h"
#include <tchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBListView

IMPLEMENT_DYNCREATE(CDBListView, CListView)

CDBListView::CDBListView()
{
	m_pSession = NULL;
	m_bEditable = FALSE;
	m_pMultipleCommand = NULL;
}

CDBListView::~CDBListView()
{
	m_pSession = NULL;
	if (m_pMultipleCommand != NULL)
		delete m_pMultipleCommand;
}


BEGIN_MESSAGE_MAP(CDBListView, CListView)
	//{{AFX_MSG_MAP(CDBListView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_UPDATE_COMMAND_UI(ID_NEXT_RESULT, OnUpdateNextResult)
	ON_COMMAND(ID_NEXT_RESULT, OnNextResult)
	//}}AFX_MSG_MAP
	ON_NOTIFY_REFLECT(LVN_KEYDOWN, OnKeyDown)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBListView drawing

void CDBListView::OnDraw(CDC* )
{

}

/////////////////////////////////////////////////////////////////////////////
// CDBListView diagnostics

#ifdef _DEBUG
void CDBListView::AssertValid() const
{
	CListView::AssertValid();
}

void CDBListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CDBViewDoc* CDBListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBViewDoc)));
	return (CDBViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBListView message handlers

int CDBListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= LVS_REPORT | LVS_NOSORTHEADER | LVS_SINGLESEL;
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Give the document a pointer to this view
	GetDocument()->m_pListView = this;

	return 0;
}

void CDBListView::EraseList()
{
	CListCtrlEx& ctlList = (CListCtrlEx&) GetListCtrl();
	ctlList.DeleteAllItems();
	while(ctlList.DeleteColumn(0));
	UpdateWindow();
}


void CDBListView::ShowDatabase()
{
	ATLENSURE(m_pSession);

	// Here, show database information (probably similar to Catalog3)

}

void CDBListView::ShowTableData(LPCTSTR lpszTableName)
{
	USES_CONVERSION;

	CCommand<CManualAccessor> rs;
	CColumns* pColumns      = NULL;
	CPrimaryKeys* pKeys     = NULL;
	int nItem               = 0;
	CListCtrlEx& ctlList    = (CListCtrlEx&) GetListCtrl();
	struct MYBIND* pBind    = NULL;

	// If we were in a multiple result set situation, destroy the
	// existing result set.
	if (m_pMultipleCommand != NULL)
	{
		delete m_pMultipleCommand;
		m_pMultipleCommand = NULL;
	}

	ATLENSURE(m_pSession);
	ATLENSURE(lpszTableName != NULL);

	TRY
	{
		// Get Column Information for the table we want
		pColumns = new CColumns;
		if (pColumns->Open(*m_pSession, NULL, NULL, lpszTableName) != S_OK)
			ThrowOLEDBException(pColumns->m_spRowset, IID_IDBSchemaRowset);

		// Generate Column Headers
		EraseList();
		ULONG ulColumns = 0;
		while (pColumns->MoveNext() == S_OK)
		{
			ulColumns++;
			ctlList.AddColumn(pColumns->m_szColumnName, ulColumns);
		}

		delete pColumns;
		pColumns = NULL;
		m_ulFields = ulColumns;
		pBind = new MYBIND[m_ulFields];

		rs.CreateAccessor(m_ulFields, pBind, sizeof(MYBIND)*m_ulFields);
		for (ULONG l=0; l<m_ulFields; l++)
		{
			#pragma warning (suppress: 6011) // unexpected null dereference prefast warning
			rs.AddBindEntry(l+1, DBTYPE_STR, sizeof(TCHAR)*40, &pBind[l].szValue,
				     NULL, &pBind[l].dwStatus);
		}

		// Check for multi word table names
		if (_tcschr(lpszTableName, _T(' ')) != NULL)
			m_strTable.Format("%s%s%s", GetDocument()->m_strQuoteStart, 
				lpszTableName, GetDocument()->m_strQuoteEnd);
		else
			m_strTable = lpszTableName;

		// Create a rowset containing data.
		m_strQuery.Format("select * from %s", m_strTable);

		// Determine if there are primary keys to order by
		pKeys = new CPrimaryKeys;
		bool bFirst = TRUE;
		if (pKeys->Open(*m_pSession, NULL, NULL, lpszTableName) == S_OK)
		{
			while(pKeys->MoveNext() == S_OK)
			{
				if (bFirst != FALSE)
				{
					m_strQuery += _T(" ORDER BY ");
					bFirst = FALSE;
				}
				else
					m_strQuery += _T(", ");

				bool bMultiWord = false;
				if (_tcschr(pKeys->m_szColumnName, _T(' ')) != NULL)
				{
					bMultiWord = true;
					m_strQuery += GetDocument()->m_strQuoteStart;
				}

				m_strQuery += pKeys->m_szColumnName;

				if (bMultiWord)
					m_strQuery += GetDocument()->m_strQuoteEnd;
			}
		}
		delete pKeys;
		pKeys = NULL;

		if (rs.Open(*m_pSession, m_strQuery) != S_OK)
			ThrowOLEDBException(rs.m_spCommand, IID_ICommand);

		// Display the data (to the maximum # of records allowed)
		int nLoaded = DisplayData((CRowset<CManualAccessor>*)&rs, pBind);

		delete [] pBind;
		pBind = NULL;
		CString strRecCount;
		strRecCount.Format(_T("Loaded %d of %d total records"), nLoaded, nItem);
		UpdateWindow();
		((CFrameWnd *) AfxGetMainWnd())->SetMessageText(strRecCount);
	}
	CATCH(COLEDBException, e)
	{
		if (pColumns != NULL)
			delete pColumns;

		if (pKeys != NULL)
			delete pKeys;

		if (pBind != NULL)
			delete [] pBind;

		CErrorsDialog dlg;
		dlg.Init(e->m_lpUnk, e->m_iid);
		dlg.DoModal();
	}
	END_CATCH
}


void CDBListView::ShowTableSchema(LPCTSTR lpszTableName)
{
	USES_CONVERSION;
	CTables*    pTableSet = NULL;

	// If we were in a multiple result set situation, destroy the
	// existing result set.
	if (m_pMultipleCommand != NULL)
	{
		delete m_pMultipleCommand;
		m_pMultipleCommand = NULL;
	}

	ATLENSURE(m_pSession);

	m_bVertical = lpszTableName != NULL;
	DisplayColumnHeadings(IDS_COL_TABLE);

	int nItem = 0;

	// Not editable
	m_bEditable = FALSE;

	pTableSet = new CTables;
	// (can simply hard code max size)
	char lpszType[64];

	strcpy_s(lpszType, 64, "TABLE");
	if (((CDBViewApp *)AfxGetApp())->m_bShowSystemObjects)
		strcat_s(lpszType, 64, ", SYSTEM TABLE");

	if (pTableSet->Open(*m_pSession, NULL, NULL, lpszTableName, lpszType) != S_OK)
	{
		delete pTableSet;
		return;
	}

	while(pTableSet->MoveNext() == S_OK)
	{
		// We do not handle multi-word tables or procedures.  Normally,
		// only Access handles these.
		if (_tcschr(pTableSet->m_szName, _T(' ')) != NULL)
			continue;

		AddItem(nItem, 0, pTableSet->m_szName);
		AddItem(nItem, 1, pTableSet->m_szType);
		AddItem(nItem, 2, pTableSet->m_szSchema);
		AddItem(nItem, 3, pTableSet->m_szCatalog);
		AddItem(nItem, 4, pTableSet->m_szDescription);
		nItem++;
	}

	delete pTableSet;
	pTableSet = NULL;
	AdjustColumnWidths();
}

void CDBListView::ShowProcedures(LPCTSTR lpszProcedureName)
{
	USES_CONVERSION;
	CProcedures*    pProcedureSet = NULL;

	ATLENSURE(m_pSession);

	m_bEditable = FALSE;
	m_bVertical = lpszProcedureName != NULL;
	DisplayColumnHeadings(IDS_COL_PROC);

	int nItem = 0;

	pProcedureSet = new CProcedures;
	if (pProcedureSet->Open(*m_pSession, NULL, NULL, lpszProcedureName) != S_OK)
	{
		delete pProcedureSet;
		return;
	}

	while(pProcedureSet->MoveNext() == S_OK)
	{
		// We do not handle multi-word tables or procedures.  Normally,
		// only Access handles these.
		if (_tcschr(pProcedureSet->m_szName, _T(' ')) != NULL)
			continue;

		AddItem(nItem, 0, pProcedureSet->m_szName);
		AddItem(nItem, 1, pProcedureSet->m_szCatalog);
		AddItem(nItem, 2, pProcedureSet->m_szSchema);
		AddItem(nItem, 3, pProcedureSet->m_szDescription);

		CString strType;
		strType.Format("%d", pProcedureSet->m_nType);
		AddItem(nItem, 4, strType);
		nItem++;
	}

	delete pProcedureSet;
	pProcedureSet = NULL;
	AdjustColumnWidths();
}

void CDBListView::AdjustColumnWidths()
{
	CListCtrlEx& ctlList = (CListCtrlEx&) GetListCtrl();
	ctlList.SetColumnWidth(-1,-3);
}

void CDBListView::AddItem(int nItem, int nSubItem, LPCTSTR lpszItem)
{
	CListCtrlEx& ctlList = (CListCtrlEx&) GetListCtrl();

	if (m_bVertical)
		ctlList.AddItem(nSubItem, 1, lpszItem);
	else
		ctlList.AddItem(nItem, nSubItem, lpszItem);
}

void CDBListView::DisplayColumnHeadings(UINT nStringID)
{
	CString strHeadings;

	if(strHeadings.LoadString(nStringID) == FALSE)
	{
		AfxThrowResourceException();
	}

	CListCtrlEx& ctlList = (CListCtrlEx&) GetListCtrl();

	int nPos;
	int nCount = 0;

	EraseList();

	if (m_bVertical)
	{
		ctlList.AddColumn(_T("Property     "),0);
		ctlList.AddColumn(_T("Value     "),1);
		m_nColumns = 2;
	}
	while ((nPos = strHeadings.Find(_T(","))) != -1){
		CString strItem;
		strItem = strHeadings.Left(nPos);
		if (m_bVertical)
			ctlList.AddItem(nCount++,0,strItem);
		else
			ctlList.AddColumn(strItem,nCount++);
		strItem = strHeadings.Mid(nPos + 1);
		strHeadings = strItem;
	}
	if (m_bVertical)
		ctlList.AddItem(nCount,0,strHeadings);
	else
		ctlList.AddColumn(strHeadings,nCount);
	m_nColumns = nCount;
}

void CDBListView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CListCtrlEx& ctlList = (CListCtrlEx&) GetListCtrl();
	LV_HITTESTINFO lvInfo;
	lvInfo.pt = point;

	if (ctlList.HitTest(&lvInfo) != -1)
	{
		// Invoke Edit Database Dialog
		CEditDlg editDlg(&ctlList, lvInfo.iItem, m_ulFields);

		if (editDlg.DoModal() == IDOK)
		{
			// Update Database
			if (UpdateDatabase(lvInfo.iItem, &editDlg))
			{
				// Requery Database
				ShowTableData(m_strTable);
			}
		}
	}

	CListView::OnLButtonDblClk(nFlags, point);
}

BOOL CDBListView::UpdateDatabase(int nRow, CEditDlg* pEditDlg)
{
	USES_CONVERSION;
	CCommand<CManualAccessor> rs;
	struct MYBIND*  pBind               = NULL;
	struct MYBIND*  pCol                = NULL;
	TCHAR           (*lpszParams)[40]   = NULL;
	CPrimaryKeys    keys;
	CPtrArray       strColumnArray;
	CListCtrlEx&    ctlList             = (CListCtrlEx&) GetListCtrl();
	ULONG           ulParams            = 0;
	bool            bConstraintColumns  = false;

	// If we were in a multiple result set situation, just ignore
	// this command.
	if (m_pMultipleCommand != NULL)
		return FALSE;

	ATLENSURE(m_pSession);

	TRY
	{
		// Get the select string to select the unique record we wish to update
		// Open the Table and load it into

		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY,
					DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);

		// Get column name from list control
		if (keys.Open(*m_pSession, NULL, NULL, m_strTable) == S_OK)
		{
			if (keys.MoveNext() == S_OK)
				bConstraintColumns = true;
		}
		ULONG i;
		for (i=0; i<m_ulFields; i++)
		{
			LV_COLUMN lvColumn;
			TCHAR szColumnName[40];

			lvColumn.mask = LVCF_TEXT;
			lvColumn.pszText = &szColumnName[0];
			lvColumn.cchTextMax = 40;
			lvColumn.iSubItem = i;

			ctlList.GetColumn(i, &lvColumn);


			if (bConstraintColumns != false)
			{
				// Note, we depend upon the sort order of the provider
				// being catalog, schema, table name, column name as
				// provided in the spec.
				#pragma warning(suppress: 6054) // szColumnName will always be NULL terminated
				if (_tcscmp(szColumnName, keys.m_szColumnName) == 0)
				{
					// column is a constraint column
					if (keys.MoveNext() != S_OK)
						bConstraintColumns = false;

					// Don't add the column to our list of bindings
					continue;
				}
			}
			pCol = new MYBIND;
			#pragma warning(suppress: 6054) // szColumnName will always be NULL terminated
			_tcscpy_s(pCol->szValue, 40, szColumnName);
			pCol->dwStatus = i+1;   // Ordinal of the column
			strColumnArray.Add(pCol);
		}

		SelectRecord(nRow, &rs, &lpszParams, &ulParams);

		// Create a temporary buffer and bind it the columns
		ULONG ulFields = (ULONG)strColumnArray.GetUpperBound() + 1;
		pBind = new MYBIND[ulFields];
		rs.CreateAccessor(ulFields, pBind, sizeof(MYBIND)*ulFields);
		for (ULONG l=0; l<ulFields; l++)
		{
			pCol = (MYBIND*)strColumnArray[l];
			#pragma warning(suppress: 6011) // unexpected null dereference prefast warning
			pBind[l].dwStatus = DBSTATUS_S_OK;
			#pragma warning(suppress: 6011) // unexpected null dereference prefast warning
			rs.AddBindEntry(pCol->dwStatus, DBTYPE_STR, sizeof(TCHAR)*40,
				&pBind[l].szValue, NULL, &pBind[l].dwStatus);

		}

		if (rs.Open(&propset) != S_OK)
			ThrowOLEDBException(rs.m_spRowset, IID_IRowset);

		rs.MoveNext();

		for (i = 0; i<ulFields; i++)
		{
			pCol = (MYBIND*)strColumnArray[i];
			CString strKey = pCol->szValue;

			// Get item from list view
			CString strValue = pEditDlg->GetValue(strKey);

			if (strValue != pBind[i].szValue)
				_tcsncpy_s(pBind[i].szValue, 40, strValue, _TRUNCATE);

			delete pCol;    // We no longer require the column information
			pCol = NULL;
		}

		strColumnArray.RemoveAll();
		rs.SetData();

		// Cleanup
		if (pBind != NULL)
			delete [] pBind;

		if (lpszParams != NULL)
			delete []lpszParams;
	}
	CATCH(COLEDBException, e)
	{
		if (pBind != NULL)
			delete [] pBind;

		if (lpszParams != NULL)
			delete []lpszParams;
		CErrorsDialog dlg;
		dlg.Init(e->m_lpUnk, e->m_iid);
		dlg.DoModal();

		return FALSE;
	}
	END_CATCH

	return TRUE;
}

void CDBListView::CallProcedure(LPCTSTR lpszProcName)
{
	USES_CONVERSION;
	CProcedureParameters       procParam;
	CCommand<CManualAccessor, CRowset, CMultipleResults>*   prs;
	CMapStringToString          mapInput;
	struct MYBIND*              pParams     = NULL;
	ULONG                       ulParams    = 0;
	CPtrArray                   arrColInfo;
	CWordArray                  arrType;
	struct MYBIND*              pParamInfo = NULL;

	// If we were in a multiple result set situation, destroy the
	// existing result set.
	if (m_pMultipleCommand != NULL)
	{
		delete m_pMultipleCommand;
		m_pMultipleCommand = NULL;
	}

	ATLENSURE(m_pSession);
	ATLENSURE(lpszProcName != NULL);

	// Create the stored procedure string
	CString strProc, strCall, strTemp("? = ");

	// Handle any multiword characters that may exist
	if (_tcschr(lpszProcName, _T(' ')) != NULL)
		strProc.Format("Call %s%s%s ", GetDocument()->m_strQuoteStart,
			lpszProcName, GetDocument()->m_strQuoteEnd);
	else
		strProc.Format("Call %s ", lpszProcName);
	
	int nFirst = 0;

	int nReturnValue = 0;
	if (procParam.Open(*m_pSession, NULL, NULL, lpszProcName) == S_OK)
	{
		while (procParam.MoveNext() == S_OK)
		{
			ulParams++;
			pParamInfo = new MYBIND;
			pParamInfo->dwStatus = ulParams;
			_tcsncpy_s(pParamInfo->szValue, 40, procParam.m_szName, _TRUNCATE);
			arrColInfo.Add(pParamInfo);
			arrType.Add((WORD)procParam.m_nType);
			

			// Handle return type
			switch (procParam.m_nType)
			{
				case DBPARAMTYPE_RETURNVALUE:
					strTemp += strProc;
					strProc = strTemp;
					nReturnValue = 1;
					break;

				case DBPARAMTYPE_INPUT:
				case DBPARAMTYPE_INPUTOUTPUT:
					mapInput.SetAt(procParam.m_szParameterName, "");

				case DBPARAMTYPE_OUTPUT:
					if (nFirst == 0)
					{
						strProc += "(?";
						nFirst++;
					}
					else
						strProc += ", ?";
					break;

				default:
					break;
			}
		}
	}

	if (nFirst > 0)
		strProc += ")";

	strCall.Format("{ %s }", strProc);
	prs = new CCommand<CManualAccessor, CRowset, CMultipleResults>;
	prs->Create(*m_pSession, strCall);
	prs->Prepare(1);

	if (ulParams > 0)
	{
		DBPARAMBINDINFO* pBindInfo = new DBPARAMBINDINFO[ulParams];
		DBORDINAL* pOrdinals = new DBORDINAL[ulParams];
		pParams = new MYBIND[ulParams];

		// Make the bindings for the accessor based on the DBTYPE_STR
		// data type
		prs->CreateParameterAccessor(ulParams, &pParams[0], sizeof(MYBIND)*ulParams);
		for (ULONG l=0; l<ulParams; l++)
		{
			// Set up information for the SetParameterInfo call
			pOrdinals[l] = l+1;
			pBindInfo[l].pwszDataSourceType = CComBSTR(_T("DBTYPE_CHAR")).Detach();
			pBindInfo[l].pwszName = NULL;
			pBindInfo[l].ulParamSize = 40;
			pBindInfo[l].bPrecision = 0;
			pBindInfo[l].bScale = 0;

			DWORD dwFlags = 0;
			if (arrType[l] == DBPARAMTYPE_INPUT ||
				arrType[l] == DBPARAMTYPE_INPUTOUTPUT)
				dwFlags |= DBPARAMFLAGS_ISINPUT;

			if (arrType[l] == DBPARAMTYPE_OUTPUT ||
				arrType[l] == DBPARAMTYPE_INPUTOUTPUT ||
				arrType[l] == DBPARAMTYPE_RETURNVALUE)
				dwFlags |= DBPARAMFLAGS_ISOUTPUT;
			pBindInfo[l].dwFlags = dwFlags;


			// Set up information for bindings
			pParamInfo = (MYBIND*)arrColInfo[l];

			if (arrType[l] == DBPARAMTYPE_RETURNVALUE)
			{
				prs->AddParameterEntry(1, DBTYPE_STR, sizeof(TCHAR)*40,
					&pParams[l].szValue, NULL, &pParams[l].dwStatus, DBPARAMIO_OUTPUT);
			}
			else
			{
				prs->AddParameterEntry(l+1, DBTYPE_STR, sizeof(TCHAR)*40,
					&pParams[l].szValue, NULL, &pParams[l].dwStatus, arrType[l]);
			}

			 delete pParamInfo;
			 pParamInfo = NULL;
		}

		// Call ICommandWithParameters::SetParameterInfo so that we can
		// tell the provider to convert the parameter types to DBTYPE_STR
		prs->SetParameterInfo(ulParams, pOrdinals, pBindInfo);
		delete [] pOrdinals;
		delete []pBindInfo;
	}
	arrColInfo.RemoveAll();

	// Place values in the parameter buffers
	if (!mapInput.IsEmpty())
	{
		CEditDlg dlg(mapInput);

		if (dlg.DoModal() != IDOK)
		{
			if (pParams != NULL)
				delete []pParams;
			delete prs;
			return;
		}

		POSITION pos = mapInput.GetStartPosition();

		ULONG   l=0;
		ULONG   ulCount=0;
		while (pos != NULL)
		{
			for(l=ulCount; l<ulParams; l++)
			{
				if (arrType[l] == DBPARAMTYPE_INPUT ||
					arrType[l] == DBPARAMTYPE_INPUTOUTPUT)
				{
					CString strKey, strValue;
					mapInput.GetNextAssoc(pos, strKey, strValue);
					strValue = dlg.GetValue(strKey);
					_tcsncpy_s(pParams[l].szValue, 40, strValue, _TRUNCATE);
					ulCount = l+1;
				}
			}
		}
	}

	// Open the rowset to get the information so we can then bind the columns
	if (prs->Open(NULL, NULL, false) != S_OK)
	{
		CErrorsDialog dlg;
		dlg.Init(prs->m_spCommand, IID_ICommandPrepare);
		dlg.DoModal();
		delete prs;
		prs = NULL;
		delete []pParams;
		return;
	}


	m_pMultipleCommand = prs;
	OnNextResult();

	if (pParams != NULL)
		delete []pParams;

}

int CDBListView::DisplayData(CRowset<CManualAccessor>* pRS, struct MYBIND* pBind)
{
	CListCtrlEx&        ctlList = (CListCtrlEx&) GetListCtrl();

	// Display the data (to the maximum # of records allowed)
	int nLoaded = 0;
	int nMaxRecords = ((CDBViewApp*)AfxGetApp())->m_nMaxRecords;

	int nItem=0;
	while (pRS->MoveNext() == S_OK)
	{
		if (nItem < nMaxRecords)
		{
			nLoaded++;
			for (ULONG j=1; j<=m_ulFields; j++)
			{
				if (pBind[j-1].dwStatus == DBSTATUS_S_ISNULL)
					_tcscpy_s(pBind[j-1].szValue, 40, _T(""));
				ctlList.AddItem(nItem, j-1, pBind[j-1].szValue);
			}
			nItem++;
		}
	}

	return nLoaded;
}

void CDBListView::InsertRecord(LPCTSTR lpszTableName)
{
	USES_CONVERSION;
	CCommand<CManualAccessor> rs;
	CColumns* pColumns          = NULL;
	TCHAR (*lpszColumns)[40]    = NULL;
	CListCtrlEx& ctlList        = (CListCtrlEx&) GetListCtrl();
	CStringList strList;

	// If we were in a multiple result set situation, just
	// ignore this command
	if (m_pMultipleCommand != NULL)
		return;

	ATLENSURE(m_pSession);
	ATLENSURE(lpszTableName != NULL);

	TRY
	{
		// Set the editable information
		pColumns = new CColumns;
		if (pColumns->Open(*m_pSession, NULL, NULL, lpszTableName) != S_OK)
			ThrowOLEDBException(pColumns->m_spRowset, IID_IDBSchemaRowset);

		// Generate Column Headers
		EraseList();
		ULONG ulColumns = 0;
		while (pColumns->MoveNext() == S_OK)
		{
			ulColumns++;
			strList.AddTail(pColumns->m_szColumnName);
			ctlList.AddColumn(pColumns->m_szColumnName, ulColumns);
		}
		m_ulFields = ulColumns;

		delete pColumns;
		pColumns = NULL;
		lpszColumns = new TCHAR[m_ulFields][40];

		// Create Bindings for the insertion
		rs.CreateAccessor(m_ulFields, &lpszColumns[0], sizeof(TCHAR)*40*m_ulFields);
		for (ULONG l=0; l<m_ulFields; l++)
		{
			#pragma warning(suppress: 6011) // unexpected null dereference prefast warning
			rs.AddBindEntry(l+1, DBTYPE_STR, 40, &lpszColumns[l]);
		}

		// Create a rowset containing data.
		// Set up some properties for the rowset
		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY,
					DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);

		rs.Create(*m_pSession, m_strQuery);
		rs.Prepare();
		if (rs.Open(&propset) != S_OK)
			ThrowOLEDBException(rs.m_spRowset, IID_IRowset);

		CEditDlg editDlg(&ctlList, 0, m_ulFields);

		if (editDlg.DoModal() != IDOK)
		{
			delete []lpszColumns;
			return;
		}

		POSITION pos = strList.GetHeadPosition();
		for (ULONG i=0; i<m_ulFields; i++)
		{
			CString strKey, strValue;

			// Insert new data
			strKey = strList.GetNext(pos);
			strValue = editDlg.GetValue(strKey);
			_tcsncpy_s(lpszColumns[i], 40, strValue, _TRUNCATE);
		}

		// Update the database
		if (rs.Insert(0) != S_OK)
			ThrowOLEDBException(rs.m_spRowset, IID_IRowsetChange);
		ShowTableData(lpszTableName);

		// Cleanup
		if (lpszColumns != NULL)
		{
			delete []lpszColumns;
			lpszColumns = NULL;
		}
	}
	CATCH(COLEDBException, e)
	{
		if (pColumns != NULL)
			delete pColumns;

		if (lpszColumns != NULL)
			delete []lpszColumns;

		CErrorsDialog dlg;
		dlg.Init(e->m_lpUnk, e->m_iid);
		dlg.DoModal();
	}
	END_CATCH
}

void CDBListView::OnKeyDown(NMHDR *pNotifyStruct,LRESULT *result)
{
	LV_KEYDOWN* pKeyDown = (LV_KEYDOWN *) pNotifyStruct;

	if (pKeyDown->wVKey == VK_DELETE)
	{
		BOOL bShowWarnings = ((CDBViewApp *)AfxGetApp())->m_bShowWarnings;
		int retCode = IDYES;
		if (bShowWarnings)
		{
			retCode = MessageBox(
				_T("Are you sure you want to delete this item ?"),
				_T("DBViewer - Warning"),MB_YESNO);

			if (retCode == IDYES)
				DeleteRecord();
		}
		else
			DeleteRecord();
	}

	*result = 0;
}

void CDBListView::DeleteRecord()
{
	CCommand<CManualAccessor> rs;
	TCHAR   (*lpszParams)[40] = NULL;
	ULONG   ulParams = 0;
	CListCtrlEx&    ctlList = (CListCtrlEx&) GetListCtrl();

	// If we were in a multiple result set situation, just
	// ignore the command
	if (m_pMultipleCommand != NULL)
		return;

	// Check to see if we are editable or not
	// Get the first selected item.
	int nRow = ctlList.GetNextItem(-1, LVNI_SELECTED);
	if (nRow == -1)
		return;

	CDBPropSet propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY,
				DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);

	SelectRecord(nRow, &rs, &lpszParams, &ulParams);

	// Execute the Query
	HRESULT hr = rs.Open(&propset);
	if (hr == S_OK)
	{
		if (rs.MoveNext() == S_OK)
			rs.Delete();
	}
	if (lpszParams != NULL)
		delete []lpszParams;

	ctlList.DeleteItem(nRow);
//  DisplayData(rs);
}

HRESULT CDBListView::SelectRecord(int nRow, CCommand<CManualAccessor>* pRS,
	TCHAR (**lpszColumns)[40], ULONG* pulColumns)
{
	USES_CONVERSION;
	CStringList         strList;
	CList<ULONG, ULONG> colList;
	CPrimaryKeys*       pKeys = NULL;
	CListCtrlEx&        ctlList = (CListCtrlEx&) GetListCtrl();
	CString             strQuery;
	ULONG               nParams = 0;
	HRESULT             hr;

	ASSERT(nRow > -1);
	ATLENSURE(pulColumns != NULL);
	ATLENSURE(pRS != NULL);
	ATLENSURE(lpszColumns != NULL);

	strQuery.Format("select * from %s where ", m_strTable);

	// Get primary keys for rowset
	pKeys = new CPrimaryKeys;
	hr = pKeys->Open(*m_pSession, NULL, NULL, m_strTable);

	if (FAILED(hr))
	{
		delete pKeys;
		return hr;
	}

	while (pKeys->MoveNext() == S_OK)
	{
		// Maintain a list of indexes
		strList.AddTail(pKeys->m_szColumnName);
		colList.AddTail(pKeys->m_nOrdinal);
	}

	delete pKeys;
	pKeys = NULL;

	if (strList.IsEmpty())
		return E_FAIL;

	POSITION pos = strList.GetHeadPosition();
	nParams = (ULONG) strList.GetCount();
	*pulColumns = nParams;
	ASSERT(nParams > 0);
	*lpszColumns = new TCHAR[nParams][40];

	// Set up the Query String
	while (pos != NULL)
	{
		CString strIndex;
		CString strKey = strList.GetNext(pos);

		strIndex.Format(" %s = ?", strKey);
		strQuery += strIndex;

		if (pos != NULL)
			strQuery += ",";
	}

	POSITION posCol = colList.GetHeadPosition();
	pRS->CreateParameterAccessor(nParams, *lpszColumns[0],
		sizeof(TCHAR)*40*nParams);
	ULONG ulNextParam = 0;
	while (posCol != NULL)
	{
		pRS->AddParameterEntry(ulNextParam+1, DBTYPE_STR, sizeof(TCHAR)*40,
			*lpszColumns[ulNextParam]);

		LV_ITEM lvIndexItem;

		ASSERT(ulNextParam < nParams);

		ULONG ulCol = colList.GetNext(posCol);
		lvIndexItem.mask = LVIF_TEXT;
		lvIndexItem.pszText = *lpszColumns[ulNextParam];
		lvIndexItem.cchTextMax = 40;
		lvIndexItem.iItem = nRow;
		lvIndexItem.iSubItem = ulCol-1;
		ctlList.GetItem(&lvIndexItem);

		ulNextParam++;
	}

	// Set the command text for execution
	pRS->Create(*m_pSession, strQuery);
	return S_OK;
}

void CDBListView::OnUpdateNextResult(CCmdUI* pCmdUI)
{
	if (m_pMultipleCommand != NULL)
		pCmdUI->Enable();
	else
		pCmdUI->Enable(false);
}

void CDBListView::OnNextResult()
{
	USES_CONVERSION;

	if (m_pMultipleCommand == NULL)
		return; // no opened command available.

	EraseList();

	if (m_pMultipleCommand->m_spRowset != NULL)
	{
		CListCtrlEx&                ctlList     = (CListCtrlEx&) GetListCtrl();

		// Get the column information and bind the output columns.
		DBORDINAL		ulColumns = NULL;
		DBCOLUMNINFO*   pColumnInfo = NULL;
		OLECHAR*        pColumnNames = NULL;
		CSimpleArray<OLECHAR *> aNames;
		struct MYBIND*  pColumns    = NULL;

		if (m_pMultipleCommand->GetColumnInfo(&ulColumns,
			&pColumnInfo, &pColumnNames) != S_OK)
		{
			delete m_pMultipleCommand;
			m_pMultipleCommand = NULL;
			return;
		}

		if (ulColumns > 0)
		{
			for (unsigned int i=0; i<ulColumns; i++)
				aNames.Add(L"");
			pColumns = new MYBIND[ulColumns];
			
			m_pMultipleCommand->CreateAccessor((int)ulColumns,
				&pColumns[0], sizeof(MYBIND)*ulColumns);

			for (ULONG l=0; l<ulColumns; l++)
			{
				aNames[l] = pColumnNames;
				if (*pColumnNames)
				{
					while(*pColumnNames++)
						;
				}
				ctlList.AddColumn(COLE2T(aNames[l]), l+1);
				#pragma warning(suppress: 6011) // unexpected null dereference prefast warning
				m_pMultipleCommand->AddBindEntry(l+1, DBTYPE_STR,
					sizeof(TCHAR)*40, &pColumns[l].szValue,
					NULL, &pColumns[l].dwStatus);
			}
		}
		CoTaskMemFree(pColumnInfo);
		for (unsigned int i = 0; i < ulColumns; i++)
		{
			CoTaskMemFree(aNames[i]);
		}
		m_ulFields = (ULONG) ulColumns;
		m_pMultipleCommand->Bind();
		DisplayData((CRowset<CManualAccessor>*)m_pMultipleCommand, pColumns);
		delete [] pColumns;
		pColumns = NULL;
	}
	else
	{
		// Set the window text with the return value.
		CString strReturn;
		strReturn.Format("Stored procedure returned %ld\n", m_lRows);
		((CFrameWnd *) AfxGetMainWnd())->SetMessageText(strReturn);
	}

	// Get the next result set
	HRESULT hr;
	hr = m_pMultipleCommand->GetNextResult(&m_lRows, false);

	if (FAILED(hr) || hr == DB_S_NORESULT)
	{
		delete m_pMultipleCommand;
		m_pMultipleCommand = NULL;
	}
}
