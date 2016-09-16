// DLGBARS.cpp : Defines the class behaviors for the dialog tool bar
//               and status bar.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include <afxpriv.h>

#include "dlgbars.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBar

BEGIN_MESSAGE_MAP(CDlgToolBar, CToolBar)
	//{{AFX_MSG_MAP(CDlgToolBar)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBar Construction/Destruction

CDlgToolBar::CDlgToolBar()
{
}

CDlgToolBar::~CDlgToolBar()
{
}

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBar::OnIdleUpdateCmdUI
//      OnIdleUpdateCmdUI handles the WM_IDLEUPDATECMDUI message, which is
//      used to update the status of user-interface elements within the MFC
//      framework.
//
//      We have to get a little tricky here: CToolBar::OnUpdateCmdUI
//      expects a CFrameWnd pointer as its first parameter.  However, it
//      doesn't do anything but pass the parameter on to another function
//      which only requires a CCmdTarget pointer.  We can get a CWnd pointer
//      to the parent window, which is a CCmdTarget, but may not be a
//      CFrameWnd.  So, to make CToolBar::OnUpdateCmdUI happy, we will call
//      our CWnd pointer a CFrameWnd pointer temporarily.

LRESULT CDlgToolBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM)
{
	if (IsWindowVisible())
	{
		CFrameWnd *pParent = (CFrameWnd *)GetParent();
		if (pParent)
			OnUpdateCmdUI(pParent, (BOOL)wParam);
	}
	return 0L;
}

/////////////////////////////////////////////////////////////////////////////
// CDlgStatusBar

BEGIN_MESSAGE_MAP(CDlgStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CDlgStatusBar)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgStatusBar Construction/Destruction

CDlgStatusBar::CDlgStatusBar()
{
}

CDlgStatusBar::~CDlgStatusBar()
{
}

/////////////////////////////////////////////////////////////////////////////
// CDlgStatusBar::OnIdleUpdateCmdUI
//      OnIdleUpdateCmdUI handles the WM_IDLEUPDATECMDUI message, which is
//      used to update the status of user-interface elements within the MFC
//      framework.
//
//      We have to get a little tricky here: CStatusBar::OnUpdateCmdUI
//      expects a CFrameWnd pointer as its first parameter.  However, it
//      doesn't do anything but pass the parameter on to another function
//      which only requires a CCmdTarget pointer.  We can get a CWnd pointer
//      to the parent window, which is a CCmdTarget, but may not be a
//      CFrameWnd.  So, to make CStatusBar::OnUpdateCmdUI happy, we will call
//      our CWnd pointer a CFrameWnd pointer temporarily.

LRESULT CDlgStatusBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM)
{
	if (IsWindowVisible())
	{
		CFrameWnd *pParent = (CFrameWnd *)GetParent();
		if (pParent)
			OnUpdateCmdUI(pParent, (BOOL)wParam);
	}
	return 0L;
}
