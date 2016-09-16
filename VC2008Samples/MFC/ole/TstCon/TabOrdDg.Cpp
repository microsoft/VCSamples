// TabOrderDlg.Cpp : implementation file
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
// CTabOrderDlg dialog


CTabOrderDlg::CTabOrderDlg( CWnd* pParent ) :
   CDialog( CTabOrderDlg::IDD, pParent )
{
	//{{AFX_DATA_INIT(CTabOrderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CTabOrderDlg::DoDataExchange( CDataExchange* pDX )
{
   int nItems;
   int iItem;
   CTestContainer98Item* pItem;
   CString strItemName;
   POSITION posItem;

	CDialog::DoDataExchange( pDX );
	//{{AFX_DATA_MAP(CTabOrderDlg)
	DDX_Control(pDX, IDC_TABORDER, m_lboxTabOrder);
	//}}AFX_DATA_MAP

   if( pDX->m_bSaveAndValidate )
   {
	  m_lpTabOrder.RemoveAll();
	  nItems = m_lboxTabOrder.GetCount();
	  for( iItem = 0; iItem < nItems; iItem++ )
	  {
		 pItem = (CTestContainer98Item*)m_lboxTabOrder.GetItemDataPtr( iItem );
		 ASSERT( pItem != NULL );
		 m_lpTabOrder.AddTail( pItem );
	  }
   }
   else
   {
	  m_lboxTabOrder.ResetContent();
	  posItem = m_lpTabOrder.GetHeadPosition();
	  while( posItem != NULL )
	  {
		 pItem = m_lpTabOrder.GetNext( posItem );
		 ENSURE( pItem != NULL );
		 strItemName = pItem->GetDisplayName();
		 iItem = m_lboxTabOrder.AddString( strItemName );
		 m_lboxTabOrder.SetItemDataPtr( iItem, pItem );
	  }
   }
}


BEGIN_MESSAGE_MAP( CTabOrderDlg, CDialog )
	//{{AFX_MSG_MAP(CTabOrderDlg)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabOrderDlg message handlers

BOOL CTabOrderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

   return( TRUE );
}


static DWORD rgmapCHID[] =
{
   IDC_TABORDER, HIDC_TABORDER,
   0, 0
};

BOOL CTabOrderDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CTabOrderDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
