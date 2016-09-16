// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class COwnerDrawMenuView : public CView
{
protected: // create from serialization only
	COwnerDrawMenuView();
	DECLARE_DYNCREATE(COwnerDrawMenuView)

// Attributes
public:
	COwnerDrawMenuDoc* GetDocument();

protected:
	UINT m_uiLineStyleCmd;

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
	virtual ~COwnerDrawMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnMoreLines();
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnLineStyle(UINT uiCmd);
	afx_msg void OnUpdateLineStyle(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OwnerDrawMenuView.cpp
inline COwnerDrawMenuDoc* COwnerDrawMenuView::GetDocument()
   { return (COwnerDrawMenuDoc*)m_pDocument; }
#endif
