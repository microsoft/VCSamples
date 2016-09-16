// superpad.cpp : Defines the class behaviors for the application.
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
#include "superpad.h"
#include "mainfrm.h"
#include "padview.h"
#include "paddoc.h"
#include "padframe.h"
#include "ipframe.h"

#include <locale.h>

BEGIN_MESSAGE_MAP(CTheApp, CWinApp)
	//{{AFX_MSG_MAP(CTheApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_PAGE_SETUP, OnPageSetup)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Superpad global data

CTheApp NEAR theApp;

// this is the GUID for OCLIENT documents
static const GUID BASED_CODE clsid =
	{ 0x00021844, 0, 0, { 0xC0, 0, 0, 0, 0, 0, 0, 0x46 } };

/////////////////////////////////////////////////////////////////////////////
// CTheApp initialization

CTheApp::CTheApp()
{
	// initialize locale to system default
	_tsetlocale(LC_ALL, _T(""));
}

BOOL CTheApp::InitInstance()
{
	// initialized OLE 2.0 libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// initialization that must be done before splash dialog is shown
	CPadFrame::Initialize();

	// add doc template
	CDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_TEXTTYPE,
		RUNTIME_CLASS(CPadDoc),
		RUNTIME_CLASS(CPadFrame),
		RUNTIME_CLASS(CPadView));
	pDocTemplate->SetServerInfo(
		IDR_TEXTTYPE_EMBEDDED, IDR_TEXTTYPE_INPLACE,
		RUNTIME_CLASS(CInPlaceFrame));
	AddDocTemplate(pDocTemplate);

	// connect the server to the document template
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);

	// create main window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	int nCmdShow = m_nCmdShow;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// setup main window
	nCmdShow = !cmdInfo.m_bRunEmbedded ? m_nCmdShow : SW_HIDE;
	m_nCmdShow = SW_HIDE;
	((CMainFrame*)m_pMainWnd)->InitialShowWindow(nCmdShow);

	if (!cmdInfo.m_bRunEmbedded)
	{
		m_pMainWnd->UpdateWindow();

		if (!m_pMainWnd->IsIconic() && cmdInfo.m_bShowSplash &&
			m_splash.Create(m_pMainWnd))
		{
			m_splash.ShowWindow(SW_SHOW);
			m_splash.UpdateWindow();
			m_splash.SetTimer(1, 500, NULL);
		}
		m_dwSplashTime = ::GetCurrentTime();

		// update the registry now that the splash dialog is visible
		m_server.UpdateRegistry();
		RegisterShellFileTypes(TRUE);
	}

	// do other initialization after (possibly) creating the splash window
	EnableShellOpen();
	m_pMainWnd->DragAcceptFiles();

	LoadStdProfileSettings();
	CPadView::Initialize();
	dlgPageSetup.Initialize();

	// register any class objects we may have (for automation & OLE)
	COleTemplateServer::RegisterAll();

	// open default file if command line doesn't have /Embedding
	if (!cmdInfo.m_bRunEmbedded)
	{
		// Dispatch commands specified on the command line
		if (!ProcessShellCommand(cmdInfo))
			return FALSE;

		m_nCmdShow = nCmdShow;
		m_pMainWnd->UpdateWindow();
	}

	return TRUE;
}

BOOL CTheApp::OnIdle(LONG lCount)
{
	// call base class idle first
	BOOL bResult = CWinApp::OnIdle(lCount);

	// then do our work
	if (m_splash.m_hWnd != NULL)
	{
		if (::GetCurrentTime() - m_dwSplashTime > 2500)
		{
			// timeout expired, destroy the splash window
			m_splash.DestroyWindow();
			m_pMainWnd->UpdateWindow();

			// NOTE: don't set bResult to FALSE,
			//  CWinApp::OnIdle may have returned TRUE
		}
		else
		{
			// check again later...
			bResult = TRUE;
		}
	}

	return bResult;
}

BOOL CTheApp::PreTranslateMessage(MSG* pMsg)
{
	BOOL bResult = CWinApp::PreTranslateMessage(pMsg);

	if (m_splash.m_hWnd != NULL &&
		(pMsg->message == WM_KEYDOWN ||
		 pMsg->message == WM_SYSKEYDOWN ||
		 pMsg->message == WM_LBUTTONDOWN ||
		 pMsg->message == WM_RBUTTONDOWN ||
		 pMsg->message == WM_MBUTTONDOWN ||
		 pMsg->message == WM_NCLBUTTONDOWN ||
		 pMsg->message == WM_NCRBUTTONDOWN ||
		 pMsg->message == WM_NCMBUTTONDOWN))
	{
		m_splash.DestroyWindow();
		m_pMainWnd->UpdateWindow();
	}

	return bResult;
}

int CTheApp::ExitInstance()
{
	dlgPageSetup.Terminate();
	CPadView::Terminate();
	CPadFrame::Terminate();

	return CWinApp::ExitInstance();
}

CTheApp::~CTheApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTheApp message handlers

void CTheApp::OnAppAbout()
{
	CAboutBox about;
	about.DoModal();
}

CPageSetupDlg NEAR dlgPageSetup;
void CTheApp::OnPageSetup()
{
	dlgPageSetup.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
