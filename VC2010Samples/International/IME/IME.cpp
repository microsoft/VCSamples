/******************************************************************************\
*	IME.cpp : Defines the class behaviors for the application.
*
*	This is a part of the Microsoft Source Code Samples. 
*	Copyright (c) Microsoft Corporation.
*	All rights reserved. 
*
*	This source code is only intended as a supplement to 
*	Microsoft Development Tools and/or WinHelp documentation.
*	See these sources for detailed information regarding the 
*	Microsoft samples programs.
\******************************************************************************/


#include "stdafx.h"
#include "IMM.h"
#include "IMEEdit.h"
#include "IME.h"
#include "IMEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIMEApp

BEGIN_MESSAGE_MAP(CIMEApp, CWinApp)
	//{{AFX_MSG_MAP(CIMEApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIMEApp construction

CIMEApp::CIMEApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIMEApp object

CIMEApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CIMEApp initialization

BOOL CIMEApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CIMEDlg dlg;
	dlg.DoModal();

	return FALSE;
}
