// tlblist.cpp : implementation file
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
#include "iview.h"
#include "util.h"
#include "iviewers.h"
#include "iviewer.h"
#include "typelib.h"
#include "tlblist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define ID_LISTVIEW 43
/////////////////////////////////////////////////////////////////////////////
// CTypeLibListView

IMPLEMENT_DYNCREATE(CTypeLibListView, CView)

CTypeLibListView::CTypeLibListView()
{
}

CTypeLibListView::~CTypeLibListView()
{
}


BEGIN_MESSAGE_MAP(CTypeLibListView, CView)
	//{{AFX_MSG_MAP(CTypeLibListView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CTypeLibListView diagnostics

#ifdef _DEBUG
void CTypeLibListView::AssertValid() const
{
	CView::AssertValid();
}

void CTypeLibListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTypeLibListView message handlers

int CTypeLibListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	RECT rect ;
	rect.top = lpCreateStruct->y ;
	rect.left = lpCreateStruct->x ;
	rect.bottom = lpCreateStruct->cy ;
	rect.right = lpCreateStruct->cx ;

	if (!m_list.Create( WS_CHILD | WS_VISIBLE |
								WS_BORDER |
								LVS_REPORT |
//                                LVS_BUTTON |
								LVS_SINGLESEL |
								LVS_NOSORTHEADER,
								rect, this, ID_LISTVIEW ))
	{
		TRACE( _T("List control failed to create!") ) ;
		return -1 ;
	}

	return 0;
}

void CTypeLibListView::OnDestroy()
{
	CView::OnDestroy();
	m_list.DeleteAllItems() ;
}

void CTypeLibListView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class

}

void CTypeLibListView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_list.SetWindowPos( NULL, -1, -1, cx+2, cy+2, SWP_NOZORDER ) ;

}

void CTypeLibListView::OnInitialUpdate()
{
	TRACE(_T("OnInitialUpdate\n")) ;
	CTypeLibWnd* pFrame = (CTypeLibWnd*)GetParent()->GetParent() ;
	ASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CTypeLibWnd)));


	CView::OnInitialUpdate();
}

void CTypeLibListView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
}
