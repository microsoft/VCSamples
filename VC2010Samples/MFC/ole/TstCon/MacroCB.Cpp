// MacroComboBox.Cpp : implementation file
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

const int MACROCOMBOBOX_MRUSIZE = 8;

/////////////////////////////////////////////////////////////////////////////
// CMacroComboBox

CMacroComboBox::CMacroComboBox()
{
}

CMacroComboBox::~CMacroComboBox()
{
}

void CMacroComboBox::AddMRUEntry( LPCTSTR pszMacroName )
{
   int iString;

   iString = FindStringExact( -1, pszMacroName );
   if( iString != CB_ERR )
   {
	  DeleteString( iString );
   }

   ASSERT( GetCount() <= MACROCOMBOBOX_MRUSIZE );
   if( GetCount() == MACROCOMBOBOX_MRUSIZE )
   {
	  DeleteString( MACROCOMBOBOX_MRUSIZE-1 );
   }

   InsertString( 0, pszMacroName );
}

BEGIN_MESSAGE_MAP(CMacroComboBox, CComboBox)
	//{{AFX_MSG_MAP(CMacroComboBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMacroComboBox message handlers

BOOL CMacroComboBox::PreTranslateMessage( MSG* pMsg )
{
   CString strMacroName;

   if( pMsg->message == WM_KEYDOWN )
   {
	  if( pMsg->wParam == VK_RETURN )
	  {
		 if( (pMsg->lParam&0x04000000) == 0 )
		 {
			if( GetWindowTextLength() > 0 )
			{
			   GetWindowText( strMacroName );
			   AddMRUEntry( strMacroName );

			   SetCurSel( 0 );
			   GetOwner()->SendMessage( WM_COMMAND, MAKELONG( ID_RUNMACRO, 0 ),
				  LPARAM( m_hWnd ) );
			}
		 }

		 return( TRUE );
	  }
   }

	return( CComboBox::PreTranslateMessage( pMsg ) );
}
