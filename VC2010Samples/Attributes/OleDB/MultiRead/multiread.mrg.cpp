// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\oledb\multiread\multiread.mrg.cpp
// compiler-generated file created 09/15/17 at 22:56:32
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

#pragma message("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code



//+++ Start Injected Code For Attribute 'module'
#injected_line 21 "MultiRead.cpp"
extern "C" const __declspec(selectany) GUID __LIBID_ = {0x186f6fa3,0x7435,0x11d1,{0x8f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00}};
struct __declspec(uuid("186f6fa3-7435-11d1-8f0f-000000000000")) MULTIREADLib;

//--- End Injected Code For Attribute 'module'
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
 :
    /*+++ Added Baseclass */ public ATL::CAtlExeModuleT<CMyModule>
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

	//+++ Start Injected Code For Attribute 'module'
    #injected_line 21 "MultiRead.cpp"

    						DECLARE_LIBID(__uuidof(MULTIREADLib))
    					
	//--- End Injected Code For Attribute 'module'
}

//+++ Start Injected Code For Attribute 'module'
#injected_line 21 "MultiRead.cpp"

extern CMyModule _AtlModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 21 "MultiRead.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 21 "MultiRead.cpp"

CMyModule _AtlModule;

#injected_line 21 "MultiRead.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd)
    					
{
    return _AtlModule.WinMain(nShowCmd);
}

//--- End Injected Code For Attribute 'module'
;
