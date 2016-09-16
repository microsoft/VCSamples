// SSE2Surface16.cpp : implementation of the CSSE2Surface16Intrinsic
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
#include "SSE2Surface.h"
#include "SSE2Wrapper.h"

typedef CSSE2Unsigned16Saturated CSSE2;

// Optimized for a 8 pixel processing 16 bit buffer
void CSSE2Surface16Intrinsic::AdjustWidth(int *pWidth)
{
	ASSERT(pWidth != NULL);
	ASSERT(m_kDeltaX <= 7);

	// need to align/round-up to 128-bits/16-bytes
	// so that each line starts on an aligned boundary.

	// Since a pixel is 2 bytes wide, this means rounding
	// the nearest 8 pixels.
	*pWidth = (*pWidth+7-m_kDeltaX)& ~0x7;
}

void CSSE2Surface16Intrinsic::OnCreated()
{
	ASSERT(GetBitDepth() == 16);
	ASSERT((GetPitch() & 0xF) == 0);
	ASSERT(GetVisibleWidth() && GetVisibleHeight());

	int width = GetVisibleWidth();
    m_qqwpl  = GetPitch()/16; // qwords Per Line
    m_width = (width+7)/8; // 8 pixels at a time
}

// Note: It's still faster than the brute force approach,
// However, it's slower than choosing 24 bit and blitting to
// a 16 bit screen. breaking out the bits into MMX friendly sizes
// doesn't work out well.
void CSSE2Surface16Intrinsic::BlurBits()
{
    int height = GetVisibleHeight();
    __m128i *pCur  = (__m128i *)GetPixelAddress(0,0);

	CSSE2 cUpBase, cDownBase, cCurBase, cLeftBase, cRightBase;
	CSSE2 cUp, cDown, cCur, cLeft, cRight;
	CSSE2 cDest;
	CSSE2 cMask;
	cMask.Fill(0x001f001f001f001fu); // colorspace mask - 5 bits per color

	do {
		int width = m_width;
		do {
			// Load pixels and do the mmx unpack
			// Note: pwCur is used to do non-aligned
			// data reads - which is not normally recommended.
			// on X86, it is faster than loading aligned and
			// shift-oring.
			WORD *pwCur = (WORD *)pCur;
			cLeftBase.LoadU(pwCur-1);
			cCurBase.Load(pCur);
			cRightBase.LoadU(pwCur+1);
			cUpBase.Load(pCur-m_qqwpl);
			cDownBase.Load(pCur+m_qqwpl);

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
			cDest.Store(pCur++);
			cMask >>= 10;
		} while (--width > 0);
	} while (--height > 0);
}
