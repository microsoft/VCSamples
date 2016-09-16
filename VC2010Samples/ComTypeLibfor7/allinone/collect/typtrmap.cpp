// typtrmap.cpp : implementation file
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
#include "typtrmap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTypedPtrMapView

IMPLEMENT_DYNCREATE(CTypedPtrMapView, CFormView)

CTypedPtrMapView::CTypedPtrMapView()
	: CFormView(CTypedPtrMapView::IDD)
{
	//{{AFX_DATA_INIT(CTypedPtrMapView)
	m_strKey = "";
	m_int = 0;
	m_float = 0.0f;
	m_str = "";
	//}}AFX_DATA_INIT
}

CTypedPtrMapView::~CTypedPtrMapView()
{
}

void CTypedPtrMapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	try {
	// Copy all of the assocations from the document's CTypedPtrMap
	// to the listbox.
	BSTR bstrKey;
	IMyStruct* pMyStruct = NULL;
	m_ctlList.ResetContent();
	IStlMapStringToMyObjectPtr& map = GetDocument()->m_mapStringToMyObject;
	map->First();
	while (map->Next(&bstrKey, &pMyStruct))
	{
		CString strKey(bstrKey);
		::SysFreeString(bstrKey);
		CMyObject* pMyObject = (CMyObject*) pMyStruct;
		AddMapEntryToListBox(strKey, pMyObject);
	}
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrMapView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTypedPtrMapView)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	DDX_Text(pDX, IDC_KEY, m_strKey);
	DDX_Text(pDX, IDC_INT, m_int);
	DDX_Text(pDX, IDC_FLOAT, m_float);
	DDX_Text(pDX, IDC_STRING, m_str);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTypedPtrMapView, CFormView)
	//{{AFX_MSG_MAP(CTypedPtrMapView)
	ON_BN_CLICKED(IDC_ADD_OR_UPDATE, OnAddOrUpdate)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_REMOVE_ALL, OnRemoveAll)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelChangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CTypedPtrMapView diagnostics

#ifdef _DEBUG
void CTypedPtrMapView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTypedPtrMapView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCollectDoc* CTypedPtrMapView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CCollectDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTypedPtrMapView internal implementation

CString CTypedPtrMapView::FormatListBoxEntry(CString& strKey, CMyObject* pMyObject)
{
	CString strListBoxEntry = strKey;
	strListBoxEntry += _T(" >> ");
	CString strMyObject;
	pMyObject->Format(strMyObject);
	strListBoxEntry += strMyObject;
	return strListBoxEntry;
}

int CTypedPtrMapView::FindKeyInListBox(CString& strKey)
{
	try {
	IMyStruct* pMyStruct = NULL;
	if (!GetDocument()->m_mapStringToMyObject->Lookup((LPCTSTR) strKey, &pMyStruct))
		return LB_ERR;
	CMyObject* pMyObject = (CMyObject*) pMyStruct;
	CString strListBoxEntry = FormatListBoxEntry(strKey, pMyObject);

	return m_ctlList.FindString(-1, strListBoxEntry);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
	return LB_ERR;
}

void CTypedPtrMapView::AddMapEntryToListBox(CString& strKey, CMyObject* pMyObject)
{
	CString strListBoxEntry = FormatListBoxEntry(strKey, pMyObject);
	m_ctlList.AddString(strListBoxEntry);
}

CMyObject* CTypedPtrMapView::ConstructMyObjectFromView()
{
	CMyObject* pMyObject = new CMyObject;
	pMyObject->m_int = m_int;
	pMyObject->m_float = m_float;
	pMyObject->m_str = m_str.AllocSysString();
	return pMyObject;
}

void CTypedPtrMapView::UpdateViewFromMyObject(CMyObject* pMyObject)
{
	m_int = pMyObject->m_int;
	m_float = pMyObject->m_float;
	m_str = pMyObject->m_str;
	UpdateData(FALSE);  // update the value found in the map lookup
}


/////////////////////////////////////////////////////////////////////////////
// CTypedPtrMapView message handlers

void CTypedPtrMapView::OnAddOrUpdate()
{
	if (UpdateData() != TRUE)
		return;

	try {
	// Add or replace entry in the listbox
	int nSel = FindKeyInListBox(m_strKey);
	if (nSel != LB_ERR)
		m_ctlList.DeleteString(nSel);
	CMyObject* pMyObject = ConstructMyObjectFromView();
	AddMapEntryToListBox(m_strKey, pMyObject);

	// Add or update association in the CTypedPtrMap
	delete (CMyObject*) GetDocument()->m_mapStringToMyObject->Map[(LPCTSTR) m_strKey];
	GetDocument()->m_mapStringToMyObject->Map[(LPCTSTR) m_strKey] = pMyObject;
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrMapView::OnFind()
{
	if (UpdateData() != TRUE)
		return;

	try {
	IMyStruct* pMyStruct = NULL;
	if (!GetDocument()->m_mapStringToMyObject->Lookup((LPCTSTR) m_strKey, &pMyStruct))
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	CMyObject* pMyObject = (CMyObject*) pMyStruct;
	UpdateViewFromMyObject(pMyObject);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrMapView::OnRemove()
{
	if (UpdateData() != TRUE)
		return;

	try {
	IMyStruct* pMyStruct = NULL;
	IStlMapStringToMyObjectPtr& map = GetDocument()->m_mapStringToMyObject;
	if (!map->Lookup((LPCTSTR) m_strKey, &pMyStruct))
	{
		AfxMessageBox(IDS_KEY_NOT_FOUND);
		return;
	}

	CMyObject* pMyObject = (CMyObject*) pMyStruct;
	if (m_int != pMyObject->m_int
		|| m_float != pMyObject->m_float
		|| m_str != pMyObject->m_str)
	{
		UpdateViewFromMyObject(pMyObject);
		AfxMessageBox(IDS_KEY_NOT_FOUND_CHOOSE_REMOVE_AGAIN);
		return;
	}

	// Remove assocation from the listbox
	int nSel = FindKeyInListBox(m_strKey);
	ASSERT(nSel != LB_ERR);
	m_ctlList.DeleteString(nSel);

	// Remove the association from the CTypedPtrMap
	map->Remove;

	// Delete the CMyObject
	delete pMyObject;
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrMapView::OnRemoveAll()
{
	try {
	CCollectDoc* pDoc = GetDocument();
	BSTR bstr;
	IMyStruct* pMyStruct = NULL;
	pDoc->m_mapStringToMyObject->First();
	while (pDoc->m_mapStringToMyObject->Next(&bstr, &pMyStruct))
	{
		::SysFreeString(bstr);
		delete (CMyObject*) pMyStruct;
	}
	pDoc->m_mapStringToMyObject->RemoveAll();

	m_ctlList.ResetContent();
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

void CTypedPtrMapView::OnSelChangeList()
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
