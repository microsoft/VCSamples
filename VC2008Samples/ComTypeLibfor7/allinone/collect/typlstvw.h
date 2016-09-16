// typlstvw.h : header file
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
// CTypedPtrListView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTypedPtrListView : public CFormView
{
public:
	CTypedPtrListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTypedPtrListView)

// Attributes
public:
	CCollectDoc* GetDocument();

// Overrides
public:
	void OnInitialUpdate();

// Form Data
public:
	//{{AFX_DATA(CTypedPtrListView)
	enum { IDD = IDD_TYPED_PTR_LIST };
	CListBox    m_ctlList;
	float   m_float;
	int     m_int;
	CString m_str;
	//}}AFX_DATA

// Implementation
protected:
	CMyStruct* FindMyStruct(int& nSel);
	void AddMyStructToListBox(CMyStruct* pMyStruct, int nSel = -1);

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTypedPtrListView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTypedPtrListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTypedPtrListView)
	afx_msg void OnAdd();
	afx_msg void OnUpdate();
	afx_msg void OnRemove();
	afx_msg void OnRemoveAll();
	afx_msg void OnSelChangeList();
	afx_msg void OnInsertBefore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG
inline CCollectDoc* CTypedPtrListView::GetDocument()
   { return (CCollectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
