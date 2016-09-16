// xlistppg.cpp : Implementation of the CXlistPropPage property page class.
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
#include "xlist.h"
#include "xlistppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CXlistPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CXlistPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CXlistPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CXlistPropPage, "XLIST.XlistPropPage.1",
	0x37446b9d, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CXlistPropPage::CXlistPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CXlistPropPage

BOOL CXlistPropPage::CXlistPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_XLIST_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistPropPage::CXlistPropPage - Constructor

CXlistPropPage::CXlistPropPage() :
	COlePropertyPage(IDD, IDS_XLIST_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CXlistPropPage)
	m_InvertFlag = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CXlistPropPage::DoDataExchange - Moves data between page and properties

void CXlistPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CXlistPropPage)
	DDP_Check(pDX, IDC_INVERTCHECK, m_InvertFlag, _T("InvertFlag"));
	DDX_Check(pDX, IDC_INVERTCHECK, m_InvertFlag);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistPropPage message handlers
