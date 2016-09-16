// CAmbientPropertiesDlg.Cpp : implementation file
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
// CAmbientPropertiesDlg dialog


CAmbientPropertiesDlg::CAmbientPropertiesDlg( CWnd* pParent,
   CTestContainer98Doc* pDoc ) :
   CDialog( CAmbientPropertiesDlg::IDD, pParent ),
   m_pDoc( pDoc ),
   m_tChanged( FALSE ),
   m_dispidChanged( DISPID_UNKNOWN )
{
   ASSERT( m_pDoc != NULL );
	//{{AFX_DATA_INIT(CAmbientPropertiesDlg)
	//}}AFX_DATA_INIT
}


void CAmbientPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAmbientPropertiesDlg)
	DDX_Control(pDX, IDC_PROPVALUECOMBO_AMBIENT, m_cboxPropValue);
	DDX_Control(pDX, IDC_DATE_AMBIENT, m_date);
	DDX_Control(pDX, IDC_STATIC_PROPERTYVALUE, m_staticPropertyValue);
	DDX_Control(pDX, IDC_DISPID, m_editDISPID);
	DDX_Control(pDX, IDC_CHOOSEFONT_AMBIENT, m_butChooseFont);
	DDX_Control(pDX, IDC_CHOOSECOLOR_AMBIENT, m_butChooseColor);
	DDX_Control(pDX, IDC_PROPNAME, m_cboxPropName);
	DDX_Control(pDX, IDC_SETVALUE_AMBIENT, m_butSetValue);
	DDX_Control(pDX, IDC_PROPVALUE, m_editPropValue);
	DDX_Control(pDX, IDC_PROPTYPE, m_cboxPropType);
	DDX_Control(pDX, IDC_ENABLED, m_checkEnabled);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAmbientPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CAmbientPropertiesDlg)
	ON_CBN_SELCHANGE(IDC_PROPNAME, OnPropNameSelChange)
	ON_CBN_SELCHANGE(IDC_PROPTYPE, OnPropTypeSelChange)
	ON_BN_CLICKED(IDC_SETVALUE_AMBIENT, OnSetValue)
	ON_BN_CLICKED(IDC_ENABLED, OnEnabled)
	ON_BN_CLICKED(IDC_CHOOSECOLOR_AMBIENT, OnChooseColor)
	ON_BN_CLICKED(IDC_CHOOSEFONT_AMBIENT, OnChooseFont)
	ON_BN_CLICKED(IDC_NEWPROPERTY, OnNewProperty)
	ON_EN_SETFOCUS(IDC_PROPVALUE, OnPropValueSetFocus)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAmbientPropertiesDlg message handlers

BOOL CAmbientPropertiesDlg::OnInitDialog()
{
   int iProp;
   int iType;
   int iItem;

	CDialog::OnInitDialog();

   // Fill in the available ambient properties
   for( iProp = 0; iProp < m_pDoc->GetNumAmbientProperties(); iProp++ )
   {
	  iItem = m_cboxPropName.AddString( m_pDoc->GetAmbientProperty(
		 iProp )->GetName() );
	  m_cboxPropName.SetItemData( iItem, iProp );
   }

   for( iType = 0; iType < NUM_VARTYPES; iType++ )
   {
	  iItem = m_cboxPropType.AddString( VTIToString( iType ) );
	  m_cboxPropType.SetItemData( iItem, iType );
   }

   m_cboxPropName.SetCurSel( 0 );
   OnPropNameSelChange();

   return( TRUE );  // return TRUE unless you set the focus to a control
}

