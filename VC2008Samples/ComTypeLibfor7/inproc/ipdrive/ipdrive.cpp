// ipdrive.cpp : Defines the class behaviors for the application.
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
#include "ipdrive.h"

#include "mainfrm.h"
#include "ipdridoc.h"
#include "ipdrivw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//This routine is used where you want to dump com exception info, 
//especially in catch blocks 
void dump_com_error(_com_error &e)
{
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    TCHAR szTemp[1024];
    CString csMsg = "Oops - hit an error!\n";
    wsprintf(szTemp, _T("Code = %08lx\n"), e.Error());
    csMsg += szTemp;
    wsprintf(szTemp, _T("Code meaning = %s\n"), e.ErrorMessage());
    csMsg += szTemp;
    wsprintf(szTemp, _T("Source = %s\n"), bstrSource.length() ? (LPCTSTR)bstrSource : _T("null"));
    csMsg += szTemp;
    wsprintf(szTemp, _T("Description = %s\n"), bstrDescription.length() ? (LPCTSTR)bstrDescription : _T("null"));
    csMsg += szTemp;
    AfxMessageBox(csMsg);
}

/////////////////////////////////////////////////////////////////////////////
// CDriveApp

BEGIN_MESSAGE_MAP(CDriveApp, CWinApp)
    //{{AFX_MSG_MAP(CDriveApp)
    ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG_MAP
    // Standard file based document commands
    ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriveApp construction

CDriveApp::CDriveApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDriveApp object

CDriveApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CDriveApp initialization

BOOL CDriveApp::InitInstance()
{
    // Initialize OLE libraries
    if (S_OK != OleInitialize(NULL))
    {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#if (_MFC_VER >= 0x300)
#if (_MFC_VER < 0x700)
    Enable3dControls();
#endif
#else
    SetDialogBkColor();
#endif  

    LoadStdProfileSettings();  // Load standard INI file options (including MRU)

    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views.

    CSingleDocTemplate* pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(CDriverDoc),
        RUNTIME_CLASS(CMainFrame),       // main SDI frame window
        RUNTIME_CLASS(CDriverView));
    AddDocTemplate(pDocTemplate);

    // create a new (empty) document
    OnFileNew();

    if (m_lpCmdLine[0] != '\0')
    {
        // TODO: add command line processing here
    }

#ifdef _MAC
    // Enable drag/drop open
    m_pMainWnd->DragAcceptFiles();
#endif

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
//  Clean up at the end of the program

int CDriveApp::ExitInstance ()
{
    OleUninitialize();
    return CWinApp::ExitInstance();
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

// Implementation
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
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
void CDriveApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDriveApp commands
