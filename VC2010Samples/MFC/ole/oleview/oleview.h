// oleview.h : main header file for the Ole2View application
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

#ifndef _Ole2View_H_
#define _Ole2View_H_

#include "iviewers\\iviewers.h"

#include "resource.h"       // main symbols
#include "util.h"
#include "mainfrm.h"
#include "doc.h"

#ifdef WIN32
	#define GETCLASSUINT(hwnd, index)       (UINT)GetClassLong(hwnd, index)
	#define GETCLASSBRBACKGROUND(hwnd)      (HBRUSH)GETCLASSUINT(hwnd, GCL_HBRBACKGROUND)
	#define MGetModuleUsage(h)                  ((h), 2)
#else
	#define GETCLASSUINT(hwnd, index)       (UINT)GetClassWord(hwnd, index)
	#define GETCLASSBRBACKGROUND(hwnd)      (HBRUSH)GETCLASSUINT(hwnd, GCW_HBRBACKGROUND)
	#define MGetModuleUsage          GetModuleUsage
#endif

// override CListBox so we pass WM_COMMANDHELP on
//
class CMyListBox : public CListBox
{
public:
	DECLARE_DYNCREATE(CMyListBox)

protected:
	afx_msg LRESULT OnCommandHelp(WPARAM, LPARAM lParam) ;

	DECLARE_MESSAGE_MAP()
} ;

#include "regview.h"
#include "obj_vw.h"

#define IDB_FIRST       IDB_QUESTION
#define BMINDEX(x)      (x - IDB_FIRST)

/////////////////////////////////////////////////////////////////////////////
// COle2ViewApp:
// See Ole2View.cpp for the implementation of this class
//

class COle2ViewApp : public CWinApp
{
public:
	COle2ViewApp();

	CFont*   m_pFont ;
	CFont*   m_pFontBold ;
	UINT     m_cyFont ;

	CImageList    m_images ;

	CString     m_szStatusText ;

	void        LoadBitmaps(BOOL fFree);
	void        FreeBitmaps();
// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// Implementation

	//{{AFX_MSG(COle2ViewApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern COle2ViewApp theApp ;


#endif // _Ole2View_H_
