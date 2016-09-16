// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MSMoneyDemo.h"
#include "MSMoneyDemoDoc.h"
#include "MSMoneyDemoView.h"

#include "MainFrm.h"

#include "MSMVisualManager.h"

#include "MSMLinksBarButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_ACTIVATE()
	ON_WM_SIZE()
	ON_REGISTERED_MESSAGE(AFX_WM_RESETTOOLBAR, OnToolbarReset)
	ON_REGISTERED_MESSAGE(AFX_WM_TOOLBARMENU, OnToolbarContextMenu)
	ON_UPDATE_COMMAND_UI(ID_GO_ADDRESS_EDIT, OnUpdateGoAddressEdit)
	ON_UPDATE_COMMAND_UI(ID_BACKWARD_1, OnUpdateBackward1)
	ON_UPDATE_COMMAND_UI(ID_BACKWARD_2, OnUpdateBackward2)
	ON_UPDATE_COMMAND_UI(ID_FORWARD_1, OnUpdateForward1)
	ON_UPDATE_COMMAND_UI(ID_FORWARD_2, OnUpdateForward2)
	ON_UPDATE_COMMAND_UI(ID_TOOLBAR_CUSTOMIZE, OnUpdateCustomize)
	ON_COMMAND_RANGE(ID_CATEGORIE_1, ID_CATEGORIE_8, OnCategorie)
	ON_UPDATE_COMMAND_UI_RANGE(ID_CATEGORIE_1, ID_CATEGORIE_8, OnUpdateCategorie)
	ON_COMMAND_RANGE(ID_LINKS_HOME_1, ID_LINKS_TAXES_5, OnLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_LINKS_HOME_1, ID_LINKS_TAXES_5, OnUpdateLinks)
	ON_WM_GETMINMAXINFO()
	ON_COMMAND(ID_APP_HELP_MICROSOFT, OnHelpMicrosoft)
	ON_COMMAND(ID_HELP_MICROSOFT, OnHelpMicrosoft)
	ON_WM_SETTINGCHANGE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bMainToolbarMenu = FALSE;
	m_nCategorie       = (UINT)-1;
}

