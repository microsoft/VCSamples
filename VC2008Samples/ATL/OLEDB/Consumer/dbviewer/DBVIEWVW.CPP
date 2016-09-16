// DBViewVw.cpp : implementation of the CDBViewView class
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

#include "DBDoc.h"
#include "DBViewVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBViewView

IMPLEMENT_DYNCREATE(CDBViewView, CTreeView)

BEGIN_MESSAGE_MAP(CDBViewView, CTreeView)
	//{{AFX_MSG_MAP(CDBViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBViewView construction/destruction

CDBViewView::CDBViewView()
{
	// TODO: add construction code here

}

CDBViewView::~CDBViewView()
{
}

BOOL CDBViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDBViewView drawing

void CDBViewView::OnDraw(CDC* pDC)
{
	CDBViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CDBViewView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CDBViewView diagnostics

#ifdef _DEBUG
void CDBViewView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CDBViewView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CDBViewDoc* CDBViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBViewDoc)));
	return (CDBViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBViewView message handlers
