// DispClient.cpp : Implementation of DLL Exports.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "resource.h"

// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{8FFCEA5E-4959-41C4-9CE2-B572DBBD7A0E}", 
		 name = "DispClient", 
		 helpstring = "DispClient 1.0 Type Library",
		 resource_name = "IDR_DISPCLIENT") ];
