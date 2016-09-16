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
	CStringList& stringList = GetDocument()->m_stringList;
	POSITION pos = stringList.GetHeadPosition();
	while (pos != NULL)
	{
		CString str = stringList.GetNext(pos);
		m_ctlList.AddString(str);
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

BOOL CStringListView::FindString(int& nSel, POSITION& pos)
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

	// Find the string to be updated or replaced in the CStringList.
	CStringList& stringList = GetDocument()->m_stringList;
	pos = stringList.Find(strOld);

	// If the string is in the listbox, it should also be in the
	// CStringList.
	ASSERT(pos != NULL);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CStringListView message handlers

void CStringListView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	// Add new string to the CStringList
	GetDocument()->m_stringList.AddTail(m_strElement);

	// Add new string to the listbox.
	m_ctlList.AddString(m_strElement);
}

void CStringListView::OnInsertBefore()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the string in both the CStringList and in the listbox.
	if (FindString(nSel, pos) != TRUE)
		return;

	// Insert in front of the string found in the CStringList
	GetDocument()->m_stringList.InsertBefore(pos, m_strElement);

	// Insert new string in the listbox
	m_ctlList.InsertString(nSel, m_strElement);
}

void CStringListView::OnUpdateElement()
{
	if (UpdateData() != TRUE)
		return;

	int nSel;
	POSITION pos;
	// Find the string in both the CStringList and in the listbox.
	if (FindString(nSel, pos) != TRUE)
		return;

	// Replace the value of the string in the CStringList.
	GetDocument()->m_stringList.SetAt(pos, m_strElement);

	// Replace the value of the string in the listbox by
	// removing the old string and adding the new string.
	m_ctlList.DeleteString(nSel);
	m_ctlList.InsertString(nSel, m_strElement);
}

void CStringListView::OnRemove()
{
	int nSel;
	POSITION pos;
	// FInd the string in both the CStringList and in the listbox.
	if (FindString(nSel, pos) != TRUE)
		return;

	// Remove the string from the CStringList.
	GetDocument()->m_stringList.RemoveAt(pos);

	// Remove the string from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CStringListView::OnRemoveAll()
{
	// Remove all of the strings from the CStringList.
	GetDocument()->m_stringList.RemoveAll();

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
