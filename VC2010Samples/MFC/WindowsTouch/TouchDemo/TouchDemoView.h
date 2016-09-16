// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// TouchDemoView.h : interface of the CTouchDemoView class
//


#pragma once

#define TOUCH_OBJECT_SIZE	100

class CTouchObject : public CObject
{
public:
	CTouchObject(COLORREF clr, CPoint pt)
	{
		m_Color = clr;
		m_pt = pt;
		m_nTouchNumber = -1;
		m_ptTouchOffset = CPoint(0, 0);
	}

	BOOL HitTest (CPoint pt)
	{
		CRect rect = GetRect();
		if (!rect.PtInRect (pt))
		{
			return FALSE;
		}

		m_ptTouchOffset.x = pt.x - rect.left;
		m_ptTouchOffset.y = pt.y - rect.top;

		return TRUE;
	}

	void OnDraw (CDC* pDC) const
	{
		CRect rect = GetRect();

		pDC->FillSolidRect(rect, m_Color);
		pDC->Draw3dRect(rect, 0, 0);
	}

	void Move (CPoint pt)
	{
		m_pt = pt;
		m_pt.Offset(-m_ptTouchOffset);
	}

	CRect GetRect() const
	{
		return CRect(m_pt, CSize(TOUCH_OBJECT_SIZE, TOUCH_OBJECT_SIZE));
	}

	int	m_nTouchNumber;

protected:
	COLORREF m_Color;
	CPoint	m_pt;
	CPoint 	m_ptTouchOffset;
};

class CTouchDemoView : public CView
{
protected: // create from serialization only
	CTouchDemoView();
	DECLARE_DYNCREATE(CTouchDemoView)

// Attributes
public:
	CTouchDemoDoc* GetDocument() const;

protected:
	CArray<CTouchObject*,CTouchObject*>	m_arObjects;

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

	virtual BOOL OnTouchInput(CPoint pt, int nInputNumber, int nInputsCount, PTOUCHINPUT pInput);
	virtual ULONG GetGestureStatus(CPoint ptTouch);

// Implementation
public:
	virtual ~CTouchDemoView();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TouchDemoView.cpp
inline CTouchDemoDoc* CTouchDemoView::GetDocument() const
   { return reinterpret_cast<CTouchDemoDoc*>(m_pDocument); }
#endif

