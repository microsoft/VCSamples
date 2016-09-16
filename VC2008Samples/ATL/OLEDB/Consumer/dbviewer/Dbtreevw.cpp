// DBTreeVw.cpp : implementation file
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
#include "dlgsql.h"
#include "dbexcept.h"
#include "errordlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBTreeView

IMPLEMENT_DYNCREATE(CDBTreeView, CTreeView)

CDBTreeView::CDBTreeView()
{
	m_pSession = NULL;
}

CDBTreeView::~CDBTreeView()
{
	m_pSession = NULL;
}


BEGIN_MESSAGE_MAP(CDBTreeView, CTreeView)
	//{{AFX_MSG_MAP(CDBTreeView)
	ON_WM_CREATE()
	ON_WM_SYSCOLORCHANGE()
	ON_COMMAND(ID_QUERY_EDIT, OnQueryEdit)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_TABLE_SCHEMA, ID_QUERY_RUN, OnPopupCommand)
	ON_NOTIFY_REFLECT(TVN_KEYDOWN, OnKeyDown)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnNodeSelect)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRightClick)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDBTreeView diagnostics

#ifdef _DEBUG
void CDBTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CDBTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CDBViewDoc* CDBTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBViewDoc)));
	return (CDBViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBTreeView message handlers

int CDBTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	GetDocument()->m_pTreeView = this;

	// Create the Image List
	m_ctlImage.Create(IDB_IMAGELIST3, 16, 0, RGB(255,0,255));
	m_ctlImage.SetBkColor(GetSysColor(COLOR_WINDOW));

	/// Attach image list to Tree
	CTreeCtrlEx& ctlTree = (CTreeCtrlEx&) GetTreeCtrl();
	ctlTree.SetImageList(&m_ctlImage);

	m_dropTarget.Register(this);

	return 0;
}

void CDBTreeView::OnSysColorChange()
{
	CWnd::OnSysColorChange();

	// Reset the background color of our image list when notified
	m_ctlImage.SetBkColor(GetSysColor(COLOR_WINDOW));
}

void CDBTreeView::OnQueryEdit()
{
	USES_CONVERSION;
	ATLENSURE(m_pSession);
	CListCtrlEx&        ctlList = (CListCtrlEx&) GetDocument()->m_pListView->GetListCtrl();

	CDlgSQL dlgSQL;
	dlgSQL.m_bEditMode = TRUE;

	// GetString
	if (dlgSQL.DoModal() != IDOK)
		return;
	TRY
	{
		CDBPropSet propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY,
					DBPROPVAL_UP_INSERT | DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_DELETE);

		// Open but don't bind.
		CCommand<CManualAccessor> rs;
		if (rs.Open(*m_pSession, dlgSQL.m_strSQL, &propset,	NULL, 
				DBGUID_DBSQL, FALSE) != S_OK)
		{
			AfxMessageBox(_T("Couldn't open rowset"));
			return;
		}

		// If a valid rowset is not returned (i.e. like running an INSERT
		// statement, then exit the routine
		if (rs.m_spRowset == NULL)
		{
			GetDocument()->m_pListView->UpdateWindow();
			PopulateTree();
			AfxMessageBox(IDS_SUCCESSFUL);
			return;
		}

		// Get the column information
		DBORDINAL ulColumns             = 0;
		DBCOLUMNINFO* pColumnInfo   = NULL;
		LPOLESTR pStrings           = NULL;
		if (rs.GetColumnInfo(&ulColumns, &pColumnInfo, &pStrings) != S_OK)
			ThrowOLEDBException(rs.m_spRowset, IID_IColumnsInfo);

		struct MYBIND* pBind = new MYBIND[ulColumns];
		rs.CreateAccessor((int) ulColumns, &pBind[0], sizeof(MYBIND)*ulColumns);
		for (ULONG l=0; l<ulColumns; l++)
			rs.AddBindEntry(l+1, DBTYPE_STR, sizeof(TCHAR)*40, &pBind[l].szValue,
				NULL, &pBind[l].dwStatus);
		rs.Bind();

		// Display the data (to the maximum # of records allowed)
		int nMaxRecords = ((CDBViewApp*)AfxGetApp())->m_nMaxRecords;
		int nItem=0;
		ULONG ulFields = (ULONG) rs.GetColumnCount();
		GetDocument()->m_pListView->EraseList();
		while(rs.MoveNext() == S_OK)
		{
			if (nItem < nMaxRecords)
			{
				for (ULONG j=1; j<=ulFields; j++)
				{
					if (nItem == 0)
						ctlList.AddColumn(COLE2T(pColumnInfo[j-1].pwszName), j-1);
					#pragma warning(suppress: 6011) // unexpected null dereference prefast warning. 
					if (pBind[j-1].dwStatus == DBSTATUS_S_ISNULL)
					{
						ctlList.AddItem(nItem, j-1, _T(""));
					}
					else
					{
						LPTSTR lpszString = pBind[j-1].szValue;
						ctlList.AddItem(nItem, j-1, lpszString);
					}
				}
				nItem++;
			}
		}
		CoTaskMemFree(pColumnInfo);
		CoTaskMemFree(pStrings);
		delete [] pBind;
		pBind = NULL;
	}
	CATCH(COLEDBException, e)
	{
		CErrorsDialog dlg;
		dlg.Init(e->m_lpUnk, e->m_iid);
		dlg.DoModal();
	}
	END_CATCH

	GetDocument()->m_pListView->UpdateWindow();
}

