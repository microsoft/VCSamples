// finddlg.cpp : implementation file
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
#include <stddef.h>
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"
#include "finddlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog


CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDlg)
	m_bMatchCase = FALSE;
	m_szText = _T("");
	m_nDirection = 1; // down by default
	//}}AFX_DATA_INIT
}


void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
	DDX_Check(pDX, IDC_CHECK1, m_bMatchCase);
	DDX_CBString(pDX, IDC_COMBO1, m_szText);
	DDX_Radio(pDX, IDC_RADIO1, m_nDirection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	//{{AFX_MSG_MAP(CFindDlg)
	ON_BN_CLICKED(ID_EDIT_FIND_NEXT, OnEditFindNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFindDlg message handlers

void CFindDlg::OnEditFindNext()
{
	// the user selected to search. see if there is a search pattern in the edit control
	// using the default data exchange.
	// if no search string is present, keep the dialog box up.
	UpdateData(TRUE);

	if (!m_szText.GetLength())
	{
		MessageBeep(MB_ICONEXCLAMATION);
		GotoDlgCtrl(GetDlgItem(IDC_COMBO1));
		return ;
	}

	EndDialog(TRUE);
	GetApplicationView()->m_searchHistory.AddString(m_szText);
}

#pragma warning (disable : 4189)
BOOL CFindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* pWnd = GetDlgItem(IDC_COMBO1);
	GetApplicationView()->m_searchHistory.FillCombobox();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
#pragma warning (default: 4189)
