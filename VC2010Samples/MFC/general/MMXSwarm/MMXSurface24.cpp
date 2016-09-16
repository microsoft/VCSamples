// MMXSurface24.cpp : implementation of the CMMXSurface24Intrinsic
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

void CMMXSurface24Intrinsic::OnCreated()
{
	ASSERT(GetBitDepth() == 24);
	ASSERT(GetVisibleWidth() && GetVisibleHeight());
	ASSERT(sizeof(RGBTRIPLE) == 3);
	ASSERT((GetPitch() & 0x3) == 0);

	int width = GetVisibleWidth();
    m_dwpl = GetPitch()/4; // DWORDs Per Line
    m_width = (width+1)*3/4; // round up
    m_delta = int((GetPixelAddress(0,1) - GetPixelAddress(width,0)) / 4);
}

void CMMXSurface24Intrinsic::BlurBits()
{
    int height = GetVisibleHeight();
    DWORD *pCur  = (DWORD*)GetPixelAddress(0,0);

	CMMX cFader;
	CMMX cRight;
	CMMX cLeft;
	CMMX cUp, cDown, cCur;

	cFader.UnpackBytesLo( 0x01010101 );
	cLeft.Clear();

	do {
		int width = m_width;
		do {
			BYTE *bpCur = (BYTE *)pCur;
			// Load pixels and do the mmx unpack
			cCur.UnpackBytesLo( pCur[0] );
			// treating non-aligned data as dwords isn't generally a good idea
			cRight.UnpackBytesLo( *(DWORD *)(bpCur+3) );
			cUp.UnpackBytesLo( pCur[-m_dwpl] );
			cDown.UnpackBytesLo( pCur[m_dwpl] );

			// Sum the 4 around and double the middle
			// Do current pixel in this line
			cUp = (cDown+cUp+cLeft+cRight+(cCur<<2))>>3;

#if defined(TRIPPY)
			cUp += cFader; // increase the fade to white
#elif defined (FAST_FADE)
    	    cUp -= cFader; // increase the fade to black
#endif
			// Reset the left before we write anything out.
			// treating non-aligned data as dwords isn't generally a good idea
			cLeft.UnpackBytesLo( *(DWORD *)(bpCur+1) );
			*pCur++ = cUp.PackBytes();
		} while (--width > 0);
		pCur += m_delta;
	} while (--height > 0);
}
