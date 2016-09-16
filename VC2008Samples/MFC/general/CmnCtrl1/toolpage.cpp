// ToolPage.cpp : implementation file
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
#include "CmnCtrl1.h"
#include "toolbar1.h"
#include "toolbar2.h"
#include "ToolPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolBarCtrlPage property page

IMPLEMENT_DYNCREATE(CToolBarCtrlPage, CPropertyPage)

CToolBarCtrlPage::CToolBarCtrlPage() : CPropertyPage(CToolBarCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CToolBarCtrlPage)
	m_bAltDrag = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CToolBarCtrlPage::~CToolBarCtrlPage()
{
}

void CToolBarCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolBarCtrlPage)
	DDX_Check(pDX, IDC_ALTDRAG, m_bAltDrag);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolBarCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CToolBarCtrlPage)
	ON_BN_CLICKED(IDC_ALTDRAG, OnAltdrag)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
#pragma warning(disable : 4706)
BOOL CToolBarCtrlPage::OnInitDialog()
{

	CPropertyPage::OnInitDialog();


	m_StandardBar.Create(WS_BORDER | WS_VISIBLE | WS_CHILD
			| CCS_TOP | CCS_ADJUSTABLE | TBSTYLE_TOOLTIPS,
		CRect(0,0,0,0),this, IDR_STANDARDBAR);

	m_PaletteBar.Create(WS_BORDER | WS_VISIBLE | WS_CHILD
			| CCS_BOTTOM | TBSTYLE_WRAPABLE | TBSTYLE_TOOLTIPS,
		CRect(0,0,0,0),this, IDR_PALETTEBAR);

	m_StandardBar.AutoSize();
	m_PaletteBar.AutoSize();

	m_ToolTip.Create(this);

	CString cstrToolTip;
	CWnd *pWnd = 0;
	CRect rect;

	// Setup the tooltip control for tooltips with the static controls
	for (int nIndex = ID_TOOLBARSTYLE; nIndex <= ID_TBSTYLETOOLTIPS2; nIndex++)
	{
		cstrToolTip.LoadString(nIndex);

		ENSURE(pWnd = GetDlgItem(nIndex));

		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);

		m_ToolTip.AddTool(this, (LPCTSTR)cstrToolTip, &rect, nIndex);
	}

	m_ToolTip.Activate(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
#pragma warning(default : 4706)

void CToolBarCtrlPage::ChangeCtrlStyle(long lStyle, BOOL bSetStyle)
{
	long    lStyleOld;
	CRect   rect;

	m_StandardBar.GetWindowRect(&rect);
	lStyleOld = GetWindowLong( m_StandardBar.GetSafeHwnd(), GWL_STYLE );
	if ( bSetStyle )
		lStyleOld |= lStyle;
	else
		lStyleOld &= ~lStyle;

	SetWindowLong( m_StandardBar.GetSafeHwnd(), GWL_STYLE, lStyleOld );
	m_StandardBar.InvalidateRect(&rect);
}

void CToolBarCtrlPage::OnAltdrag()
{
	UpdateData();
	ChangeCtrlStyle(TBSTYLE_ALTDRAG, m_bAltDrag);
}


LRESULT CToolBarCtrlPage::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// We need to pass these messages to the tooltip for it to determine
	// the position of the mouse

	switch (message)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		{
			MSG msg;
			msg.hwnd = m_hWnd;
			msg.message = message;
			msg.wParam = wParam;
			msg.lParam = lParam;

			m_ToolTip.RelayEvent(&msg);
		}
	}

	return CPropertyPage::WindowProc(message,wParam,lParam);
}
