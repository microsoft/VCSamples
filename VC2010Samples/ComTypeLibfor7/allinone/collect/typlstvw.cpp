// typlstvw.cpp : implementation file
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
#include "typlstvw.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTypedPtrListView

IMPLEMENT_DYNCREATE(CTypedPtrListView, CFormView)

CTypedPtrListView::CTypedPtrListView()
	: CFormView(CTypedPtrListView::IDD)
{
	//{{AFX_DATA_INIT(CTypedPtrListView)
	m_float = 0.0f;
	m_int = 0;
	m_str = "";
	//}}AFX_DATA_INIT
}

CTypedPtrListView::~CTypedPtrListView()
{
}

void CTypedPtrListView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	try {
	// Copy all of the strings from the document's CTypedPtrList
	// to the listbox.
	m_ctlList.ResetContent();
	IStlMyStructListPtr& mystructList = GetDocument()->m_mystructList;
	mystructList->First();
	IMyStruct* pMyStruct = NULL;
	while (mystructList->Next(&pMyStruct))
		AddMyStructToListBox((CMyStruct*) pMyStruct);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTypedPtrListView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_FLOAT, m_float);
	DDX_Text(pDX, IDC_INT, m_int);
	DDX_Text(pDX, IDC_STRING, m_str);
	//}}AFX_DATA_MAP
	if (pDX->m_bSaveAndValidate && _tcschr(m_str, ' ') != NULL)
	{
		AfxMessageBox(IDS_BLANK_CHARS_NOT_ALLOWED);
		pDX->Fail();
	}
}


BEGIN_MESSAGE_MAP(CTypedPtrListView, CFormView)
	//{{AFX_MSG_MAP(CTypedPtrListView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	ON_BN_CLICKED(IDC_INSERT_BEFORE, OnInsertBefore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTypedPtrListView diagnostics

#ifdef _DEBUG
void CTypedPtrListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTypedPtrListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CTypedPtrListView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CmystructListView internal implementation

CMyStruct* CTypedPtrListView::FindMyStruct(int& nSel)
{
	try {
	nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_ENTRY);
		return NULL;
	}

	// The CMyStruct pointer was saved as the listbox entry's data item.
	CMyStruct* pMyStruct = (CMyStruct*)m_ctlList.GetItemDataPtr(nSel);

	// Find the CMyStruct pointer in the CTypedPtrList.
	return GetDocument()->m_mystructList->Find(pMyStruct) ? pMyStruct : NULL;
	} catch(_com_error& e) {
		dump_com_error(e);
	}
	return NULL;
}

void CTypedPtrListView::AddMyStructToListBox(CMyStruct* pMyStruct, int nSel)
{
	try {
	// Add new CMyStruct to the listbox.
	CString str;
	pMyStruct->Format(str);
	if (nSel == -1)
		nSel = m_ctlList.AddString(str);
	else
		m_ctlList.InsertString(nSel, str);
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Save the CMyStruct pointer as the listbox entry's "data item".
	m_ctlList.SetItemDataPtr(nSel, pMyStruct);
}


/////////////////////////////////////////////////////////////////////////////
// CTypedPtrListView message handlers

void CTypedPtrListView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	try {
	// Add new CMyStruct to the CTypedPtrList
	CMyStruct* pMyStruct = new CMyStruct;
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str.AllocSysString();
	GetDocument()->m_mystructList->Add = pMyStruct;

	AddMyStructToListBox(pMyStruct);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	if (!FindMyStruct(nSel))
		return;

	try {
	// Insert new CMyStruct in the CTypedPtrList
	CMyStruct* pMyStruct = new CMyStruct;
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str.AllocSysString();
	GetDocument()->m_mystructList->InsertBefore = pMyStruct;

	AddMyStructToListBox(pMyStruct, nSel);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::OnUpdate()
{
	if (UpdateData() != TRUE)
		return;

	try {
	int nSel;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel);
	if (pMyStruct == NULL)
		return;

	// Replace the value of the CMyStruct in the CTypedPtrList.
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str.AllocSysString();

	// Replace the displayed CMyStruct in the listbox by removing
	// the old listbox entry and adding a new entry.
	AddMyStructToListBox(pMyStruct, nSel);
	m_ctlList.DeleteString(nSel);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::OnRemove()
{
	try {
	int nSel;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel);
	if (pMyStruct == NULL)
		return;

	// Remove the CMyStruct ptr from the CTypedPtrList.
	GetDocument()->m_mystructList->Remove;

	// Delete the CMyStruct object. (The CTypePtrList only holds the ptr.)
	delete (CMyStruct*) pMyStruct;

	// Remove the corresponding entry from the listbox.
	m_ctlList.DeleteString(nSel);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::OnRemoveAll()
{
	try {
	IStlMyStructListPtr& mystructList = GetDocument()->m_mystructList;

	// Delete all of the CMyStruct objects pointed to
	// by the CTypedPtrList. Then remove all of the
	// CMyStruct pointers from the CTypedPtrList, which
	// is faster than removing each individually.
	mystructList->First();
	IMyStruct* pstr = NULL;
	while (mystructList->Next(&pstr))
		delete (CMyStruct*) pstr;
	mystructList->RemoveAll();

	// Remove all of the corresponding formatted strings from the listbox.
	m_ctlList.ResetContent();
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrListView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.

	int nSel;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel);

	m_int = pMyStruct->m_int;
	m_float = pMyStruct->m_float;
	m_str = pMyStruct->m_str;

	UpdateData(FALSE);
}
