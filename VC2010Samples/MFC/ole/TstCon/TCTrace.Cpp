// File: TCTrace.Cpp
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

static int g_nTraceLevel = TRACELEVEL_NORMAL;

int GetTraceLevel()
{
   return( g_nTraceLevel );
}

void SetTraceLevel( int nLevel )
{
   g_nTraceLevel = nLevel;
}

void __cdecl TCControlTrace( int nLevel, CTestContainer98Item* pItem,
   LPCTSTR pszFormat, ... )
{
   va_list args;
   va_start( args, pszFormat );

   int nBuf;
   TCHAR szBuffer[512];
   CString strItemName;

   if( g_nTraceLevel < nLevel )
   {
	  return;
   }

   strItemName = pItem->GetDisplayName();
   sprintf_s( szBuffer, 512, "TestCon: %s: ", LPCTSTR( strItemName ) );
   OutputDebugString( szBuffer );

   nBuf = _vstprintf_s( szBuffer, 512, pszFormat, args );
   ASSERT( nBuf < sizeof( szBuffer ) );

   OutputDebugString( szBuffer );

   va_end( args );
}

void __cdecl TCTrace( int nLevel, LPCTSTR pszFormat, ... )
{
   va_list args;
   va_start( args, pszFormat );

   int nBuf;
   TCHAR szBuffer[512];

   if( g_nTraceLevel < nLevel )
   {
	  return;
   }

   nBuf = _vstprintf_s( szBuffer, 512, pszFormat, args );
   ASSERT( nBuf < sizeof( szBuffer ) );

   OutputDebugString( _T( "TestCon: " ) );
   OutputDebugString( szBuffer );

   va_end( args );
}
