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

#include "stdafx.h"
#include <initguid.h>
#include "atlduck.h"

#include "atlduck_i.c"
#include "DuckDoer.h"

class CAtlDuckModule : public CAtlExeModuleT< CAtlDuckModule >
{
public:
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_Atlduck, "{120B7294-65BF-11D0-9DDC-00A0C9034892}")
	DECLARE_LIBID(LIBID_ATLDUCKLib)
	
	HRESULT PreMessageLoop(int nShowCmd)
	{
		_ASSERT(CDuckDoer::m_pDlg == NULL);
		CDuckDoer::m_pDlg = new CDuckDoerDlg();
		CDuckDoer::m_pDlg->Create(NULL);
		CDuckDoer::m_pDlg->ShowWindow(SW_SHOWNORMAL);
		_ASSERT(CDuckDoer::m_pDlg != NULL);
		
		HRESULT hr = CAtlExeModuleT<CAtlDuckModule>::PreMessageLoop(nShowCmd);
		if (FAILED(hr))
			return hr;
	

		
		return S_OK;
	}
};

CAtlDuckModule _AtlModule;

/////////////////////////////////////////////////////////////////////////////
//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/,
	HINSTANCE /*hPrevInstance*/, LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	_AtlModule.WinMain(nShowCmd);
}
