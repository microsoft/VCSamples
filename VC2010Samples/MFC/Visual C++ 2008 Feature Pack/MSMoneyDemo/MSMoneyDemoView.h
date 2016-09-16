// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMoneyDemoView.h : interface of the CMSMoneyDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CMSMoneyDemoView : public CView
{
protected: // create from serialization only
	CMSMoneyDemoView();
	DECLARE_DYNCREATE(CMSMoneyDemoView)

// Attributes
public:
	CMSMoneyDemoDoc* GetDocument();

protected:
	CBitmap	m_Image;
	CSize	m_sizeImage;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMSMoneyDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MSMoneyDemoView.cpp
inline CMSMoneyDemoDoc* CMSMoneyDemoView::GetDocument()
{
	return (CMSMoneyDemoDoc*)m_pDocument;
}
#endif
