// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "DlgToolTips.h"
#include "CustomToolTipCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomToolTipCtrl

CCustomToolTipCtrl::CCustomToolTipCtrl()
{
	m_nCurrID = 0;
}

CCustomToolTipCtrl::~CCustomToolTipCtrl()
{
}


BEGIN_MESSAGE_MAP(CCustomToolTipCtrl, CMFCToolTipCtrl)
	ON_NOTIFY_REFLECT(TTN_SHOW, OnShow)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomToolTipCtrl message handlers

void CCustomToolTipCtrl::OnShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_nCurrID = CWnd::FromHandle ((HWND)pNMHDR->idFrom)->GetDlgCtrlID ();

	switch (m_nCurrID)
	{
	case IDOK:
		SetDescription (_T("OK Button description..."));
		break;

	case IDCANCEL:
		SetDescription (_T("Cancel Button description..."));
		break;

	default:
		SetDescription (_T (""));
	}

	CMFCToolTipCtrl::OnShow (pNMHDR, pResult);
}

BOOL CCustomToolTipCtrl::OnDrawIcon (CDC* pDC, CRect rectImage)
{
	UINT uiBmpResID = 0;

	switch (m_nCurrID)
	{
	case IDOK:
		uiBmpResID = IDB_OK;
		break;

	case IDCANCEL:
		uiBmpResID = IDB_CANCEL;
		break;
	}

	if (uiBmpResID == 0)
	{
		return FALSE;
	}

	CMFCToolBarImages image;
	image.Load (uiBmpResID);
	image.SetSingleImage ();
	image.DrawEx (pDC, rectImage, 0);

	return TRUE;
}
