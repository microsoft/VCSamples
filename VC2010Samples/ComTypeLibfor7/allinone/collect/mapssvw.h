// mapssvw.h : header file
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
// CMapStringToStringView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMapStringToStringView : public CFormView
{
public:
	CMapStringToStringView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMapStringToStringView)

// Form Data
public:
	//{{AFX_DATA(CMapStringToStringView)
	enum { IDD = IDD_MAP_STRING_TO_STRING };
	CListBox    m_ctlList;
	CString m_strKey;
	CString m_strValue;
	//}}AFX_DATA

// Attributes
public:
	CCollectDoc* GetDocument();

// Overrides
public:
	void OnInitialUpdate();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMapStringToStringView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int FindKeyInListBox(CString& strKey);
	void AddMapEntryToListBox(CString& strKey, CString& strValue);

	virtual ~CMapStringToStringView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMapStringToStringView)
	afx_msg void OnAddOrUpdate();
	afx_msg void OnFind();
	afx_msg void OnRemove();
	afx_msg void OnRemoveAll();
	afx_msg void OnSelChangeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG
inline CCollectDoc* CMapStringToStringView::GetDocument()
   { return (CCollectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
