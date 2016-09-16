// File: PChngPg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_PROPERTYCHANGESPAGE_H__CAC42501_E29A_11D0_8E15_00C04FB68D60__INCLUDED_)
#define AFX_PROPERTYCHANGESPAGE_H__CAC42501_E29A_11D0_8E15_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropertyChangesPage.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyChangesPage dialog

class CPropertyChangesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropertyChangesPage)

// Construction
public:
	CPropertyChangesPage();
	~CPropertyChangesPage();

// Dialog Data
	//{{AFX_DATA(CPropertyChangesPage)
	enum { IDD = IDD_CONTROLLOGGING_PROPERTYCHANGES };
	CCheckListBox   m_lbProperties;
	//}}AFX_DATA

   CStringArray m_astrPropertyNames;
   CUIntArray m_atLogFlags;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropertyChangesPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPropertyChangesPage)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYCHANGESPAGE_H__CAC42501_E29A_11D0_8E15_00C04FB68D60__INCLUDED_)
