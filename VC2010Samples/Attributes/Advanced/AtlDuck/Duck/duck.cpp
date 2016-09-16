// duck.cpp : Implementation of WinMain
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
//      run nmake -f duckps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "mydlg.h"

#include "duckint.h"


CMyDlg mydlg;
/////////////////////////////////////////////////////////////////////////////
//

[ module(exe,
		 name = "DUCKAttrib",
		 uuid = "92F978DC-97F2-4559-A2EE-92E7C43316A3",
		 helpstring = "duck Attrib 1.0 Type Library")
]
class CDUCKAttribModule
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
			res = this->RegisterClassObjects(CLSCTX_LOCAL_SERVER,
				REGCLS_MULTIPLEUSE);
			_ASSERTE(SUCCEEDED(res));


			mydlg.DoModal();

			this->RevokeClassObjects();
		}
		CoUninitialize();
		return nRet;
	}
};