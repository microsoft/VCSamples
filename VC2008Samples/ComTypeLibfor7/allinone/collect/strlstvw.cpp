// strlstvw.cpp : implementation file
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
#include "strlstvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStringListView

IMPLEMENT_DYNCREATE(CStringListView, CFormView)

CStringListView::CStringListView()
	: CFormView(CStringListView::IDD)
{
	//{{AFX_DATA_INIT(CStringListView)
	m_strElement = "";
	//}}AFX_DATA_INIT
}

CStringListView::~CStringListView()
{
}

void CStringListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the strings from the document's CStringList
	// to the listbox.
	m_ctlList.ResetContent();
	IStlStringListPtr& stringList = GetDocument()->m_stringList;
	try {
	stringList->First();
	BSTR bstr;
	while (stringList->Next(&bstr))
	{
		CString str = bstr;
		::SysFreeString(bstr);
		m_ctlList.AddString(str);
	}
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CStringListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStringListView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_ELEMENT, m_strElement);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStringListView, CFormView)
	//{{AFX_MSG_MAP(CStringListView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdateElement)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	ON_BN_CLICKED(IDC_INSERT_BEFORE, OnInsertBefore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CStringListView diagnostics

#ifdef _DEBUG
void CStringListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStringListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CStringListView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStringListView internal implementation

BOOL CStringListView::FindString(int& nSel)
{
	nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_STRING_FIRST);
		return FALSE;
	}

	// The currently selected string in the listbox is the string
	// to be updated or removed .
	CString strOld;
	m_ctlList.GetText(nSel, strOld);

	try {
	// Find the string to be updated or replaced in the CStringList.
	return GetDocument()->m_stringList->Find((LPCTSTR) strOld);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CStringListView message handlers

void CStringListView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	try {
	// Add new string to the CStringList
	GetDocument()->m_stringList->Add = (LPCTSTR) m_strElement;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Add new string to the listbox.
	m_ctlList.AddString(m_strElement);
}

void CStringListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	// Find the string in both the CStringList and in the listbox.
	if (!FindString(nSel))
		return;

	try {
	// Insert in front of the string found in the CStringList
	GetDocument()->m_stringList->InsertBefore = (LPCTSTR) m_strElement;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Insert new string in the listbox
	m_ctlList.InsertString(nSel, m_strElement);
}

void CStringListView::OnUpdateElement()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	// Find the string in both the CStringList and in the listbox.
	if (!FindString(nSel))
		return;

	try {
	// Replace the value of the string in the CStringList.
	GetDocument()->m_stringList->SetAt = (LPCTSTR) m_strElement;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Replace the value of the string in the listbox by
	// removing the old string and adding the new string.
	m_ctlList.DeleteString(nSel);
	m_ctlList.InsertString(nSel, m_strElement);
}

void CStringListView::OnRemove()
{
	int nSel;
	// FInd the string in both the CStringList and in the listbox.
	if (!FindString(nSel))
		return;

	try {
	// Remove the string from the CStringList.
	GetDocument()->m_stringList->Remove;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Remove the string from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CStringListView::OnRemoveAll()
{
	try {
	// Remove all of the strings from the CStringList.
	GetDocument()->m_stringList->RemoveAll();
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Remove all of the strings from the listbox.
	m_ctlList.ResetContent();
}


void CStringListView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.
	m_ctlList.GetText(m_ctlList.GetCurSel(), m_strElement);
	UpdateData(FALSE);
}
