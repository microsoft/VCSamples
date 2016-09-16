// timeppg.cpp : Implementation of the CTimePropPage property page class.
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
#include "time.h"
#include "timeppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTimePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTimePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTimePropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTimePropPage, "TIME.TimePropPage.1",
	0x37446b93, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::CTimePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTimePropPage

BOOL CTimePropPage::CTimePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TIME_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::CTimePropPage - Constructor

CTimePropPage::CTimePropPage() :
	COlePropertyPage(IDD, IDS_TIME_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTimePropPage)
	m_Enabled = FALSE;
	m_Interval = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage::DoDataExchange - Moves data between page and properties

void CTimePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTimePropPage)
	DDP_Check(pDX, IDC_ENABLEDCHECK, m_Enabled, _T("Enabled"));
	DDX_Check(pDX, IDC_ENABLEDCHECK, m_Enabled);
	DDP_Text(pDX, IDC_INTERVALEDIT, m_Interval, _T("Interval"));
	DDX_Text(pDX, IDC_INTERVALEDIT, m_Interval);
	DDV_MinMaxInt(pDX, m_Interval, 1, 32767);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTimePropPage message handlers
