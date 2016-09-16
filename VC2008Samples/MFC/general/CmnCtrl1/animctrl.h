// animctrl.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _ANIMCTRL_H
#define _ANIMCTRL_H

/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrlPage dialog

class CAnimateCtrlPage : public CPropertyPage
{
// Construction
public:
	CAnimateCtrlPage();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAnimateCtrlPage)
	enum { IDD = IDD_ANIMCTRL };
	CString m_cstrFileName;
	BOOL m_bCentered;
	BOOL m_bTransparent;
	BOOL m_bAutoplay;
	//}}AFX_DATA
	CAnimateCtrl m_AnimateCtrl;
	CRect m_rectAnimateCtrl;
	DWORD m_dwStyle;   // control styles
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimateCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:

	void ApplyChanges();

	// Generated message map functions
	//{{AFX_MSG(CAnimateCtrlPage)
	afx_msg void OnFileChange();
	afx_msg void OnBrowse();
	afx_msg void OnCenter();
	afx_msg void OnTransparent();
	afx_msg void OnAutoplay();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
