// FireWnd.cpp : Implementation of CFireWnd
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "FireWnd.h"
#include "propdlg.h"

static RGBQUAD rgbStd256[] =
{
	{   0,  0,  0, 0 }, {   0,  0,128, 0 }, {   0,128,  0, 0 }, {   0,128,128, 0 },
	{ 128,  0,  0, 0 }, { 128,  0,128, 0 }, { 128,128,  0, 0 }, { 192,192,192, 0 },
	{ 192,220,192, 0 }, { 240,202,166, 0 }, { 238,238,238, 0 }, { 221,221,221, 0 },
	{ 204,204,204, 0 }, { 187,187,187, 0 }, { 170,170,170, 0 }, { 153,153,153, 0 },
	{ 136,136,136, 0 }, { 119,119,119, 0 }, { 102,102,102, 0 }, {  85, 85, 85, 0 },
	{  68, 68, 68, 0 }, {  51, 51, 51, 0 }, {  34, 34, 34, 0 }, {  17, 17, 17, 0 },
	{ 204,255,255, 0 }, { 153,255,255, 0 }, { 102,255,255, 0 }, {  51,255,255, 0 },
	{ 255,204,255, 0 }, { 204,204,255, 0 }, { 153,204,255, 0 }, { 102,204,255, 0 },
	{  51,204,255, 0 }, {   0,204,255, 0 }, { 255,153,255, 0 }, { 204,153,255, 0 },
	{ 153,153,255, 0 }, { 102,153,255, 0 }, {  51,153,255, 0 }, {   0,153,255, 0 },
	{ 255,102,255, 0 }, { 204,102,255, 0 }, { 153,102,255, 0 }, { 102,102,255, 0 },
	{  51,102,255, 0 }, {   0,102,255, 0 }, { 255, 51,255, 0 }, { 204, 51,255, 0 },
	{ 153, 51,255, 0 }, { 102, 51,255, 0 }, {  51, 51,255, 0 }, {   0, 51,255, 0 },
	{ 204,  0,255, 0 }, { 153,  0,255, 0 }, { 102,  0,255, 0 }, {  51,  0,255, 0 },
	{ 255,255,204, 0 }, { 204,255,204, 0 }, { 153,255,204, 0 }, { 102,255,204, 0 },
	{  51,255,204, 0 }, {   0,255,204, 0 }, { 255,204,204, 0 }, { 153,204,204, 0 },
	{ 102,204,204, 0 }, {  51,204,204, 0 }, {   0,204,204, 0 }, { 255,153,204, 0 },
	{ 204,153,204, 0 }, { 153,153,204, 0 }, { 102,153,204, 0 }, {  51,153,204, 0 },
	{   0,153,204, 0 }, { 255,102,204, 0 }, { 204,102,204, 0 }, { 153,102,204, 0 },
	{ 102,102,204, 0 }, {  51,102,204, 0 }, {   0,102,204, 0 }, { 255, 51,204, 0 },
	{ 204, 51,204, 0 }, { 153, 51,204, 0 }, { 102, 51,204, 0 }, {  51, 51,204, 0 },
	{   0, 51,204, 0 }, { 255,  0,204, 0 }, { 204,  0,204, 0 }, { 153,  0,204, 0 },
	{ 102,  0,204, 0 }, {  51,  0,204, 0 }, { 255,255,153, 0 }, { 204,255,153, 0 },
	{ 153,255,153, 0 }, { 102,255,153, 0 }, {  51,255,153, 0 }, {   0,255,153, 0 },
	{ 255,204,153, 0 }, { 204,204,153, 0 }, { 153,204,153, 0 }, { 102,204,153, 0 },
	{  51,204,153, 0 }, {   0,204,153, 0 }, { 255,153,153, 0 }, { 204,153,153, 0 },
	{ 102,153,153, 0 }, {  51,153,153, 0 }, {   0,153,153, 0 }, { 255,102,153, 0 },
	{ 204,102,153, 0 }, { 153,102,153, 0 }, { 102,102,153, 0 }, {  51,102,153, 0 },
	{   0,102,153, 0 }, { 255, 51,153, 0 }, { 204, 51,153, 0 }, { 153, 51,153, 0 },
	{ 102, 51,153, 0 }, {  51, 51,153, 0 }, {   0, 51,153, 0 }, { 255,  0,153, 0 },
	{ 204,  0,153, 0 }, { 153,  0,153, 0 }, { 102,  0,153, 0 }, {  51,  0,153, 0 },
	{ 255,255,102, 0 }, { 204,255,102, 0 }, { 153,255,102, 0 }, { 102,255,102, 0 },
	{  51,255,102, 0 }, {   0,255,102, 0 }, { 255,204,102, 0 }, { 204,204,102, 0 },
	{ 153,204,102, 0 }, { 102,204,102, 0 }, {  51,204,102, 0 }, {   0,204,102, 0 },
	{ 255,153,102, 0 }, { 204,153,102, 0 }, { 153,153,102, 0 }, { 102,153,102, 0 },
	{  51,153,102, 0 }, {   0,153,102, 0 }, { 255,102,102, 0 }, { 204,102,102, 0 },
	{ 153,102,102, 0 }, {  51,102,102, 0 }, {   0,102,102, 0 }, { 255, 51,102, 0 },
	{ 204, 51,102, 0 }, { 153, 51,102, 0 }, { 102, 51,102, 0 }, {  51, 51,102, 0 },
	{   0, 51,102, 0 }, { 255,  0,102, 0 }, { 204,  0,102, 0 }, { 153,  0,102, 0 },
	{ 102,  0,102, 0 }, {  51,  0,102, 0 }, { 255,255, 51, 0 }, { 204,255, 51, 0 },
	{ 153,255, 51, 0 }, { 102,255, 51, 0 }, {  51,255, 51, 0 }, {   0,255, 51, 0 },
	{ 255,204, 51, 0 }, { 204,204, 51, 0 }, { 153,204, 51, 0 }, { 102,204, 51, 0 },
	{  51,204, 51, 0 }, {   0,204, 51, 0 }, { 255,153, 51, 0 }, { 204,153, 51, 0 },
	{ 153,153, 51, 0 }, { 102,153, 51, 0 }, {  51,153, 51, 0 }, {   0,153, 51, 0 },
	{ 255,102, 51, 0 }, { 204,102, 51, 0 }, { 153,102, 51, 0 }, { 102,102, 51, 0 },
	{  51,102, 51, 0 }, {   0,102, 51, 0 }, { 255, 51, 51, 0 }, { 204, 51, 51, 0 },
	{ 153, 51, 51, 0 }, { 102, 51, 51, 0 }, {   0, 51, 51, 0 }, { 255,  0, 51, 0 },
	{ 204,  0, 51, 0 }, { 153,  0, 51, 0 }, { 102,  0, 51, 0 }, {  51,  0, 51, 0 },
	{ 204,255,  0, 0 }, { 153,255,  0, 0 }, { 102,255,  0, 0 }, {  51,255,  0, 0 },
	{ 255,204,  0, 0 }, { 204,204,  0, 0 }, { 153,204,  0, 0 }, { 102,204,  0, 0 },
	{  51,204,  0, 0 }, { 255,153,  0, 0 }, { 204,153,  0, 0 }, { 153,153,  0, 0 },
	{ 102,153,  0, 0 }, {   0,  0,238, 0 }, {   0,  0,221, 0 }, {   0,  0,204, 0 },
	{   0,  0,187, 0 }, {   0,  0,170, 0 }, {   0,  0,153, 0 }, {   0,  0,136, 0 },
	{   0,  0,119, 0 }, {   0,  0,102, 0 }, {   0,  0, 85, 0 }, {   0,  0, 68, 0 },
	{   0,  0, 51, 0 }, {   0,  0, 34, 0 }, {   0,  0, 17, 0 }, {   0,238,  0, 0 },
	{   0,221,  0, 0 }, {   0,204,  0, 0 }, {   0,187,  0, 0 }, {   0,170,  0, 0 },
	{   0,153,  0, 0 }, {   0,136,  0, 0 }, {   0,119,  0, 0 }, {   0,102,  0, 0 },
	{   0, 85,  0, 0 }, {   0, 68,  0, 0 }, {   0, 51,  0, 0 }, {   0, 34,  0, 0 },
	{   0, 17,  0, 0 }, { 238,  0,  0, 0 }, { 221,  0,  0, 0 }, { 204,  0,  0, 0 },
	{ 187,  0,  0, 0 }, { 170,  0,  0, 0 }, { 153,  0,  0, 0 }, { 136,  0,  0, 0 },
	{ 119,  0,  0, 0 }, { 102,  0,  0, 0 }, {  85,  0,  0, 0 }, {  68,  0,  0, 0 },
	{  51,  0,  0, 0 }, {  34,  0,  0, 0 }, { 240,251,255, 0 }, { 164,160,160, 0 },
	{ 128,128,128, 0 }, {   0,  0,255, 0 }, {   0,255,  0, 0 }, {   0,255,255, 0 },
	{ 255,  0,  0, 0 }, { 255,  0,255, 0 }, { 255,255,  0, 0 }, { 255,255,255, 0 }
};



