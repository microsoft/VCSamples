///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp 2000.  All rights reserved.
//
//  Description: Shows how to throw and handle CLR Exceptions in C
//
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <windows.h>

__declspec(dllimport) void thrower();

int main()
{
    printf("CLR Exception code would be %x\n", 0xE0000000 | 'COM');

    __try {
        thrower();
    }
    __except(1) {
        printf("Caught an exception -- code: %x\n", GetExceptionCode());
    }

    return 0;
}
