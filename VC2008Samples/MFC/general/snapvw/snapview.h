// SnapView.h : interface of the CSnapView class
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

class CSnapView : public CFormView
{
protected: // create from serialization only
	CSnapView();
	DECLARE_DYNCREATE(CSnapView)

public:
	//{{AFX_DATA(CSnapView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CSnapDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnapView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSnapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// tracks whether parent frame has already been sized.
	BOOL m_bSizedBefore;

	// property sheet is wired to MDI child frame and is not displayed
	CPropertySheet* m_pPropSheet;

	// one page for each menu so we can initialize controls
	// using OnInitDialog
	CPropertyPage* m_pPageBkfst;
	CPropertyPage* m_pPageLunch;
	CPropertyPage* m_pPageDinner;

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDraw(CDC* pDC);

// Generated message map functions
protected:
	//{{AFX_MSG(CSnapView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnapView.cpp
inline CSnapDoc* CSnapView::GetDocument()
   { return (CSnapDoc*) m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
