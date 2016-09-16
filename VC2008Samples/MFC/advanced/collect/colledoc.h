// colledoc.h : interface of the CCollectDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CMyStruct
{
// Attributes
public:
	int m_int;
	float m_float;
	CString m_str;

// Operations
public:
	void FormatMyStruct(CString& str);
};

// Note: in order for the specialization to be accepted by the compiler
//  the prototype for SerializeElements (or any other specialization)
//  must be visible when the template is expanded.  It is best to place
//  these declarations in the header file to avoid any unexpected
//  results.

#if _MSC_VER > 1020
template <> void AFXAPI SerializeElements<CMyStruct*>(CArchive& ar, CMyStruct** ppElements, INT_PTR nCount);
#else
void SerializeElements(CArchive& ar, CMyStruct** ppElements, int nCount);
#endif

class CMyObject : public CObject
{
public:
	CMyObject();
	DECLARE_SERIAL(CMyObject)

// Attributes
public:
	int m_int;
	float m_float;
	CString m_str;

// Operations
public:
	void FormatMyObject(CString& str);

// Implementation
public:
	virtual ~CMyObject();
	virtual void Serialize(CArchive& ar);
};

typedef CTypedPtrList<CPtrList, CMyStruct*> CMyStructList;
typedef CTypedPtrArray<CObArray,CMyObject*> CMyObjectArray;
typedef CTypedPtrMap<CMapStringToOb,CString,CMyObject*> CMapStringToMyObject;
typedef CMap<DWORD,DWORD,CMyStruct*,CMyStruct*&> CMapDWordToMyStruct;


class CCollectDoc : public CDocument
{
protected: // create from serialization only
	CCollectDoc();
	DECLARE_DYNCREATE(CCollectDoc)

// Attributes
public:
	CStringList m_stringList;
	CMyStructList m_mystructList;
	CList<int,int> m_intList;
	CDWordArray m_dwArray;
	CMyObjectArray m_myobArray;
	CArray<CPoint,CPoint> m_ptArray;
	CMapStringToString m_mapStringToString;
	CMapStringToMyObject m_mapStringToMyObject;
	CMapDWordToMyStruct m_mapDWordToMyStruct;


// Operations

// Overrides
	virtual void DeleteContents();
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCollectDoc)
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCollectDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCollectDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
