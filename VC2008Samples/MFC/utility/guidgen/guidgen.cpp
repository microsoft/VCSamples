// guidgen.cpp : Defines the class behaviors for the application.
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
#include "guidgen.h"
#include "guidgdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp

BEGIN_MESSAGE_MAP(CGuidGenApp, CWinApp)
	//{{AFX_MSG_MAP(CGuidGenApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp construction

CGuidGenApp::CGuidGenApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGuidGenApp object

CGuidGenApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp initialization

BOOL CGuidGenApp::InitInstance()
{
	// Turn on the "termination on heap corruption" flag.
	(void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	SetRegistryKey(_T("Microsoft\\MFC 3.0 Samples"));

	if (::CoInitialize(NULL) != S_OK)
	{
		AfxMessageBox(IDP_ERR_INIT_OLE);
		return FALSE;
	}

	// process command line arguments
	CWnd* pParentWnd = NULL;
	for (LPCTSTR lpsz = m_lpCmdLine; *lpsz != 0; ++lpsz)
	{
		if (*lpsz != '-' && *lpsz != '/')
			continue;

		switch (lpsz[1])
		{
		// "/A" or "/a" allows the window to be parented to the IDE window
		// add GUIDGEN /A to your tools menu for easy access!
		case 'a':
		case 'A':
			pParentWnd = CWnd::GetForegroundWindow();
			break;
		}
	}

	CGuidGenDlg dlg(pParentWnd);
	m_pMainWnd = &dlg;
	int nResponse = (int)dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CGuidGenApp::ExitInstance()
{
	::CoUninitialize();

	return CWinApp::ExitInstance();
}
