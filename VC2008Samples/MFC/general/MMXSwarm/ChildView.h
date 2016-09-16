// ChildView.h : interface of the CChildView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once
#include "MMXSurface.h"
#include "Swarm.h"

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:
	BOOL OnIdle(LONG lCount);
	CSurface *GetSurface() const
	{ return(m_pSurface); }

// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnUpdateFPS(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePauseBlur(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePauseSwarm(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePauseBlit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateResolution(CCmdUI* pCmdUI);
	afx_msg void OnUpdateImageFormats(CCmdUI* pCmdUI);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnViewPauseBlur();
	afx_msg void OnViewPauseSwarm();
	afx_msg void OnViewPauseBlit();
	afx_msg void OnImageFormats(UINT nID);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	enum ESurface {
		eNone				= 0,
		e16BitSSE2Intrin	= IDD_16BIT_SSE2INTRINSICS,
		e16BitMMXIntrin		= IDD_16BIT_MMXINTRINSICS,
		e16BitGeneric		= IDD_16BIT_GENERICCBLUR,
		e24BitSSE2Intrin	= IDD_24BIT_SSE2INTRINSICS,
		e24BitMMXIntrin		= IDD_24BIT_MMXINTRINSICS,
		e24BitGeneric		= IDD_24BIT_GENERICCBLUR,
		e32BitSSE2Intrin	= IDD_32BIT_SSE2INTRINSICS,
		e32BitMMXIntrin		= IDD_32BIT_MMXINTRINSICS,
		e32BitGeneric		= IDD_32BIT_GENERICCBLUR,
	};

	void CreateSurface();

	ESurface  m_eSurf;
	CSurface *m_pSurface;
	CSwarm	  m_swarm;

	int		m_nFrameCounter;
	int		m_nFilterLoad; // remember file/open filter
	int		m_nFilterSave; // remember file/save filter
	DWORD	m_dwTickStart;
	bool	m_bSizeChanged;
	bool	m_bPauseBlur;
	bool	m_bPauseSwarm;
	bool	m_bPauseBlit;
	bool    m_bTimerPopped;

	static const UINT_PTR m_kTimerID = 31;
	static const UINT m_kTimerDelay = 1500;
public:
	afx_msg void OnDestroy(void);
};

