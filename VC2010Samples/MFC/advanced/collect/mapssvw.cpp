// mapssvw.cpp : implementation file
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
#include "mapssvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapStringToStringView

IMPLEMENT_DYNCREATE(CMapStringToStringView, CFormView)

CMapStringToStringView::CMapStringToStringView()
	: CFormView(CMapStringToStringView::IDD)
{
	//{{AFX_DATA_INIT(CMapStringToStringView)
	m_strKey = "";
	m_strValue = "";
	//}}AFX_DATA_INIT
}

CMapStringToStringView::~CMapStringToStringView()
{
}

void CMapStringToStringView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the assocations from the document's CMapStringToString
	// to the listbox.
	CString strKey, strValue;
	m_ctlList.ResetContent();
	CMapStringToString& map = GetDocument()->m_mapStringToString;
	POSITION pos = map.GetStartPosition();
	while (pos != NULL)
	{
		map.GetNextAssoc(pos, strKey, strValue);
		AddMapEntryToListBox(strKey, strValue);
	}
}

void CMapStringToStringView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapStringToStringView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_KEY, m_strKey);
	DDX_Text(pDX, IDC_VALUE, m_strValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMapStringToStringView, CFormView)
	//{{AFX_MSG_MAP(CMapStringToStringView)
	ON_BN_CLICKED(IDC_ADD_OR_UPDATE, OnAddOrUpdate)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMapStringToStringView diagnostics

#ifdef _DEBUG
void CMapStringToStringView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMapStringToStringView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CMapStringToStringView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapStringToStringView internal implementation

int CMapStringToStringView::FindKeyInListBox(CString& strKey)
{
	CString strValue;
	if (GetDocument()->m_mapStringToString.Lookup(strKey, strValue) != TRUE)
		return LB_ERR;
	CString strListBoxEntry = strKey;
	strListBoxEntry += _T(" >> ");
	strListBoxEntry += strValue;
	return m_ctlList.FindString(-1, strListBoxEntry);
}

void CMapStringToStringView::AddMapEntryToListBox(CString& strKey, CString& strValue)
{
	CString str = strKey;
	str += _T(" >> ");
	str += strValue;
	m_ctlList.AddString(str);
}

/////////////////////////////////////////////////////////////////////////////
// CMapStringToStringView message handlers

void CMapStringToStringView::OnAddOrUpdate()
{
	if (UpdateData() != TRUE)
		return;

	// Add or replace entry in the listbox
	int nSel = FindKeyInListBox(m_strKey);
	if (nSel != LB_ERR)
		m_ctlList.DeleteString(nSel);
	AddMapEntryToListBox(m_strKey, m_strValue);

	// Add or update association in the CMapStringToString
	GetDocument()->m_mapStringToString[m_strKey] = m_strValue;
}

void CMapStringToStringView::OnFind()
{
	if (UpdateData() != TRUE)
		return;

	CString strValue;
	if (GetDocument()->m_mapStringToString.Lookup(m_strKey, strValue) != TRUE)
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	m_strValue = strValue;
	UpdateData(FALSE);  // update the value found in the map lookup
}

void CMapStringToStringView::OnRemove()
{
	if (UpdateData() != TRUE)
		return;

	CString strValue;
	CMapStringToString& map = GetDocument()->m_mapStringToString;
	if (map.Lookup(m_strKey, strValue) != TRUE)
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	if (strValue != m_strValue)
	{
		m_strValue = strValue;
		UpdateData(FALSE);
		AfxMessageBox(IDS_KEY_NOT_FOUND_CHOOSE_REMOVE_AGAIN);
		return;
	}

	// Remove assocation from the listbox
	int nSel = FindKeyInListBox(m_strKey);
	ASSERT(nSel != LB_ERR);
	m_ctlList.DeleteString(nSel);

	// Remove the association from the CMapStringToString
	map.RemoveKey(m_strKey);
}

void CMapStringToStringView::OnRemoveAll()
{
	GetDocument()->m_mapStringToString.RemoveAll();
	m_ctlList.ResetContent();
}

void CMapStringToStringView::OnSelChangeList()
{
	// Update the "key" field to reflect the new selection in the listbox.
	CString str;
	m_ctlList.GetText(m_ctlList.GetCurSel(), str);
	m_strKey.Empty();
	LPCTSTR lpsz = str;
	while (*lpsz != ' ' || *(lpsz+1) != '>' || *(lpsz+2) != '>')
	{
		m_strKey += *lpsz;
		lpsz++;
	}
	UpdateData(FALSE);

	// Now that the key field has been updated to reflect the listbox selection,
	// find the string in the map as though the user had hit the Find button.
	OnFind();
}
