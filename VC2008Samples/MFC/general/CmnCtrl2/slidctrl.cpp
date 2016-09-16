// SlidCtrl.cpp : implementation file
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
#include "SlidCtrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSliderCtrlPage property page

IMPLEMENT_DYNCREATE(CSliderCtrlPage, CPropertyPage)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CSliderCtrlPage::CSliderCtrlPage() : CPropertyPage(CSliderCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CSliderCtrlPage)
	m_bAutoticks = TRUE;
	m_bEnablesel = FALSE;
	m_bFixed = FALSE;
	m_uiLine = 10;
	m_bNothumb = FALSE;
	m_bNoticks = FALSE;
	m_iOrientation = 0;
	m_uiPage = 50;
	m_iTickpos = 0;
	m_uiRangeFrom = 0;
	m_uiRangeTo = 100;
	m_uiSelRangeFrom = 20;
	m_uiSelRangeTo = 80;
	m_uiTickFreq = 20;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CSliderCtrlPage::~CSliderCtrlPage()
{
}

void CSliderCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSliderCtrlPage)
	DDX_Control(pDX, IDC_NOTIFICATIONS, m_Notifications);
	DDX_Check(pDX, IDC_SLIDER_AUTOTICKS, m_bAutoticks);
	DDX_Check(pDX, IDC_SLIDER_ENABLESEL, m_bEnablesel);
	DDX_Check(pDX, IDC_SLIDER_FIXED, m_bFixed);
	DDX_Text(pDX, IDC_SLIDER_LINE, m_uiLine);
	DDV_MinMaxUInt(pDX, m_uiLine, 0, 65535);
	DDX_Check(pDX, IDC_SLIDER_NOTHUMB, m_bNothumb);
	DDX_Check(pDX, IDC_SLIDER_NOTICKS, m_bNoticks);
	DDX_CBIndex(pDX, IDC_SLIDER_ORIENTATION, m_iOrientation);
	DDX_Text(pDX, IDC_SLIDER_PAGE, m_uiPage);
	DDV_MinMaxUInt(pDX, m_uiPage, 0, 65535);
	DDX_CBIndex(pDX, IDC_SLIDER_POINT, m_iTickpos);
	DDX_Text(pDX, IDC_SLIDER_RANGEFROM, m_uiRangeFrom);
	DDV_MinMaxUInt(pDX, m_uiRangeFrom, 0, 65535);
	DDX_Text(pDX, IDC_SLIDER_RANGETO, m_uiRangeTo);
	DDV_MinMaxUInt(pDX, m_uiRangeTo, 0, 65535);
	DDX_Text(pDX, IDC_SLIDER_SELRANGEFROM, m_uiSelRangeFrom);
	DDV_MinMaxUInt(pDX, m_uiSelRangeFrom, 0, 65535);
	DDX_Text(pDX, IDC_SLIDER_SELRANGETO, m_uiSelRangeTo);
	DDV_MinMaxUInt(pDX, m_uiSelRangeTo, 0, 65535);
	DDX_Text(pDX, IDC_SLIDER_TICKFREQ, m_uiTickFreq);
	DDV_MinMaxUInt(pDX, m_uiTickFreq, 0, 65535);
	//}}AFX_DATA_MAP
}

BOOL CSliderCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Initially create slider control in horizontal position
	CWnd* pWnd =
		GetDlgItem( IDC_SLIDER_HORZPOS );
	CRect rect;
	pWnd->GetWindowRect( &rect );
	ScreenToClient( &rect );

	// Initialise controls
	m_Slider.Create( WS_VISIBLE|WS_CHILD|TBS_HORZ|TBS_BOTH|TBS_AUTOTICKS,
					 rect, this, IDC_SLIDER );
	m_Slider.SetTicFreq( m_uiTickFreq );    // Send TBM_SETTICFREQ
	m_Slider.SetLineSize( m_uiLine );       // Send TBM_SETLINESIZE
	m_Slider.SetPageSize( m_uiPage );       // Send TBM_SETPAGESIZE
	m_Slider.SetRange( m_uiRangeFrom, m_uiRangeTo, TRUE );
											// Send TBM_SETRANGE
	return TRUE;
}

