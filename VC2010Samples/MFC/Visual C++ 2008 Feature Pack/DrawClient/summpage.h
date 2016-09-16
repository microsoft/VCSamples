// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

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
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	//{{AFX_MSG(CSummPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
