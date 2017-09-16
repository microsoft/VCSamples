// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\labrador\labrador.mrg.cpp
// compiler-generated file created 09/15/17 at 22:19:25
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

#pragma message("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

// Labrador.cpp : Implementation of EXE registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "prelab.h"
#include "labres.h"
#include "initguid.h"

[ emitidl ];
[ module(exe, uuid = "{62A33E74-932A-11CF-B056-00A0C90348FA}", name = "Labrador", helpstring = "Labrador 1.0 Type Library") ];

//+++ Start Injected Code For Attribute 'module'
#injected_line 17 "Labrador.cpp"
extern "C" const __declspec(selectany) GUID __LIBID_ = {0x62a33e74,0x932a,0x11cf,{0xb0,0x56,0x00,0xa0,0xc9,0x03,0x48,0xfa}};
struct __declspec(uuid("62a33e74-932a-11cf-b056-00a0c90348fa")) Labrador;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 17 "Labrador.cpp"

class CLabradorModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 17 "Labrador.cpp"

extern CLabradorModule _AtlModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 17 "Labrador.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 17 "Labrador.cpp"

class CLabradorModule : public CAtlExeModuleT<CLabradorModule>
    								
{
public:
    DECLARE_LIBID(__uuidof(Labrador))
        								
};

#injected_line 17 "Labrador.cpp"

CLabradorModule _AtlModule;

#injected_line 17 "Labrador.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd)
    					
{
    return _AtlModule.WinMain(nShowCmd);
}

//--- End Injected Code For Attribute 'module'

