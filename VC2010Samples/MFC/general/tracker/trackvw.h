// trackvw.h : interface of the CTrackerView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////

class CTrackerView : public CView
{
protected: // create from serialization only
	CTrackerView();
	DECLARE_DYNCREATE(CTrackerView)

// Attributes
public:
	CTrackerDoc* GetDocument();

// Operations
public:

// Implementation
public:
	virtual ~CTrackerView();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

	// Printing support
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Generated message map functions
protected:
	//{{AFX_MSG(CTrackerView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnViewSethandlesize();
	afx_msg void OnViewSetminimumsize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in trackvw.cpp
inline CTrackerDoc* CTrackerView::GetDocument()
   { return (CTrackerDoc*) m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
