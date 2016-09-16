///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description: Coverage of basic concepts and information useful to
//               understanding other examples in this sample project.
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// PRAGMA REGION
// The examples in this sample project will use pragma region to hide
// utility functions, such as printing the contents of a collection.
//=========================================================================

#pragma region Example
// By default, the Visual Studio editor will collapse this region of code.
// Code generators, such as the Forms Designers, will generate code inside
// these regions to help the programmer focus on non-generated code.
#pragma endregion 

//=========================================================================
// HELLO WORLD
//=========================================================================

void HelloWorld() {
    System::Console::WriteLine("    Hello World!");
}

//=========================================================================
// ASSEMBLY REFERENCES
// Assemblies are referenced with the #using directive. The mscorlib.dll
// assembly is automatically referenced by the C++ compiler, so it is not
// necessary to include that in source code.
//=========================================================================

// Get access to the diagnostics libraries in the .NET Frameworks
#using <System.dll>

// All of the code in Frameworks assemblies are in namespaces. Sometimes
// it is useful to bring contents of a particular namespace into the
// current scope with a using directive.
using namespace System::Diagnostics;

// This sample has the following using directive in the header file
// samples.h so that the contents of the System namespace are available
// throughout the code in this project.
using namespace System;

//=========================================================================
// HANDLES
//=========================================================================

void Handles() {
    // Handles refer to an object on the garbage collected heap
    String^ str = "    A String!";
    Object^ obj = str;

    // Members of a handle variable are accessed via the arrow operator
    Console::WriteLine(obj->ToString());
}

//=========================================================================
// GCNEW
// The gcnew operator creates a new instance of a type on the garbage
// collected heap. When all roots to that object are no longer active,
// the CLR garbage collector will cleanup the memory to that object.
//=========================================================================

void GarbageCollection() {
    Random^ rand = gcnew Random;
    Console::WriteLine("    Some random numbers: {0}, {1}, {2}",
                       rand->Next(), rand->Next(), rand->Next());
}

//=========================================================================
// BASICS SAMPLE
//=========================================================================

void Basics() {
    Console::WriteLine("=== Beginning of Basic Concepts Sample ===\n");

    HelloWorld();
    Handles();
    GarbageCollection();

    Console::WriteLine("\n=== End of Basic Concepts Sample ===");
}