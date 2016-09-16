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

	// Copy all of the strings from the document's CTypedPtrList
	// to the listbox.
	m_ctlList.ResetContent();
	CMyStructList& mystructList = GetDocument()->m_mystructList;
	POSITION pos = mystructList.GetHeadPosition();
	while (pos != NULL)
	{
		CMyStruct* pMyStruct = mystructList.GetNext(pos);
		AddMyStructToListBox(pMyStruct);
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
	ON_BN_CLICKED(IDC_UPDATE, OnUpdateButton)
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

CMyStruct* CTypedPtrListView::FindMyStruct(int& nSel, POSITION& pos)
{
	nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_ENTRY);
		return NULL;
	}

	// The CMyStruct pointer was saved as the listbox entry's data item.
	CMyStruct* pMyStruct = (CMyStruct*)m_ctlList.GetItemDataPtr(nSel);

	// Find the CMyStruct pointer in the CTypedPtrList.
	pos = GetDocument()->m_mystructList.Find(pMyStruct);

	// If the CMyStruct is displayed in the listbox, it should also be
	// found in the CTypedPtrList.
	ASSERT(pos != NULL);

	return pMyStruct;
}

void CTypedPtrListView::AddMyStructToListBox(CMyStruct* pMyStruct, int nSel)
{
	// Add new CMyStruct to the listbox.
	CString str;
	pMyStruct->FormatMyStruct(str);
	if (nSel == -1)
		nSel = m_ctlList.AddString(str);
	else
		m_ctlList.InsertString(nSel, str);

	// Save the CMyStruct pointer as the listbox entry's "data item".
	m_ctlList.SetItemDataPtr(nSel, pMyStruct);
}


/////////////////////////////////////////////////////////////////////////////
// CTypedPtrListView message handlers

void CTypedPtrListView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	// Add new CMyStruct to the CTypedPtrList
	CMyStruct* pMyStruct = new CMyStruct;
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str;
	GetDocument()->m_mystructList.AddTail(pMyStruct);

	AddMyStructToListBox(pMyStruct);
}

void CTypedPtrListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	if (FindMyStruct(nSel, pos) == NULL)
		return;

	// Insert new CMyStruct in the CTypedPtrList
	CMyStruct* pMyStruct = new CMyStruct;
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str;
	GetDocument()->m_mystructList.InsertBefore(pos, pMyStruct);

	AddMyStructToListBox(pMyStruct, nSel);
}

void CTypedPtrListView::OnUpdateButton()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel, pos);
	if (pMyStruct == NULL)
		return;

	// Replace the value of the CMyStruct in the CTypedPtrList.
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str;

	// Replace the displayed CMyStruct in the listbox by removing
	// the old listbox entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	AddMyStructToListBox(pMyStruct, nSel);
}

void CTypedPtrListView::OnRemove()
{
	int nSel;
	POSITION pos;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel, pos);
	if (pMyStruct == NULL)
		return;

	// Remove the CMyStruct ptr from the CTypedPtrList.
	GetDocument()->m_mystructList.RemoveAt(pos);

	// Delete the CMyStruct object. (The CTypePtrList only holds the ptr.)
	delete pMyStruct;

	// Remove the corresponding entry from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CTypedPtrListView::OnRemoveAll()
{
	CMyStructList& mystructList = GetDocument()->m_mystructList;

	// Delete all of the CMyStruct objects pointed to
	// by the CTypedPtrList. Then remove all of the
	// CMyStruct pointers from the CTypedPtrList, which
	// is faster than removing each individually.
	POSITION pos = mystructList.GetHeadPosition();
	while (pos != NULL)
	{
		delete mystructList.GetNext(pos);
	}
	mystructList.RemoveAll();

	// Remove all of the corresponding formatted strings from the listbox.
	m_ctlList.ResetContent();
}

void CTypedPtrListView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.

	int nSel;
	POSITION pos;
	// Find the CMyStruct in the CTypedPtrList and listbox.
	CMyStruct* pMyStruct = FindMyStruct(nSel, pos);

	m_int = pMyStruct->m_int;
	m_float = pMyStruct->m_float;
	m_str = pMyStruct->m_str;

	UpdateData(FALSE);
}
