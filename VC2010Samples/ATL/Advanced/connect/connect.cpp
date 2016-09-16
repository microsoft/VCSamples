// Connect.cpp : Implementation of DLL Exports.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "preconn.h"
#include "connres.h"
#include "initguid.h"
#include "Connect.h"
#include "Random.h"

#define IID_DEFINED
#include "Connect_i.c"

class CatlConnectModule : public CAtlDllModuleT< CatlConnectModule >
{
public :
	DECLARE_LIBID(LIBID_CONNECTLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_Random, "{CCE84215-DB31-11CF-9D75-00A0C90391D3}")
};

CatlConnectModule _AtlModule;

OBJECT_ENTRY_AUTO(CLSID_CoRandom, CRandom)

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