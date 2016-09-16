// MMXSurface16.cpp : implementation of the CMMXSurface16Intrinsic
// class
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
#include "MMXSurface.h"
#include "MMXWrapper.h"

typedef CMMXUnsigned16Saturated CMMX;

// Optimized for a 4 pixel processing 16 bit buffer
void CMMXSurface16Intrinsic::AdjustWidth(int *pWidth)
{
	ASSERT(pWidth != NULL);
	ASSERT(m_kDeltaX <= 3);
	// to avoid special casing the end of the loop,
	// our visible pixel width needs to be a multiple of 4

	*pWidth = (*pWidth+3-m_kDeltaX)& ~0x3;
}

void CMMXSurface16Intrinsic::OnCreated()
{
	ASSERT(GetBitDepth() == 16);
	ASSERT((GetPitch() & 0x7) == 0);
	ASSERT(GetVisibleWidth() && GetVisibleHeight());

	int width = GetVisibleWidth();
    m_qwpl  = GetPitch()/8; // qwords Per Line
    m_width = (width+3)/4; // 4 pixels at a time
}

// Note: It's still faster than the brute force approach,
// However, it's slower than choosing 24 bit and blitting to
// a 16 bit screen. breaking out the bits into MMX friendly sizes
// doesn't work out well.
void CMMXSurface16Intrinsic::BlurBits()
{
    int height = GetVisibleHeight();
    ULONGLONG *pCur  = (ULONGLONG *)GetPixelAddress(0,0);

	CMMX cUpBase, cDownBase, cCurBase, cLeftBase, cRightBase;
	CMMX cUp, cDown, cCur, cLeft, cRight;
	CMMX cDest;
	CMMX cMask(0x001f001f001f001fu); // colorspace mask - 5 bits per color

	do {
		int width = m_width;
		do {
			// Load pixels and do the mmx unpack
			// Note: pwCur is used to do non-aligned
			// data reads - which is not normally recommended.
			// on X86, it is faster than loading aligned and
			// shift-oring.
			WORD *pwCur = (WORD *)pCur;
			cLeftBase = *(ULONGLONG*)(pwCur-1);
			cCurBase = pCur[0];
			cRightBase = *(ULONGLONG*)(pwCur+1);
			cUpBase = pCur[-m_qwpl];
			cDownBase = pCur[+m_qwpl];

			cLeft = cLeftBase & cMask;
			cCur = cCurBase & cMask;
			cRight = cRightBase & cMask;
			cUp = cUpBase & cMask;
			cDown = cDownBase & cMask;

			// Actual math. Don't step on current, or right.
			// Sum the 4 around and double the middle
			// Do current pixel in this line
			cDest = ((cDown+cUp+cLeft+cRight+(cCur<<2))>>3);
			cMask <<= 5;

			cLeft = cLeftBase & cMask;
			cCur = cCurBase & cMask;
			cRight = cRightBase & cMask;
			cUp = cUpBase & cMask;
			cDown = cDownBase & cMask;

			// Actual math for next color space
			cDest |= cMask & ((cDown+cUp+cLeft+cRight+(cCur<<2))>>3);
			cMask <<= 5;

			cLeft = (cLeftBase & cMask) >> 3;
			cCur = (cCurBase & cMask) >> 3;
			cRight = (cRightBase & cMask) >> 3;
			cUp = (cUpBase & cMask) >> 3;
			cDown = (cDownBase & cMask) >> 3;

			// Actual math for next color space
			cDest |= cMask & (cDown+cUp+cLeft+cRight+(cCur<<2));
			*pCur++ = cDest;
			cMask >>= 10;
		} while (--width > 0);
	} while (--height > 0);
}
