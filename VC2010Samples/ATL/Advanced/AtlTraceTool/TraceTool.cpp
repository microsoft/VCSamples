// TraceTool.cpp : Defines the class behaviors for the application.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "TraceTool.h"
#include "TraceToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HMODULE LoadLocalizedResourceDLLUsingPath(const CString &strPath, const CString &strDLLName)
{
	if (strPath.IsEmpty() || strPath.IsEmpty())
	{
		return NULL;
	}

	// Check if given path even exists
	if (GetFileAttributes(strPath) == 0xFFFFFFFF)
	{
		return NULL;
	}

	LANGID langid = GetUserDefaultUILanguage();
	const LCID lcidUser = MAKELCID(langid, SORT_DEFAULT);

	LCID rglcid[3];
	rglcid[0] = lcidUser;
	rglcid[1] = MAKELCID(MAKELANGID(PRIMARYLANGID(lcidUser), SUBLANG_DEFAULT), SORTIDFROMLCID(lcidUser));
	rglcid[2] = 0x409;

	CString strFullPath;
	BOOL fFoundDLL = FALSE;

	for (int i = 0; i < _countof(rglcid); i++)
	{
		// Check if it's the same as any LCID already checked, which is very possible
		int n = 0;
		for (n = 0; n < i; n++)
		{
			if (rglcid[n] == rglcid[i])
				break;
		}

		if (n < i)
		{
			continue;
		}

		strFullPath.Format(_T("%s\\%d\\%s"), strPath, rglcid[i], strDLLName);

		if (GetFileAttributes(strFullPath) != 0xFFFFFFFF)
		{
			fFoundDLL = TRUE;
			break;
		}
	}

	if (fFoundDLL)
	{
		// Finally, attempt to load the library
		return LoadLibraryEx(strFullPath, NULL, 0);
	}

	return NULL;
}

HMODULE LoadLocalizedResourceDLL(const CString &strDLLName)
{
	TCHAR szModulePath[_MAX_PATH + 1];
	GetModuleFileName(GetModuleHandle(NULL), szModulePath, _MAX_PATH);

	// find path of current executable
	CString strModule = szModulePath;
	CString strPath = strModule.Left(strModule.ReverseFind(_T('\\')));

	return LoadLocalizedResourceDLLUsingPath(strPath, strDLLName);
}

const TCHAR* szTraceToolUIDll = _T("AtlTraceToolUI.dll");

/////////////////////////////////////////////////////////////////////////////
// CTraceToolApp

BEGIN_MESSAGE_MAP(CTraceToolApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTraceToolApp construction

CTraceToolApp::CTraceToolApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	EnableHtmlHelp();

	// Enable the restart manager so ATLTrace supports WM_QUERYENDSESSION/WM_ENDSESSION.
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
}


// The one and only CTraceToolApp object

CTraceToolApp theApp;


// CTraceToolApp initialization

static const LPCTSTR g_pszEventName = _T( "ATLTraceTool_Instance" );

BOOL CTraceToolApp::InitInstance()
{
#ifndef _M_IA64
	// Turn on the "termination on heap corruption" flag.
	(void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
#endif

	// Check to see if another instance of the tool is running
	BOOL bCreated = m_hSingleInstanceEvent.Create( NULL, FALSE, FALSE, g_pszEventName );
	if( !bCreated )
	{
		return( FALSE );
	}
	HINSTANCE hInstRes=LoadLocalizedResourceDLL(szTraceToolUIDll);
	AfxSetResourceHandle(hInstRes);
	if( ::GetLastError() == ERROR_ALREADY_EXISTS )
	{
		m_hSingleInstanceEvent.Set();  // Notify the original instance
		return( FALSE );
	}

	CWinApp::InitInstance();


	CTraceToolDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
