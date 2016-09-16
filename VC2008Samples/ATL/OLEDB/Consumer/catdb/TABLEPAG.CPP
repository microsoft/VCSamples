// tablepag.cpp : implementation file
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
#include "CatDB.h"
#include "tablepag.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTablePage property page

IMPLEMENT_DYNCREATE(CTablePage, CPropertyPage)

CTablePage::CTablePage() : CPropertyPage(CTablePage::IDD)
{
	//{{AFX_DATA_INIT(CTablePage)
	m_bSystemTables = FALSE;
	m_bViews = FALSE;
	m_bSynonyms = FALSE;
	//}}AFX_DATA_INIT
}

CTablePage::~CTablePage()
{
}

void CTablePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTablePage)
	DDX_Check(pDX, IDC_SYSTABLES, m_bSystemTables);
	DDX_Check(pDX, IDC_VIEWS, m_bViews);
	DDX_Check(pDX, IDC_ALIAI, m_bSynonyms);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTablePage, CPropertyPage)
	//{{AFX_MSG_MAP(CTablePage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTablePage message handlers
