// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#define _ATL_DISABLE_NO_VTABLE
#define _ATL_APARTMENT_THREADED
#define STRICT
#define NO_DISPATCH_TRACE
#define _ATL_DEBUG_REFCOUNT
#define ATL_NO_NAMESPACE

#pragma warning(disable : 4100)

#include <atlbase.h>

#ifdef _DEBUG
#define _ATL_DEBUG_QI
#endif //_DEBUG

#include <atlcom.h>
#include <atlwin.h>
#include <atlctl.h>

