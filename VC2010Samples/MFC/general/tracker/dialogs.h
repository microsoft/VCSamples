// dialogs.h : header file
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
// CHandleSize dialog

class CHandleSize : public CDialog
{
// Construction
public:
	CHandleSize(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
	//{{AFX_DATA(CHandleSize)
	enum { IDD = IDD_HANDLE_SIZE };
	int     m_nHandleSize;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CHandleSize)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CMinSize dialog

class CMinSize : public CDialog
{
// Construction
public:
	CMinSize(CWnd* pParent = NULL); // standard constructor

// Dialog Data
	//{{AFX_DATA(CMinSize)
	enum { IDD = IDD_MIN_SIZE };
	int     m_nMinX;
	int     m_nMinY;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CMinSize)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
