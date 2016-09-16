// File: RegCtlDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_REGISTERCONTROLSDLG_H__6E565AF4_D854_11D0_8E11_00C04FB68D60__INCLUDED_)
#define AFX_REGISTERCONTROLSDLG_H__6E565AF4_D854_11D0_8E11_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// RegisterControlsDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegisterControlsDlg dialog

class CRegisterControlsDlg : public CDialog
{
// Construction
public:
	CRegisterControlsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterControlsDlg)
	enum { IDD = IDD_REGISTERCONTROLS };
	CButton m_butReregister;
	CButton m_butUnregister;
	CListCtrl   m_lvRegisteredControls;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterControlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   void RefreshRegisteredControls();
   void UpdateButtons();

	// Generated message map functions
	//{{AFX_MSG(CRegisterControlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnUnregister();
	afx_msg void OnRegisteredControlsItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnReregister();
	afx_msg void OnRegister();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERCONTROLSDLG_H__6E565AF4_D854_11D0_8E11_00C04FB68D60__INCLUDED_)
