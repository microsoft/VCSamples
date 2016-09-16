// ipframe.cpp : implementation of the CInPlaceFrame class
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
#include "hiersvr.h"
#include "ipframe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame

IMPLEMENT_DYNCREATE(CInPlaceFrame, COleIPFrameWnd)

BEGIN_MESSAGE_MAP(CInPlaceFrame, COleIPFrameWnd)
	//{{AFX_MSG_MAP(CInPlaceFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_CONTEXT_HELP, OnUpdateContextHelp)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_INDEX, COleIPFrameWnd::OnHelpIndex)
	ON_COMMAND(ID_HELP_USING, COleIPFrameWnd::OnHelpUsing)
	ON_COMMAND(ID_HELP, COleIPFrameWnd::OnHelp)
	ON_COMMAND(ID_DEFAULT_HELP, COleIPFrameWnd::OnHelpIndex)
	ON_COMMAND(ID_CONTEXT_HELP, COleIPFrameWnd::OnContextHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
	ID_APP_ABOUT,
	ID_CONTEXT_HELP,
};

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame construction/destruction

CInPlaceFrame::CInPlaceFrame()
{
}

CInPlaceFrame::~CInPlaceFrame()
{
}

int CInPlaceFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleIPFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("Failed to create resize bar\n");
		return -1;      // fail to create
	}

	m_dropTarget.Register(this);
	return 0;
}

// OnCreateControlBars is called by the framework to create control
//  bars on the container application's windows.
BOOL CInPlaceFrame::OnCreateControlBars(CFrameWnd* pWndFrame,
	CFrameWnd* /*pWndDoc*/)
{
	// create toolbar on client's frame window
	if (!m_wndToolBar.Create(pWndFrame) ||
		!m_wndToolBar.LoadBitmap(IDR_HIERSVRTYPE_SRVR_IP) ||
		!m_wndToolBar.SetButtons(buttons,
		  sizeof(buttons)/sizeof(UINT)))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;
	}

	// set owner to this window, so messages are delivered to correct app
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_SIZE_DYNAMIC);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);
	m_wndToolBar.SetOwner(this);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame diagnostics

#ifdef _DEBUG
void CInPlaceFrame::AssertValid() const
{
	COleIPFrameWnd::AssertValid();
}

void CInPlaceFrame::Dump(CDumpContext& dc) const
{
	COleIPFrameWnd::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame commands

void CInPlaceFrame::OnUpdateContextHelp(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!m_bHelpMode);
}
