// regview.h : header file
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
// CRegistryView form view

#ifndef __REGVIEW_H__
#define __REGVIEW_H__

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CRegistryView : public CFormView
{
protected:
	CRegistryView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRegistryView)

// Form Data
public:
	COle2ViewDoc* GetDocument();

	//{{AFX_DATA(CRegistryView)
	enum { IDD = IDD_REGVIEW };
	CStatic m_Name;
	CStatic m_CLSID;
	CStatic m_icon;
	CTreeCtrl   m_tree;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegistryView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRegistryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRegistryView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnUnregister();
	afx_msg void OnTreeViewItemExpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetDispInfoTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetDispInfoTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteItemTreeView(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in vw.cpp
inline COle2ViewDoc* CRegistryView::GetDocument()
   { return (COle2ViewDoc*) m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
#endif
