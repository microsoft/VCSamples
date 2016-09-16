// Dlgcbr32.cpp : Defines the class behaviors for CModelessMain.
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
#include <afxpriv.h>
#include "mdlsmain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelessMain

IMPLEMENT_DYNAMIC(CModelessMain, CModelessDialog)

BEGIN_MESSAGE_MAP(CModelessMain, CModelessDialog)
	//{{AFX_MSG_MAP(CModelessMain)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_QUERYDRAGICON()
	ON_WM_ENTERIDLE()
	ON_WM_INITMENUPOPUP()
	ON_WM_MENUSELECT()
	ON_MESSAGE(WM_SETMESSAGESTRING, OnSetMessageString)
	ON_MESSAGE(WM_POPMESSAGESTRING, OnPopMessageString)
	//}}AFX_MSG_MAP
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipText)

	// Standard View menu options
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnStatusBarCheck)
	ON_COMMAND(ID_VIEW_TOOLBAR, OnToolBarCheck)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STATUS_BAR, OnUpdateStatusBarMenu)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateToolBarMenu)

	// Standard status bar mode indicators
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_CAPS, OnUpdateKeyIndicator)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUM, OnUpdateKeyIndicator)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_SCRL, OnUpdateKeyIndicator)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelessMain Construction/Destruction

CModelessMain::CModelessMain()
{
	m_hIcon = NULL;

	m_nIDTracking     = 0;
	m_nIDLastMessage  = 0;

	m_lpaIDStatusBar  = NULL;
	m_cIDStatusBar    = 0;

	m_lpaIDToolBar    = NULL;
	m_cIDToolBar      = 0;
	m_nIDBitmap       = 0;
}

CModelessMain::~CModelessMain()
{
}

////////////////////////////////////////////////////////////////////////////
// CModelessMain::Create
//      Create saves away information about the status bar and toolbar,
//      loads the dialog icon, and creates the dialog window.  It assumes
//      the dialog icon has the same resource ID as the dialog template
//      itself.

BOOL CModelessMain::Create(UINT nIDTemplate,
						   const UINT FAR* lpaIDStatus, int cIDStatus,
						   const UINT FAR* lpaIDToolbar, int cIDToolbar,
						   UINT nIDBitmap)
{
	m_hIcon = AfxGetApp()->LoadIcon(nIDTemplate);

	m_lpaIDStatusBar = lpaIDStatus;
	m_cIDStatusBar   = cIDStatus;

	m_lpaIDToolBar   = lpaIDToolbar;
	m_cIDToolBar     = cIDToolbar;
	m_nIDBitmap      = nIDBitmap;

	return CModelessDialog::Create(nIDTemplate);
}

BOOL CModelessMain::Create(LPCTSTR lpszTemplateName,
						   const UINT FAR* lpaIDStatus, int cIDStatus,
						   const UINT FAR* lpaIDToolbar, int cIDToolbar,
						   UINT nIDBitmap)
{
	ASSERT(lpszTemplateName != NULL);

	m_hIcon = AfxGetApp()->LoadIcon(lpszTemplateName);

	m_lpaIDStatusBar = lpaIDStatus;
	m_cIDStatusBar   = cIDStatus;

	m_lpaIDToolBar   = lpaIDToolbar;
	m_cIDToolBar     = cIDToolbar;
	m_nIDBitmap      = nIDBitmap;

	return CModelessDialog::Create(lpszTemplateName);
}


/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnClose
//      OnClose handles the WM_CLOSE message by posting a WM_QUIT message
//      (so the app shuts down), after performing default processing to
//      actually close the window.

