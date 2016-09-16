// ThelpPpg.h : Declaration of the CTesthelpPropPage property page class.

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

////////////////////////////////////////////////////////////////////////////
// CTesthelpPropPage : See ThelpPpg.cpp for implementation.

class CTesthelpPropPage : public COlePropertyPage
{
	 DECLARE_DYNCREATE(CTesthelpPropPage)
	 DECLARE_OLECREATE_EX(CTesthelpPropPage)

// Constructor
public:
	 CTesthelpPropPage();

	 BOOL OnHelp(LPCTSTR helpdir);

// Dialog Data
	 //{{AFX_DATA(CTesthelpPropPage)
	enum { IDD = IDD_PROPPAGE_TESTHELP };
	 CEdit     m_CtrlTipCaption;
	 CString     m_szName1;
	 CString     m_szName2;
	 CString     m_szName3;
	 BOOL     m_bUseMine;
	 CString     m_szTipCaption;
	 BOOL     m_bUseToolTip;
	 int        m_nUsePopupHelp;
	//}}AFX_DATA

// Implementation
protected:
	 virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	 //{{AFX_MSG(CTesthelpPropPage)
	 virtual BOOL OnInitDialog();
	afx_msg void OnUsetooltipClicked();
	//}}AFX_MSG
	 DECLARE_MESSAGE_MAP()

};
