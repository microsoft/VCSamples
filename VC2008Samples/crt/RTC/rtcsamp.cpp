/* 
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 *
 * Demonstration of the use of the Run-Time Error Checking (RTC) API without 
 * using the C Run-Time Library (CRT).
 *
 * This file contains several functions which purposely demonstrate each
 * type of error which can be caught with RTC.
 */

#include "rtcsample.h"

#ifdef NOCRT
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
int main(int, char **)
#endif
{
   DoInitialization();

    LoseInfoInIntToShortCast();
    TrashStackVariable();
    UseUninitializedVariable();

    DoTermination();

    return 0;
}

int GetVal()
{
    return 0x12341234;
}

void doSomething(short )
{}

void LoseInfoInIntToShortCast()
{
    int value = GetVal();
    doSomething((short)value);
}

void thrashVar(int *i)
{
    i[0] = 4;
    i[1] = 4;
}

void TrashStackVariable()
{
    int stackvar;
    char stackarray[4];
    thrashVar(&stackvar);
    while (stackvar)
#pragma warning (suppress: 6386)
        stackarray[stackvar--] = 0;
}

void UseUninitializedVariable()
{
    for (int i = 0; i < 2; i++)
    {
        int k = 0;
        if (!(i & 1))
            k = i;

        if (i % 2)
            doSomething((short)k);            
    }
}