void CSliderCtrlPage::ChangeCtrlStyle( long lStyle, BOOL bSetBit)
{
	long    lStyleOld;
	CRect   rect;

	lStyleOld = GetWindowLong( m_Slider.GetSafeHwnd(), GWL_STYLE );
	if ( bSetBit )
		lStyleOld |= lStyle;
	else
		lStyleOld &= ~lStyle;
	SetWindowLong( m_Slider.GetSafeHwnd(), GWL_STYLE, lStyleOld );
	m_Slider.GetWindowRect(&rect);
	m_Slider.InvalidateRect(&rect);
}

BEGIN_MESSAGE_MAP(CSliderCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSliderCtrlPage)
	ON_BN_CLICKED(IDC_SLIDER_AUTOTICKS, OnAutoticks)
	ON_EN_KILLFOCUS(IDC_SLIDER_TICKFREQ, OnTickfreq)
	ON_BN_CLICKED(IDC_SLIDER_NOTICKS, OnNoticks)
	ON_BN_CLICKED(IDC_SLIDER_NOTHUMB, OnNothumb)
	ON_BN_CLICKED(IDC_SLIDER_FIXED, OnFixed)
	ON_BN_CLICKED(IDC_SLIDER_ENABLESEL, OnEnablesel)
	ON_EN_KILLFOCUS(IDC_SLIDER_LINE, OnLine)
	ON_EN_KILLFOCUS(IDC_SLIDER_PAGE, OnPage)
	ON_EN_KILLFOCUS(IDC_SLIDER_RANGEFROM, OnRangefrom)
	ON_EN_KILLFOCUS(IDC_SLIDER_RANGETO, OnRangeto)
	ON_CBN_SELCHANGE(IDC_SLIDER_ORIENTATION, OnOrientation)
	ON_CBN_SELCHANGE(IDC_SLIDER_POINT, OnPoint)
	ON_EN_KILLFOCUS(IDC_SLIDER_SELRANGEFROM, OnSelrangefrom)
	ON_EN_KILLFOCUS(IDC_SLIDER_SELRANGETO, OnSelrangeto)
//  ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSliderCtrlPage message handlers

void CSliderCtrlPage::OnAutoticks()
{
	UpdateData();

	// Shows tick marks according to increment/frequency when set (default frequency is 1)
	ChangeCtrlStyle( TBS_AUTOTICKS, m_bAutoticks );

	// Enable/disable edit controls
	GetDlgItem( IDC_SLIDER_TICKFREQ )->EnableWindow( m_bAutoticks );

	if ( m_bAutoticks )
		// Set tick marks with given frequency (1 = tick at every increment)
		m_Slider.SetTicFreq( m_uiTickFreq );    // Send TBM_SETTICFREQ - need TBS_AUTOTICKS
	else
		// Clear tick marks
		m_Slider.ClearTics( TRUE );
}

void CSliderCtrlPage::OnTickfreq()
{
	UpdateData();
	if ( m_bAutoticks )
		// Set tick marks at given frequency (1 = tick at every increment)
		m_Slider.SetTicFreq( m_uiTickFreq );    // Send TBM_SETTICFREQ - need TBS_AUTOTICKS
}

void CSliderCtrlPage::OnNoticks()
{
	UpdateData();

	// Removes tick marks when set
	ChangeCtrlStyle( TBS_NOTICKS, m_bNoticks );
}

void CSliderCtrlPage::OnNothumb()
{
	UpdateData();

	// Removes thumb from slider control when set
	ChangeCtrlStyle( TBS_NOTHUMB, m_bNothumb );
}