void CDBTreeView::OnPopupCommand(UINT nMenuID)
{
	CWaitCursor w;
	GetDocument()->m_pListView->SetRedraw(FALSE);
	switch (nMenuID)
	{
		case ID_TABLE_SCHEMA:
			GetDocument()->m_pListView->ShowTableSchema(m_ItemSel.GetText());
			break;
		case ID_TABLE_DATA:
			GetDocument()->m_pListView->ShowTableData(m_ItemSel.GetText());
			break;
		case ID_TABLE_INSERT:
			GetDocument()->m_pListView->InsertRecord(m_ItemSel.GetText());
			break;
		case ID_QUERY_RUN:
			GetDocument()->m_pListView->CallProcedure(m_ItemSel.GetText());
			break;
		default:
			break;
	}
	GetDocument()->m_pListView->SetRedraw(TRUE);
}

void CDBTreeView::OnKeyDown(NMHDR *pNotifyStruct,LRESULT *result)
{
	TV_KEYDOWN* pKeyDown = (TV_KEYDOWN *) pNotifyStruct;

	if (pKeyDown->wVKey == VK_DELETE)
	{
		BOOL bShowWarnings = ((CDBViewApp *)AfxGetApp())->m_bShowWarnings;
		int retCode = IDYES;
		if (bShowWarnings)
		{
			retCode = MessageBox(
				_T("Are you sure you want to delete this item ?"),
				_T("DBViewer - Warning"),MB_YESNO);
		}
		if (retCode == IDYES)
			DeleteItem(m_ItemSel);
	}
	*result = 0;
}

void CDBTreeView::OnNodeSelect(NMHDR *, LRESULT *result)
{
	*result = 0;

	if (m_bNoNotifications)
		return;

	CTreeCtrlEx& ctlTree = (CTreeCtrlEx&) GetTreeCtrl();

	m_ItemSel = ctlTree.GetSelectedItem();

	UINT nImageID = m_ItemSel.GetImageID();
	GetDocument()->m_pListView->SetRedraw(FALSE);

	switch (nImageID)
	{
		case IID_DATABASE:
//          GetDocument()->m_pListView->ShowDatabase();
			break;
		case IID_TABLES:
			GetDocument()->m_pListView->ShowTableSchema(NULL);
			break;
		case IID_TABLE:
			GetDocument()->m_pListView->ShowTableSchema(m_ItemSel.GetText());
			break;
		case IID_FIELDS:
//          GetDocument()->m_pListView->ShowFields(m_ItemSel.GetParent().GetText());
			break;
		case IID_FIELD:
//          GetDocument()->m_pListView->ShowFields(m_ItemSel.GetParent().GetParent().GetText(),m_ItemSel.GetText());
			break;
		case IID_PROCEDURES:
			GetDocument()->m_pListView->ShowProcedures(NULL);
			break;
		case IID_PROCEDURE:
			GetDocument()->m_pListView->ShowProcedures(m_ItemSel.GetText());
			break;
		case IID_VIEWS:
			GetDocument()->m_pListView->ShowTableSchema(NULL);
			break;
		case IID_VIEW:
			GetDocument()->m_pListView->ShowTableSchema(m_ItemSel.GetText());
			break;
		case IID_INDEXES:
//          GetDocument()->m_pListView->ShowIndexes(m_ItemSel.GetParent().GetText());
			break;
		case IID_INDEX:
//          GetDocument()->m_pListView->ShowIndexes(m_ItemSel.GetParent().GetParent().GetText(),m_ItemSel.GetText());
			break;
	}

	GetDocument()->m_pListView->SetRedraw(TRUE);
}

