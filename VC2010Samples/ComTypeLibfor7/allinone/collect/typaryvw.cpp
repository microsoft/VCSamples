// typaryvw.cpp : implementation file
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
#include "typaryvw.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTypedPtrArrayView

IMPLEMENT_DYNCREATE(CTypedPtrArrayView, CFormView)

CTypedPtrArrayView::CTypedPtrArrayView()
	: CFormView(CTypedPtrArrayView::IDD)
{
	//{{AFX_DATA_INIT(CTypedPtrArrayView)
	m_int = 0;
	m_float = 0.0f;
	m_str = "";
	//}}AFX_DATA_INIT
}

CTypedPtrArrayView::~CTypedPtrArrayView()
{
}

void CTypedPtrArrayView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	try {
	// Copy all of the entries from the document's CTypedPtrArray
	// to the listbox.
	m_ctlList.ResetContent();
	IStlMyObjectArrayPtr& myobArray = GetDocument()->m_myobArray;
	for (int nIndex = 0; nIndex < (int) myobArray->Count; nIndex++)
	{
		CMyObject* pMyObject = (CMyObject*) myobArray->Array[nIndex];
		AddMyObjectToListBox(pMyObject);
	}
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrArrayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTypedPtrArrayView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_INT, m_int);
	DDX_Text(pDX, IDC_FLOAT, m_float);
	DDX_Text(pDX, IDC_STRING, m_str);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTypedPtrArrayView, CFormView)
	//{{AFX_MSG_MAP(CTypedPtrArrayView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdate)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CTypedPtrArrayView diagnostics

#ifdef _DEBUG
void CTypedPtrArrayView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTypedPtrArrayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CTypedPtrArrayView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CmyobArrayView internal implementation

void CTypedPtrArrayView::AddMyObjectToListBox(CMyObject* pMyObject,
	int nSel)
{
	// Add new CMyObject to the listbox.
	CString str;
	pMyObject->Format(str);
	if (nSel == -1)
		nSel = m_ctlList.AddString(str);
	else
		m_ctlList.InsertString(nSel, str);
}


/////////////////////////////////////////////////////////////////////////////
// CTypedPtrArrayView message handlers

void CTypedPtrArrayView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	try {
	// Add new CMyObject to the CTypedPtrArray
	CMyObject* pMyObject = new CMyObject;
	pMyObject->m_int = m_int;
	pMyObject->m_float = m_float;
	pMyObject->m_str = m_str.AllocSysString();
	GetDocument()->m_myobArray->Add = pMyObject;

	AddMyObjectToListBox(pMyObject);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrArrayView::OnUpdate()
{
	if (UpdateData() != TRUE)
		return;

	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_ENTRY_TO_BE_UPDATED);
		return;
	}

	try {
	CMyObject* pMyObject = (CMyObject*) GetDocument()->m_myobArray->Array[nSel];

	// Replace the value of the CMyObject in the CTypedPtrArray.
	pMyObject->m_int = m_int;
	pMyObject->m_float = m_float;
	pMyObject->m_str = m_str.AllocSysString();

	// Replace the displayed CMyObject in the listbox by removing
	// the old listbox entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	AddMyObjectToListBox(pMyObject, nSel);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrArrayView::OnRemove()
{
	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_ENTRY_TO_BE_REMOVED);
		return;
	}

	try {
	CMyObject* pMyObject = (CMyObject*) GetDocument()->m_myobArray->Array[nSel];

	// Remove the CMyObject ptr from the CTypedPtrArray.
	GetDocument()->m_myobArray->Remove[nSel];

	// Delete the CMyObject object. (The CTypedPtrArray only holds the ptr.)
	delete pMyObject;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Remove the corresponding entry from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CTypedPtrArrayView::OnRemoveAll()
{
	CCollectDoc* pDoc = GetDocument();
	try {
	for (int n = 0; n < (int) pDoc->m_myobArray->Count; n++)
		delete (CMyObject*) pDoc->m_myobArray->Array[n];

	pDoc->m_myobArray->RemoveAll();
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	// Remove all of the corresponding formatted strings from the listbox.
	m_ctlList.ResetContent();
}

void CTypedPtrArrayView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.
	int nSel = m_ctlList.GetCurSel();
	try {
	CMyObject* pMyObject = (CMyObject*) GetDocument()->m_myobArray->Array[nSel];

	m_int = pMyObject->m_int;
	m_float = pMyObject->m_float;
	m_str = pMyObject->m_str;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	UpdateData(FALSE);
}
