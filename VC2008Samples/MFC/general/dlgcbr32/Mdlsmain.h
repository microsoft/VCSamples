// MdlsMain.h : header file
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
	Interface for CModelessMain, a reusable class for creating modeless
	dialogs which act as main application windows.  The dialog contains
	a status bar and a tool bar.  It provides support for ID_VIEW_STATUS_BAR
	and ID_VIEW_TOOLBAR commands, as well as CAPS, NUM, and SCRL key
	indicators.

  Functions:
	CModelessMain::CModelessMain()          -- constructor
	CModelessMain::~CModelessMain()         -- destructor
	CModelessMain::Create()                 -- Create dialog window
	CModelessMain::GetStatusBar()           -- access status bar
	CModelessMain::GetToolBar()             -- access toolbar
	CModelessMain::OnClose()                -- handle WM_CLOSE
	CModelessMain::OnEnterIdle()            -- handle WM_ENTERIDLE
	CModelessMain::OnEraseBkgnd()           -- handle WM_ERASEBKGND
	CModelessMain::OnInitDialog()           -- initialize dialog
	CModelessMain::OnInitMenuPopup()        -- handle WM_INITMENUPOPUP
	CModelessMain::OnMenuSelect()           -- handle WM_MENUSELECT
	CModelessMain::OnPaint()                -- handle WM_PAINT
	CModelessMain::OnQueryDragIcon()        -- handle WM_QUERYDRAGICON
	CModelessMain::OnSetMessageString()     -- handle WM_SETMESSAGESTRING
	CModelessMain::OnStatusBarCheck()       -- ID_VIEW_STATUS_BAR handler
	CModelessMain::OnToolBarCheck()         -- ID_VIEW_TOOLBAR handler
	CModelessMain::OnUpdateKeyIndicator()   -- update key indicator items
	CModelessMain::OnUpdateStatusBarMenu()  -- update ID_VIEW_STATUS_BAR items
	CModelessMain::OnUpdateToolBarMenu()    -- update ID_VIEW_TOOLBAR items

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __MDLSMAIN_H__
#define __MDLSMAIN_H__

#include "modeless.h"
#include "dlgbars.h"

class CModelessMain : public CModelessDialog
{
private:
	using CModelessDialog::Create;

	DECLARE_DYNAMIC(CModelessMain)

// Construction
public:
	CModelessMain();
	BOOL Create(LPCTSTR lpszTemplateName,
				const UINT FAR* lpaIDStatus, int cIDStatus,
				const UINT FAR* lpaIDToolbar, int cIDToolbar,
				UINT nIDBitmap);
	BOOL Create(UINT nIDTemplate,
				const UINT FAR* lpaIDStatus, int cIDStatus,
				const UINT FAR* lpaIDToolbar, int cIDToolbar,
				UINT nIDBitmap);

// Attributes
public:
	CStatusBar* GetStatusBar() { return &m_statusBar; }
	CToolBar*   GetToolBar()   { return &m_toolBar; }

// Implementation
public:
	virtual ~CModelessMain();

	// Overrides
	virtual BOOL OnInitDialog();

protected:
	HICON           m_hIcon;

	UINT            m_nIDTracking;
	UINT            m_nIDLastMessage;

	const UINT FAR* m_lpaIDStatusBar;
	int             m_cIDStatusBar;
	CDlgStatusBar   m_statusBar;

	const UINT FAR* m_lpaIDToolBar;
	int             m_cIDToolBar;
	UINT            m_nIDBitmap;
	CDlgToolBar     m_toolBar;

	// Generated message map functions
	//{{AFX_MSG(CModelessMain)
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnterIdle(UINT nWhy, CWnd* pWho);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam = 0L);
	afx_msg void OnStatusBarCheck();
	afx_msg void OnToolBarCheck();
	afx_msg void OnUpdateStatusBarMenu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolBarMenu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateKeyIndicator(CCmdUI* pCmdUI);
	afx_msg LRESULT OnPopMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif //__MDLSMAIN_H__
