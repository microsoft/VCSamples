// MonthCalPage.cpp : implementation file
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
#include "resource.h"

#include "MonthCal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonthCalPage property page

IMPLEMENT_DYNCREATE(CMonthCalPage, CPropertyPage)

CMonthCalPage::CMonthCalPage() : CPropertyPage(CMonthCalPage::IDD)
{
	//{{AFX_DATA_INIT(CMonthCalPage)
	m_nMaxSelCount = 0;
	m_pszRange = _T("");
	m_pszSelection = _T("");
	m_bDayState = FALSE;
	m_bNoToday = FALSE;
	m_bNoTodayCircle = FALSE;
	m_bWeekNumbers = FALSE;
	m_bMultiSelect = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CMonthCalPage::~CMonthCalPage()
{
}

void CMonthCalPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonthCalPage)
	DDX_Control(pDX, IDC_EDSELRANGE, m_edMaxSel);
	DDX_Control(pDX, IDC_NOTIFYLIST, m_NotifyList);
	DDX_Text(pDX, IDC_EDSELRANGE, m_nMaxSelCount);
	DDX_Text(pDX, IDC_STRRANGE, m_pszRange);
	DDX_Text(pDX, IDC_STRSELECTION, m_pszSelection);
	DDX_Check(pDX, IDC_CKDAYSTATE, m_bDayState);
	DDX_Check(pDX, IDC_CKNOTODAY, m_bNoToday);
	DDX_Check(pDX, IDC_CKNOTODAYCIRCLE, m_bNoTodayCircle);
	DDX_Check(pDX, IDC_CKWEEKNUMBERS, m_bWeekNumbers);
	DDX_Check(pDX, IDC_CMULTISELECT, m_bMultiSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonthCalPage, CPropertyPage)
	//{{AFX_MSG_MAP(CMonthCalPage)
	ON_BN_CLICKED(IDC_CKNOTODAY, OnCknotoday)
	ON_BN_CLICKED(IDC_CKNOTODAYCIRCLE, OnCknotodaycircle)
	ON_BN_CLICKED(IDC_CKWEEKNUMBERS, OnCkweeknumbers)
	ON_BN_CLICKED(IDC_CMULTISELECT, OnCmultiselect)
	ON_EN_CHANGE(IDC_EDSELRANGE, OnChangeEdselrange)
	ON_BN_CLICKED(IDC_CKDAYSTATE, OnCkdaystate)
	//}}AFX_MSG_MAP
	ON_NOTIFY(MCN_SELCHANGE,IDC_MONTHCAL,HandleSelChange)
	ON_NOTIFY(MCN_SELECT,IDC_MONTHCAL,HandleSelect)
	ON_NOTIFY(MCN_GETDAYSTATE,IDC_MONTHCAL,GetDayState)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonthCalPage message handlers

BOOL CMonthCalPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CWnd *pFrame = GetDlgItem(IDC_MCFRAME);
	CRect rcWnd;
	pFrame->GetClientRect(rcWnd);
	pFrame->DestroyWindow(); //pFrame was just a placeholder anyway.
	m_MonthCal.Create(WS_CHILD|WS_VISIBLE,CPoint(rcWnd.left,rcWnd.top),this,IDC_MONTHCAL);
	m_nMaxSelCount = m_MonthCal.GetMaxSelCount();
	UpdateData(FALSE);

	return TRUE;
}

void CMonthCalPage::OnCknotoday()
{
	UpdateData(TRUE);

	if(m_bNoToday)
	{
		//add style
		m_MonthCal.ModifyStyle(0,MCS_NOTODAY,SWP_NOSIZE);
	}
	else
	{
		//remove style
		m_MonthCal.ModifyStyle(MCS_NOTODAY,0,SWP_NOSIZE);
	}
	m_MonthCal.SizeMinReq();
}
void CMonthCalPage::OnCknotodaycircle()
{
	UpdateData(TRUE);
	if(m_bNoTodayCircle)
	{
		//add style
		m_MonthCal.ModifyStyle(0,MCS_NOTODAYCIRCLE,SWP_NOSIZE);
	}
	else
	{
		//remove style
		m_MonthCal.ModifyStyle(MCS_NOTODAYCIRCLE,SWP_NOSIZE);
	}

}
void CMonthCalPage::OnCkweeknumbers()
{
	UpdateData(TRUE);
	if(m_bWeekNumbers)
	{
		//add style
		m_MonthCal.ModifyStyle(0,MCS_WEEKNUMBERS,SWP_NOSIZE);
	}
	else
	{
		//remove style
		m_MonthCal.ModifyStyle(MCS_WEEKNUMBERS,SWP_NOSIZE);
	}
	m_MonthCal.SizeMinReq();

}

