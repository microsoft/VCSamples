// File: AProp.Cpp
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


IMPLEMENT_SERIAL( CAmbientProperty, CObject, 1 );

CAmbientProperty::CAmbientProperty() :
   m_dispid( 0 ),
   m_tEnabled( FALSE )
{
}

CAmbientProperty::CAmbientProperty( DISPID dispid, LPCTSTR pszName,
   const VARIANT& var, int vti, BOOL tStock ) :
   m_dispid( dispid ),
   m_strName( pszName ),
   m_varValue( var ),
   m_vti( vti ),
   m_tEnabled( TRUE ),
   m_tStock( tStock )
{
}

CAmbientProperty& CAmbientProperty::operator=( const CAmbientProperty& prop )
{
   m_dispid = prop.m_dispid;
   m_strName = prop.m_strName;
   m_varValue = prop.m_varValue;
   m_vti = prop.m_vti;
   m_tEnabled = prop.m_tEnabled;
   m_tStock = prop.m_tStock;

   return( *this );
}

void CAmbientProperty::Enable( BOOL tEnabled )
{
   m_tEnabled = tEnabled;
}

DISPID CAmbientProperty::GetID() const
{
   return( m_dispid );
}

CString CAmbientProperty::GetName() const
{
   return( m_strName );
}

const COleVariant& CAmbientProperty::GetValue() const
{
   return( m_varValue );
}

int CAmbientProperty::GetVTI() const
{
   return( m_vti );
}

BOOL CAmbientProperty::IsEnabled() const
{
   return( m_tEnabled );
}

BOOL CAmbientProperty::IsStock() const
{
   return( m_tStock );
}

void CAmbientProperty::SetValue( const VARIANT& varValue, int vti )
{
   m_varValue = varValue;
   if( vti == -1 )
   {
	  m_vti = VTToVTI( varValue.vt );
   }
   else
   {
	  ASSERT( VTIToVT( vti ) == varValue.vt );
	  m_vti = vti;
   }
}

void CAmbientProperty::Serialize( CArchive& ar )
{
   CObject::Serialize( ar );

   if( ar.IsStoring() )
   {
	  ar<<m_dispid;
	  ar<<m_strName;
	  ar<<m_varValue;
	  ar<<m_vti;
	  ar<<m_tEnabled;
	  ar<<m_tStock;
   }
   else
   {
	  ar>>m_dispid;
	  ar>>m_strName;
	  ar>>m_varValue;
	  ar>>m_vti;
	  ar>>m_tEnabled;
	  ar>>m_tStock;
   }
}
