// File: ExcepInf.Cpp
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

CExcepInfo::CExcepInfo()
{
   memset( this, 0, sizeof( *this ) );
}

CExcepInfo::~CExcepInfo()
{
   Clear();
}

void CExcepInfo::Clear()
{
   if( bstrSource != NULL )
   {
	  ::SysFreeString( bstrSource );
   }
   if( bstrDescription != NULL )
   {
	  ::SysFreeString( bstrDescription );
   }
   if( bstrHelpFile != NULL )
   {
	  ::SysFreeString( bstrHelpFile );
   }

   memset( this, 0, sizeof( *this ) );
}
