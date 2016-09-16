// EventLoggingPage.Cpp : implementation file
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
// CEventLoggingPage property page

IMPLEMENT_DYNCREATE(CEventLoggingPage, CPropertyPage)

CEventLoggingPage::CEventLoggingPage() :
   CPropertyPage( CEventLoggingPage::IDD )
{
   m_psp.dwFlags &= ~PSP_HASHELP;

	//{{AFX_DATA_INIT(CEventLoggingPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CEventLoggingPage::~CEventLoggingPage()
{
}

void CEventLoggingPage::DoDataExchange(CDataExchange* pDX)
{
   int iEvent;
   int iItem;

	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEventLoggingPage)
	DDX_Control(pDX, IDC_EVENTS, m_lbEvents);
	//}}AFX_DATA_MAP

   if( m_lbEvents.GetCount() > 0 )
   {
	  for( iEvent = 0; iEvent < m_astrEventNames.GetSize(); iEvent++ )
	  {
		 iItem = m_lbEvents.FindStringExact( -1, m_astrEventNames[iEvent] );
		 ASSERT( iItem != LB_ERR );
		 if( pDX->m_bSaveAndValidate )
		 {
			m_atLogFlags[iEvent] = m_lbEvents.GetCheck( iItem );
		 }
		 else
		 {

			m_lbEvents.SetCheck( iItem, m_atLogFlags[iEvent] != FALSE );
		 }
	  }
   }
}


BEGIN_MESSAGE_MAP(CEventLoggingPage, CPropertyPage)
	//{{AFX_MSG_MAP(CEventLoggingPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventLoggingPage message handlers

BOOL CEventLoggingPage::OnInitDialog()
{
   int iEvent;

	CPropertyPage::OnInitDialog();

   for( iEvent = 0; iEvent < m_astrEventNames.GetSize(); iEvent++ )
   {
	  m_lbEvents.AddString( m_astrEventNames[iEvent] );
   }

   UpdateData( FALSE );

	return( TRUE );
}

static DWORD rgmapCHID[] =
{
   IDC_EVENTS, HIDC_EVENTS,
   0, 0
};

BOOL CEventLoggingPage::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CEventLoggingPage::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
