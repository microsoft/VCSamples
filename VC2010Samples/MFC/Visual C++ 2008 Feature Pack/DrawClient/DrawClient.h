// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include <afxtempl.h>       // drawcli uses collection class templates

/////////////////////////////////////////////////////////////////////////////
// CDrawApp:
// See drawcli.cpp for the implementation of this class
//

class CDrawApp : public CWinAppEx
{
public:
	CDrawApp();

	// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	COleTemplateServer m_server;

	// Implementation
protected:
	//{{AFX_MSG(CDrawApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDrawApp theApp;
