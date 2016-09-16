// mfccalc.cpp : Defines the class behaviors for the application.
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
#include "mfccalc.h"
#include "calcdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalcApp

BEGIN_MESSAGE_MAP(CCalcApp, CWinApp)
	//{{AFX_MSG_MAP(CCalcApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcApp construction

CCalcApp::CCalcApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCalcApp object

CCalcApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCalcApp initialization

BOOL CCalcApp::InitInstance()
{
	// Initialize OLE 2.0 libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Parse the command line to see if launched as OLE server
	if (RunEmbedded() || RunAutomated())
	{
		// Register all OLE server (factories) as running.  This enables the
		//  OLE 2.0 libraries to create objects from other applications.
		COleTemplateServer::RegisterAll();

		// Do not continue with rest of initialization.  Wait for
		// client to create a CCalcDlg object instead.
		return TRUE;
	}

	// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	COleObjectFactory::UpdateRegistryAll();

	// create a modeless dialog as the main window of the application
	//This disables the warning that the dialog could leak - 
	//it will not leak since the Set Visible registers the dialog as
	//the main frame and any windows message that closes that dialog
	//causes the parent class to call the destructor
	#pragma warning( push )
	#pragma warning(disable:6014)
	CCalcDlg* pDlg = new CCalcDlg;
	#pragma warning( pop )
	pDlg->SetVisible(TRUE);
	if (!pDlg->GetVisible())
	{
		// if GetVisible fails after SetVisibile, we never registered
		// the pDlg with the parent class, and it will not be deleted
		AfxMessageBox(IDP_UNABLE_TO_SHOW_CALC);
		delete pDlg;
		return FALSE;
	}
	pDlg->RegisterActive();

	// We are using a modeless dialog so we can translate accelerator keys
	// against the dialog.  In order to run the main message pump,
	// InitInstance must return TRUE even though this application is
	// a dialog-based application.
	return TRUE;
}
