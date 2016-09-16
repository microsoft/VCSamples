// circ.cpp : Implementation of DLL Exports.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// You will need the NT SUR Beta 2 SDK or VC 4.2 in order to build this
// project.  This is because you will need MIDL 3.00.15 or higher and new
// headers and libs.  If you have VC 4.2 installed, then everything should
// already be configured correctly.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f circps.mak in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "CircCtl.h"

#define IID_DEFINED

[ module(dll,
		 uuid = "08F9C743-9BCC-4e6e-BC0C-AF558B56FF30",
		 name = "CIRCAttrib",
		 helpstring = "circ Attrib 1.0 Type Library")
];