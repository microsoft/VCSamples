// DHtmlExploreDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CDHtmlExploreDlg dialog

class CDHtmlExploreDlg : public CDHtmlDialog
{
// Construction
public:
	CDHtmlExploreDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDHtmlExploreDlg)
	enum { IDD = IDD_DHTMLEXPLORE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDHtmlExploreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	void RefreshDir();
	CString m_strCurrDir;
	void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl);

	HRESULT OnBrowse(IHTMLElement *phtmlElement);
	HRESULT OnMouseOverElement(IHTMLElement *phtmlElement);
	HRESULT OnMouseOutElement(IHTMLElement *phtmlElement);
	HRESULT OnClickFolder(IHTMLElement *phtmlElement);
	HRESULT OnClickFile(IHTMLElement *phtmlElement);
	HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);

	CComPtr<IHTMLElement> m_spCurrElement;
	CString m_strCtxFileName;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDHtmlExploreDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnContextBrowse();
	afx_msg void OnContextExit();
	afx_msg void OnContextProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
