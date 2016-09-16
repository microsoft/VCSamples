// WndList.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/*****************************************************************************
  Purpose:
	Interface of CWndListDlg, the main dialog window for the application.

  Functions:
	CWndListDlg::CWndListDlg()          -- constructor
	CWndListDlg::Create()               -- create dialog window
	CWndListDlg::DoDataExchange()       -- dialog data exchange/validation
	CWndListDlg::OnClose()              -- WM_CLOSE handler
	CWndListDlg::OnInitDialog()         -- initialize dialog
	CWndListDlg::OnOptionNow()          -- handle "Options!Update Now"
	CWndListDlg::OnOptionRate()         -- handle "Options!Update Interval"
	CWndListDlg::OnSelChangeWndList()   -- update dlg on list selection change
	CWndListDlg::OnTimer()              -- WM_TIMER handler
	CWndListDlg::OnUpdateOptionRate()   -- set "Options!Update Interval" status
	CWndListDlg::OnUpdateTime()         -- update status bar clock
	CWndListDlg::WalkWindowList()       -- enumerate windows

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __WNDLIST_H__
#define __WNDLIST_H__

#include "mdlsmain.h"

class CWndListDlg : public CModelessMain
{
private:
	using CModelessMain::Create;

// Construction
public:
	CWndListDlg();
	BOOL Create();

// Dialog Data
protected:
	//{{AFX_DATA(CWndListDlg)
	enum { IDD = IDR_MAIN };
	CListBox    m_lbWindows;
	//}}AFX_DATA

	UINT    m_nIDTimer;
	UINT    m_iRate;
	UINT    m_iTicks;

// Overrides
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

// Implementation
protected:
	void WalkWindowList();

	// Generated message map functions
	//{{AFX_MSG(CWndListDlg)
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSelChangeWndList();
	afx_msg void OnOptionNow();
	afx_msg void OnOptionRate();
	afx_msg void OnUpdateOptionRate(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnUpdateTime(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#endif //__WNDLIST_H__
