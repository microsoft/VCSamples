// obj_vw.h
//
// Interface def for CObjTreeView
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _OBJ_VW_H_
#define _OBJ_VW_H_

#include "view.h"

/////////////////////////////////////////////////////////////////////////////
// CObjectData

class CObjectData : public CObject
{
	DECLARE_DYNCREATE(CObjectData)
public:
	CObjectData() ;
	virtual ~CObjectData() ;

	HRESULT CreateInstance( DWORD clsctx ) ;
	BOOL Release() ;

	DWORD           m_nType;

	CLSID           m_clsid ;
	TCHAR           m_szProgID[40] ; // max 39 chars
	WORD            m_wMajorVer, m_wMinorVer ;
	UINT            m_uiBitmap ;
	IClassFactory*  m_pcf ;
	IUnknown*       m_punk ;

	enum {
		typeUnknown,
		typeObject,
		typeTypeLib,
		typeInterface,
		typeStaticInterface
	};

} ;


class CObjTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CObjTreeView)
protected: // create from serialization only
	CObjTreeView();

// Attributes
public:

	COle2ViewDoc* GetDocument();
	HTREEITEM     m_hObjects;
	HTREEITEM     m_hTypeLibs ;
	HTREEITEM     m_hInterfaces;

	HTREEITEM     m_hInsertable ;
	HTREEITEM     m_hControls ;
	HTREEITEM     m_hInternal ;
#ifdef SHOW_CONTAINERS
	HTREEITEM     m_hContainers ;
#endif
	HTREEITEM     m_hOLE1 ;
	HTREEITEM     m_hUnclassified ;

// Operations
public:
	void DeleteTreeContents() ;
	void DeleteTreeItems( HTREEITEM htree ) ;
	BOOL IsValidSel() ;
	void ExpandInterfaces( NM_TREEVIEW* pNMTreeView );
	void ExpandTypeLibs( NM_TREEVIEW* pNMTreeView );
	void ExpandClassification( NM_TREEVIEW* pNMTreeView );
	void ExpandObject( NM_TREEVIEW* pNMTreeView );
	void CallInterfaceViewer(CObjectData* pObjectData, HTREEITEM hItem);

// Implementation
public:

	virtual ~CObjTreeView();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint ) ;
	virtual void OnDraw( CDC* pdc );
	virtual void OnInitialUpdate();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// Generated message map functions
protected:
	//{{AFX_MSG(CObjTreeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnObjectDelete();
	afx_msg void OnObjectVerify();
	afx_msg void OnUseInProcServer();
	afx_msg void OnUpdateUseInProcServer(CCmdUI* pCmdUI);
	afx_msg void OnUseInProcHandler();
	afx_msg void OnUpdateUseInProcHandler(CCmdUI* pCmdUI);
	afx_msg void OnUseLocalServer();
	afx_msg void OnUpdateUseLocalServer(CCmdUI* pCmdUI);
	afx_msg void OnFileBind();
	//}}AFX_MSG
	afx_msg void OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeItemExpanding(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeItemExpanded(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeDeleteItem(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg void OnTreeReturn(NMHDR* pNMHDR, LRESULT* pResult) ;
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM lParam) ;
	DECLARE_MESSAGE_MAP()

	friend class CMainFrame;
};

#ifndef _DEBUG  // debug version in vw.cpp
inline COle2ViewDoc* CObjTreeView::GetDocument()
   { return (COle2ViewDoc*) m_pDocument; }
#endif

#endif // _OBJ_VW_H_
