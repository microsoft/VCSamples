// Cat3View.cpp : implementation of the CCatDBView class
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
#include "CatDB.h"

#include "CatDBDoc.h"
#include "CatDBVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCatDBView

IMPLEMENT_DYNCREATE(CCatDBView, CListView)

BEGIN_MESSAGE_MAP(CCatDBView, CListView)
	//{{AFX_MSG_MAP(CCatDBView)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLUMNINFO, OnUpdateViewColumnlevel)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TABLES, OnUpdateViewTablelevel)
	ON_COMMAND(ID_VIEW_COLUMNINFO, OnViewColumnlevel)
	ON_COMMAND(ID_VIEW_TABLES, OnViewTablelevel)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatDBView construction/destruction

CCatDBView::CCatDBView()
{
}

CCatDBView::~CCatDBView()
{
}

BOOL CCatDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// set list view control to report, single selection
	cs.style &= ~(LVS_LIST | LVS_ICON | LVS_SMALLICON);
	cs.style |= LVS_REPORT;
	cs.style |= LVS_SINGLESEL;

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCatDBView drawing

void CCatDBView::OnDraw(CDC* )
{
	CCatDBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CCatDBView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CCatDBView diagnostics

#ifdef _DEBUG
void CCatDBView::AssertValid() const
{
	CListView::AssertValid();
}

void CCatDBView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CCatDBDoc* CCatDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCatDBDoc)));
	return (CCatDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCatDBView message handlers

void CCatDBView::OnUpdateViewColumnlevel(CCmdUI* pCmdUI)
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_nLevel == CCatDBDoc::levelTable &&
		GetListCtrl().GetSelectedCount())
	{
		pCmdUI->Enable();
	}
	else
		pCmdUI->Enable(FALSE);
}

void CCatDBView::OnUpdateViewTablelevel(CCmdUI* pCmdUI)
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_nLevel == CCatDBDoc::levelColumn)
		pCmdUI->Enable();
	else
		pCmdUI->Enable(FALSE);
}

BOOL CCatDBView::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult)
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// handle double click if at table view level
	if (pDoc->m_nLevel == CCatDBDoc::levelTable)
	{
		if (message == WM_NOTIFY &&
			((NMHDR*)lParam)->code == NM_DBLCLK)
		{
			OnViewColumnlevel();
			return 0;
		}
	}

	return CListView::OnChildNotify(message, wParam, lParam, pLResult);
}

void CCatDBView::OnViewColumnlevel()
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// determine list control selection
	CListCtrl&  control = GetListCtrl();
	int nCount = control.GetItemCount();
	int i;
	for (i = 0; i < nCount; i++)
	{
		if (control.GetItemState(i,LVIS_SELECTED))
			break;
	}
	if (i < nCount)
	{
		// pull table name to send to document
		pDoc->m_strTableName = control.GetItemText(i,0);

#ifndef _UNICODE
		LPCSTR lpszName;
		lpszName = pDoc->m_strTableName;
#else
		LPSTR lpszName;
		char rgchTableName[257];
		lpszName = rgchTableName;
		int nSize;
		nSize = ::WideCharToMultiByte(CP_ACP,0,pDoc->m_strTableName,
			-1, lpszName, 257, NULL, NULL);
		// Notify on failure
		ASSERT(nSize);
#endif  // _UNICODE

		pDoc->FetchColumnInfo(lpszName);
		pDoc->SetLevel(CCatDBDoc::levelColumn);
	}
}

void CCatDBView::OnViewTablelevel()
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_strTableName.Empty();
	pDoc->FetchTableInfo();
	pDoc->SetLevel(CCatDBDoc::levelTable);
}

void CCatDBView::OnFileOpen()
{
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->OnOpenDocument())
		pDoc->SetLevel(CCatDBDoc::levelTable);
	else
		pDoc->SetLevel(CCatDBDoc::levelNone);
}

