// EmpView.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_EMPVIEW_H__1FF640C9_B507_11D0_BE98_00C04FC99F83__INCLUDED_)
#define AFX_EMPVIEW_H__1FF640C9_B507_11D0_BE98_00C04FC99F83__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CEmpView view

class CEmpView : public CListView
{
protected:
	CEmpView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CEmpView)

// Attributes
public:
	CDBVListDoc* GetDocument();

// Operations
public:
	void UpdateFilter(CString strCurQuery);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmpView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	protected:
	//}}AFX_VIRTUAL
	void PrepareCache(int iFrom, int iTo);
	void GetDispInfo(LVITEM* pItem);
	int FindItem(int iStart, LVFINDINFO* plvfi);

// Implementation
protected:
	virtual ~CEmpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CEmpView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg void OnColumnClick(UINT id, NMHDR* pNotifyStruct, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBVListView.cpp
inline CDBVListDoc* CEmpView::GetDocument()
   { return (CDBVListDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPVIEW_H__1FF640C9_B507_11D0_BE98_00C04FC99F83__INCLUDED_)
