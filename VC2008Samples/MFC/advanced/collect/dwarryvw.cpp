// dwarryvw.cpp : implementation file
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
#include "dwarryvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDWordArrayView

IMPLEMENT_DYNCREATE(CDWordArrayView, CFormView)

CDWordArrayView::CDWordArrayView()
	: CFormView(CDWordArrayView::IDD)
{
	//{{AFX_DATA_INIT(CDWordArrayView)
	m_dw = 0;
	//}}AFX_DATA_INIT
}

CDWordArrayView::~CDWordArrayView()
{
}

void CDWordArrayView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the DWORDs from the document's CDWordArray
	// to the listbox.
	m_ctlList.ResetContent();
	CDWordArray& dwArray = GetDocument()->m_dwArray;
	for (int nIndex = 0; nIndex < dwArray.GetSize(); nIndex++)
	{
		DWORD dw = dwArray[nIndex];
		CString str;
		str.Format(_T("%d"),dw);
		int nSel = 0;
		nSel = m_ctlList.AddString(str);
	}
}

void CDWordArrayView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDWordArrayView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_DWORD, m_dw);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDWordArrayView, CFormView)
	//{{AFX_MSG_MAP(CDWordArrayView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_UPDATE, OnUpdateButton)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CDWordArrayView diagnostics

#ifdef _DEBUG
void CDWordArrayView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDWordArrayView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CDWordArrayView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CDWordArrayView message handlers

void CDWordArrayView::OnAdd()
{
	if (UpdateData() != TRUE)
		return;

	// Add new DWORD to the CDWordArray
	int nIndex = (int)GetDocument()->m_dwArray.Add(m_dw);

	// Add new DWORD to the listbox.
	CString str;
	str.Format(_T("%d"),m_dw);
	int nSel = m_ctlList.AddString(str);

	// The index of the new DWORD in the array should be the
	// same as the index of the new DWORD in the listbox.
	ASSERT(nIndex == nSel);
}

void CDWordArrayView::OnUpdateButton()
{
	if (UpdateData() != TRUE)
		return;

	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_DWORD_TO_UPDATE);
		return;
	}

	// Replace the DWORD in the CDWordArray.
	GetDocument()->m_dwArray[nSel] = m_dw;

	// Update the old DWORD in the listbox by removing
	// the old entry and adding a new entry.
	m_ctlList.DeleteString(nSel);
	CString str;
	str.Format(_T("%d"),m_dw);
	m_ctlList.InsertString(nSel, str);
}

void CDWordArrayView::OnRemove()
{
	if (UpdateData() != TRUE)
		return;

	int nSel = m_ctlList.GetCurSel();
	if (nSel == LB_ERR)
	{
		AfxMessageBox(IDS_SELECT_DWORD_TO_REMOVE);
		return;
	}

	// Remove the DWORD from the CDWordArray.
	GetDocument()->m_dwArray.RemoveAt(nSel);

	// Remove the DWORD from the listbox.
	m_ctlList.DeleteString(nSel);
}

void CDWordArrayView::OnRemoveAll()
{
	// Remove all of the DWORDs from the CDWordArray.
	GetDocument()->m_dwArray.RemoveAll();

	// Remove all of the DWORDs from the listbox.
	m_ctlList.ResetContent();
}

void CDWordArrayView::OnSelChangeList()
{
	// Update the edit control to reflect the new selection
	// in the listbox.
	m_dw = GetDocument()->m_dwArray[m_ctlList.GetCurSel()];
	UpdateData(FALSE);
}
