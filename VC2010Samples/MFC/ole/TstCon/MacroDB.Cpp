// File: MacroDB.Cpp
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

IMPLEMENT_DYNAMIC( CMacroDialogBar, CDialogBar )

BEGIN_MESSAGE_MAP( CMacroDialogBar, CDialogBar )
   ON_WM_CREATE()
END_MESSAGE_MAP()

CSize CMacroDialogBar::CalcFixedLayout( BOOL tStretch, BOOL tHorz )
{
   CSize size;

   size = CDialogBar::CalcFixedLayout( tStretch, tHorz );

   size.cy = 23;

   return( size );
}

BOOL CMacroDialogBar::Create( CWnd* pParent, UINT nStyle, UINT nID )
{
   HWND hControl;

   if( !CDialogBar::Create( pParent, IDD_MACROBAR, nStyle, nID ) )
   {
	  return( FALSE );
   }

   hControl = NULL;
   GetDlgItem( IDC_MACRO, &hControl );
   ASSERT( hControl != NULL );

   if( !m_cboxMacroName.SubclassWindow( hControl ) )
   {
	  ASSERT( FALSE );
   }

   return( TRUE );
}
