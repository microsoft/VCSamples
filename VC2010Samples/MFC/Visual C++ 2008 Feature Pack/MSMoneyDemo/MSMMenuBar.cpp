// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// MSMMenuBar.cpp : implementation file
//

#include "stdafx.h"
#include "MSMMenuBar.h"

#include "MSMVisualManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMMenuBar

IMPLEMENT_DYNCREATE(CMSMMenuBar, CMFCMenuBar)

CMSMMenuBar::CMSMMenuBar ()
{
}

CMSMMenuBar::~CMSMMenuBar ()
{
}

BEGIN_MESSAGE_MAP(CMSMMenuBar, CMFCMenuBar)
	ON_WM_CREATE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMMenuBar message handlers

int CMSMMenuBar::OnCreate (LPCREATESTRUCT lpCreateStruct) 
{
	if (CMFCMenuBar::OnCreate (lpCreateStruct) == -1)
		return -1;

	SetPaneStyle((GetPaneStyle () & 
		~(CBRS_GRIPPER | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT))
		| CBRS_SIZE_DYNAMIC);
	SetBorders ();
	
	return 0;
}
