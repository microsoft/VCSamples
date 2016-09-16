// AtlAgent.cpp : Implementation of DLL Exports.
//
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
//      run nmake -f AtlAgentps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "AgentCtl.h"

[ module(dll,
		 uuid = "079B4F1C-19E1-4a1b-A316-CA72BCA49E86",
		 name = "ATLAgentAttrib",
		 helpstring = "AtlAgent Attrib 1.0 Type Library")
];
