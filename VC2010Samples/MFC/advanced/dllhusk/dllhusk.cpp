// dllhusk.cpp : Defines the class behaviors for the application.
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
#include "dllhusk.h"

#include "mainfrm.h"
#include "testdll1.h"   // classes exported from TESTDLL1
#include "testdll2.h"   // classes exported from TESTDLL2

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuskApp

BEGIN_MESSAGE_MAP(CHuskApp, CWinApp)
	//{{AFX_MSG_MAP(CHuskApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_DUMP_CLASSES, OnDumpClasses)
	ON_COMMAND(ID_DUMP_DOCTEMPLATES, OnDumpDocTemplates)
	ON_COMMAND(ID_DUMP_OBJECTS, OnDumpObjects)
	ON_COMMAND(ID_DUMP_DLLS, OnDumpDLLs)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuskApp construction
// Place all significant initialization in InitInstance

CHuskApp::CHuskApp()
{
	m_pListOut = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHuskApp object

CHuskApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CHuskApp initialization

BOOL CHuskApp::InitInstance()
{
	// Standard initialization

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME)){
		delete pMainFrame; //clean up
		return FALSE;
	}

	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	m_pMainWnd = pMainFrame;

	// Initialize DLLs - will add doc templates and make other class
	//   implementations available to this application
	InitTestDLL1();
	InitTestDLL2();

	CreateListOutput();

	if (m_lpCmdLine[0] == '\0')
	{
		if (m_pListOut != NULL)
			m_pListOut->AddString(_T("Attempting to create a new document"));
		// create a new (empty) document
		OnFileNew();
	}
	else
	{
		if (m_pListOut != NULL)
			m_pListOut->AddString(_T("Attempting to open an existing document"));
		// open an existing document
		OpenDocumentFile(m_lpCmdLine);
	}

#ifdef _DEBUG
	if (m_pListOut != NULL)
	{
		m_pListOut->AddString(_T(""));
		m_pListOut->AddString(_T("Click the Right-Mouse-Button over"));
		m_pListOut->AddString(_T(" the main TitleBar for diagnostic menu"));
		m_pListOut->AddString(_T(""));
	}
#endif
	return TRUE;
}

// Example of calling a class in a DLL
BOOL CHuskApp::CreateListOutput()
{
	m_pListOut = new CListOutputFrame;
			// all objects are allocated on the application's heap,
			//  even CListOutputFrame which is defined in another DLL

	CRect rectOriginal(250, 0, 600, 300);
			// hard-coded initial position

	if (!m_pListOut->Create(_T("List Output"),
			WS_OVERLAPPEDWINDOW | WS_CHILD | WS_VISIBLE,
			rectOriginal, (CMDIFrameWnd*)m_pMainWnd))
	{
		AfxMessageBox(_T("Failed to create ListOutput Window"));
		m_pListOut = NULL;  // just in case (Create will delete the C++ object)
		return FALSE;
	}

	m_pListOut->SetBackpointer(&m_pListOut);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

void CHuskApp::OnAppAbout()
{
	if (m_pListOut != NULL)
		m_pListOut->AddString(_T("CHuskApp::OnAppAbout called"));
	CDialog(IDD_ABOUTBOX).DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CHuskApp debug menu dump commands

#ifdef _DEBUG
static void DumpObjectProc(CObject* pObject, void* pContext)
{
	CListOutputFrame* pListOut = (CListOutputFrame*)pContext;
	TCHAR szT[128];
	_stprintf_s(szT, 128, _T("    a %s at $%08lX"),
		pObject->GetRuntimeClass()->m_lpszClassName, (LONG_PTR)(void*)pObject);
	pListOut->AddString(szT);
}

static void DumpClassProc(const CRuntimeClass* pClass, void* pContext)
{
	CListOutputFrame* pListOut = (CListOutputFrame*)pContext;
	TCHAR szT[128];
	_stprintf_s(szT, 128, _T("    %s"), pClass->m_lpszClassName);
	pListOut->AddString(szT);
}
#endif

void CHuskApp::OnDumpClasses()
{
#ifdef _DEBUG
	if (m_pListOut == NULL && !CreateListOutput())
		return; // no output window
	m_pListOut->AddString(_T("Dump of all classes:"));
	AfxDoForAllClasses(DumpClassProc, m_pListOut);
	m_pListOut->AddString(_T(""));
#endif
}

void CHuskApp::OnDumpDocTemplates()
{
#ifdef _DEBUG
	if (m_pListOut == NULL && !CreateListOutput())
		return; // no output window
	m_pListOut->AddString(_T("Dump of all Doc Templates:"));
	POSITION pos = GetFirstDocTemplatePosition();
	while (pos != NULL)
	{
		CDocTemplate* pTemplate = GetNextDocTemplate(pos);
		CString str;
		TCHAR szT[128];
		if (pTemplate->GetDocString(str, CDocTemplate::fileNewName))
			_stprintf_s(szT, 128, _T("    Template for %s documents"), (LPCTSTR)str);
		else
			_stprintf_s(szT, 128, _T("    Unknown DocTemplate at $%08lX"),
				(LONG_PTR)(void*)pTemplate);
		m_pListOut->AddString(szT);
	}
	m_pListOut->AddString(_T(""));
#endif
}

void CHuskApp::OnDumpObjects()
{
#ifdef _DEBUG
	if (m_pListOut == NULL && !CreateListOutput())
		return; // no output window
	m_pListOut->AddString(_T("Dump of all heap Objects"));
	AfxDoForAllObjects(DumpObjectProc, m_pListOut);
	m_pListOut->AddString(_T(""));
#endif
}

void CHuskApp::OnDumpDLLs()
{
#ifdef _DEBUG
	if (m_pListOut == NULL && !CreateListOutput())
		return; // no output window
	m_pListOut->AddString(_T("Dump of DLLs in resource search order"));
	AFX_MODULE_STATE* pState = AfxGetModuleState();
	CDynLinkLibrary* pDLL = NULL;
	for (pDLL = pState->m_libraryList; pDLL != NULL;
		pDLL = pDLL->m_pNextDLL)
	{
		// get module name
		TCHAR szName[255];
		DWORD dwRet = 0;
		dwRet = ::GetModuleFileName(pDLL->m_hModule, szName, sizeof(szName));
		TCHAR szT[256];

		// count classes
		int nClasses = 0;
		for (CRuntimeClass* pClass = pDLL->m_classList;
			pClass != NULL; pClass = pClass->m_pNextClass)
			nClasses++;

		// count factories
		int nFactories = 0;
	#ifndef _AFX_NO_OLE_SUPPORT
		for (COleObjectFactory* pFactory = pDLL->m_factoryList;
			pFactory != NULL; pFactory = pFactory->m_pNextFactory)
			nFactories++;
	#endif

		_stprintf_s(szT, 256, _T("    Module %s has %d classes and %d factories"),
			szName, nClasses, nFactories);
		m_pListOut->AddString(szT);
	}
	m_pListOut->AddString(_T(""));
#endif
}

/////////////////////////////////////////////////////////////////////////////
