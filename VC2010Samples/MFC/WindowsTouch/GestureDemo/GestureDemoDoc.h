// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// GestureDemoDoc.h : interface of the CGestureDemoDoc class
//


#pragma once


class CGestureDemoDoc : public CDocument
{
protected: // create from serialization only
	CGestureDemoDoc();
	DECLARE_DYNCREATE(CGestureDemoDoc)

// Attributes
public:
	CImage	m_Image;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszFile);
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CGestureDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

};


