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

class CWorkspaceToolBar : public CMFCToolBar
{
public: 
	// All commands should be routed via owner window, not via frame:
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler) 
	{ 
		CMFCToolBar::OnUpdateCmdUI ((CFrameWnd*) GetOwner (), bDisableIfNoHndler);
	}

	// Toolbar should't appear on the customization list
	virtual BOOL AllowShowOnList () const		{	return FALSE;	}
	virtual void AdjustLayout ();
};


class CWorkspaceBar : public CDockablePane
{
public:
	CWorkspaceBar();

// Attributes
protected:
	CWorkspaceToolBar	m_wndToolBar;
	CMFCTabCtrl			m_wndTabs;

	CTreeCtrl			m_wndTree1;
	CTreeCtrl			m_wndTree2;

// Operations
public:
	void AdjustLayout ();

// Overrides

// Implementation
public:
	virtual ~CWorkspaceBar();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCommand1();
	afx_msg void OnCommand2();
	afx_msg void OnCommand3();
	afx_msg void OnUpdateCommand3(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};
