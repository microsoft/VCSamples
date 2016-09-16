// CDInfo1.cpp : Implementation of CCDInfo
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
#include <math.h>

#include "CDInfo_h.h"
#include "CDInfo1.h"

/////////////////////////////////////////////////////////////////////////////
// CCDInfo

COLORREF CCDInfo::m_colSegment[] =
{
	RGB(0x00,0x00,0x00),
	RGB(0xff,0x00,0x00),
	RGB(0x00,0xff,0x00),
	RGB(0x00,0x00,0xff),
	RGB(0xff,0xff,0x00),
	RGB(0x00,0xff,0xff),
	RGB(0xff,0x00,0xff),
	RGB(0xff,0xff,0xff),
	RGB(0x7f,0x7f,0x7f),
	RGB(0x7f,0x00,0x00),
	RGB(0x00,0x7f,0x00),
	RGB(0x00,0x00,0x7f),
	RGB(0x7f,0x7f,0x00),
	RGB(0x00,0x7f,0x7f),
	RGB(0x7f,0x00,0x7f),
	RGB(0x7f,0x7f,0x7f)
};

HRESULT CCDInfo::OnDraw(ATL_DRAWINFO& di)
{
	if (di.dwDrawAspect == DVASPECT_CONTENT)
	{
		ATLTRACE(_T("Ondraw\n"));
		DrawOffScreen(di.hdcDraw, *(RECT*)di.prcBounds);
	}
	return 0;
}

void CCDInfo::DrawOffScreen(HDC hdc, RECT rc)
{
	HBITMAP hbmMem, hbmOld;
	HDC     hdcMem;
	RECT    rcDP;

	// First make sure we have the coordinates in device units and we
	// are offset from 0,0

	LPtoDP(hdc, (LPPOINT)&rc, 2);
	rcDP = rc;
	OffsetRect(&rc, -rc.left, -rc.top);

	// Create a DC to draw into
	hdcMem = CreateCompatibleDC(hdc);

	// Create a bitmap big enough for our drawing
	hbmMem = CreateCompatibleBitmap(hdc, rc.right-rc.left, rc.bottom-rc.top);

	// Select the bitmap into our new DC
	hbmOld = (HBITMAP)SelectObject(hdcMem, hbmMem);

	// If we can get the ambient background color from the container then we
	// will use it.

	CComVariant var;
	if (SUCCEEDED(m_spAmbientDispatch.GetProperty(DISPID_AMBIENT_BACKCOLOR,
			&var)))
	{
		LOGBRUSH    logbrush;
		COLORREF    col;
		logbrush.lbStyle = BS_SOLID;
		OleTranslateColor(var.lVal, m_hPalette, &col);
		logbrush.lbColor = col;
		HBRUSH hBrush = CreateBrushIndirect(&logbrush);
		FillRect(hdcMem, &rc, hBrush);
		DeleteObject(hBrush);
	}

	RECT rcEllipse = rc;
	ReduceRect(&rcEllipse);
	DrawCD(hdcMem, rcEllipse);

	// Now we can blt our offscreen bitmap onto the passed DC.
	BitBlt(hdc,
		   rcDP.left, rcDP.top,
		   rcDP.right-rcDP.left, rcDP.bottom-rcDP.top,
		   hdcMem,
		   0, 0,
		   SRCCOPY);

	// Clean up our stuff
	SelectObject(hdcMem, hbmOld);
	DeleteObject(hbmMem);
	DeleteDC(hdcMem);
}

void CCDInfo::DrawCD(HDC hdc, RECT rc)
{
	double  dblAngle = m_dblCurrentAngle;
	double  dblRadius = (rc.right - rc.left) / 2;
	short   nTracks, nTrack, nTotalLength;
	POINT   pt1, pt2, ptCenter, ptStart;
	HBRUSH      hBrush, hOldBrush;
	HPEN        hOldPen;
	LOGBRUSH    logbrush;
	COLORREF    col;

	ptCenter.x = (rc.right + rc.left) / 2;
	ptCenter.y = (rc.bottom + rc.top) / 2;

	nTracks = m_cd.GetNumberOfTracks();
	nTotalLength = m_cd.GetTotalLength();

	hOldPen = (HPEN)SelectObject(hdc, GetStockObject(BLACK_PEN));

	logbrush.lbStyle = BS_SOLID;
	ptStart = pt1 = CalcPoint(ptCenter, dblRadius, dblAngle);
	for (nTrack=1; nTrack<=nTracks; nTrack++)
	{
		col = m_colSegment[nTrack % (sizeof(m_colSegment)/sizeof(COLORREF))];
		logbrush.lbColor = col;
		hBrush = CreateBrushIndirect(&logbrush);
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

		if (nTracks==1)
		{
			// As we only have 1 track ensure it is painted correctly
			Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
			MoveToEx(hdc, ptCenter.x, ptCenter.y, NULL);
			LineTo(hdc, pt1.x, pt1.y);
		}
		dblAngle += m_cd.GetTrackLength(nTrack) / (double)nTotalLength * 2 * PI;
		if (nTrack==nTracks)
			pt2 = ptStart; // Ensure we finish where we started
		else
			pt2 = CalcPoint(ptCenter, dblRadius, dblAngle);

		// Only draw the wedge if it is big enough to see
		if (pt1.x != pt2.x || pt1.y != pt2.y)
		{
			Pie(hdc, rc.left, rc.top, rc.right, rc.bottom, pt2.x, pt2.y, pt1.x, pt1.y);
			pt1 = pt2;
		}

		SelectObject(hdc, hOldBrush);
		DeleteObject(hBrush);
	}
	SelectObject(hdc, hOldPen);
}

