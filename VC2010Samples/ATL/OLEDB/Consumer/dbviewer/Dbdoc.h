// DBDoc.h : interface of the CDBViewDoc class
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

/////////////////////////////////////////////////////////////////////////////

#ifndef __DBDOC_H__
#define __DBDOC_H__

/////////////////////////////////////////////////////////////////////////////
// Forward declarations

class CDBListView;
class CDBTreeView;


/////////////////////////////////////////////////////////////////////////////
// Class CDBViewDoc

class CDBViewDoc : public CDocument
{
protected: // create from serialization only
	CString m_strConnect;
	CDataSource m_Connect;
	CSession    m_Session;
	CDBViewDoc();
	DECLARE_DYNCREATE(CDBViewDoc)

// Attributes
public:
	CString GetConnect();
	CString GetDSN();
	void RefreshViews();
	CDBListView* m_pListView;
	CDBTreeView* m_pTreeView;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_strQuoteEnd;
	CString m_strQuoteStart;
	CDataSource* GetDataSource();
	virtual ~CDBViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void ExtractProviderInfo();	// Gets literal characters, DSN, etc.

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBViewDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // __DBDOC_H__

/////////////////////////////////////////////////////////////////////////////
