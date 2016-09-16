// File: ConInfDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CCONTAINERINFODLG_H__D2C50BD1_C64C_11D0_8E02_00C04FB68D60__INCLUDED_)
#define AFX_CCONTAINERINFODLG_H__D2C50BD1_C64C_11D0_8E02_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CContainerInfoDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContainerInfoDlg dialog

class CContainerInfoDlg : public CDialog
{
// Construction
public:
	CContainerInfoDlg( CWnd* pParent, CTestContainer98Doc* pDoc );

// Dialog Data
	//{{AFX_DATA(CContainerInfoDlg)
	enum { IDD = IDD_CONTAINERINFO };
	CListCtrl   m_listObjects;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContainerInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   CTestContainer98Doc* m_pDoc;

	// Generated message map functions
	//{{AFX_MSG(CContainerInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CCONTAINERINFODLG_H__D2C50BD1_C64C_11D0_8E02_00C04FB68D60__INCLUDED_)
