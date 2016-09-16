// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0400		// Change this to 0x0500 to target Windows 98 and Windows 2000.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0400	// Change this to 0x0500 to target Windows 2000.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0400	// Change this to 0x0500 to target IE 5.0.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

using namespace ATL;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#pragma warning (disable : 4146)


#define OFFICE2007 1
#define OFFICEXP 2
#define OFFICE2000 3

// Default Settings
#define OFFICE_VER OFFICE2007

#define _M2STR(x) #x
#define M2STR(x) _M2STR(x)

// Ignore hard wired default paths if MSDLL_PATH is
// defined from the command line
#ifndef MSDLL_PATH

// Paths to required MS OFFICE files.
// Make sure these paths are correct for your  machine
#pragma message ("Make sure the path to MSO DLL is correct.")
#if OFFICE_VER == OFFICE2007
#define _MSDLL_PATH "C:\Program Files\Common Files\Microsoft Shared\Office12\MSO.DLL"
#elif  OFFICE_VER == OFFICEXP
#define _MSDLL_PATH "C:\Program Files\Common Files\Microsoft Shared\Office11\MSO.DLL"
#elif  OFFICE_VER == OFFICE2000
#define   _MSDLL_PATH "C:\Program Files\Microsoft Office\Office\MSO9.dll"
#endif

#else
#define _MSDLL_PATH M2STR(MSDLL_PATH)
#endif

//
// Delete the *.tlh files when changing import qualifiers
#import _MSDLL_PATH rename("RGB", "MSRGB") rename("DocumentProperties", "WordDocumentProperties") raw_interfaces_only

#ifdef VBE6EXT_PATH
#import M2STR(VBE6EXT_PATH) 
#else
#import "C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB" raw_interfaces_only
#endif

// Ignore hard wired default paths if MSWORDOLB_PATH is
// defined from the command line
#ifndef MSWORDOLB_PATH

#pragma message ("Make sure the path to MSWORD OLB is correct.")
#if OFFICE_VER == OFFICE2007
#define _MSWORDOLB_PATH "F:\Program Files\Microsoft Office\OFFICE12\MSWORD.OLB"
#elif  OFFICE_VER == OFFICEXP
#define _MSWORDOLB_PATH "C:\Program Files\Microsoft Office\OFFICE11\MSWORD.OLB"
#elif  OFFICE_VER == OFFICE2000
#define _MSWORDOLB_PATH "C:\Program Files\Microsoft Office\Office\MSWORD9.OLB"
#endif

#else
#define _MSWORDOLB_PATH M2STR(MSWORDOLB_PATH)
#endif

#import _MSWORDOLB_PATH rename("ExitWindows", "WordExitWindows") rename("FindText", "WordFindText") raw_interfaces_only

#pragma warning (default : 4146)
