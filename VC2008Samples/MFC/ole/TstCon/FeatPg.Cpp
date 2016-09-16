// CFeaturesPage.Cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "StdAfx.H"
#include "TestCon.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFeaturesPage property page

IMPLEMENT_DYNCREATE(CFeaturesPage, CPropertyPage)

CFeaturesPage::CFeaturesPage() : CPropertyPage(CFeaturesPage::IDD)
{
   m_psp.dwFlags &= ~PSP_HASHELP;

	//{{AFX_DATA_INIT(CFeaturesPage)
	m_tAllowWindowless = FALSE;
	m_tTwoPassDrawing = FALSE;
	m_tHonorIgnoreActivateWhenVisible = FALSE;
	m_tUseIPointerInactive = FALSE;
	m_tUseQuickActivation = FALSE;
	//}}AFX_DATA_INIT
}

CFeaturesPage::~CFeaturesPage()
{
}

void CFeaturesPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFeaturesPage)
	DDX_Check(pDX, IDC_ALLOWWINDOWLESS, m_tAllowWindowless);
	DDX_Check(pDX, IDC_TWOPASSDRAWING, m_tTwoPassDrawing);
	DDX_Check(pDX, IDC_IGNOREACTIVATEWHENVISIBLE, m_tHonorIgnoreActivateWhenVisible);
	DDX_Check(pDX, IDC_USEIPOINTERINACTIVE, m_tUseIPointerInactive);
	DDX_Check(pDX, IDC_USEQUICKACTIVATION, m_tUseQuickActivation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFeaturesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CFeaturesPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFeaturesPage message handlers

static DWORD rgmapCHID[] =
{
   IDC_ALLOWWINDOWLESS, HIDC_ALLOWWINDOWLESS,
   IDC_TWOPASSDRAWING, HIDC_TWOPASSDRAWING,
   IDC_IGNOREACTIVATEWHENVISIBLE, HIDC_IGNOREACTIVATEWHENVISIBLE,
   IDC_USEIPOINTERINACTIVE, HIDC_USEIPOINTERINACTIVE,
   IDC_USEQUICKACTIVATION, HIDC_USEQUICKACTIVATION,
   0, 0
};

BOOL CFeaturesPage::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CFeaturesPage::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
