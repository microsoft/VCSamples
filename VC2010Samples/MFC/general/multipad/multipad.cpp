// multipad.cpp : Defines the class behaviors for the Multipad application.
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
#include "multipad.h"
#include <locale.h>

CMultiPadApp NEAR theApp;

BEGIN_MESSAGE_MAP(CMultiPadApp, CWinApp)
	//{{AFX_MSG_MAP(CMultiPadApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)     // file commands...
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

BOOL CMultiPadApp::InitInstance()
{
	_tsetlocale(LC_ALL, _T(""));

	LoadStdProfileSettings();

	AddDocTemplate(new CMultiDocTemplate(IDR_TEXTTYPE,
		RUNTIME_CLASS(CPadDoc), RUNTIME_CLASS(CMDIChildWnd),
		RUNTIME_CLASS(CEditView)));
	m_pMainWnd = new CMainFrame;
	((CFrameWnd*)m_pMainWnd)->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd->ShowWindow(m_nCmdShow);

	// enable file manager drag/drop and DDE Execute open
	m_pMainWnd->DragAcceptFiles();
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	return TRUE;
}

void CMultiPadApp::OnAppAbout()
{
	CDialog(IDD_ABOUTBOX).DoModal();
}

IMPLEMENT_DYNCREATE(CMainFrame, CMDIFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT buttons[] =
{
	ID_FILE_NEW, ID_FILE_OPEN, ID_FILE_SAVE, ID_SEPARATOR,
	ID_EDIT_CUT, ID_EDIT_COPY, ID_EDIT_PASTE, ID_SEPARATOR,
	ID_FILE_PRINT, ID_APP_ABOUT
};

static UINT indicators[] =
{
	ID_SEPARATOR, ID_INDICATOR_CAPS, ID_INDICATOR_NUM, ID_INDICATOR_SCRL
};

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	((m_ToolBar.Create(this) &&
		m_ToolBar.LoadBitmap(IDR_MAINFRAME) &&
		m_ToolBar.SetButtons(buttons, sizeof(buttons)/sizeof(UINT)) &&
		m_StatusBar.Create(this) &&
		m_StatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT)))
	  ? 0 : -1);
	return CMDIFrameWnd::OnCreate(lpCreateStruct);
}

IMPLEMENT_DYNCREATE(CPadDoc, CDocument)
BEGIN_MESSAGE_MAP(CPadDoc, CDocument)
	//{{AFX_MSG_MAP(CPadDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPadDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
