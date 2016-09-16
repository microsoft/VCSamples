// MonthCalPage.h : header file for the CMNCTRL1 application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.



#if !defined(AFX_MONTHCALPAGE_H__39010223_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_)
#define AFX_MONTHCALPAGE_H__39010223_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CMonthCalPage dialog

class CMonthCalPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CMonthCalPage)

// Construction
public:
	void HandleSelChange(NMHDR *pHdr, LRESULT *pRes);
	void HandleSelect(NMHDR *pHdr, LRESULT *pRes);
	void GetDayState(NMHDR *pHdr, LRESULT *pRes);
	CMonthCalPage();
	~CMonthCalPage();
	CMonthCalCtrl m_MonthCal;
// Dialog Data
	//{{AFX_DATA(CMonthCalPage)
	enum { IDD = IDD_MONTHCAL };
	CEdit   m_edMaxSel;
	CListBox    m_NotifyList;
	UINT    m_nMaxSelCount;
	CString m_pszRange;
	CString m_pszSelection;
	BOOL    m_bDayState;
	BOOL    m_bNoToday;
	BOOL    m_bNoTodayCircle;
	BOOL    m_bWeekNumbers;
	BOOL    m_bMultiSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMonthCalPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CMonthCalPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnCknotoday();
	afx_msg void OnCknotodaycircle();
	afx_msg void OnCkweeknumbers();
	afx_msg void OnCmultiselect();
	afx_msg void OnChangeEdselrange();
	afx_msg void OnCkdaystate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONTHCALPAGE_H__39010223_ECB6_11D0_8FEA_00A0C9034892__INCLUDED_)
