// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_STDAFX_H__4417CF88_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)
#define AFX_STDAFX_H__4417CF88_AFA9_11D1_AB61_D9B80632F018__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define		MM_SPIRO		MM_LOENGLISH
#define		CYCLE_ERROR		5  // tolerance(error) in distance to consider a pattern done
#define		TRACES_PER_TICK_SLOW	8
#define		TRACES_PER_TICK_FAST	16

#include <afxtempl.h>

#ifndef elementsof
#define elementsof(rgX) ((int)(sizeof(rgX) / sizeof(rgX[0])))
#endif


#define PENMARKERSIZE	5


#include "piece.h"
#include "spirodoc.h"
#include "spiroview.h"

#include <winspool.h>
#include <math.h>

#pragma warning(disable: 4172)

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.


// custom definitions for the spirograph application
#endif // !defined(AFX_STDAFX_H__4417CF88_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)