/////////////////////////////////////////////////////////////////////////////
// CFireWnd

// Initialize the seed for random number generation.  For a more random
// flame this could be initialized by a call to ::rand().  Declaring it
// this way causes the same flame to be drawn each time the application
// is executed.
unsigned long CFireWnd::m_RandSeed = 0x38549391;

CFireWnd::CFireWnd(): m_curColor(0),rcSize(0,0), m_pBits(0)
{
	m_nDecay = 4;
	m_nFlammability = 385;
	m_nMaxHeat = 223;
	m_nSpreadRate = 20;
	m_nSmoothness = 1;
	m_nDistribution = 1;
	m_nChaos = 50;

	m_nSize = 0;
	m_MaxBurn = 0;
	m_Fire = NULL;

	m_hMemDC = NULL;
	m_hWinDC = NULL;
	m_hBitmap = NULL;
	m_hPalette = NULL;
	m_pOldPalette = NULL;
	m_pOldBitmap = NULL;
	CreatePopup();
}

CFireWnd::~CFireWnd()
{
	if (m_hRightMenu != NULL)
		DestroyMenu(m_hRightMenu);
	m_hWnd = 0;
}

LRESULT CFireWnd::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	m_uTimerID = (UINT)(SetTimer(0x451,33));
	InitFire();
	return 1;  // Let the system set the focus
}


