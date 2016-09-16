///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description: Demonstrates the syntax for writing different classes
//               and modifiers for those classes.
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// REF CLASSES
//=========================================================================

ref class R1 {
public:
    R1() { X = 0; }
    int X;
    void F() {
        Console::WriteLine("    Value of X in instance of R1: {0}", X++);
    }
};

void RefClasses() {
    R1^ r = gcnew R1;
    r->F();
    r->F();
}

//=========================================================================
// VALUE CLASSES
//=========================================================================

value class V1 {
public:
    int X;
    void F() {
        Console::WriteLine("    Value of X in instance of V1: {0}", X++);
    }
};

void ValueClasses() {
    V1 v;
    v.F();
    v.F();
}

//=========================================================================
// INTERFACES
//=========================================================================

interface class I1 {
    void F();
};

ref class R2 : I1 {
public:
    R2() { X = 0; }
    int X;
    virtual void F() {
        Console::WriteLine("    Value of X in instance of R2 (I1): {0}", X++);
    }
};

void Interfaces() {
    I1^ i = gcnew R2;
    i->F();
    i->F();
}

//=========================================================================
// ABSTRACT
//=========================================================================

ref class Animal abstract {
public:
    virtual String^ Habitat() {
        return "Earth";
    }
};

ref class PolarBear : Animal {
public:
    virtual String^ Habitat() override {
        return String::Concat("North Pole, ", Animal::Habitat());
    }
};

void Abstract() {
    Animal^ creature = gcnew PolarBear;
    Console::WriteLine("    This animal is located at: {0}", 
        creature->Habitat());
}

//=========================================================================
// SEALED
//=========================================================================

ref class Currency {
public:
    virtual String^ Color() {
        return "Every Color";
    }
};

ref class Dollar sealed : Currency {
public:
    virtual String^ Color() override {
        return "Green";
    }
};

void Sealed() {
    Dollar^ buck = gcnew Dollar;
    Console::WriteLine("    The color of a dollar is: {0}",
        buck->Color());
}

//=========================================================================
// ACCESSIBILITY
//=========================================================================

ref class R3 {
public:
    int A;
protected:
    int B;
private:
    int C;
internal:     // Private outside the assembly, public inside
    int D;
public protected:   // Protected outside the assembly, public inside
    int E;
protected private:  // Private outside the assembly, protected inside
    int F;
};

ref struct R4 {
    int X;  // Accessibility of X is public
};


value struct V2 {
    int X;  // Accessibility of X is public
};

//=========================================================================
// CLASSES SAMPLE
//=========================================================================

void Classes() {
    Console::WriteLine("=== Beginning of Classes Sample ===\n");

    RefClasses();
    ValueClasses();
    Interfaces();
    Abstract();
    Sealed();

    Console::WriteLine("\n=== End of Classes Sample ===");
}