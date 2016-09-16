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

#define STRICT
#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED

// The following is required to use riched32.dll in a Unicode build
#define _RICHEDIT_VER 0x100
#define ATL_TRACE_LEVEL 4

#include <atlbase.h>

// You may derive a class from CComModule and use it if you want
// to override something, but do not change the name of _Module

extern CComModule _Module;

#include <atlcom.h>
#include <atlctl.h>
