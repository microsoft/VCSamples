// DlgSQL.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "DBViewer.h"
#include "DlgSQL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSQL dialog


CDlgSQL::CDlgSQL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSQL::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSQL)
	m_strSQL = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSQL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSQL)
	DDX_Text(pDX, IDC_EDITSQL, m_strSQL);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSQL, CDialog)
	//{{AFX_MSG_MAP(CDlgSQL)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSQL message handlers
