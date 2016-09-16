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
#include "MFCBind.h"

#include "MainFrm.h"
#include "BindView.h"
#include "ObjView.h"

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

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

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


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	// Create the splitter window for the main frame window'
	// client area.  For the main view, we'll use the same view
	// used in the doc-template displayed in the second pane
	// of the splitter. We'll use our special object list view
	// for the first pane of the splitter.

	// make the pane 2.5 times as wide as an icon
	// (arbitrary but pleasing)

	int nIconPaneWidth = ::GetSystemMetrics(SM_CXICON);
	nIconPaneWidth += nIconPaneWidth + (nIconPaneWidth >> 1);

	CRect rcClient;
	GetClientRect(rcClient);

	// Create the splitter and it's views
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to create splitter window\n");
		return FALSE;
	}

	ASSERT(RUNTIME_CLASS(CMFCBindView) == pContext->m_pNewViewClass);

	if (!m_wndSplitter.CreateView(0, 1, pContext->m_pNewViewClass,
			CSize(rcClient.Width() - nIconPaneWidth, 50), pContext))
	{
		TRACE0("Failed to create main view\n");
		return FALSE;
	}

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CObjListView),
			CSize(nIconPaneWidth, 0), pContext))
	{
		TRACE0("Failed to create object list view\n");
		return FALSE;
	}

	// Set the active view
	SetActiveView((CView*) m_wndSplitter.GetPane(0, 1));
	return TRUE;
}

CObjListView* CMainFrame::GetObjListView()
{
	// returns the view that contains the current list of objects
	return (CObjListView*) m_wndSplitter.GetPane(0, 0);
}

CMFCBindView* CMainFrame::GetDocView()
{
	// returns the view that the ole items are embedded in
	return (CMFCBindView*) m_wndSplitter.GetPane(0, 1);
}
