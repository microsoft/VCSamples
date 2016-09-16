// Surface.cpp : implementation of the CSurface class
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
#include "Surface.h"

void CSurface::Create(CWnd *pWnd, int nBitDepth)
{
	// no palettes
	ASSERT(nBitDepth == 24 || nBitDepth == 16 || nBitDepth == 32);

    CRect clientRect;
    pWnd->GetClientRect(clientRect);
	int height = clientRect.Height();
    int width = clientRect.Width();

	if (!height || !width)
		return;

    Destroy();

	m_nBitDepth = nBitDepth;
	m_nByteDepth = nBitDepth/8;
	m_wndHeight = height;
    m_wndWidth = width;
	m_hDestDC = ::GetDC(pWnd->GetSafeHwnd());
	m_pSrcWnd = pWnd;
    ASSERT(m_hDestDC);

	width = m_wndWidth + m_kDeltaX; // not *2 because we don't need it on the left side.
	// Allow derived classes a shot at updating if they need more alignment
	AdjustWidth(&width);

	// pass Negative Height to make it Top Down.
	VERIFY(m_image.Create(width, -(m_wndHeight + m_kDeltaY*2), m_nBitDepth, 0));
	ASSERT((DWORD_PTR(m_image.GetBits()) & 0xf) == 0); // make sure we are at least 128 bit aligned.(SSE2)
	ASSERT(m_image.GetPitch() > 0); // Verify top down DIB
	VERIFY(m_image.GetDC() != NULL); // Prefer the DC to exist for life of object
	OnCreated();
}

void CSurface::Destroy()
{ 
	if (IsNull())
		return;

	m_image.ReleaseDC();
	m_image.Destroy(); 
	::ReleaseDC(m_pSrcWnd->GetSafeHwnd(), m_hDestDC);
	m_wndHeight = 0;
	m_wndWidth = 0;
}

void CSurface::Import(const CImage &image)
{
	image.BitBlt(m_image.GetDC(), 0, m_kDeltaY, 
		GetVisibleWidth(), GetVisibleHeight(), 0, 0);
	m_image.ReleaseDC();
	BlitBits();
}

void CSurface::ClearBits()
{
    int size = m_image.GetPitch() * m_image.GetHeight();
	memset(m_image.GetBits(), 0x00, size);
}

void CSurface::StripeBits()
{
    int count = 0x880000;
    for (int i = 0; i < m_wndHeight; i++) {
        COLORREF color = count++; // RAND();
        for (int j = 0; j < m_wndWidth; j++) {
            PointColor(j, i, color);
        }
    }

}

void CSurface::RandomBits()
{
    for (int i = 0; i < m_wndHeight; i++) {
        for (int j = 0; j < m_wndWidth; j++) {
            PointColor(j, i, RGB(Random(), Random(), Random()));
        }
    }
}

void CSurface::ShiftBits()
{
	BYTE *pBits = (BYTE*)m_image.GetBits();
	int nPitch = GetPitch();
	for (int i = 0; i < m_wndHeight; i++) {
		memcpy_s(pBits, nPitch, pBits+nPitch, nPitch);
		pBits += nPitch;
	}
}

void CSurface::BlurBits()
{
    COLORREF cLeft = 0, cCur = PointColor(0,0), cRight, cUp, cDown;
    BYTE r, g, b;
    for (int i = 0; i < m_wndHeight; i++) {
		cLeft = 0;
        for (int j = 0; j < m_wndWidth; j++) {
            cRight = PointColor(j+1, i);
            cUp = PointColor(j, i-1);
            cDown = PointColor(j, i+1);
            r = (BYTE)(((int)(GetRValue(cCur) << 2) + GetRValue(cLeft) + GetRValue(cRight) + GetRValue(cUp) + GetRValue(cDown)) >> 3);
            g = (BYTE)(((int)(GetGValue(cCur) << 2) + GetGValue(cLeft) + GetGValue(cRight) + GetGValue(cUp) + GetGValue(cDown)) >> 3);
            b = (BYTE)(((int)(GetBValue(cCur) << 2) + GetBValue(cLeft) + GetBValue(cRight) + GetBValue(cUp) + GetBValue(cDown)) >> 3);
            PointColor(j, i, RGB(b,g,r)); // RGBs are physically inverted
            cLeft = cCur;
            cCur = cRight;
        }
    }
}

// nothing beats good old fashioned Bresenham
void CSurface::Line(const CPoint &p1, const CPoint &p2, COLORREF c)
{
    int x1 = p1.x;
    int x2 = p2.x;
    int y1 = p1.y;
    int y2 = p2.y;

	int d, deltax, deltay, numpixels,
    dinc1, dinc2,
    xinc1, xinc2,
    yinc1, yinc2;

	// Calculate deltax and deltay for startup
	deltax = ABS(x2 - x1);
	deltay = ABS(y2 - y1);

	// Initialize all vars based on which is the independent variable
    if (deltax >= deltay) {
		// x is independent variable
		numpixels = deltax + 1;
		dinc1 = deltay << 1;
		dinc2 = (deltay - deltax) << 1;
		d = dinc1 - deltax;
		xinc1 = xinc2 = yinc2 = 1;
		yinc1 = 0;
    }
    else {
		// y is independent variable
		numpixels = deltay + 1;
		dinc1 = deltax <<  1;
		dinc2 = (deltax - deltay) << 1;
		d = dinc1 - deltay;
		xinc1 = 0;
		xinc2 = yinc1 = yinc2 = 1;
    }

	// Make sure x and y move in the right directions
    if (x1 > x2) {
		xinc1 = -xinc1;
		xinc2 = -xinc2;
    }
    if (y1 > y2) {
		yinc1 = -yinc1;
		yinc2 = -yinc2;
    }

	// Start drawing pixels at [x1, y1]
    for (int i = numpixels; i > 0; i--) {
        PointColor(x1, y1, c);
        if (d < 0) {
			d += dinc1;
			x1 += xinc1;
			y1 += yinc1;
        }
        else {
			d += dinc2;
			x1 += xinc2;
			y1 += yinc2;
        }
    }
}

void CSurface::RandomLine(COLORREF c)
{
    CPoint p1(Random(m_wndWidth), Random(m_wndHeight));
    CPoint p2(Random(m_wndWidth), Random(m_wndHeight));
    Line(p1, p2, c);
}

void CSurface::BlitBits()
{
	ASSERT(m_wndHeight && m_wndWidth);
    BOOL bStat = m_image.BitBlt(m_hDestDC, 0, 0, 
        m_wndWidth, m_wndHeight, 0, m_kDeltaY);

    ASSERT(bStat);
}
