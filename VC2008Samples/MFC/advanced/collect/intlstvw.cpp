// intlstvw.cpp : implementation file
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
#include "intlstvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIntListView

IMPLEMENT_DYNCREATE(CIntListView, CFormView)

CIntListView::CIntListView()
	: CFormView(CIntListView::IDD)
{
	//{{AFX_DATA_INIT(CIntListView)
	m_int = 0;
	//}}AFX_DATA_INIT
}

CIntListView::~CIntListView()
{
}

void CIntListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the integers from the document's CList<int,int>
	// to the listbox.
	m_ctlList.ResetContent();
	CList<int,int>& intList = GetDocument()->m_intList;
	POSITION pos = intList.GetHeadPosition();
	while (pos != NULL)
	{
		int n = intList.GetNext(pos);
		AddIntToListBox(n);
	}
}


void CIntListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIntListView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_ELEMENT, m_int);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIntListView, CFormView)
	//{{AFX_MSG_MAP(CIntListView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdateButton)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	ON_BN_CLICKED(IDC_INSERT_BEFORE, OnInsertBefore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CIntListView diagnostics

#ifdef _DEBUG
void CIntListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIntListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CIntListView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIntListView internal implementation

BOOL CIntListView::FindInt(int& nSel, POSITION& pos)
{
	nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_INTEGER);
		return FALSE;
	}

	int nValue = (int)m_ctlList.GetItemData(nSel);

	// Find the integer in the integer list.
	pos = GetDocument()->m_intList.Find(nValue);

	// If the integer is in the listbox, it must also be in the integer list
	ASSERT(pos != NULL);

	return TRUE;
}

void CIntListView::AddIntToListBox(int n, int nSel)
{
	// Add new integer to the listbox.
	CString str;
	str.Format(_T("%i"),n);
	if (nSel == -1)
		nSel = m_ctlList.AddString(str);
	else
		m_ctlList.InsertString(nSel, str);

	// Save the integer as the listbox entry's "data item".
	m_ctlList.SetItemData(nSel, (DWORD)n);
}


/////////////////////////////////////////////////////////////////////////////
// CIntListView message handlers

void CIntListView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	// Add new integer to the CList<int,int>
	GetDocument()->m_intList.AddTail(m_int);

	AddIntToListBox(m_int);
}

void CIntListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the integer in both the CList<int,int> and the listbox.
	if (FindInt(nSel, pos) != TRUE)
		return;


	// Insert in front of the integer found in the CList<int,int>
	POSITION posTemp = 0;
	posTemp = GetDocument()->m_intList.InsertBefore(pos, m_int);

	// Insert new integer in the listbox
	AddIntToListBox(m_int, nSel);
}

void CIntListView::OnUpdateButton()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the integer in both the CList<int,int> and the listbox.
	if (FindInt(nSel, pos) != TRUE)
		return;

	// Replace the integer in the CList<int,int>.
	GetDocument()->m_intList.SetAt(pos, m_int);

	// Update the old integer in the listbox by removing
	// the old entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	AddIntToListBox(m_int, nSel);
}

void CIntListView::OnRemove()
{
	int nSel;
	POSITION pos;
	// Find the string in both the CList<int,int> and in the listbox.
	if (FindInt(nSel, pos) != TRUE)
		return;


	// Remove the integer from the CList<int,int>.
	GetDocument()->m_intList.RemoveAt(pos);

	// Remove the integer from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CIntListView::OnRemoveAll()
{
	// Remove all of the integers from the CList<int,int>.
	GetDocument()->m_intList.RemoveAll();

	// Remove all of the integers from the listbox.
	m_ctlList.ResetContent();
}

void CIntListView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.
	m_int = (int)m_ctlList.GetItemData(m_ctlList.GetCurSel());
	UpdateData(FALSE);
}
