// MultiDlg.cpp : Implementation of CMultiDlg
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "MultiDlg.h"
#include "DBRead.h"

/////////////////////////////////////////////////////////////////////////////
// CMultiDlg

CMultiDlg::CMultiDlg()
{
}

CMultiDlg::~CMultiDlg()
{
}

LRESULT CMultiDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	CenterWindow();
	return 1;  // Let the system set the focus
}

LRESULT CMultiDlg::OnRun(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	TCHAR   szMsg[256];
	long    nThreads = GetDlgItemInt(IDC_THREADS);
	DWORD   dwTime, dwRows;

	if (nThreads < 1 || nThreads > MAXIMUM_WAIT_OBJECTS)
	{
		_stprintf_s(szMsg, 256, _T("Must have between 1 and %d threads."), MAXIMUM_WAIT_OBJECTS);
		MessageBox(szMsg, _T("Error"), 0);
		return 0;
	}

	// Clear text first so we know when it's finished
	SetDlgItemText(IDC_MESSAGE, _T(""));
	ReadRecords(nThreads, &dwTime, &dwRows);

	_stprintf_s(szMsg, 256, _T("%d records in %ld ms"), dwRows, dwTime);
	SetDlgItemText(IDC_MESSAGE, szMsg);

	return 0;
}

LRESULT CMultiDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}
