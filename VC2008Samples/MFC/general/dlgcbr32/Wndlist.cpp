// WndList.cpp : Implementation file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/*****************************************************************************
  Purpose:
	Implements CWndListDlg, the main dialog window for the application.

  Functions:
	CWndListDlg::CWndListDlg()          -- constructor
	CWndListDlg::Create()               -- create dialog window
	CWndListDlg::DoDataExchange()       -- dialog data exchange/validation
	CWndListDlg::OnClose()              -- WM_CLOSE handler
	CWndListDlg::OnInitDialog()         -- initialize dialog
	CWndListDlg::OnOptionNow()          -- handle "Options!Update Now"
	CWndListDlg::OnOptionRate()         -- handle "Options!Update Interval"
	CWndListDlg::OnSelChangeWndList()   -- update dlg on list selection change
	CWndListDlg::OnTimer()              -- WM_TIMER handler
	CWndListDlg::OnUpdateOptionRate()   -- set "Options!Update Interval" status
	CWndListDlg::OnUpdateTime()         -- update status bar clock
	CWndListDlg::WalkWindowList()       -- enumerate windows

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#include "stdafx.h"
#include <afxpriv.h>
#include "resource.h"
#include "wndlist.h"
#include "ratedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg control bar data

static UINT auIDStatusBar[] = {
   ID_SEPARATOR,
   ID_INDICATOR_TIME
};

static UINT auIDToolBar[] = {
   ID_APP_EXIT,
   ID_SEPARATOR,
   ID_OPTION_NOW,
   ID_OPTION_RATE,
   ID_SEPARATOR,
   ID_HELP_ABOUT
};

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg dialog

CWndListDlg::CWndListDlg()
{
	//{{AFX_DATA_INIT(CWndListDlg)
	//}}AFX_DATA_INIT
	m_nIDTimer = 0;
	m_iRate = m_iTicks = 0;
}

BOOL CWndListDlg::Create()
{
	return CModelessMain::Create(CWndListDlg::IDD,
								 auIDStatusBar,
								 sizeof(auIDStatusBar)/sizeof(UINT),
								 auIDToolBar,
								 sizeof(auIDToolBar)/sizeof(UINT),
								 IDR_MAIN);
}

void CWndListDlg::DoDataExchange(CDataExchange* pDX)
{
	CModelessMain::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWndListDlg)
	DDX_Control(pDX, IDC_WNDLIST, m_lbWindows);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWndListDlg, CModelessMain)
	//{{AFX_MSG_MAP(CWndListDlg)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_LBN_SELCHANGE(IDC_WNDLIST, OnSelChangeWndList)
	ON_COMMAND(ID_OPTION_NOW, OnOptionNow)
	ON_COMMAND(ID_OPTION_RATE, OnOptionRate)
	ON_UPDATE_COMMAND_UI(ID_OPTION_RATE, OnUpdateOptionRate)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_TIME, OnUpdateTime)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnInitDialog
//      OnInitDialog fills the listbox with information about the parent
//      windows which exist.  It also sets up a 1sec timer, which is used
//      to automatically update the listbox contents and/or to update the
//      status bar clock.

