// File: VarUtils.Cpp
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

class INVOKEKIND_ENTRY
{
public:
   LPCTSTR pszName;
   INVOKEKIND invokekind;
};

static INVOKEKIND_ENTRY g_aInvokeKinds[] =
{
   { _T( "Method" ), INVOKE_FUNC },
   { _T( "PropGet" ), INVOKE_PROPERTYGET },
   { _T( "PropPut" ), INVOKE_PROPERTYPUT },
   { _T( "PropPutRef" ), INVOKE_PROPERTYPUTREF }
};

const int NUM_INVOKEKINDS = sizeof( g_aInvokeKinds )/sizeof(
   g_aInvokeKinds[0] );

LPCTSTR InvokeKindToString( INVOKEKIND invokekind )
{
   int iInvokeKind;

   for( iInvokeKind = 0; iInvokeKind < NUM_INVOKEKINDS; iInvokeKind++ )
   {
	  if( g_aInvokeKinds[iInvokeKind].invokekind == invokekind )
	  {
		 return( g_aInvokeKinds[iInvokeKind].pszName );
	  }
   }

   return( NULL );
}

class VARTYPE_ENTRY
{
public:
   LPCTSTR pszName;
   VARTYPE vt;
};

static VARTYPE_ENTRY g_aVarTypes[] =
{
   { _T( "VT_EMPTY" ), VT_EMPTY },
   { _T( "VT_BOOL" ), VT_BOOL },
   { _T( "VT_UI1" ), VT_UI1 },
   { _T( "VT_UI2" ), VT_UI2 },
   { _T( "VT_UI4" ), VT_UI4 },
   { _T( "VT_UI8" ), VT_UI8 },
   { _T( "VT_I1" ), VT_I1 },
   { _T( "VT_I2" ), VT_I2 },
   { _T( "VT_I4" ), VT_I4 },
   { _T( "VT_I8" ), VT_I8 },
   { _T( "VT_R4" ), VT_R4 },
   { _T( "VT_R8" ), VT_R8 },
   { _T( "VT_BSTR" ), VT_BSTR },
   { _T( "VT_CY" ), VT_CY },
   { _T( "VT_DATE" ), VT_DATE },
   { _T( "VT_ERROR" ), VT_ERROR },
   { _T( "VT_COLOR" ), VT_COLOR },
   { _T( "VT_FONT" ), VT_FONT },
   { _T( "VT_UNKNOWN" ), VT_UNKNOWN }
};

LPCTSTR VTIToString( int iType )
{
   return( g_aVarTypes[iType].pszName );
}

VARTYPE VTIToVT( int iType )
{
   return( g_aVarTypes[iType].vt );
}

LPCTSTR VTToString( VARTYPE vt )
{
   int iType;

   for( iType = 0; iType < NUM_VARTYPES; iType++ )
   {
	  if( g_aVarTypes[iType].vt == vt )
	  {
		 return( g_aVarTypes[iType].pszName );
	  }
   }

   return( NULL );
}

int VTToVTI( VARTYPE vt )
{
   int iType;

   for( iType = 0; iType < NUM_VARTYPES; iType++ )
   {
	  if( g_aVarTypes[iType].vt == vt )
	  {
		 return( iType );
	  }
   }

   return( -1 );
}

CString VariantToString( const VARIANT& var )
{

   CString strResult;
   COleVariant varString;
   BOOL tHandled;

   tHandled = FALSE;
   switch( var.vt )
   {
   case VT_BOOL:
	  if( var.boolVal == VARIANT_FALSE )
	  {
		 strResult = _T( "FALSE" );
	  }
	  else
	  {
		 strResult = _T( "TRUE" );
	  }
	  tHandled = TRUE;
	  break;
   }

   if( !tHandled )
   {
	  varString = var;
	  TRY
	  {
		 varString.ChangeType( VT_BSTR );
	  }
	  CATCH( COleException, e )
	  {
		 TRACE( "ChangeType() failed.\n" );
	  }
	  END_CATCH

	  strResult = varString.bstrVal;
   }

   return( strResult );
}
