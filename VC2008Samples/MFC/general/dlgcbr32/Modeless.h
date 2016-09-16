// Modeless.h : header file
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
  Purpose:
	Interface for CModelessDialog, a reusable class for creating modeless
	dialogs.

  Functions:
	CModelessDialog::CModelessDialog()      -- constructor
	CModelessDialog::~CModelessDialog()     -- destructor
	CModelessDialog::OnCancel()             -- WM_COMMAND IDCANCEL handler
	CModelessDialog::OnOK()                 -- WM_COMMAND IDOK handler
	CModelessDialog::PostNcDestroy()        -- called after WM_NCDESTROY

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __MODELESS_H__
#define __MODELESS_H__

class CModelessDialog : public CDialog
{
	DECLARE_DYNAMIC(CModelessDialog)

// Construction
public:
	CModelessDialog();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelessDialog)
	public:
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CModelessDialog();

protected:
	// Generated message map functions
	//{{AFX_MSG(CModelessDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif //__MODELESS_H__
