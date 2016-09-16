// animctrl.cpp : implementation file
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
#include "animctrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrlPage property page

CAnimateCtrlPage::CAnimateCtrlPage()
	: CPropertyPage(CAnimateCtrlPage::IDD),
	m_dwStyle(WS_CHILD|WS_VISIBLE|ACS_CENTER)
{
	//{{AFX_DATA_INIT(CAnimateCtrlPage)
	m_cstrFileName = _T("");
	m_bCentered = TRUE;
	m_bTransparent = FALSE;
	m_bAutoplay = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

void CAnimateCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimateCtrlPage)
	DDX_Check(pDX, IDC_CENTER, m_bCentered);
	DDX_Check(pDX, IDC_TRANSPARENT, m_bTransparent);
	DDX_Check(pDX, IDC_AUTOPLAY, m_bAutoplay);
	DDX_Text(pDX, IDC_EDIT1, m_cstrFileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimateCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CAnimateCtrlPage)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnFileChange)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDC_CENTER, OnCenter)
	ON_BN_CLICKED(IDC_TRANSPARENT, OnTransparent)
	ON_BN_CLICKED(IDC_AUTOPLAY, OnAutoplay)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrlPage message handlers
BOOL CAnimateCtrlPage::OnInitDialog()
{
	if(!CPropertyPage::OnInitDialog())
		return FALSE;

	// Create animation control inside static frame.
	// This is necessary to avoid having the animation control
	// "overflow" the rectangle assigned to it when the
	// ACS_CENTER style is removed.

	CWnd* pFrame = GetDlgItem(IDC_ANIMFRAME);
	pFrame->GetClientRect(&m_rectAnimateCtrl);
	m_AnimateCtrl.Create(m_dwStyle, m_rectAnimateCtrl, pFrame, IDC_ANIMATE);

	return TRUE;
}

void CAnimateCtrlPage::OnFileChange()
{
	UpdateData();
	CFileStatus filestatus;
	if(CFile::GetStatus(m_cstrFileName, filestatus))
		ApplyChanges();
}

void CAnimateCtrlPage::OnBrowse()
{
	CFileDialog dlg( TRUE,_T("AVI"),_T("*.AVI"),
					 OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
					 _T("Animation (*.AVI)|*.AVI|"));

	if( dlg.DoModal()==IDOK )
	{
		m_cstrFileName = dlg.GetPathName();
		UpdateData(FALSE);
		ApplyChanges();
	}
}

void CAnimateCtrlPage::OnCenter()
{
	UpdateData();
	if( m_bCentered )
		m_dwStyle |= ACS_CENTER;
	else
		m_dwStyle &= ~ACS_CENTER;
	ApplyChanges();
}

void CAnimateCtrlPage::OnTransparent()
{
	UpdateData();
	if( m_bTransparent )
		m_dwStyle |= ACS_TRANSPARENT;
	else
		m_dwStyle &= ~ACS_TRANSPARENT;
	ApplyChanges();
}

void CAnimateCtrlPage::OnAutoplay()
{
	UpdateData();
	if( m_bAutoplay )
		m_dwStyle |= ACS_AUTOPLAY;
	else
		m_dwStyle &= ~ACS_AUTOPLAY;
	ApplyChanges();
}

void CAnimateCtrlPage::OnPlay()
{
	// From frame: 1, To frame: end (0xFFFF, or -1),
	// Play once (1)
	m_AnimateCtrl.Play(0,0xFFFF,1);
}

void CAnimateCtrlPage::OnStop()
{
	m_AnimateCtrl.Stop();
}

void CAnimateCtrlPage::ApplyChanges()
{
	// Stop any current animation and close the animation file
	m_AnimateCtrl.Stop();
	m_AnimateCtrl.Close();

	// Set the new style
	::SetWindowLong(m_AnimateCtrl.GetSafeHwnd(), GWL_STYLE, m_dwStyle);
	// A call to SetWindowPos forces the window to re-read its style
	m_AnimateCtrl.SetWindowPos(NULL, 0, 0, m_rectAnimateCtrl.Width(), m_rectAnimateCtrl.Height(),
							   SWP_NOZORDER|SWP_NOMOVE|SWP_NOACTIVATE|SWP_SHOWWINDOW);

	m_AnimateCtrl.Open(m_cstrFileName);
	// force repaint of the portion of the property page occupied by the control
	InvalidateRect(&m_rectAnimateCtrl);
	UpdateWindow();
}
