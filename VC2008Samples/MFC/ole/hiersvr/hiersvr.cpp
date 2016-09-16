// hiersvr.cpp : Defines the class behaviors for the application.
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
#include "hiersvr.h"

#include "mainfrm.h"
#include "ipframe.h"
#include "svrdoc.h"
#include "svrview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerApp

BEGIN_MESSAGE_MAP(CServerApp, CWinApp)
	//{{AFX_MSG_MAP(CServerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerApp construction
// Place all significant initialization in InitInstance

CServerApp::CServerApp()
{
		EnableHtmlHelp();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CServerApp object

CServerApp theApp;

// this is the GUID for HIERSVR documents
static const GUID BASED_CODE clsid =
	{ 0x00021841, 0, 0, { 0xC0, 0, 0, 0, 0, 0, 0, 0x46 } };

/////////////////////////////////////////////////////////////////////////////
//

CHierSvrDocTemplate::CHierSvrDocTemplate()
: CMultiDocTemplate(IDR_HIERSVRTYPE,
	RUNTIME_CLASS(CServerDoc),
	RUNTIME_CLASS(CMDIChildWnd), // standard MDI child frame
	RUNTIME_CLASS(CServerView))
{
}

CDocTemplate::Confidence CHierSvrDocTemplate::MatchDocType(LPCTSTR lpszPathName,
	CDocument*& rpDocMatch)
{
	CDocTemplate::Confidence ret;

	ret = CMultiDocTemplate::MatchDocType(lpszPathName, rpDocMatch);

	if (ret == CDocTemplate::yesAttemptForeign)
		ret = CDocTemplate::noAttempt;

	return ret;
}

/////////////////////////////////////////////////////////////////////////////
// CServerApp initialization

BOOL CServerApp::InitInstance()
{
#ifdef _DEBUG
	// turn on extra memory tracking
	afxMemDF |= checkAlwaysMemDF;
#endif

	// OLE 2.0 initialization
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_AFXOLEINIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	LoadStdProfileSettings();

	// Register document templates
	CDocTemplate* pDocTemplate;
	pDocTemplate = new CHierSvrDocTemplate;
	pDocTemplate->SetServerInfo(
		IDR_HIERSVRTYPE_SRVR_EMB, IDR_HIERSVRTYPE_SRVR_IP,
		RUNTIME_CLASS(CInPlaceFrame), RUNTIME_CLASS(CServerView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// enable file manager drag/drop and DDE Execute open
	m_pMainWnd->DragAcceptFiles();
	EnableShellOpen();

	// connect the COleTemplate server to the document template
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);
	COleTemplateServer::RegisterAll();
		// Note: MDI applications register all class objects regardless of
		//  the /Embedding on the command line.

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// try to launch as an OLE server
	if (cmdInfo.m_bRunEmbedded)
	{
		// application was run with /Embedding flag.  Instead of showing
		//  the window, the application waits to receive OLE requests.
		return TRUE;
	}

	m_server.UpdateRegistry();
	RegisterShellFileTypes(TRUE);
	COleObjectFactory::UpdateRegistryAll();

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CServerApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg() : CDialog(CAboutDlg::IDD)
	{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
	}

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
void CServerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CServerApp commands
