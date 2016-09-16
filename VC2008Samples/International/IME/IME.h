// IME.h : main header file for the IME application
//

#if !defined(AFX_IME_H__8E60BE06_2516_11D4_8ABF_00B0D02D1522__INCLUDED_)
#define AFX_IME_H__8E60BE06_2516_11D4_8ABF_00B0D02D1522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIMEApp:
// See IME.cpp for the implementation of this class
//

class CIMEApp : public CWinApp
{
public:
	CIMEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIMEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIMEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IME_H__8E60BE06_2516_11D4_8ABF_00B0D02D1522__INCLUDED_)
