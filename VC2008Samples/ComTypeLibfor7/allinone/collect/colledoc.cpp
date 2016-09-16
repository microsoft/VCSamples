// colledoc.cpp : implementation of the CCollectDoc class
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
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyObject

IMPLEMENT_SERIAL(CMyObject, CObject, 0)

void CMyObject::Serialize(CArchive& ar)
{
	WORD w;
	if (ar.IsStoring())
	{
		w = (WORD)m_int;
		ar << w;
		ar << m_float;
		ar << (CString) m_str;
	}
	else
	{
		ar >> w;
		m_int = w;
		ar >> m_float;
		CString str;
		ar >> str;
		m_str = str.AllocSysString();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc

IMPLEMENT_DYNCREATE(CCollectDoc, CDocument)

BEGIN_MESSAGE_MAP(CCollectDoc, CDocument)
	//{{AFX_MSG_MAP(CCollectDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc construction/destruction

CCollectDoc::CCollectDoc()
{
	try {
	IStlListsPtr m_Lists(__uuidof(CStlLists));
	m_stringList = m_Lists;
	m_mystructList = m_Lists;
	m_intList = m_Lists;

	IStlArraysPtr m_Arrays(__uuidof(CStlArrays));
	m_dwArray = m_Arrays;
	m_myobArray = m_Arrays;
	m_ptArray = m_Arrays;

	IStlMapsPtr m_Maps(__uuidof(CStlMaps));
	m_mapStringToString = m_Maps;
	m_mapStringToMyObject = m_Maps;
	m_mapDWordToMyStruct = m_Maps;
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

CCollectDoc::~CCollectDoc()
{
}

BOOL CCollectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	try {
	CString strFirst;
	strFirst.LoadString(IDS_INITIAL_STRING);
	m_stringList->Add = (LPCTSTR) strFirst;

	CMyStruct* pMyStruct = new CMyStruct();
	pMyStruct->m_int = 1234;
	pMyStruct->m_float = 12.34f;
	CString str;
	str.LoadString(IDS_INITIAL_STRING);
	pMyStruct->m_str = str.AllocSysString();
	m_mystructList->Add = pMyStruct;

	m_intList->Add = 100;

	m_dwArray->Add = 100000;

	CMyObject* pMyObject = new CMyObject();
	pMyObject->m_int = 5678;
	pMyObject->m_float = 56.78f;
	pMyObject->m_str = str.AllocSysString();
	m_myobArray->Add = pMyObject;

	CPoint pt(10,10);
	m_ptArray->Add = pt;

	CString strKey, strValue;
	strKey.LoadString(IDS_INITIAL_KEY);
	strValue.LoadString(IDS_INITIAL_VALUE);
	m_mapStringToString->Map[(LPCTSTR) strKey] = (LPCTSTR) strValue;


	CMyObject* pMyObject2 = new CMyObject();
	pMyObject2->m_int = 1357;
	pMyObject2->m_float = 13.57f;
	pMyObject2->m_str = str.AllocSysString();
	m_mapStringToMyObject->Map[(LPCTSTR) strKey] = pMyObject2;

	CMyStruct* pMyStruct2 = new CMyStruct();
	pMyStruct2->m_int = 2468;
	pMyStruct2->m_float = 24.68f;
	pMyStruct2->m_str = str.AllocSysString();
	m_mapDWordToMyStruct->Map[100] = pMyStruct2;
	} catch(_com_error& e) {
		dump_com_error(e);
	}

	return TRUE;
}

void CCollectDoc::DeleteContents()
{
	try {
	m_stringList->RemoveAll();

	m_mystructList->First();
	IMyStruct* pMyStruct = NULL;
	while (m_mystructList->Next(&pMyStruct))
		delete (CMyStruct*) pMyStruct;

	m_mystructList->RemoveAll();

	m_intList->RemoveAll();

	m_dwArray->RemoveAll();

	for (int n = 0; n < (int) m_myobArray->Count; n++)
		delete (CMyObject*) m_myobArray->Array[n];

	m_myobArray->RemoveAll();

	m_mapStringToString->RemoveAll();

	m_ptArray->RemoveAll();

	m_mapStringToMyObject->First();
	BSTR str;
	while (m_mapStringToMyObject->Next(&str, &pMyStruct))
		delete (CMyObject*) pMyStruct;

	m_mapStringToMyObject->RemoveAll();

	m_mapDWordToMyStruct->First();
	DWORD dwKey;
	while (m_mapDWordToMyStruct->Next(&dwKey, &pMyStruct))
		delete (CMyStruct*) pMyStruct;

	m_mapDWordToMyStruct->RemoveAll();
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc serialization


CArchive& AFXAPI operator<<(CArchive& ar, BSTR b)
{
	ar << (CString) b;
	return ar;
}

CArchive& AFXAPI operator>>(CArchive& ar, BSTR& b)
{
	CString str;
	ar >> str;
	b = str.AllocSysString();
	return ar;
}

CArchive& AFXAPI operator<<(CArchive& ar, IMyStruct* p)
{
	ar << p->m_int;
	ar << p->m_float;
	ar << (CString) p->m_str;

	return ar;
}

CArchive& AFXAPI operator>>(CArchive& ar, IMyStruct*& p)
{
	p = new CMyStruct;
	ar >> p->m_int;
	ar >> p->m_float;
	CString str;
	ar >> str;
	p->m_str = str.AllocSysString();
	return ar;
}

template <class T, class C>
void Serialize(T t, C* p, CArchive& ar)
{
	long nCount;
	if (ar.IsStoring())
	{
		nCount = p->Count;
		ar << nCount;
		p->First();
		while (p->Next(&t))
		{
			ar << t;
			nCount--;
		}
		ASSERT(nCount == 0);
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			ar >> t;
			p->Add = t;
		}
	}
}

template <class T1, class T2, class C>
void Serialize(T1 t1, T2 t2, C* p, CArchive& ar)
{
	long nCount;
	if (ar.IsStoring())
	{
		nCount = p->Count;
		ar << nCount;
		p->First();
		while (p->Next(&t1, &t2))
		{
			ar << t1;
			ar << t2;
			nCount--;
		}
		ASSERT(nCount == 0);
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			ar >> t1;
			ar >> t2;
			p->Map[t1] = t2;
		}
	}
}

// NOTE: Partial template specialization is not implemented yet.
template <class C>
void Serialize(C* p, CArchive& ar)
{
	long nCount;
	IMyStruct* t;
	CMyObject* t1;
	if (ar.IsStoring())
	{
		nCount = p->Count;
		ar << nCount;
		p->First();
		while (p->Next(&t))
		{
			t1 = (CMyObject*) t;
			ar << (CObject*) t1;
			nCount--;
		}
		ASSERT(nCount == 0);
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			ar >> t1;
			t = (IMyStruct*) t1;
			p->Add = t;
		}
	}
}

// NOTE: Partial template specialization is not implemented yet.
template <class T1, class C>
void Serialize2(T1 t1, C* p, CArchive& ar)
{
	long nCount;
	IMyStruct* t;
	CMyObject* t2;
	if (ar.IsStoring())
	{
		nCount = p->Count;
		ar << nCount;
		p->First();
		while (p->Next(&t1, &t))
		{
			ar << t1;
			t2 = (CMyObject*) t;
			ar << (CObject*) t2;
			nCount--;
		}
		ASSERT(nCount == 0);
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			ar >> t1;
			ar >> t2;
			t = (IMyStruct*) t2;
			p->Map[t1] = t2;
		}
	}
}

void CCollectDoc::Serialize(CArchive& ar)
{
	try {
	BSTR str = 0;
	::Serialize(str, (IStlStringList*) m_stringList, ar);

	IMyStruct* pStr = NULL;
	::Serialize(pStr, (IStlMyStructList*) m_mystructList, ar);

	long n = 0;
	::Serialize(n, (IStlintList*) m_intList, ar);

	DWORD dw = 0;
	::Serialize(dw, (IStlDWordArray*) m_dwArray, ar);

	// NOTE: Partial template specialization is not implemented yet.
	::Serialize((IStlMyObjectArray*) m_myobArray, ar);

	CPoint pt(0, 0);
	::Serialize(pt, (IStlPointArray*) m_ptArray, ar);

	BSTR str2 = 0;
	::Serialize(str, str2, (IStlMapStringToString*) m_mapStringToString, ar);

	// NOTE: Partial template specialization is not implemented yet.
	::Serialize2(str, (IStlMapStringToMyObject*) m_mapStringToMyObject, ar);

	::Serialize(dw, pStr, (IStlMapDWordToMyStruct*) m_mapDWordToMyStruct, ar);
	} catch(_com_error& e) {
		dump_com_error(e);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc diagnostics

#ifdef _DEBUG
void CCollectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCollectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc commands
