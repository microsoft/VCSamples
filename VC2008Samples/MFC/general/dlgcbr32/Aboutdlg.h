// AboutDlg.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.




/*****************************************************************************
  ABOUTDLG.H

  Purpose:
	Interface for CAboutDlg, which displays the application About Box.

  Functions:
	CAboutDlg::CAboutDlg()          -- constructor
	CAboutDlg::DoDataExchange()     -- dialog data exchange/validation
	CAboutDlg::OnInitDialog()       -- initialize dialog

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __ABOUTDLG_H__
#define __ABOUTDLG_H__

class CAboutDlg : public CDialog
{
// Construction
public:
	CAboutDlg(CWnd* pParent = NULL);    // standard constructor

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUT };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif //__ABOUTDLG_H__
