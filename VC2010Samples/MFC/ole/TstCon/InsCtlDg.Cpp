// InsertControlDlg.Cpp : implementation file
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
// CInsertControlDlg dialog


CInsertControlDlg::CInsertControlDlg( CWnd* pParent ) :
   CDialog( CInsertControlDlg::IDD, pParent ),
   m_clsid( CLSID_NULL )
{
	//{{AFX_DATA_INIT(CInsertControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInsertControlDlg::DoDataExchange(CDataExchange* pDX)
{
   int iItem;
   POSITION posControl;

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInsertControlDlg)
	DDX_Control(pDX, IDC_SERVERPATH, m_staticServerPath);
	DDX_Control(pDX, IDC_REQUIREDCATEGORIES, m_butRequiredCategories);
	DDX_Control(pDX, IDC_IGNOREREQUIREDCATEGORIES, m_butIgnoreRequiredCategories);
	DDX_Control(pDX, IDOK, m_butOK);
	DDX_Control(pDX, IDC_CONTROLS, m_lbControls);
	//}}AFX_DATA_MAP

   if( pDX->m_bSaveAndValidate )
   {
	  iItem = m_lbControls.GetCurSel();
	  if( iItem == LB_ERR )
	  {
		 m_clsid = CLSID_NULL;
	  }
	  else
	  {
		 posControl = POSITION( m_lbControls.GetItemDataPtr( iItem ) );
		 ASSERT( posControl != NULL );
		 m_clsid = m_lControls.GetAt( posControl );
	  }
   }
}


BEGIN_MESSAGE_MAP(CInsertControlDlg, CDialog)
	//{{AFX_MSG_MAP(CInsertControlDlg)
	ON_BN_CLICKED(IDC_IMPLEMENTEDCATEGORIES, OnImplementedCategories)
	ON_LBN_DBLCLK(IDC_CONTROLS, OnControlsDblClk)
	ON_BN_CLICKED(IDC_REQUIREDCATEGORIES, OnRequiredCategories)
	ON_LBN_SELCHANGE(IDC_CONTROLS, OnControlsSelChange)
	ON_BN_CLICKED(IDC_IGNOREREQUIREDCATEGORIES, OnIgnoreRequiredCategories)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsertControlDlg message handlers

BOOL CInsertControlDlg::OnInitDialog()
{
   HRESULT hResult;
   CATID catid;

   hResult = m_pCatInfo.CreateInstance( CLSID_StdComponentCategoriesMgr, NULL,
	  CLSCTX_INPROC_SERVER );
   if( FAILED( hResult ) )
   {
	  TRACE( "Failed to create category manager\n" );
	  EndDialog( IDCANCEL );
	  return( TRUE );
   }

	CDialog::OnInitDialog();

   catid = CATID_Control;
   m_aImplementedCategories.Add( catid );

   m_butIgnoreRequiredCategories.SetCheck( 0 );

   m_lbControls.ModifyStyle( 0, WS_HSCROLL );

   RefreshControlList();

   m_lbControls.SetFocus();

	return( FALSE );
}

void GetClassServerPath( REFCLSID clsid, CString& strServerPath )
{
   HKEY hKey;
   HKEY hServerKey;
   OLECHAR szCLSID[64];
   LONG nResult;
   ULONG nBytes;
   DWORD dwType;
   LPTSTR pszServerPath;

   StringFromGUID2( clsid, szCLSID, 64 );

   hKey = NULL;
   hServerKey = NULL;
   try
   {
	  nResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, CString( "CLSID\\" )+CString(
		 szCLSID ), 0, KEY_READ, &hKey );
	  if( nResult != ERROR_SUCCESS )
	  {
		 throw( E_FAIL );
	  }

	  nResult = RegOpenKeyEx( hKey, _T( "InprocServer32" ), 0, KEY_READ,
		 &hServerKey );
	  if( nResult != ERROR_SUCCESS )
	  {
		 nResult = RegOpenKeyEx( hKey, _T( "InprocHandler32" ), 0, KEY_READ,
			&hServerKey );
		 if( nResult != ERROR_SUCCESS )
		 {
			nResult = RegOpenKeyEx( hKey, _T( "LocalServer32" ), 0, KEY_READ,
			   &hServerKey );
			if( nResult != ERROR_SUCCESS )
			{
			   throw( E_FAIL );
			}
		 }
	  }

	  nBytes = 0;
	  nResult = RegQueryValueEx( hServerKey, NULL, NULL, &dwType, NULL,
		 &nBytes );
	  if( (nResult != ERROR_SUCCESS) || (dwType != REG_SZ) )
	  {
		 throw( E_FAIL );
	  }
	  pszServerPath = LPTSTR( _alloca( nBytes ) );
	  nResult = RegQueryValueEx( hServerKey, NULL, NULL, &dwType,
		 LPBYTE( pszServerPath ), &nBytes );
	  if( (nResult != ERROR_SUCCESS) || (dwType != REG_SZ) )
	  {
		 throw( E_FAIL );
	  }

	  strServerPath = pszServerPath;

	  RegCloseKey( hKey );
	  hKey = NULL;
	  RegCloseKey( hServerKey );
	  hServerKey = NULL;
   }
   catch( HRESULT )
   {
	  if( hKey != NULL )
	  {
		 RegCloseKey( hKey );
	  }
	  if( hServerKey != NULL )
	  {
		 RegCloseKey( hServerKey );
	  }

	  LOAD_STRING_FROM_RESOURCE( strServerPath, IDS_SERVERNOTFOUND );

	  return;
   }
}

