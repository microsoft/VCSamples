// palppg.cpp : Implementation of the CPalPropPage property page class.
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
#include "pal.h"
#include "palppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CPalPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPalPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CPalPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPalPropPage, "PAL.PalPropPage.1",
	0x37446b85, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CPalPropPage::CPalPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CPalPropPage

BOOL CPalPropPage::CPalPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_PAL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CPalPropPage::CPalPropPage - Constructor

CPalPropPage::CPalPropPage() :
	COlePropertyPage(IDD, IDS_PAL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CPalPropPage)
	m_Length = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CPalPropPage::DoDataExchange - Moves data between page and properties

void CPalPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CPalPropPage)
	DDP_Text(pDX, IDC_LENGTHEDIT, m_Length, _T("Length"));
	DDX_Text(pDX, IDC_LENGTHEDIT, m_Length);
	DDV_MinMaxInt(pDX, m_Length, 1, 255);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CPalPropPage message handlers
