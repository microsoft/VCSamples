// File: VarUtils.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

const int VTI_EMPTY = 0;
const int VTI_BOOL = 1;
const int VTI_UI1 = 2;
const int VTI_UI2 = 3;
const int VTI_UI4 = 4;
const int VTI_UI8 = 5;
const int VTI_I1 = 6;
const int VTI_I2 = 7;
const int VTI_I4 = 8;
const int VTI_I8 = 9;
const int VTI_R4 = 10;
const int VTI_R8 = 11;
const int VTI_BSTR = 12;
const int VTI_CY = 13;
const int VTI_DATE = 14;
const int VTI_ERROR = 15;
const int VTI_COLOR = 16;
const int VTI_FONT = 17;
const int VTI_UNKNOWN = 18;
const int NUM_VARTYPES = 19;

const VARIANT_BOOL VAR_TRUE = ~VARIANT_FALSE;
const VARIANT_BOOL VAR_FALSE = VARIANT_FALSE;

LPCTSTR InvokeKindToString( INVOKEKIND invokekind );
LPCTSTR VTIToString( int iType );
VARTYPE VTIToVT( int iType );
LPCTSTR VTToString( VARTYPE vt );
int VTToVTI( VARTYPE vt );

CString VariantToString( const VARIANT& var );
