// npview.h : interface of the CNotepadView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

class CFindDlg;     // forward declarations
class CGotoDlg;

#include "history.h"

class CNotepadView : public CEditView
{
protected: // create from serialization only
	CNotepadView();
	DECLARE_DYNCREATE(CNotepadView)

// Attributes
public:
	CNotepadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotepadView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

public:
// Attributes
	CFindDlg*    m_pFindDialog;             // find dialog
	CGotoDlg*    m_pGotoDialog;             // goto line number dialog
	CHistoryList m_searchHistory;           // last used search history list

public:
// Operations
	void OnViewFindNext(CString &s1);

// Implementation
public:
	virtual ~CNotepadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNotepadView)
	afx_msg void OnEditGoto();
	afx_msg void OnUpdateEditGoto(CCmdUI* pCmdUI);
	afx_msg void OnEditFind();
	afx_msg void OnUpdateEditFind(CCmdUI* pCmdUI);
	afx_msg void OnViewFindNext();
	afx_msg void OnEditPaste();
	afx_msg void OnEditCopy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in npview.cpp
inline CNotepadDoc* CNotepadView::GetDocument()
   { return (CNotepadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
