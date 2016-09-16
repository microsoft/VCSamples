// Dlgcbar.cpp : Defines the class behaviors for the application.
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

#include "resource.h"
#include "dlgcbar.h"
#include "aboutdlg.h"
#include "wndlist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTheApp

CTheApp theApp;

BEGIN_MESSAGE_MAP(CTheApp, CWinApp)
	//{{AFX_MSG_MAP(CTheApp)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTheApp Constructors/Destructors

CTheApp::CTheApp()
{
}

CTheApp::~CTheApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTheApp::FirstInstance
//      FirstInstance checks for an existing instance of the application.
//      If one is found, it is activated.
//
//      This function uses a technique similar to that described in KB
//      article Q109175 to locate the previous instance of the application.
//      However, instead of searching for a matching class name, it searches
//      for a matching caption.  This allows us to use the normal dialog
//      class for our main window.  It assumes that the AFX_IDS_APP_TITLE
//      string resource matches the caption specified in the dialog template.

BOOL CTheApp::FirstInstance()
{
	CString strCaption;
	strCaption.LoadString(AFX_IDS_APP_TITLE);

	CWnd* pwndFirst = CWnd::FindWindow((LPCTSTR)(DWORD_PTR)WC_DIALOG,
									   strCaption);
	if (pwndFirst)
	{
		// another instance is already running - activate it
		CWnd* pwndPopup = pwndFirst->GetLastActivePopup();
		pwndFirst->SetForegroundWindow();
		if (pwndFirst->IsIconic())
			pwndFirst->ShowWindow(SW_SHOWNORMAL);
		if (pwndFirst != pwndPopup)
			pwndPopup->SetForegroundWindow();
		return FALSE;
	}
	else
	{
		// this is the first instance
		return TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTheApp::InitInstance
//      InitInstance performs per-instance initialization of the DLGCBAR
//      application.  If an instance of the application is already running,
//      it activates that instance.  Otherwise, it creates the modeless
//      dialog which serves as the application's interface.

BOOL CTheApp::InitInstance()
{
	if (!FirstInstance())
		return FALSE;

	// Create main window
	TRY
	{
		CWndListDlg* pMainWnd = new CWndListDlg;
		m_pMainWnd = pMainWnd;
		return pMainWnd->Create();
	}
	CATCH_ALL(e)
	{
		TRACE0("Failed to create main dialog\n");
		return FALSE;
	}
	END_CATCH_ALL

}

/////////////////////////////////////////////////////////////////////////////
// CTheApp::OnHelpAbout
//      OnHelpAbout displays the application's about box.

void CTheApp::OnHelpAbout()
{
	CAboutDlg dlg(m_pMainWnd);
	dlg.DoModal();
}
