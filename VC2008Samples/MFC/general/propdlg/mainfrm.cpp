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

#include "stdafx.h"
#include "propdlg.h"
#include "colorpge.h"
#include "stylepge.h"
#include "shapeobj.h"
#include "preview.h"
#include "propsht.h"
#include "propsht2.h"
#include "minifrm.h"
#include "resource.h"
#include "mainfrm.h"
#include "shapedoc.h"
#include "shapesvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MINI_FRAME_PROPERTY_SHEET, OnMiniFramePropertySheet)
	ON_UPDATE_COMMAND_UI(ID_MINI_FRAME_PROPERTY_SHEET, OnUpdateMiniFramePropertySheet)
	//}}AFX_MSG_MAP
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
	ID_FILE_PRINT,
	ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
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
	m_pShapePropFrame = NULL;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(buttons,
		  sizeof(buttons)/sizeof(UINT)))
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

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnMiniFramePropertySheet()
{
	// If mini frame does not already exist, create a new one.
	// Otherwise, unhide it

	if (m_pShapePropFrame == NULL)
	{
		m_pShapePropFrame = new CShapePropSheetFrame;
		CRect rect(0, 0, 0, 0);
		CString strTitle;
		strTitle.LoadString(IDS_OBJECT_PROPERTIES);
		if (!m_pShapePropFrame->Create(NULL, strTitle,
			WS_POPUP | WS_CAPTION | WS_SYSMENU, rect, this))
		{
			m_pShapePropFrame = NULL;
			return;
		}
		m_pShapePropFrame->CenterWindow();
	}

	// Before unhiding the modeless property sheet, update its
	// settings to reflect the currently selected shape.
	CShapesView* pView =
		STATIC_DOWNCAST(CShapesView, MDIGetActive()->GetActiveView());
	ASSERT_VALID(pView);
	if (pView->m_pShapeSelected != NULL)
	{
	   m_pShapePropFrame->m_pModelessShapePropSheet->
		   SetSheetPropsFromShape(pView->m_pShapeSelected);
	}

	if (m_pShapePropFrame != NULL && !m_pShapePropFrame->IsWindowVisible())
		m_pShapePropFrame->ShowWindow(SW_SHOW);
}

void CMainFrame::OnUpdateMiniFramePropertySheet(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pShapePropFrame == NULL
		|| !m_pShapePropFrame->IsWindowVisible());
}

void CMainFrame::HideModelessPropSheet()
{
	if (m_pShapePropFrame != NULL)
		m_pShapePropFrame->ShowWindow(SW_HIDE);
}
