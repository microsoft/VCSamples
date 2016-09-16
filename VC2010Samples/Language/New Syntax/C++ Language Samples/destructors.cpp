///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description:
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// SIMPLE DESTRUCTOR
//=========================================================================

ref class SimpleDestructorType {
public:
    ~SimpleDestructorType() {
        Console::WriteLine("    Called Destructor in Simple Type");
    }
};

void SimpleDestructor() {

    SimpleDestructorType^ hsdt = gcnew SimpleDestructorType;
    delete hsdt;
}

//=========================================================================
// EMBEDDED CLASS
//=========================================================================

ref class EmbeddedDestructorType {
public:
    ~EmbeddedDestructorType() {
        Console::WriteLine("    Called Destructor with Embedded Type");
    }
};

void EmbeddedDestructor() {

    EmbeddedDestructorType^ hedt = gcnew EmbeddedDestructorType;
    delete hedt;
}

//=========================================================================
// DERIVED CLASS DESTRUCTOR
//=========================================================================

ref class DerivedDestructorType : SimpleDestructorType {
public:
    ~DerivedDestructorType() {
        Console::WriteLine("    Called Destructor in Derived Type");
    }
};

void DerivedClassDestructor() {

    DerivedDestructorType^ hddt = gcnew DerivedDestructorType;
    delete hddt;
}

//=========================================================================
// DESTRUCTOR SAMPLE
//=========================================================================

void Destructors() {
    Console::WriteLine("=== Beginning of Destructors Sample ===\n");

    SimpleDestructor();
    EmbeddedDestructor();
    DerivedClassDestructor();

    Console::WriteLine("\n=== End of Destructors Sample ===");
}