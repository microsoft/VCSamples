// SlidCtrl.h : header file
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
// CSliderCtrlPage dialog
#ifndef INC_SLIDCTRL_H
#define INC_SLIDCTRL_H

class CSliderCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSliderCtrlPage)

// Construction
public:
	CSliderCtrlPage();
	~CSliderCtrlPage();

// Dialog Data
	//{{AFX_DATA(CSliderCtrlPage)
	enum { IDD = IDD_SLIDERCTRL };
	CStatic m_Notifications;
	BOOL    m_bAutoticks;
	BOOL    m_bEnablesel;
	BOOL    m_bFixed;
	UINT    m_uiLine;
	BOOL    m_bNothumb;
	BOOL    m_bNoticks;
	int     m_iOrientation;
	UINT    m_uiPage;
	int     m_iTickpos;
	UINT    m_uiRangeFrom;
	UINT    m_uiRangeTo;
	UINT    m_uiSelRangeFrom;
	UINT    m_uiSelRangeTo;
	UINT    m_uiTickFreq;
	//}}AFX_DATA

	CSliderCtrl m_Slider;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSliderCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ChangeCtrlStyle(long lStyle,BOOL bSetBit=TRUE);

	// Generated message map functions
	//{{AFX_MSG(CSliderCtrlPage)
	afx_msg void OnAutoticks();
	afx_msg void OnTickfreq();
	afx_msg void OnNoticks();
	afx_msg void OnNothumb();
	afx_msg void OnFixed();
	afx_msg void OnEnablesel();
	afx_msg void OnLine();
	afx_msg void OnPage();
	afx_msg void OnRangefrom();
	afx_msg void OnRangeto();
	afx_msg void OnOrientation();
	afx_msg void OnPoint();
	afx_msg void OnSelrangefrom();
	afx_msg void OnSelrangeto();
//  afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif
