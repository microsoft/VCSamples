///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description: This demonstrates the different kind of enumerations that
//               C++ supports and some of the behavioral differences 
//               between them.
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// NATIVE ENUMERATIONS
// A native enumeration can still be used by C# and will act just like CLR
// enumerations in other languages. The difference between native and CLR
// enums are (1) the enumeration values are accessed in the enclosing
// scope and do not need to be qualified with the name of the enum, and
// (2) a native enum value has an implicit conversion to int.
//
// The second difference shows up with overloaded functions, as an integer
// overload will be preferred over an Object overload.
//=========================================================================

enum Directions {
    North,
    East,
    South,
    West
};

void NativeEnums() {
    Directions course = North;
    course = static_cast<Directions>((static_cast<int>(course) + 1));
	Console::Write("    Current direction: ");
    Console::WriteLine(course);
}

//=========================================================================
// CLR ENUMERATIONS
// As noted above, the console output here will choose the Object overload
// which prints the name of the enumeration instead of its integer value.
//=========================================================================

enum class Suits {
    Spades,
    Hearts,
    Clubs,
    Diamonds
};

void ClrEnums() {
    Suits card = Suits::Spades;
    ++card;

    Console::Write("    Current suit: ");
    Console::WriteLine(card);
}

//=========================================================================
// FLAGS ENUMERATIONS
// Putting the Flags attribute on an enumeration indicates that different
// enumerations from the enum can be combined together.
//=========================================================================

[Flags]
enum class Clearance {
    NoAccess       = 0x00,
    TopSecret      = 0x01,
    Confidential   = 0x02,
    MarketResearch = 0x04
};

void FlagsEnums() {
    Clearance employee = 
        Clearance::Confidential | Clearance::MarketResearch;

    Console::WriteLine("    Does employee have top secret clearance? {0}",
        (employee & Clearance::TopSecret) == Clearance::TopSecret);
    Console::WriteLine("    Clearance of employee: {0}", employee);
}

//=========================================================================
// UNDERLYING TYPE
//=========================================================================

enum class SmallEnum : char {
    Value = 'A'
};

void UnderlyingType() {
    Console::WriteLine("    Size of SmallEnum is {0}", sizeof(SmallEnum));
}

//=========================================================================
// ENUMS SAMPLE
//=========================================================================

void Enums() {
    Console::WriteLine("=== Beginning of Enums Sample ===\n");

    NativeEnums();
    ClrEnums();
    FlagsEnums();
    UnderlyingType();

    Console::WriteLine("\n=== End of Enums Sample ===");
}