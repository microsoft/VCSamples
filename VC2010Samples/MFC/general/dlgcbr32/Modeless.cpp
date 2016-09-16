// Modeless.cpp : implementation file
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
	Implements CModelessDialog, a reusable class for creating modeless
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

#include "stdafx.h"
#include "modeless.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelessDialog

IMPLEMENT_DYNAMIC(CModelessDialog, CDialog)

BEGIN_MESSAGE_MAP(CModelessDialog, CDialog)
	//{{AFX_MSG_MAP(CModelessDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelessDialog Construction/Destruction

CModelessDialog::CModelessDialog()
{
}

CModelessDialog::~CModelessDialog()
{
}

void CModelessDialog::PostNcDestroy()
{
	delete this;
}

/////////////////////////////////////////////////////////////////////////////
// CModelessDialog::OnCancel
//      Modeless dialogs must not call EndDialog(), as CDialog::OnCancel()
//      does.  All we need to do is destroy the window.

void CModelessDialog::OnCancel()
{
	DestroyWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CModelessDialog::OnOK
//      Modeless dialogs must not call EndDialog(), as CDialog::OnOK() does
//      We retrieve data from the controls using DDX, then destroy the
//      window.

void CModelessDialog::OnOK()
{
	if (!UpdateData(TRUE))
	{
		TRACE0("UpdateData failed -- modeless dialog terminate\n");
		return;
	}
	DestroyWindow();
}
