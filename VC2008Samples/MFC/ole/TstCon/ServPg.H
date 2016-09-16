// File: ServPg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_SERVICESPAGE_H__292403FA_0CFF_11D1_8E2F_00C04FB68D60__INCLUDED_)
#define AFX_SERVICESPAGE_H__292403FA_0CFF_11D1_8E2F_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ServicesPage.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CServicesPage dialog

class CServicesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CServicesPage)

// Construction
public:
	CServicesPage();
	~CServicesPage();

// Dialog Data
	//{{AFX_DATA(CServicesPage)
	enum { IDD = IDD_CONTAINEROPTIONS_SERVICES };
	BOOL    m_tSBindHost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CServicesPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CServicesPage)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVICESPAGE_H__292403FA_0CFF_11D1_8E2F_00C04FB68D60__INCLUDED_)
