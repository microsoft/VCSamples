// File: InsCtlDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_INSERTCONTROLDLG_H__C6531855_F70A_11D0_8E26_00C04FB68D60__INCLUDED_)
#define AFX_INSERTCONTROLDLG_H__C6531855_F70A_11D0_8E26_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InsertControlDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInsertControlDlg dialog

class CInsertControlDlg : public CDialog
{
// Construction
public:
	CInsertControlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInsertControlDlg)
	enum { IDD = IDD_INSERTCONTROL };
	CStatic m_staticServerPath;
	CButton m_butRequiredCategories;
	CButton m_butIgnoreRequiredCategories;
	CButton m_butOK;
	CListBox    m_lbControls;
	//}}AFX_DATA

   CLSID m_clsid;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   void RefreshControlList();

   ICatInformationPtr m_pCatInfo;
   CArray< CATID, CATID& > m_aImplementedCategories;
   CArray< CATID, CATID& > m_aRequiredCategories;
   CList< CLSID, CLSID& > m_lControls;

	// Generated message map functions
	//{{AFX_MSG(CInsertControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnImplementedCategories();
	afx_msg void OnControlsDblClk();
	afx_msg void OnRequiredCategories();
	afx_msg void OnControlsSelChange();
	afx_msg void OnIgnoreRequiredCategories();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSERTCONTROLDLG_H__C6531855_F70A_11D0_8E26_00C04FB68D60__INCLUDED_)
