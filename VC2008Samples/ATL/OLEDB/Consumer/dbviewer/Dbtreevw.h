// DBTreeVw.h : header file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#ifndef __DBTREEVW_H__
#define __DBTREEVW_H__

/////////////////////////////////////////////////////////////////////////////
// CDBTreeView view

class CDBTreeView : public CTreeView
{
protected:
	CDBTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDBTreeView)

// Attributes
public:
	UINT m_nIDClipFormat;
	CTreeCursor m_ItemSel;
	BOOL m_bNoNotifications;
	CDBViewDoc* GetDocument();
	CSession*   m_pSession;

	enum ImageIDS{
		IID_DATABASE = 0,IID_DATABASES,
		IID_TABLE,IID_TABLES,
		IID_FIELD,IID_FIELDS,
		IID_INDEX,IID_INDEXES,
		IID_VIEW,IID_VIEWS,
		IID_PROCEDURE,IID_PROCEDURES,
		IID_FOREIGNKEY, IID_FOREIGNKEYS
	};

protected:
	CImageList m_ctlImage;

	// Some bookmarks to places in the tree
	CTreeCursor tDatabases, tDatabase;
	CTreeCursor tTables, tTable;
	CTreeCursor tView, tProcedures;

	COleDropTarget m_dropTarget;

// Operations
public:
	void PopulateTree();
	void AddItem(WORD nItemType, LPCTSTR lpszName);
	void DeleteItem(CTreeCursor& itemDelete);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBTreeView)
	protected:
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDBTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDBTreeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSysColorChange();
	afx_msg void OnQueryEdit();
	//}}AFX_MSG
	afx_msg void OnPopupCommand(UINT nMenuID);
	void OnNodeSelect(NMHDR *pNotifyStruct,LRESULT *result);
	void OnKeyDown(NMHDR *pNotifyStruct,LRESULT *result);
	void OnRightClick(NMHDR *pNotifyStruct,LRESULT *result);
	void DoPopupMenu(UINT nMenuID);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBViewVw.cpp
inline CDBViewDoc* CDBTreeView::GetDocument()
   { return (CDBViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

#endif // __DBTREEVW_H__

/////////////////////////////////////////////////////////////////////////////
