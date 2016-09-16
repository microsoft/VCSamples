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

#include "ToolsPalette.h"

class CMainFrame : public CFrameWndEx
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
	CMFCMenuBar	m_wndMenuBar;
	CMFCStatusBar	m_wndStatusBar;
	CMFCToolBar	m_wndToolBar;
	CToolsPalette	m_wndPalette;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewToolsPalette();
	afx_msg void OnUpdateViewToolsPalette(CCmdUI* pCmdUI);
	afx_msg void OnTwoColumns();
	afx_msg void OnUpdateTwoColumns(CCmdUI* pCmdUI);
	afx_msg void OnThreeColumns();
	afx_msg void OnUpdateThreeColumns(CCmdUI* pCmdUI);
	afx_msg void OnFourColumns();
	afx_msg void OnUpdateFourColumns(CCmdUI* pCmdUI);
	afx_msg LRESULT OnToolbarContextMenu(WPARAM,LPARAM);
	afx_msg void OnViewCustomize();

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnShowPopupMenu (CMFCPopupMenu* pMenuPopup);
};
