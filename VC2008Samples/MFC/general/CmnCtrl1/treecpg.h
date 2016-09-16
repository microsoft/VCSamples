// TreeCtrlPage.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlPage dialog
#ifndef INC_TRCPAGE_H
#define INC_TRCPAGE_H

#include "mtreectl.h"
#include "notifwdw.h"

class CTreeCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTreeCtrlPage)

// Construction
public:
	CTreeCtrlPage();
	~CTreeCtrlPage();

// Dialog Data
	//{{AFX_DATA(CTreeCtrlPage)
	enum { IDD = IDD_TREECTRL };
	CNotifyShowCase m_notifshowcase;
	CMyTreeCtrl m_mytreectrl;
	BOOL    m_bDisableDragDrop;
	BOOL    m_bHasButtons;
	BOOL    m_bHasLines;
	BOOL    m_bLinesAtRoot;
	BOOL    m_bEditLabels;
	BOOL    m_bShowSelAlways;
	CString m_cstrStatus;
	BOOL    m_bSingleExpand;
	//}}AFX_DATA


	HTREEITEM   m_rghItem[12];
	HTREEITEM   m_hitemDrag;
	HTREEITEM   m_hitemDrop;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	// Generated message map functions
	//{{AFX_MSG(CTreeCtrlPage)
	afx_msg void OnEditLabels();
	afx_msg void OnHasButtons();
	afx_msg void OnHasLines();
	afx_msg void OnLinesAtRoot();
	afx_msg void OnDisabledDragDrop();
	afx_msg void OnShowSelAlways();
	afx_msg void ShowNotification(LPNMHDR pnmhdr, LRESULT *pLResult);
	afx_msg void OnSingleExpand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif
