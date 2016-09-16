// File: PropertiesDlg.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_PROPERTIESDLG_H__AABFFA2A_818A_11D2_AA8F_00C04F990180__INCLUDED_)
#define AFX_PROPERTIESDLG_H__AABFFA2A_818A_11D2_AA8F_00C04F990180__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog

class CPropertiesDlg : public CDHtmlDialog
{
// Construction
public:
	CPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	CString m_strFileName;
	CString m_strType;
	CString m_strFileSize;
	CString m_strCreationTime;
	CString m_strModificationTime;
	CString m_strAccessTime;
	DWORD m_dwFileAttributes;
	int m_nReadOnly;
	int m_nArchive;
	int m_nHidden;
	int m_nSystem;
	//{{AFX_DATA(CPropertiesDlg)
	enum { IDD = IDD_PROPERTIES };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertiesDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIESDLG_H__AABFFA2A_818A_11D2_AA8F_00C04F990180__INCLUDED_)
