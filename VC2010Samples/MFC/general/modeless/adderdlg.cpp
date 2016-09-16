// AdderDlg.cpp : implementation file
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
#include "modeless.h"
#include "AdderDlg.h"
#include "modeldlg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdderDialog dialog


CAdderDialog::CAdderDialog(CWnd* pParent)
	: CDialog(CAdderDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdderDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	ASSERT(pParent != NULL);

	m_pParent = pParent;
	m_nID = CAdderDialog::IDD;
}

void CAdderDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdderDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdderDialog, CDialog)
	//{{AFX_MSG_MAP(CAdderDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CAdderDialog message handlers

void CAdderDialog::OnOK()
{
	CEdit* pEdit = (CEdit*) GetDlgItem(IDC_NEWTEXT);
	CListBox* pList = (CListBox*) (m_pParent->GetDlgItem(IDC_LIST));

	ASSERT(pList != NULL);
	ASSERT(pEdit != NULL);

	if (pList != NULL && pEdit != NULL)
	{
		CString str;
		pEdit->GetWindowText(str);
		pList->AddString(str);
	}
}

BOOL CAdderDialog::Create()
{
	return CDialog::Create(m_nID, m_pParent);
}

void CAdderDialog::OnCancel()
{
	((CMainDlg*)m_pParent)->BoxDone();
	DestroyWindow();
}

void CAdderDialog::PostNcDestroy()
{
	delete this;
}
