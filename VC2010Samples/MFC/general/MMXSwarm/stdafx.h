// stdafx.h : include file for standard system include files,
//
// or project specific include files that are used frequently,
// but are changed infrequently
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <atlcoll.h> 		// ATL/MFC shared collection classes
#include <comdef.h>			// for _com_error

#include <emmintrin.h>		// MMX, SSE, SSE2 intrinsic support

inline void SeedRandom(int nSeed = 0)
{ srand(nSeed ? nSeed : ::GetTickCount()); }
inline int Random() { return(rand()); }
inline int Random(int n) { return(rand() % n ); }

bool IsMMX();
bool IsSSE2();

// Note: This file/project expects to run in an environment
// where no float operations are being done. Therefore, we
// don't require resetting the registers states with an EMMS.
// So we disable the warning that tells us we haven't used
// an EMMS instruction
#pragma warning(disable: 4799)
