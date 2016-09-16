// AdvancedPV.cpp : Implementation of DLL Exports.
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f AdvancedPVps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{961D9EC9-E3C2-47B1-AE59-692A0EEFCEAF}", 
		 name = "AdvancedPV", 
		 helpstring = "AdvancedPV 1.0 Type Library",
		 resource_name = "IDR_ADVANCEDPV") ];
