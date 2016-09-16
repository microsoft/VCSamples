// SSE2Surface24.cpp : implementation of the CSSE2Surface24Intrinsic
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

// Optimized for a 4-pixel processing 24 bit buffer
void CSSE2Surface24Intrinsic::AdjustWidth(int *pWidth)
{
	ASSERT(pWidth != NULL);
	ASSERT(m_kDeltaX <= 15);

	// need to align/round-up to 256-bits/32-bytes
	// since we process 32 bit chunks.

	// Also need to make sure the pitch is 16 byte aligned.
	// so that each line starts on an aligned boundary.

	// Since a pixel is 3 bytes wide, this unfortunately means
	// making it 48 byte aligned, or 48/3 pixels, or round up to
	// the nearest 16.
	*pWidth = (*pWidth+15-m_kDeltaX)& ~0xF;
}

void CSSE2Surface24Intrinsic::OnCreated()
{
	ASSERT(GetBitDepth() == 24);
	ASSERT((GetPitch() & 0xF) == 0);
	ASSERT(GetVisibleWidth() && GetVisibleHeight());
	ASSERT(sizeof(RGBTRIPLE) == 3);

	int width = GetVisibleWidth();
    m_qwpl  = GetPitch()/8; // qwords Per Line
    m_width = (width*3+15)/16;// (+7/8) // m_qwpl/2 without processing off-screen bits;
	m_delta = m_qwpl - m_width*2;
}

void CSSE2Surface24Intrinsic::BlurBits()
{
    int height = GetVisibleHeight();
    ULONGLONG *pCur  = (ULONGLONG*)GetPixelAddress(0,0);

	CSSE2 cFader;
	CSSE2 cRight, cLeft;
	CSSE2 cUp, cDown, cCur;
	CSSE2 cResult;

	cFader.UnpackBytesLo( 0x0101010101010101u );
	cLeft.Clear();

	do {
		int width = m_width;
		do {
			BYTE *bpCur = (BYTE *)pCur;
			// Load pixels and do the mmx unpack
			cCur.UnpackBytesLo( pCur[0] );
			// treating non-aligned data as dwords isn't generally a good idea
			cRight.UnpackBytesLo( *(ULONGLONG *)(bpCur+3) );
			cUp.UnpackBytesLo( pCur[-m_qwpl] );
			cDown.UnpackBytesLo( pCur[m_qwpl] );

			// Sum the 4 around and double the middle
			// Do current pixel in this line
			cResult = (cDown+cUp+cLeft+cRight+(cCur<<2))>>3;

			cLeft.UnpackBytesLo( *(ULONGLONG *)(bpCur+5) );
			pCur++;
			bpCur = (BYTE *)pCur;
			cCur.UnpackBytesLo( pCur[0] );
			cRight.UnpackBytesLo( *(ULONGLONG *)(bpCur+3) );
			cUp.UnpackBytesLo( pCur[-m_qwpl] );
			cDown.UnpackBytesLo( pCur[m_qwpl] );
			cCur = (cDown+cUp+cLeft+cRight+(cCur<<2))>>3;

#if defined(TRIPPY)
			cCur += cFader; // increase the fade to white
			cResult += cFader; // increase the fade to white
#elif defined (FAST_FADE)
			cCur -= cFader; // increase the fade to white
			cResult -= cFader; // increase the fade to white
#endif
			// Reset the left before we write anything out.
			// treating non-aligned data as dwords isn't generally a good idea
			cLeft.UnpackBytesLo( *(ULONGLONG *)(bpCur+5) );
			cResult.PackBytes(pCur-1, cCur);
			pCur++;
		} while (--width > 0);
		pCur += m_delta;
	} while (--height > 0);
}
