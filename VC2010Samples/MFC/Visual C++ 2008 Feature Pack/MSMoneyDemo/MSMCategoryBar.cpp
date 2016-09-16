// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// MSMCategoriesBar.cpp : implementation file
//

#include "stdafx.h"
#include "MSMoneyDemo.h"
#include "MSMCategoryBar.h"
#include "MSMCategoryBarButton.h"

#include "MSMVisualManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMCategoryBar

IMPLEMENT_DYNCREATE(CMSMCategoryBar, CMSMToolBar)

CMSMCategoryBar::CMSMCategoryBar ()
{
}

CMSMCategoryBar::~CMSMCategoryBar ()
{
}

BEGIN_MESSAGE_MAP(CMSMCategoryBar, CMSMToolBar)
	ON_WM_CREATE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMCategoryBar message handlers

int CMSMCategoryBar::OnCreate (LPCREATESTRUCT lpCreateStruct) 
{
	if (CMSMToolBar::OnCreate (lpCreateStruct) == -1)
		return -1;
	
	RestoreOriginalstate ();

	return 0;
}

BOOL CMSMCategoryBar::RestoreOriginalstate ()
{
	RemoveAllButtons ();

	InsertButton (CMSMCategoryBarButton (_T("Home")     , ID_CATEGORIE_1));
	InsertButton (CMSMCategoryBarButton (_T("Banking")  , ID_CATEGORIE_2));
	InsertButton (CMSMCategoryBarButton (_T("Bills")    , ID_CATEGORIE_3));
	InsertButton (CMSMCategoryBarButton (_T("Reports")  , ID_CATEGORIE_4));
	InsertButton (CMSMCategoryBarButton (_T("Budget")   , ID_CATEGORIE_5));
	InsertButton (CMSMCategoryBarButton (_T("Investing"), ID_CATEGORIE_6));
	InsertButton (CMSMCategoryBarButton (_T("Planning") , ID_CATEGORIE_7));
	InsertButton (CMSMCategoryBarButton (_T("Taxes")    , ID_CATEGORIE_8));

//	EnableCustomizeButton (TRUE, -1, _T(""));

	AdjustLayout ();
	Invalidate ();

	return TRUE;
}
