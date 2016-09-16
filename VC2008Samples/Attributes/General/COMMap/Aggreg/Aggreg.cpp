// Aggreg.cpp : Implementation of DLL Exports.
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
//      run nmake -f Aggregps.mak in the project directory.

#include "preagg.h"
#include "aggres.h"
#include "initguid.h"
#include "Agg.h"
#include "AggBlind.h"
#include "AutoAgg.h"
#include "AutoAggB.h"

//#define IID_DEFINED


[emitidl];
[ module(dll, name="AggregLib", uuid = "{4F9A68EB-DD9D-11CF-9462-00AA00BBAD7F}", helpstring = "Aggreg 1.0 Type Library")];