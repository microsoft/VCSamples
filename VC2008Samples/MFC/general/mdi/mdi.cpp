// mdi.cpp : Defines the class behaviors for the application.
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
#include "mdi.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdiApp

BEGIN_MESSAGE_MAP(CMdiApp, CWinApp)
	//{{AFX_MSG_MAP(CMdiApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdiApp construction
// Place all significant initialization in InitInstance

CMdiApp::CMdiApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMdiApp object

CMdiApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CMdiApp initialization

BOOL CMdiApp::InitInstance()
{
	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		// free the memory and return
		delete pMainFrame;
		return FALSE;
	}

	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	m_pMainWnd = pMainFrame;

	// load the two static menus
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMdiApp commands

void CMdiApp::OnAppAbout()
{
	CDialog(IDD_ABOUTBOX).DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// other globals

// Color array maps to Color menu
COLORREF NEAR colorArray[] =
{
	RGB (0, 0, 0),
	RGB (255, 0, 0),
	RGB (0, 255, 0),
	RGB (0, 0, 255),
	RGB (255, 255, 255)
};

/////////////////////////////////////////////////////////////////////////////
