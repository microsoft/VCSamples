// multipad.h : main header file for the Multipad application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#include <afxext.h>
#include "resource.h"

class CMultiPadApp : public CWinApp
{
	BOOL InitInstance();
	//{{AFX_MSG(CMultiPadApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNCREATE(CMainFrame)
	CStatusBar  m_StatusBar;
	CToolBar    m_ToolBar;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CPadDoc : public CDocument
{
	DECLARE_DYNCREATE(CPadDoc)
	void Serialize(CArchive& ar);
	//{{AFX_MSG(CPadDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
