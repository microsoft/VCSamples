// AutoServer.cpp : Implementation of WinMain
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
#include "AutoServer.h"

#include "AutoServer_i.c"
#include "AutoServ.h"

class CAutoSvrModule : 
	public CAtlExeModuleT< CAutoSvrModule >,
	public CAtlAutoThreadModule
{
public :
	DECLARE_LIBID(LIBID_AUTOSERVERLib)
};

CAutoSvrModule _AtlModule;

////////////////////////////////////////////////////////////////////////////////////
// EXE entry point
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}
