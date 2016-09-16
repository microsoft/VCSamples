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

#include "ATLCon1.h"


#pragma comment(lib, "comctl32.lib")

[ module(exe,
		 uuid = "4210A082-0771-4d35-ADDC-980F404DA174",
		 name = "ATLConAttrib",
		 helpstring = "ATLCon Attrib 1.0 Type Library")
]
class CMyComModule 
{
public:
		CAtlCon * m_pWndFrame;
		
	HRESULT PreMessageLoop(int nShowCmd) throw()	
	{
		HRESULT hr = S_OK;
		// call base first
		hr = __super::PreMessageLoop(nShowCmd);
		if(FAILED(hr))
			return hr;
			
		::InitCommonControls();
		
		m_pWndFrame = new CAtlCon;
		if(NULL == m_pWndFrame)
			return E_OUTOFMEMORY;
			
		RECT rcPos = { CW_USEDEFAULT, 0, 0, 0 };
		HMENU hMenu = LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
		HICON hIcon = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_ICON1));
		m_pWndFrame->GetWndClassInfo().m_wc.hIcon = hIcon;
		m_pWndFrame->Create(GetDesktopWindow(), rcPos, _T("ATL Container"), 0, 0, (UINT)hMenu);
		m_pWndFrame->ShowWindow(SW_SHOWNORMAL);
		
		return hr;
	}
};

