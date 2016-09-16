// pushppg.cpp : Implementation of the CPushPropPage property page class.
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
#include "push.h"
#include "pushppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CPushPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPushPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CPushPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPushPropPage, "PUSH.PushPropPage.1",
	0x37446b88, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CPushPropPage::CPushPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CPushPropPage

BOOL CPushPropPage::CPushPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_PUSH_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CPushPropPage::CPushPropPage - Constructor

CPushPropPage::CPushPropPage() :
	COlePropertyPage(IDD, IDS_PUSH_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CPushPropPage)
	m_Border = FALSE;
	m_Caption = _T("");
	m_Enabled = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CPushPropPage::DoDataExchange - Moves data between page and properties

void CPushPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CPushPropPage)
	DDP_Check(pDX, IDC_BORDERCHECK, m_Border, _T("BorderStyle"));
	DDX_Check(pDX, IDC_BORDERCHECK, m_Border);
	DDP_Text(pDX, IDC_CAPTIONEDIT, m_Caption, _T("Caption"));
	DDX_Text(pDX, IDC_CAPTIONEDIT, m_Caption);
	DDP_Check(pDX, IDC_ENABLEDCHECK, m_Enabled, _T("Enabled"));
	DDX_Check(pDX, IDC_ENABLEDCHECK, m_Enabled);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CPushPropPage message handlers
