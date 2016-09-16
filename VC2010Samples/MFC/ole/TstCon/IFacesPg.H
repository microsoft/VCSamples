// File: IFacesPg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CINTERFACESPAGE_H__D2C50BD0_C64C_11D0_8E02_00C04FB68D60__INCLUDED_)
#define AFX_CINTERFACESPAGE_H__D2C50BD0_C64C_11D0_8E02_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CInterfacesPage.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInterfacesPage dialog

class CInterfacesPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CInterfacesPage)

// Construction
public:
	CInterfacesPage();
	~CInterfacesPage();

// Dialog Data
	//{{AFX_DATA(CInterfacesPage)
	enum { IDD = IDD_CONTAINEROPTIONS_INTERFACES };
	BOOL    m_tIOleInPlaceSiteWindowless;
	BOOL    m_tIOleInPlaceSiteEx;
	BOOL    m_tIAdviseSinkEx;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CInterfacesPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CInterfacesPage)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CINTERFACESPAGE_H__D2C50BD0_C64C_11D0_8E02_00C04FB68D60__INCLUDED_)
