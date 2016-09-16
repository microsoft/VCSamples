// ptarryvw.cpp : implementation file
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
#include "collect.h"
#include "colledoc.h"
#include "ptarryvw.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointArrayView

IMPLEMENT_DYNCREATE(CPointArrayView, CFormView)

CPointArrayView::CPointArrayView()
	: CFormView(CPointArrayView::IDD)
{
	//{{AFX_DATA_INIT(CPointArrayView)
	m_x = 0;
	m_y = 0;
	//}}AFX_DATA_INIT
}

CPointArrayView::~CPointArrayView()
{
}

void CPointArrayView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the points from the document's CArray of CPoints
	// to the listbox.
	m_ctlList.ResetContent();
	CArray<CPoint,CPoint>&ptArray = GetDocument()->m_ptArray;
	for (int nIndex = 0; nIndex < ptArray.GetSize(); nIndex++)
	{
		CPoint pt = ptArray[nIndex];
		AddPointToListBox(pt);
	}
}


void CPointArrayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPointArrayView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPointArrayView, CFormView)
	//{{AFX_MSG_MAP(CPointArrayView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdateButton)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CPointArrayView diagnostics

#ifdef _DEBUG
void CPointArrayView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPointArrayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CPointArrayView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CPointArrayView internal implementation

void CPointArrayView::AddPointToListBox(CPoint pt, int nSel)
{
	// Add new point to the listbox.
	CString str;
	str.Format(_T("(%i,%i)"), pt.x, pt.y);
	if (nSel == -1)
		nSel = m_ctlList.AddString(str);
	else
		m_ctlList.InsertString(nSel, str);
}


/////////////////////////////////////////////////////////////////////////////
// CPointArrayView message handlers

void CPointArrayView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	// Add new point to the CList<int,int>
	CPoint pt(m_x, m_y);
	GetDocument()->m_ptArray.Add(pt);

	AddPointToListBox(pt);
}

void CPointArrayView::OnUpdateButton()
{
	if (UpdateData() != TRUE)
		return;

	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_POINT_TO_BE_UPDATED);
		return;
	}

	// Replace the point in the CArray of CPoints.
	CPoint pt(m_x, m_y);
	GetDocument()->m_ptArray[nSel] = pt;

	// Update the old point in the listbox by removing
	// the old entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	AddPointToListBox(pt, nSel);
}

void CPointArrayView::OnRemove()
{
	if (UpdateData() != TRUE)
		return;

	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_POINT_TO_BE_REMOVED);
		return;
	}

	// Remove the point from the CArray of CPoints..
	GetDocument()->m_ptArray.RemoveAt(nSel);

	// Remove the point from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CPointArrayView::OnRemoveAll()
{
	// Remove all of the points from the CArray of CPoints.
	GetDocument()->m_ptArray.RemoveAll();

	// Remove all of the points from the listbox.
	m_ctlList.ResetContent();
}

void CPointArrayView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.
	CPoint pt = GetDocument()->m_ptArray[m_ctlList.GetCurSel()];
	m_x = pt.x;
	m_y = pt.y;
	UpdateData(FALSE);
}