void CModelessMain::OnClose()
{
	CModelessDialog::OnClose();
	PostQuitMessage(0);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnInitDialog
//      OnInitDialog centers the dialog on the screen and creates the status
//      and toolbars.  To make sure the control bars don't overlap any
//      dialog controls, the dialog's client area is expanded by the amount
//      of space required for the control bars.

BOOL CModelessMain::OnInitDialog()
{
	CModelessDialog::OnInitDialog();

	// Create status bar at the bottom of the dialog window
	if (m_statusBar.Create(this))
	{
		m_statusBar.SetIndicators(m_lpaIDStatusBar, m_cIDStatusBar);
		OnSetMessageString(AFX_IDS_IDLEMESSAGE);

		// Make a sunken or recessed border around the first pane
		m_statusBar.SetPaneInfo(0, m_statusBar.GetItemID(0),
			SBPS_STRETCH, NULL );
	}

	// Create toolbar at the top of the dialog window
	if (m_toolBar.Create(this))
	{
		m_toolBar.LoadBitmap(m_nIDBitmap);
		m_toolBar.SetButtons(m_lpaIDToolBar, m_cIDToolBar);
	}

	m_toolBar.SetBarStyle(m_toolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// We need to resize the dialog to make room for control bars.
	// First, figure out how big the control bars are.
	CRect rcClientStart;
	CRect rcClientNow;
	GetClientRect(rcClientStart);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST,
				   0, reposQuery, rcClientNow);

	// Now move all the controls so they are in the same relative
	// position within the remaining client area as they would be
	// with no control bars.
	CPoint ptOffset(rcClientNow.left - rcClientStart.left,
					rcClientNow.top - rcClientStart.top);

	CRect  rcChild;
	CWnd* pwndChild = GetWindow(GW_CHILD);
	while (pwndChild)
	{
		pwndChild->GetWindowRect(rcChild);
		ScreenToClient(rcChild);
		rcChild.OffsetRect(ptOffset);
		pwndChild->MoveWindow(rcChild, FALSE);
		pwndChild = pwndChild->GetNextWindow();
	}

	// Adjust the dialog window dimensions
	CRect rcWindow;
	GetWindowRect(rcWindow);
	rcWindow.right += rcClientStart.Width() - rcClientNow.Width();
	rcWindow.bottom += rcClientStart.Height() - rcClientNow.Height();
	MoveWindow(rcWindow, FALSE);

	// And position the control bars
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);         // Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon

	// Finally, center the dialog on the screen
	CenterWindow();
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnPaint
// CModelessMain::OnEraseBkgnd
// CModelessMain::OnQueryDragIcon
//      These functions are used to display a custom icon for the dialog.
//
//      These functions use a technique described in KB article Q87976
//      to display a custom icon for our dialog window.  We assume that
//      the icon has been loaded into m_hIcon.

void CModelessMain::OnPaint()
{
	CPaintDC dc(this);
	if (IsIconic() && m_hIcon)
	{
		// Erase the icon background when placed over other app window
		DefWindowProc(WM_ICONERASEBKGND, (WORD)dc.m_hDC, 0L);

		// Center the icon
		CRect rc;
		GetClientRect(&rc);
		rc.left = (rc.right - ::GetSystemMetrics(SM_CXICON))/2;
		rc.top  = (rc.bottom - ::GetSystemMetrics(SM_CYICON))/2;

		// Draw the icon
		dc.DrawIcon(rc.left, rc.top, m_hIcon);
	}
}

BOOL CModelessMain::OnEraseBkgnd(CDC* pDC)
{
	if (IsIconic() && m_hIcon)
		return TRUE;
	else
		return CModelessDialog::OnEraseBkgnd(pDC);
}

HCURSOR CModelessMain::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnInitMenuPopup
//      OnInitMenuPopup updates the state of items on a popup menu.
//
//      This code is based on CFrameWnd::OnInitMenuPopup.  We assume the
//      application does not support context sensitive help.

void CModelessMain::OnInitMenuPopup(CMenu* pPopupMenu, UINT /*nIndex*/, BOOL bSysMenu)
{
	if (!bSysMenu)
	{
		ENSURE(pPopupMenu != NULL);

		// check the enabled state of various menu items
		CCmdUI state;
		state.m_pMenu = pPopupMenu;
		ASSERT(state.m_pOther == NULL);

		state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
		for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
			 state.m_nIndex++)
		{
			state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
			if (state.m_nID == 0)
				continue; // menu separator or invalid cmd - ignore it

			ASSERT(state.m_pOther == NULL);
			ASSERT(state.m_pMenu != NULL);
			if (state.m_nID == (UINT)-1)
			{
				// possibly a popup menu, route to first item of that popup
				state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
				if (state.m_pSubMenu == NULL ||
					(state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
					state.m_nID == (UINT)-1)
				{
					continue; // first item of popup can't be routed to
				}
				state.DoUpdate(this, FALSE);  // popups are never auto disabled
			}
			else
			{
				// normal menu item
				// Auto enable/disable if command is _not_ a system command
				state.m_pSubMenu = NULL;
				state.DoUpdate(this, state.m_nID < 0xF000);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnEnterIdle
//      OnEnterIdle updates the status bar when there's nothing better to do.
//      This code is based on CFrameWnd::OnEnterIdle.

void CModelessMain::OnEnterIdle(UINT nWhy, CWnd* /*pWho*/)
{
	if (nWhy != MSGF_MENU || m_nIDTracking == m_nIDLastMessage)
		return;

	OnSetMessageString(m_nIDTracking);
	ASSERT(m_nIDTracking == m_nIDLastMessage);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnMenuSelect
//      OnMenuSelect updates the status bar message, based on the state
//      of the dialog menu.
//
//      This code is based on CFrameWnd::OnMenuSelect.  We assume the
//      application does not support context sensitive help.

void CModelessMain::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU /*hSysMenu*/)
{
	// set the tracking state
	if (nFlags == 0xFFFF)
	{
		// cancel menu operation (go back to idle now)
		m_nIDTracking = AFX_IDS_IDLEMESSAGE;
		OnSetMessageString(m_nIDTracking);  // set string now
		ASSERT(m_nIDTracking == m_nIDLastMessage);
	}
	else if (nItemID == 0 ||
			 nFlags & (MF_SEPARATOR|MF_POPUP|MF_MENUBREAK|MF_MENUBARBREAK))
	{
		// nothing should be displayed
		m_nIDTracking = 0;
	}
	else if (nItemID >= 0xF000 && nItemID < 0xF1F0)
	{
		// special string table entries for system commands
		m_nIDTracking = ID_COMMAND_FROM_SC(nItemID);
		ASSERT(m_nIDTracking >= AFX_IDS_SCFIRST &&
			   m_nIDTracking < AFX_IDS_SCFIRST + 31);
	}
	else
	{
		// track on idle
		m_nIDTracking = nItemID;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnSetMessageString
//      OnSetMessageString updates the status bar text.
//
//      This code is based on CFrameWnd::OnSetMessageString.  We assume
//      a string ID is always passed in wParam.

LRESULT CModelessMain::OnSetMessageString(WPARAM wParam, LPARAM /*lParam*/)
{
	UINT    nIDMsg = (UINT)wParam;
	CString strMsg;

	if (nIDMsg)
	{
		if (strMsg.LoadString(nIDMsg) != 0)
		{
			CString strStatusText;
			AfxExtractSubString(strStatusText, strMsg, 0, '\n');
			m_statusBar.SetWindowText(strStatusText);
		}
		else
			TRACE1("Warning: no message line prompt for ID %x%04X\n", nIDMsg);
	}

	UINT nIDLast     = m_nIDLastMessage;
	m_nIDLastMessage = nIDMsg;
	m_nIDTracking    = nIDMsg;
	return nIDLast;

}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnStatusBarCheck
//      OnStatusBarCheck toggles the status of the status bar when the
//      corresponding View option is selected from the menu.

void CModelessMain::OnStatusBarCheck()
{
	m_statusBar.ShowWindow(m_statusBar.IsWindowVisible() ? SW_HIDE : SW_SHOWNA);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnUpdateStatusBarMenu
//      OnUpdateStatusBarMenu checks or unchecks the View option,
//      depending on whether or not the status bar is visible.

void CModelessMain::OnUpdateStatusBarMenu(CCmdUI* pCmdUI)
{
	ASSERT(pCmdUI->m_nID == ID_VIEW_STATUS_BAR);
	pCmdUI->SetCheck(m_statusBar.IsWindowVisible());
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnToolBarCheck
//      OnToolBarCheck toggles the status of the toolbar when the
//      corresponding View option is selected from the menu.

void CModelessMain::OnToolBarCheck()
{
	m_toolBar.ShowWindow(m_toolBar.IsWindowVisible() ? SW_HIDE : SW_SHOWNA);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnUpdateToolBarMenu
//      OnUpdateToolBarMenu checks or unchecks the View option,
//      depending on whether or not the toolbar is visible.

void CModelessMain::OnUpdateToolBarMenu(CCmdUI* pCmdUI)
{
	ASSERT(pCmdUI->m_nID == ID_VIEW_TOOLBAR);
	pCmdUI->SetCheck(m_toolBar.IsWindowVisible());
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnUpdateKeyIndicator
//      OnUpdateKeyIndicator enables or disables one of the key indicators
//      in a status bar.  It recognizes the CAPS, NUM, and SCRL keys.

void CModelessMain::OnUpdateKeyIndicator(CCmdUI* pCmdUI)
{
	UINT nVK;

	switch (pCmdUI->m_nID)
	{
	case ID_INDICATOR_CAPS:
		nVK = VK_CAPITAL;
		break;

	case ID_INDICATOR_NUM:
		nVK = VK_NUMLOCK;
		break;

	case ID_INDICATOR_SCRL:
		nVK = VK_SCROLL;
		break;

	default:
		TRACE1("Warning: OnUpdateKeyIndicator - unknown indicator 0x%04X\n",
			pCmdUI->m_nID);
		pCmdUI->ContinueRouting();
		return; // not for us
	}

	pCmdUI->Enable(::GetKeyState(nVK) & 1);
		// enable static text based on toggled key state
	ASSERT(pCmdUI->m_bEnableChanged);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnPopMessageString
//      Resets status bar message string.  This code is based on
//      CFrameWnd::OnPopMessageString

LRESULT CModelessMain::OnPopMessageString(WPARAM wParam, LPARAM lParam)
{
	if (m_nFlags & WF_NOPOPMSG)
		return 0;

	return SendMessage(WM_SETMESSAGESTRING, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessMain::OnToolTipText
//      Handles TTN_NEEDTEXT message to display tooltips for the toolbar.
//      This code is based on CFrameWnd::OnToolTipText

BOOL CModelessMain::OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
	ASSERT(pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW);

	// allow top level routing frame to handle the message
	if (GetRoutingFrame() != NULL)
		return FALSE;

	// need to handle both ANSI and UNICODE versions of the message
	TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
	TCHAR szFullText[256];
	CString strTipText;
	UINT_PTR nID = (UINT_PTR)pNMHDR->idFrom;
	if (pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
		pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND))
	{
		// idFrom is actually the HWND of the tool
		nID = ((UINT_PTR)(WORD)::GetDlgCtrlID((HWND)nID));
	}

	if (nID != 0) // will be zero on a separator
	{
		AfxLoadString((UINT)nID, szFullText);
			// this is the command id, not the button index
		AfxExtractSubString(strTipText, szFullText, 1, '\n');
	}
#ifndef _UNICODE
	if (pNMHDR->code == TTN_NEEDTEXTA)
		_tcsncpy_s(pTTTA->szText, (sizeof(pTTTA->szText)/sizeof(pTTTA->szText[0])),
			strTipText, _TRUNCATE);
	else
	{
		int n = MultiByteToWideChar(CP_ACP, 0, strTipText, -1, pTTTW->szText, 
			sizeof(pTTTW->szText)/sizeof(pTTTW->szText[0]));
		if (n > 0)
			pTTTW->szText[n-1] = 0;
	}
#else
	if (pNMHDR->code == TTN_NEEDTEXTA)
	{
		int n = WideCharToMultiByte(CP_ACP, 0, strTipText, -1, 
			pTTTA->szText, sizeof(pTTTA->szText)/sizeof(pTTTA->szText[0]),
			NULL, NULL);
		if (n > 0)
			pTTTA->szText[n-1] = 0;
	}
	else
		_tcsncpy_s(pTTTW->szText, (sizeof(pTTTW->szText)/sizeof(pTTTW->szText[0])),
			strTipText, _TRUNCATE);
#endif
	*pResult = 0;

	// bring the tooltip window above other popup windows
	::SetWindowPos(pNMHDR->hwndFrom, HWND_TOP, 0, 0, 0, 0,
		SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOMOVE);

	return TRUE;    // message was handled
}