CMainFrame::~CMainFrame()
{
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


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	ModifyStyle (WS_CAPTION | FWS_ADDTOTITLE, 0);
	ModifyStyleEx (WS_EX_CLIENTEDGE, 0);

	CMFCVisualManager::SetDefaultManager (RUNTIME_CLASS (CMSMVisualManager));

	//---------------------------------
	// Set toolbar and menu image size:
	//---------------------------------
	CMFCToolBarButton::m_bWrapText = FALSE;
	CMFCToolBar::SetMenuSizes (CSize (22, 22), CSize (16, 16));

	CMFCToolBarComboBoxButton::SetFlatMode ();
	CMFCToolBarComboBoxButton::SetCenterVert ();

	if (!m_wndCaptionBar.Create(this, IDR_MAINFRAME))
	{
		TRACE0("Failed to create captionbar\n");
		return -1;
	}

	if (afxGlobalData.fontRegular.GetSafeHandle () != NULL)
	{
		LOGFONT lf;
		ZeroMemory (&lf, sizeof (LOGFONT));
		afxGlobalData.fontRegular.GetLogFont (&lf);

		m_wndCaptionBar.SetCaptionFont (lf);
	}

	if (!m_wndMenuBar.Create (this, AFX_DEFAULT_TOOLBAR_STYLE))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	EnableDocking(CBRS_ALIGN_ANY);

	DockPane(&m_wndMenuBar);

	CClientDC dc (this);
	m_bIsHighColor = dc.GetDeviceCaps (BITSPIXEL) > 16;

	UINT uiToolbarHotID  = m_bIsHighColor ? IDB_HOTTOOLBAR : 0;
	UINT uiToolbarColdID = m_bIsHighColor ? IDB_COLDTOOLBAR : 0;
	UINT uiToolbarDisID  = m_bIsHighColor ? IDB_DISABLEDTOOLBAR : 0;
	UINT uiToolbarPresID = m_bIsHighColor ? IDB_PRESSEDTOOLBAR : 0;
	UINT uiMenuID        = m_bIsHighColor ? IDB_MENU_IMAGES : IDB_MENU_IMAGES_16;

	if (!m_wndToolBar.CreateEx (this, TBSTYLE_FLAT,
		                        CBRS_SIZE_FIXED | AFX_DEFAULT_TOOLBAR_STYLE) ||
		!m_wndToolBar.LoadToolBar (IDR_MAINFRAME, uiToolbarColdID, uiMenuID, 
			FALSE /* Not locked */, uiToolbarDisID, 0, uiToolbarHotID, uiToolbarPresID))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.InsertButton 
		(CMFCToolBarComboBoxButton (ID_GO_ADDRESS_EDIT, 0), 3);

	DockPane (&m_wndToolBar);

	if (!m_wndCategoryBar.CreateEx (this, TBSTYLE_FLAT, 
		                      CBRS_SIZE_FIXED | AFX_DEFAULT_TOOLBAR_STYLE, 
							  CRect (1, 1, 1, 1), AFX_IDW_TOOLBAR + 3))
	{
		TRACE0("Failed to create categoriebar\n");
		return -1;      // fail to create
	}

	DockPane (&m_wndCategoryBar);

	for (long i = 0; i < 8; i++)
	{
		if (!m_wndLinksBars[i].CreateEx (this, TBSTYLE_FLAT, 
								  CBRS_SIZE_FIXED | AFX_DEFAULT_TOOLBAR_STYLE, 
								  CRect (1, 1, 1, 1), AFX_IDW_TOOLBAR + 4 + i))
		{
			TRACE0("Failed to create linksbar\n");
			return -1;      // fail to create
		}

		DockPane (&m_wndLinksBars[i]);
		ShowPane (&m_wndLinksBars[i], FALSE, FALSE, FALSE);
	}

	m_wndLinksBars[0].InsertButton (CMSMLinksBarButton (_T("My Money"), ID_LINKS_HOME_1));
	m_wndLinksBars[0].InsertButton (CMSMLinksBarButton (_T("MSN Money News"), ID_LINKS_HOME_2));
	m_wndLinksBars[0].SetCurrentCommand (ID_LINKS_HOME_1);

	m_wndLinksBars[1].InsertButton (CMSMLinksBarButton (_T("Account List"), ID_LINKS_BANKING_1));
	m_wndLinksBars[1].InsertButton (CMSMLinksBarButton (_T("Account Tools"), ID_LINKS_BANKING_2));
	m_wndLinksBars[1].InsertButton (CMSMLinksBarButton (_T("Mortgages && Loans"), ID_LINKS_BANKING_3));
	m_wndLinksBars[1].InsertButton (CMSMLinksBarButton (_T("Bank Services"), ID_LINKS_BANKING_4));
	m_wndLinksBars[1].InsertButton (CMSMLinksBarButton (_T("Credit Center"), ID_LINKS_BANKING_5));
	m_wndLinksBars[1].SetCurrentCommand (ID_LINKS_BANKING_1);

	m_wndLinksBars[2].InsertButton (CMSMLinksBarButton (_T("Bills Summary"), ID_LINKS_BILLS_1));
	m_wndLinksBars[2].InsertButton (CMSMLinksBarButton (_T("Bill Calendar"), ID_LINKS_BILLS_2));
	m_wndLinksBars[2].InsertButton (CMSMLinksBarButton (_T("Transfer Money"), ID_LINKS_BILLS_3));
	m_wndLinksBars[2].InsertButton (CMSMLinksBarButton (_T("MSN Bill Pay Online"), ID_LINKS_BILLS_4));
	m_wndLinksBars[2].InsertButton (CMSMLinksBarButton (_T("History"), ID_LINKS_BILLS_5));
	m_wndLinksBars[2].SetCurrentCommand (ID_LINKS_BILLS_1);

	m_wndLinksBars[3].InsertButton (CMSMLinksBarButton (_T("Reports Home"), ID_LINKS_REPORTS_1));
	m_wndLinksBars[3].InsertButton (CMSMLinksBarButton (_T("Favorite Reports"), ID_LINKS_REPORTS_2));
	m_wndLinksBars[3].InsertButton (CMSMLinksBarButton (_T("Monthly Reports"), ID_LINKS_REPORTS_3));
	m_wndLinksBars[3].SetCurrentCommand (ID_LINKS_REPORTS_1);

	m_wndLinksBars[4].InsertButton (CMSMLinksBarButton (_T("Budget Summary"), ID_LINKS_BUDGET_1));
	m_wndLinksBars[4].InsertButton (CMSMLinksBarButton (_T("Budget vs. Spending"), ID_LINKS_BUDGET_2));
	m_wndLinksBars[4].SetCurrentCommand (ID_LINKS_BUDGET_1);

	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Investing Home"), ID_LINKS_INVESTING_1));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Investing Tools"), ID_LINKS_INVESTING_2));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Market News"), ID_LINKS_INVESTING_3));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Stocks"), ID_LINKS_INVESTING_4));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Funds"), ID_LINKS_INVESTING_5));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Insight"), ID_LINKS_INVESTING_6));
	m_wndLinksBars[5].InsertButton (CMSMLinksBarButton (_T("Brokers"), ID_LINKS_INVESTING_7));
	m_wndLinksBars[5].SetCurrentCommand (ID_LINKS_INVESTING_1);

	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Planning Home"), ID_LINKS_PLANNING_1));
	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Planning Tools"), ID_LINKS_PLANNING_2));
	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Retirement"), ID_LINKS_PLANNING_3));
	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Savings"), ID_LINKS_PLANNING_4));
	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Insurance"), ID_LINKS_PLANNING_5));
	m_wndLinksBars[6].InsertButton (CMSMLinksBarButton (_T("Family && College"), ID_LINKS_PLANNING_6));
	m_wndLinksBars[6].SetCurrentCommand (ID_LINKS_PLANNING_1);

	m_wndLinksBars[7].InsertButton (CMSMLinksBarButton (_T("Taxes Home"), ID_LINKS_TAXES_1));
	m_wndLinksBars[7].InsertButton (CMSMLinksBarButton (_T("Tax Tools"), ID_LINKS_TAXES_2));
	m_wndLinksBars[7].InsertButton (CMSMLinksBarButton (_T("Prepare Online"), ID_LINKS_TAXES_3));
	m_wndLinksBars[7].InsertButton (CMSMLinksBarButton (_T("Planning"), ID_LINKS_TAXES_4));
	m_wndLinksBars[7].InsertButton (CMSMLinksBarButton (_T("Products && Services"), ID_LINKS_TAXES_5));
	m_wndLinksBars[7].SetCurrentCommand (ID_LINKS_TAXES_1);

	//-----------------------
	// Set up Favorites menu:
	//-----------------------

	int nCategorie = theApp.GetProfileInt (_T(""), _T("Categorie"), 0);

	OnCategorie (ID_CATEGORIE_1 + nCategorie);

	m_wndTaskPane.Create (_T(""), this, CRect (0, 0, 140, 200), 
		FALSE, IDR_MAINFRAME + 1, 
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT, 0, 0);

	DockPane(&m_wndTaskPane);

	return 0;
}


