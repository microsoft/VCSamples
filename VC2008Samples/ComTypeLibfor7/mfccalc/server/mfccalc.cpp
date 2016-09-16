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
const GUID CDECL BASED_CODE _tlid =
		{ 0x5627AF00, 0xF44C, 0x11CD, { 0x8C, 0x3D, 0x00, 0xAA, 0x00, 0x4B, 0xB3, 0xB7 } };

const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

/////////////////////////////////////////////////////////////////////////////
// CCalcApp initialization

BOOL CCalcApp::InitInstance()
{
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.
#if _MFC_VER < 0x0700
	Enable3dControls();
#endif
    // Initialize OLE 2.0 libraries
    if (!AfxOleInit())
    {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

	// Parse command line for automation or reg/unreg switches.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (RunEmbedded() || RunAutomated())
    {
        // Register all OLE server (factories) as running.  This enables the 
        //  OLE 2.0 libraries to create objects from other applications.
        COleTemplateServer::RegisterAll();

        // Do not continue with rest of initialization.  Wait for
        // client to create a CCalcDlg object instead.
        return TRUE;
    }
	// App was launched with /Unregserver or /Unregister switch.  Remove
	// entries from the registry.
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		COleObjectFactory::UpdateRegistryAll(FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
		return FALSE;
	}
	// App was launched standalone or with other switches (e.g. /Register
	// or /Regserver).  Update registry entries, including typelibrary.
	else
	{
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
			return FALSE;
	}

	
    // create a modeless dialog as the main window of the application
	//suppress warning because an object of CDialog is self-destructing
	#pragma warning (suppress: 6014)
    CCalcDlg* pDlg = new CCalcDlg;
    pDlg->SetVisible(TRUE);
    if (!pDlg->GetVisible())
    {
        AfxMessageBox(IDP_UNABLE_TO_SHOW_CALC);
		return FALSE;
    }
    pDlg->RegisterActive();

    // We are using a modeless dialog so we can translate accelerator keys 
    // against the dialog.  In order to run the main message pump, 
    // InitInstance must return TRUE even though this application is
    // a dialog-based application.
    return TRUE;
}
