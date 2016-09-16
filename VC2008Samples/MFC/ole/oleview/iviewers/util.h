// util.h

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _UTIL_H_
#define _UTIL_H_
LPCTSTR AFXAPI _GetScodeString(SCODE sc);
void ErrorMessage( const CString& str, HRESULT hr ) ;
LPTSTR HRtoString( HRESULT hr ) ;
LONG WINAPI ParseOffNumber( LPTSTR FAR *lplp, LPINT lpConv ) ;
CString TYPEDESCtoString( ITypeInfo* pti, TYPEDESC* ptdesc );
CString  VTtoString( VARTYPE vt ) ;

#endif
