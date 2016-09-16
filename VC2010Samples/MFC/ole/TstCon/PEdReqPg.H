// File: PEdReqPg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_PROPERTYEDITREQUESTSPAGE_H__E3C35167_EC02_11D0_8E1D_00C04FB68D60__INCLUDED_)
#define AFX_PROPERTYEDITREQUESTSPAGE_H__E3C35167_EC02_11D0_8E1D_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PropertyEditRequestsPage.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyEditRequestsPage dialog

class CPropertyEditRequestsPage :
   public CPropertyPage
{
   DECLARE_DYNCREATE( CPropertyEditRequestsPage )

public:
   class CPropertyInfo
   {
   public:
	  CPropertyInfo();
	  CPropertyInfo( LPCTSTR pszName, BOOL tLogged, int iResponse );

   public:
	  CString m_strName;
	  BOOL m_tLogged;
	  int m_iResponse;
   };

// Construction
public:
	CPropertyEditRequestsPage();

// Dialog Data
	//{{AFX_DATA(CPropertyEditRequestsPage)
	enum { IDD = IDD_CONTROLLOGGING_PROPERTYEDITREQUESTS };
	CCheckListBox   m_lbProperties;
	int     m_iAllowEdit;
	//}}AFX_DATA

   CArray< CPropertyInfo, CPropertyInfo& > m_aProperties;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertyEditRequestsPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   int GetSelectionResponse();
   void SetSelectionResponse( int iResponse );

	// Generated message map functions
	//{{AFX_MSG(CPropertyEditRequestsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPropertiesSelChange();
	afx_msg void OnAlways();
	afx_msg void OnNever();
	afx_msg void OnPrompt();
	afx_msg void OnSelectAll();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYEDITREQUESTSPAGE_H__E3C35167_EC02_11D0_8E1D_00C04FB68D60__INCLUDED_)
