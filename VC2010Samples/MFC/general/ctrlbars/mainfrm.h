// mainfrm.h : interface of the CMainFrame class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXEXT_H__
#include <afxext.h>         // for access to CToolBar and CStatusBar
#endif

#include "palette.h"        // for access to CPaletteBar


// Instead of using a class here we could have just put these controls
// directly into CMainFrame.  As it is they are sending messages to the
// main frame just like they were part of it instead of part of a control
// bar.
class CStyleBar : public CToolBar
{
public:
	CComboBox   m_comboBox;
	CFont       m_font;
};

class CMainFrame : public CFrameWnd
{
// Constructor
public:
	CMainFrame();

// Attributes
public:
	BOOL m_bInsert;     // TRUE => insert mode, FALSE => overstrike mode

// Operations
public:

// Implementation
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	BOOL CreateStyleBar();
	BOOL CreateToolBar();
	BOOL CreatePaletteBar();
	BOOL CreateStatusBar();

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CStyleBar   m_wndStyleBar;
	CPaletteBar m_wndPaletteBar;
	CDialogBar  m_wndDlgBar;
	UINT        m_nPaletteCol;
	BOOL        m_bDialogTop;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewDlgbarTop();
	afx_msg void OnUpdateViewDlgbartop(CCmdUI* pCmdUI);
	afx_msg BOOL OnViewBar(UINT nID);
	afx_msg void OnUpdateBarMenu(CCmdUI* pCmdUI);
	afx_msg void OnViewShort();
	afx_msg void OnViewLong();
	afx_msg void OnUpdateInsert(CCmdUI* pCmdUI);
	afx_msg void OnToggleInsert();
	afx_msg void OnViewPalette();
	afx_msg void OnUpdatePaletteMenu(CCmdUI* pCmdUI);
	afx_msg void OnSelChangePalette();
	afx_msg void OnPalette2column();
	afx_msg void OnPalette3column();
	afx_msg void OnUpdatePalette3column(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePalette2column(CCmdUI* pCmdUI);
	//}}AFX_MSG

	afx_msg void OnUpdateStyle(CCmdUI* pCmdUI);
	afx_msg void OnChangeStyle(UINT nID);
	afx_msg void OnPalette(UINT nID);
	afx_msg void OnUpdatePalette(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