LRESULT CFireWnd::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	ATLTRACE(_T("CFireWnd::OnPaint\n"));
	PAINTSTRUCT ps;
	HDC dc = BeginPaint(&ps);

		// A different color brush can be used to fill the rect
		// to test the drawing of the bitmap, but basically this
		// code is not needed. It also helps reduce flicker a bit
		// on slower machines though.
		HBRUSH blackBrush, oldBrush = NULL;
		blackBrush = CreateSolidBrush(RGB(0,0,0));
		oldBrush = (HBRUSH)::SelectObject(dc,&blackBrush);
		RECT rc;
		GetClientRect(&rc);
		::FillRect(dc,const_cast<const RECT*>(&rc),blackBrush);
		if(oldBrush)
			::SelectObject(dc,&oldBrush);

		// Do the real flame bitmap drawing
		PaintFlame(dc);

	EndPaint(&ps);
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CFireWnd Operations

void CFireWnd::InitFire()
{
	ATLTRACE(_T("CFireWnd::InitFire()\n"));
	CreatePalette(m_curColor + 1);

	CreateBitmap();

	{
		HWND hActiveWnd = GetActiveWindow();
		if (hActiveWnd != NULL)
			::SendMessage(hActiveWnd, WM_QUERYNEWPALETTE, 0, 0);
	}
}

HPALETTE* CFireWnd::GetPalette()
{
	ATLTRACE(_T("CFireWnd::GetPalette()\n"));
	if (m_hPalette != NULL)
		return &m_hPalette;
	else
		return NULL;
}

void CFireWnd::CreatePalette(int nColor)
{
	ATLTRACE(_T("CFireWnd::CreatePalette()\n"));
	UINT i;

	if (m_hPalette != NULL)
	{
		DeleteObject(m_hPalette);
		m_hPalette = NULL;
	}

	memcpy_s( m_rgbPalette, sizeof(RGBQUAD) * 256, rgbStd256, sizeof(RGBQUAD) * 256 );

	int r,g,b;

	switch(nColor)
	{
	case blue:
		b = 256+256+255;
		g = 256+255;
		r = 255;
		break;
	case green:
		g = 256+256+255;
		r = 256+255;
		b = 255;
		break;
	case red:
	default:
		r = 256+256+255;
		g = 256+255;
		b = 255;
		break;
	}

	for(i = 239; i > 15; i--)
	{
		m_rgbPalette[i].rgbRed = static_cast<BYTE>((r > 255) ? 255 : r);
		m_rgbPalette[i].rgbGreen = static_cast<BYTE>((g > 255) ? 255 : g);
		m_rgbPalette[i].rgbBlue = static_cast<BYTE>((b > 255) ? 255 : b);
		r = (r > 3) ? (r - 4) : 0;
		g = (g > 3) ? (g - 4) : 0;
		b = (b > 3) ? (b - 4) : 0;
	}

	LPLOGPALETTE lpLogPal;
	lpLogPal = (LPLOGPALETTE) new BYTE[sizeof(LOGPALETTE) + ((255) * sizeof(PALETTEENTRY))];
	lpLogPal->palVersion = 0x0300;
	lpLogPal->palNumEntries = 256;

	for (i = 0; i < 256; i++)
	{
		lpLogPal->palPalEntry[i].peRed = m_rgbPalette[i].rgbRed;
		lpLogPal->palPalEntry[i].peGreen = m_rgbPalette[i].rgbGreen;
		lpLogPal->palPalEntry[i].peBlue = m_rgbPalette[i].rgbBlue;
		lpLogPal->palPalEntry[i].peFlags = 0;
	}

	m_hPalette = ::CreatePalette( lpLogPal );
	_ASSERTE(m_hPalette);

	delete [] (BYTE *)lpLogPal;
}


