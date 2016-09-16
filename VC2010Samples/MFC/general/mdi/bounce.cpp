// bounce.cpp : Defines the class behaviors for the Bounce child window.
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
#include "mdi.h"
#include "bounce.h"

#define ABS(x) ((x) < 0? -(x) : (x) > 0? (x) : 0)


/////////////////////////////////////////////////////////////////////////////
// CBounceWnd

BEGIN_MESSAGE_MAP(CBounceWnd, CMDIChildWnd)
	//{{AFX_MSG_MAP(CBounceWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_COMMAND(IDM_BLACK, OnColor)
	ON_COMMAND(IDM_CUSTOM, OnCustomColor)
	ON_COMMAND(IDM_RED, OnColor)
	ON_COMMAND(IDM_GREEN, OnColor)
	ON_COMMAND(IDM_BLUE, OnColor)
	ON_COMMAND(IDM_WHITE, OnColor)
	ON_UPDATE_COMMAND_UI(IDM_SLOW, OnUpdateSlow)
	ON_COMMAND(IDM_SLOW, OnSlow)
	ON_UPDATE_COMMAND_UI(IDM_RED, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_WHITE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_GREEN, OnUpdateColor)
	ON_COMMAND(IDM_FAST, OnFast)
	ON_UPDATE_COMMAND_UI(IDM_FAST, OnUpdateFast)
	ON_UPDATE_COMMAND_UI(IDM_CUSTOM, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLUE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLACK, OnUpdateColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CMenu NEAR CBounceWnd::menu;        // menu for all BOUNCE windows

/////////////////////////////////////////////////////////////////////////////
// CBounceWnd creation

BOOL CBounceWnd::Create(LPCTSTR szTitle, LONG style /* = 0 */,
	const RECT& rect /* = rectDefault */,
	CMDIFrameWnd* parent /* = NULL */)
{
	// Setup the shared menu
	if (menu.m_hMenu == NULL)
		menu.LoadMenu(IDR_BOUNCE);
	m_hMenuShared = menu.m_hMenu;

	// Register a custom WndClass and create a window.
	// This must be done because CBounceWnd has a custom cursor, and
	//  no icon.
	LPCTSTR lpszBounceClass =
		AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
			LoadCursor(NULL, IDC_UPARROW),
			(HBRUSH)(COLOR_WINDOW+1),
			NULL);

	return CMDIChildWnd::Create(lpszBounceClass, szTitle, style, rect, parent);
}

CBounceWnd::CBounceWnd()
{
	m_nIDColor = IDM_BLACK;
	m_clrBall = RGB(0,0,0);
	m_bFastSpeed = FALSE;
}


// Set up the ball parameters and start a timer.
int CBounceWnd::OnCreate(LPCREATESTRUCT /* p */)
{
	if (!SetTimer(1, 100 /*start slow*/, NULL))
	{
		MessageBox(_T("Not enough timers available for this window."),
				_T("MDI:Bounce"), MB_ICONEXCLAMATION | MB_OK);

		// signal creation failure...
		return -1;
	}

	CDC* pDC = GetDC();
	m_ptPixel.x = pDC->GetDeviceCaps(ASPECTX);
	m_ptPixel.y = pDC->GetDeviceCaps(ASPECTY);
	ReleaseDC(pDC);

	// Note that we could call MakeNewBall here (which should be called
	// whenever the ball's speed, color or size has been changed), but the
	// OnSize member function is always called after the OnCreate. Since
	// the OnSize member has to call MakeNewBall anyway, we don't here.

	return 0;
}

// MakeNewBall:
// Whenever a parameter changes which would affect the speed or appearance
// of the ball, call this to regenerate the ball bitmap.
//
void CBounceWnd::MakeNewBall()
{
	m_sizeTotal.cx = (m_sizeRadius.cx + ABS(m_sizeMove.cx)) << 1;
	m_sizeTotal.cy = (m_sizeRadius.cy + ABS(m_sizeMove.cy)) << 1;

	if (m_bmBall.m_hObject != NULL)
		m_bmBall.DeleteObject();        // get rid of old bitmap

	CClientDC dc(this);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);

	m_bmBall.CreateCompatibleBitmap(&dc, m_sizeTotal.cx, m_sizeTotal.cy);
	ASSERT(m_bmBall.m_hObject != NULL);

	CBitmap* pOldBitmap = dcMem.SelectObject(&m_bmBall);

	// draw a rectangle in the background (window) color
	CRect rect(0, 0, m_sizeTotal.cx, m_sizeTotal.cy);
	CBrush brBackground(::GetSysColor(COLOR_WINDOW));
	dcMem.FillRect(rect, &brBackground);

	CBrush brCross(HS_DIAGCROSS, 0L);
	CBrush* pOldBrush = dcMem.SelectObject(&brCross);

	dcMem.SetBkColor(m_clrBall);
	dcMem.Ellipse(ABS(m_sizeMove.cx), ABS(m_sizeMove.cy),
		m_sizeTotal.cx - ABS(m_sizeMove.cx),
		m_sizeTotal.cy - ABS(m_sizeMove.cy));

	dcMem.SelectObject(pOldBrush);
	dcMem.SelectObject(pOldBitmap);
	dcMem.DeleteDC();
}

