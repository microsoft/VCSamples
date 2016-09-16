// AllControlsSheet.cpp : implementation file
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

#include "AllControlsSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllControlsSheet

IMPLEMENT_DYNAMIC(CAllControlsSheet, CPropertySheet)

CAllControlsSheet::CAllControlsSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddControlPages();
}

CAllControlsSheet::CAllControlsSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddControlPages();
}

CAllControlsSheet::~CAllControlsSheet()
{
}

void CAllControlsSheet::AddControlPages()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_psh.dwFlags |= PSP_USEHICON;
	m_psh.dwFlags |= PSH_NOAPPLYNOW; // Eliminate the Apply button
	m_psh.hIcon = m_hIcon;

	// Eliminate the Help button
	m_psh.dwFlags &= ~PSH_HASHELP;
	m_pagectrlpage.m_psp.dwFlags &= ~PSP_HASHELP;
	m_commandLinkpage.m_psp.dwFlags &= ~PSP_HASHELP;
	m_splitButtonpage.m_psp.dwFlags &= ~PSP_HASHELP;
	m_netaddressctrlpage.m_psp.dwFlags &= ~PSP_HASHELP;

	AddPage(&m_pagectrlpage);
	AddPage(&m_commandLinkpage);
	AddPage(&m_splitButtonpage);
	AddPage(&m_netaddressctrlpage);
}

BEGIN_MESSAGE_MAP(CAllControlsSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CAllControlsSheet)
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllControlsSheet message handlers

BOOL CAllControlsSheet::OnInitDialog()
{
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	return CPropertySheet::OnInitDialog();
}
HCURSOR CAllControlsSheet::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CAllControlsSheet::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CAllControlsSheet::OnSysCommand(UINT nID, LPARAM lParam)
{
	CPropertySheet::OnSysCommand(nID, lParam);
}
