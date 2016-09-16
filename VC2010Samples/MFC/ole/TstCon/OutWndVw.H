// File: OutWndVw.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_OUTPUTWINDOWVIEW_H__5808BFDF_5166_11D1_8E54_00C04FB68D60__INCLUDED_)
#define AFX_OUTPUTWINDOWVIEW_H__5808BFDF_5166_11D1_8E54_00C04FB68D60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputWindowView.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputWindowView view

class COutputWindowView : public CEditView
{
protected:
	COutputWindowView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COutputWindowView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputWindowView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COutputWindowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   CFont m_font;

	// Generated message map functions
protected:
	//{{AFX_MSG(COutputWindowView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG

   afx_msg void OnClear();
   afx_msg void OnCopy();

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTWINDOWVIEW_H__5808BFDF_5166_11D1_8E54_00C04FB68D60__INCLUDED_)
