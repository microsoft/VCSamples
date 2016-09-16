// spinppg.cpp : Implementation of the CSpindialPropPage property page class.
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
#include "spindial.h"
#include "spinppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CSpindialPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CSpindialPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CSpindialPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSpindialPropPage, "SPINDIAL.SpindialPropPage.1",
	0x37446b8b, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CSpindialPropPage::CSpindialPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CSpindialPropPage

BOOL CSpindialPropPage::CSpindialPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SPINDIAL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialPropPage::CSpindialPropPage - Constructor

CSpindialPropPage::CSpindialPropPage() :
	COlePropertyPage(IDD, IDS_SPINDIAL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CSpindialPropPage)
	m_NeedlePosition = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialPropPage::DoDataExchange - Moves data between page and properties

void CSpindialPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CSpindialPropPage)
	DDP_Text(pDX, IDC_POSITIONEDIT, m_NeedlePosition, _T("NeedlePosition"));
	DDX_Text(pDX, IDC_POSITIONEDIT, m_NeedlePosition);
	DDV_MinMaxInt(pDX, m_NeedlePosition, 0, 3);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialPropPage message handlers
