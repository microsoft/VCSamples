// DuckDoerDlg.cpp : Implementation of CDuckDoerDlg
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
#include "DuckDoerDlg.h"
#include "duckdoer.h"


/////////////////////////////////////////////////////////////////////////////
// CDuckDoerDlg

CDuckDoerDlg::CDuckDoerDlg()
{
	m_pObject = NULL;
	m_xListboxExtentMax = 0;
	CDuckDoer::m_pDlg = this;
}

CDuckDoerDlg::~CDuckDoerDlg()
{
}

LRESULT CDuckDoerDlg::OnInitDialog(UINT , WPARAM , LPARAM , BOOL& )
{
	CenterWindow();
	return 1;  // Let the system set the focus
}

LRESULT CDuckDoerDlg::OnOK(WORD , WORD , HWND , BOOL& )
{
	ShowWindow(SW_HIDE);
	_ASSERT(m_pObject != NULL);
	m_pObject->m_bLocked = FALSE;
	return 0;
}

LRESULT CDuckDoerDlg::OnCancel(WORD , WORD , HWND , BOOL& )
{
	_ASSERT(FALSE);
	return 0;
}

LRESULT CDuckDoerDlg::OnQuack(WORD , WORD , HWND , BOOL& )
{
	USES_CONVERSION;
	TCHAR szWhosCalling[100];
	_tcscpy_s(szWhosCalling, 100, _T("Server Quacking for Sink No. XX."));
	CComBSTR szOut(szWhosCalling);
	m_pObject->Fire_Quack(szOut);
	return 1;
}

LRESULT CDuckDoerDlg::OnFlap(WORD , WORD , HWND , BOOL& )
{
	USES_CONVERSION;
	TCHAR szWhosCalling[100];
	_tcscpy_s(szWhosCalling,100, _T("Server Flapping for Sink No. XX."));
	CComBSTR  szOut(szWhosCalling);
	m_pObject->Fire_Flap(szOut);
	return 1;
}

LRESULT CDuckDoerDlg::OnPaddle(WORD , WORD , HWND , BOOL& )
{
	USES_CONVERSION;
	TCHAR szWhosCalling[100];
	_tcscpy_s(szWhosCalling, 100,_T("Server Paddling for Sink No. XX."));
	CComBSTR  szOut(szWhosCalling);
	m_pObject->Fire_Paddle(szOut);
	return 1;
}

LRESULT CDuckDoerDlg::OnWalk(WORD , WORD , HWND , BOOL& )
{
	USES_CONVERSION;
	TCHAR szWhosCalling[100];
	_tcscpy_s(szWhosCalling, 100, _T("Server Walking for Sink No. XX."));
	CComBSTR  szOut(szWhosCalling);
	m_pObject->Fire_Walk(szOut);
	return 1;
}

void CDuckDoerDlg::RecalcListboxExtent(LPCTSTR szEntry, BOOL bAdded)
{
	HDC hDC;
	HWND hwndListbox = GetDlgItem(IDC_LISTCONNPTS);
	SIZE  size;

	ATLENSURE(hwndListbox != NULL);
	hDC = ::GetDC(hwndListbox);
	ATLENSURE(hDC != NULL);
	_VERIFY(::GetTextExtentPoint32(hDC, szEntry, (int)_tcslen(szEntry), &size));
	if (bAdded && size.cx > m_xListboxExtentMax)
	{
		m_xListboxExtentMax = size.cx;
		::SendMessage(hwndListbox, LB_SETHORIZONTALEXTENT, (WPARAM)size.cx, 0);
	}
	else if (!bAdded && size.cx == m_xListboxExtentMax)
	{
		TCHAR szBuffer[100];
		m_xListboxExtentMax = 0;
		int nLim = (int)::SendMessage(hwndListbox, LB_GETCOUNT, 0, 0);
		ATLENSURE(nLim != LB_ERR);
		for (int i = 0; i <= nLim; i++)
		{
			::SendMessage(hwndListbox, LB_GETTEXT, (WPARAM)i, (LPARAM)szBuffer);
			#pragma warning(suppress: 6054) // SendMessage LB_GETTEXT will always return a null terminated string
			::GetTextExtentPoint32(hDC, szBuffer, (int)_tcslen(szBuffer), &size);
			if (size.cx > m_xListboxExtentMax)
				m_xListboxExtentMax = size.cx;
		}

		::SendMessage(hwndListbox, LB_SETHORIZONTALEXTENT, (WPARAM)size.cx, 0);
	}

	::ReleaseDC(hwndListbox, hDC);
}
