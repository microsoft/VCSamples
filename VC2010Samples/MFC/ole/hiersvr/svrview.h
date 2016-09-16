// svrview.h : interface of the CServerView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "svritem.h"

class CServerView : public CScrollView
{
protected: // create from serialization only
	CServerView();
	DECLARE_DYNCREATE(CServerView)

// Attributes
public:
	CServerDoc* GetDocument()
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CServerDoc)));
		ASSERT_VALID(m_pDocument);
		return (CServerDoc*)m_pDocument;
	}
	void SetSelection(CServerNode* pNewSel, CDC* pDC);
	void SetSelection(CServerNode* pNewSel);

// Operations
public:
	void SetScrollInfo();
	BOOL SetZoomFactor(CSize zoomNum, CSize zoomDenom);
	void UpdateServerView();
	CSize CalcActualViewSize(CDC *pDC);
	CSize CalcActualItemSize(CServerNode* pItem, CDC *pDC);
	CSize CalcScaledViewSize();
	CSize CalcScaledItemSize(CServerNode* pItem);
	BOOL DoPasteItem(COleDataObject* pDataObject);
	void DoPasteNative(COleDataObject* pDataObject);
	void DoPasteText(COleDataObject* pDataObject);
	void DoImportText(CArchive &ar);
	void ScrollToItem(CServerNode* pItem, BOOL bScrollUp);
	void Locate(int cnt, BOOL bScrollUp);
	void InvalidateItem(CServerNode* pItem, CDC* pDC);
	void InvalidateItem(CServerNode* pItem);
	void ToggleSelectedItem();

// Implementation
public:
	virtual ~CServerView();
	virtual void OnDraw(CDC* pDC);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


protected:
	// drag/drop stuff
	COleDropTarget m_dropTarget;
	DROPEFFECT m_prevDropEffect;

	// current selection - store the node and the last drawn rect
	CServerNode* m_pSelectedNode;
	static CServerNode* NEAR m_pDragNode;

	// upper left of drawing
	CPoint m_ptStart;

	// zoom factor
	CSize m_zoomNum;
	CSize m_zoomDenom;

	// implementation helpers
	void SelectAtPoint(CPoint point, CPoint& pointHit);
	void DoBranch(CServerNode *pItem, BOOL bHide);

	virtual BOOL OnDrop(COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject,
		DWORD grfKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject,
		DWORD grfKeyState, CPoint point);
	virtual void OnDragLeave();

// Generated message map functions
protected:
	//{{AFX_MSG(CServerView)
	afx_msg void OnChangeName();
	afx_msg void OnAddNode();
	afx_msg void OnUpdateHasSel(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnImportText();
	afx_msg void OnViewZoomCustom();
	afx_msg void OnEditCut();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEditClear();
	afx_msg void OnTreeCollapsebranch();
	afx_msg void OnTreeExpandall();
	afx_msg void OnTreeExpandbranch();
	afx_msg void OnTreeExpandonelevel();
	afx_msg void OnUpdateTreeCollapsebranch(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTreeExpandonelevel(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTreeExpandall(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTreeExpandbranch(CCmdUI* pCmdUI);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	// special message handling
	afx_msg void OnZoom(UINT nID);
	afx_msg void OnUpdateZoom(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
	friend class CServerViewDC;
};

class CServerDC : public CClientDC
{
	CFont font;
	CFont *pOldFont;

public:
	CServerDC(CServerView *pView);
	~CServerDC();
};

/////////////////////////////////////////////////////////////////////////////
