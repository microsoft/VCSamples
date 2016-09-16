// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#pragma once

class CRibbonGadgetsView : public CView
{
protected: // create from serialization only
	CRibbonGadgetsView();
	DECLARE_DYNCREATE(CRibbonGadgetsView)

// Attributes
public:
	CRibbonGadgetsDoc* GetDocument();

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual HMENU GetContextMenu(WORD, LPOLEOBJECT, CHARRANGE* );
	virtual void OnDraw(CDC* pDC);

// Implementation
public:
	virtual ~CRibbonGadgetsView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RibbonGadgetsView.cpp
inline CRibbonGadgetsDoc* CRibbonGadgetsView::GetDocument()
   { return (CRibbonGadgetsDoc*)m_pDocument; }
#endif
