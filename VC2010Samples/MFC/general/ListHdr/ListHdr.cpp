// ListHdr.cpp : Defines the class behaviors for the application.
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
#include "ListHdr.h"
#include "LHdrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListHdrApp

BEGIN_MESSAGE_MAP(CListHdrApp, CWinApp)
	//{{AFX_MSG_MAP(CListHdrApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListHdrApp construction

CListHdrApp::CListHdrApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CListHdrApp object

CListHdrApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CListHdrApp initialization

BOOL CListHdrApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	CListHdrDlg dlg;
	m_pMainWnd = &dlg;

	// Bring up modal dialog
	dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
