// searchbx.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "docktool.h"
#include "searchbx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchBox

CSearchBox::CSearchBox()
{
}

CSearchBox::~CSearchBox()
{
}

BEGIN_MESSAGE_MAP(CSearchBox, CComboBox)
	//{{AFX_MSG_MAP(CSearchBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchBox message handlers

BOOL CSearchBox::PreTranslateMessage(MSG* pMsg)
{
	if ((pMsg->message != WM_KEYDOWN) || (pMsg->wParam != VK_RETURN))
		return CComboBox::PreTranslateMessage(pMsg);

	// when the enter key is hit in the ComboBox we want to add the string
	// to the top of the list and hilight it.  We also want to limit the
	// list to the last 15 entries.
	if ((pMsg->lParam & 0x40000000) == 0)   // Not a repeat.
	{
		CString strText;
		GetWindowText(strText);
		InsertString(0, strText);
		SetCurSel(0);
		if (GetCount() > 15)
			DeleteString(GetCount()-1);
	}
	return TRUE;
}
