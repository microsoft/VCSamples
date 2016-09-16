// File: TCTrace.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

const int TRACELEVEL_NONE = 0;
const int TRACELEVEL_NORMAL = 1;
const int TRACELEVEL_VERBOSE = 2;

class CTestContainer98Item;

int GetTraceLevel();
void SetTraceLevel( int nLevel );
void __cdecl TCTrace( int nLevel, LPCTSTR pszFormat, ... );
void __cdecl TCControlTrace( int nLevel, CTestContainer98Item* pItem,
   LPCTSTR pszFormat, ... );
