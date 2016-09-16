// mydlg.cpp: Implementation of CMyDlg
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
#include "mydlg.h"

BOOL CMyDlg::m_bOleInitialized = FALSE;

static const CLSID CLSID_DuckDoer = {0x120B72A0,0x65BF,0x11D0,{0x9D,0xDC,0x00,0xA0,0xC9,0x03,0x48,0x92}};

CMyDlg::CMyDlg()
{
	m_pIDuckConnectionPoint = NULL;
	m_pDuckInt = NULL;
	m_dwCookie = 0;
}

CMyDlg::~CMyDlg()
{
	if (m_pDuckInt != NULL)
	{
#ifdef _DEBUG
		ATLENSURE(((IDuckInt*)m_pDuckInt)->Release() == 0);
#else
		((IDuckInt*)m_pDuckInt)->Release();
#endif
		m_pDuckInt = NULL;
	}
}


void CMyDlg::DoMyIToA(DWORD dwNumber, LPTSTR lpszResult)
{
	TCHAR* pch = lpszResult;
	BOOL bSign = dwNumber < 0;
	if (bSign)
		dwNumber *= (DWORD)-1;

	do
	{
		*pch++ = (char)(dwNumber % 10) + '0';
		dwNumber /= 10;
	}
	while (dwNumber > 0);

	if (bSign)
		*pch++ = _T('-');

	*pch-- = 0;

	// will now reverse the string
	TCHAR* pchRev = lpszResult;
	TCHAR ch;
	while (pch > pchRev)
	{
		ch = *pch;
		*pch-- = *pchRev;
		*pchRev++ = ch;
	}
}

interface DECLSPEC_UUID("120B729F-65BF-11D0-9DDC-00A0C9034892")
IDuckDoer : public IUnknown
{
};

const IID IID_IDuckDoer = {0x120B729F,0x65BF,0x11D0,{0x9D,0xDC,0x00,0xA0,0xC9,0x03,0x48,0x92}};

LRESULT CMyDlg::OnCreateDoDuck(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled)
{
	UNUSED_ALWAYS(wID);
	UNUSED_ALWAYS(hwndCtl);

	if (wNotifyCode != BN_CLICKED)
	{
		bHandled = FALSE;  // let someone else handle this message
		return 0L;
	}

	ATLENSURE(m_pIDuckConnectionPoint == NULL);  // Only one connection point at a given time
	if (!m_bOleInitialized)
	{
		OleInitialize(NULL);
		m_bOleInitialized = TRUE;
	}

	HRESULT hr;
	IUnknown* pUnk = NULL;
	IConnectionPointContainer* pConnPtContainer = NULL;
	hr = CoCreateInstance(CLSID_DuckDoer, NULL, CLSCTX_LOCAL_SERVER, IID_IUnknown, (void**)&pUnk);
	if (!SUCCEEDED(hr))
	{
		::MessageBox(m_hWnd, _T("Could not create DuckDoer object.  Make sure the server is registered."),
			_T("Object Instantiation Error."), MB_OK | MB_ICONINFORMATION);

		return 0L;
	}

	ATLENSURE(pUnk != NULL);

	hr = pUnk->QueryInterface(IID_IConnectionPointContainer, (void**)&pConnPtContainer);
	ATLENSURE(SUCCEEDED(hr) && pConnPtContainer != NULL);
	hr = pConnPtContainer->FindConnectionPoint(IID_IDuckInt, &m_pIDuckConnectionPoint);
	ATLENSURE(SUCCEEDED(hr) && m_pIDuckConnectionPoint != NULL);
	ATLENSURE(m_pDuckInt != NULL);
	pUnk->Release();
	pConnPtContainer->Release();

	// Will now disable controls in the dialog as needed
	::EnableWindow(GetDlgItem(IDOK), FALSE);  // cannot exit the application
	::EnableWindow(GetDlgItem(wID), FALSE);  // disable the creation of more doduck objects from this instance
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), TRUE);  // enable the button to release the connection point
	::EnableWindow(GetDlgItem(IDC_ADVISE), TRUE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), FALSE);

	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	ATLENSURE(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Created object and got *IDuckConnectionPoint"));
	return 0L;
}

LRESULT CMyDlg::OnDestroyDoDuck(WORD , WORD wID, HWND , BOOL& )
{
	ATLENSURE(m_pIDuckConnectionPoint != NULL);
	m_pIDuckConnectionPoint->Release();
	m_pIDuckConnectionPoint = NULL;

	::EnableWindow(GetDlgItem(IDOK), TRUE);
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_CREATEDODUCK), TRUE);
	::EnableWindow(GetDlgItem(IDC_ADVISE), FALSE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), FALSE);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	ATLENSURE(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Released IDuckConnectionPoint interface."));

	::SetWindowText(GetDlgItem(IDC_COOKIE), _T(""));
	return 0L;
}

LRESULT CMyDlg::OnInitDialog(UINT umsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	UNUSED_ALWAYS(umsg);
	UNUSED_ALWAYS(wParam);
	UNUSED_ALWAYS(lParam);
	UNUSED_ALWAYS(bHandled);

	CenterWindow();
	m_pDuckInt = new CComObject<CDuckInt>;
	ATLENSURE(m_pDuckInt != NULL);
	((IDuckInt*)m_pDuckInt)->AddRef();
	return 1;
}


LRESULT CMyDlg::OnOK(WORD , WORD wID, HWND , BOOL& )
{
	EndDialog(wID);
	return 0;
}

LRESULT CMyDlg::OnCancel(WORD , WORD wID, HWND , BOOL& )
{
	EndDialog(wID);
	return 0;
}

LRESULT CMyDlg::OnAdvise(WORD , WORD wID, HWND , BOOL& )
{
	HRESULT hr;
	ATLENSURE(m_pIDuckConnectionPoint != NULL);
	hr = m_pIDuckConnectionPoint->Advise((IUnknown*)m_pDuckInt, &m_dwCookie);
	ATLENSURE(SUCCEEDED(hr) && m_dwCookie != 0);
	HWND hwndCookie = GetDlgItem(IDC_COOKIE);
	TCHAR  szCookie[10];
	DoMyIToA(m_dwCookie, szCookie);
	::SetWindowText(hwndCookie, szCookie);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	ATLENSURE(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Advise called."));

	// enable only the valid buttons
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), FALSE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), TRUE);
	return 0;
}

LRESULT CMyDlg::OnUnadvise(WORD , WORD wID, HWND , BOOL& )
{
	HRESULT hr;
	ATLENSURE(m_pIDuckConnectionPoint != NULL);
	hr = m_pIDuckConnectionPoint->Unadvise(m_dwCookie);
	ATLENSURE(SUCCEEDED(hr));
	m_dwCookie = 0;
	HWND hwndCookie = GetDlgItem(IDC_COOKIE);
	::SetWindowText(hwndCookie, _T(""));
	::UpdateWindow(hwndCookie);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	ATLENSURE(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Unadvise called."));
	::UpdateWindow(hwndStatus);
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), TRUE);
	::EnableWindow(GetDlgItem(IDC_ADVISE), TRUE);
	return 0;
}
