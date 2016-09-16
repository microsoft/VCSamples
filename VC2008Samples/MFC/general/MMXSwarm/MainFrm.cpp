// MainFrm.cpp : implementation of the CMainFrame class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#include "stdafx.h"
#include "MMXSwarm.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SIZING()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator

	ID_INDICATOR_RESOLUTION,
	ID_INDICATOR_FPS,
	ID_INDICATOR_PAUSE_BLIT,
	ID_INDICATOR_PAUSE_BLUR,
	ID_INDICATOR_PAUSE_SWARM,
};


/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
 
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||

		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}


	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	// Cut stretchy pane min width in 1/2 (to 1/8 of window)
	UINT nId, nStyle;
	int cxWidth;
	m_wndStatusBar.GetPaneInfo(0, nId, nStyle, cxWidth);
	ASSERT(nId == 0);
	cxWidth /= 2;
	m_wndStatusBar.SetPaneInfo(0, nId, nStyle, cxWidth);

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// Recalc the layout and update our initial size.
	RecalcLayout(TRUE);

	CRect frameRect;
	CRect viewRect;
	GetWindowRect(&frameRect);
	GetView()->GetClientRect(&viewRect);
	int dx;
	int dy;

#ifdef _DEBUG
	dx = 320 - viewRect.Width();
	dy = 240 - viewRect.Height();
#else
	dx = 640 - viewRect.Width();
	dy = 480 - viewRect.Height();
#endif

	SetWindowPos(NULL, 0, 0,
		frameRect.Width()+dx, frameRect.Height()+dy,
		SWP_NOMOVE|SWP_NOZORDER);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

 	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
 
void CMainFrame::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CFrameWnd::OnSizing(fwSide, pRect);

	// These shouldbe computed based on the
	// client window size - not the frame size.
	CRect rect(pRect);
    CRect viewRect;
    CRect frameRect;

	m_wndView.GetClientRect(viewRect);
    GetWindowRect(frameRect);
    int cx = frameRect.Width() - viewRect.Width();
    int cy = frameRect.Height() - viewRect.Height();
	const int kMinWidth = 96 + cx;
	const int kMinHeight = 64 + cy;

	if (rect.Width() < kMinWidth) {
		switch(fwSide) {
		case WMSZ_BOTTOMRIGHT:
		case WMSZ_RIGHT:
		case WMSZ_TOPRIGHT:
			pRect->right = rect.left + kMinWidth;
			break;
		default:
			pRect->left = rect.right - kMinWidth;
			break;
		}
	}
	if (rect.Height() < kMinHeight) {
		switch(fwSide) {
		case WMSZ_BOTTOM:
		case WMSZ_BOTTOMLEFT:
		case WMSZ_BOTTOMRIGHT: 
			pRect->bottom = rect.top + kMinHeight;
			break;
		default:
			pRect->top = rect.bottom - kMinHeight;
			break;
		}
	}
}
