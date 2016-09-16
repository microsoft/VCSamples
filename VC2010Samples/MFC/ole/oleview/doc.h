// doc.h : interface of the COle2ViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _DOC_H_
#define _DOC_H_


class COle2ViewDoc : public CDocument
{
friend class CObjTreeView ;
friend class CRegistryView ;
friend class CMainFrame ;

protected: // create from serialization only
	COle2ViewDoc();
	DECLARE_DYNCREATE(COle2ViewDoc)

public:
	CString         m_szObjectCur ;
	CLSID           m_clsidCur ;
	BOOL            m_fTypeLib ;
	BOOL            m_fInterface ;

	DWORD           m_dwClsCtx ;

// Attributes
public:


// Operations
public:

// Implementation
public:
	virtual ~COle2ViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual BOOL    OnNewDocument();
	virtual void    OnCloseDocument() ;

// Generated message map functions
protected:
	//{{AFX_MSG(COle2ViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // _DOC_H_
