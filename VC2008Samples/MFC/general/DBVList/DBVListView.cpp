// DBVListView.cpp : implementation of the CDBVListView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "DBVList.h"

#include "DBVListSet.h"
#include "DBVListDoc.h"
#include "DBVListView.h"
#include "MainFrm.h"
#include "EmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBVListView

IMPLEMENT_DYNCREATE(CDBVListView, CFormView)

BEGIN_MESSAGE_MAP(CDBVListView, CFormView)
	//{{AFX_MSG_MAP(CDBVListView)
	ON_BN_CLICKED(IDC_FETCH, OnFetch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBVListView construction/destruction

CDBVListView::CDBVListView()
	: CFormView(CDBVListView::IDD)
{
	//{{AFX_DATA_INIT(CDBVListView)
	m_pSet = NULL;
	m_strDiv = _T("");
	//}}AFX_DATA_INIT
}

CDBVListView::~CDBVListView()
{
}

void CDBVListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDBVListView)
	DDX_CBString(pDX, IDC_DIV, m_strDiv);
	//}}AFX_DATA_MAP
}

BOOL CDBVListView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void CDBVListView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_dBVListSet;
	CFormView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CDBVListView diagnostics

#ifdef _DEBUG
void CDBVListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDBVListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDBVListDoc* CDBVListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBVListDoc)));
	return (CDBVListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBVListView database support
CDaoRecordset* CDBVListView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDBVListView message handlers

void CDBVListView::OnFetch()
{
	CMainFrame* pFrame=static_cast<CMainFrame*>(AfxGetMainWnd());
	CEmpView* pView=static_cast<CEmpView*>(pFrame->m_wndSplitter.GetPane(1,0));

	// set the filter for viewing the database to the currently selected division
	UpdateData(TRUE);
	pView->UpdateFilter(m_strDiv);
}
