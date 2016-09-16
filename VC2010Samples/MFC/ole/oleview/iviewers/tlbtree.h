// tlbtree.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __TLBTREE_H__
#define __TLBTREE_H__

#include "tree.h"

/////////////////////////////////////////////////////////////////////////////
// CTypeLibTreeView view
#define ID_TREEVIEW 42
class CTypeLibTreeView : public CView
{
friend class CTypeLibWnd ;
public:
	CTypeLibTreeView();           // protected constructor used by dynamic creation
	virtual ~CTypeLibTreeView();
	DECLARE_DYNCREATE(CTypeLibTreeView)

// Attributes
public:
	CTreeCtrl       m_tree ;

	ITypeLib*       m_ptlb ;

	enum {IMGID_TYPELIB = 0,
		  IMGID_TYPEINFO_C,
		  IMGID_TYPEINFO_O };
	CImageList      m_images ;
	HTREEITEM       m_hTypeInfos ;

// Operations
public:
	void DeleteTreeItems( HTREEITEM htree ) ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTypeLibTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTypeLibTreeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg void OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeItemExpanding(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeItemExpanded(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeItemReturn(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeDeleteItem(NMHDR* pNMHDR, LRESULT* pResult) ;
	DECLARE_MESSAGE_MAP()
};
#endif // __TLBTREE_H__

/////////////////////////////////////////////////////////////////////////////