void CInsertControlDlg::RefreshControlList()
{
   BOOL tDone;
   HRESULT hResult;
   IEnumGUIDPtr pEnum;
   ULONG nImplementedCategories;
   CATID* pcatidImpl;
   ULONG nRequiredCategories;
   CATID* pcatidReq;
   CLSID clsid;
   LPOLESTR pszName;
   CString strName;
   ULONG iCategory;
   int iItem;
   POSITION posControl;
   CString strServerPath;
   CString strString;

   m_lbControls.ResetContent();
   m_lControls.RemoveAll();

   nImplementedCategories = (ULONG)m_aImplementedCategories.GetSize();
   if( nImplementedCategories == 0 )
   {
	  nImplementedCategories = ULONG( -1 );
	  pcatidImpl = NULL;
   }
   else
   {
	  pcatidImpl = (CATID*)_malloca( nImplementedCategories*sizeof( CATID ) );
	  for( iCategory = 0; iCategory < nImplementedCategories; iCategory++ )
	  {
		 pcatidImpl[iCategory] = m_aImplementedCategories[iCategory];
	  }
   }

   if( m_butIgnoreRequiredCategories.GetCheck() )
   {
	  nRequiredCategories = ULONG( -1 );
	  pcatidReq = NULL;
   }
   else
   {
	  nRequiredCategories = (ULONG)m_aRequiredCategories.GetSize();
	  if( nRequiredCategories == 0 )
	  {
		 pcatidReq = NULL;
	  }
	  else
	  {
		 pcatidReq = (CATID*)_malloca( nRequiredCategories*sizeof( CATID ) );
		 for( iCategory = 0; iCategory < nRequiredCategories; iCategory++ )
		 {
			pcatidReq[iCategory] = m_aRequiredCategories[iCategory];
		 }
	  }
   }

   hResult = m_pCatInfo->EnumClassesOfCategories( nImplementedCategories,
	  pcatidImpl, nRequiredCategories, pcatidReq, &pEnum );


   _freea(pcatidImpl);
   _freea(pcatidReq);

   
   if( FAILED( hResult ) )
   {
	  return;
   }

   tDone = FALSE;

   int nExtent = 0;
   TEXTMETRIC tm;
   ::ZeroMemory(&tm, sizeof(TEXTMETRIC));
   CFont *pFont = NULL;
   CFont *pOldFont = NULL;
   CDC *pDC = m_lbControls.GetDC();
   ASSERT(pDC);
   if (pDC)
   {
	   pFont = m_lbControls.GetFont();
	   ASSERT(pFont);
       if (pFont)
	   {
		   pOldFont = pDC->SelectObject(pFont);
		   VERIFY(pDC->GetTextMetrics(&tm));
	   }
   }

   while( !tDone )
   {
	  hResult = pEnum->Next( 1, &clsid, NULL );
	  if( hResult == S_OK )
	  {
		 pszName = NULL;
		 hResult = OleRegGetUserType( clsid, USERCLASSTYPE_FULL, &pszName );
		 if( SUCCEEDED( hResult ) )
		 {
			strName = pszName;
			CoTaskMemFree( pszName );
			pszName = NULL;
			if (pDC && pFont)
			{
				CSize sz = pDC->GetTextExtent(strName);
				if (sz.cx > nExtent)
					nExtent = sz.cx;
			}
			iItem = m_lbControls.AddString( strName );
			posControl = m_lControls.AddTail( clsid );
			m_lbControls.SetItemDataPtr( iItem, posControl );
		 }
	  }
	  else
	  {
		 tDone = TRUE;
	  }
   }
   if (pDC && pFont)
   {
	   pDC->SelectObject(pOldFont);
	   m_lbControls.SetHorizontalExtent(nExtent + tm.tmAveCharWidth);
   }

   OnControlsSelChange();
}