void CMainFrame::OnClose() 
{
	theApp.WriteProfileInt (_T(""), _T("Categorie"), m_nCategorie);
	
	CFrameWnd::OnClose();
}


void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
	
	if (m_wndCaptionBar.GetSafeHwnd () != NULL)
	{
		m_wndCaptionBar.SetParentActive (nState != WA_INACTIVE);
	}
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	SetupMemoryBitmapSize (CSize (cx, cy));

	if (m_wndCaptionBar.GetSafeHwnd () != NULL)
	{
		m_wndCaptionBar.SetParentMaximize (nType == SIZE_MAXIMIZED);
	}

	CFrameWnd::OnSize(nType, cx, cy);
}

LRESULT CMainFrame::OnToolbarContextMenu(WPARAM /*wp*/,LPARAM /*lp*/)
{
	return 0;
}

LRESULT CMainFrame::OnToolbarReset(WPARAM wp, LPARAM)
{
	UINT uiToolBarId = (UINT) wp;
	if (uiToolBarId == IDR_MAINFRAME)
	{
		// Replace "Back" and "Forward" buttons by the menu buttons
		// with the history lists:

		CMenu menuBackward;
		menuBackward.LoadMenu (IDR_BACKWARD_MENU);

		m_wndToolBar.ReplaceButton (ID_GO_BACK, 
			CMFCToolBarMenuButton (ID_GO_BACK, menuBackward, 
						GetCmdMgr ()->GetCmdImage (ID_GO_BACK), NULL));

		CMenu menuForward;
		menuForward.LoadMenu (IDR_FORWARD_MENU);

		m_wndToolBar.ReplaceButton (ID_GO_FORWARD,
			CMFCToolBarMenuButton (ID_GO_FORWARD, menuForward, 
						GetCmdMgr ()->GetCmdImage (ID_GO_FORWARD), NULL));
	}

	return 0;
}

BOOL CMainFrame::OnShowPopupMenu (CMFCPopupMenu* pMenuPopup)
{
	CFrameWndEx::OnShowPopupMenu (pMenuPopup);

	if (pMenuPopup == NULL)
	{
		return TRUE;
	}

	CMFCToolBarMenuButton* pParentButton = pMenuPopup->GetParentButton ();
	if (pParentButton == NULL)
	{
		return TRUE;
	}

	switch (pParentButton->m_nID)
	{
	case ID_GO_BACK:
	case ID_GO_FORWARD:
		{
			if (CMFCToolBar::IsCustomizeMode ())
			{
				return FALSE;
			}
		}
	}

	return TRUE;
}

