// BkfstPg.cpp : implementation file
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
#include "BkfstPg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBkfstPage property page

IMPLEMENT_DYNCREATE(CBkfstPage, CPropertyPage)

CBkfstPage::CBkfstPage() : CPropertyPage(CBkfstPage::IDD)
{
	//{{AFX_DATA_INIT(CBkfstPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CBkfstPage::~CBkfstPage()
{
}

void CBkfstPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBkfstPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBkfstPage, CPropertyPage)
	//{{AFX_MSG_MAP(CBkfstPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBkfstPage message handlers

BOOL CBkfstPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CButton* pBevButton;
	pBevButton = (CButton*) GetDlgItem(IDC_HOT_TEA);
	pBevButton->SetCheck(1);

	CButton* pStyleButton;
	pStyleButton = (CButton*) GetDlgItem(IDC_CONTINENTAL2);
	pStyleButton->SetCheck(1);

	CButton* pNewsButton;
	pNewsButton = (CButton*) GetDlgItem(IDC_FINANCE);
	pNewsButton->SetCheck(1);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
