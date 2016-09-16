// viewex.cpp : Defines the class behaviors for the application.
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
#include "viewex.h"

#include "splitter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewExApp

BEGIN_MESSAGE_MAP(CViewExApp, CWinApp)
	//{{AFX_MSG_MAP(CViewExApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewExApp construction
// Place all significant initialization in InitInstance

CViewExApp::CViewExApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CViewExApp object

CViewExApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CViewExApp initialization

BOOL CViewExApp::InitInstance()
{
	// This VIEWEX sample shows several techniques for creating CView
	//  derived classes.   All the views in this sample use the same
	//  CMainDoc class.  For simplicity the CMainDoc class does not
	//  support serialization, but has a very simple data model of
	//  a single string and an RGB color.  We register different
	//  document templates for each of the interesting view types.

	// simple text output view
	AddDocTemplate(new CMultiDocTemplate(IDR_TEXTTYPE,
			RUNTIME_CLASS(CMainDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CTextView)));

	// simple color output view
	//   a doc template with no 'fileNewName' so it is not a choice for FileNew
	AddDocTemplate(new CMultiDocTemplate(IDR_COLORTYPE,
			RUNTIME_CLASS(CMainDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CColorView)));

	// form view with input
	AddDocTemplate(new CMultiDocTemplate(IDR_INPUTTYPE,
			RUNTIME_CLASS(CMainDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CInputView)));

	// splitter frame with both simple text output and form input view
	AddDocTemplate(new CMultiDocTemplate(IDR_SPLIT2TYPE,
			RUNTIME_CLASS(CMainDoc),
			RUNTIME_CLASS(CSplitterFrame),
			RUNTIME_CLASS(CTextView)));

	// 3-way splitter frame with form input, text output and color output views
	AddDocTemplate(new CMultiDocTemplate(IDR_SPLIT3TYPE,
			RUNTIME_CLASS(CMainDoc),
			RUNTIME_CLASS(C3WaySplitterFrame),
			RUNTIME_CLASS(CInputView)));

	// create main MDI Frame window
	// Please note that for simple MDI Frame windows with no toolbar,
	//   status bar or other special behavior, the CMDIFrameWnd class
	//   can be used directly for the main frame window just as the
	//   CMDIChildWnd can be use for a document frame window.

	CMDIFrameWnd* pMainFrame = new CMDIFrameWnd;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		// free the memory
		delete pMainFrame;
		return FALSE;
	}

	// Also in this example, there is only one menubar shared between
	//  all the views.  The automatic menu enabling support of MFC
	//  will disable the menu items that don't apply based on the
	//  currently active view.  The one MenuBar is used for all
	//  document types, including when there are no open documents.

	// Now finally show the main menu
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	m_pMainWnd = pMainFrame;

	// command line arguments are ignored, create a new (empty) document
	OnFileNew();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CViewExApp commands

void CViewExApp::OnAppAbout()
{
	CDialog(IDD_ABOUTBOX).DoModal();
}

/////////////////////////////////////////////////////////////////////////////
