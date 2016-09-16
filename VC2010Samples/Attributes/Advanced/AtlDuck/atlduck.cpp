// atlduck.cpp : Implementation of WinMain
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f atlduckps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"

#include "DuckDoer.h"

LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
	while (*p1 != NULL)
	{
		LPCTSTR p = p2;
		while (*p != NULL)
		{
			if (*p1 == *p++)
				return p1+1;
		}
		p1++;
	}
	return NULL;
}

[ module(exe,
		 uuid="89FBD7D7-A6D5-4761-AB0C-DA79191693AA",
		 name="ATLDUCKAttrib",
		 helpstring="atlduck Attrib 1.0 Type Library")
]
class CExeModule
{
public:
	int WinMain(int nShowCmd) throw()
	{
		LPCTSTR lpCmdLine = GetCommandLine();

		CoInitialize(0);
		int nRet = 0;
		HRESULT res;
		BOOL bRun = TRUE;
		TCHAR szTokens[] = _T("-/");
		LPCTSTR lpszToken = FindOneOf(lpCmdLine, szTokens);
		while (lpszToken != NULL)
		{
			if (WordCmpI(lpszToken, _T("UnregServer"))==0)
			{
				res = this->UnregisterServer(TRUE);
				if (SUCCEEDED(res))
					res = this->UnregisterAppId();
				return false;
			}

			// Register as Local Server
			if (WordCmpI(lpszToken, _T("RegServer"))==0)
			{
				res = this->RegisterAppId();
				if (SUCCEEDED(res))
					res = this->RegisterServer(TRUE);
				return false;
			}

			lpszToken = FindOneOf(lpszToken, szTokens);
		}
		if (bRun)
		{
			// create a modeless dialog to be displayed
			_ASSERT(CDuckDoer::m_pDlg == NULL);
			CDuckDoer::m_pDlg = new CDuckDoerDlg();
			CDuckDoer::m_pDlg->Create(NULL);
			CDuckDoer::m_pDlg->ShowWindow(SW_SHOWNORMAL);
			_ASSERT(CDuckDoer::m_pDlg != NULL);

			res = this->RegisterClassObjects(CLSCTX_LOCAL_SERVER,
				REGCLS_MULTIPLEUSE);
			_ASSERTE(SUCCEEDED(res));


			MSG msg;
			while (GetMessage(&msg, 0, 0, 0))
				DispatchMessage(&msg);

			this->RevokeClassObjects();
		}
		CoUninitialize();
		return nRet;
	}
};
