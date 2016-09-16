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

class CCollectDoc : public CDocument
{
protected: // create from serialization only
	CCollectDoc();
	DECLARE_DYNCREATE(CCollectDoc)

// Attributes
public:
	IStlStringListPtr m_stringList;
	IStlMyStructListPtr m_mystructList;
	IStlintListPtr m_intList;
	IStlDWordArrayPtr m_dwArray;
	IStlMyObjectArrayPtr m_myobArray;
	IStlPointArrayPtr m_ptArray;
	IStlMapStringToStringPtr m_mapStringToString;
	IStlMapStringToMyObjectPtr m_mapStringToMyObject;
	IStlMapDWordToMyStructPtr m_mapDWordToMyStruct;

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
