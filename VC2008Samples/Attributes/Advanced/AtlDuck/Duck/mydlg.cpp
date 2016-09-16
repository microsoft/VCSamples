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

#pragma warning(disable : 4100)
#pragma warning(disable : 4245)


BOOL CMyDlg::m_bOleInitialized = FALSE;
									
//static const CLSID CLSID_DuckDoer = {0x8346EF41,0x4775,0x47e7,{0xA3,0xB7,0x75,0xC2,0x78,0xA4,0x59,0xEC}};
//				6D6B20D3-E68A-4691-9D7E-E6B34AD1F29E


CMyDlg::CMyDlg()
{
	m_pIDuckConnectionPoint = NULL;
	m_pDuckInt = NULL;
	m_dwCookie = 0;
}

CMyDlg::~CMyDlg()
{
}


void CMyDlg::DoMyIToA(DWORD dwNumber, LPTSTR lpszResult)
{
	TCHAR* pch = lpszResult;
	BOOL bSign = dwNumber < 0;
	if (bSign)
		dwNumber *= -1;

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

	_ASSERT(m_pIDuckConnectionPoint == NULL);  // Only one connection point at a given time
	if (!m_bOleInitialized)
	{
		OleInitialize(NULL);
		m_bOleInitialized = TRUE;
	}

	HRESULT hr = S_OK;
	CLSID clsid;
	hr = CLSIDFromProgID(L"AtlDuck.Atlduckattrib.1", &clsid);
	ATLASSERT(S_OK == hr);
	hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IUnknown, (void**)&m_pUnk);
	if (!SUCCEEDED(hr))
	{
		::MessageBox(m_hWnd, _T("Could not create DuckDoer object.  Make sure the server is registered."),
			_T("Object Instantiation Error."), MB_OK | MB_ICONINFORMATION);

		return 0L;
	}

	_ASSERT(m_pUnk != NULL);

	// Will now disable controls in the dialog as needed
	::EnableWindow(GetDlgItem(IDOK), FALSE);  // cannot exit the application
	::EnableWindow(GetDlgItem(wID), FALSE);  // disable the creation of more doduck objects from this instance
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), TRUE);  // enable the button to release the connection point
	::EnableWindow(GetDlgItem(IDC_ADVISE), TRUE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), FALSE);

	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	_ASSERT(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Created object and got *IDuckConnectionPoint"));
	return 0L;
}

LRESULT CMyDlg::OnDestroyDoDuck(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled)
{
	UNUSED_ALWAYS(wID);
	UNUSED_ALWAYS(hwndCtl);
	UNUSED_ALWAYS(bHandled);

	ATLENSURE(m_pUnk != NULL);
	m_pUnk->Release();
	m_pUnk = NULL;

	::EnableWindow(GetDlgItem(IDOK), TRUE);
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_CREATEDODUCK), TRUE);
	::EnableWindow(GetDlgItem(IDC_ADVISE), FALSE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), FALSE);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	_ASSERT(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Released IDuckConnectionPoint interface."));

	::SetWindowText(GetDlgItem(IDC_COOKIE), _T(""));
	if (m_pDuckInt != NULL)
	{
#ifdef _DEBUG
		_ASSERT(((IDuckInt*)m_pDuckInt)->Release() == 0);
#else
		((IDuckInt*)m_pDuckInt)->Release();
#endif
		m_pDuckInt = NULL;
	}

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
	_ASSERT(m_pDuckInt != NULL);
	((IDuckInt*)m_pDuckInt)->AddRef();
	return 1;
}


LRESULT CMyDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

LRESULT CMyDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

LRESULT CMyDlg::OnAdvise(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled)
{
	HRESULT hr;
	_ASSERT(m_pUnk != NULL);
	hr = m_pDuckInt->Adv(m_pUnk);
//	_ASSERT(SUCCEEDED(hr));
	HWND hwndCookie = GetDlgItem(IDC_COOKIE);
	TCHAR  szCookie[10];
	DoMyIToA(m_dwCookie, szCookie);
	::SetWindowText(hwndCookie, szCookie);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	_ASSERT(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Advise called."));

	// enable only the valid buttons
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), FALSE);
	::EnableWindow(GetDlgItem(IDC_UNADVISE), TRUE);
	return 0;
}

LRESULT CMyDlg::OnUnadvise(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled)
{
	HRESULT hr;
	_ASSERT(m_pUnk != NULL);
	hr = m_pDuckInt->UnAdv(m_pUnk);
	_ASSERT(SUCCEEDED(hr));
	m_dwCookie = 0;
	HWND hwndCookie = GetDlgItem(IDC_COOKIE);
	::SetWindowText(hwndCookie, _T(""));
	::UpdateWindow(hwndCookie);
	HWND hwndStatus = GetDlgItem(IDC_STATUS);
	_ASSERT(hwndStatus != NULL);
	::SetWindowText(hwndStatus, _T("Unadvise called."));
	::UpdateWindow(hwndStatus);
	::EnableWindow(GetDlgItem(wID), FALSE);
	::EnableWindow(GetDlgItem(IDC_DESTROYDODUCK), TRUE);
	::EnableWindow(GetDlgItem(IDC_ADVISE), TRUE);
	return 0;
}
