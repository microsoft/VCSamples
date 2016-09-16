// shapesvw.h : interface of the CShapesView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CShapesView : public CView
{
protected: // create from serialization only
	CShapesView();
	DECLARE_DYNCREATE(CShapesView)

// Attributes
public:
	CShapesDoc* GetDocument();
	CShape* m_pShapeSelected;
protected:
	CModalShapePropSheet* m_pModalShapePropSheet;


// Operations
public:

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CShapesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CModelessShapePropSheet* GetModelessShapePropSheet();

	virtual ~CShapesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CShapesView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSimplePropertySheet();
	afx_msg void OnUpdateSimplePropertySheet(CCmdUI* pCmdUI);
	afx_msg void OnPropertySheetWithPreview();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUpdatePropertySheetWithPreview(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
   afx_msg LRESULT OnChangeObjectProps(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in shapesvw.cpp
inline CShapesDoc* CShapesView::GetDocument()
   { return (CShapesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
