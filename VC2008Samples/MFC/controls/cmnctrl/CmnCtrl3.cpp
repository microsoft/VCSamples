// CmnCtrl3.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"

#include "CmnCtrl3.h"
#include "AllControlsSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCmnCtrl3App

BEGIN_MESSAGE_MAP(CCmnCtrl3App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CCmnCtrl3App construction
CCmnCtrl3App::CCmnCtrl3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CCmnCtrl3App object
CCmnCtrl3App theApp;

// CCmnCtrl3App initialization
BOOL CCmnCtrl3App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

	CAllControlsSheet   allcontrolssheet(_T("Common Controls Sample"));
	m_pMainWnd = &allcontrolssheet;
	allcontrolssheet.DoModal();
	return FALSE;
}
