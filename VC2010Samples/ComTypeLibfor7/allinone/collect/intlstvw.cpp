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
	IStlintListPtr& intList = GetDocument()->m_intList;
	try {
	intList->First();
	long n = 0;
	while (intList->Next(&n))
		AddIntToListBox(n);
	} catch(_com_error& e) {
		dump_com_error(e);
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
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
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

BOOL CIntListView::FindInt(int& nSel)
{
	nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_INTEGER);
		return FALSE;
	}

	int nValue = (int)m_ctlList.GetItemData(nSel);

	try {
	// Find the integer in the integer list.
	return GetDocument()->m_intList->Find(nValue);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
	return FALSE;
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

	try {
	// Add new integer to the CList<int,int>
	GetDocument()->m_intList->Add = m_int;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	AddIntToListBox(m_int);
}

void CIntListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	// Find the integer in both the CList<int,int> and the listbox.
	if (!FindInt(nSel))
		return;


	try {
	// Insert in front of the integer found in the CList<int,int>
	GetDocument()->m_intList->InsertBefore = m_int;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Insert new integer in the listbox
	AddIntToListBox(m_int, nSel);
}

void CIntListView::OnUpdate()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	// Find the integer in both the CList<int,int> and the listbox.
	if (!FindInt(nSel))
		return;

	try {
	// Replace the integer in the CList<int,int>.
	GetDocument()->m_intList->SetAt = m_int;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Update the old integer in the listbox by removing
	// the old entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	AddIntToListBox(m_int, nSel);
}

void CIntListView::OnRemove()
{
	int nSel;
	// Find the string in both the CList<int,int> and in the listbox.
	if (!FindInt(nSel))
		return;

	try {
	// Remove the integer from the CList<int,int>.
	GetDocument()->m_intList->Remove;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Remove the integer from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CIntListView::OnRemoveAll()
{
	try {
	// Remove all of the integers from the CList<int,int>.
	GetDocument()->m_intList->RemoveAll();
	} catch(_com_error& e) {
		dump_com_error(e);
	}

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
