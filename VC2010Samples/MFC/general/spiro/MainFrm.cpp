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

#include "stdafx.h"
#include "spiro.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
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
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME) ||
		!m_wndToolBarSpiro.Create(this) ||
		!m_wndToolBarSpiro.LoadToolBar(IDR_PIECES))
	{
		TRACE0("Failed to create toolbars\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	m_wndToolBarSpiro.SetBarStyle(m_wndToolBarSpiro.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBarSpiro.EnableDocking(CBRS_ALIGN_ANY);

	EnableDocking(CBRS_ALIGN_ANY);

	UINT rgID[] = {ID_HUGERING, ID_VERYLARGERING, ID_MEDIUMRING,
				ID_SMALLRING, ID_ENORMOUSWHEEL, ID_HUGEWHEEL,
				ID_VERYLARGEWHEEL, ID_LARGEWHEEL, ID_MEDIUMWHEEL,
				ID_SMALLWHEEL, ID_TINYWHEEL};

	int nIndex;
	int i;
	for (i = 0; i < elementsof(rgID); i++)
	{
		VERIFY((nIndex = m_wndToolBarSpiro.CommandToIndex(rgID[i])) != -1);
		m_wndToolBarSpiro.SetButtonStyle(nIndex, TBBS_CHECKBOX);
	}

	UINT rgID2[] = {ID_BLUE, ID_RED, ID_YELLOW, ID_GREEN, ID_PURPLE, ID_BLACK, ID_TRACEWIDTH};
	for (i = 0; i < elementsof(rgID2); i++)
	{
		VERIFY((nIndex = m_wndToolBar.CommandToIndex(rgID2[i])) != -1);
		m_wndToolBar.SetButtonStyle(nIndex, TBBS_CHECKBOX);
	}

	m_wndToolBar.GetToolBarCtrl().CheckButton(ID_BLACK);
	VERIFY((nIndex = m_wndToolBar.CommandToIndex(ID_TRACEWIDTH)) != -1);
	m_wndToolBar.SetButtonStyle(nIndex, TBBS_CHECKBOX);

	DockControlBar(&m_wndToolBar);
	DockControlBar(&m_wndToolBarSpiro);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFrameWnd::PreCreateWindow(cs);
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


