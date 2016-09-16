// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently

#define VC_EXTRALEAN

#include <afxwin.h>      // MFC core and standard components
#include <afxext.h>         // MFC extensions (including VB)
#include <afxtempl.h>
#include <afxdisp.h>

#include "../server/cdata.h"

#import "../server/stlcoll.tlb" no_namespace exclude("tagPOINT") exclude("tagIMyStruct")

void dump_com_error(_com_error &e);