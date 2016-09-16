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

#if !defined(AFX_STDAFX_H__120B7297_65BF_11D0_9DDC_00A0C9034892__INCLUDED_)
#define AFX_STDAFX_H__120B7297_65BF_11D0_9DDC_00A0C9034892__INCLUDED_

#pragma once

#define STRICT

#define _ATL_APARTMENT_THREADED
#pragma warning(disable:4100)
#include <stdio.h>

#include <atlbase.h>

#include <atlcom.h>
#include <atlwin.h>

#ifndef _VERIFY
#ifdef _DEBUG
#define _VERIFY(x)  if (!x) {_ASSERT(FALSE);}
#else
#define _VERIFY(x)  x
#endif
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__120B7297_65BF_11D0_9DDC_00A0C9034892__INCLUDED)
