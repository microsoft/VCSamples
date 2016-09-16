// DBVListView.h : interface of the CDBVListView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_DBVLISTVIEW_H__13CCB74B_ED59_11D0_8286_00C04FD73634__INCLUDED_)
#define AFX_DBVLISTVIEW_H__13CCB74B_ED59_11D0_8286_00C04FD73634__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDBVListSet;

class CDBVListView : public CFormView
{
protected: // create from serialization only
	CDBVListView();
	DECLARE_DYNCREATE(CDBVListView)

public:
	//{{AFX_DATA(CDBVListView)
	enum { IDD = IDD_DBVLIST_FORM };
	CDBVListSet* m_pSet;
	CString m_strDiv;
	//}}AFX_DATA

// Attributes
public:
	CDBVListDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBVListView)
	public:
	virtual CDaoRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBVListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBVListView)
	afx_msg void OnFetch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBVListView.cpp
inline CDBVListDoc* CDBVListView::GetDocument()
   { return (CDBVListDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBVLISTVIEW_H__13CCB74B_ED59_11D0_8286_00C04FD73634__INCLUDED_)
