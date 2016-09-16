// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "RibbonMDIDemo.h"

#include "RibbonMDIDemoDoc.h"
#include "RibbonMDIDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView

IMPLEMENT_DYNCREATE(CRibbonMDIDemoView, CView)

BEGIN_MESSAGE_MAP(CRibbonMDIDemoView, CView)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView construction/destruction

CRibbonMDIDemoView::CRibbonMDIDemoView()
{
	// TODO: add construction code here

}

CRibbonMDIDemoView::~CRibbonMDIDemoView()
{
}

BOOL CRibbonMDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView drawing

void CRibbonMDIDemoView::OnDraw(CDC* /*pDC*/)
{
//	CRibbonMDIDemoDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView printing

void CRibbonMDIDemoView::OnFilePrintPreview() 
{
	AFXPrintPreview (this);
}

BOOL CRibbonMDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRibbonMDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRibbonMDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView diagnostics

#ifdef _DEBUG
void CRibbonMDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRibbonMDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRibbonMDIDemoDoc* CRibbonMDIDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRibbonMDIDemoDoc)));
	return (CRibbonMDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoView message handlers

void CRibbonMDIDemoView::OnContextMenu(CWnd*, CPoint point)
{
	theApp.ShowPopupMenu (IDR_CONTEXT_MENU, point, this);
}
