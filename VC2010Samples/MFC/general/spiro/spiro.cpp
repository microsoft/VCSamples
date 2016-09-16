// spiro.cpp : Defines the class behaviors for the application.
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
#include "spiro.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpiroApp

BEGIN_MESSAGE_MAP(CSpiroApp, CWinApp)
	//{{AFX_MSG_MAP(CSpiroApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpiroApp construction

CSpiroApp::CSpiroApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSpiroApp object

CSpiroApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSpiroApp initialization

void CSpiroApp::SetLandscape() 
{
    // Get default printer settings.
    PRINTDLG   pd;

    pd.lStructSize = (DWORD) sizeof(PRINTDLG);
    if (GetPrinterDeviceDefaults(&pd))
    {
        // Lock memory handle.
        DEVMODE FAR* pDevMode =
            (DEVMODE FAR*)::GlobalLock(m_hDevMode);
        LPDEVNAMES lpDevNames;
        LPTSTR lpszDriverName, lpszDeviceName, lpszPortName;
        HANDLE hPrinter;


        if (pDevMode)
        {
            // Change printer settings in here.
            pDevMode->dmOrientation = DMORIENT_LANDSCAPE;
           // Unlock memory handle.
	       lpDevNames = (LPDEVNAMES)GlobalLock(pd.hDevNames);
		   lpszDriverName = (LPTSTR )lpDevNames + lpDevNames->wDriverOffset;
			lpszDeviceName = (LPTSTR )lpDevNames + lpDevNames->wDeviceOffset;
			lpszPortName   = (LPTSTR )lpDevNames + lpDevNames->wOutputOffset;

			::OpenPrinter(lpszDeviceName, &hPrinter, NULL);
			::DocumentProperties(NULL,hPrinter,lpszDeviceName,pDevMode,
                           pDevMode, DM_IN_BUFFER|DM_OUT_BUFFER);

       // Sync the pDevMode.
       // See SDK help for DocumentProperties for more info.
		   ::ClosePrinter(hPrinter);
	       ::GlobalUnlock(m_hDevNames);
		   ::GlobalUnlock(m_hDevMode);
		}
    }
} 

BOOL CSpiroApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)
	SetLandscape();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSpiroDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CSpiroView));
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	m_cursorRing = LoadCursor(IDC_DROPRING);
	m_cursorWheel = LoadCursor(IDC_DROPWHEEL);

	m_imageList.Create(IDB_PENCIL, 48, 2, RGB(255, 255, 255));

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
void CSpiroApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroApp commands
