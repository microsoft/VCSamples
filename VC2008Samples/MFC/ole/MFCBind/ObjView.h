// ObjView.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_OBJLISTVIEW_H__7C3F7403_C7B1_11D0_8FAD_00A0C9034892__INCLUDED_)
#define AFX_OBJLISTVIEW_H__7C3F7403_C7B1_11D0_8FAD_00A0C9034892__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CObjListView view
#define ITEM_HEIGHT 60

class CObjListView;
struct CItemIcons
{
	CItemIcons(){}
	~CItemIcons(){}
	CString m_Name;
	HICON m_hIcon;
	COleClientItem *m_pObject;
};


/////////////////////////////////////////////////////////////////////////////
// CCustomList window

class CCustomList : public CListBox
{
// Construction
public:
	CCustomList();
	CCustomList(CObjListView *pParent):m_pParent(pParent){}
	void MeasureItem(LPMEASUREITEMSTRUCT lpm);
	void DrawItem(LPDRAWITEMSTRUCT ldis);
	CObjListView *m_pParent;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomList)
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


class CObjListView : public CView
{
protected:
	CObjListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CObjListView)
	BOOL AddItem(COleClientItem* pObject, CString& name, HICON hIcon);
	BOOL RemoveItem(COleClientItem* pItem);
	void RemoveAllItems();
	CCustomList m_listbox;

// Attributes
public:

// Operations
public:
	CFont m_IconFont;
	BOOL m_bFont;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CObjListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CObjListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CObjListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OBJLISTVIEW_H__7C3F7403_C7B1_11D0_8FAD_00A0C9034892__INCLUDED_)
