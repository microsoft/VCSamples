// SnapPs.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "SnapVw.h"
#include "SnapPs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapPropertySheet

IMPLEMENT_DYNAMIC(CSnapPropertySheet, CPropertySheet)

CSnapPropertySheet::CSnapPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CSnapPropertySheet::CSnapPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CSnapPropertySheet::~CSnapPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CSnapPropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSnapPropertySheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapPropertySheet message handlers

BOOL CSnapPropertySheet::PreTranslateMessage(MSG* pMsg)
{
	// since CPropertySheet::PreTranslateMessage will eat frame window
	// accelerators, we call all frame windows' PreTranslateMessage first.
	CFrameWnd* pFrameWnd = GetParentFrame();   // start with first parent frame
	while (pFrameWnd != NULL)
	{
		// allow owner & frames to translate before IsDialogMessage does
		if (pFrameWnd->PreTranslateMessage(pMsg))
			return TRUE;

		// try parent frames until there are no parent frames
		pFrameWnd = pFrameWnd->GetParentFrame();
	}

	// otherwise, just let the sheet translate the message
	return CPropertySheet::PreTranslateMessage(pMsg);
}
