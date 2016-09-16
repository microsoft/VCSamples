// DateTime.cpp : implementation file
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
#include "RESOURCE.H"
#include "DateTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDateTimePage property page

IMPLEMENT_DYNCREATE(CDateTimePage, CPropertyPage)

CDateTimePage::CDateTimePage() : CPropertyPage(CDateTimePage::IDD)
{
	//{{AFX_DATA_INIT(CDateTimePage)
	m_bAppCanParse = FALSE;
	m_bShowNone = FALSE;
	m_bUpDown = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CDateTimePage::~CDateTimePage()
{
}

void CDateTimePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDateTimePage)
	DDX_Check(pDX, IDC_CKAPPCANPARSE, m_bAppCanParse);
	DDX_Check(pDX, IDC_CKSHOWNONE, m_bShowNone);
	DDX_Check(pDX, IDC_CKUPDOWN, m_bUpDown);
	//}}AFX_DATA_MAP
	DDX_Control(pDX,IDC_LBNOTIFY,m_lbNotifyList);
}


BEGIN_MESSAGE_MAP(CDateTimePage, CPropertyPage)
	//{{AFX_MSG_MAP(CDateTimePage)
	ON_BN_CLICKED(IDC_CKUPDOWN, OnCkupdown)
	ON_BN_CLICKED(IDC_CKTIMEFORMAT, OnCktimeformat)
	ON_BN_CLICKED(IDC_CKSHORTDATEFORMAT, OnCkshortdateformat)
	ON_BN_CLICKED(IDC_CKSHOWNONE, OnCkshownone)
	ON_BN_CLICKED(IDC_CKLONGDATEFORMAT, OnCklongdateformat)
	ON_BN_CLICKED(IDC_CKAPPCANPARSE, OnCkappcanparse)
	//}}AFX_MSG_MAP
	ON_NOTIFY(DTN_CLOSEUP,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_DATETIMECHANGE,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_DROPDOWN ,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_FORMAT,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_FORMATQUERY,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_USERSTRING,IDC_DATETIME, OnDTNotify)
	ON_NOTIFY(DTN_WMKEYDOWN ,IDC_DATETIME, OnDTNotify)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateTimePage message handlers

BOOL CDateTimePage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CWnd *pWnd = GetDlgItem(IDC_DTFRAME);
	CRect rc;
	if(!pWnd) return TRUE;
	pWnd->GetWindowRect(rc);
	pWnd->DestroyWindow(); //pWnd was just a placeholder;
	ScreenToClient(rc);
	m_DateTime.Create(WS_CHILD|WS_VISIBLE|DTS_SHORTDATEFORMAT,rc,this,IDC_DATETIME);
	m_nPrevStyle=DTS_SHORTDATEFORMAT;
	SetCheck(IDC_CKSHORTDATEFORMAT);


	return TRUE;
}

void CDateTimePage::OnCkupdown()
{
	UpdateData(TRUE);

	if(m_bUpDown)
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle |= DTS_UPDOWN;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);
	}
	else
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle &= ~DTS_UPDOWN;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);
	}

}





void CDateTimePage::OnCkshownone()
{
	UpdateData(TRUE);
	if(m_bShowNone)
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle |= DTS_SHOWNONE;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);

	}
	else
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle &= ~DTS_SHOWNONE;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);
	}

}



void CDateTimePage::OnCkappcanparse()
{
	UpdateData(TRUE);
	if(m_bAppCanParse)
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle |= DTS_APPCANPARSE;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);
	}
	else
	{
		CRect rc;
		m_DateTime.GetWindowRect(rc);
		long lStyle = ::GetWindowLong(m_DateTime.m_hWnd,GWL_STYLE);
		lStyle &= ~DTS_APPCANPARSE;
		m_DateTime.DestroyWindow();
		ScreenToClient(rc);
		m_DateTime.Create(lStyle,rc,this,IDC_DATETIME);
	}

}

void CDateTimePage::OnCkshortdateformat()
{
	SetCheck(IDC_CKSHORTDATEFORMAT);
	//remove previous format style
	m_DateTime.ModifyStyle(m_nPrevStyle,0);
	//set this style
	m_DateTime.ModifyStyle(0,DTS_SHORTDATEFORMAT,SWP_NOSIZE);
	m_nPrevStyle=DTS_SHORTDATEFORMAT;
}
void CDateTimePage::OnCklongdateformat()
{
	SetCheck(IDC_CKLONGDATEFORMAT);

	//remove previous format style
	m_DateTime.ModifyStyle(m_nPrevStyle,0);
	//set this style
	m_DateTime.ModifyStyle(0,DTS_LONGDATEFORMAT,SWP_NOSIZE);
	m_nPrevStyle=DTS_LONGDATEFORMAT;
}
void CDateTimePage::OnCktimeformat()
{
	SetCheck(IDC_CKTIMEFORMAT);

	//remove previous format style
	m_DateTime.ModifyStyle(m_nPrevStyle,0);
	//set this style
	m_DateTime.ModifyStyle(0,DTS_TIMEFORMAT,SWP_NOSIZE);
	m_nPrevStyle=DTS_TIMEFORMAT;
}
void CDateTimePage::SetCheck(UINT idBtn)
{
	static UINT buttons []={IDC_CKTIMEFORMAT,IDC_CKLONGDATEFORMAT,IDC_CKSHORTDATEFORMAT};
	CButton *pBtn=NULL;
	for(int i=0;i<3;i++)
	{
		pBtn = (CButton*)GetDlgItem(buttons[i]);
		if(!pBtn) continue;

		if(buttons[i]==idBtn)
			pBtn->SetCheck(1);
		else
			pBtn->SetCheck(0);
	}

}

void CDateTimePage::OnDTNotify(NMHDR *pHdr, LRESULT * /*pRes*/)
{
	switch( pHdr->code)
	{
	case DTN_CLOSEUP:
		m_lbNotifyList.AddString(_T("DTN_CLOSEUP"));
		break;
	case DTN_DATETIMECHANGE:
		m_lbNotifyList.AddString(_T("DTN_DATETIMECHANGE"));
		break;
	case DTN_DROPDOWN:
		m_lbNotifyList.AddString(_T("DTN_DROPDOWN"));
		break;
	case DTN_FORMAT:
		m_lbNotifyList.AddString(_T("DTN_FORMAT"));
		break;
	case DTN_FORMATQUERY:
		m_lbNotifyList.AddString(_T("DTN_FORMATQUERY"));
		break;
	case DTN_USERSTRING:
		m_lbNotifyList.AddString(_T("DTN_USERSTRING"));
		break;
	case DTN_WMKEYDOWN:
		m_lbNotifyList.AddString(_T("DTN_WMKEYDOWN"));
		break;
	}

}
