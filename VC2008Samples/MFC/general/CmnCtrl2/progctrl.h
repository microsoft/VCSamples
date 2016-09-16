// ProgCtrl.h : header file
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
// CProgCtrlPage dialog
#ifndef INC_PROGCTRL_H
#define INC_PROGCTRL_H

class CProgCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CProgCtrlPage)

// Construction
public:
	CProgCtrlPage();
	~CProgCtrlPage();

// Dialog Data
	//{{AFX_DATA(CProgCtrlPage)
	enum { IDD = IDD_PROGCTRL };
	int     m_iDelta;
	UINT    m_uiStep;
	UINT    m_uiRangeFrom;
	UINT    m_uiPos;
	UINT    m_uiRangeTo;
	BOOL    m_bVertical;
	BOOL    m_bSmooth;
	//}}AFX_DATA
	CProgressCtrl   m_Progress;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CProgCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgCtrlPage)
	afx_msg void OnProgressStepit();
	afx_msg void OnSetpos();
	afx_msg void OnProgressSetdelta();
	afx_msg void OnFrom();
	afx_msg void OnTo();
	afx_msg void OnStep();
	afx_msg void OnStyleChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif
