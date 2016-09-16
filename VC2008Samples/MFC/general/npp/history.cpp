// history.cpp : implementation of the CHistoryList class
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
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"
#include "finddlg.h"
#include <afxcoll.h>

void CHistoryList::FillCombobox()
{
	CNotepadView* pView = GetApplicationView();
	CWnd* pWnd = pView->m_pFindDialog->GetDlgItem(IDC_COMBO1);
	ASSERT_VALID(pWnd);

	POSITION pos = GetHeadPosition();
	while(pos)
		pWnd->SendMessage(CB_ADDSTRING, 0, (LPARAM)((LPCTSTR)GetNext(pos)));
}


BOOL CHistoryList::AddString(CString &s1)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CWnd* pWnd = &pFrame->m_wndToolBar.m_toolBarCombo;
	ASSERT_VALID(pWnd);

	if (!s1.GetLength())
		return FALSE;

	POSITION pos = Find(s1);
	INT_PTR nCount = GetCount();

	if (pos == NULL)
	{
		// if list is full, remove from the end
		if (nCount == HISTORY_COUNT)
		{
			RemoveTail();
			pWnd->SendMessage(CB_DELETESTRING, nCount-1);
		}

		AddHead(s1);
		pWnd->SendMessage(CB_INSERTSTRING, 0, (LPARAM)((LPCTSTR)s1));
	}
	else
	{
		SwapStrings(pWnd, s1);
	}

	return TRUE;
}

void CHistoryList::SwapStrings(CWnd* pWnd, CString &s1)
{
	// swap internal list items
	POSITION pos = GetHeadPosition();
	ASSERT(pos != NULL);

	CString s2;
	INT_PTR nCount = GetCount();
	int idx=0;

	// Note: combo-box find is not case-sensitive
	do
	{
		s2 = GetNext(pos);
	} while(idx < nCount && s1 != s2 && ++idx);


	// swap internal list
	pos = FindIndex(idx);
	ASSERT(pos != NULL);
	RemoveAt(pos);
	AddHead(s2);

	// swap combo box item with combo's edit control
	pWnd->SendMessage(CB_DELETESTRING, idx);
	pWnd->SendMessage(CB_SETCURSEL, pWnd->SendMessage(CB_INSERTSTRING, 0, (LPARAM)((LPCTSTR)s1)));
}
