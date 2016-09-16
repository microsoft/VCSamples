// SSE2Surface32.cpp : implementation of the CSSE2Surface32Intrinsic
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

// Optimized for a 4-pixel processing 32 bit buffer
void CSSE2Surface32Intrinsic::AdjustWidth(int *pWidth)
{
	ASSERT(pWidth != NULL);
	ASSERT(m_kDeltaX <= 3);

	*pWidth = (*pWidth + 3-m_kDeltaX) & ~3; // round up by 4
}

void CSSE2Surface32Intrinsic::OnCreated()
{
	ASSERT(GetBitDepth() == 32);
	ASSERT((GetPitch() & 0xF) == 0);
	ASSERT(GetVisibleWidth() && GetVisibleHeight());
	ASSERT(sizeof(RGBQUAD) == 4);

	int width = GetVisibleWidth();
    m_qwpl  = GetPitch()/8; // qwords Per Line
    m_width = (width+3)/4; // 4 pixels at a time
}

void CSSE2Surface32Intrinsic::BlurBits()
{
    int height = GetVisibleHeight();
    ULONGLONG *pCur  = (ULONGLONG *)GetPixelAddress(0,0);
	ASSERT((DWORD_PTR(pCur) & 0xF) == 0);

	CSSE2 cFader;
	CSSE2 cRight, cLeft;
	CSSE2 cUp, cDown, cCur;
	CSSE2 cResult;

	cFader.UnpackBytesLo( 0x0101010101010101u );
	cLeft.Clear();

	do {
		int width = m_width;
		ASSERT((DWORD_PTR(pCur) & 0xF) == 0);
		do {
			RGBQUAD *pdwCur = (RGBQUAD*)pCur;
			ULONGLONG *pNext = (ULONGLONG*)(pdwCur+1);

			// Load pixels and do the mmx unpack
			cCur.UnpackBytesLo( *pCur );
			cRight.UnpackBytesLo( *pNext );
			cUp.UnpackBytesLo( pCur[-m_qwpl] );
			cDown.UnpackBytesLo( pCur[m_qwpl] );

			// Actual math. Don't step on current, or right.
			// Sum the 4 around and double the middle
			
			// Do current pixel in this line
			cResult = (cDown+cUp+cLeft+cRight+(cCur<<2))>>3;

			// Do next pixel
			cLeft = cRight; 		// Slide left!
			cCur.UnpackBytesLo( pCur[1] );
			cRight.UnpackBytesLo( pNext[1] );
			cUp.UnpackBytesLo( pCur[-m_qwpl+1] );
			cDown.UnpackBytesLo( pCur[m_qwpl+1] );
			cCur = (cDown+cUp+cLeft+cRight+(cCur<<2))>>3;

#if defined(TRIPPY)
			cCur += cFader; // increase the fade to white
			cResult += cFader; // increase the fade to white
#elif defined (FAST_FADE)
    	    cCur -= cFader; // increase the fade to black
    	    cResult -= cFader; // increase the fade to black
#endif
			cLeft = cRight; 		// Slide left!
	
			cResult.PackBytes(pCur, cCur);
			pCur += 2;
		} while (--width > 0);
	} while (--height > 0);
}
