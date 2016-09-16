// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "DynamicMenu.h"
#include "MyMenuBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMenuBar::CMyMenuBar()
{

}

CMyMenuBar::~CMyMenuBar()
{

}

BOOL CMyMenuBar::RestoreOriginalstate ()
{
	if (!CMFCMenuBar::RestoreOriginalstate ())
	{
		return FALSE;
	}

	AddSubMenu ();
	return TRUE;
}

void CMyMenuBar::AddSubMenu ()
{
	CMenu menu;
	menu.LoadMenu (IDR_DYNAMIC_MENU); 

	InsertButton (CMFCToolBarMenuButton (0, menu, -1, _T ("&DynamicMenu")));

	AdjustLayout();
	AdjustSizeImmediate ();
}
