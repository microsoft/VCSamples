// CPropertyBagDlg.Cpp : implementation file
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

void AutoSetColumnWidth( CListCtrl& list, int iColumn )
{
   int nAutoWidth;
   int nAutoHeaderWidth;

   list.SetColumnWidth( iColumn, LVSCW_AUTOSIZE );
   nAutoWidth = list.GetColumnWidth( iColumn );
   list.SetColumnWidth( iColumn, LVSCW_AUTOSIZE_USEHEADER );
   nAutoHeaderWidth = list.GetColumnWidth( iColumn );
   list.SetColumnWidth( iColumn, max( nAutoWidth, nAutoHeaderWidth ) );
}

/////////////////////////////////////////////////////////////////////////////
// CPropertyBagDlg dialog


CPropertyBagDlg::CPropertyBagDlg( CPropertyBag* pPropertyBag, CWnd* pParent ) :
   CDialog( CPropertyBagDlg::IDD, pParent ),
   m_pPropertyBag( pPropertyBag )
{
   ASSERT( m_pPropertyBag != NULL );

	//{{AFX_DATA_INIT(CPropertyBagDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPropertyBagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertyBagDlg)
	DDX_Control(pDX, IDC_PROPERTIES, m_lvProperties);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertyBagDlg, CDialog)
	//{{AFX_MSG_MAP(CPropertyBagDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertyBagDlg message handlers

BOOL CPropertyBagDlg::OnInitDialog()
{
   POSITION posItem;
   CPropertyBagItem* pItem;
   int iItem;
   int iLVItem;
   COleVariant varString;
   CString strColumnTitle;
   CString str;

   CDialog::OnInitDialog();

   // Add the appropriate columns to the parameter list control.
   LOAD_STRING_FROM_RESOURCE(strColumnTitle, IDS_PROPERTY);
   m_lvProperties.InsertColumn( 0, strColumnTitle, LVCFMT_LEFT, 100 );
   LOAD_STRING_FROM_RESOURCE(strColumnTitle, IDS_VALUE);
   m_lvProperties.InsertColumn( 1, strColumnTitle, LVCFMT_LEFT, 100 );
   LOAD_STRING_FROM_RESOURCE(strColumnTitle, IDS_TYPE);
   m_lvProperties.InsertColumn( 2, strColumnTitle, LVCFMT_LEFT, 100 );

   iItem = 0;
   posItem = m_pPropertyBag->GetFirstItemPosition();
   while( posItem != NULL )
   {
	  pItem = m_pPropertyBag->GetNextItem( posItem );
	  iLVItem = m_lvProperties.InsertItem( iItem, pItem->m_strName );
	  m_lvProperties.SetItemText( iLVItem, 0, pItem->m_strName );

	  TRY
	  {
		 varString.ChangeType( VT_BSTR, pItem->m_varValue );
		 str = varString.bstrVal;
	  }
	  CATCH( COleException, e )
	  {
		LOAD_STRING_FROM_RESOURCE(str, IDS_UNABLETOREPRESENT);
	  }
	  END_CATCH

	  m_lvProperties.SetItemText( iLVItem, 1, str );
	  m_lvProperties.SetItemText( iLVItem, 2, VTToString(
		 pItem->m_varValue.vt ) );

	  iItem++;
   }

   AutoSetColumnWidth( m_lvProperties, 0 );
   AutoSetColumnWidth( m_lvProperties, 1 );
   AutoSetColumnWidth( m_lvProperties, 2 );

	return( TRUE );
}


static DWORD rgmapCHID[] =
{
   IDC_PROPERTIES, HIDC_PROPERTIES,
   0, 0
};

BOOL CPropertyBagDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CPropertyBagDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
