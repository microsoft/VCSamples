// ctrlbars.cpp : Defines the class behaviors for the application.
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
#include <afxpriv.h>    // for idle-update windows message

#include "ctrlbars.h"
#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtrlbarsApp

BEGIN_MESSAGE_MAP(CCtrlbarsApp, CWinApp)
	//{{AFX_MSG_MAP(CCtrlbarsApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtrlbarsApp construction

CCtrlbarsApp::CCtrlbarsApp()
{
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCtrlbarsApp object

CCtrlbarsApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CCtrlbarsApp initialization

BOOL CCtrlbarsApp::InitInstance()
{
	// create a new SDI main frame window
	CFrameWnd* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		// free the memory
		delete pMainFrame;
		return FALSE;
	}
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	m_pMainWnd = pMainFrame;

	pMainFrame->SendMessage(WM_COMMAND, IDM_VIEWPALETTE, (LPARAM)0);
	return TRUE;
}


// In this override of OnIdle we are doing UI for our app.
// Since this needs to be as fast as possible to give the user
// the best result we do our updates first when lCount is zero
// then we call the library to do its work.
BOOL CCtrlbarsApp::OnIdle(LONG lCount)
{
	if (lCount == 0)
	{
		ENSURE(m_pMainWnd != NULL);

		// look for any top-level windows owned by us
		// we use 'HWND's to avoid generation of too many temporary CWnds
		for (HWND hWnd = ::GetWindow(m_pMainWnd->m_hWnd, GW_HWNDFIRST);
				hWnd != NULL; hWnd = ::GetNextWindow(hWnd, GW_HWNDNEXT))
		{
			if (::GetParent(hWnd) == m_pMainWnd->m_hWnd)
			{
				// if owned window is active, move the activation to the
				//   application window
				if (GetActiveWindow() == hWnd && (::GetCapture() == NULL))
					m_pMainWnd->SetActiveWindow();

				// also update the buttons for the top-level window
				SendMessage(hWnd, WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0L);
			}
		}
	}
	return CWinApp::OnIdle(lCount);
}

/////////////////////////////////////////////////////////////////////////////
// CCtrlbarsApp commands

void CCtrlbarsApp::OnAppAbout()
{
	CDialog(IDD_ABOUTBOX).DoModal();
}

/////////////////////////////////////////////////////////////////////////////
