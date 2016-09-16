// ThelpPpg.cpp : Implementation of the CTesthelpPropPage property page class.

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "testhelp.h"
#include "ThelpPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTesthelpPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTesthelpPropPage, COlePropertyPage)
	 //{{AFX_MSG_MAP(CTesthelpPropPage)
	ON_BN_CLICKED(IDC_USETOOLTIP, OnUsetooltipClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTesthelpPropPage, "TESTHELP.TesthelpPropPage.1",
	0x31a2b284, 0x8c11, 0x11cf, 0xb3, 0x7f, 0, 0xaa, 0, 0xb9, 0x2b, 0x50)


/////////////////////////////////////////////////////////////////////////////
// CTesthelpPropPage::CTesthelpPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTesthelpPropPage

BOOL CTesthelpPropPage::CTesthelpPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TESTHELP_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpPropPage::CTesthelpPropPage - Constructor

CTesthelpPropPage::CTesthelpPropPage() :
	 COlePropertyPage(IDD, IDS_TESTHELP_PPG_CAPTION)
{
	 //{{AFX_DATA_INIT(CTesthelpPropPage)
	 m_szName1 = _T("");
	 m_szName2 = _T("");
	 m_szName3 = _T("");
	 m_bUseMine = FALSE;
	 m_szTipCaption = _T("");
	 m_bUseToolTip = FALSE;
	m_nUsePopupHelp = -1;
	//}}AFX_DATA_INIT

// Calling SetHelpInfo will set up the proper variables of COlePropertyPage
// so that when someone connects to our IPropertyPage and calls
// IPropertyPage::GetPageInfo the correct help information will be supplied.
SetHelpInfo(_T("Names to appear in the control"),
			   _T("TESTHELP.CHM"),
			   0);

}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpPropPage::DoDataExchange - Moves data between page and properties

void CTesthelpPropPage::DoDataExchange(CDataExchange* pDX)
{
	 //{{AFX_DATA_MAP(CTesthelpPropPage)
	 DDX_Control(pDX, IDC_TIPCAPTION, m_CtrlTipCaption);
	DDP_Text(pDX, IDC_NAME1, m_szName1, _T("Name1") );
	DDX_Text(pDX, IDC_NAME1, m_szName1);
	DDP_Text(pDX, IDC_NAME2, m_szName2, _T("Name2") );
	DDX_Text(pDX, IDC_NAME2, m_szName2);
	DDP_Text(pDX, IDC_NAME3, m_szName3, _T("Name3") );
	DDX_Text(pDX, IDC_NAME3, m_szName3);
	DDP_Check(pDX, IDC_USEMINE, m_bUseMine, _T("UseMyHelp") );
	DDX_Check(pDX, IDC_USEMINE, m_bUseMine);
	DDP_Text(pDX, IDC_TIPCAPTION, m_szTipCaption, _T("ToolTipText") );
	DDX_Text(pDX, IDC_TIPCAPTION, m_szTipCaption);
	DDP_Check(pDX, IDC_USETOOLTIP, m_bUseToolTip, _T("ShowToolTip") );
	DDX_Check(pDX, IDC_USETOOLTIP, m_bUseToolTip);
	DDP_Radio(pDX, IDC_POPUPHELP, m_nUsePopupHelp, _T("UsePopupHelp") );
	DDX_Radio(pDX, IDC_POPUPHELP, m_nUsePopupHelp);
	//}}AFX_DATA_MAP
	 DDP_PostProcessing(pDX);
}



/////////////////////////////////////////////////////////////////////////////
// CTesthelpPropPage message handlers

BOOL CTesthelpPropPage::OnInitDialog()
{
	 COlePropertyPage::OnInitDialog();

	 // enable or disable the ToolTip caption edit control
	 m_CtrlTipCaption.EnableWindow(m_bUseToolTip);

	 return FALSE;  // return TRUE unless you set the focus to a control
				   // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CTesthelpPropPage::OnHelp(LPCTSTR)
{
	// OnHelp is called by IPropertyPage::Help.  When someone requests
	// it, we supply help by calling CWinApp::HtmlHelp
	AfxGetApp()->HtmlHelp((DWORD_PTR)(_T("IDH_PROPERTIES.htm")), HH_DISPLAY_TOPIC);

	return TRUE;
}




void CTesthelpPropPage::OnUsetooltipClicked()
{
	 //Enable or disable the ToolTip caption window.
	 UpdateData(TRUE);
	 m_CtrlTipCaption.EnableWindow(m_bUseToolTip);

}
