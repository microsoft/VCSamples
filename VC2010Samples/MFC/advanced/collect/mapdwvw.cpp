// mapdwvw.cpp : implementation file
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
#include "mapdwvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapDWordToMyStructView

IMPLEMENT_DYNCREATE(CMapDWordToMyStructView, CFormView)

CMapDWordToMyStructView::CMapDWordToMyStructView()
	: CFormView(CMapDWordToMyStructView::IDD)
{
	//{{AFX_DATA_INIT(CMapDWordToMyStructView)
	m_int = 0;
	m_float = 0.0f;
	m_str = "";
	m_dwKey = 0;
	//}}AFX_DATA_INIT
}

CMapDWordToMyStructView::~CMapDWordToMyStructView()
{
}

void CMapDWordToMyStructView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// Copy all of the assocations from the document's CMap to the listbox.
	DWORD dwKey;
	CMyStruct* pMyStruct;
	m_ctlList.ResetContent();
	CMapDWordToMyStruct& map = GetDocument()->m_mapDWordToMyStruct;
	POSITION pos = map.GetStartPosition();
	while (pos != NULL)
	{
		map.GetNextAssoc(pos, dwKey, pMyStruct);
		AddMapEntryToListBox(dwKey, pMyStruct);
	}
}

void CMapDWordToMyStructView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapDWordToMyStructView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_INT, m_int);
	DDX_Text(pDX, IDC_FLOAT, m_float);
	DDX_Text(pDX, IDC_STRING, m_str);
	DDX_Text(pDX, IDC_KEY, m_dwKey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMapDWordToMyStructView, CFormView)
	//{{AFX_MSG_MAP(CMapDWordToMyStructView)
	ON_BN_CLICKED(IDC_ADD_OR_UPDATE, OnAddOrUpdate)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMapDWordToMyStructView diagnostics

#ifdef _DEBUG
void CMapDWordToMyStructView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMapDWordToMyStructView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CMapDWordToMyStructView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapDWordToMyStructView internal implementation

CString CMapDWordToMyStructView::FormatListBoxEntry(DWORD dwKey, CMyStruct* pMyStruct)
{
	CString strListBoxEntry;
	strListBoxEntry.Format(_T("%d"),dwKey);
	strListBoxEntry += _T(" >> ");
	CString strMyStruct;
	pMyStruct->FormatMyStruct(strMyStruct);
	strListBoxEntry += strMyStruct;
	return strListBoxEntry;
}

int CMapDWordToMyStructView::FindKeyInListBox(DWORD dwKey)
{
	for (int nSel = 0; nSel < m_ctlList.GetCount(); nSel++)
	{
		if (m_ctlList.GetItemData(nSel) == dwKey)
			return nSel;
	}
	return LB_ERR;
}

void CMapDWordToMyStructView::AddMapEntryToListBox(DWORD dwKey, CMyStruct* pMyStruct)
{
	CString strListBoxEntry = FormatListBoxEntry(dwKey, pMyStruct);
	int nSel = m_ctlList.AddString(strListBoxEntry);
	m_ctlList.SetItemData(nSel, dwKey);
}

CMyStruct* CMapDWordToMyStructView::ConstructMyStructFromView()
{
	CMyStruct* pMyStruct = new CMyStruct;
	pMyStruct->m_int = m_int;
	pMyStruct->m_float = m_float;
	pMyStruct->m_str = m_str;
	return pMyStruct;
}

void CMapDWordToMyStructView::UpdateViewFromMyStruct(CMyStruct* pMyStruct)
{
	m_int = pMyStruct->m_int;
	m_float = pMyStruct->m_float;
	m_str = pMyStruct->m_str;
	UpdateData(FALSE);  // update the value found in the map lookup
}


/////////////////////////////////////////////////////////////////////////////
// CMapDWordToMyStructView message handlers

void CMapDWordToMyStructView::OnAddOrUpdate()
{
	if (UpdateData() != TRUE)
		return;

	// Add or replace entry in the listbox
	int nSel = FindKeyInListBox(m_dwKey);
	if (nSel != LB_ERR)
		m_ctlList.DeleteString(nSel);
	CMyStruct* pMyStruct = ConstructMyStructFromView();
	AddMapEntryToListBox(m_dwKey, pMyStruct);

	// Add or update association in the CMap
	CMyStruct* pTemp;
	if( GetDocument()->m_mapDWordToMyStruct.Lookup( m_dwKey, pTemp ) )
		delete pTemp; // delete old value
	GetDocument()->m_mapDWordToMyStruct[m_dwKey] = pMyStruct;
}

void CMapDWordToMyStructView::OnFind()
{
	if (UpdateData() != TRUE)
		return;

	CMyStruct* pMyStruct;
	if (GetDocument()->m_mapDWordToMyStruct.Lookup(m_dwKey, pMyStruct) != TRUE)
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	UpdateViewFromMyStruct(pMyStruct);
}

void CMapDWordToMyStructView::OnRemove()
{
	if (UpdateData() != TRUE)
		return;

	CMyStruct* pMyStruct;
	CMapDWordToMyStruct& map = GetDocument()->m_mapDWordToMyStruct;
	if (map.Lookup(m_dwKey, pMyStruct) != TRUE)
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	if (m_int != pMyStruct->m_int
		|| m_float != pMyStruct->m_float
		|| m_str != pMyStruct->m_str)
	{
		UpdateViewFromMyStruct(pMyStruct);
		AfxMessageBox(IDS_KEY_NOT_FOUND_CHOOSE_REMOVE_AGAIN);
		return;
	}

	// Remove assocation from the listbox
	int nSel = FindKeyInListBox(m_dwKey);
	ASSERT(nSel != LB_ERR);
	m_ctlList.DeleteString(nSel);

	// Remove the association from the CMap
	map.RemoveKey(m_dwKey);

	// Delete CMyStruct
	delete pMyStruct;
}

void CMapDWordToMyStructView::OnRemoveAll()
{
	CCollectDoc* pDoc = GetDocument();
	POSITION pos = GetDocument()->m_mapDWordToMyStruct.GetStartPosition();
	while (pos != NULL)
	{
		DWORD dwKey;
		CMyStruct* pMyStruct;
		pDoc->m_mapDWordToMyStruct.GetNextAssoc(pos, dwKey, pMyStruct);
		delete pMyStruct;
	}
	pDoc->m_mapDWordToMyStruct.RemoveAll();
	m_ctlList.ResetContent();
}

void CMapDWordToMyStructView::OnSelChangeList()
{
	// Update the "key" field to reflect the new selection in the listbox.
	m_dwKey = (DWORD)m_ctlList.GetItemData(m_ctlList.GetCurSel());
	UpdateData(FALSE);

	// Now that the key field has been updated to reflect the listbox selection,
	// find the string in the map as though the user had hit the Find button.
	OnFind();
}
