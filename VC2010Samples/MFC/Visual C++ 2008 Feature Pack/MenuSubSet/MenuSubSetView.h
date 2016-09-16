// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CMenuSubSetView : public CFormView
{
protected: // create from serialization only
	CMenuSubSetView();
	DECLARE_DYNCREATE(CMenuSubSetView)

public:
	enum{ IDD = IDD_MENUSUBSET_FORM };

// Attributes
public:
	CMenuSubSetDoc* GetDocument();

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMenuSubSetView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnDemoDemo1();
	afx_msg void OnDemoDemo2();
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnFilePrintPreview();

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MenuSubSetView.cpp
inline CMenuSubSetDoc* CMenuSubSetView::GetDocument()
   { return (CMenuSubSetDoc*)m_pDocument; }
#endif
