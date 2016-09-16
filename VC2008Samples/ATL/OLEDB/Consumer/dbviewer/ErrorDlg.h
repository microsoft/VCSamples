#if !defined(AFX_ERRORDLG_H__EAC8D343_DDCB_11D0_8470_00A0C905A456__INCLUDED_)
#define AFX_ERRORDLG_H__EAC8D343_DDCB_11D0_8470_00A0C905A456__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ErrorDlg.h : header file
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
// struct MYERRORINFO

struct MYERRORINFO
{
	BSTR    bstrSource;
	BSTR    bstrDescription;
	DWORD   dwHelpContext;
	GUID    guid;
	BSTR    bstrHelpFile;
};


/////////////////////////////////////////////////////////////////////////////
// CErrorsDialog dialog

class CErrorsDialog : public CDialog
{
// Construction
public:
	CErrorsDialog(CWnd* pParent = NULL);   // standard constructor
	~CErrorsDialog()
	{
		while (!m_listErrorInfo.IsEmpty())
		{
			struct MYERRORINFO* pInfo = (MYERRORINFO*)m_listErrorInfo.RemoveTail();
			SysFreeString(pInfo->bstrSource);
			SysFreeString(pInfo->bstrDescription);
			SysFreeString(pInfo->bstrHelpFile);
			delete pInfo;
			pInfo = NULL;
		}
		m_listErrorInfo.RemoveAll();
	}
	void Init(IUnknown* pUnk, const IID& iid)
	{
		m_spUnk = pUnk;
		m_iid = iid;
	}

// Dialog Data
	//{{AFX_DATA(CErrorsDialog)
	enum { IDD = IDD_ERRORS };
	CEdit   m_ctlGUID;
	CListBox    m_ctlListSource;
	CEdit   m_ctlDescription;
	CButton m_ctlHelp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CErrorsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void SelectSource(int nSel);
	CPtrList m_listErrorInfo;
	CComPtr<IUnknown> m_spUnk;
	IID m_iid;
	int m_nSelectedItem;

	// Generated message map functions
	//{{AFX_MSG(CErrorsDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnHelp();
	afx_msg void OnSelChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORDLG_H__EAC8D343_DDCB_11D0_8470_00A0C905A456__INCLUDED_)