void CMainFrame::OnUpdateGoAddressEdit(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnCategorie(UINT nID)
{
	if (m_nCategorie != -1)
	{
		ShowPane (&m_wndLinksBars[m_nCategorie], FALSE, TRUE, FALSE);
	}

	m_nCategorie = nID - ID_CATEGORIE_1;

	ShowPane (&m_wndLinksBars[m_nCategorie], TRUE, FALSE, FALSE);
}

void CMainFrame::OnUpdateCategorie(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
	pCmdUI->SetCheck (pCmdUI->m_nID == (m_nCategorie + ID_CATEGORIE_1));
}

CMSMLinksBar* CMainFrame::GetLinksBar (UINT nID)
{
	CMSMLinksBar* pBar = NULL;

	if(ID_LINKS_HOME_1 <= nID && nID <= ID_LINKS_HOME_2)
	{
		pBar = &m_wndLinksBars [0];
	}
	else if(ID_LINKS_BANKING_1 <= nID && nID <= ID_LINKS_BANKING_5)
	{
		pBar = &m_wndLinksBars [1];
	}
	else if(ID_LINKS_BILLS_1 <= nID && nID <= ID_LINKS_BILLS_5)
	{
		pBar = &m_wndLinksBars [2];
	}
	else if(ID_LINKS_REPORTS_1 <= nID && nID <= ID_LINKS_REPORTS_3)
	{
		pBar = &m_wndLinksBars [3];
	}
	else if(ID_LINKS_BUDGET_1 <= nID && nID <= ID_LINKS_BUDGET_2)
	{
		pBar = &m_wndLinksBars [4];
	}
	else if(ID_LINKS_INVESTING_1 <= nID && nID <= ID_LINKS_INVESTING_7)
	{
		pBar = &m_wndLinksBars [5];
	}
	else if(ID_LINKS_PLANNING_1 <= nID && nID <= ID_LINKS_PLANNING_6)
	{
		pBar = &m_wndLinksBars [6];
	}
	else if(ID_LINKS_TAXES_1 <= nID && nID <= ID_LINKS_TAXES_5)
	{
		pBar = &m_wndLinksBars [7];
	}
	else
	{
		ASSERT (FALSE);
	}

	return pBar;
}

void CMainFrame::OnLinks(UINT nID)
{
	CMSMLinksBar* pBar = GetLinksBar (nID);

	if (pBar != NULL)
	{
		pBar->SetCurrentCommand (nID);
	}
}

void CMainFrame::OnUpdateLinks(CCmdUI* pCmdUI) 
{
	CMSMLinksBar* pBar = GetLinksBar (pCmdUI->m_nID);

	if (pBar != NULL)
	{
		pCmdUI->SetCheck (pCmdUI->m_nID == pBar->GetCurrentCommand ());
	}

	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnUpdateBackward1(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnUpdateBackward2(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnUpdateForward1(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnUpdateForward2(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnUpdateCustomize(CCmdUI* pCmdUI)
{
	pCmdUI->Enable (TRUE);
}

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	CFrameWnd::OnGetMinMaxInfo(lpMMI);

	if(m_wndCategoryBar.GetSafeHwnd () != NULL)
	{
		CRect rtRect (CPoint (0, 0), m_wndCategoryBar.CalcSize (FALSE));

		rtRect.bottom = 200;

		CalcWindowRect (rtRect, CWnd::adjustBorder);

		lpMMI->ptMinTrackSize.x = rtRect.Width ();
		lpMMI->ptMinTrackSize.y = rtRect.Height ();
	}
}

void CMainFrame::OnHelpMicrosoft() 
{
	::ShellExecute (NULL, NULL, _T("http://msdn2.microsoft.com/en-us/visualc/default.aspx"), NULL, NULL, NULL);
}

void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
	CFrameWnd::OnSettingChange(uFlags, lpszSection);

	if (m_wndCaptionBar.GetSafeHwnd () != NULL && 
		afxGlobalData.fontRegular.GetSafeHandle () != NULL)
	{
		LOGFONT lf;
		ZeroMemory (&lf, sizeof (LOGFONT));
		afxGlobalData.fontRegular.GetLogFont (&lf);

		m_wndCaptionBar.SetCaptionFont (lf);
	}

	CRect rt;
	GetClientRect (rt);

	SetupMemoryBitmapSize (rt.Size ());
}

void CMainFrame::SetupMemoryBitmapSize (const CSize& sz)
{
	CMSMVisualManager* pManager = DYNAMIC_DOWNCAST (CMSMVisualManager,
		CMFCVisualManager::GetInstance ());

	if (pManager != NULL)
	{
		CRect rtRes (0, 0, sz.cx, 0);

		CRect rt;

		CPane* bars[4] = 
			{&m_wndCaptionBar, &m_wndMenuBar, &m_wndToolBar, &m_wndCategoryBar};

		for (long i = 0; i < 4; i++)
		{
			CPane* pBar = bars [i];

			if (pBar != NULL && pBar->GetSafeHwnd () != NULL)
			{
				pBar->GetWindowRect (rt);
				rtRes.bottom += rt.Height ();
			}
		}

		CDC* pDC = GetDC ();

		pManager->SetupMemoryBitmapSize (pDC, rtRes.Size ());

		ReleaseDC (pDC);
	}
}