void CAmbientPropertiesDlg::OnPropNameSelChange()
{

   int iProp;
   int iItem;
   CString strDisplay;

   iItem = m_cboxPropName.GetCurSel();
   ASSERT( iItem != CB_ERR );
   iProp = (int)m_cboxPropName.GetItemData( iItem );

   m_pProp = m_pDoc->GetAmbientProperty( iProp );

   strDisplay.Format( _T( "%d" ), m_pProp->GetID() );
   m_editDISPID.SetWindowText( strDisplay );
   m_editDISPID.SetReadOnly( m_pProp->IsStock() );

//   m_cboxPropType.SetCurSel( m_pProp->GetVTI() );
   m_cboxPropType.SelectString( -1, VTIToString( m_pProp->GetVTI() ) );
   OnPropTypeSelChange();
   TRY
   {
      if( m_pProp->GetVTI() == VTI_DATE )
      {
         m_date.SetTime( COleDateTime( m_pProp->GetValue() ) );
      }
      else if( m_pProp->GetVTI() == VTI_BOOL )
      {
         m_cboxPropValue.SetCurSel( m_pProp->GetValue().boolVal ? 1 : 0 );
      }
      else
      {
	     strDisplay = VariantToString( m_pProp->GetValue() );
	     m_editPropValue.SetWindowText( strDisplay );
      }
   }
   CATCH( COleException, e )
   {
	  TRACE( "ChangeType() failed.\n" );
   }
   END_CATCH

   if( m_pProp->IsEnabled() )
   {
	  m_checkEnabled.SetCheck( 1 );
     m_date.EnableWindow( TRUE );
     m_cboxPropValue.EnableWindow( TRUE );
	  m_cboxPropType.EnableWindow( TRUE );
	  m_editPropValue.EnableWindow( TRUE );
	  m_butSetValue.EnableWindow( TRUE );
	  m_butChooseColor.EnableWindow( TRUE );
	  m_butChooseFont.EnableWindow( TRUE );
   }
   else
   {
	  m_checkEnabled.SetCheck( 0 );
     m_cboxPropValue.EnableWindow( FALSE );
     m_date.EnableWindow( FALSE );
	  m_cboxPropType.EnableWindow( FALSE );
	  m_editPropValue.EnableWindow( FALSE );
	  m_butSetValue.EnableWindow( FALSE );
	  m_butChooseColor.EnableWindow( FALSE );
	  m_butChooseFont.EnableWindow( FALSE );
   }
}

void CAmbientPropertiesDlg::OnPropTypeSelChange()
{
   int iType;
   int iItem;

   iItem = m_cboxPropType.GetCurSel();
   ASSERT( iItem != CB_ERR );
   iType = (int)m_cboxPropType.GetItemData( iItem );

   switch( iType )
   {
   case VTI_BOOL:
      m_butChooseColor.ShowWindow( SW_HIDE );
      m_editPropValue.ShowWindow( SW_HIDE );
      m_butChooseFont.ShowWindow( SW_HIDE );
      m_date.ShowWindow( SW_HIDE );
      m_butSetValue.ShowWindow( SW_NORMAL );
      m_staticPropertyValue.ShowWindow( SW_NORMAL );
      m_cboxPropValue.ShowWindow( SW_NORMAL );
      DisplayPropValues( iType );
		m_cboxPropValue.SetCurSel( 0 );
      break;

   case VTI_FONT:
      m_cboxPropValue.ShowWindow( SW_HIDE );
	  m_butChooseColor.ShowWindow( SW_HIDE );
	  m_staticPropertyValue.ShowWindow( SW_HIDE );
	  m_editPropValue.ShowWindow( SW_HIDE );
	  m_butSetValue.ShowWindow( SW_HIDE );
     m_date.ShowWindow( SW_HIDE );
	  m_butChooseFont.ShowWindow( SW_NORMAL );
	  break;

   case VTI_COLOR:
      m_cboxPropValue.ShowWindow( SW_HIDE );
	  m_butChooseFont.ShowWindow( SW_HIDE );
	  m_staticPropertyValue.ShowWindow( SW_HIDE );
	  m_editPropValue.ShowWindow( SW_HIDE );
	  m_butSetValue.ShowWindow( SW_HIDE );
	  m_butChooseColor.ShowWindow( SW_NORMAL );
     m_date.ShowWindow( SW_HIDE );
	  break;

   case VTI_DATE:
      m_cboxPropValue.ShowWindow( SW_HIDE );
	  m_butChooseFont.ShowWindow( SW_HIDE );
	  m_staticPropertyValue.ShowWindow( SW_NORMAL );
	  m_editPropValue.ShowWindow( SW_HIDE );
	  m_butSetValue.ShowWindow( SW_NORMAL );
	  m_butChooseColor.ShowWindow( SW_HIDE );
     m_date.ShowWindow( SW_NORMAL );
      break;

   default:
      m_cboxPropValue.ShowWindow( SW_HIDE );
	  m_butChooseColor.ShowWindow( SW_HIDE );
	  m_butChooseFont.ShowWindow( SW_HIDE );
	  m_staticPropertyValue.ShowWindow( SW_NORMAL );
	  m_editPropValue.ShowWindow( SW_NORMAL );
	  m_butSetValue.ShowWindow( SW_NORMAL );
     m_date.ShowWindow( SW_HIDE );
	  break;
   }
}