void CMonthCalPage::OnCmultiselect()
{
	UpdateData(TRUE);
	if(m_bMultiSelect)
	{
		long lStyle; CRect rc;
		lStyle = ::GetWindowLong(m_MonthCal.m_hWnd,GWL_STYLE);
		lStyle |= MCS_MULTISELECT;
		m_MonthCal.GetClientRect(rc);
		m_MonthCal.DestroyWindow();
		m_MonthCal.Create(lStyle,CPoint(rc.left,rc.top),this,IDC_MONTHCAL);
		m_nMaxSelCount = m_MonthCal.GetMaxSelCount();
		UpdateData(FALSE);
		m_edMaxSel.EnableWindow(TRUE);

	}
	else
	{
		//remove style
		long lStyle; CRect rc;
		lStyle = ::GetWindowLong(m_MonthCal.m_hWnd,GWL_STYLE);
		lStyle &= ~MCS_MULTISELECT;
		m_MonthCal.GetClientRect(rc);
		m_MonthCal.DestroyWindow();
		m_MonthCal.Create(lStyle,CPoint(rc.left,rc.top),this,IDC_MONTHCAL);
		m_nMaxSelCount = m_MonthCal.GetMaxSelCount();
		UpdateData(FALSE);
		m_edMaxSel.EnableWindow(FALSE);
	}

}

void CMonthCalPage::OnCkdaystate()
{
	UpdateData(TRUE);
	if(m_bDayState)
	{
		long lStyle; CRect rc;
		lStyle = ::GetWindowLong(m_MonthCal.m_hWnd,GWL_STYLE);
		lStyle |= MCS_DAYSTATE;
		m_MonthCal.GetClientRect(rc);
		m_MonthCal.DestroyWindow();
		m_MonthCal.Create(lStyle,CPoint(rc.left,rc.top),this,IDC_MONTHCAL);
		UpdateData(FALSE);

	}
	else
	{
		//remove style
		long lStyle; CRect rc;
		lStyle = ::GetWindowLong(m_MonthCal.m_hWnd,GWL_STYLE);
		lStyle &= ~MCS_DAYSTATE;
		m_MonthCal.GetClientRect(rc);
		m_MonthCal.DestroyWindow();
		m_MonthCal.Create(lStyle,CPoint(rc.left,rc.top),this,IDC_MONTHCAL);
		m_nMaxSelCount = m_MonthCal.GetMaxSelCount();
		UpdateData(FALSE);
	}
}

//Notification handlers for notifications from the MonthCal control
void CMonthCalPage::GetDayState(NMHDR *pHdr, LRESULT* /*pRes*/)
{
	NMDAYSTATE *pds = (NMDAYSTATE*)pHdr;
	m_NotifyList.AddString(_T("MCN_GETDAYSTATE"));
	//this function just bolds the first four days of every visible
	//month.
	for(int i=0;i<pds->cDayState;i++)
		pds->prgDayState[i]=0xf;

}

void CMonthCalPage::HandleSelect(NMHDR* /*pHdr*/, LRESULT* /*pRes*/)
{
	m_NotifyList.AddString(_T("MCN_SELECT"));
	if((m_MonthCal.GetStyle() & MCS_MULTISELECT))
		return;
	CTime ct;
	m_MonthCal.GetCurSel(ct);
	m_pszSelection.Format(_T("%02d/%02d/%2d"),ct.GetMonth(),ct.GetDay(),ct.GetYear());
	UpdateData(FALSE);

}

void CMonthCalPage::HandleSelChange(NMHDR* /*pHdr*/, LRESULT* /*pRes*/)
{

	m_NotifyList.AddString(_T("MCN_SELCHANGE"));
	if(! (m_MonthCal.GetStyle() & MCS_MULTISELECT))
		return;
	CTime ctmin,ctmax;
	m_MonthCal.GetSelRange(ctmin,ctmax);
	m_pszRange.Format(_T("%02d/%02d/%2d to %02d/%02d/%2d"), ctmin.GetMonth(),ctmin.GetDay(),ctmin.GetYear(),
								ctmax.GetMonth(),ctmax.GetDay(),ctmax.GetYear());
	UpdateData(FALSE);
}

//Handler for selection range edit control
void CMonthCalPage::OnChangeEdselrange()
{
	UpdateData(TRUE);
	m_MonthCal.SetMaxSelCount(m_nMaxSelCount);
}
