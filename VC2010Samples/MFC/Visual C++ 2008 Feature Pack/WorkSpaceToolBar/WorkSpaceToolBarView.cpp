// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "WorkSpaceToolBar.h"

#include "WorkSpaceToolBarDoc.h"
#include "WorkSpaceToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView

IMPLEMENT_DYNCREATE(CWorkSpaceToolBarView, CView)

BEGIN_MESSAGE_MAP(CWorkSpaceToolBarView, CView)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView construction/destruction

CWorkSpaceToolBarView::CWorkSpaceToolBarView()
{
	// TODO: add construction code here

}

CWorkSpaceToolBarView::~CWorkSpaceToolBarView()
{
}

BOOL CWorkSpaceToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView drawing

void CWorkSpaceToolBarView::OnDraw(CDC* /*pDC*/)
{
	//CWorkSpaceToolBarDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView printing

void CWorkSpaceToolBarView::OnFilePrintPreview() 
{
	AFXPrintPreview (this);
}

BOOL CWorkSpaceToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWorkSpaceToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWorkSpaceToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView diagnostics

#ifdef _DEBUG
void CWorkSpaceToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CWorkSpaceToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkSpaceToolBarDoc* CWorkSpaceToolBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkSpaceToolBarDoc)));
	return (CWorkSpaceToolBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorkSpaceToolBarView message handlers

void CWorkSpaceToolBarView::OnContextMenu(CWnd*, CPoint point)
{
	theApp.ShowPopupMenu (IDR_CONTEXT_MENU, point, this);
}
