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

#define CMDIFrameWnd CMDIFrameWndEx

// -EXAMPLE-

class CMyMenuBar : public CMFCMenuBar
{
	virtual void CreateFromMenu (HMENU hMenu, BOOL bDefaultMenu = FALSE,
						BOOL bForceUpdate = FALSE);
};

// ---

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:

// Operations
public:

// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual BOOL OnShowPopupMenu (CMFCPopupMenu* pMenuPopup);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMyMenuBar		m_wndMenuBar;
	CMFCStatusBar	m_wndStatusBar;
	CMFCToolBar	m_wndToolBar;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	afx_msg void OnWindowManager();
	afx_msg void OnAppLook(UINT id);
	afx_msg void OnUpdateAppLook(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()

	virtual CMDIChildWndEx* CreateDocumentWindow (LPCTSTR lpcszDocName, CObject* /*pObj*/);

	UINT	m_nAppLook;
};
