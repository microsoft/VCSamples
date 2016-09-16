// ipframe.h : interface of the CInPlaceFrame class
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

class CInPlaceFrame : public COleIPFrameWnd
{
protected:
	using COleIPFrameWnd::OnCreateControlBars;

	DECLARE_DYNCREATE(CInPlaceFrame)
public:
	CInPlaceFrame();

// Implementation
public:
	virtual ~CInPlaceFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc);

protected:
	// control bar embedded members
	CToolBar    m_wndToolBar;
	COleResizeBar   m_wndResizeBar;
	// for enabling drag/drop to our window
	COleDropTarget m_dropTarget;

// Generated message map functions
protected:
	//{{AFX_MSG(CInPlaceFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateContextHelp(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
