// LunchPg.cpp : implementation file
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
#include "LunchPg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLunchPage property page

IMPLEMENT_DYNCREATE(CLunchPage, CPropertyPage)

CLunchPage::CLunchPage() : CPropertyPage(CLunchPage::IDD)
{
	//{{AFX_DATA_INIT(CLunchPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLunchPage::~CLunchPage()
{
}

void CLunchPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLunchPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLunchPage, CPropertyPage)
	//{{AFX_MSG_MAP(CLunchPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLunchPage message handlers

BOOL CLunchPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CButton* pBevButton;
	pBevButton = (CButton*) GetDlgItem(IDC_SODA);
	pBevButton->SetCheck(1);

	CButton* pFoodButton;
	pFoodButton = (CButton*) GetDlgItem(IDC_GREASY);
	pFoodButton->SetCheck(1);

	CButton* pMagButton;
	pMagButton = (CButton*) GetDlgItem(IDC_TABLOID);
	pMagButton->SetCheck(1);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
