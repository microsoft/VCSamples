// CmnCtrl2.cpp : Defines the class behaviors for the application.
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
#include "CmnCtrl2.h"
#include "propsht.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrl2App

BEGIN_MESSAGE_MAP(CCmnCtrl2App, CWinApp)
	//{{AFX_MSG_MAP(CCmnCtrl2App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrl2App construction

CCmnCtrl2App::CCmnCtrl2App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCmnCtrl2App object

CCmnCtrl2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrl2App initialization

BOOL CCmnCtrl2App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

	CAllControlsSheet   allcontrolssheet(_T("Common Controls Sample"));
	m_pMainWnd = &allcontrolssheet;
	allcontrolssheet.DoModal();
	return FALSE;
}