void CAmbientPropertiesDlg::DisplayPropValues( int iType )
{
   CString strValue;

   m_cboxPropValue.ResetContent();
   switch( iType )
   {
   case VTI_BOOL:
      LOAD_STRING_FROM_RESOURCE( strValue, IDS_FALSE );
      m_cboxPropValue.AddString( strValue );
      LOAD_STRING_FROM_RESOURCE( strValue, IDS_TRUE );
      m_cboxPropValue.AddString( strValue );
      break;

   default:
      ASSERT( FALSE );
      break;
   }
}

void CAmbientPropertiesDlg::OnSetValue()
{
   COleVariant varValue;
   CString strValue;
   int iType;
   int iItem;
   COleDateTime date;

   iItem = m_cboxPropType.GetCurSel();
   ASSERT( iItem != CB_ERR );
   iType = (int)m_cboxPropType.GetItemData( iItem );
   if( iType == VTI_DATE )
   {
      m_date.GetTime( date );
      varValue = date;
   }
   else if( iType == VTI_BOOL )
   {
      varValue = COleVariant( VARIANT_BOOL( (m_cboxPropValue.GetCurSel() == 
         1) ? ~VARIANT_FALSE : VARIANT_FALSE ), VT_BOOL );
   }
   else
   {
      m_editPropValue.GetWindowText( strValue );
      varValue = strValue;
   }

   TRY
   {
	  varValue.ChangeType( VTIToVT( iType ) );
	  m_pProp->SetValue( varValue, iType );
	  OnPropertyChanged( m_pProp->GetID() );
   }
   CATCH( COleException, e )
   {
	  TRACE( "ChangeType() failed.\n" );
   }
   END_CATCH

   m_editPropValue.SetFocus();
   m_editPropValue.SetSel( 0, -1 );
}

void CAmbientPropertiesDlg::OnEnabled()
{
   if( m_checkEnabled.GetCheck() )
   {
	  m_pProp->Enable( TRUE );
	  OnPropNameSelChange();
   }
   else
   {
	  m_pProp->Enable( FALSE );
	  OnPropNameSelChange();
   }
}

BOOL CAmbientPropertiesDlg::GetChangedPropertyID( DISPID* pdispid ) const
{
   if( m_tChanged )
   {
	  *pdispid = m_dispidChanged;
   }
   else
   {
	  *pdispid = DISPID_UNKNOWN;
   }

   return( m_tChanged );
}

void CAmbientPropertiesDlg::OnChooseColor()
{
   int nResult;
   COleVariant varColor;

   varColor = m_pProp->GetValue();
   try
   {
	  varColor.ChangeType( VT_COLOR );
   }
   catch( CException* pException )
   {
	  varColor = COleVariant( long( 0 ), VT_COLOR );

	 pException->Delete();
   }

   ASSERT( varColor.vt == VT_COLOR );

   CColorDialog dlg( varColor.lVal );

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   varColor = COleVariant( long( dlg.GetColor() ), VT_COLOR );
   m_pProp->SetValue( varColor );
   OnPropertyChanged( m_pProp->GetID() );
}

