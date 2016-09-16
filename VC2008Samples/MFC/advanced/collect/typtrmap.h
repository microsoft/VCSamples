// typtrmap.h : header file
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
// CTypedPtrMapView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTypedPtrMapView : public CFormView
{
public:
	CTypedPtrMapView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTypedPtrMapView)

// Form Data
public:
	//{{AFX_DATA(CTypedPtrMapView)
	enum { IDD = IDD_TYPED_PTR_MAP };
	CListBox    m_ctlList;
	CString m_strKey;
	int     m_int;
	float   m_float;
	CString m_str;
	//}}AFX_DATA

// Attributes
public:
	CCollectDoc* GetDocument();

// Overrides
public:
	void OnInitialUpdate();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTypedPtrMapView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	static CString FormatListBoxEntry(CString& strKey, CMyObject* pMyObject);
	int FindKeyInListBox(CString& strKey);
	void AddMapEntryToListBox(CString& strKey, CMyObject* pMyObject);
	CMyObject* ConstructMyObjectFromView();
	void UpdateViewFromMyObject(CMyObject* pMyObject);

	virtual ~CTypedPtrMapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTypedPtrMapView)
	afx_msg void OnAddOrUpdate();
	afx_msg void OnFind();
	afx_msg void OnRemove();
	afx_msg void OnRemoveAll();
	afx_msg void OnSelChangeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG
inline CCollectDoc* CTypedPtrMapView::GetDocument()
   { return (CCollectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
