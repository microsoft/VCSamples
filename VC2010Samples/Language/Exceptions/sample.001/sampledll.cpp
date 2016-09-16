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

__declspec(dllexport) void thrower()
{
    throw CException(0xEEEEEEEE);
}
