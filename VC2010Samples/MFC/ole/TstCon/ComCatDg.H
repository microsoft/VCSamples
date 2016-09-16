// File: ComCatDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_COMPONENTCATEGORIESDLG_H__B1590DF0_0783_11D1_8E2E_00C04FB68D60__INCLUDED_)
#define AFX_COMPONENTCATEGORIESDLG_H__B1590DF0_0783_11D1_8E2E_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ComponentCategoriesDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComponentCategoriesDlg dialog

class CComponentCategoriesDlg : public CDialog
{
// Construction
public:
	CComponentCategoriesDlg( UINT idCaption, CWnd* pParent = NULL );

// Dialog Data
	//{{AFX_DATA(CComponentCategoriesDlg)
	enum { IDD = IDD_COMPONENTCATEGORIES };
	CCheckListBox   m_lbCategories;
	//}}AFX_DATA

   UINT m_idCaption;
   CList< CATID, CATID& > m_lSelectedCategories;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComponentCategoriesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   ICatInformationPtr m_pCatInfo;
   CArray< CATID, CATID& > m_aAvailableCategories;

	// Generated message map functions
	//{{AFX_MSG(CComponentCategoriesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelectAll();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTCATEGORIESDLG_H__B1590DF0_0783_11D1_8E2E_00C04FB68D60__INCLUDED_)