BOOL CWndListDlg::OnInitDialog()
{
	CModelessMain::OnInitDialog();

	// Initialize windows listbox contents
	WalkWindowList();
	OnSelChangeWndList();

	// Set up a 1 second timer
	m_nIDTimer = (UINT)SetTimer(1, 1000, NULL);
	if (!m_nIDTimer)
		AfxMessageBox(IDP_NOTIMER);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnClose
//      OnClose makes sure the 1sec timer is destroyed when the dialog
//      is closed.

void CWndListDlg::OnClose()
{
	if (m_nIDTimer)
	{
		KillTimer(m_nIDTimer);
		m_nIDTimer = NULL;
	}
	CModelessMain::OnClose();
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::WalkWindowList
//      WalkWindowList enumerates all parent windows on the screen.
//      It adds a string containing the window handle and caption to
//      the listbox for each window, using the helper function
//      EnumWindowsProc().

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	static TCHAR szBuffer[90];
	static TCHAR szTemp[80];

	static TCHAR szFormat[] = _T("%08lX: %s");
	HWND hwndListBox = (HWND)lParam;
	CListBox* plb = (CListBox*)CWnd::FromHandle(hwndListBox);

	GetWindowText(hwnd, szTemp, sizeof(szTemp));
	_stprintf_s(szBuffer, 90, szFormat, hwnd, szTemp);

	return (plb->AddString(szBuffer) >= 0) ? TRUE : FALSE;
}

void CWndListDlg::WalkWindowList()
{
	// don't assume that m_lbWindows has been initialized yet
	CListBox* plb = (CListBox*)GetDlgItem(IDC_WNDLIST);

	plb->SetRedraw(FALSE);
	plb->ResetContent();

	EnumWindows(EnumWindowsProc, (LPARAM)plb->GetSafeHwnd());

	plb->SetRedraw(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnSelChangeWndList
//      OnSelChangeWndList updates the static dialog fields when the
//      window listbox selection is changed.

void CWndListDlg::OnSelChangeWndList()
{
	static TCHAR szBuffer[256];
	static TCHAR szTemp[80];

	static TCHAR szParse[]  = _T("%08lX");
	static TCHAR szFormat[] = _T("%08lX: %s");

	HWND hwnd = 0;
	BOOL bValid = FALSE;

	int iSel = m_lbWindows.GetCurSel();
	if (iSel >= 0)
	{
		m_lbWindows.GetText(iSel, szBuffer);
		if( _stscanf_s(szBuffer, szParse, &hwnd) == 1 )
			bValid = ::IsWindow(hwnd);
		else
			bValid = FALSE;
	}

	if (bValid)
	{
		::GetClassName(hwnd, szBuffer, sizeof(szBuffer));
		GetDlgItem(IDC_CLASS)->SetWindowText(szBuffer);

		HINSTANCE hInstance = (HINSTANCE)::GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
		::GetModuleFileName(hInstance, szBuffer, sizeof(szBuffer));
		GetDlgItem(IDC_MODULE)->SetWindowText(szBuffer);

		HWND hwndParent = ::GetParent(hwnd);
		::GetWindowText(hwndParent, szTemp, sizeof(szTemp));
		_stprintf_s(szBuffer, 256, szFormat, hwndParent, szTemp);
		GetDlgItem(IDC_PARENT)->SetWindowText(szBuffer);

		RECT rect;
		::GetWindowRect(hwnd, &rect);
		_stprintf_s(szBuffer, 256, _T("(%d,%d) - (%d,%d)"), rect.left, rect.top,
				rect.right, rect.bottom);
		GetDlgItem(IDC_RECT)->SetWindowText(szBuffer);

		LONG lStyle = ::GetWindowLong(hwnd, GWL_STYLE);
		_stprintf_s(szBuffer, 256, _T("%08lX"), lStyle);
		GetDlgItem(IDC_STYLE)->SetWindowText(szBuffer);
	}
	else
	{
		szBuffer[0] = '\0';
		GetDlgItem(IDC_CLASS)->SetWindowText(szBuffer);
		GetDlgItem(IDC_MODULE)->SetWindowText(szBuffer);
		GetDlgItem(IDC_PARENT)->SetWindowText(szBuffer);
		GetDlgItem(IDC_RECT)->SetWindowText(szBuffer);
		GetDlgItem(IDC_STYLE)->SetWindowText(szBuffer);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnTimer()
//      OnTimer handles messages from the 1sec interval timer.  The variable
//      m_iRate indicates how many timer messages must be received before
//      the window list is updated.  The variable m_iTicks indicates how
//      many timer messages have been received since the last time the
//      window list was updated.

void CWndListDlg::OnTimer(UINT_PTR /*nIDEvent*/)
{
	if (m_iRate)
	{
		m_iTicks++;
		if (m_iTicks == m_iRate)
			OnOptionNow();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnOptionNow()
//      OnOptionNow resets the update interval counter, refills the window
//      list, and resets the selection, if possible.

void CWndListDlg::OnOptionNow()
{
	m_iTicks = 0;

	int iTopIndex = m_lbWindows.GetTopIndex();

	CString strSelect;
	int iSel = m_lbWindows.GetCurSel();
	if (iSel >= 0)
		m_lbWindows.GetText(iSel, strSelect);

	WalkWindowList();

	if (m_lbWindows.SelectString(-1, strSelect) <= 0)
		m_lbWindows.SetCurSel(iSel);

	m_lbWindows.SetTopIndex(iTopIndex);

}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnOptionRate()
//      OnOptionRate allows the user to specify the rate at which the
//      window list should be updated.

void CWndListDlg::OnOptionRate()
{
	CRateDlg dlg(m_iRate, this);
	if (dlg.DoModal() == IDOK)
		m_iRate = dlg.GetRate();
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnUpdateOptionRate()
//      OnUpdateOptionRate enables or disables the Option Update Rate...
//      command, depending on whether or not a timer has been created.

void CWndListDlg::OnUpdateOptionRate(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_nIDTimer != 0);
}

/////////////////////////////////////////////////////////////////////////////
// CWndListDlg::OnUpdateTime()
//      OnUpdateTime updates the status bar clock.

void CWndListDlg::OnUpdateTime(CCmdUI* pCmdUI)
{
	CTime t = CTime::GetCurrentTime();
	TCHAR  szTime[6];
	SYSTEMTIME sysTime;
	t.GetAsSystemTime(sysTime);

	// Localize to user locale, strip seconds and time marker
	int nLen;
	nLen = GetTimeFormat(LOCALE_USER_DEFAULT, TIME_NOSECONDS|TIME_NOTIMEMARKER,
			&sysTime, NULL, szTime, sizeof(szTime));
	// Now set the text of the pane
	CStatusBar* pStatusBar = GetStatusBar();
	pStatusBar->SetPaneText(pStatusBar->CommandToIndex(ID_INDICATOR_TIME),
							szTime);
	pCmdUI->Enable();
}
