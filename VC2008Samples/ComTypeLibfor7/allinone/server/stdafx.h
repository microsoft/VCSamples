#if !defined(AFX_STDAFX_H__7CE086A4_3E78_11D0_AE6B_00C04FD7D06E__INCLUDED_)
#define AFX_STDAFX_H__7CE086A4_3E78_11D0_AE6B_00C04FD7D06E__INCLUDED_

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma warning(disable: 4786)

#define _WIN32_WINNT 0x0500
#define _ATL_APARTMENT_THREADED


#include <afxwin.h>
#include <afxdisp.h>
#include <atlbase.h>

#include "cdata.h"

//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
#ifndef _USRDLL
class CExeModule : public CComModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
};
extern CExeModule _Module;
#else
extern CComModule _Module;
#endif

#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__7CE086A4_3E78_11D0_AE6B_00C04FD7D06E__INCLUDED)
