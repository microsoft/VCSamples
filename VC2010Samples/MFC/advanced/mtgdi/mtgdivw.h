// mtgdivw.h : interface of the CThreadView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "threads.h"

class CThreadView : public CView
{
protected: // create from serialization only
	CThreadView();
	DECLARE_DYNCREATE(CThreadView)

// Attributes
public:
	CClientDC *m_pDC;
	CTypedPtrList<CObList,CGDIThread*>     m_threadList;
	CThreadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
public:
	void StartThread(int ThreadID);
	void UpdateTitle(int nThreads = -1);
	virtual ~CThreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CThreadView)
	afx_msg void OnNewball();
	afx_msg void OnKillThreads();
	afx_msg void OnDestroy();
	afx_msg void OnNewline();
	afx_msg void OnNewrectangle();
	afx_msg void On10newballs();
	afx_msg void On10newlines();
	afx_msg void On10newrectangles();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void On25newballs();
	afx_msg void On25newlines();
	afx_msg void On25newrectangles();
	afx_msg void OnThreadKillThreadsSlow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mtgdivw.cpp
inline CThreadDoc* CThreadView::GetDocument()
   { return (CThreadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
