// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

//*******************************************************************************
//
// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "MSMCaptionBar.h"
#include "MSMMenuBar.h"
#include "MSMToolBar.h"
#include "MSMTasksPane.h"
#include "MSMCategoryBar.h"
#include "MSMLinksBar.h"

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

// Implementation
public:

	virtual ~CMainFrame();

	virtual BOOL OnShowPopupMenu (CMFCPopupMenu* pMenuPopup);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	afx_msg LRESULT OnToolbarContextMenu(WPARAM,LPARAM);
	afx_msg void OnUpdateGoAddressEdit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBackward1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBackward2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateForward1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateForward2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCustomize(CCmdUI* pCmdUI);
	afx_msg void OnCategorie(UINT nID);
	afx_msg void OnUpdateCategorie(CCmdUI* pCmdUI);
	afx_msg void OnLinks(UINT nID);
	afx_msg void OnUpdateLinks(CCmdUI* pCmdUI);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnHelpMicrosoft();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);

	DECLARE_MESSAGE_MAP()

private:
	void SetupMemoryBitmapSize (const CSize& sz);

	CMSMLinksBar*    GetLinksBar (UINT nID);

	CMSMCaptionBar   m_wndCaptionBar;
	CMSMMenuBar      m_wndMenuBar;
	CMSMToolBar      m_wndToolBar;
	CMSMCategoryBar  m_wndCategoryBar;
	CMSMLinksBar     m_wndLinksBars[8];
	CMSMTasksPane    m_wndTaskPane;

	CMenu				 m_menuFavotites;

	BOOL				 m_bIsHighColor;
	BOOL				 m_bMainToolbarMenu;

	UINT				 m_nCategorie;
};
