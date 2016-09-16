///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp 2000.  All rights reserved.
//
//  Run: To throw an exception from managed-code to unmanaged-code: managed2unmanaged.cmd
//       To throw an exception from unmanaged-code to managed-code: unmanaged2managed.cmd
//
//  Description: Shows how to throw and handle CLR Exceptions in C++
//
///////////////////////////////////////////////////////////////////////////////

#include "Exception.h"

#ifdef _MANAGED
#using <mscorlib.dll>

using namespace System;
#endif

__declspec(dllimport) void thrower();

int main()
{
    try {
        thrower();
    }
    catch(const CException &e) {
        cout << "Caught " << e << endl;
    } 

    cout << "**DONE**\n";

    return 0;
}
