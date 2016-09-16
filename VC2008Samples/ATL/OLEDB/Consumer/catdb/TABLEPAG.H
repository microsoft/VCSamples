// tablepag.h : header file
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
// CTablePage dialog

class CTablePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CTablePage)

// Construction
public:
	CTablePage();
	~CTablePage();

// Dialog Data
	//{{AFX_DATA(CTablePage)
	enum { IDD = IDD_TABLEPAGE };
	BOOL    m_bSystemTables;
	BOOL    m_bViews;
	BOOL    m_bSynonyms;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CTablePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CTablePage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
