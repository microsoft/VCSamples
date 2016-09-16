// mainfrm.h : interface of the CMainFrame class
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

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CComboToolBar    m_wndToolBar;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	BOOL CreateComboBox();

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnViewStatusBar();
	afx_msg void OnEditFindCombo();
	//}}AFX_MSG
	afx_msg void OnUpdateViewStatusBar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLineNumber(CCmdUI* pCmdUI);
	afx_msg void OnUpdateClock(CCmdUI* pCmdUI);

	// timer call back function
	static void CALLBACK EXPORT UpdateTime(HWND hWnd,UINT nMsg, UINT_PTR nIDEvent, DWORD dwTime);
	DECLARE_MESSAGE_MAP()
};

inline CNotepadView* GetApplicationView()
{
	CFrameWnd* pFrame = (CFrameWnd*)AfxGetMainWnd();
	ENSURE(pFrame);
	return (CNotepadView*)(pFrame)->GetActiveView();
}

/////////////////////////////////////////////////////////////////////////////
