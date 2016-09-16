// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

#if !defined(AFX_STDAFX_H__7A31999A_48C0_11D0_AE70_00C04FD7D06E__INCLUDED_)
#define AFX_STDAFX_H__7A31999A_48C0_11D0_AE70_00C04FD7D06E__INCLUDED_

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define STRICT

#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module

#ifdef _USRDLL
extern CComModule _Module;
#else
class CExeModule : public CComModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
};
extern CExeModule _Module;
#endif

#include <atlcom.h>

#include "adosamp.h"

#import <msado15.dll> raw_interfaces_only no_namespace exclude("DataTypeEnum") exclude("ParameterDirectionEnum")

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__7A31999A_48C0_11D0_AE70_00C04FD7D06E__INCLUDED)
