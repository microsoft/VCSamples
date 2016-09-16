// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMoneyDemoView.cpp : implementation of the CMSMoneyDemoView class
//

#include "stdafx.h"
#include "MSMoneyDemo.h"

#include "MSMoneyDemoDoc.h"
#include "MSMoneyDemoView.h"

#include "MainFrm.h"

#include "MSMVisualManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView

IMPLEMENT_DYNCREATE(CMSMoneyDemoView, CView)

BEGIN_MESSAGE_MAP(CMSMoneyDemoView, CView)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView construction/destruction

CMSMoneyDemoView::CMSMoneyDemoView()
{
	// TODO: add construction code here

}

CMSMoneyDemoView::~CMSMoneyDemoView()
{
	m_sizeImage = CSize (0, 0);
}

BOOL CMSMoneyDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style &= ~WS_BORDER;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView drawing

void CMSMoneyDemoView::OnDraw(CDC* pDCView)
{
	CMemDC memDC (*pDCView, this);
	CDC* pDC = &memDC.GetDC ();

	CRect rectClient;
	GetClientRect (rectClient);

	pDC->FillSolidRect (rectClient, RGB (255, 255, 255));

	pDC->DrawState (CPoint (20, 20), m_sizeImage, &m_Image, DSS_NORMAL);
}

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView printing

BOOL CMSMoneyDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMSMoneyDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMSMoneyDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView diagnostics

#ifdef _DEBUG
void CMSMoneyDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMSMoneyDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMSMoneyDemoDoc* CMSMoneyDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMSMoneyDemoDoc)));
	return (CMSMoneyDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoView message handlers
// these are all simple one-liners to do simple controlling of the browser

BOOL CMSMoneyDemoView::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;
}

int CMSMoneyDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_Image.LoadBitmap (IDB_MSM_VIEW_BKGND);

	BITMAP bitmap;
	m_Image.GetBitmap (&bitmap);

	m_sizeImage = CSize (bitmap.bmWidth, bitmap.bmHeight);
	return 0;
}
