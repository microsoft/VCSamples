// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoClient.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f AutoClientps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include "AutoCtl.h"


[emitidl];
[module(dll, name="AutoClientLib", uuid="{A6D89F1F-35F4-11D2-9375-00C04FD9757C}", helpstring="Autoclient 1.0 Type Library")];