void CInsertControlDlg::OnImplementedCategories()
{
   CComponentCategoriesDlg dlg( IDS_IMPLEMENTEDCATEGORIES );
   int nResult;
   int iCategory;
   POSITION posCategory;
   CATID catid;

   for( iCategory = 0; iCategory < m_aImplementedCategories.GetSize();
	  iCategory++ )
   {
	  dlg.m_lSelectedCategories.AddTail( m_aImplementedCategories[
		 iCategory] );
   }

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   m_aImplementedCategories.RemoveAll();
   posCategory = dlg.m_lSelectedCategories.GetHeadPosition();
   while( posCategory != NULL )
   {
	  catid = dlg.m_lSelectedCategories.GetNext( posCategory );
	  m_aImplementedCategories.Add( catid );
   }

   RefreshControlList();
}

void CInsertControlDlg::OnControlsDblClk()
{
   OnOK();
}

void CInsertControlDlg::OnRequiredCategories()
{
   CComponentCategoriesDlg dlg( IDS_REQUIREDCATEGORIES );
   int nResult;
   int iCategory;
   POSITION posCategory;
   CATID catid;

   for( iCategory = 0; iCategory < m_aRequiredCategories.GetSize();
	  iCategory++ )
   {
	  dlg.m_lSelectedCategories.AddTail( m_aRequiredCategories[iCategory] );
   }

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   m_aRequiredCategories.RemoveAll();
   posCategory = dlg.m_lSelectedCategories.GetHeadPosition();
   while( posCategory != NULL )
   {
	  catid = dlg.m_lSelectedCategories.GetNext( posCategory );
	  m_aRequiredCategories.Add( catid );
   }

   RefreshControlList();
}

void CInsertControlDlg::OnControlsSelChange()
{
   int iItem;
   POSITION posControl;
   CString strServerPath;
   CLSID clsid;
   CDC dc;
   CFont* pFont;
   LPTSTR pszServerPath;
   CRect rect;
   CFont* pOldFont;

   iItem = m_lbControls.GetCurSel();
   if( iItem != LB_ERR )
   {
	  m_butOK.EnableWindow( TRUE );
	  posControl = POSITION( m_lbControls.GetItemDataPtr( iItem ) );
	  clsid = m_lControls.GetAt( posControl );
	  GetClassServerPath( clsid, strServerPath );

	  dc.CreateCompatibleDC( NULL );

	  pFont = m_staticServerPath.GetFont();
	  pOldFont = dc.SelectObject( pFont );

	  // Workaround for SHLWAPI bug (in weird cases, PathCompactPath actually
	  // expands the pathname)
	  pszServerPath = strServerPath.GetBuffer( MAX_PATH+2 );
	  m_staticServerPath.GetWindowRect( &rect );
	  PathCompactPath( dc, pszServerPath, rect.Width() );
	  strServerPath.ReleaseBuffer();

	  dc.SelectObject( pOldFont );

	  m_staticServerPath.SetWindowText( strServerPath );
   }
   else
   {
	  m_butOK.EnableWindow( FALSE );
	  m_staticServerPath.SetWindowText( NULL );
   }
}

void CInsertControlDlg::OnIgnoreRequiredCategories()
{
   RefreshControlList();

   if( m_butIgnoreRequiredCategories.GetCheck() )
   {
	  m_butRequiredCategories.EnableWindow( FALSE );
   }
   else
   {
	  m_butRequiredCategories.EnableWindow( TRUE );
   }
}

static DWORD rgmapCHID[] =
{
   IDC_CONTROLS, HIDC_CONTROLS,
   IDC_IMPLEMENTEDCATEGORIES, HIDC_IMPLEMENTEDCATEGORIES,
   IDC_REQUIREDCATEGORIES, HIDC_REQUIREDCATEGORIES,
   IDC_IGNOREREQUIREDCATEGORIES, HIDC_IGNOREREQUIREDCATEGORIES,
   0, 0
};

BOOL CInsertControlDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CInsertControlDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
