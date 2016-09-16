// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

#ifndef WINVER				
#define WINVER 0x0400		
#endif

#ifndef _WIN32_WINNT		
#define _WIN32_WINNT 0x0400	
#endif						

#ifndef _WIN32_WINDOWS		
#define _WIN32_WINDOWS 0x0410 
#endif

#ifndef _WIN32_IE			
#define _WIN32_IE 0x0400	
#endif

#define _ATL_APARTMENT_THREADED

#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	

#define _ATL_APARTMENT_THREADED


#include <atlbase.h>

using namespace ATL;

#include <atlcom.h>
#include <atlhost.h>
#include <atlctl.h>
#include <afxres.h>
#include <atlstr.h>