#define WIDTHBYTES(bits) ((((bits) + 31) / 32) * 4)

void CFireWnd::CreateBitmap()
{
	if(rcSize.cx <= 0 || rcSize.cy <= 0)
	{
		// no place to do a bitmap, then get out
		return;
	}

	ATLTRACE(_T("CFireWnd::CreateBitmap()\n"));
	if (m_hMemDC != NULL)
	{
		::SelectObject(m_hMemDC, m_hBitmap);
		DeleteDC(m_hMemDC);
		m_hMemDC = NULL;
		m_pOldBitmap = NULL;
	}

	if (m_hWinDC != NULL)
	{
		::SelectObject(m_hWinDC,m_hPalette);
		DeleteDC(m_hWinDC);
		m_hWinDC = NULL;
		m_pOldPalette = NULL;
	}

	if (m_hBitmap != NULL)
		DeleteObject(m_hBitmap);

	if (m_Fire != NULL)
	{
		delete m_Fire;
		m_Fire = NULL;
	}

	// rcSize is the cached size of the window that was
	// set during the call to IOleInPlaceObject_SetObjectRects
	_ASSERTE(rcSize.cx != 0);
	_ASSERTE(rcSize.cy != 0);


	// Just make the maximum height be the size of the rect
	m_MaxBurn = (int)(rcSize.cy);

	m_nSize = (int)(rcSize.cx  * 0.66 );

	m_Fire = new BYTE[rcSize.cx];
	m_nFireSize = rcSize.cx;

	LPBITMAPINFO lpbi;

	// Fill in the BITMAPINFOHEADER
	lpbi = (LPBITMAPINFO) new BYTE[sizeof(BITMAPINFOHEADER) + (256 * sizeof(RGBQUAD))];
	lpbi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	lpbi->bmiHeader.biWidth = rcSize.cx;
	lpbi->bmiHeader.biHeight = rcSize.cy;
	lpbi->bmiHeader.biPlanes = 1;
	lpbi->bmiHeader.biBitCount = 8;
	lpbi->bmiHeader.biCompression = BI_RGB;
	lpbi->bmiHeader.biSizeImage = WIDTHBYTES((DWORD)rcSize.cx * 8) * rcSize.cy;
	lpbi->bmiHeader.biXPelsPerMeter = 0;
	lpbi->bmiHeader.biYPelsPerMeter = 0;
	lpbi->bmiHeader.biClrUsed = 0;
	lpbi->bmiHeader.biClrImportant = 0;

	// Fill in the color table
	UINT uUsage = DIB_RGB_COLORS;
	memcpy( lpbi->bmiColors, m_rgbPalette, sizeof(RGBQUAD) * 256 );

	m_hWinDC = GetDC();
	_ASSERTE(m_hWinDC);

	HBITMAP hBitmap = CreateDIBSection( m_hWinDC, lpbi, uUsage, (void **)&m_pBits, NULL, 0 );
	_ASSERTE(hBitmap);

	delete [] (BYTE *)lpbi;

	m_hBitmap = hBitmap;

	m_hMemDC = CreateCompatibleDC(m_hWinDC);
	_ASSERTE(m_hMemDC);

	m_pOldPalette = (HPALETTE)::SelectPalette( m_hWinDC, m_hPalette, FALSE );
	RealizePalette(m_hWinDC);
	m_pOldBitmap = (HBITMAP)::SelectObject(m_hMemDC, m_hBitmap );

	for (int x = 0; x < rcSize.cx; x++ )
		m_Fire[x] = 16;

	// cache the bitmap size for later use so we don't
	// have to call GetBitmapSize() for every timer message
	bmSize.cx = rcSize.cx;
	bmSize.cy = rcSize.cy;
}


