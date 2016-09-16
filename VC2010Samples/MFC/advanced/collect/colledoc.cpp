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
// CMyStruct

void CMyStruct::FormatMyStruct(CString& str)
{
	str.Format(_T("{%i, %.4f, %s}"), m_int, m_float, (LPCTSTR)m_str);
}

#if _MSC_VER > 1020
template <> void AFXAPI SerializeElements<CMyStruct*>(CArchive& ar, CMyStruct** ppElements, INT_PTR nCount)
#else
void SerializeElements(CArchive& ar, CMyStruct** ppElements, int nCount)
#endif
{
	// Since SerializeElements is always called by the framework with nCount=1
	// for a CMap<>, it is a good idea to implement SerializeElement to handle
	// nCount>1, in case you decide to reuse it for a CArray<> with the same
	// element type.
	if (ar.IsStoring())
	{
		for (int i = 0; i < nCount; i++)
		{
			CMyStruct* pMyStruct = *(ppElements + i);
			WORD w = (WORD)pMyStruct->m_int;
			ar << w;
			ar << pMyStruct->m_float;
			ar << pMyStruct->m_str;
			nCount--;
		}
	}
	else
	{
		for (int i = 0; i < nCount; i++)
		{
			CMyStruct* pMyStruct = new CMyStruct;
			*(ppElements + i) = pMyStruct;
			WORD w;
			ar >> w;
			pMyStruct->m_int = w;
			ar >> pMyStruct->m_float;
			ar >> pMyStruct->m_str;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyObject

IMPLEMENT_SERIAL(CMyObject, CObject, 0)

CMyObject::CMyObject()
{
}

CMyObject::~CMyObject()
{
}

void CMyObject::FormatMyObject(CString& str)
{
	str.Format(_T("{%i, %.4f, %s}"), m_int, m_float, (LPCTSTR)m_str);
}

void CMyObject::Serialize(CArchive& ar)
{
	WORD w;
	if (ar.IsStoring())
	{
		w = (WORD)m_int;
		ar << w;
		ar << m_float;
		ar << m_str;
	}
	else
	{
		ar >> w;
		m_int = w;
		ar >> m_float;
		ar >> m_str;
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
}

CCollectDoc::~CCollectDoc()
{
}

BOOL CCollectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	CString strFirst;
	strFirst.LoadString(IDS_INITIAL_STRING);
	m_stringList.AddTail(strFirst);

	CMyStruct* pMyStruct = new CMyStruct();
	pMyStruct->m_int = 1234;
	pMyStruct->m_float = 12.34f;
	pMyStruct->m_str.LoadString(IDS_INITIAL_STRING);
	m_mystructList.AddTail(pMyStruct);

	m_intList.AddTail(100);

	m_dwArray.Add(100000);

	CMyObject* pMyObject = new CMyObject();
	pMyObject->m_int = 5678;
	pMyObject->m_float = 56.78f;
	pMyObject->m_str.LoadString(IDS_INITIAL_STRING);
	m_myobArray.Add(pMyObject);

	CPoint pt(10,10);
	m_ptArray.Add(pt);

	CString strKey, strValue;
	strKey.LoadString(IDS_INITIAL_KEY);
	strValue.LoadString(IDS_INITIAL_VALUE);
	m_mapStringToString[strKey] = strValue;


	CMyObject* pMyObject2 = new CMyObject();
	pMyObject2->m_int = 1357;
	pMyObject2->m_float = 13.57f;
	pMyObject2->m_str.LoadString(IDS_INITIAL_STRING);
	m_mapStringToMyObject[strKey] = pMyObject2;

	CMyStruct* pMyStruct2 = new CMyStruct();
	pMyStruct2->m_int = 2468;
	pMyStruct2->m_float = 24.68f;
	pMyStruct2->m_str.LoadString(IDS_INITIAL_STRING);
	m_mapDWordToMyStruct[100] = pMyStruct2;

	return TRUE;
}

void CCollectDoc::DeleteContents()
{
	m_stringList.RemoveAll();

	POSITION pos = m_mystructList.GetHeadPosition();
	while (pos != NULL)
	{
		delete m_mystructList.GetNext(pos);
	}
	m_mystructList.RemoveAll();

	m_intList.RemoveAll();

	m_dwArray.RemoveAll();

	for (int n = 0; n < m_myobArray.GetSize(); n++)
	{
		delete m_myobArray[n];
	}
	m_myobArray.RemoveAll();

	m_mapStringToString.RemoveAll();

	m_ptArray.RemoveAll();

	pos = m_mapStringToMyObject.GetStartPosition();
	while (pos != NULL)
	{
		CString str;
		CMyObject* pMyObject;
		m_mapStringToMyObject.GetNextAssoc(pos, str, pMyObject);
		delete pMyObject;
	}
	m_mapStringToMyObject.RemoveAll();

	pos = m_mapDWordToMyStruct.GetStartPosition();
	while (pos != NULL)
	{
		DWORD dwKey;
		CMyStruct* pMyStruct;
		m_mapDWordToMyStruct.GetNextAssoc(pos, dwKey, pMyStruct);
		delete pMyStruct;
	}
	m_mapDWordToMyStruct.RemoveAll();
}

/////////////////////////////////////////////////////////////////////////////
// CCollectDoc serialization

void CCollectDoc::Serialize(CArchive& ar)
{
	POSITION pos;
	WORD nCount;
	WORD w;

	m_stringList.Serialize(ar);

	if (ar.IsStoring())
	{
		nCount = (WORD)m_mystructList.GetCount();
		ar << nCount;
		pos = m_mystructList.GetHeadPosition();
		while (pos != NULL)
		{
			CMyStruct* pMyStruct = m_mystructList.GetNext(pos);
			w = (WORD)pMyStruct->m_int;
			ar << w;
			ar << pMyStruct->m_float;
			ar << pMyStruct->m_str;
			nCount--;
		}
		ASSERT(nCount == 0);
	}
	else
	{
		ar >> nCount;
		while (nCount-- > 0)
		{
			CMyStruct* pMyStruct = new CMyStruct;
			ar >> w;
			pMyStruct->m_int = w;
			ar >> pMyStruct->m_float;
			ar >> pMyStruct->m_str;
			m_mystructList.AddTail(pMyStruct);
		}
	}

	m_intList.Serialize(ar);

	m_dwArray.Serialize(ar);

	m_myobArray.Serialize(ar);

	m_ptArray.Serialize(ar);

	m_mapStringToString.Serialize(ar);

	m_mapStringToMyObject.Serialize(ar);

	m_mapDWordToMyStruct.Serialize(ar);
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
