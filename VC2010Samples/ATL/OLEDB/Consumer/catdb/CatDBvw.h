// Cat3View.h : interface of the CCatDBView class
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

/////////////////////////////////////////////////////////////////////////////

class CCatDBView : public CListView
{
protected: // create from serialization only
	CCatDBView();
	DECLARE_DYNCREATE(CCatDBView)

// Attributes
public:
	CCatDBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatDBView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCatDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCatDBView)
	afx_msg void OnUpdateViewColumnlevel(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewTablelevel(CCmdUI* pCmdUI);
	afx_msg void OnViewColumnlevel();
	afx_msg void OnViewTablelevel();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Cat3View.cpp
inline CCatDBDoc* CCatDBView::GetDocument()
   { return (CCatDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
