// ChildView.cpp : implementation of the CChildView class
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "ScreenCap.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CChildView message handlers
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::SetImage(const CString &strPath)
{
	if (!m_image.IsNull())
		m_image.Destroy();

	HRESULT hr = m_image.Load(strPath);
	if (FAILED(hr)) {
		TRACE("Image Load Failed: %x\n", hr);
	}
	Invalidate();
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// Do not call CWnd::OnPaint() for painting messages
	if (m_image.IsNull())
		return;
	CRect rect;
	GetClientRect(rect);
	// In a real app you would probably want to maintain aspect ratio.
	dc.SetStretchBltMode(HALFTONE);
	m_image.StretchBlt(dc, rect);
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	if (m_image.IsNull())
		return(CWnd::OnEraseBkgnd(pDC));
	return(TRUE);
}
