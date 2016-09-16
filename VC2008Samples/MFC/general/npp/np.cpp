// np.cpp : Defines the class behaviors for the application.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

#include "stdafx.h"
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"
#include <locale.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotepadApp

BEGIN_MESSAGE_MAP(CNotepadApp, CWinApp)
	//{{AFX_MSG_MAP(CNotepadApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotepadApp construction

CNotepadApp::CNotepadApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNotepadApp object

CNotepadApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNotepadApp initialization

BOOL CNotepadApp::InitInstance()
{
	_tsetlocale(LC_ALL, _T(""));

	// Standard initialization

	LoadStdProfileSettings(8);  // Load standard INI file options (including MRU)

	// Register document templates

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CNotepadDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CNotepadView));
	AddDocTemplate(pDocTemplate);

	// open file specified on command line
	if (m_lpCmdLine[0] == 0)
		OnFileNew();
	else
		OpenDocumentFile(m_lpCmdLine);

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
void CNotepadApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadApp commands

BOOL CNotepadApp::OnIdle(LONG lCount)
{
	CMainFrame* pFrame = (CMainFrame*) AfxGetMainWnd();
	CStatusBar* pStatusBar = (CStatusBar*) pFrame->GetDescendantWindow(AFX_IDW_STATUS_BAR);

	if(pStatusBar)
	{
		CEdit &edit = ((CEditView*)pFrame->GetActiveView())->GetEditCtrl();
		CString s1;
		UINT i = edit.LineFromChar();
		s1.Format(_T("Ln %u"), ++i);
		pStatusBar->SetPaneText(pStatusBar->CommandToIndex(ID_INDICATOR_LINE), s1);
	}

	return CWinApp::OnIdle(lCount);
}
