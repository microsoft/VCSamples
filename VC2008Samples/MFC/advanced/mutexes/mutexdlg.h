// mutexesDlg.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// This sample application is derived from the Mutex application
// distributed with Jeffrey Richter's "Advanced Windows" programming book
// (Microsoft Press).  See the book for more information about Win32
// programming topics, including thread synchronization.

class CCounterThread;
class CDisplayThread;

/////////////////////////////////////////////////////////////////////////////
// CMutexesDlg dialog

class CMutexesDlg : public CDialog
{
// Construction
public:
	CMutexesDlg(CWnd* pParent = NULL);  // standard constructor
	~CMutexesDlg();
// Dialog Data
	//{{AFX_DATA(CMutexesDlg)
	enum { IDD = IDD_MUTEXES_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMutexesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	CString m_strNumber;

	CMutex m_mutex;

	CCounterThread* m_pCounterThread;
	CDisplayThread* m_pDisplayThread;

	void AddToListBox(LPCTSTR szBuffer);

	void OnPriorityChange(UINT nID);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMutexesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPriorityClassChange();
	afx_msg void OnPriorityChangeCntr();
	afx_msg void OnPriorityChangeDisp();
	afx_msg void OnClose();
	afx_msg void OnPause();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
