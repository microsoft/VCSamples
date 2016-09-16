// AdderDlg.h : header file
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
// CAdderDialog dialog

class CAdderDialog : public CDialog
{
private:
	using CDialog::Create;

// Construction
public:
	CAdderDialog(CWnd* pParent);   // standard constructor
	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CAdderDialog)
	enum { IDD = IDD_ADDME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdderDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	CWnd* m_pParent;
	int m_nID;

	// Generated message map functions
	//{{AFX_MSG(CAdderDialog)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
