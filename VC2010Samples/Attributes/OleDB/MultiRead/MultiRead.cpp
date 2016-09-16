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
#include "MultiDlg.h"

[ module(exe,
		 uuid = "186F6FA3-7435-11D1-8F0F-000000000000",
		 name = "MULTIREADLib",
		 helpstring = "MultiRead 1.0 Type Library"),
  threading(free)
]
class CMyModule
{
public:
	HRESULT PreMessageLoop(int nShowCmd) throw()	
	{
		HRESULT hr = S_OK;
		hr = __super::PreMessageLoop(nShowCmd);
		if(FAILED(hr))
			return hr;

		CMultiDlg dlg;
		dlg.DoModal();
		return S_FALSE;
	}
};
