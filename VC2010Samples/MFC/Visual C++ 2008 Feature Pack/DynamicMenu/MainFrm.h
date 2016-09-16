// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

//------------- Example --------------------//
// here is the overriden version of of CMFCMenuBar that will dynamically modify 
// the top level menu bar
#include "MyMenuBar.h"
//-----------------------------------------//

#define CFrameWnd CFrameWndEx

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	//------------- Example --------------------//
	CMyMenuBar		m_wndMenuBar;
	//------------------------------------------//
	CMFCStatusBar		m_wndStatusBar;
	CMFCToolBar		m_wndToolBar;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDynamicItem1();
	afx_msg void OnDynamicItem2();
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	afx_msg LRESULT OnToolbarContextMenu(WPARAM,LPARAM);
	afx_msg LRESULT OnResetMenu(WPARAM,LPARAM);
	afx_msg void OnEditMyItem1 ();
	afx_msg void OnEditMyItem2 ();

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnShowPopupMenu (CMFCPopupMenu* pMenuPopup);
	//------------- Example --------------------//
	virtual BOOL OnDrawMenuImage (	CDC* pDC, 
									const CMFCToolBarMenuButton* pMenuButton, 
									const CRect& rectImage);
	//------------------------------------------//
};
