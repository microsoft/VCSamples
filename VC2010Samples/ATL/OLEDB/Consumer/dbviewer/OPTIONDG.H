// OptionsDlg.h : header file
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
// COptionsDlg dialog

class COptionsDlg : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsDlg)

// Construction
public:
	COptionsDlg();
	~COptionsDlg();

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_DLGOPTIONS };
	BOOL    m_bOpenODBC;
	BOOL    m_bShowSystemObjects;
	BOOL    m_bShowWarnings;
	UINT    m_nMaxRecords;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
