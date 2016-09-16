// spiroView.h : interface of the CSpiroView class
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

#if !defined(AFX_SPIROVIEW_H__4417CF8E_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)
#define AFX_SPIROVIEW_H__4417CF8E_AFA9_11D1_AB61_D9B80632F018__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "piece.h"

class CSpiroView : public CScrollView
{
public:
	// Data Members
	long	m_nZoomNumer;  // The zoom is determined by ZoomNumer/ZoomDenom
	long	m_nZoomDenom;
	bool	m_bDrawingActive;
	bool	m_bStartDrag;	// Initiate figure moving action on next mousemove message
	bool	m_bDrawingDone;  // The pattern has been drawn completely
	bool	m_bDroppingAnchor;  // a ring is being dropped on the form
	bool	m_bDroppingWheel;  // a wheel is being dropped on the form
	int		m_iPieceDropped;  // index of piece being dropped.
	bool	m_bMovingPencil;  // the user is dragging the pencil location
	COLORREF m_coCurrentPen;	// color of current pen being used.
	int		m_nCurrentPenWidth;  // width of current pen used in the drawing
	int		m_nTracesPerTick;	// number of traces per callback on the timer
	INT_PTR m_IDTimer;			// Timer ID for the view.

	CDC*	m_pDCMem;		// memory DC used to draw before bitblt'ing
	CBitmap*	m_pBitmap;		// bitmap used by the memory DC
	CBitmap*	m_pbitmapOld;	// stores the original bitmap in m_pDCMem
	CSize	m_sizeBitmap;		// size of the bitmap, which changes as required.

	double	m_dDataAnchorFirst;		// Initial Data for an anchor piece
	double	m_dDataWheelFirst;		// Initial Data for a wheel piece
	CPoint	m_ptWheelPosFirst;		// Initial position for the wheel piece

	CBasePiece*		m_pAnchor;  // anchored piece on the form
	CBasePiece*		m_pWheel;	// moving part on the form (wheel or not)

protected:
	CImageList* m_pILDragFigure;   // image list for Figure dragging
	CFigure*	m_pFigureDrag;		// Figure being dragged
	CPoint		m_ptHotSpotDragFigure;   // Hot Spot for the image used when dragging a Figure
	CBitmap*	m_pBitmapDragFigure;	// bitmap that goes into the image list for dragging a figure.

protected: // create from serialization only
	CSpiroView();
	DECLARE_DYNCREATE(CSpiroView)

// Attributes
public:
	CSpiroDoc* GetDocument();

// Operations
public:

	static void CALLBACK TimerCallBack(HWND hWnd, UINT nMsg, UINT_PTR nIDEvent, DWORD dwTimer);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpiroView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

protected:
	void	OnRemovePiece(CBasePiece** ppPiece);
	void	ZoomChange(int nChange);
	void	CreateFigure();  // calculates the figure with the given tools
	long	GetWheelDistanceForFigure() const;
	void	PressButton(UINT id);

// Implementation
public:
	virtual ~CSpiroView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void OnDropPiece(int* rgID, int nCount);

// Generated message map functions
protected:
	//{{AFX_MSG(CSpiroView)
	afx_msg void OnPenWidth();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateAnyWheel(CCmdUI* pCmdUI);
	afx_msg void OnDropRing();
	afx_msg void OnDropWheel();
	afx_msg void OnUpdateRemoveRing(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRemoveWheel(CCmdUI* pCmdUI);
	afx_msg void OnRemoveRing();
	afx_msg void OnRemoveWheel();
	afx_msg void OnUpdateZoomIn(CCmdUI* pCmdUI);
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnUpdateZoomOut(CCmdUI* pCmdUI);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateDrawPattern(CCmdUI* pCmdUI);
	afx_msg void OnDrawPattern();
	afx_msg void OnEndDrawing();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBlack();
	afx_msg void OnBlue();
	afx_msg void OnGreen();
	afx_msg void OnPurple();
	afx_msg void OnRed();
	afx_msg void OnYellow();
	afx_msg void OnUpdateColor(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePauseDrawing(CCmdUI* pCmdUI);
	afx_msg void OnPauseDrawing();
	afx_msg void OnUpdateSlow(CCmdUI* pCmdUI);
	afx_msg void OnSlow();
	afx_msg void OnUpdateFast(CCmdUI* pCmdUI);
	afx_msg void OnFast();
	afx_msg void OnCallTimerTick();
	afx_msg void OnUpdateTimerTick(CCmdUI* pCmdUI);
	afx_msg void OnTraceWidth();
	afx_msg void OnUpdateTraceWidth(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnUpdateAnyRing(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDraw(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePause(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenWidth(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in spiroView.cpp
inline CSpiroDoc* CSpiroView::GetDocument()
   { return (CSpiroDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIROVIEW_H__4417CF8E_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)
