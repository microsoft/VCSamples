// PropertyChangesPage.Cpp : implementation file
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
// CPropertyChangesPage property page

IMPLEMENT_DYNCREATE(CPropertyChangesPage, CPropertyPage)

CPropertyChangesPage::CPropertyChangesPage() :
   CPropertyPage( CPropertyChangesPage::IDD )
{
   m_psp.dwFlags &= ~PSP_HASHELP;

	//{{AFX_DATA_INIT(CPropertyChangesPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPropertyChangesPage::~CPropertyChangesPage()
{
}

void CPropertyChangesPage::DoDataExchange( CDataExchange* pDX )
{
   int iProperty;
   int iItem;

	CPropertyPage::DoDataExchange( pDX );
	//{{AFX_DATA_MAP(CPropertyChangesPage)
	DDX_Control(pDX, IDC_PROPERTIES_CHANGES, m_lbProperties);
	//}}AFX_DATA_MAP

   if( m_lbProperties.GetCount() > 0 )
   {
	  for( iProperty = 0; iProperty < m_astrPropertyNames.GetSize();
		 iProperty++ )
	  {
		 iItem = m_lbProperties.FindStringExact( -1, m_astrPropertyNames[
			iProperty] );
		 ASSERT( iItem != LB_ERR );
		 if( pDX->m_bSaveAndValidate )
		 {
			m_atLogFlags[iProperty] = m_lbProperties.GetCheck( iItem );
		 }
		 else
		 {
			m_lbProperties.SetCheck( iItem, m_atLogFlags[iProperty] != FALSE );
		 }
	  }
   }
}


BEGIN_MESSAGE_MAP(CPropertyChangesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPropertyChangesPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyChangesPage message handlers

BOOL CPropertyChangesPage::OnInitDialog()
{
   int iProperty;

	CPropertyPage::OnInitDialog();

   for( iProperty = 0; iProperty < m_astrPropertyNames.GetSize(); iProperty++ )
   {
	  m_lbProperties.AddString( m_astrPropertyNames[iProperty] );
   }

   UpdateData( FALSE );

	return( TRUE );
}


static DWORD rgmapCHID[] =
{
   IDC_PROPERTIES_CHANGES, HIDC_PROPERTIES_CHANGES,
   0, 0
};

BOOL CPropertyChangesPage::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CPropertyChangesPage::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
