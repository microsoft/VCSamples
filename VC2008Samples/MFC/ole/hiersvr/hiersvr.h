// hiersvr.h : main header file for the HIERSVR application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerApp:
// See hiersvr.cpp for the implementation of this class
//

class CServerApp : public CWinApp
{
public:
	CServerApp();

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
protected:
	COleTemplateServer m_server;

	//{{AFX_MSG(CServerApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CHierSvrDocTemplate : public CMultiDocTemplate
{
public:
	CHierSvrDocTemplate();

	CDocTemplate::Confidence MatchDocType(LPCTSTR lpszPathName,
		CDocument*& rpDocMatch);
};

/////////////////////////////////////////////////////////////////////////////
