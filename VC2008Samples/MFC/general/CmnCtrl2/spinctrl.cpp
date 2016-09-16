// SpinCtrl.cpp : implementation file
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
#include "CmnCtrl2.h"
#include "SpinCtrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrlPage property page

IMPLEMENT_DYNCREATE(CSpinCtrlPage, CPropertyPage)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CSpinCtrlPage::CSpinCtrlPage() : CPropertyPage(CSpinCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CSpinCtrlPage)
	m_iAlignment = 0;
	m_bArrowkeys = FALSE;
	m_bAutobuddy = FALSE;
	m_uiRangeFrom = 0;
	m_bNothousands = FALSE;
	m_iOrientation = 0;
	m_bSetbuddyint = FALSE;
	m_uiRangeTo = 100;
	m_bWrap = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CSpinCtrlPage::~CSpinCtrlPage()
{
}

void CSpinCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpinCtrlPage)
	DDX_CBIndex(pDX, IDC_SPIN_ALIGNMENT, m_iAlignment);
	DDX_Check(pDX, IDC_SPIN_ARROWKEYS, m_bArrowkeys);
	DDX_Check(pDX, IDC_SPIN_AUTOBUDDY, m_bAutobuddy);
	DDX_Text(pDX, IDC_SPIN_FROM, m_uiRangeFrom);
	DDV_MinMaxUInt(pDX, m_uiRangeFrom, 0, 65535);
	DDX_Check(pDX, IDC_SPIN_NOTHOUSANDS, m_bNothousands);
	DDX_CBIndex(pDX, IDC_SPIN_ORIENTATION, m_iOrientation);
	DDX_Check(pDX, IDC_SPIN_SETBUDDYINT, m_bSetbuddyint);
	DDX_Text(pDX, IDC_SPIN_TO, m_uiRangeTo);
	DDV_MinMaxUInt(pDX, m_uiRangeTo, 0, 65535);
	DDX_Check(pDX, IDC_SPIN_WRAP, m_bWrap);
	//}}AFX_DATA_MAP
}

BOOL CSpinCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CWnd* pEdit = GetDlgItem( IDC_SPIN_EDIT );
	pEdit->GetWindowRect( &m_EditRect );
	ScreenToClient( &m_EditRect );

	CreateSpinCtrl();
	SetModified(TRUE);  // allow the APPLY button to become active

	return TRUE;
}

void CSpinCtrlPage::CreateSpinCtrl()
{
DWORD dwStyles=0;

	// Build styles mask
	if ( 1 == m_iAlignment )
		dwStyles |= UDS_ALIGNLEFT;      // Control is placed to the left of buddy, if set
										// (default = unattached)
	else if ( 2 == m_iAlignment )
		dwStyles |= UDS_ALIGNRIGHT;     // Control is placed to the right of buddy, if set
										// (default = unattached)
	if ( m_bArrowkeys )
		dwStyles |= UDS_ARROWKEYS;      // Up/Down arrow keys inc/decrement, if set

	if ( m_bAutobuddy )
		dwStyles |= UDS_AUTOBUDDY;      // Previous (in Z-order) edit used as buddy, if set

	if ( m_bNothousands )
		dwStyles |= UDS_NOTHOUSANDS;    // No thousands seperator used, if set

	if ( 1 == m_iOrientation )
		dwStyles |= UDS_HORZ;           // Control is horizontal, if set (default = vert)

	if ( m_bSetbuddyint )
		dwStyles |= UDS_SETBUDDYINT;    // Control updates buddy edit with position, if set

	if ( m_bWrap )
		dwStyles |= UDS_WRAP;           // Position wraps when range exceeded, if set

	// Get edit control and change Z-order (created controls go at bottom of Z-order)
	CWnd* pEdit = GetDlgItem( IDC_SPIN_EDIT );
	pEdit->SetWindowPos( &wndBottom, m_EditRect.left, m_EditRect.top,
						 m_EditRect.Width(), m_EditRect.Height(), SWP_SHOWWINDOW );

	// Create spin (up-down) control
	CWnd* pWnd = GetDlgItem( IDC_SPIN_POS );
	CRect rect;
	pWnd->GetWindowRect( &rect );
	ScreenToClient( &rect );

	m_Spin.Create( WS_VISIBLE|WS_CHILD|dwStyles, rect, this, IDC_SPIN );
	m_Spin.SetRange( (short)m_uiRangeFrom, (short)m_uiRangeTo );  // Sends UDM_SETRANGE

	// Prime edit control with initial value
	TCHAR buf[32];
	int pos = m_Spin.GetPos();                      // Sends UDM_GETPOS
	_stprintf_s( buf, 32, _T("%d"), pos );
	pWnd = m_Spin.GetBuddy();                       // Sends UDM_GETBUDDY
	if (pWnd != NULL && HIWORD(pos) != 1)           // Check for error in high word
		pWnd->SetWindowText( buf );
}

BEGIN_MESSAGE_MAP(CSpinCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSpinCtrlPage)
	ON_BN_CLICKED(IDC_SPIN_ARROWKEYS, OnAnyChange)
	ON_BN_CLICKED(IDC_SPIN_AUTOBUDDY, OnAnyChange)
	ON_BN_CLICKED(IDC_SPIN_NOTHOUSANDS, OnAnyChange)
	ON_CBN_SELCHANGE(IDC_SPIN_ORIENTATION, OnAnyChange)
	ON_BN_CLICKED(IDC_SPIN_SETBUDDYINT, OnAnyChange)
	ON_EN_CHANGE(IDC_SPIN_TO, OnAnyChange)
	ON_BN_CLICKED(IDC_SPIN_WRAP, OnAnyChange)
	ON_EN_CHANGE(IDC_SPIN_EDIT, OnAnyChange)
	ON_EN_CHANGE(IDC_SPIN_FROM, OnAnyChange)
	ON_CBN_SELCHANGE(IDC_SPIN_ALIGNMENT, OnAnyChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinCtrlPage message handlers

BOOL CSpinCtrlPage::OnApply()
{
	UpdateData();
	m_Spin.DestroyWindow();

	CreateSpinCtrl();
	return TRUE;
}

void CSpinCtrlPage::OnAnyChange()
{
  SetModified(TRUE);
}