void CSliderCtrlPage::OnFixed()
{
	UpdateData();

	// Fixes length of slider thumb when set (
	ChangeCtrlStyle( TBS_FIXEDLENGTH, m_bFixed );
}

void CSliderCtrlPage::OnEnablesel()
{
	UpdateData();
	ChangeCtrlStyle( TBS_ENABLESELRANGE, m_bEnablesel );

	// Enable/disable edit controls
	GetDlgItem( IDC_SLIDER_SELRANGEFROM )->EnableWindow( m_bEnablesel );
	GetDlgItem( IDC_SLIDER_SELRANGETO )->EnableWindow( m_bEnablesel );

	if ( m_bEnablesel )
		// Set selection range
		m_Slider.SetSelection( m_uiSelRangeFrom, m_uiSelRangeTo );  // Send TBM_SETSEL
	else
		// Clear selection range
		m_Slider.ClearSel( TRUE );
}

void CSliderCtrlPage::OnLine()
{
	UpdateData();

	// Set line size (determines effect of arrow keys)
	m_Slider.SetLineSize( m_uiLine );       // Send TBM_SETLINESIZE
}

void CSliderCtrlPage::OnPage()
{
	UpdateData();

	// Set page size (determines effect of PageUp/PageDown keys)
	m_Slider.SetPageSize( m_uiPage );       // Send TBM_SETPAGESIZE
}

void CSliderCtrlPage::OnRangefrom()
{
	UpdateData();

	// Set range of slider control
	m_Slider.SetRangeMin( m_uiRangeFrom, TRUE );    // Send TBM_SETRANGE
}

void CSliderCtrlPage::OnRangeto()
{
	UpdateData();

	// Set range of slider control
	m_Slider.SetRangeMax( m_uiRangeTo, TRUE );  // Send TBM_SETRANGE
}

void CSliderCtrlPage::OnOrientation()
{
	UpdateData();

	// Obtain horz/vert place marker (static control)
	CWnd* pWnd =
		GetDlgItem( (0==m_iOrientation)?IDC_SLIDER_HORZPOS:IDC_SLIDER_VERTPOS );
	CRect rect;
	pWnd->GetWindowRect( &rect );
	ScreenToClient( &rect );

	// Set slider control style
	ChangeCtrlStyle( TBS_HORZ, (0 == m_iOrientation) );
	ChangeCtrlStyle( TBS_VERT, (1 == m_iOrientation) );

	// Move control to horz/vert position
	m_Slider.SetWindowPos( NULL,
						   rect.left, rect.top,
						   rect.Width(), rect.Height(),
						   SWP_NOZORDER|SWP_SHOWWINDOW );
	Invalidate();
}

void CSliderCtrlPage::OnPoint()
{
	UpdateData();

	switch ( m_iTickpos )
	{
	case 0:
		ChangeCtrlStyle( TBS_BOTH );
		break;
	case 1:
		ChangeCtrlStyle( TBS_TOP );     // Same as TBS_LEFT
		ChangeCtrlStyle( TBS_BOTH, FALSE );
		ChangeCtrlStyle( TBS_BOTTOM, FALSE );
		break;
	case 2:
		ChangeCtrlStyle( TBS_BOTTOM );  // Same as TBS_RIGHT
		ChangeCtrlStyle( TBS_BOTH, FALSE );
		ChangeCtrlStyle( TBS_TOP, FALSE );
		break;
	default:
		break;
	}
}

void CSliderCtrlPage::OnSelrangefrom()
{
	UpdateData();
	m_Slider.ClearSel();
	m_Slider.SetSelection( m_uiSelRangeFrom, m_uiSelRangeTo );  // Send TBM_SETSEL
}

void CSliderCtrlPage::OnSelrangeto()
{
	UpdateData();
	m_Slider.ClearSel();
	m_Slider.SetSelection( m_uiSelRangeFrom, m_uiSelRangeTo );  // Send TBM_SETSEL
}
