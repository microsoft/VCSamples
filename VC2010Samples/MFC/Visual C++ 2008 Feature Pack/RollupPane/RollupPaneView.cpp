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
#include "RollupPane.h"

#include "RollupPaneDoc.h"
#include "RollupPaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRollupPaneView

IMPLEMENT_DYNCREATE(CRollupPaneView, CView)

BEGIN_MESSAGE_MAP(CRollupPaneView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
END_MESSAGE_MAP()

// CRollupPaneView construction/destruction

CRollupPaneView::CRollupPaneView()
{
	// TODO: add construction code here

}

CRollupPaneView::~CRollupPaneView()
{
}

BOOL CRollupPaneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRollupPaneView drawing

void CRollupPaneView::OnDraw(CDC* /*pDC*/)
{
//	CRollupPaneDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


// CRollupPaneView printing

void CRollupPaneView::OnFilePrintPreview()
{
	AFXPrintPreview (this);
}

BOOL CRollupPaneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRollupPaneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRollupPaneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CRollupPaneView diagnostics

#ifdef _DEBUG
void CRollupPaneView::AssertValid() const
{
	CView::AssertValid();
}

void CRollupPaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRollupPaneDoc* CRollupPaneView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRollupPaneDoc)));
	return (CRollupPaneDoc*)m_pDocument;
}
#endif //_DEBUG


// CRollupPaneView message handlers