void CDBTreeView::OnRightClick(NMHDR *, LRESULT *result)
{
	CTreeCtrlEx& ctlTree = (CTreeCtrlEx&) GetTreeCtrl();

	UINT nFlags;
	CPoint curPoint;
	GetCursorPos(&curPoint);
	ScreenToClient(&curPoint);
	m_ItemSel = ctlTree.HitTest(curPoint, &nFlags);

	UINT nImageID = m_ItemSel.GetImageID();
	switch (nImageID)
	{
		case IID_TABLE:
		case IID_VIEW:
			DoPopupMenu(IDR_POPUP_TABLE);
			break;
		case IID_PROCEDURE:
			DoPopupMenu(IDR_POPUP_QUERY);
			break;
	}
	*result = 0;
}

void CDBTreeView::DoPopupMenu(UINT nMenuID)
{
	CMenu popMenu;

	popMenu.LoadMenu(nMenuID);

	CPoint posMouse;
	GetCursorPos(&posMouse);

	popMenu.GetSubMenu(0)->TrackPopupMenu(0,posMouse.x,posMouse.y,this);
}


/////////////////////////////////////////////////////////////////////////////
// CDBTreeView implementation functions

void CDBTreeView::PopulateTree()
{
	USES_CONVERSION;
	CTreeCtrlEx& ctlTree = (CTreeCtrlEx&) GetTreeCtrl();
	CTables*        pTableSet = NULL;
	CProcedures*    pProcedureSet = NULL;

	m_bNoNotifications = TRUE;

	ctlTree.DeleteAllItems();
	UpdateWindow();

	// If session is unavailable, we don't have a valid connection.  Therefore,
	// there is no requirement to populate the tree
	if (!m_pSession)
		return;

	// Insert root node by call to tree object this time
	tDatabase = ctlTree.GetRootItem().AddTail(GetDocument()->GetDSN(),
							IID_DATABASE);

	// From now on call via iterators
	tTables = tDatabase.AddTail(_T("Tables"),IID_TABLES);
	tProcedures = tDatabase.AddTail(_T("Procedures"),IID_PROCEDURES);

//	BOOL bShowSystemObjects = ((CDBViewApp *)AfxGetApp())->m_bShowSystemObjects;


	// List the tables in the data source
	// Add an entry for all tables in the system
	pTableSet = new CTables;

	// (can simply hard code max size)
	char lpszType[64];

	// Set up type type to be retrieved
	strcpy_s(lpszType, 64, "TABLE");
	if (((CDBViewApp *)AfxGetApp())->m_bShowSystemObjects)
		strcat_s(lpszType, 64, ",SYSTEM TABLE");

	if (pTableSet->Open(*m_pSession, NULL, NULL, NULL, lpszType) != S_OK)
	{
		delete pTableSet;
		return;
	}
	while(pTableSet->MoveNext() == S_OK)
	{
		if (_tcscmp(pTableSet->m_szType, _T("VIEW")) == 0)
			AddItem(IID_VIEW, pTableSet->m_szName);
		else
			AddItem(IID_TABLE, pTableSet->m_szName);
	}

	delete pTableSet;
	pTableSet = NULL;

	// List the stored procedures in the data source
	// Get the Procedures Here
	pProcedureSet = new CProcedures;

	// Get all procedure names
	if (pProcedureSet->Open(*m_pSession) != S_OK)
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

		AddItem(IID_PROCEDURE, pProcedureSet->m_szName);
	}

	delete pProcedureSet;
	pProcedureSet = NULL;

	tDatabase.Expand();
	m_bNoNotifications = FALSE;
	UpdateWindow();
}

void CDBTreeView::AddItem(WORD nItemType, LPCTSTR lpszName)
{
	switch (nItemType)
	{
		case IID_TABLE:
		{
			tTable = tTables.AddTail(lpszName, IID_TABLE);
			break;
		}
		case IID_PROCEDURE:
		{
			tProcedures.AddTail(lpszName, IID_PROCEDURE);
			break;
		}
		case IID_VIEW:
		{
			tTable = tTables.AddTail(lpszName, IID_VIEW);
			break;
		}
	}
}

void CDBTreeView::DeleteItem(CTreeCursor& itemDelete)
{
	CString strText;
	CCommand<CDynamicAccessor> rs;
	strText.Format(_T("DROP TABLE %s"), itemDelete.GetText());
	rs.Open(*m_pSession, strText, NULL, NULL, DBGUID_DEFAULT, false);
//  rs.Close();
	itemDelete.Delete();
}
