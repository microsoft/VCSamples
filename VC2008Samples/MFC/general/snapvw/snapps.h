// File: snapps.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_SNAPPS_H__E2FD70FC_605F_11D1_A346_00C04FD91807__INCLUDED_)
#define AFX_SNAPPS_H__E2FD70FC_605F_11D1_A346_00C04FD91807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SnapPs.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSnapPropertySheet

class CSnapPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSnapPropertySheet)

// Construction
public:
	CSnapPropertySheet() : CPropertySheet() { }
	CSnapPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSnapPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapPropertySheet)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnapPropertySheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSnapPropertySheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAPPS_H__E2FD70FC_605F_11D1_A346_00C04FD91807__INCLUDED_)
