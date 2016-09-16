// ToolPage.h : header file
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
// CToolBarCtrlPage dialog
#ifndef INC_TOOLPAGE_H
#define INC_TOOLPAGE_H

#include "toolbar1.h"
#include "toolbar2.h"

class CToolBarCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CToolBarCtrlPage)

// Construction
public:
	CToolBarCtrlPage();
	~CToolBarCtrlPage();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyToolBarCtrlPage)
	//}}AFX_VIRTUAL

// Attributes
protected:
	CStandardBar    m_StandardBar;
	CPaletteBar     m_PaletteBar;
	CToolTipCtrl    m_ToolTip;
// Dialog Data
	//{{AFX_DATA(CToolBarCtrlPage)
	enum { IDD = IDD_TOOLBARCTRL };
	BOOL    m_bAltDrag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CToolBarCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ChangeCtrlStyle(long lStyle, BOOL bSetStyle);

	// Generated message map functions
	//{{AFX_MSG(CToolBarCtrlPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAltdrag();
	//}}AFX_MSG
#ifdef FWC
	afx_msg void OnToolbarCommand(UINT nID);
#endif
	DECLARE_MESSAGE_MAP()

};

#endif
