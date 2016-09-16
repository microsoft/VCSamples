// gotodlg.cpp : implementation file
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
#include "gotodlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGotoDlg dialog


CGotoDlg::CGotoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGotoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGotoDlg)
	m_nLineNum = 1;
	//}}AFX_DATA_INIT
}


void CGotoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGotoDlg)
	DDX_Text(pDX, IDC_GOTO_LINE, m_nLineNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGotoDlg, CDialog)
	//{{AFX_MSG_MAP(CGotoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CGotoDlg::OnCancel()
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}
