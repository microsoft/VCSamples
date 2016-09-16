// maindoc.h : interface of the CMainDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CMainDoc : public CDocument
{
protected: // create from serialization only
	CMainDoc();
	DECLARE_SERIAL(CMainDoc)

// Attributes
public:
	// an example of document specific data
	CString m_strData;          // string text
	COLORREF m_colorData;       // color for the string text

// Implementation
public:
	virtual ~CMainDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
protected:
	virtual BOOL    OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CMainDoc)
	afx_msg void OnChangeData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
