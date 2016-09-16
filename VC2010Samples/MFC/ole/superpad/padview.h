// padview.h : interface of the CPadView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __PADVIEW_H__
#define __PADVIEW_H__

#include <afxdlgs.h>
#include <afxext.h>
#include "paddoc.h"

class CPadView : public CEditView
{
	DECLARE_DYNCREATE(CPadView)

// Construction
	CPadView();
	BOOL PreCreateWindow(CREATESTRUCT& cs);

// Attributes
public:
	// static init/term...
	static void Initialize();
	static void Terminate();

	CPadDoc* GetDocument()
		{ return (CPadDoc*)m_pDocument; }

// Operations
public:
	// Word wrap...
	BOOL IsWordWrap() const;
	BOOL SetWordWrap(BOOL bWordWrap);

	// Printing...
	virtual void OnPrint(CDC* pDC, CPrintInfo *pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnScrollTo(CDC* pDC, CPrintInfo* pInfo, POINT point);

	// Buffer access...
	LPCTSTR LockBuffer() const
		{ return CEditView::LockBuffer(); }
	void UnlockBuffer() const
		{ CEditView::UnlockBuffer(); }

// Implementation
public:
	BOOL IsUpdatePending() {return (m_uTimerID != NULL);}

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	UINT_PTR m_uTimerID; // ==0 when no outstanding

	static LOGFONT NEAR m_lfDefFont;
	static LOGFONT NEAR m_lfDefFontOld;
	CFont m_font;

	static LOGFONT NEAR m_lfDefPrintFont;
	static LOGFONT NEAR m_lfDefPrintFontOld;
	CFont m_fontPrint;

	static UINT m_nDefTabStops;
	static UINT m_nDefTabStopsOld;
	static BOOL m_bDefWordWrap;
	static BOOL m_bDefWordWrapOld;

	UINT m_nPreviewPage;
	CTime m_timeHeader;
	CTime m_timeFooter;

	//{{AFX_MSG(CPadView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChooseFont();
	afx_msg void OnWordWrap();
	afx_msg void OnUpdateWordWrap(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChoosePrintFont();
	afx_msg void OnMirrorDisplayFont();
	afx_msg void OnUpdateMirrorDisplayFont(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChoosePrintFont(CCmdUI* pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEditChange();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	afx_msg void OnSetTabStops();

	DECLARE_MESSAGE_MAP()
};

#endif  // __PADVIEW_H__

/////////////////////////////////////////////////////////////////////////////
