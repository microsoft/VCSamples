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
#include "RollupPane.h"
#include "InfoBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoBar

CInfoBar::CInfoBar()
{
}

CInfoBar::~CInfoBar()
{
}


BEGIN_MESSAGE_MAP(CInfoBar, CDockablePane)
	//{{AFX_MSG_MAP(CInfoBar)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInfoBar message handlers

void CInfoBar::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CRect rectClient;
	GetClientRect (rectClient);

	dc.FillSolidRect (rectClient, ::GetSysColor (COLOR_3DHILIGHT));
	dc.Draw3dRect (rectClient, ::GetSysColor (COLOR_3DSHADOW),
		::GetSysColor (COLOR_3DLIGHT));

	dc.SetBkMode (TRANSPARENT);
	dc.SetTextColor (::GetSysColor (COLOR_BTNTEXT));
	CFont* pOldFont = (CFont*) dc.SelectStockObject (DEFAULT_GUI_FONT);

	CString str = _T("Information...");
	dc.TextOut (10, 10, str);

	dc.SelectObject (pOldFont);
}
