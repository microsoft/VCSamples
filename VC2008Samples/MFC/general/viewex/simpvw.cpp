// simpvw.cpp : implementation of the simple view classes
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
#include "viewex.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	//{{AFX_MSG_MAP(CTextView)
	ON_WM_MOUSEACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView construction/destruction

CTextView::CTextView()
{
}

CTextView::~CTextView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CMainDoc* pDoc = GetDocument();

	CRect rect;
	GetClientRect(rect);
	pDC->SetTextAlign(TA_BASELINE | TA_CENTER);
	pDC->SetTextColor(pDoc->m_colorData);
	pDC->SetBkMode(TRANSPARENT);
	// center in the window
	pDC->TextOut(rect.Width() / 2, rect.Height() / 2,
		pDoc->m_strData, pDoc->m_strData.GetLength());
}


int CTextView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// side-step CView's implementation since we don't want to activate
	//  this view
	return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

/////////////////////////////////////////////////////////////////////////////
// CColorView

IMPLEMENT_DYNCREATE(CColorView, CView)

BEGIN_MESSAGE_MAP(CColorView, CView)
	//{{AFX_MSG_MAP(CColorView)
	ON_WM_MOUSEACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorView construction/destruction

CColorView::CColorView()
{
}

CColorView::~CColorView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CColorView drawing

void CColorView::OnDraw(CDC* pDC)
{
	CMainDoc* pDoc = GetDocument();

	CRect rect;
	GetClientRect(rect);

	// fill the view with the specified color
	CBrush br(pDoc->m_colorData);
	pDC->FillRect(rect, &br);
}

int CColorView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// side-step CView's implementation since we don't want to activate
	//  this view
	return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

void CColorView::OnActivateView(BOOL, CView*, CView*)
{
	ASSERT(FALSE);      // output only view - should never be active
}


/////////////////////////////////////////////////////////////////////////////
