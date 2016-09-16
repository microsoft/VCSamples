// Scheduler.cpp : Defines the class behaviors for the application.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "Scheduler.h"
#include "SchedulerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSchedulerApp

BEGIN_MESSAGE_MAP(CSchedulerApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSchedulerApp construction

CSchedulerApp::CSchedulerApp()
{
	EnableHtmlHelp();
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSchedulerApp object

CSchedulerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSchedulerApp initialization

BOOL CSchedulerApp::InitInstance()
{
	AfxEnableControlContainer();


	CSchedulerDlg dlg;
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
	dlg.ExitScheduler();
	return FALSE;
}

template <> void AFXAPI SerializeElements <CMyScheduler> ( CArchive& ar, CMyScheduler* pSchedule, INT_PTR nCount )
{
    for ( int i = 0; i < nCount; i++, pSchedule++ )
    {
        // Serialize each CMyScheduler object
        pSchedule->Serialize( ar );
    }
}
