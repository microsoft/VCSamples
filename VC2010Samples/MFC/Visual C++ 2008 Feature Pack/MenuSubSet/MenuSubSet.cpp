// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "MenuSubSet.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "MenuSubSetDoc.h"
#include "MenuSubSetView.h"

#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetApp

BEGIN_MESSAGE_MAP(CMenuSubSetApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetApp construction

CMenuSubSetApp::CMenuSubSetApp() :
	CWinAppEx (TRUE /* m_bResourceSmartUpdate */)
{
	m_nCurrConfig = 0;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMenuSubSetApp object

CMenuSubSetApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetApp initialization

BOOL CMenuSubSetApp::InitInstance()
{
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Microsoft\\MFC\\Samples"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	SetRegistryBase (_T("Settings"));

	m_nCurrConfig = GetInt (_T("Configuration"), 0);

	// Initialize all Managers for usage. They are automatically constructed
	// if not yet present
	InitContextMenuManager();
	InitKeyboardManager();

	// TODO: Remove this if you don't want extended tooltips:
	InitTooltipManager();

	CMFCToolTipInfo params;
	params.m_bVislManagerTheme = TRUE;

	theApp.GetTooltipManager ()->SetTooltipParams (
		AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS (CMFCToolTipCtrl),
		&params);

// -EXAMPLE-

	// Choose application configuration:
	BOOL bResetToolbars = ChooseConfig (TRUE);

// --

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MENUSUTYPE,
		RUNTIME_CLASS(CMenuSubSetDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CMenuSubSetView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

// -EXAMPLE-

	if (bResetToolbars)
	{
		CMFCToolBar::ResetAll ();
	}

// --

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMenuSubSetApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetApp message handlers

int CMenuSubSetApp::ExitInstance() 
{
	return CWinAppEx::ExitInstance();
}

void CMenuSubSetApp::PreLoadState ()
{

	GetContextMenuManager()->AddMenu (_T("My menu"), IDR_CONTEXT_MENU);

	// TODO: add another context menus here
}


/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetApp message handlers

BOOL CMenuSubSetApp::SaveAllModified()
{
	if (!CWinApp::SaveAllModified ())
	{
		return FALSE;
	}

	CMDIFrameWndEx* pMainFrame = 
		DYNAMIC_DOWNCAST (CMDIFrameWndEx, m_pMainWnd);
	if (pMainFrame != NULL)
	{
		pMainFrame->SaveMDIState (GetRegSectionPath ());
	}

	return TRUE;
}

// -EXAMPLE-

BOOL CMenuSubSetApp::ChooseConfig(BOOL bIsStartup)
{
	CConfigDlg dlgConfig (bIsStartup);

	dlgConfig.m_nConfig = m_nCurrConfig;
	
	if (dlgConfig.DoModal () != IDOK)
	{
		return FALSE;
	}

	BOOL bResetToolbars = m_nCurrConfig != dlgConfig.m_nConfig;

	m_nCurrConfig = dlgConfig.m_nConfig;

	// These commands will be removed from all menus/toolbars/keyboard shortcuts:
	CList<UINT, UINT> lstNonPermittedCommands;

	switch (dlgConfig.m_nConfig)
	{
	case 0:
		// All commands will be visible
		break;

	case 1:
		// Remove demo commands:
		lstNonPermittedCommands.AddTail (ID_DEMO_DEMO1);
		lstNonPermittedCommands.AddTail (ID_DEMO_DEMO2);
		break;

	case 2:
		// Remove demo/save commands:
		lstNonPermittedCommands.AddTail (ID_DEMO_DEMO1);
		lstNonPermittedCommands.AddTail (ID_DEMO_DEMO2);
		lstNonPermittedCommands.AddTail (ID_FILE_SAVE);
		lstNonPermittedCommands.AddTail (ID_FILE_SAVE_AS);
		break;
	}

	CMFCToolBar::SetNonPermittedCommands (lstNonPermittedCommands);

	WriteInt (_T("Configuration"), m_nCurrConfig);
	return bResetToolbars;
}

// ---
