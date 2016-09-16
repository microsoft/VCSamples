// MultiRead.cpp : Implementation of WinMain
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f MultiReadps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "MultiRead.h"

#include "MultiRead_i.c"
#include "MultiDlg.h"

CMyModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
//
extern "C" int WINAPI _tWinMain(HINSTANCE hInstance,
	HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int /*nShowCmd*/)
{
	lpCmdLine = GetCommandLine();

#if defined(_ATL_FREE_THREADED)
	HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
#else
	HRESULT hRes = CoInitialize(NULL);
#endif
	_ASSERTE(SUCCEEDED(hRes));
	if (!SUCCEEDED(hRes))
		return -1;
	_Module.Init(ObjectMap, hInstance, &LIBID_MULTIREADLib);
	_Module.dwThreadID = GetCurrentThreadId();
//	TCHAR szTokens[] = _T("-/");

	CMultiDlg dlg;
	dlg.DoModal();

	_Module.Term();
	CoUninitialize();
	return 0;
}
