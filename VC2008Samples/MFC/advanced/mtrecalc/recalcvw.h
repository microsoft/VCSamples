// recalcvw.h : interface of the CRecalcView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#define UPDATE_HINT_SUM 1

class CRecalcView : public CFormView
{
protected: // create from serialization only
	CRecalcView();
	DECLARE_DYNCREATE(CRecalcView)

public:
	//{{AFX_DATA(CRecalcView)
	enum { IDD = IDD_MTRECALC_FORM };
	CEdit   m_ctlSum;
	int     m_nInt1;
	int     m_nInt2;
	//}}AFX_DATA

// Attributes
public:
	CRecalcDoc* GetDocument();
protected:
	BOOL    m_bFirstKillFocus;  // to avoid multiple (infinite) validations on kill focus

// Operations
public:

	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRecalcView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:

	virtual ~CRecalcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	LRESULT OnRecalcDone(WPARAM wParam, LPARAM lParam);
	LRESULT OnRecalcNowMsg(WPARAM wParam, LPARAM lParam);
	//{{AFX_MSG(CRecalcView)
	afx_msg void OnKillFocus();
	afx_msg void OnRecalculateNow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in recalcvw.cpp
inline CRecalcDoc* CRecalcView::GetDocument()
   { return (CRecalcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
