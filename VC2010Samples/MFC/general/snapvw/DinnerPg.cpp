// DinnerPg.cpp : implementation file
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
#include "snapvw.h"
#include "DinnerPg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDinnerPage property page

IMPLEMENT_DYNCREATE(CDinnerPage, CPropertyPage)

CDinnerPage::CDinnerPage() : CPropertyPage(CDinnerPage::IDD)
{
	//{{AFX_DATA_INIT(CDinnerPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDinnerPage::~CDinnerPage()
{
}

void CDinnerPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDinnerPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDinnerPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDinnerPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDinnerPage message handlers

BOOL CDinnerPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO: Add extra initialization here

	CButton* pBevButton;
	pBevButton = (CButton*) GetDlgItem(IDC_COFFEE1);
	pBevButton->SetCheck(1);

	CButton* pFoodButton;
	pFoodButton = (CButton*) GetDlgItem(IDC_ROMANTIC);
	pFoodButton->SetCheck(1);

	CButton* pCompButton;
	pCompButton = (CButton*) GetDlgItem(IDC_NEIGHBOR);
	pCompButton->SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
