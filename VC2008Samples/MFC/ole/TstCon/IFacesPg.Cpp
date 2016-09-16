// CInterfacesPage.Cpp : implementation file
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
// CInterfacesPage property page

IMPLEMENT_DYNCREATE(CInterfacesPage, CPropertyPage)

CInterfacesPage::CInterfacesPage() : CPropertyPage(CInterfacesPage::IDD)
{
   m_psp.dwFlags &= ~PSP_HASHELP;

	//{{AFX_DATA_INIT(CInterfacesPage)
	m_tIOleInPlaceSiteWindowless = FALSE;
	m_tIOleInPlaceSiteEx = FALSE;
	m_tIAdviseSinkEx = FALSE;
	//}}AFX_DATA_INIT
}

CInterfacesPage::~CInterfacesPage()
{
}

void CInterfacesPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInterfacesPage)
	DDX_Check(pDX, IDC_IOLEINPLACESITEWINDOWLESS, m_tIOleInPlaceSiteWindowless);
	DDX_Check(pDX, IDC_IOLEINPLACESITEEX, m_tIOleInPlaceSiteEx);
	DDX_Check(pDX, IDC_IADVISESINKEX, m_tIAdviseSinkEx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInterfacesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CInterfacesPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterfacesPage message handlers


static DWORD rgmapCHID[] =
{
   IDC_IOLEINPLACESITEEX, HIDC_IOLEINPLACESITEEX,
   IDC_IOLEINPLACESITEWINDOWLESS, HIDC_IOLEINPLACESITEWINDOWLESS,
   IDC_IADVISESINKEX, HIDC_IADVISESINKEX,
   0, 0
};

BOOL CInterfacesPage::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CInterfacesPage::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
