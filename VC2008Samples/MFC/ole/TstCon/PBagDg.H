// File: PBagDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CPROPERTYBAGDLG_H__5C86BA45_D2DA_11D0_8E0F_00C04FB68D60__INCLUDED_)
#define AFX_CPROPERTYBAGDLG_H__5C86BA45_D2DA_11D0_8E0F_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CPropertyBagDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyBagDlg dialog

class CPropertyBagDlg : public CDialog
{
// Construction
public:
	CPropertyBagDlg( CPropertyBag* pPropertyBag, CWnd* pParent = NULL );

// Dialog Data
	//{{AFX_DATA(CPropertyBagDlg)
	enum { IDD = IDD_PROPERTYBAG };
	CListCtrl   m_lvProperties;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyBagDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   CPropertyBag* m_pPropertyBag;

	// Generated message map functions
	//{{AFX_MSG(CPropertyBagDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPROPERTYBAGDLG_H__5C86BA45_D2DA_11D0_8E0F_00C04FB68D60__INCLUDED_)
