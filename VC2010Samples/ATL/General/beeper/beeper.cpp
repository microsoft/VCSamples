// beeper.cpp : Implementation of CBeeperApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "prebeep.h"
#include <initguid.h>
#include "resource.h"
#include "beeper.h"
#include "beepobj.h"

#define IID_DEFINED
#include "beeper_i.c"

#ifndef _WINDLL
// Beeper as an exe
class CBeeperModule : public CAtlExeModuleT< CBeeperModule >
{
public :
	DECLARE_LIBID(LIBID_BeeperLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BEEPEREXE, "{92491A56-D6BD-4517-AB30-C09DD4CA73F6}")
};

#else
// Beeper as a dll
class CBeeperModule : public CAtlDllModuleT< CBeeperModule >
{
public :
	DECLARE_LIBID(LIBID_BeeperLib)
};

#endif //_WINDLL

CBeeperModule _AtlModule;

/////////////////////////////////////////////////////////////////////////////
// EXE Entry Point

#ifndef _WINDLL
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}
#else
/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
#endif //_WINDLL