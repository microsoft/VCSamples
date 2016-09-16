// mainfrm.cpp : implementation of the CMainFrame class
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
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_COMMAND(ID_EDIT_FIND_COMBO, OnEditFindCombo)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_VIEW_STATUS_BAR, OnUpdateViewStatusBar)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_LINE, OnUpdateLineNumber)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CLOCK, OnUpdateClock)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
		ID_SEPARATOR, //(8) CComboBox location in the toolbar
		ID_SEPARATOR,
	ID_FILE_PRINT,
	ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_LINE,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_CLOCK,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(buttons,
		  sizeof(buttons)/sizeof(UINT)))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!CreateComboBox())
	{
		TRACE0("Failed to create combobox in toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM , AFX_IDW_STATUS_BAR) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	DockControlBar(&m_wndToolBar);

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	// create the timer to update the status bar clock
	if(!SetTimer(TIMER_ID, 2000, &CMainFrame::UpdateTime))
		return -1;

	CMainFrame::UpdateTime(m_hWnd, 0, 0, 0); // update the time now

	return 0;
}

int CMainFrame::CreateComboBox()
{
	CRect rect, comboRect;
	m_wndToolBar.SetButtonInfo(8, IDW_COMBO, TBBS_SEPARATOR, COMBO_WIDTH);
	m_wndToolBar.GetItemRect(8, &rect);
	rect.bottom += COMBO_HEIGHT;

	if (!m_wndToolBar.m_toolBarCombo.Create(CBS_DROPDOWN|WS_VISIBLE|WS_TABSTOP|CBS_AUTOHSCROLL,
			rect, &m_wndToolBar, IDW_COMBO))
	{
		return FALSE;
	}

	// center combo box edit control vertically within tool bar
	rect.bottom -= COMBO_HEIGHT;
	m_wndToolBar.m_toolBarCombo.GetWindowRect(&comboRect);
	m_wndToolBar.m_toolBarCombo.ScreenToClient(&comboRect);

	m_wndToolBar.m_toolBarCombo.SetWindowPos(&m_wndToolBar.m_toolBarCombo, rect.left,
		rect.top + (rect.Height() - comboRect.Height())/2+1, 0, 0,
		SWP_NOZORDER|SWP_NOSIZE|SWP_NOACTIVATE);

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

#pragma warning (disable : 4706)
void CMainFrame::OnViewStatusBar()
{
	CWnd* pStatusBar;
	if (pStatusBar = GetDescendantWindow(AFX_IDW_STATUS_BAR))
	{
		pStatusBar->ShowWindow(!(pStatusBar->GetStyle() & WS_VISIBLE));
		RecalcLayout();
	}
}
#pragma warning (default: 4706)

#pragma warning (disable : 4706)
void CMainFrame::OnUpdateViewStatusBar(CCmdUI* pCmdUI)
{
	CWnd* pStatusBar;
	if (pStatusBar = GetDescendantWindow(AFX_IDW_STATUS_BAR))
		pCmdUI->SetCheck((pStatusBar->GetStyle() & WS_VISIBLE));
}
#pragma warning (default: 4706)

void CMainFrame::OnUpdateLineNumber(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnUpdateClock(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE);
}

void CMainFrame::OnEditFindCombo()
{
	m_wndToolBar.m_toolBarCombo.SetFocus();
}

void CMainFrame::OnClose()
{
	KillTimer(TIMER_ID);
	CFrameWnd::OnClose();
}

void CALLBACK EXPORT CMainFrame::UpdateTime(HWND hWnd,UINT /*nMsg*/, UINT_PTR /*nIDEvent*/, DWORD /*dwTime*/)
{
	CString time;
	BOOL bPM = TRUE;
	SYSTEMTIME tm;

	CMainFrame* pFrame = (CMainFrame*)CWnd::FromHandle(hWnd);
	CStatusBar* pStatusBar = (CStatusBar*) pFrame->GetDescendantWindow(AFX_IDW_STATUS_BAR);

	if (pStatusBar == NULL)
		return;

	GetLocalTime(&tm);

	if (tm.wHour >= 0 && tm.wHour < 12)
		bPM = FALSE;

	// convert 24 hour clock
	if (tm.wHour > 12)      // 13 - 23
		tm.wHour -= 12;
	else if (tm.wHour == 0) // midnight
		tm.wHour = 12;

	time.Format(_T(" %d:%02.2d %s "), tm.wHour, tm.wMinute, ((bPM) ? _T("PM"):_T("AM")));

	// get current pane font information and update time
	UINT nID, nStyle;
	int nWidth, nIndex = pStatusBar->CommandToIndex(ID_INDICATOR_CLOCK);

	CClientDC dc(pStatusBar);
	CFont* pOldFont = dc.SelectObject(pStatusBar->GetFont());
	CSize szExtent = dc.GetTextExtent(time, time.GetLength());
	dc.SelectObject(pOldFont);

	pStatusBar->GetPaneInfo(nIndex, nID, nStyle, nWidth);
	pStatusBar->SetPaneInfo(nIndex, nID, nStyle, szExtent.cx);
	pStatusBar->SetPaneText(nIndex, time);
}
