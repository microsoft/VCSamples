// ProgCtrl.cpp : implementation file
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
#include "ProgCtrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgCtrlPage property page

IMPLEMENT_DYNCREATE(CProgCtrlPage, CPropertyPage)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CProgCtrlPage::CProgCtrlPage() : CPropertyPage(CProgCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CProgCtrlPage)
	m_iDelta = 0;
	m_uiStep = 10;
	m_uiRangeFrom = 0;
	m_uiPos = 0;
	m_uiRangeTo = 175;
	m_bVertical = FALSE;
	m_bSmooth = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button

}

CProgCtrlPage::~CProgCtrlPage()
{
}

void CProgCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgCtrlPage)
	DDX_Text(pDX, IDC_PROGRESS_DELTA, m_iDelta);
	DDX_Text(pDX, IDC_PROGRESS_STEP, m_uiStep);
	DDV_MinMaxUInt(pDX, m_uiStep, 0, 65535);
	DDX_Text(pDX, IDC_PROGRESS_FROM, m_uiRangeFrom);
	DDV_MinMaxUInt(pDX, m_uiRangeFrom, 0, 65535);
	DDX_Text(pDX, IDC_PROGRESS_POS, m_uiPos);
	DDV_MinMaxUInt(pDX, m_uiPos, 0, 65535);
	DDX_Text(pDX, IDC_PROGRESS_TO, m_uiRangeTo);
	DDV_MinMaxUInt(pDX, m_uiRangeTo, 0, 65535);
	DDX_Check(pDX, IDC_VERTICAL, m_bVertical);
	DDX_Check(pDX, IDC_SMOOTH, m_bSmooth);
	//}}AFX_DATA_MAP
}

BOOL CProgCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Initially create progress control in horizontal position
	CWnd* pWnd =
		GetDlgItem( IDC_PROG_HORZPOS );
	CRect rect;
	pWnd->GetWindowRect( &rect );
	ScreenToClient( &rect );

	// Initialise controls
	m_Progress.Create( WS_VISIBLE | WS_CHILD, rect, this, IDC_PROGRESS );
	m_Progress.SetRange( static_cast<short>(m_uiRangeFrom), static_cast<short>(m_uiRangeTo) );

	return TRUE;
}

BEGIN_MESSAGE_MAP(CProgCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CProgCtrlPage)
	ON_BN_CLICKED(IDC_PROGRESS_STEPIT, OnProgressStepit)
	ON_BN_CLICKED(IDC_SETPOS, OnSetpos)
	ON_BN_CLICKED(IDC_PROGRESS_SETDELTA, OnProgressSetdelta)
	ON_EN_KILLFOCUS(IDC_PROGRESS_FROM, OnFrom)
	ON_EN_KILLFOCUS(IDC_PROGRESS_TO, OnTo)
	ON_EN_KILLFOCUS(IDC_PROGRESS_STEP, OnStep)
	ON_BN_CLICKED(IDC_SMOOTH, OnStyleChange)
	ON_BN_CLICKED(IDC_VERTICAL, OnStyleChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgCtrlPage message handlers

void CProgCtrlPage::OnProgressStepit()
{
	m_Progress.StepIt();
}

void CProgCtrlPage::OnSetpos()
{
	UpdateData();
	m_Progress.SetPos( m_uiPos );
}

void CProgCtrlPage::OnProgressSetdelta()
{
	UpdateData();
	m_Progress.OffsetPos( m_iDelta );
}

void CProgCtrlPage::OnFrom()
{
	UpdateData();
	m_Progress.SetRange( static_cast<short>(m_uiRangeFrom), static_cast<short>(m_uiRangeTo) );
}

void CProgCtrlPage::OnTo()
{
	UpdateData();
	m_Progress.SetRange( static_cast<short>(m_uiRangeFrom), static_cast<short>(m_uiRangeTo) );
}

void CProgCtrlPage::OnStep()
{
	UpdateData();
	m_Progress.SetStep( m_uiStep );
}

void CProgCtrlPage::OnStyleChange()
{
	UpdateData();

	m_Progress.DestroyWindow();

	// Determine orientation
	CWnd* pWnd =
		GetDlgItem( (0==m_bVertical)?IDC_PROG_HORZPOS:IDC_PROG_VERTPOS );
	CRect rect;
	pWnd->GetWindowRect( &rect );
	ScreenToClient( &rect );

	DWORD dwStyle= 0;
	if( m_bSmooth)
		dwStyle= PBS_SMOOTH;
	if(0 == m_bVertical)
		m_Progress.Create( WS_VISIBLE | WS_CHILD |
			dwStyle, rect, this, IDC_PROGRESS );
	else
		m_Progress.Create( WS_VISIBLE | WS_CHILD |
			PBS_VERTICAL | dwStyle, rect, this, IDC_PROGRESS );
	m_Progress.SetRange(static_cast<short>(m_uiRangeFrom), static_cast<short>(m_uiRangeTo));
}
