///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description:
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// BOXING SAMPLE
//=========================================================================

void Boxing() {
    Console::WriteLine("=== Beginning of Boxing Sample ===\n");

    Object^ obj = 42;           // Box the integer value 42
    int^ boxint = (int^)obj;    // int^ is a boxed int

    Console::WriteLine("    Value of obj, boxint: {0}, {1}", obj, boxint);

    *boxint = 101;              // Change value in boxed int object

    Console::WriteLine("    Value of obj, boxint: {0}, {1}", obj, boxint);

    obj = 87;                   // Box the integer value 87

    Console::WriteLine("    Value of obj, boxint: {0}, {1}", obj, boxint);

    int i = (int)obj;           // Unbox and copy value from an Object^
    int j = *boxint;            // Copy value from an int^

    Console::WriteLine("    Value of i, j: {0}, {1}", i, j);

    Console::WriteLine("\n=== End of Boxing Sample ===");
}