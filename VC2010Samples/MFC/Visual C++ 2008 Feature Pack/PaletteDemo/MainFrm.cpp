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
#include "PaletteDemo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_TOOLS_PALETTE, OnViewToolsPalette)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLS_PALETTE, OnUpdateViewToolsPalette)
	ON_COMMAND(ID_TWO_COLUMNS, OnTwoColumns)
	ON_UPDATE_COMMAND_UI(ID_TWO_COLUMNS, OnUpdateTwoColumns)
	ON_COMMAND(ID_THREE_COLUMNS, OnThreeColumns)
	ON_UPDATE_COMMAND_UI(ID_THREE_COLUMNS, OnUpdateThreeColumns)
	ON_COMMAND(ID_FOUR_COLUMNS, OnFourColumns)
	ON_UPDATE_COMMAND_UI(ID_FOUR_COLUMNS, OnUpdateFourColumns)
	ON_COMMAND(ID_VIEW_CUSTOMIZE, OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_TOOLBARMENU, OnToolbarContextMenu)
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
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// enable Office XP look:
	CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMFCVisualManagerOffice2003));

	if (!m_wndMenuBar.Create (this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndPalette.Create(this,
		WS_CHILD | WS_VISIBLE | CBRS_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_HIDE_INPLACE | CBRS_SIZE_DYNAMIC |
		CBRS_GRIPPER | CBRS_BORDER_3D,
		ID_VIEW_TOOLS_PALETTE) ||
		!m_wndPalette.LoadToolBar (IDR_PALETTE, 0, 0, TRUE /* Locked */))
	{
		TRACE0("Failed to create build toolbar\n");
		return FALSE;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	BOOL bValidString;
	CString strMainToolbarTitle;
	bValidString = strMainToolbarTitle.LoadString (IDS_MAIN_TOOLBAR);
	m_wndToolBar.SetWindowText (strMainToolbarTitle);

	CString strPaletteTitle;
	bValidString = strPaletteTitle.LoadString (IDS_PALETTE);
	m_wndPalette.SetWindowText (strPaletteTitle);
	
	m_wndMenuBar.EnableDocking (CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking (CBRS_ALIGN_ANY);
	m_wndPalette.EnableDocking (CBRS_ALIGN_LEFT | CBRS_ALIGN_RIGHT);

	EnableDocking(CBRS_ALIGN_ANY);

	DockPane (&m_wndMenuBar);
	DockPane (&m_wndToolBar);
	DockPane (&m_wndPalette);

	m_wndToolBar.EnableCustomizeButton (TRUE, ID_VIEW_CUSTOMIZE, _T("Customize..."));
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



LRESULT CMainFrame::OnToolbarContextMenu(WPARAM,LPARAM lp)
{
	CPoint point (AFX_GET_X_LPARAM(lp), AFX_GET_Y_LPARAM(lp));

	CMenu menu;
	VERIFY(menu.LoadMenu (IDR_POPUP_TOOLBAR));

	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	if (pPopup)
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;
		pPopupMenu->Create (this, point.x, point.y, pPopup->Detach ());
	}

	return 0;
}

void CMainFrame::OnViewCustomize()
{
	//------------------------------------
	// Create a customize toolbars dialog:
	//------------------------------------
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog (this,
		TRUE /* Automatic menus scaning */);

	pDlgCust->Create ();
}

BOOL CMainFrame::OnShowPopupMenu (CMFCPopupMenu* pMenuPopup)
{
	//---------------------------------------------------------
	// Replace ID_VIEW_TOOLBARS menu item to the toolbars list:
	//---------------------------------------------------------
	CFrameWndEx::OnShowPopupMenu (pMenuPopup);

	if (pMenuPopup != NULL &&
		pMenuPopup->GetMenuBar ()->CommandToIndex (ID_VIEW_TOOLBARS) >= 0)
	{
		if (CMFCToolBar::IsCustomizeMode ())
		{
			//----------------------------------------------------
			// Don't show toolbars list in the cuztomization mode!
			//----------------------------------------------------
			return FALSE;
		}

		pMenuPopup->RemoveAllItems ();

		CMenu menu;
		VERIFY(menu.LoadMenu (IDR_POPUP_TOOLBAR));

		CMenu* pPopup = menu.GetSubMenu(0);
		ASSERT(pPopup != NULL);

		if (pPopup)
		{
			pMenuPopup->GetMenuBar ()->ImportFromMenu (*pPopup, TRUE);
		}
	}

	return TRUE;
}

void CMainFrame::OnViewToolsPalette() 
{
	ShowPane (&m_wndPalette,
					!(m_wndPalette.GetStyle () & WS_VISIBLE),
					FALSE, TRUE);
}

void CMainFrame::OnUpdateViewToolsPalette(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (m_wndPalette.GetStyle () & WS_VISIBLE);
}

void CMainFrame::OnTwoColumns() 
{
	m_wndPalette.SetColumns (2);
}

void CMainFrame::OnUpdateTwoColumns(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio (m_wndPalette.GetColumns () == 2);
}

void CMainFrame::OnThreeColumns() 
{
	m_wndPalette.SetColumns (3);
}

void CMainFrame::OnUpdateThreeColumns(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio (m_wndPalette.GetColumns () == 3);
}

void CMainFrame::OnFourColumns() 
{
	m_wndPalette.SetColumns (4);
}

void CMainFrame::OnUpdateFourColumns(CCmdUI* pCmdUI) 
{
	pCmdUI->SetRadio (m_wndPalette.GetColumns () == 4);
}
