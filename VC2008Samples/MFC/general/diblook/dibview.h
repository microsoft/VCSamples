// dibview.h : interface of the CDibView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CDibView : public CScrollView
{
protected: // create from serialization only
	CDibView();
	DECLARE_DYNCREATE(CDibView)

// Attributes
public:
	CDibDoc* GetDocument()
		{
			ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDibDoc)));
			return (CDibDoc*) m_pDocument;
		}

// Operations
public:

// Implementation
public:
	virtual ~CDibView();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view

	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView,
					CView* pDeactiveView);

	// Printing support
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Generated message map functions
protected:
	//{{AFX_MSG(CDibView)
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg LRESULT OnDoRealize(WPARAM wParam, LPARAM lParam);  // user message
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