POINT CCDInfo::CalcPoint(POINT ptCenter, double dwRadius, double dblAngle)
{
	POINT ptReturn;

	ptReturn.x = (long)(ptCenter.x + dwRadius * cos(dblAngle) + 0.5);
	ptReturn.y = (long)(ptCenter.y + dwRadius * sin(dblAngle) + 0.5);
	return ptReturn;
}

double CCDInfo::CalcAngle(POINT ptCenter, POINT point)
{
	double dblAngle;
	dblAngle = atan2((double)(point.y-ptCenter.y), (double)(point.x-ptCenter.x));
	if (dblAngle < PI/2)
		dblAngle += 2 * PI;
	if (dblAngle > 3*PI/2)
		dblAngle -= 2 * PI;
	return dblAngle;
}

LRESULT CCDInfo::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	POINT   pt;
	short   nTrack;

	pt.x = LOWORD(lParam);  // horizontal position of cursor
	pt.y = HIWORD(lParam);  // vertical position of cursor

	nTrack = GetTrackFromPoint(pt);
	if (nTrack)
		Click(nTrack);

	RelayEvent(uMsg, wParam, lParam, bHandled);
	return 0;
}

LRESULT CCDInfo::OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	if (m_wndToolTip.m_hWnd)
	{
		POINT pt;
		static int uId;
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		m_nMouseTrack = GetTrackFromPoint(pt);

		if (m_nMouseTrack)
		{
			TOOLINFO ti;
			ti.cbSize = sizeof(TOOLINFO);
			ti.hwnd   = m_hTheWnd;
			uId = (uId==2) ? 1 : 2;
			ti.uId    = uId;
			ti.rect.left   = pt.x;
			ti.rect.right  = pt.x+1;
			ti.rect.top    = pt.y;
			ti.rect.bottom = pt.y+1;
			m_wndToolTip.SendMessage(TTM_NEWTOOLRECT,   0, (LPARAM)&ti);

			if (m_nMouseTrack)
			{
				short nLength = m_cd.GetTrackLength(m_nMouseTrack);
				short nSeconds = (short)(nLength % 60);
				TCHAR szTip[10];
				TCHAR szSeconds[3];
				_stprintf_s(szTip, 10, _T("%hd:"), nLength / 60);
				if (nSeconds < 10)
					_tcscat_s(szTip, 10, _T("0"));
				_stprintf_s(szSeconds, 3, _T("%hd"), nSeconds);
				_tcscat_s(szTip, 10, szSeconds);
				ti.lpszText = szTip;
				m_wndToolTip.SendMessage(TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
			}
		}
		RelayEvent(uMsg, wParam, lParam, bHandled);
	}
	return 0;
}

short CCDInfo::GetTrackFromPoint(const POINT& pt)
{
	POINT   ptCenter;
	short   nTracks, nTrack, nTotalLength;
	double  dblAngle, dblNewAngle, dblCursorAngle;
	nTracks = m_cd.GetNumberOfTracks();
	nTotalLength = m_cd.GetTotalLength();

	if (!InEllipse(m_rcEllipse, pt) || nTracks==0)
		return 0;

	ptCenter.x = (m_rcEllipse.right + m_rcEllipse.left) / 2;
	ptCenter.y = (m_rcEllipse.bottom + m_rcEllipse.top) / 2;

	dblAngle = m_dblCurrentAngle;
	dblCursorAngle = CalcAngle(ptCenter, pt);

	// Ensure the angle will be in the range that we are checking for
	if (dblCursorAngle < dblAngle)
		dblCursorAngle += 2 * PI;

	for (nTrack=1; nTrack<=nTracks; nTrack++)
	{
		dblNewAngle = dblAngle + m_cd.GetTrackLength(nTrack) / (double)nTotalLength * 2 * PI;
		if (dblAngle < dblCursorAngle && dblCursorAngle < dblNewAngle)
			break;
		dblAngle = dblNewAngle;
	}
	return nTrack;
}

