// File: TypeAttr.Cpp
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

CSmartTypeAttr::CSmartTypeAttr( ITypeInfo* pTypeInfo ) :
   m_pTypeAttr( NULL ),
   m_pTypeInfo( pTypeInfo )
{
}

CSmartTypeAttr::~CSmartTypeAttr()
{
   Release();
}

TYPEATTR* CSmartTypeAttr::operator->()
{
   ASSERT( m_pTypeAttr != NULL );

   return( m_pTypeAttr );
}

TYPEATTR** CSmartTypeAttr::operator&()
{
   ASSERT( m_pTypeAttr == NULL );

   return( &m_pTypeAttr );
}

void CSmartTypeAttr::Release()
{
   if( m_pTypeAttr != NULL )
   {
	  ASSERT( m_pTypeInfo != NULL );
	  m_pTypeInfo->ReleaseTypeAttr( m_pTypeAttr );
	  m_pTypeAttr = NULL;
   }
}

CSmartVarDesc::CSmartVarDesc( ITypeInfo* pTypeInfo ) :
   m_pVarDesc( NULL ),
   m_pTypeInfo( pTypeInfo )
{
}

CSmartVarDesc::~CSmartVarDesc()
{
   Release();
}

VARDESC* CSmartVarDesc::operator->()
{
   ASSERT( m_pVarDesc != NULL );

   return( m_pVarDesc );
}

VARDESC** CSmartVarDesc::operator&()
{
   ASSERT( m_pVarDesc == NULL );

   return( &m_pVarDesc );
}

CSmartVarDesc::operator const VARDESC*() const
{
   return( m_pVarDesc );
}

void CSmartVarDesc::Release()
{
   if( m_pVarDesc != NULL )
   {
	  ASSERT( m_pTypeInfo != NULL );
	  m_pTypeInfo->ReleaseVarDesc( m_pVarDesc );
	  m_pVarDesc = NULL;
   }
}

CSmartFuncDesc::CSmartFuncDesc( ITypeInfo* pTypeInfo ) :
   m_pFuncDesc( NULL ),
   m_pTypeInfo( pTypeInfo )
{
}

CSmartFuncDesc::~CSmartFuncDesc()
{
   Release();
}

FUNCDESC* CSmartFuncDesc::operator->()
{
   ASSERT( m_pFuncDesc != NULL );

   return( m_pFuncDesc );
}

FUNCDESC** CSmartFuncDesc::operator&()
{
   ASSERT( m_pFuncDesc == NULL );

   return( &m_pFuncDesc );
}

CSmartFuncDesc::operator const FUNCDESC*() const
{
   return( m_pFuncDesc );
}

void CSmartFuncDesc::Release()
{
   if( m_pFuncDesc != NULL )
   {
	  ASSERT( m_pTypeInfo != NULL );
	  m_pTypeInfo->ReleaseFuncDesc( m_pFuncDesc );
	  m_pFuncDesc = NULL;
   }
}
