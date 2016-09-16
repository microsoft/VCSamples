// AClikDoc.h : interface of the CAutoClickDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
/////////////////////////////////////////////////////////////////////////////

class CAutoClickDoc : public CDocument
{
protected: // create from serialization only
	CAutoClickDoc();
	DECLARE_DYNCREATE(CAutoClickDoc)

// Attributes
public:
	CPoint m_pt;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoClickDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoClickDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoClickDoc)
	afx_msg void OnEditChangetext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
public:
	//{{AFX_DISPATCH(CAutoClickDoc)
	CString m_str;
	afx_msg short GetX();
	afx_msg void SetX(short nNewValue);
	afx_msg short GetY();
	afx_msg void SetY(short nNewValue);
	afx_msg LPDISPATCH GetPosition();
	afx_msg void SetPosition(LPDISPATCH newValue);
	afx_msg void Refresh();
	afx_msg void SetAllProps(short x, short y, LPCTSTR text);
	afx_msg void ShowWindow();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
