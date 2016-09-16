// hello.cpp : Defines the class behaviors for the Hello child window.
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
#include "hello.h"
#include "mdi.h"

/////////////////////////////////////////////////////////////////////////////
// CHelloWnd Member Functions

BEGIN_MESSAGE_MAP(CHelloWnd, CMDIChildWnd)
	//{{AFX_MSG_MAP(CHelloWnd)
	ON_WM_PAINT()
	ON_COMMAND(IDM_BLACK, OnColor)
	ON_COMMAND(IDM_CUSTOM, OnCustomColor)
	ON_COMMAND(IDM_RED, OnColor)
	ON_COMMAND(IDM_GREEN, OnColor)
	ON_COMMAND(IDM_BLUE, OnColor)
	ON_COMMAND(IDM_WHITE, OnColor)
	ON_UPDATE_COMMAND_UI(IDM_BLACK, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLUE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_GREEN, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_RED, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_WHITE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_CUSTOM, OnUpdateColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CMenu NEAR CHelloWnd::menu;     // menu for all HELLO windows

/////////////////////////////////////////////////////////////////////////////
// CHelloWnd construction

BOOL CHelloWnd::Create(LPCTSTR szTitle, LONG style /* = 0 */,
	const RECT& rect /* = rectDefault */,
	CMDIFrameWnd* parent /* = NULL */)
{
	// Setup the shared menu
	if (menu.m_hMenu == NULL)
		menu.LoadMenu(IDR_HELLO);
	m_hMenuShared = menu.m_hMenu;

	// Register a custom WndClass and create a window.
	// This must be done because CHelloWnd has a custom icon.

	LPCTSTR lpszHelloClass =
		  AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
			LoadCursor(NULL, IDC_ARROW),
			(HBRUSH) (COLOR_WINDOW+1),
			LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_HELLO)));

	return CMDIChildWnd::Create(lpszHelloClass, szTitle, style, rect, parent);
}

CHelloWnd::CHelloWnd()
{
	m_nIDColor = IDM_BLACK;
	m_clrText = RGB(0, 0, 0);
}

// OnPaint:
// Draw a string in the center of the client area.
//
void CHelloWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;

	dc.SetTextColor(m_clrText);
	dc.SetBkColor(::GetSysColor(COLOR_WINDOW));
	GetClientRect(rect);
	dc.DrawText(_T("Hello, World!"), -1, rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

/////////////////////////////////////////////////////////////////////////////
// CHelloWnd command

void CHelloWnd::OnUpdateColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nIDColor);
}

void CHelloWnd::OnColor()
{
	m_nIDColor = LOWORD(GetCurrentMessage()->wParam);
	m_clrText = colorArray[m_nIDColor - IDM_BLACK];

	// Force the client area text to be repainted in the new color
	Invalidate();
}

void CHelloWnd::OnCustomColor()
{
	CColorDialog dlgColor(m_clrText);
	if (dlgColor.DoModal() == IDOK)
	{
		m_clrText = dlgColor.GetColor();
		m_nIDColor = IDM_CUSTOM;
		Invalidate();
	}
}