BOOL CCDInfo::InEllipse(RECT& rect, POINT point)
{
	// Determine radii
	double a = (rect.right - rect.left) / 2;
	double b = (rect.bottom - rect.top) / 2;

	// Determine x, y
	double x = point.x - (rect.left + rect.right) / 2;
	double y = point.y - (rect.top + rect.bottom) / 2;

	// Apply ellipse formula
	return ((x * x) / (a * a) + (y * y) / (b * b) <= 1);
}

double CCDInfo::GetTrackAngle(short nWantedTrack)
{
	short nTrack, nLength;
	double dblMiddlePos;

	nLength = 0;
	for (nTrack=1; nTrack<nWantedTrack; nTrack++)
		nLength = (short)(nLength + m_cd.GetTrackLength(nTrack));

	dblMiddlePos = nLength + m_cd.GetTrackLength(nTrack) / 2.0;

	return dblMiddlePos / (double)m_cd.GetTotalLength() * 2 * PI;
}

#define STEP 0.02

void CCDInfo::DrawToTrack(short nTrack)
{
	HDC     hDC;
	HRESULT hr;
	double  dblNewAngle;
	double  dblStep;

	if (m_bWndLess)
	{
		// We're windowless so we need the DC from the client
		hr = m_spInPlaceSite->GetDC(NULL, OLEDC_NODRAW, &hDC);
		ATLASSERT(SUCCEEDED(hr));
		// We need to reset the origin if we are drawing in client coordinates
		// ::SetWindowOrgEx(hDC, -m_rcPos.left, -m_rcPos.top, &ptOld);
	}
	else
		hDC = ::GetDC(m_hWnd);

	dblNewAngle = 3 * PI / 2 - GetTrackAngle(nTrack);
	if (dblNewAngle > m_dblCurrentAngle)
		dblStep = +STEP;    // Anti-clockwise
	else
		dblStep = -STEP;    // Clockwise

	while ( fabs(m_dblCurrentAngle - dblNewAngle) > STEP)
	{
		Sleep(5);
		m_dblCurrentAngle += dblStep;
		DrawCD(hDC, m_rcEllipse);
	}

	m_dblCurrentAngle = dblNewAngle;
	DrawCD(hDC, m_rcEllipse);

	if (m_bWndLess)
		hr = m_spInPlaceSite->ReleaseDC(hDC);
	else
		::ReleaseDC(m_hWnd, hDC);
}

void CCDInfo::CreateTooltipWindow()
{
	InitCommonControls();
	m_wndToolTip.m_hWnd =
		::CreateWindow(TOOLTIPS_CLASS, (LPTSTR)NULL, TTS_ALWAYSTIP,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			NULL, (HMENU) NULL, _AtlBaseModule.GetModuleInstance(), NULL);

	// Ensure the tooltip always appears above our window
	m_wndToolTip.SetWindowPos(HWND_TOPMOST,0,0,0,0,
		SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOREDRAW|SWP_NOSIZE);

	TOOLINFO    ti;
	ti.cbSize = sizeof(TOOLINFO);
	ti.uFlags = 0;
	ti.hwnd   = m_hTheWnd;
	ti.uId    = 1;
	ti.hinst  = NULL;
	ti.lpszText = _T("");
	ti.rect.left   = 0;
	ti.rect.right  = 0;
	ti.rect.top    = 0;
	ti.rect.bottom = 0;
	m_wndToolTip.SendMessage(TTM_ADDTOOL, 0, (LPARAM)&ti);

	ti.uId = 2;
	m_wndToolTip.SendMessage(TTM_ADDTOOL, 0, (LPARAM)&ti);
}

// Get the window we need to use. This will either be the window that
// has already been created if we are window or if we are windowless
// the HWND of the client will be retrieved from the HDC.

void CCDInfo::GetTheWindow()
{
	// If we're windowless we still need an HWND for Direct3d
	if (m_bWndLess)
	{
		HDC hDC;

		// Get the HDC from the client
		m_spInPlaceSite->GetDC(NULL, OLEDC_NODRAW, &hDC);
		m_hTheWnd = WindowFromDC(hDC);

		
		RECT rect;
		::GetClientRect(m_hTheWnd,&rect);
		HRGN hRegion = CreateRectRgn(rect.left, rect.top,
			rect.right, rect.bottom);
		SelectClipRgn(hDC,hRegion);
		m_spInPlaceSite->ReleaseDC(hDC);
	}
	else
		m_hTheWnd = m_hWnd;
}
