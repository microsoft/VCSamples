// EditDlg.h : header file
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
// CEditDlg dialog

class CEditDlg : public CDialog
{
// Construction
public:
	int m_nCurSel;
	CEditDlg();
	CEditDlg(CMapStringToString& mapData);
	CEditDlg(CListCtrlEx* pCtrl, int nItem, int nFields);

// Dialog Data
	//{{AFX_DATA(CEditDlg)
	enum { IDD = IDD_EDIT_DIALOG };
	CEdit   m_ctlEdit;
	CListBox    m_ctlListBox;
	CString m_strEdit;
	//}}AFX_DATA

// Attributes
public:
	CString GetValue(CString strKey);

protected:
	BOOL    m_bMode;

protected:
	CMapStringToString  m_mapField;
	CListCtrlEx*        m_pListCtrl;
	int                 m_nItem;
	int                 m_nFields;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEditDlg();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnFieldChange();
	virtual void OnOK();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
