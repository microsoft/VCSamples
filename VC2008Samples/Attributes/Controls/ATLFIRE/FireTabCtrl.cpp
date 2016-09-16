// FireTabCtrl.cpp : Implementation of CFireTabCtrl
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
#include "ATLFire.h"
#include "FireTabCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CFireTabCtrl


HRESULT CFireTabCtrl::OnDraw(ATL_DRAWINFO& di)
{
	return S_OK;
}

LRESULT CFireTabCtrl::OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
{
	if(m_ctlSysTabControl32.m_hWnd != NULL)
		TabCtrl_DeleteAllItems(m_ctlSysTabControl32);
	return 0;
}

CFireTabCtrl::CFireTabCtrl() :
	m_ctlSysTabControl32(_T("SysTabControl32"), this, 1)
{
	m_bWindowOnly = TRUE;
}

CFireTabCtrl::~CFireTabCtrl()
{
	TCHAR szBuff[128];
	_stprintf_s(szBuff, 128, _T("ATL:%s"), m_ctlSysTabControl32.m_lpszClassName);
	UnregisterClass(szBuff, _pModule->GetModuleInstance());
}

LRESULT CFireTabCtrl::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ATLTRACE(_T("CFireTabCtrl::OnSize()\n"));
	int cx, cy;
	cx = LOWORD(lParam);
	cy = HIWORD(lParam);
	::SetWindowPos(m_ctlSysTabControl32.m_hWnd, NULL, 0,
		0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);

	int cxFire = cx - 12;
	int cyFire = cy - 40;
	::SetWindowPos(m_Display.m_hWnd, NULL, 5,
		30, cxFire, cyFire, SWP_NOZORDER | SWP_NOACTIVATE);

	m_Display.bmSize.cx = cxFire - 5;
	m_Display.bmSize.cy = cyFire - 30;
	switch(m_Display.m_curColor)
	{
	case 0:
		m_Display.InitFire(CFireWnd::red);
		break;
	case 1:
		m_Display.InitFire(CFireWnd::blue);
		break;
	case 2:
		m_Display.InitFire(CFireWnd::green);
		break;
	}
	FireOnChanged(5);

	return 0;
}

LRESULT CFireTabCtrl::OnSelChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	ATLTRACE(_T("CTabDlg::OnSelChanged()\n"));
	m_Display.m_curColor = TabCtrl_GetCurSel(m_ctlSysTabControl32.m_hWnd);
	switch(m_Display.m_curColor)
	{
	case 0:
		m_Display.InitFire(CFireWnd::red);
		break;
	case 1:
		m_Display.InitFire(CFireWnd::blue);
		break;
	case 2:
		m_Display.InitFire(CFireWnd::green);
		break;
	}

	// force a repaint
	m_Display.Invalidate();

	return 0;
}

LRESULT CFireTabCtrl::OnEraseBackground(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ATLTRACE(_T("CTabDlg::OnEraseBackground()\n"));
	return 0;
}

LRESULT CFireTabCtrl::OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ATLTRACE(_T("CTabDlg::OnActivate()\n"));
	m_Display.SendMessage(WM_QUERYNEWPALETTE);  // redo the palette if necessary
	return 0;
}

LRESULT CFireTabCtrl::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	ATLTRACE(_T("CFireTabDlg::OnCreate()\n"));

	// Setup and create the tab control
	int nTabs = 3;
	_TCHAR *pszNames[] = { _T("Wood"), _T("Natural Gas"), _T("Kryptonite") };
	RECT rc;
	GetWindowRect(&rc);
	rc.right -= rc.left;
	rc.bottom -= rc.top;
	rc.top = rc.left = 0;
	m_ctlSysTabControl32.Create(m_hWnd, rc,_T(""), WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | TCS_TABS );
	TC_ITEM tie;
	for( int i = 0; i < nTabs; i++ )
	{
		tie.mask = TCIF_TEXT | TCIF_IMAGE;
		tie.iImage = -1;
		tie.pszText = pszNames[i];
		tie.cchTextMax = (int)_tcslen(pszNames[i]);
		if (TabCtrl_InsertItem (m_ctlSysTabControl32.m_hWnd, i, &tie) == -1)
		{
			// The insert failed; display an error box.
			::MessageBox (NULL, _T("TabCtrl_InsertItem failed!"), NULL, MB_OK);
			return E_FAIL;
		}
	}

	m_Display.Create(m_ctlSysTabControl32.m_hWnd);
	TabCtrl_SetCurSel(m_ctlSysTabControl32.m_hWnd, m_Display.m_curColor);
	m_Display.ShowWindow(TRUE);
	return 0;
}

