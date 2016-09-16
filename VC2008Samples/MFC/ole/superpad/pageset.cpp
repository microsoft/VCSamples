// pageset.cpp : implementation of the CPadView class
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
#include "superpad.h"
#include <malloc.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageSetupDlg dialog

IMPLEMENT_DYNAMIC(CPageSetupDlg, CDialog)

CPageSetupDlg::CPageSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageSetupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageSetupDlg)
	m_iFooterTime = -1;
	m_iHeaderTime = -1;
	//}}AFX_DATA_INIT
}

void CPageSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageSetupDlg)
	DDX_Text(pDX, IDC_FOOTER, m_strFooter);
	DDX_Text(pDX, IDC_HEADER, m_strHeader);
	DDX_Radio(pDX, IDC_FOOTER_FILE, m_iFooterTime);
	DDX_Radio(pDX, IDC_HEADER_FILE, m_iHeaderTime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPageSetupDlg, CDialog)
	//{{AFX_MSG_MAP(CPageSetupDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageSetup member functions

static void Replace(CString& strModify, LPCTSTR pszWhat, LPCTSTR pszWith)
	// replace pszWhat with pwzWith in string strModify
{
	int i;
	if ((i = strModify.Find(pszWhat)) >= 0)
	{
		strModify = strModify.Left(i) + pszWith +
			strModify.Mid(i+lstrlen(pszWhat));
	}
}

void CPageSetupDlg::FormatFilePage(CString& strFormat,
	LPCTSTR pszFileName, UINT nPage)
{
	TCHAR sz[32];
	_stprintf_s(sz, 32, _T("%d"), nPage);
	::Replace(strFormat, _T("&p"), sz);
	if (pszFileName == NULL)
	{
		pszFileName = sz;
		sz[0] = 0;
	}
	::Replace(strFormat, _T("&f"), pszFileName);
}

void CPageSetupDlg::FormatHeader(CString& strHeader, CTime& time,
	LPCTSTR pszFileName, UINT nPage)
{
	CString strFormat = m_strHeader;
	FormatFilePage(strFormat, pszFileName, nPage);
#ifdef _UNICODE
	int nLen = strFormat.GetLength();
	char *pszFormat = (char*)_alloca(nLen+1);
	wcstombs(pszFormat, strFormat, nLen+1);
	strHeader = time.Format(pszFormat);
#else
	strHeader = time.Format(strFormat);
#endif
}

void CPageSetupDlg::FormatFooter(CString& strFooter, CTime& time,
	LPCTSTR pszFileName, UINT nPage)
{
	CString strFormat = m_strFooter;
	FormatFilePage(strFormat, pszFileName, nPage);
#ifdef _UNICODE
	int nLen = strFormat.GetLength();
	char *pszFormat = (char*)_alloca(nLen+1);
	wcstombs(pszFormat, strFormat, nLen+1);
	strFooter = time.Format(pszFormat);
#else
	strFooter = time.Format(strFormat);
#endif
}


static TCHAR BASED_CODE szPageSetup[] = _T("PageSetup");
static TCHAR BASED_CODE szHeader[] = _T("Header");
static TCHAR BASED_CODE szFooter[] = _T("Footer");
static TCHAR BASED_CODE szHeaderTime[] = _T("HeaderTime");
static TCHAR BASED_CODE szFooterTime[] = _T("FooterTime");

void CPageSetupDlg::Initialize()
{
	m_strHeader = AfxGetApp()->GetProfileString(szPageSetup, szHeader,
		_T("File: &f"));
	m_strFooter = AfxGetApp()->GetProfileString(szPageSetup, szFooter,
		_T("Page: &p"));
	m_iHeaderTime = AfxGetApp()->GetProfileInt(szPageSetup, szHeaderTime, 0);
	m_iFooterTime = AfxGetApp()->GetProfileInt(szPageSetup, szFooterTime, 0);
	m_strHeaderOld = m_strHeader;
	m_strFooterOld = m_strFooter;
	m_iHeaderTimeOld = m_iHeaderTime;
	m_iFooterTimeOld = m_iFooterTime;
}

void CPageSetupDlg::Terminate()
{
	if (m_strHeader != m_strHeaderOld)
		AfxGetApp()->WriteProfileString(szPageSetup, szHeader, m_strHeader);
	if (m_strFooter != m_strFooterOld)
		AfxGetApp()->WriteProfileString(szPageSetup, szFooter, m_strFooter);
	if (m_iHeaderTime != m_iHeaderTimeOld)
		AfxGetApp()->WriteProfileInt(szPageSetup, szHeaderTime, m_iHeaderTime);
	if (m_iFooterTime != m_iFooterTimeOld)
		AfxGetApp()->WriteProfileInt(szPageSetup, szFooterTime, m_iFooterTime);
}

/////////////////////////////////////////////////////////////////////////////
// CPageSetupDlg message handlers
