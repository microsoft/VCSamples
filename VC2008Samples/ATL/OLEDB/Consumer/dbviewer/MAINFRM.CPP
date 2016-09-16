// MainFrm.cpp : implementation of the CMainFrame class
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "DBViewer.h"
#include "OptionDg.h"

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
	ON_COMMAND(ID_VIEW_OPTIONS, OnViewOptions)
	ON_COMMAND(ID_APP_CLONE, OnAppClone)
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

BOOL CMainFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		pContext->m_pNewViewClass, CSize(200, 50), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - an input view in column 1
	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CDBListView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}

	// activate the input view
	SetActiveView((CView*)m_wndSplitter.GetPane(0,1));

	return TRUE;
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

void CMainFrame::OnViewOptions()
{
	CPropertySheet propSheet(_T("DaoView - Options"));
	COptionsDlg pageOptions;
	propSheet.AddPage(&pageOptions);

	CDBViewApp* pApp = (CDBViewApp *)AfxGetApp();

	pageOptions.m_bShowWarnings = pApp->m_bShowWarnings;
	pageOptions.m_bShowSystemObjects = pApp->m_bShowSystemObjects;
	pageOptions.m_bOpenODBC= pApp->m_bOpenODBC;
	pageOptions.m_nMaxRecords= pApp->m_nMaxRecords;

	if (propSheet.DoModal() == IDOK)
	{
		BOOL bRebuildList = FALSE;
		if (pApp->m_bShowSystemObjects != pageOptions.m_bShowSystemObjects)
			bRebuildList = TRUE;

		pApp->m_bShowSystemObjects = pageOptions.m_bShowSystemObjects;

		if (bRebuildList)
			((CDBViewDoc*) GetActiveDocument())->RefreshViews();

		pApp->m_bShowWarnings = pageOptions.m_bShowWarnings;
		pApp->m_bOpenODBC = pageOptions.m_bOpenODBC;
		pApp->m_nMaxRecords = pageOptions.m_nMaxRecords;
	}
}

void CMainFrame::OnAppClone()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// Initialize the STARTUPINFO structure.
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);


	#pragma warning( push )
	#pragma warning(disable:6054)
	TCHAR szProcess[MAX_PATH];
	int nCharsCopied = ::GetModuleFileName(AfxGetInstanceHandle(), szProcess, MAX_PATH);
	if ( !nCharsCopied )
	{
		return;
	}
	ATLENSURE(nCharsCopied < MAX_PATH);
	CreateProcess(
		szProcess, // pointer to name of executable module
		NULL,   // pointer to command line string
		NULL,   // pointer to process security attributes
		NULL,   // pointer to thread security attributes
		FALSE,  // handle inheritance flag
		0,      // creation flags
		NULL,   // pointer to new environment block
		NULL,   // pointer to current directory name
		&si,    // pointer to STARTUPINFO
		&pi     // pointer to PROCESS_INFORMATION
	   );
	#pragma warning( pop )
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}
