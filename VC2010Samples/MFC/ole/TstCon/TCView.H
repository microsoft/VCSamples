// CTestContainer98View.h : interface of the CTestContainer98View class
//
/////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CTESTCONTAINER98VIEW_H__1981850A_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
#define AFX_CTESTCONTAINER98VIEW_H__1981850A_B837_11D0_8DF1_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTestContainer98Item;

const DWORD HITTYPE_NONE = 0;
const DWORD HITTYPE_OBJECT = 1;
const DWORD HITTYPE_BORDER = 2;

class CTestContainer98View : public CView
{
   DECLARE_DYNCREATE(CTestContainer98View)

protected: // create from serialization only
   CTestContainer98View();

// Attributes
public:
   CTestContainer98Doc* GetDocument();
   CTestContainer98Item* m_pSelection;

// Operations
public:
   void ClearSelection();

// Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CTestContainer98View)
	public:
   virtual void OnDraw(CDC* pDC);  // overridden to draw this view
   virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
   virtual BOOL PreTranslateMessage(MSG* pMsg);
   virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual void OnDragLeave();
	protected:
   virtual void OnInitialUpdate(); // called first time after construct
   virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
   virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
   void OnFocus( CTestContainer98Item* pItem, BOOL tGotFocus );
   BOOL HandlePointerInactiveDragOver( CPoint point );
   BOOL HandlePointerInactiveMove( CPoint point, DWORD dwKeyState );
   BOOL HandlePointerInactiveSetCursor( DWORD dwMouseMessage );
   BOOL HandleWindowlessDragEnter( COleDataObject* pDataObject,
	  DWORD dwKeyState, CPoint point, DWORD* pdwDropEffect );
   void HandleWindowlessDragLeave();
   BOOL HandleWindowlessDragOver( COleDataObject* pDataObject,
	  DWORD dwKeyState, CPoint point, DWORD* pdwDropEffect );
   BOOL HandleWindowlessDrop( COleDataObject* pDataObject, DWORD dwKeyState,
	  CPoint point, DWORD* pdwDropEffect );
   BOOL HandleWindowlessKeyboardMessage();
   BOOL HandleWindowlessMouseMessage( CPoint point );
   HRESULT OnWindowlessDefWindowMessage( UINT nMessage, WPARAM wParam,
	  LPARAM lParam, LRESULT* plResult );
   HRESULT OnWindowlessReleaseCapture( CTestContainer98Item* pItem );
   HRESULT OnWindowlessReleaseFocus();
   HRESULT OnWindowlessSetCapture( CTestContainer98Item* pItem );
   HRESULT OnWindowlessSetFocus( CTestContainer98Item* pItem );
   CTestContainer98Item* GetItemWithCapture() const;
   CTestContainer98Item* GetItemWithFocus() const;
   void SetupSelectionTracker( CRectTracker* pTracker );
   void SetupTracker( CTestContainer98Item* pItem, CRectTracker* pTracker );
   void SetMultiSelect( CTestContainer98Item* pItem, BOOL tSelect );
   void SetSelection( CTestContainer98Item* pItem );
   void ToggleMultiSelect( CTestContainer98Item* pItem );
   CTestContainer98Item* HitTestItems( CPoint point, DWORD* pdwHitType );
   virtual ~CTestContainer98View();
#ifdef _DEBUG
   virtual void AssertValid() const;
   virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   // m_pSelection holds the selection to the current CTestContainer98Item.
   // For many applications, such a member variable isn't adequate to
   //  represent a selection, such as a multiple selection or a selection
   //  of objects that are not CTestContainer98Item objects.  This selection
   //  mechanism is provided just to help you get started.

   COleDropTarget m_dropTarget;
   CTestContainer98Item* m_pItemWithCapture;
   CTestContainer98Item* m_pItemWithFocus;
   CPoint m_ptLastMousePosition;
   CTestContainer98Item* m_pItemToDeactivateOnLeave;
   CTestContainer98Item* m_pInactiveDropTarget;
   CTestContainer98Item* m_pWindowlessDropTarget;
   DWORD m_dwLastDropKeyState;
   CTypedPtrList< CObList, CTestContainer98Item* > m_lpSelectedItems;

   static CLIPFORMAT s_cfObjectDescriptor;

// Generated message map functions
protected:
   //{{AFX_MSG(CTestContainer98View)
   afx_msg void OnDestroy();
   afx_msg void OnSetFocus(CWnd* pOldWnd);
   afx_msg void OnSize(UINT nType, int cx, int cy);
   afx_msg void OnInsertObject();
   afx_msg void OnCancelEditCntr();
   afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
   afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
   afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
   afx_msg void OnEditClear();
   afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);
   afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
   afx_msg void OnOptionsDesignMode();
   afx_msg void OnUpdateOptionsDesignMode(CCmdUI* pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnCancelMode();
	afx_msg void OnControlSaveToStream();
	afx_msg void OnEditInsertFromStream();
	afx_msg void OnControlSaveToPropertyBag();
	afx_msg void OnUpdateControlSaveToPropertyBag(CCmdUI* pCmdUI);
	afx_msg void OnUpdateControlSaveToStream(CCmdUI* pCmdUI);
	afx_msg void OnControlInvokeMethods();
	afx_msg void OnUpdateControlInvokeMethods(CCmdUI* pCmdUI);
	afx_msg void OnControlLogging();
	afx_msg void OnUpdateControlLogging(CCmdUI* pCmdUI);
	afx_msg void OnControlActivate();
	afx_msg void OnControlDeactivate();
	afx_msg void OnControlUIActivate();
	afx_msg void OnControlUIDeactivate();
	afx_msg void OnUpdateControlUIDeactivate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateControlUIActivate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateControlActivate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateControlDeactivate(CCmdUI* pCmdUI);
	afx_msg void OnEditBringToFront();
	afx_msg void OnUpdateEditBringToFront(CCmdUI* pCmdUI);
	afx_msg void OnEditSendToBack();
	afx_msg void OnUpdateEditSendToBack(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditProperties();
	afx_msg void OnUpdateEditProperties(CCmdUI* pCmdUI);
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnControlSaveToStorage();
	afx_msg void OnUpdateControlSaveToStorage(CCmdUI* pCmdUI);
	afx_msg void OnEditInsertControlFromStorage();
	afx_msg void OnUpdateEditSelectAll(CCmdUI* pCmdUI);
	afx_msg void OnControlDrawMetaFile();
	afx_msg void OnUpdateControlDrawMetaFile(CCmdUI* pCmdUI);
	//}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CTestContainer98View.cpp
inline CTestContainer98Doc* CTestContainer98View::GetDocument()
   { return (CTestContainer98Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTCONTAINER98VIEW_H__1981850A_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
