// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently
#define STRICT

#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CExeModule : public CComModule
{
public:
    LONG Unlock();
    DWORD dwThreadID;
};
extern CExeModule _Module;
#include <atlcom.h>
#include <atlctl.h>
#include <atlwin.h>

#import "../drawctl/drawctl.tlb" no_namespace raw_interfaces_only
