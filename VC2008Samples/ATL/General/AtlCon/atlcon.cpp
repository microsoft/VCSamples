// ATLCon.cpp : Example showing how to host controls and
//              create frame windows using ATL
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "ATLCon.h"
#include "ATLCon_i.c"
#include "ATLCon1.h"
#pragma comment(lib, "comctl32.lib")


class CATLConModule : public CAtlExeModuleT< CATLConModule >
{
public :
	DECLARE_LIBID(LIBID_ATLCONLib);
	CAtlCon* m_pwndMain;

	CATLConModule() : m_pwndMain(NULL)
	{
	}
	~CATLConModule()
	{
		delete m_pwndMain;
	}

	HRESULT PreMessageLoop(int nShowCmd) throw()
	{
		HRESULT hr = __super::PreMessageLoop(nShowCmd);
		if (FAILED(hr))
		{
			return hr;
		}

		::InitCommonControls();

		RECT rcPos = { CW_USEDEFAULT, 0, 0, 0 };
		HMENU hMenu = LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
		HICON hIcon = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_ICON1));
		m_pwndMain = new CAtlCon;
		if (m_pwndMain == NULL)
		{
			__super::PostMessageLoop();
			return E_OUTOFMEMORY;
		}
		m_pwndMain->GetWndClassInfo().m_wc.hIcon = hIcon;
		m_pwndMain->Create(GetDesktopWindow(), rcPos, _T("ATL Container"), 0, 0, hMenu);
		m_pwndMain->ShowWindow(nShowCmd);

		return S_OK;
	}
};

CATLConModule _AtlModule;

extern "C" int WINAPI _tWinMain(HINSTANCE , HINSTANCE , 
                                LPTSTR , int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}
