// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

// NOTE: This example will only work with Excel10 in OfficeXP
// Compile with cl /GX comexcel.cpp
#include "stdafx.h"


#define OFFICE2007 1
#define OFFICEXP 2
#define OFFICE2000 3

// Default Settings
#define OFFICE_VER OFFICE2007
#define USE_PROGID 1
#define USE_LIBID 0

#define _M2STR(x) #x
#define M2STR(x) _M2STR(x)


// Ignore hard wired default paths if MSDLL_PATH is
// defined from the command line
#ifndef MSDLL_PATH

// Paths to required MS OFFICE files.
// Make sure these paths are correct for your  machine
#pragma message ("Make sure the path to MSO DLL is correct.")
#if OFFICE_VER == OFFICE2007
#define _MSDLL_PATH "C:\Program Files\Common Files\Microsoft Shared\Office12\MSO.DLL"
#elif  OFFICE_VER == OFFICEXP
#define _MSDLL_PATH "C:\Program Files\Common Files\Microsoft Shared\Office11\MSO.DLL"
#elif  OFFICE_VER == OFFICE2000
#define   _MSDLL_PATH "C:\Program Files\Microsoft Office\Office\MSO9.dll"
#endif

#else
#define _MSDLL_PATH M2STR(MSDLL_PATH)
#endif

//
// Delete the *.tlh files when changing import qualifiers
#import _MSDLL_PATH rename("RGB", "MSRGB")


#ifdef VBE6EXT_PATH
#import M2STR(VBE6EXT_PATH) 
#else
#import "C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB"
#endif

#if USE_PROGID
#import "progid:Excel.Sheet" auto_search auto_rename rename_search_namespace("Office12") 

#elif USE_LIBID
#import "libid:{00020813-0000-0000-C000-000000000046}" auto_search auto_rename version(1.3) lcid(0) no_search_namespace
#else

// Ignore hard wired default paths if MSDLL_PATH is
// defined from the command line
#ifndef MSEXCEL_PATH

#pragma message ("Make sure the path to excel.exe is correct")
#if  OFFICE_VER == OFFICE2007
#define   _MSEXCEL_PATH "C:\Program Files\Microsoft Office\Office12\excel.exe"
#elif  OFFICE_VER == OFFICEXP
#define   _MSEXCEL_PATH "C:\Program Files\Microsoft Office\Office11\excel.exe"
#elif  OFFICE_VER == OFFICE2000
#define   _MSEXCEL_PATH "C:\Program Files\Microsoft Office\Office\excel.exe"
#endif

#else
#define _MSEXCEL_PATH  M2STR(MSEXCEL_PATH) 
#endif

#import _MSEXCEL_PATH auto_search auto_rename dual_interfaces
#endif // USE_LIBID



void dump_com_error(_com_error &e)
{
    _tprintf(_T("Oops - hit an error!\n"));
    _tprintf(_T("\a\tCode = %08lx\n"), e.Error());
    _tprintf(_T("\a\tCode meaning = %s\n"), e.ErrorMessage());
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    _tprintf(_T("\a\tSource = %s\n"), (LPCTSTR) bstrSource);
    _tprintf(_T("\a\tDescription = %s\n"), (LPCTSTR) bstrDescription);
}

// If this is placed in the scope of the smart pointers, they must be
// explicitly Release(d) before CoUninitialize() is called.  If any reference
// count is non-zero, a protection fault will occur.
struct StartOle {
    StartOle() { CoInitialize(NULL); }
    ~StartOle() { CoUninitialize(); }
} _inst_StartOle;

void main()
{
    using namespace Excel;

    _ApplicationPtr pXL;

    try {
    pXL.CreateInstance(L"Excel.Application");

    pXL->Visible[0] = VARIANT_TRUE;

    WorkbooksPtr pBooks = pXL->Workbooks;
    _WorkbookPtr pBook  = pBooks->Add((long)xlWorksheet);

    _WorksheetPtr pSheet = pXL->ActiveSheet;


    try {
        // This one will fail; it is done on purpose to demonstrate the error.
        pSheet->Name = "Market Share?";
    } catch (_com_error &e) {
        dump_com_error(e);
    }

    pSheet->Name = "Market Share!";

    // When using parameterized properties, optional args must be explicitly dealt with.
    pSheet->Range["A2"][vtMissing]->Value2 = "Company A";
    pSheet->Range["B2"][vtMissing]->Value2 = "Company B";
    pSheet->Range["C2"][vtMissing]->Value2 = "Company C";
    pSheet->Range["D2"][vtMissing]->Value2 = "Company D";

    // Of course, you can call a parameterized property as a method and then optional args are implicit.
    pSheet->GetRange("A3")->Value2 = 75.0;
    pSheet->GetRange("B3")->Value2 = 14.0;
    pSheet->GetRange("C3")->Value2 = 7.0;
    pSheet->GetRange("D3")->Value2 = 4.0;
    
    Sleep(1000);

    RangePtr pRange = pSheet->Range["A2:D3"][vtMissing];
    _ChartPtr pChart = pBook->Charts->Add();
    
    pChart->ChartWizard((Range*) pRange, (long) xl3DPie, 7L, (long) xlRows,
        1L, 0L, 2L, "Market Share");

    Sleep(6000);

    pBook->Saved[0] = VARIANT_TRUE;
    pXL->Quit();
    } catch(_com_error &e) {
    dump_com_error(e);
    }
	
}
