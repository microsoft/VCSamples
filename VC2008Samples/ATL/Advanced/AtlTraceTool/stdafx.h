// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
#ifndef WINVER				// Allow use of features specific to Win 2K or later
#define WINVER 0x0500
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Win 2K or later
#define _WIN32_WINNT 0x0500
#endif

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Win 98 or later
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 5.01 or later
#define _WIN32_IE 0x0501
#endif

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <atlcoll.h>
#include <atlsync.h>

// Include database headers.  For a DLL or app which just includes database
// headers (no database view), conditionally include DAO and ODBC.
// If an actual view is used, always & only include the corresponding header.
// First, actual view is used:


#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxtempl.h>
#include <tlhelp32.h>
#include <atldebugapi.h>
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