//
//  This routine was adapted from a pascal routine written by
//  Frank Jan Sorensen Alias:Frank Patxi (fjs@lab.jt.dk)
//
//  See AboutBox for a special thank you for all his work.
//
// NOTE: There is a bug in the boundary conditions for the size
//       of the bitmap. For example an object with a size of
//       width 487 to 500 and a height of 300 doesn't work
//       I have a hunch that the WIDTHBYTES macro doesn't account
//       for all possible values for the upper bound.
//       This bug doesn't show up in the MFC Fire sample because
//       the size is hard wired to something that works. Since
//       it has nothing to do with ATL controls, I just left the
//       algorithm as is. MK

void CFireWnd::RenderFlame()
{
	int xStart, xEnd, x, y;
	BYTE* pRow = NULL;
	BYTE* pNextRow = NULL;

	if(bmSize.cx <= 0 || bmSize.cy <= 0 || m_pBits == NULL)
	{
		// if we don't have any dimensions or bits for
		//  our bitmap then we aren't ready to paint
		return;
	}

	// width of the bitmap
	m_nSize = bmSize.cx - 1;
	if (m_nSize < 0)
		m_nSize = 0;

	// height of the bitmap
	m_MaxBurn = rcSize.cy - 1;
	if (m_MaxBurn < 0)
		m_MaxBurn = 0;

	xStart = (bmSize.cx - m_nSize) / 2;
	xEnd = xStart + m_nSize + 1;

	{
		pRow = m_pBits;
		for (x=0;x<bmSize.cx && x < m_nFireSize;x++)
		{
			if (x < (xStart + m_nDistribution) || x >= (xEnd - m_nDistribution))
				m_Fire[x] = 16;
			*pRow++ = m_Fire[x];
		}
	}


	for (y = m_MaxBurn; y > 0; y--)
	{
		pRow = (m_pBits + WIDTHBYTES((DWORD)bmSize.cx * 8) * y);
		pNextRow = (m_pBits + WIDTHBYTES((DWORD)bmSize.cx * 8) * (y - 1));

		if ((rand() % 2) == 0)
		{
			for (x = 0; x < bmSize.cx; x++)
			{
				BurnPoint(pRow, pNextRow);
				pRow++;
				pNextRow++;
			}
		}
		else
		{
			pRow += bmSize.cx - 1;
			pNextRow += bmSize.cx - 1;
			for (x = 0; x < bmSize.cx; x++)
			{
				BurnPoint(pRow, pNextRow);
				pRow--;
				pNextRow--;
			}
		}
	}

	int MaxHeat = m_nMaxHeat + 16;

	if ( rand() % (400 - m_nFlammability) == 0)
	{
		int off = m_nSize - 5;
		off = rand() % off;
		off += xStart;

		for (x = off; x < off + 5 && x < m_nFireSize; x++)
			m_Fire[x] = 239;
	}

	for (x = xStart; x < xEnd && x < m_nFireSize; x++)
	{
		if (m_Fire[x] < MaxHeat)
		{
			int val = rand() % m_nChaos+1;
			val -= m_nChaos / 2;
			val += m_nSpreadRate;
			val += m_Fire[x];

			if ( val > MaxHeat)
				m_Fire[x] = static_cast<BYTE>(MaxHeat);
			else if ( val < 16)
				m_Fire[x] = 16;
			else
				m_Fire[x] = static_cast<BYTE>(val);
		}
		else
			m_Fire[x] = static_cast<BYTE>(MaxHeat);
	}

	if (m_nSmoothness > 0)
	{
		xStart += m_nSmoothness;
		xEnd -= m_nSmoothness;
		for (x = xStart; x < xEnd && x < m_nFireSize; x++)
		{
			int val = 0;
			for (y = x - m_nSmoothness; y < x + 1 + m_nSmoothness && y < m_nFireSize; y++)
				val += m_Fire[y];

			m_Fire[x] = static_cast<BYTE>(val / (2*m_nSmoothness+1));
		}
	}
}