void CAmbientPropertiesDlg::OnChooseFont()
{

   int nResult;
   IFontDispPtr pFontDisp;
   IFontPtr pFont;
   FONTDESC desc;
   HRESULT hResult;
   COleVariant varFont;
   CFont font;
   HFONT hFont;
   LOGFONT logfont;
   LOGFONT* pLogFont;
   BOOL tSuccess;

   hFont = NULL;
   varFont = m_pProp->GetValue();
   if( varFont.vt == VT_FONT )
   {
	  pFont = varFont.pdispVal;
	  if( pFont != NULL )
	  {
		 hResult = pFont->get_hFont( &hFont );
		 if( FAILED( hResult ) )
		 {
			hFont = NULL;
		 }
		 pFont.Release();
	  }
   }

   if( hFont != NULL )
   {
	  font.Attach( hFont );
	  tSuccess = font.GetLogFont( &logfont );
	  font.Detach();
	  if( !tSuccess )
	  {
		 hFont = NULL;
	  }
   }

   if( hFont != NULL )
   {
	  pLogFont = &logfont;
   }
   else
   {
	  pLogFont = NULL;
   }

   CFontDialog dlg( pLogFont );

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   memset( &desc, 0, sizeof( desc ) );
   desc.cbSizeofstruct = sizeof( desc );
   CT2OLE tName(dlg.m_cf.lpLogFont->lfFaceName);
   desc.lpstrName = tName;
   desc.cySize = COleCurrency( dlg.m_cf.iPointSize/10, 1000*
	  (dlg.m_cf.iPointSize%10) );
   desc.sWeight = short( dlg.m_cf.lpLogFont->lfWeight );
   desc.sCharset = dlg.m_cf.lpLogFont->lfCharSet;
   desc.fItalic = dlg.m_cf.lpLogFont->lfItalic;
   desc.fUnderline = dlg.m_cf.lpLogFont->lfUnderline;
   desc.fStrikethrough = dlg.m_cf.lpLogFont->lfStrikeOut;

   hResult = OleCreateFontIndirect( &desc, IID_IFontDisp, (void**)&pFontDisp );
   if( FAILED( hResult ) )
   {
	  TRACE( "OleCreateFontIndirect() failed\n" );
	  return;
   }

   varFont.vt = VT_DISPATCH;
   varFont.pdispVal = pFontDisp;
   varFont.pdispVal->AddRef();
   m_pProp->SetValue( varFont );
   OnPropertyChanged( m_pProp->GetID() );
}

void CAmbientPropertiesDlg::OnPropertyChanged( DISPID dispid )
{
   if( m_tChanged == FALSE )
   {
	  // This is the first property we changed.
	  m_tChanged = TRUE;
	  m_dispidChanged = dispid;
   }
   else
   {
	  if( m_dispidChanged != dispid )
	  {
		 // We've already changed a different property, so we'll have to do
		 // a bulk notify.
		 m_dispidChanged = DISPID_UNKNOWN;
	  }
   }
}

void CAmbientPropertiesDlg::OnNewProperty()
{
   COleVariant var;
   int iProp;
   int iItem;
   CNewAmbientPropertyDlg dlg;
   int nResult;

   LOAD_STRING_FROM_RESOURCE( dlg.m_strName, IDS_NEWPROPERTY );
   dlg.m_dispid = DISPID_UNKNOWN;

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   var = COleVariant( VARIANT_FALSE, VT_BOOL );
   try
   {
	  iProp = m_pDoc->AddAmbientProperty( dlg.m_dispid, dlg.m_strName, var,
		 VTI_BOOL );
	  iItem = m_cboxPropName.AddString( dlg.m_strName );
	  m_cboxPropName.SetItemData( iItem, iProp );
	  m_cboxPropName.SetCurSel( iItem );
	  OnPropertyChanged( dlg.m_dispid );
	  OnPropNameSelChange();
   }
   catch( ... )
   {
	  TRACE( "Failed to add ambient property\n" );
   }
}

void CAmbientPropertiesDlg::OnPropValueSetFocus()
{
   // The ParamValue edit box just got the keyboard focus.  The user should be
   // able to set the value to the contents of the edit box just by hitting
   // ENTER.
   SetDefID( IDC_SETVALUE_AMBIENT );
}

static DWORD rgmapCHID[] =
{
   IDC_PROPNAME, HIDC_PROPNAME,
   IDC_DISPID, HIDC_DISPID,
   IDC_ENABLED, HIDC_ENABLED,
   IDC_CHOOSECOLOR_AMBIENT, HIDC_CHOOSECOLOR_AMBIENT,
   IDC_CHOOSEFONT_AMBIENT, HIDC_CHOOSEFONT_AMBIENT,
   IDC_PROPTYPE, HIDC_PROPTYPE,
   IDC_SETVALUE_AMBIENT, HIDC_SETVALUE_AMBIENT,
   IDC_PROPVALUE, HIDC_PROPVALUE,
   IDC_NEWPROPERTY, HIDC_NEWPROPERTY,
   IDC_DATE_AMBIENT, HIDC_DATE_AMBIENT,
   IDC_PROPVALUECOMBO_AMBIENT, HIDC_PROPVALUECOMBO_AMBIENT,
   IDC_STATIC_PROPERTYVALUE, DWORD( -1 ),
   0, 0
};

BOOL CAmbientPropertiesDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CAmbientPropertiesDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
