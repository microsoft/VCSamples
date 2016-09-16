// DlgBars.h : header file
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
	Interface for CDlgToolBar, a special type of CToolBar which does not
	expect a parent frame window to be available, and CDlgStatusBar, which
	does the same for CStatusBars.  This allows the control bars
	to be used in applications where the main window is a dialog bar.

  Functions:
	CDlgToolBar::CDlgToolBar()          -- constructor
	CDlgToolBar::~CDlgToolBar()         -- destructor
	CDlgToolBar::OnIdleUpdateCmdUI()    -- WM_IDLEUPDATECMDUI handler

	CDlgStatusBar::CDlgStatusBar()      -- constructor
	CDlgStatusBar::~CDlgStatusBar()     -- destructor
	CDlgStatusBar::OnIdleUpdateCmdUI()  -- WM_IDLEUPDATECMDUI handler

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __DLGBARS_H__
#define __DLGBARS_H__

class CDlgToolBar : public CToolBar
{
// Construction
public:
	CDlgToolBar();

// Implementation
public:
	virtual ~CDlgToolBar();

protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgToolBar)
	afx_msg LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CDlgStatusBar : public CStatusBar
{
// Construction
public:
	CDlgStatusBar();

// Implementation
public:
	virtual ~CDlgStatusBar();

protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgStatusBar)
	afx_msg LRESULT OnIdleUpdateCmdUI(WPARAM wParam, LPARAM);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#endif //__DLGBARS_H__
