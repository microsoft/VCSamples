// stdafx.cpp : source file that includes just the standard includes
// MMXSwarm.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information
// Also includes utility functions that rarely change.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

// Note: See the CPUID sample for a more complete
// implentation

const DWORD _MMX_FEATURE_BIT = 0x00800000;
const DWORD _SSE2_FEATURE_BIT = 0x04000000;

static bool _IsFeature(DWORD nFeature);


bool IsMMX()
{
	static bool bMMX = _IsFeature(_MMX_FEATURE_BIT);
	return(bMMX);
}

bool IsSSE2()
{
	static bool bSSE2 = _IsFeature(_SSE2_FEATURE_BIT);
	return(bSSE2);
}

static bool _IsFeature(DWORD dwRequestFeature)
{
	// This	bit	flag can get set on	calling	cpuid
	// with	register eax set to	1
	DWORD dwFeature	= 0;
	__try {
			_asm {
				mov	eax,1
				cpuid
				mov	dwFeature,edx
			}
	} __except ( EXCEPTION_EXECUTE_HANDLER)	{
			return false;
	}
	if ((dwRequestFeature == _MMX_FEATURE_BIT) &&
		(dwFeature & _MMX_FEATURE_BIT)) {
		__try {
			__asm {
				pxor mm0, mm0
				emms
			}
		} __except (EXCEPTION_EXECUTE_HANDLER) {
			return (0);
		}
		return(true);
	}
	else if ((dwRequestFeature == _SSE2_FEATURE_BIT) &&
		(dwFeature & _SSE2_FEATURE_BIT)) {
		__try {
			__asm {
				xorpd xmm0, xmm0
			}
		} __except (EXCEPTION_EXECUTE_HANDLER) {
			return (0);
		}
		return(true);
	}

	return false;
}

