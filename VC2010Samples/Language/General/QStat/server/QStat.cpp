//Copyright (c) Microsoft Corporation.  All rights reserved.
//
// QStat.cpp : Implementation of DLL Exports.
//

#include "stdafx.h"
#include "resource.h"

// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{B6083577-2AF6-411A-A762-EFF37B6D8152}", 
		 name = "QStat", 
		 helpstring = "QStat 1.0 Type Library",
		 resource_name = "IDR_QSTAT") ];
