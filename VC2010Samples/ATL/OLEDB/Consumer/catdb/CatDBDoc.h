// Cat3Doc.h : interface of the CCatDBDoc class
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

class CCatDBDoc : public CDocument
{
protected: // create from serialization only
	int GetProfileValue(LPCTSTR lpszSection,LPCTSTR lpszItem);
	CCatDBDoc();
	DECLARE_DYNCREATE(CCatDBDoc)

// Attributes
public:
	CString m_strConnect;
	// Database Connection
	CDataSource m_source;
	CSession    m_session;

	// Table Information
	CTables* m_pTableset;
	BOOL m_bSystemTables;
	BOOL m_bViews;
	BOOL m_bSynonyms;

	// Column Information
	CColumns* m_pColumnset;
	BOOL m_bLength;
	BOOL m_bPrecision;
	BOOL m_bNullability;

	// Level Information
	enum Level
	{
		levelNone,
		levelTable,
		levelColumn
	};

	Level       m_nLevel;
	CString     m_strTableName;


// Operations
public:
	void SetLevel(Level nLevel);
	CString GetDSN();
	void    FetchColumnInfo(LPCSTR lpszName);
	BOOL    FetchTableInfo();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatDBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument();
	virtual void OnCloseDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCatDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCatDBDoc)
	afx_msg void OnViewSettings();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
