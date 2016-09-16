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
#include "MenuSubSet.h"

#include "MenuSubSetDoc.h"
#include "MenuSubSetView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetView

IMPLEMENT_DYNCREATE(CMenuSubSetView, CFormView)

BEGIN_MESSAGE_MAP(CMenuSubSetView, CFormView)
	ON_COMMAND(ID_DEMO_DEMO1, OnDemoDemo1)
	ON_COMMAND(ID_DEMO_DEMO2, OnDemoDemo2)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetView construction/destruction

CMenuSubSetView::CMenuSubSetView()
	: CFormView(CMenuSubSetView::IDD)
{
	// TODO: add construction code here

}

CMenuSubSetView::~CMenuSubSetView()
{
}

void CMenuSubSetView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMenuSubSetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMenuSubSetView::OnInitialUpdate()
{
	// There is only one view ever, so it only needs to do the initial
	// update once--otherwise the application is  resized needlessly.
	static BOOL bUpdatedOnce = FALSE;
	if (bUpdatedOnce)
		return;
	bUpdatedOnce = TRUE;

	CFormView::OnInitialUpdate();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetView printing

void CMenuSubSetView::OnFilePrintPreview() 
{
	AFXPrintPreview (this);
}

BOOL CMenuSubSetView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuSubSetView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuSubSetView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMenuSubSetView::OnPrint(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetView diagnostics

#ifdef _DEBUG
void CMenuSubSetView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMenuSubSetView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMenuSubSetDoc* CMenuSubSetView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuSubSetDoc)));
	return (CMenuSubSetDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetView message handlers

void CMenuSubSetView::OnContextMenu(CWnd*, CPoint point)
{
	theApp.ShowPopupMenu (IDR_CONTEXT_MENU, point, this);
}

void CMenuSubSetView::OnDemoDemo1() 
{
	MessageBox (_T("Demo 1"));
}

void CMenuSubSetView::OnDemoDemo2() 
{
	MessageBox (_T("Demo 2"));
}
