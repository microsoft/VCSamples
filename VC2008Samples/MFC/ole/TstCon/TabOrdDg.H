// File: TabOrdDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_TABORDERDLG_H__E042BBA9_E1E9_11D0_8E14_00C04FB68D60__INCLUDED_)
#define AFX_TABORDERDLG_H__E042BBA9_E1E9_11D0_8E14_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TabOrderDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabOrderDlg dialog

class CTabOrderDlg : public CDialog
{
// Construction
public:
	CTabOrderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTabOrderDlg)
	enum { IDD = IDD_TABORDER };
	CDragListBox    m_lboxTabOrder;
	//}}AFX_DATA

   CTypedPtrList< CObList, CTestContainer98Item* > m_lpTabOrder;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabOrderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabOrderDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABORDERDLG_H__E042BBA9_E1E9_11D0_8E14_00C04FB68D60__INCLUDED_)
