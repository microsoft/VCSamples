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

#include "stdafx.h"
#include <initguid.h>
#include "duck.h"
#include "mydlg.h"

#include "duck_i.c"
#include "duckint.h"

CMyDlg mydlg;

class CDuckModule : public CAtlExeModuleT< CDuckModule >
{
public:
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_Duck, "{120B72A3-65BF-11D0-9DDC-00A0C9034892}")
	DECLARE_LIBID(LIBID_DUCKLib)
	
	HRESULT PreMessageLoop(int nShowCmd)
	{
		HRESULT hr = CAtlExeModuleT<CDuckModule>::PreMessageLoop(nShowCmd);
		if (FAILED(hr))
			return hr;
	
		mydlg.DoModal();
		
		return S_FALSE;
	}
};

CDuckModule _AtlModule;

/////////////////////////////////////////////////////////////////////////////
//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/,
	HINSTANCE /*hPrevInstance*/, LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	_AtlModule.WinMain(nShowCmd);
}
