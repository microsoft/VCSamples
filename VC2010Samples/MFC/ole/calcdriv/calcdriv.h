// calcdriv.h : main header file for the CALCDRIV application
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
// CCalcDrivApp:
// See calcdriv.cpp for the implementation of this class

class CCalcDrivApp : public CWinApp
{
public:
	CCalcDrivApp();

// Overrides
	virtual BOOL InitInstance();

// Implementation
	//{{AFX_MSG(CCalcDrivApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog

// Include the type-safe class generated from ClassWizard's "Read Type Library"
//  button to interface with the IDispatch enabled calculator object.
#include "calctype.h"

class CDriverDlg : public CDialog
{
// Construction
public:
	CDriverDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverDlg)
	enum { IDD = IDD_CALCDRIV };
	CStatic m_stcOperator;
	CStatic m_stcOperand;
	CStatic m_stcAccum;
	CEdit   m_editExpression;
	//}}AFX_DATA

	// an instance of the IDispatch enabled calculator
	CRemoteCalcDlg m_calc;

// Implementation
public:
	virtual ~CDriverDlg();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(CDriverDlg)
	afx_msg void OnGo();
	afx_msg void OnSingleStep();
	virtual BOOL OnInitDialog();
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
