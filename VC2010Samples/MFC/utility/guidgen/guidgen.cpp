// guidgen.cpp : Defines the class behaviors for the application.
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
#include "guidgen.h"
#include "guidgdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
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

const TCHAR *szLocalizedUIDll = _T("GuidGenUI.dll");

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp

BEGIN_MESSAGE_MAP(CGuidGenApp, CWinApp)
	//{{AFX_MSG_MAP(CGuidGenApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp construction

CGuidGenApp::CGuidGenApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGuidGenApp object

CGuidGenApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGuidGenApp initialization

BOOL CGuidGenApp::InitInstance()
{
	// Turn on the "termination on heap corruption" flag.
	(void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	SetRegistryKey(_T("Microsoft\\MFC 3.0 Samples"));

	if (::CoInitialize(NULL) != S_OK)
	{
		AfxMessageBox(IDP_ERR_INIT_OLE);
		return FALSE;
	}

	// Load the localized resource DLL for current locale
	HINSTANCE hInstRes = LoadLocalizedResourceDLL(szLocalizedUIDll);
	AfxSetResourceHandle(hInstRes);

	// process command line arguments
	CWnd* pParentWnd = NULL;
	for (LPCTSTR lpsz = m_lpCmdLine; *lpsz != 0; ++lpsz)
	{
		if (*lpsz != '-' && *lpsz != '/')
			continue;

		switch (lpsz[1])
		{
		// "/A" or "/a" allows the window to be parented to the IDE window
		// add GUIDGEN /A to your tools menu for easy access!
		case 'a':
		case 'A':
			pParentWnd = CWnd::GetForegroundWindow();
			break;
		}
	}

	CGuidGenDlg dlg(pParentWnd);
	m_pMainWnd = &dlg;
	// ignore return value
	dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CGuidGenApp::ExitInstance()
{
	::CoUninitialize();

	return CWinApp::ExitInstance();
}
