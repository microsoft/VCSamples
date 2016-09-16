// File: NewAPDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_NEWAMBIENTPROPERTYDLG_H__D59AF2B5_FE12_11D0_8E2A_00C04FB68D60__INCLUDED_)
#define AFX_NEWAMBIENTPROPERTYDLG_H__D59AF2B5_FE12_11D0_8E2A_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NewAmbientPropertyDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewAmbientPropertyDlg dialog

class CNewAmbientPropertyDlg : public CDialog
{
// Construction
public:
	CNewAmbientPropertyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewAmbientPropertyDlg)
	enum { IDD = IDD_NEWAMBIENTPROPERTY };
	CEdit   m_editName;
	int     m_dispid;
	CString m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewAmbientPropertyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewAmbientPropertyDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWAMBIENTPROPERTYDLG_H__D59AF2B5_FE12_11D0_8E2A_00C04FB68D60__INCLUDED_)
