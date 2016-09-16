// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers

#include <afxctl.h>         // MFC support for OLE Controls
#include <afxcmn.h>
// Delete the two includes below if you do not wish to use the MFC
//  database classes
#ifndef _UNICODE
#include <afxdb.h>          // MFC database classes

#endif //_UNICODE

#pragma warning (push)
#pragma warning (disable : 4005)
#include "hlp\HTMLDefines.h"
#include "hlp\popups.h"
#pragma warning (pop)
