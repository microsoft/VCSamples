///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description: Demonstrates safe cast and C-style cast.
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// DYNAMIC CAST
// A dynamic cast lets you check whether a handle can be casted to another
// type. If it is successful, the cast is done. Otherwise, the result is
// the null value. If returning a null value is not possible, an
// exception occurs.
//=========================================================================

void DynamicCast() {
    Object^ obj = "123";
    IComparable^ icomp = dynamic_cast<IComparable^>(obj);

    if (icomp) {
        int value = icomp->CompareTo("ABC");
        Console::WriteLine("    The object was IComparable, result: {0}", 
            value);
    } else {
        Console::WriteLine("    The obj variable was not IConvertible");
    }
}

//=========================================================================
// SAFE CAST
// Safe cast is capable of casting a base handle to a derived handle when
// it is safe to do so. If it is not safe, an InvalidCastException is
// thrown. A safe cast can also invoke both implicit and explicit user
// defined conversions.
//=========================================================================

void SafeCast() {
    // Base to derived casts
    Object^ obj = "Rhubarb";
    try {
        Version^ v = safe_cast<Version^>(obj);
		Console::WriteLine("Object Version^ is {0}\n", v->ToString());
    } catch (InvalidCastException^) {
        Console::WriteLine("    The object was not Version^");
    }

    String^ str = safe_cast<String^>(obj);
    Console::WriteLine("    The object was a string: {0}", str);

    // User defined conversions
    Decimal d(19.99);
    float f = safe_cast<float>(d);

    Console::WriteLine("    Value of float from conversion: {0}", f);
}

//=========================================================================
// EXPLICIT TYPE CONVERSION
// This is also called a C-style cast. For CLR types and handles, a
// C-style cast will always generate verifiable code. In many cases, it
// is the same as using safe_cast.
//=========================================================================

void ExplicitTypeConversion() {
    // Base to derived casts
    Object^ obj = "Mollusk";
    try {
        Version^ v = (Version^)obj;
		Console::WriteLine("Object Version^ is {0}\n", v->ToString());
    } catch (InvalidCastException^) {
        Console::WriteLine("    The object was not a Version^");
    }

    String^ str = (String^)obj;
    Console::WriteLine("    The object was a string: {0}", str);

    // User defined conversions
    Decimal d(20.01);
    float f = (float)d;

    Console::WriteLine("    Value of float from conversion: {0}", f);
}

//=========================================================================
// CASTING SAMPLE
//=========================================================================

void Casting() {
    Console::WriteLine("=== Beginning of Casting Sample ===\n");

    DynamicCast();
    SafeCast();
    ExplicitTypeConversion();

    Console::WriteLine("\n=== End of Casting Sample ===");
}