void CFireWnd::PaintFlame(HDC hDC)
{
	if (m_hPalette != NULL  && m_hBitmap != NULL)
	{
		if (hDC != NULL)
		{
			HPALETTE pOldPalette;
			pOldPalette = ::SelectPalette(hDC, m_hPalette, FALSE );
			RealizePalette(hDC);
			_ASSERTE(m_hMemDC);
			HBITMAP pOldBitmap = (HBITMAP)::SelectObject(m_hMemDC, m_hBitmap);
			BitBlt(hDC, 0, 0, bmSize.cx, bmSize.cy, m_hMemDC, 0, 0, SRCCOPY );
			::SelectObject(m_hMemDC, pOldBitmap);
			SelectPalette( hDC, pOldPalette, TRUE );
		}
		else
		{
			::BitBlt(m_hWinDC, 0, 0, bmSize.cx, bmSize.cy, m_hMemDC, 0, 0, SRCCOPY );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFireWnd message handlers

LRESULT CFireWnd::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{

	if (m_hMemDC != NULL)
	{
		::SelectObject(m_hMemDC, m_hBitmap);
		DeleteDC(m_hMemDC);
		m_hMemDC = NULL;
		m_pOldBitmap = NULL;
	}

	if (m_hWinDC != NULL)
	{
		::SelectObject(m_hWinDC,m_hPalette);
		DeleteDC(m_hWinDC);
		m_hWinDC = NULL;
		m_pOldPalette = NULL;
	}

	if (m_hBitmap != NULL)
		DeleteObject(m_hBitmap);

	if (m_hPalette != NULL)
		DeleteObject(m_hBitmap);

	if (m_Fire != NULL)
	{
		delete m_Fire;
		m_Fire = NULL;
		m_nFireSize = 0;
	}

	KillTimer(m_uTimerID);

	return 0;
}

LRESULT CFireWnd::OnPaletteChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ATLTRACE(_T("CFireWnd::OnPaletteChanged()\n"));
	HWND pFocusWnd = GetFocus();
	if (pFocusWnd == m_hWnd || IsChild(pFocusWnd))
		return 0;
	return OnQueryNewPalette(uMsg, wParam, lParam, bHandled);
}

LRESULT CFireWnd::OnQueryNewPalette(UINT uMsg, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{

	ATLTRACE(_T("CFireWnd::OnQueryNewPalette()\n"));
	if (GetPalette() == NULL)
		return FALSE;

	{
		HDC dc = GetDC();
		SelectPalette(dc, m_hPalette, uMsg == WM_PALETTECHANGED);
		UINT nChanged = RealizePalette(dc);
		if (nChanged == 0)  // no change to our mapping
			return FALSE;
		ReleaseDC(dc);
	}

	// some changes have been made; invalidate
	Invalidate(FALSE);
	return 0;
}

LRESULT CFireWnd::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	ATLTRACE(_T("CFireWnd::OnSize()\n"));
	rcSize.cx = LOWORD(lParam);
	rcSize.cy = HIWORD(lParam);
		
	bmSize.cx = rcSize.cx - 5;
	if (bmSize.cx < 0)
		bmSize.cx= 0;
	bmSize.cy = rcSize.cy - 30;
	if (bmSize.cy < 0)
		bmSize.cx = 0;
	InitFire();		

	return 0;
}

LRESULT CFireWnd::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	RenderFlame();
	PaintFlame();
	// Eat spurious WM_TIMER messages
	MSG msg;
	while(::PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE));
	return 0;
}


LRESULT CFireWnd::OnProperties(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtlr*/, BOOL& /*bHandled*/)
{
	CPropDlg dlg(this);
	dlg.DoModal(m_hWnd);
	return 0;
}

LRESULT CFireWnd::OnRButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	ATLTRACE(_T("CFireWnd::OnRButtonDown()\n"));
	POINT ptClick;
	ptClick.x = LOWORD(lParam);
	ptClick.y = HIWORD(lParam);
	::ClientToScreen(m_hWnd, &ptClick);
	TrackPopupMenuEx(m_hRightMenu, TPM_VERTICAL, ptClick.x, ptClick.y, m_hWnd, NULL);
	return 0;
}

void CFireWnd::CreatePopup()
{
	m_hRightMenu = NULL;
	m_hPropMenu = LoadMenu(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
	if (m_hPropMenu == NULL)
	{
		ATLTRACE(_T("Failed to load right click menu\n"));
		_ASSERTE(FALSE);
		return;
	}

	m_hRightMenu = GetSubMenu(m_hPropMenu, 0);
	if (m_hRightMenu == NULL)
	{
		ATLTRACE(_T("Failed to load Popup menu\n"));
		_ASSERTE(FALSE);
		return;
	}
}
