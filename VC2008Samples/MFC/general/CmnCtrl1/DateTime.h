// DateTime.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
#if !defined(AFX_DATETIME_H__39010224_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_)
#define AFX_DATETIME_H__39010224_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CDateTimePage dialog

class CDateTimePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDateTimePage)

// Construction
public:
	void OnDTNotify(NMHDR *pHdr, LRESULT *pRes);
	CListBox m_lbNotifyList;
	UINT m_nPrevStyle;
	void SetCheck(UINT idBtn);
	CDateTimeCtrl m_DateTime;
	CDateTimePage();
	~CDateTimePage();

// Dialog Data
	//{{AFX_DATA(CDateTimePage)
	enum { IDD = IDD_DATETIME };
	BOOL    m_bAppCanParse;
	BOOL    m_bShowNone;
	BOOL    m_bUpDown;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDateTimePage)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDateTimePage)
	virtual BOOL OnInitDialog();
	afx_msg void OnCkupdown();
	afx_msg void OnCktimeformat();
	afx_msg void OnCkshortdateformat();
	afx_msg void OnCkshownone();
	afx_msg void OnCklongdateformat();
	afx_msg void OnCkappcanparse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATETIME_H__39010224_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_)
