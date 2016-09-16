// btnppg.cpp : Implementation of the CButtonPropPage property page class.
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
#include "button.h"
#include "btnppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CButtonPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CButtonPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CButtonPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CButtonPropPage, "BUTTON.ButtonPropPage.1",
	0x4a8c9993, 0x7713, 0x101b, 0xa5, 0xa1, 0x4, 0x2, 0x1c, 0x0, 0x94, 0x2)


/////////////////////////////////////////////////////////////////////////////
// CButtonPropPage::CButtonPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CButtonPropPage

BOOL CButtonPropPage::CButtonPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_BUTTON_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonPropPage::CButtonPropPage - Constructor

CButtonPropPage::CButtonPropPage() :
	COlePropertyPage(IDD, IDS_BUTTON_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CButtonPropPage)
	m_Caption = _T("");
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CButtonPropPage::DoDataExchange - Moves data between page and properties

void CButtonPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CButtonPropPage)
	DDP_Text(pDX, IDC_CAPTIONEDIT, m_Caption, _T("Caption") );
	DDX_Text(pDX, IDC_CAPTIONEDIT, m_Caption);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonPropPage message handlers
