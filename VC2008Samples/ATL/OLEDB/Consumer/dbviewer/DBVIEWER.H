// DBViewer.h : main header file for the DBVIEWER application
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

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "ctrlext.h"
#include "dbdoc.h"
#include "dbtreevw.h"
#include "dblistvw.h"
#include "dbdoc.h"

/////////////////////////////////////////////////////////////////////////////
// CDBViewApp:
// See DBViewer.cpp for the implementation of this class
//

class CDBViewApp : public CWinApp
{
public:
	BOOL m_bPositionUpdate;
	CDBViewApp();

	BOOL m_nMaxRecords;
	BOOL m_bOpenODBC;
	BOOL m_bShowWarnings;
	BOOL m_bShowSystemObjects;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDBViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
