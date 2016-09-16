// typelib.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef ___TYPELIB_H__
#define ___TYPELIB_H__

#include "iviewer.h"

const int UPDF_NOTREEVIEW       = 0x0001 ;
const int UPDF_NOLISTVIEW       = 0x0002 ;
const int UPDF_NOODLVIEW        = 0x0004 ;


/////////////////////////////////////////////////////////////////////////////
// CTypeLibViewer command target
class CTypeLibViewer : public CInterfaceViewer
{
public:
	DECLARE_DYNCREATE(CTypeLibViewer)
	CTypeLibViewer();           // protected constructor used by dynamic creation
	virtual ~CTypeLibViewer();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeLibViewer)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL
	virtual HRESULT OnView(HWND hwndParent, REFIID riid, LPUNKNOWN punk);

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTypeLibViewer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CTypeLibViewer)
};

/////////////////////////////////////////////////////////////////////////////
// CTypeLibWnd frame
class CTypeLibTreeView ;
class CTypeLibListView ;
class CTypeLibODLView ;
class CTreeItem ;
class CTypeLibWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(CTypeLibWnd)
	CTypeLibWnd(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTypeLibWnd();


// Attributes
public:
	ITypeLib*       m_ptlb ;

	CSplitterWnd    m_wndSplitter ;
	CTypeLibTreeView*   m_pTreeView ;
	#ifdef _LIST_VIEW
	CTypeLibListView*   m_pListView ;
	#else
	CTypeLibODLView*    m_pODLView ;
	#endif

	CTreeItem*      m_pSelectedItem ;

	CStatusBar      m_wndStatusBar ;
	CToolBar        m_wndToolBar ;

	BOOL            m_fGroupByKind ;
// Operations
public:
	void RestorePosition();
	void UpdateAllViews( CView* pSender, LPARAM lHint = 0L, CObject* pHint = NULL ) ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeLibWnd)
	protected:
	virtual void PostNcDestroy();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL
	virtual BOOL OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pcc ) ;

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTypeLibWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnAppAbout();
	afx_msg void OnFileClose();
	afx_msg void OnViewGroupKind();
	afx_msg void OnUpdateViewGroupByKind(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif // ___TYPELIB_H__
