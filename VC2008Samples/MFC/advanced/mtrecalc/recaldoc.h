// recaldoc.h : interface of the CRecalcDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CRecalcDoc : public CDocument
{
protected: // create from serialization only
	CRecalcDoc();
	DECLARE_DYNCREATE(CRecalcDoc)

// Attributes
public:
	int m_nInt1;
	int m_nInt2;
	int m_nSum;
	BOOL m_bRecalcInProgress;
	BOOL m_bRecalcNeeded;
	int m_nRecalcSpeedSeconds;

	UINT m_nCurrentDemoCommand;
	CWinThread* m_pRecalcWorkerThread;
	CRecalcThreadInfo m_recalcThreadInfo;
	HANDLE m_hEventStartRecalc;
	HANDLE m_hEventRecalcDone;
	HANDLE m_hEventKillRecalcThread;
	HANDLE m_hEventRecalcThreadKilled;

// Operations
public:
	void UpdateInt1AndInt2(int n1, int n2, BOOL bForceRecalc);
	void RecalcDone();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRecalcDoc)
	public:
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	void RecalcInSingleThread();
	void RecalcInSecondThread();

	virtual ~CRecalcDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void OnDemoThread(UINT nCmdID);
	void OnUpdateDemoThread(CCmdUI* pCmdUI);
	//{{AFX_MSG(CRecalcDoc)
	afx_msg void OnRecalcSpeed();
	afx_msg void OnKillWorkerThread();
	afx_msg void OnUpdateKillWorkerThread(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
