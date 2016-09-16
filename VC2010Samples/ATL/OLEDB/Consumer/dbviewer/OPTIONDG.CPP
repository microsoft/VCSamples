// OptionsDlg.cpp : implementation file
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
#include "OptionDg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg property page

IMPLEMENT_DYNCREATE(COptionsDlg, CPropertyPage)

COptionsDlg::COptionsDlg() : CPropertyPage(COptionsDlg::IDD)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_bOpenODBC = FALSE;
	m_bShowSystemObjects = FALSE;
	m_bShowWarnings = FALSE;
	m_nMaxRecords = 0;
	//}}AFX_DATA_INIT
}

COptionsDlg::~COptionsDlg()
{
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Check(pDX, IDC_BOPENODBC, m_bOpenODBC);
	DDX_Check(pDX, IDC_BSYSTEMOBJECTS, m_bShowSystemObjects);
	DDX_Check(pDX, IDC_BWARNINGS, m_bShowWarnings);
	DDX_Text(pDX, IDC_MAXRECS, m_nMaxRecords);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers
