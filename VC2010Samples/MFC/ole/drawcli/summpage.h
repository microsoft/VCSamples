// summpage.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

/////////////////////////////////////////////////////////////////////////////
// CSummPage dialog

class CSummPage : public CPropertyPage
{
		DECLARE_DYNCREATE(CSummPage)

// Construction
public:
		CSummPage();
		~CSummPage();

// Dialog Data
		//{{AFX_DATA(CSummPage)
	enum { IDD = IDD_SUMM_PAGE };
	CString m_strAuthor;
	CString m_strKeywd;
	CString m_strSubj;
	CString m_strCmt;
	CString m_strTempl;
	CString m_strTitle;
	CString m_strAppname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
		//{{AFX_VIRTUAL(CSummPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
		//{{AFX_MSG(CSummPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
