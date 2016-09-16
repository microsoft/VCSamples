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

/////////////////////////////////////////////////////////////////////////////
// CFolderBar window

class CFolderBar : public CDockablePane
{
// Construction
public:
	CFolderBar();

// Attributes
public:
	CMFCShellTreeCtrl	m_wndShellTree;

// Operations
public:

// Overrides

// Implementation
public:
	virtual ~CFolderBar();

protected:
	ULONG m_ulRecycleBin;

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg	LRESULT OnNotifyRecycleBin(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};
