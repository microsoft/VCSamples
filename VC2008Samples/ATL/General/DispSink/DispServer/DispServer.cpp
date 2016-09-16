// DispServer.cpp : Implementation of WinMain
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
#include "DispServer.h"

#include "DispServer_i.c"
#include "DispServ.h"

class CDispSvrModule : 
	public CAtlExeModuleT< CDispSvrModule >
{
public :
	DECLARE_LIBID(LIBID_DISPSERVERLib)
};

CDispSvrModule _AtlModule;

////////////////////////////////////////////////////////////////////////////////////
// EXE entry point
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}