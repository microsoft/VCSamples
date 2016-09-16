// dllhusk.h : main header file for the DLLHUSK application
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
// CHuskApp:
// See dllhusk.cpp for the implementation of this class
//

class CListOutputFrame;     // from TESTDLL2

class CHuskApp : public CWinApp
{
public:
	CHuskApp();

// Attributes
	CListOutputFrame* m_pListOut;

// Overrides
	virtual BOOL InitInstance();

// Implementation
	BOOL CreateListOutput();

	//{{AFX_MSG(CHuskApp)
	afx_msg void OnAppAbout();
	afx_msg void OnDumpClasses();           // debug only
	afx_msg void OnDumpDocTemplates();      // debug only
	afx_msg void OnDumpObjects();           // debug only
	afx_msg void OnDumpDLLs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
