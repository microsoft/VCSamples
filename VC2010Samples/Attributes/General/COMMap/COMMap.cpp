// COMMap.cpp : Implementation of DLL Exports.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
//
// You will need the NT SUR Beta 2 SDK or VC 4.2 in order to build this
// project.  This is because you will need MIDL 3.00.15 or higher and new
// headers and libs.  If you have VC 4.2 installed, then everything should
// already be configured correctly.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f COMMapps.mak in the project directory.

#include "premap.h"
#include "mapres.h"
#include "initguid.h"
#include "Outer.h"


[emitidl];
[ module(dll, name="COMMapLib", uuid = "{4F9A68DD-DD9D-11CF-9462-00AA00BBAD7F}", helpstring = "COMMap 1.0 Type Library")];