void CCatDBView::OnUpdate(CView* , LPARAM , CObject* )
{
	USES_CONVERSION;
	CCatDBDoc*  pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// delete all items and columns
	CListCtrl& control = GetListCtrl();
	control.DeleteAllItems();
	while (control.DeleteColumn(0));

	// set up view based on the document's level
	switch (pDoc->m_nLevel)
	{
		case CCatDBDoc::levelNone:

			// set the document title
			pDoc->SetTitle(pDoc->GetDSN());
			break;

		case CCatDBDoc::levelTable:
		{
			// set the document title
			CString strDataSource = pDoc->GetDSN();
			strDataSource += _T(" [Tables]");
			pDoc->SetTitle(strDataSource);

			// add columns to display
			control.InsertColumn(0,_T("Name"),LVCFMT_LEFT,100,-1);
			control.InsertColumn(1,_T("Type"),LVCFMT_LEFT,100,1);
			control.InsertColumn(2,_T("Catalog"),LVCFMT_LEFT,100,2);
			control.InsertColumn(3,_T("Schema"),LVCFMT_LEFT,100,3);
			control.InsertColumn(4,_T("Description"),LVCFMT_LEFT,100,4);

			// traverse the table recordset
			// displaying the table information
			int item = 0;
			while (pDoc->m_pTableset->MoveNext() == S_OK)
			{
				control.InsertItem(item,
					pDoc->m_pTableset->m_szName);
				control.SetItem(item,1,LVIF_TEXT,
					pDoc->m_pTableset->m_szType,0,0,0,0);
				control.SetItem(item,2,LVIF_TEXT,
					pDoc->m_pTableset->m_szCatalog,0,0,0,0);
				control.SetItem(item,3,LVIF_TEXT,
					pDoc->m_pTableset->m_szSchema,0,0,0,0);
				control.SetItem(item,4,LVIF_TEXT,
					pDoc->m_pTableset->m_szDescription,0,0,0,0);
				item++;
			}

			break;
		}

		case CCatDBDoc::levelColumn:
		{
			int column;

			// set the document title
			CString strDataSource = pDoc->GetDSN();
			strDataSource += _T(" - ");
			strDataSource += pDoc->m_strTableName;
			strDataSource += _T(" [Column Info]");
			pDoc->SetTitle(strDataSource);

			// add columns to display
			// respect the column info settings values
			column = 0;
			control.InsertColumn(column++,_T("Name"),LVCFMT_LEFT,100,-1);
			control.InsertColumn(column,_T("Type"),LVCFMT_LEFT,100,column++);
			if (pDoc->m_bLength)
				control.InsertColumn(column,_T("Length"),LVCFMT_LEFT,80,column++);
			if (pDoc->m_bPrecision)
			{
				control.InsertColumn(column,_T("Precision"),LVCFMT_LEFT,80,column++);
				control.InsertColumn(column,_T("Scale"),LVCFMT_LEFT,50,column++);
			}
			if (pDoc->m_bNullability)
				control.InsertColumn(column,_T("Nullable"),LVCFMT_LEFT,50,column++);

			// traverse the column info recordset
			// respect the column info settings values
			int item = 0;

			// If the column rowset couldn't be opened, don't attempt to fetch
			// any data.
			if (pDoc->m_pColumnset == NULL)
				break;

			while (pDoc->m_pColumnset->MoveNext() == S_OK)
			{
				CString strValue;

				// always insert the column name
				control.InsertItem(item, pDoc->m_pColumnset->m_szColumnName);

				// always insert the column type
				column = 1;
				CString strType;
				strType.Format("%d", pDoc->m_pColumnset->m_nDataType);
				control.SetItem(item,column++,LVIF_TEXT, strType,0,0,0,0);

				// only show type if requested
				if (pDoc->m_bLength)
				{
					strValue.Format(_T("%ld"),pDoc->m_pColumnset->m_nMaxLength);
					control.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);
				}

				// only show precision,scale,radix if requested
				if (pDoc->m_bPrecision)
				{
					// precision
					strValue.Format(_T("%d"),pDoc->m_pColumnset->m_nNumericPrecision);
					control.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);

					// scale
					strValue.Format(_T("%d"),pDoc->m_pColumnset->m_nNumericScale);
					control.SetItem(item,column++,LVIF_TEXT,strValue,0,0,0,0);
				}

				// only show nullability if requested
				if (pDoc->m_bNullability)
				{
					if (pDoc->m_pColumnset->m_bIsNullable == FALSE)
						control.SetItem(item,column++,LVIF_TEXT,_T("No"),0,0,0,0);
					else
						control.SetItem(item,column++,LVIF_TEXT,_T("Yes"),0,0,0,0);
				}

				item++;
			}
			break;
		}
	}
}
