// minifrm.h : interface of the CShapePropSheetFrame class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CShapePropSheetFrame : public CMiniFrameWnd
{
// Constructor
public:
	CShapePropSheetFrame();

// Attributes
public:
	CModelessShapePropSheet* m_pModelessShapePropSheet;

// Handlers
protected:
	//{{AFX_MSG(CShapePropSheetFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
