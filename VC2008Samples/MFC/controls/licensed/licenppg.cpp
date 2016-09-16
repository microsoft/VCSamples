// licenppg.cpp : Implementation of the CLicensedPropPage property page class.
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
#include "licensed.h"
#include "licenppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLicensedPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLicensedPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CLicensedPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLicensedPropPage, "LICENSED.LicensedPropPage.1",
	0x37446b82, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CLicensedPropPage::CLicensedPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CLicensedPropPage

BOOL CLicensedPropPage::CLicensedPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LICENSED_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedPropPage::CLicensedPropPage - Constructor

CLicensedPropPage::CLicensedPropPage() :
	COlePropertyPage(IDD, IDS_LICENSED_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CLicensedPropPage)
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedPropPage::DoDataExchange - Moves data between page and properties

void CLicensedPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CLicensedPropPage)
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedPropPage message handlers
