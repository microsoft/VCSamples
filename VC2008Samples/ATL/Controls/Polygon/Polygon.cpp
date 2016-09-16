// Polygon.cpp : Implementation of DLL Exports.

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f Polygonps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "Polygon.h"

#include "Polygon_i.c"
#include "PolyCtl.h"
#include "PolyProp.h"

class CatlPolygonModule : public CAtlDllModuleT< CatlPolygonModule >
{
public :
	DECLARE_LIBID(LIBID_POLYGONLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_POLYGON, "{FEB4F8A5-0105-48bd-AC06-2F94F5020EF5}")
};

CatlPolygonModule _AtlModule;

OBJECT_ENTRY_AUTO(CLSID_PolyCtl, CPolyCtl)
OBJECT_ENTRY_AUTO(CLSID_PolyProp, CPolyProp)

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