HRESULT CFireTabCtrl::IOleInPlaceObject_UIDeactivate()
{
	ATLTRACE(_T("CFireTabDlg::IOleInPlaceObject_UIDeactivate()\n"));

	if(m_Display.m_hWnd != NULL && ::IsWindow(m_Display.m_hWnd))
	{
		ATLTRACE(_T("Destroying m_Display.m_hWnd\n"));
		m_Display.DestroyWindow();
	}

	return CComControlBase::IOleInPlaceObject_UIDeactivate();
}

STDMETHODIMP CFireTabCtrl::IOleInPlaceObject_SetObjectRects(LPCRECT prcPos,LPCRECT prcClip)
{
	CComControlBase::IOleInPlaceObject_SetObjectRects(prcPos, prcClip);
	ATLTRACE(_T("CFireTabDlg::IOleInPlaceObject_SetObjectRects()\n"));

	// The width and height of the rectangle for the tab control
	int cx = prcPos->right - prcPos->left;
	int cy = prcPos->bottom - prcPos->top;

	// Here's where we cache away the size of the window
	// for the fire bitmap display. rcSize is used in
	// CFireWnd::CreateBitmap()
	m_Display.rcSize.cx = cx - 12;
	m_Display.rcSize.cy = cy - 40;

	// We'll set the window sizes if the tab control has a window
	if( ::IsWindow(m_ctlSysTabControl32.m_hWnd) )
	{
		::SetWindowPos(m_ctlSysTabControl32.m_hWnd, NULL, 0,
			0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		::SetWindowPos(m_Display.m_hWnd, NULL, 5,
			30, cx - 12, cy - 40, SWP_NOZORDER | SWP_NOACTIVATE);
	}

	return 0;
}

STDMETHODIMP CFireTabCtrl::GetViewStatus(DWORD* pdwStatus)
{
	ATLTRACE(_T("IViewObjectExImpl::GetViewStatus\n"));
	*pdwStatus = VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Decay(long * pVal)
{
	*pVal = m_Display.m_nDecay;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Decay(long newVal)
{
	if( newVal < 1 || newVal > 100 )
	{
		Error(_T("Please insert a number between 1 and 100"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nDecay = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Flammability(long * pVal)
{
	*pVal = m_Display.m_nFlammability;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Flammability(long newVal)
{
	if( newVal < 1 || newVal > 399 )
	{
		Error(_T("Please insert a number between 1 and 399"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nFlammability = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_MaxHeat(long * pVal)
{
	*pVal = m_Display.m_nMaxHeat;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_MaxHeat(long newVal)
{
	if( newVal < 0 || newVal > 223 )
	{
		Error( _T("Please insert a number between 0 and 223"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nMaxHeat = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_SpreadRate(long * pVal)
{
	*pVal = m_Display.m_nSpreadRate;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_SpreadRate(long newVal)
{
	if( newVal < 1 || newVal > 100 )
	{
		Error(_T("Please insert a number between 1 and 100"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nSpreadRate = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Size(long * pVal)
{
	*pVal = m_Display.m_nSize;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Size(long newVal)
{
	if( m_Display.bmSize.cx  != 0)
	{
		int maxWidth = m_Display.bmSize.cx - 1;
		if( newVal < 1 || newVal > maxWidth )
		{
			_TCHAR buf[128];
			_stprintf_s(buf,128,_T("Please insert a number between 1 and %d (bitmap width)"), maxWidth);
			Error(buf);
			return DISP_E_EXCEPTION;
		}
	}

	m_Display.m_nSize = newVal;

	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Smoothness(long * pVal)
{
	*pVal = m_Display.m_nSmoothness;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Smoothness(long newVal)
{
	if( newVal < 0 || newVal > 5 )
	{
		Error(_T("Please insert a number between 0 and 5"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nSmoothness = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Distribution(long * pVal)
{
	*pVal = m_Display.m_nDistribution;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Distribution(long newVal)
{
	if( newVal < 0 || newVal > 10 )
	{
		Error(_T("Please insert a number between 0 and 10"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nDistribution = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_Chaos(long * pVal)
{
	*pVal = m_Display.m_nChaos;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_Chaos(long newVal)
{
	if( newVal < 1 || newVal > 100 )
	{
		Error(_T("Please insert a number between 1 and 100"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_nChaos = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::get_StartTab(long * pVal)
{
	*pVal = m_Display.m_curColor;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::put_StartTab(long newVal)
{
	ATLTRACE(_T("CFireTabCtrl::put_StartTab()\n"));
	if( newVal < 0 || newVal > 2 )
	{
		Error(_T("Please insert a number between 0 and 2"));
		return DISP_E_EXCEPTION;
	}
	m_Display.m_curColor = newVal;
	return S_OK;
}

STDMETHODIMP CFireTabCtrl::AboutBox()
{
	CAboutBox dlg;
	dlg.DoModal();
	return S_OK;
}


LRESULT CAboutBox::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}
