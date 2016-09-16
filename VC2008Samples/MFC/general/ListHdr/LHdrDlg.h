// LHdrDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_ListHdrDLG_H__31281828_D350_11D0_8286_00C04FD73634__INCLUDED_)
#define AFX_ListHdrDLG_H__31281828_D350_11D0_8286_00C04FD73634__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "mlistctl.h"

/////////////////////////////////////////////////////////////////////////////
// CListHdrDlg dialog

class CListHdrDlg : public CDialog
{
// Construction
public:
	CListHdrDlg(CWnd* pParent = NULL);  // standard constructor
	~CListHdrDlg();

// Dialog Data
	//{{AFX_DATA(CListHdrDlg)
	enum { IDD = IDD_LISTHDR_DIALOG };
//  CListCtrl   m_listctrl;
	CMyListCtrl m_listctrl;
	BOOL    m_bNoLabelWrap;
	BOOL    m_bAutoArrange;
	BOOL    m_bSingleSel;
	BOOL    m_bEditLabels;
	BOOL    m_bNoColHdr;
	BOOL    m_bNoSortHdr;
	CString m_strViewMode;
	CString m_strAlignMode;
	CString m_strSortMode;
	BOOL    m_bHoverSelect;
	BOOL    m_bWorkAreas;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListHdrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList * m_pImageHdrSmall;
	CImageList * m_pImageList;
	CImageList * m_pImageListSmall;
	void ModifyHeaderItems();
	void FillListCtrl();
	void RenewListCtrl(DWORD dwStyle, BOOL bSetBits);
	void ChangeListCtrlStyle(DWORD dwStyle, BOOL bSetBits);
	BOOL m_bHotCursor;
	HCURSOR m_hStdHotCursor;
	HCURSOR m_hMyHotCursor;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListHdrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNoLabelWrap();
	afx_msg void OnAutoArrange();
	afx_msg void OnEditLabels();
	afx_msg void OnNoColHdr();
	afx_msg void OnNoSortHdr();
	afx_msg void OnSingleSel();
	afx_msg void OnChangeAlign();
	afx_msg void OnChangeView();
	afx_msg void OnHover();
	afx_msg void OnMyHotCur();
	afx_msg void OnChangeSort();
	afx_msg void OnWorkAreas();
	afx_msg void OnStdHotCur();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ListHdrDLG_H__31281828_D350_11D0_8286_00C04FD73634__INCLUDED_)