// The ball's size and displacement change according to the window size.
void CBounceWnd::OnSize(UINT nType, int cx, int cy)
{
	LONG lScale;

	m_ptCenter.x = cx >> 1;
	m_ptCenter.y = cy >> 1;
	m_ptCenter.x += cx >> 3; // make the ball a little off-center

	lScale = min((LONG)cx * m_ptPixel.x,
		(LONG)cy * m_ptPixel.y) >> 4;
	m_sizeRadius.cx = (int)(lScale / m_ptPixel.x);
	m_sizeRadius.cy = (int)(lScale / m_ptPixel.y);
	m_sizeMove.cx = max(1, m_sizeRadius.cy >> 2);
	m_sizeMove.cy = max(1, m_sizeRadius.cy >> 2);

	MakeNewBall();

	CMDIChildWnd::OnSize(nType, cx, cy);
}

/////////////////////////////////////////////////////////////////////////////
// CBounceWnd commands

void CBounceWnd::OnUpdateColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nIDColor);
}

void CBounceWnd::OnColor()
{
	m_nIDColor = LOWORD(GetCurrentMessage()->wParam);
	m_clrBall = colorArray[m_nIDColor - IDM_BLACK];

	// Force the client area text to be repainted in the new color
	MakeNewBall();
	Invalidate();
}

void CBounceWnd::OnCustomColor()
{
	CColorDialog dlgColor(m_clrBall);
	if (dlgColor.DoModal() == IDOK)
	{
		m_clrBall = dlgColor.GetColor();
		m_nIDColor = IDM_CUSTOM;
		MakeNewBall();
		Invalidate();
	}
}

// Change the ball's speed
void CBounceWnd::ChangeSpeed()
{
	// re-create the timer
	KillTimer(1);
	if (!SetTimer(1, m_bFastSpeed ? 0 : 100, NULL))
	{
		MessageBox(_T("Not enough timers available for this window."),
				_T("MDI:Bounce"), MB_ICONEXCLAMATION | MB_OK);
		DestroyWindow();
	}
}

// Animate the ball.
void CBounceWnd::OnTimer(UINT_PTR /* wParam */)
{
	if (m_bmBall.m_hObject == NULL)
		return;     // no bitmap for the ball

	CRect rcClient;
	GetClientRect(rcClient);

	CClientDC dc(this);
	CBitmap* pbmOld = NULL;

	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	pbmOld = dcMem.SelectObject(&m_bmBall);

	dc.BitBlt(m_ptCenter.x - m_sizeTotal.cx / 2,
			m_ptCenter.y - m_sizeTotal.cy / 2,
			m_sizeTotal.cx, m_sizeTotal.cy,
			&dcMem, 0, 0, SRCCOPY);

	m_ptCenter += m_sizeMove;

	if ((m_ptCenter.x + m_sizeRadius.cx >= rcClient.right) ||
		(m_ptCenter.x - m_sizeRadius.cx <= 0))
	{
		m_sizeMove.cx = -m_sizeMove.cx;
	}

	if ((m_ptCenter.y + m_sizeRadius.cy >= rcClient.bottom) ||
		(m_ptCenter.y - m_sizeRadius.cy <= 0))
	{
		m_sizeMove.cy = -m_sizeMove.cy;
	}

	dcMem.SelectObject(pbmOld);
	dcMem.DeleteDC();
}

void CBounceWnd::OnUpdateSlow(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!m_bFastSpeed);
}

void CBounceWnd::OnSlow()
{
	m_bFastSpeed = FALSE;
	ChangeSpeed();
}

void CBounceWnd::OnUpdateFast(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bFastSpeed);
}

void CBounceWnd::OnFast()
{
	m_bFastSpeed = TRUE;
	ChangeSpeed();
}
