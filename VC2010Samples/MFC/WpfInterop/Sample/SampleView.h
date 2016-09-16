
// SampleView.h : interface of the CSampleView class
//


#pragma once

#include "WpfElementHostProxy.h"
#include "SampleContentProxy.h"

class CSampleView : public CView
{
protected: // create from serialization only
	CSampleView();
	DECLARE_DYNCREATE(CSampleView)

// Attributes
public:
	CSampleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	CWpfElementHostProxy m_elementHost;
	HWND m_hWndElementHost;
	CSampleContentProxy m_sampleContent;
	CGotFocusEventHandler m_gotFocusHandler;
	void WpfElementHost_OnGotFocus(const CManagedObjectProxy &sender, const CGotFocusEventArgsProxy &args);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in SampleView.cpp
inline CSampleDoc* CSampleView::GetDocument() const
   { return reinterpret_cast<CSampleDoc*>(m_pDocument); }
#endif

