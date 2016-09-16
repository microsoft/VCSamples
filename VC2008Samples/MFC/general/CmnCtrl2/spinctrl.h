// SpinCtrl.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrlPage dialog
#ifndef INC_SPINCTRL_H
#define INC_SPINCTRL_H

class CSpinCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSpinCtrlPage)

// Construction
public:
	CSpinCtrlPage();
	~CSpinCtrlPage();

// Dialog Data
	//{{AFX_DATA(CSpinCtrlPage)
	enum { IDD = IDD_SPINCTRL };
	int     m_iAlignment;
	BOOL    m_bArrowkeys;
	BOOL    m_bAutobuddy;
	UINT    m_uiRangeFrom;
	BOOL    m_bNothousands;
	int     m_iOrientation;
	BOOL    m_bSetbuddyint;
	UINT    m_uiRangeTo;
	BOOL    m_bWrap;
	//}}AFX_DATA

	CSpinButtonCtrl m_Spin;
	CRect           m_EditRect;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSpinCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnApply();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void CreateSpinCtrl();

	// Generated message map functions
	//{{AFX_MSG(CSpinCtrlPage)
	afx_msg void OnAnyChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif
