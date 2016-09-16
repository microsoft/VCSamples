// duckint.cpp: Implementation of CDuckInt
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
#include "resource.h"
#include "duckint.h"
#include "mydlg.h"

extern CMyDlg mydlg;

static void ShowStatus(LPCTSTR szWhosCalling)
{
	HWND hwndStatus = mydlg.GetDlgItem(IDC_STATUS);
	::SetWindowText(hwndStatus, szWhosCalling);
}

STDMETHODIMP CDuckInt::Quack(BSTR szWhosCalling)
{
	USES_CONVERSION;

	COLE2T temp(szWhosCalling);
	LPTSTR szCaller = temp;
	ShowStatus(szCaller);
	return S_OK;
}

STDMETHODIMP CDuckInt::Flap(BSTR szWhosCalling)
{
	USES_CONVERSION;

	COLE2T temp(szWhosCalling);
	LPTSTR szCaller = temp;
	ShowStatus(szCaller);
	return S_OK;
}

STDMETHODIMP CDuckInt::Paddle(BSTR szWhosCalling)
{
	USES_CONVERSION;

	COLE2T temp(szWhosCalling);
	LPTSTR szCaller = temp;
	ShowStatus(szCaller);
	return S_OK;
}

STDMETHODIMP CDuckInt::Walk(BSTR szWhosCalling)
{
	USES_CONVERSION;

	COLE2T temp(szWhosCalling);
	LPTSTR szCaller = temp;
	ShowStatus(szCaller);
	return S_OK;
}
