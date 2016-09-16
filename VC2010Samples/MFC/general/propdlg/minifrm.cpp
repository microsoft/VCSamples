// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#include "shapeobj.h"
#include "resource.h"
#include "colorpge.h"
#include "stylepge.h"
#include "propsht2.h"
#include "minifrm.h"
#include "mainfrm.h"

BEGIN_MESSAGE_MAP(CShapePropSheetFrame, CMiniFrameWnd)
	//{{AFX_MSG_MAP(CShapePropSheetFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_SETFOCUS()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CShapePropSheetFrame::CShapePropSheetFrame()
{
	m_pModelessShapePropSheet = NULL;
}

int CShapePropSheetFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMiniFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pModelessShapePropSheet = new CModelessShapePropSheet(this);
	if (!m_pModelessShapePropSheet->Create(this,
		WS_CHILD | WS_VISIBLE, 0))
	{
		delete m_pModelessShapePropSheet;
		m_pModelessShapePropSheet = NULL;
		return -1;
	}

	// Resize the mini frame so that it fits around the child property
	// sheet.
	CRect rectClient, rectWindow;
	m_pModelessShapePropSheet->GetWindowRect(rectClient);
	rectWindow = rectClient;

	// CMiniFrameWnd::CalcWindowRect adds the extra width and height
	// needed from the mini frame.
	CalcWindowRect(rectWindow);
	SetWindowPos(NULL, rectWindow.left, rectWindow.top,
		rectWindow.Width(), rectWindow.Height(),
		SWP_NOZORDER | SWP_NOACTIVATE);
	m_pModelessShapePropSheet->SetWindowPos(NULL, 0, 0,
		rectClient.Width(), rectClient.Height(),
		SWP_NOZORDER | SWP_NOACTIVATE);

	return 0;
}

void CShapePropSheetFrame::OnClose()
{
	// Instead of closing the modeless property sheet, just hide it.
	CMainFrame* pMainFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	pMainFrame->HideModelessPropSheet();
}

void CShapePropSheetFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// Forward focus to the embedded property sheet
	ASSERT_VALID(m_pModelessShapePropSheet);
	m_pModelessShapePropSheet->SetFocus();
}

void CShapePropSheetFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CMiniFrameWnd::OnActivate(nState, pWndOther, bMinimized);

	// Forward any WM_ACTIVATEs to the property sheet...
	// Like the dialog manager itself, it needs them to save/restore the focus.
	ASSERT_VALID(m_pModelessShapePropSheet);

	// Use GetCurrentMessage to get unmodified message data.
	const MSG* pMsg = GetCurrentMessage();
	ASSERT(pMsg->message == WM_ACTIVATE);
	m_pModelessShapePropSheet->SendMessage(pMsg->message, pMsg->wParam,
		pMsg->lParam);
}
