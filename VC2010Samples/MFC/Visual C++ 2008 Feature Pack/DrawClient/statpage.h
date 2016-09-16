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

/////////////////////////////////////////////////////////////////////////////
// CStatPage dialog

class CStatPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CStatPage)

// Construction
public:
	CStatPage();
	~CStatPage();

// Dialog Data
	//{{AFX_DATA(CStatPage)
	enum { IDD = IDD_STAT_PAGE };
	CString m_strSavedBy;
	CString m_strRevNum;
	CString m_strEditTime;
	CString m_strLastPrint;
	CString m_strCreateDate;
	CString m_strLastSave;
	CString m_strNumPages;
	CString m_strNumWords;
	CString m_strNumChars;
	CString m_strSecurity;
	//}}AFX_DATA

// Overrides
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	//{{AFX_MSG(CStatPage)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
