// AClikVw.cpp : implementation of the CAutoClickView class
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
#include "AutoClik.h"

#include "AClikDoc.h"
#include "AClikVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView

IMPLEMENT_DYNCREATE(CAutoClickView, CView)

BEGIN_MESSAGE_MAP(CAutoClickView, CView)
	//{{AFX_MSG_MAP(CAutoClickView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView construction/destruction

CAutoClickView::CAutoClickView()
{
	// TODO: add construction code here

}

CAutoClickView::~CAutoClickView()
{
}

BOOL CAutoClickView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView drawing

void CAutoClickView::OnDraw(CDC* pDC)
{
	CAutoClickDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->TextOut(pDoc->m_pt.x, pDoc->m_pt.y, pDoc->m_str);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView printing

BOOL CAutoClickView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAutoClickView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAutoClickView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView diagnostics

#ifdef _DEBUG
void CAutoClickView::AssertValid() const
{
	CView::AssertValid();
}

void CAutoClickView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAutoClickDoc* CAutoClickView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoClickDoc)));
	return (CAutoClickDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoClickView message handlers

void CAutoClickView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CAutoClickDoc* pDoc = GetDocument();
	pDoc->m_pt = point;
	pDoc->Refresh();

	CView::OnLButtonDown(nFlags, point);
}
