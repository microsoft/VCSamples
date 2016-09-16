// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define STRICT
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>

const CLSID CLSID_CDrawServ = {0x330E9E79,0xDF48,0x11CF,{0x8E,0x2C,0x00,0xA0,0xC9,0x0D,0xC9,0x4B}};

#import "drawctl.tlb" no_namespace named_guids rename("CDrawCtl", "CoDrawCtl") raw_interfaces_only