// typelib.h : header file
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
// CDispatchViewer command target

class CDispatchViewer : public CInterfaceViewer
{
	DECLARE_DYNCREATE(CDispatchViewer)
protected:
	CDispatchViewer();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDispatchViewer)
	public:
//  virtual void OnFinalRelease();
	//}}AFX_VIRTUAL
	virtual HRESULT OnView(HWND hwndParent, REFIID riid, LPUNKNOWN punk);

// Implementation
protected:
	virtual ~CDispatchViewer();

	// Generated message map functions
	//{{AFX_MSG(CDispatchViewer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CDispatchViewer)
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CDispatchDlg dialog

class CDispatchDlg : public CDialog
{
// Construction
public:
	CDispatchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDispatchDlg)
	enum { IDD = IDD_DISPATCH };
	CButton m_btnViewTypeInfo;
	UINT    m_uiTypeInfoCount;
	//}}AFX_DATA

	IDispatch* m_pdisp ;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDispatchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDispatchDlg)
	afx_msg void OnViewTypeInfo();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
