// TestContainer98.h : main header file for the TESTCONTAINER98 application
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_TESTCONTAINER98_H__198184FF_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
#define AFX_TESTCONTAINER98_H__198184FF_B837_11D0_8DF1_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

const int TCLOG_NULL = 0;
const int TCLOG_OUTPUTWINDOW = 1;
const int TCLOG_DEBUG = 2;
const int TCLOG_FILE = 3;

#define LOAD_STRING_FROM_RESOURCE(s, r) \
if(s.LoadString(r) == FALSE) { AfxThrowResourceException(); }

class CTCOptions
{
public:
   CTCOptions();

public:
   BOOL m_tUserMode;
   int m_iLogType;
   CString m_strLogFileName;
   CString m_strProgID;
   CString m_strDSMFile;
   BOOL m_tAllowWindowless;
   BOOL m_tQuickActivation;
   BOOL m_tTwoPassDrawing;
   BOOL m_tUseIPointerInactive;
   BOOL m_tHonorIgnoreActivateWhenVisible;
   BOOL m_tIOleInPlaceSiteEx;
   BOOL m_tIOleInPlaceSiteWindowless;
   BOOL m_tIAdviseSinkEx;
   BOOL m_tSBindHost;
};

class CTCCommandLineInfo :
   public CCommandLineInfo
{
public:
   CTCCommandLineInfo( CTCOptions* pOptions );

   void ParseInterfaceFlag( LPCTSTR pszParam );
   void ParseOptionFlag( LPCTSTR pszParam );
   void ParseParam( LPCTSTR pszParam, BOOL tFlag, BOOL tLast );
   void ParseServiceFlag( LPCTSTR pszParam );

protected:
   CTCOptions* m_pOptions;
   BOOL m_tExpectingLogFileName;
   BOOL m_tExpectingProgID;
   BOOL m_tExpectingDSMFile;
};

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98App:
// See TestContainer98.cpp for the implementation of this class
//

class CTestContainer98App : public CWinApp
{
public:
	CTestContainer98App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestContainer98App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

   CTCOptions m_options;

   void LoadRegistrySettings();
   void SaveRegistrySettings();

	//{{AFX_MSG(CTestContainer98App)
	afx_msg void OnAppAbout();
	afx_msg void OnOptionsTraceLevelNone();
	afx_msg void OnOptionsTraceLevelNormal();
	afx_msg void OnOptionsTraceLevelVerbose();
	afx_msg void OnUpdateOptionsTraceLevelNone(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOptionsTraceLevelNormal(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOptionsTraceLevelVerbose(CCmdUI* pCmdUI);
	afx_msg void OnFileRegisterControls();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCONTAINER98_H__198184FF_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
