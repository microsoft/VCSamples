// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// GestureDemoView.h : interface of the CGestureDemoView class
//


#pragma once

class CGestureDemoView : public CView
{
protected: // create from serialization only
	CGestureDemoView();
	DECLARE_DYNCREATE(CGestureDemoView)

// Attributes
public:
	CGestureDemoDoc* GetDocument() const;

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
	virtual void OnInitialUpdate();

// Implementation
public:
	virtual ~CGestureDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnResetConfig();
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnGestureZoom(CPoint ptCenter, long lDelta);
	virtual BOOL OnGesturePan(CPoint ptFrom, CPoint ptTo);
	virtual BOOL OnGestureRotate(CPoint ptCenter, double dblAngle);
	virtual BOOL OnGestureTwoFingerTap(CPoint ptCenter);
	virtual BOOL OnGesturePressAndTap(CPoint ptFirstFinger, long lDelta);

	double	m_dblZoomRatio;
	double	m_dblAngle;
	double	m_dblAngleStart;
	CPoint	m_ptOffset;
	CPoint	m_ptCenter;

	BOOL	m_bInZoom;
	BOOL	m_bInPan;
	BOOL	m_bInRotate;

	ULONG_PTR 	m_ulGDIPlusToken;
};

#ifndef _DEBUG  // debug version in GestureDemoView.cpp
inline CGestureDemoDoc* CGestureDemoView::GetDocument() const
   { return reinterpret_cast<CGestureDemoDoc*>(m_pDocument); }
#endif

