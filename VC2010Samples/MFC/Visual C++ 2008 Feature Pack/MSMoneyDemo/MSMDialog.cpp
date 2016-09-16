// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// MSMDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MSMDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMDialog dialog


IMPLEMENT_DYNAMIC(CMSMDialog, CDialogEx)

CMSMDialog::CMSMDialog()
	: CDialogEx ()
{
	CommonConstruct ();
}

CMSMDialog::CMSMDialog(UINT nIDTemplate, CWnd* pParentWnd /*=NULL*/)
	: CDialogEx (nIDTemplate, pParentWnd)
{
	CommonConstruct ();
}

CMSMDialog::CMSMDialog(LPCTSTR lpszTemplateName, CWnd *pParentWnd /*=NULL*/)
	: CDialogEx (lpszTemplateName, pParentWnd)
{
	CommonConstruct ();
}

void CMSMDialog::CommonConstruct ()
{
	SetBackgroundColor (RGB (239, 247, 253));
}


BEGIN_MESSAGE_MAP(CMSMDialog, CDialogEx)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMDialog message handlers
