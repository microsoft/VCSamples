// DuckDoer.cpp : Implementation of CDuckDoer
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
#include "DuckDoer.h"

/////////////////////////////////////////////////////////////////////////////
// CDuckDoer

// static class members
CDuckDoerDlg* CDuckDoer::m_pDlg = NULL;


STDMETHODIMP CDuckDoer::Advise(IUnknown* pUnk, DWORD* pdwCookie)
{
	if (!m_bLocked)  // lock the server on the first advise received
	{
		(this)->AddRef();
		m_bLocked = TRUE;
	}

	HRESULT hr = IConnectionPointImpl<CDuckDoer,&__uuidof(IDuckInt), CComDynamicUnkArray>::Advise(pUnk, pdwCookie);
	if (SUCCEEDED(hr))
	{
		TCHAR szCookieItem[50];
		_stprintf_s(szCookieItem, 50,_T("Cookie %9d.\t(pUnk = %p)"), *pdwCookie, *pUnk);
		ATLENSURE(m_pDlg != NULL);

		if (!m_pDlg->IsWindowVisible())
			m_pDlg->ShowWindow(SW_SHOWNORMAL);

		HWND hwndListBox = m_pDlg->GetDlgItem(IDC_LISTCONNPTS);
		SendMessage(hwndListBox, LB_ADDSTRING, 0, (LPARAM)(TCHAR*)szCookieItem);

		m_pDlg->RecalcListboxExtent(szCookieItem);

		// enable all the dialog buttons for connection points
		_ASSERT(m_pDlg != NULL);
		::EnableWindow(m_pDlg->GetDlgItem(IDC_QUACK), TRUE);
		::EnableWindow(m_pDlg->GetDlgItem(IDC_FLAP), TRUE);
		::EnableWindow(m_pDlg->GetDlgItem(IDC_PADDLE), TRUE);
		::EnableWindow(m_pDlg->GetDlgItem(IDC_WALK), TRUE);
		::EnableWindow(m_pDlg->GetDlgItem(IDOK), FALSE);
	}

	return hr;
}

STDMETHODIMP CDuckDoer::Unadvise(DWORD dwCookie)
{
	HRESULT hr = IConnectionPointImpl<CDuckDoer,&__uuidof(IDuckInt), CComDynamicUnkArray>::Unadvise(dwCookie);
	if (SUCCEEDED(hr))
	{
		TCHAR szCookieItem[50];
		_stprintf_s(szCookieItem, 50, _T("Cookie %9d."), dwCookie);
		ATLENSURE(m_pDlg != NULL);
		HWND hwndListBox = m_pDlg->GetDlgItem(IDC_LISTCONNPTS);
		LRESULT nIndex = SendMessage(hwndListBox, LB_FINDSTRING, (WPARAM)-1, (LPARAM)szCookieItem);
		ATLENSURE(nIndex != LB_ERR);  // the entry has to be in the listbox.
		SendMessage(hwndListBox, LB_GETTEXT, nIndex, (LPARAM)szCookieItem);
		SendMessage(hwndListBox, LB_DELETESTRING, nIndex, 0);
		m_pDlg->RecalcListboxExtent(szCookieItem, FALSE/*bAdded*/);
		int nItems = (int)SendMessage(hwndListBox, LB_GETCOUNT, 0, 0);
		ATLENSURE(nItems != LB_ERR);
		if (nItems == 0)  // the listbox is empty change button settings
		{
			_ASSERT(m_pDlg != NULL);
			::EnableWindow(m_pDlg->GetDlgItem(IDC_QUACK), FALSE);
			::EnableWindow(m_pDlg->GetDlgItem(IDC_FLAP), FALSE);
			::EnableWindow(m_pDlg->GetDlgItem(IDC_PADDLE), FALSE);
			::EnableWindow(m_pDlg->GetDlgItem(IDC_WALK), FALSE);
			::EnableWindow(m_pDlg->GetDlgItem(IDOK), TRUE);
		}
	}

	return hr;
}
