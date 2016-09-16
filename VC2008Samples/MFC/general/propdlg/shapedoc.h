// shapesdoc.h : interface of the CShapesDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include <afxtempl.h>

class CShapesDoc : public CDocument
{
protected: // create from serialization only
	CShapesDoc();
	DECLARE_DYNCREATE(CShapesDoc)

// Attributes
public:
	CTypedPtrList<CObList, CShape*> m_shapeList;

// Operations
public:
	void AddShape(CShape* pShapeNew);
	CShape* HitTest(CPoint pt);

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CShapesDoc)
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShapesDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShapesDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
