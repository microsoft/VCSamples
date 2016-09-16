// EmpView.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "DBVList.h"
#include "DBVListSet.h"
#include "DBVListDoc.h"

#include "EmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmpView

IMPLEMENT_DYNCREATE(CEmpView, CListView)

CEmpView::CEmpView()
{
	m_dwDefaultStyle |= ( LVS_REPORT | LVS_OWNERDATA );
}

CEmpView::~CEmpView()
{
}


BEGIN_MESSAGE_MAP(CEmpView, CListView)
	//{{AFX_MSG_MAP(CEmpView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_NOTIFY_RANGE(LVN_COLUMNCLICK,0,0xffff,OnColumnClick)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmpView diagnostics

#ifdef _DEBUG
void CEmpView::AssertValid() const
{
	CListView::AssertValid();
}

void CEmpView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CDBVListDoc* CEmpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBVListDoc)));
	return (CDBVListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEmpView message handlers

void CEmpView::PrepareCache(int /*iFrom*/, int /*iTo*/)
{
}

void CEmpView::GetDispInfo(LVITEM* pItem)
{
	CDBVListSet* pSet = &GetDocument()->m_dBVListSet;

	// called when the listview needs to display data
	if(pItem->mask & LVIF_TEXT)
	{
		// first, move to the appropriate row in the database
		pSet->MoveFirst();
		pSet->Move(pItem->iItem);

		if(!pSet->IsEOF())
		{
			// then display the appropriate column
			switch(pItem->iSubItem)
			{
			case 0:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Email);
				break;
			case 1:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Name);
				break;
			case 2:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Phone);
				break;
			case 3:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Location);
				break;
			case 4:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Title);
				break;
			case 5:
				_tcscpy_s(pItem->pszText, pItem->cchTextMax, (LPCTSTR)pSet->m_Department);
				break;
			}
		}
	}
}

int CEmpView::FindItem(int /*iStart*/, LVFINDINFO* /*plvfi*/)
{
	return -1;
}

void CEmpView::UpdateFilter(CString strCurQuery)
{
	// convenience function to set the SQL filter for the query

	CDBVListSet* pSet = &GetDocument()->m_dBVListSet;

	pSet->SetFilter(strCurQuery);

	// set the item count to the new record count
	int nRecordCount = 0;
	if (pSet->IsOpen())
	{
		nRecordCount=pSet->GetRecordCount();
	}
	GetListCtrl().SetItemCountEx(nRecordCount);

	// Invalidate the listview so it will redraw itself
	Invalidate();
}

void CEmpView::OnInitialUpdate()
{
	//initialise columns in the listview

	CListView::OnInitialUpdate();

	LV_COLUMN lvc;

	lvc.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;

	lvc.iSubItem = 0;
	lvc.pszText = _T("Email");
	lvc.cx = 75;
	GetListCtrl().InsertColumn(0,&lvc);
	lvc.iSubItem = 1;
	lvc.pszText = _T("Name (First, Last)");
	lvc.cx = 125;
	GetListCtrl().InsertColumn(1,&lvc);
	lvc.iSubItem = 2;
	lvc.pszText = _T("Phone");
	lvc.cx = 75;
	GetListCtrl().InsertColumn(2,&lvc);
	lvc.iSubItem = 3;
	lvc.pszText = _T("Location");
	lvc.cx = 75;
	GetListCtrl().InsertColumn(3,&lvc);
	lvc.iSubItem = 4;
	lvc.pszText = _T("Title");
	lvc.cx = 150;
	GetListCtrl().InsertColumn(4,&lvc);
	lvc.iSubItem = 5;
	lvc.pszText = _T("Dept");
	lvc.cx = 150;
	GetListCtrl().InsertColumn(5,&lvc);
}

void CEmpView::OnColumnClick(UINT /*id*/, NMHDR* pNotifyStruct, LRESULT* /*pResult*/)
{
	// when a column is clicked on, sort by that column

	CDBVListSet* pSet = &GetDocument()->m_dBVListSet;

	switch(reinterpret_cast<NMLISTVIEW*>(pNotifyStruct)->iSubItem)
	{
	case 0:
		pSet->SetSort(_T("[Email]"));
		break;
	case 1:
		pSet->SetSort(_T("[Name]"));
		break;
	case 2:
		pSet->SetSort(_T("[Phone]"));
		break;
	case 3:
		pSet->SetSort(_T("[Location]"));
		break;
	case 4:
		pSet->SetSort(_T("[Title]"));
		break;
	case 5:
		pSet->SetSort(_T("[Department]"));
		break;
	case 6:
		pSet->SetSort(_T("[Division]"));
		break;
	}
	Invalidate();
}

BOOL CEmpView::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if(message == WM_NOTIFY)
	{
		NMHDR* phdr = (NMHDR*)lParam;

		// these 3 notifications are only sent by virtual listviews
		switch(phdr->code)
		{
		case LVN_GETDISPINFO:
			{
				NMLVDISPINFO* pLvdi;

				pLvdi = (NMLVDISPINFO*)lParam;
				GetDispInfo(&pLvdi->item);
			}
			if(pResult != NULL)
			{
				*pResult = 0;
			}
			break;
		case LVN_ODCACHEHINT:
			{
				NMLVCACHEHINT* pHint = (NMLVCACHEHINT*)lParam;

				PrepareCache(pHint->iFrom, pHint->iTo);
			}
			if(pResult != NULL)
			{
				*pResult = 0;
			}
			break;
		case LVN_ODFINDITEM:
			{
				NMLVFINDITEM* pFindItem = (NMLVFINDITEM*)lParam;
				int i = FindItem(pFindItem->iStart, &pFindItem->lvfi);
				if(pResult != NULL)
				{
					*pResult = i;
				}
			}
			break;
		default:
			return CListView::OnChildNotify(message, wParam, lParam, pResult);
		}
	}
	else
		return CListView::OnChildNotify(message, wParam, lParam, pResult);

	return TRUE;
}
