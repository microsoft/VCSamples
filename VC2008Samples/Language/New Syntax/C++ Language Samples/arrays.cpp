///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description: Demonstration of arrays and how they can be used.
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

#pragma region OutputUtilities
void PrintSingleDimensionalArray(array<int>^ Arr) {
    for(int i = 0; i < Arr->Length; i++) {
        Console::Write("{0,3}", Arr[i]);
    }
    Console::WriteLine();
}

void PrintMultiDimensionalArray(array<int,2>^ Arr) {
    for(int i = 0; i < Arr->GetLength(0); i++) {
        Console::Write("        ");
        for(int j = 0; j < Arr->GetLength(1); j++) {
            Console::Write("{0,3}", Arr[i,j]);
        }
        Console::WriteLine();
    }
}

void PrintJaggedArray(array<array<int>^>^ Arr) {
    for(int i = 0; i < Arr->Length; i++) {
        Console::Write("        ");
        for(int j = 0; j < Arr[i]->Length; j++) {
            Console::Write("{0,3}", Arr[i][j]);
        }
        Console::WriteLine();
    }
}
#pragma endregion

//=========================================================================
// SINGLE DIMENSIONAL ARRAYS
//=========================================================================

void SingleDimensional() {
    // Create and aggregate initialize a single dimensional array of
    // length 10.
    array<int>^ arr1 = gcnew array<int>(10) {0, 1, 2, 3, 4};

    // Create and aggregate initialize a single dimensional array. The
    // length is the given number of elements between the brackets.
    array<int>^ arr2 = gcnew array<int> {0, 1, 2, 3, 4};

    // Create a single dimensional array of length 10 and manually
    // initialize it with perfect squares.
    array<int>^ arr3 = gcnew array<int>(10);
    for(int i = 0; i < arr3->Length; i++) {
        arr3[i] = i*i;
    }

    // Print contents of all three arrays
    Console::Write("    Contents of arr1:");
    PrintSingleDimensionalArray(arr1);

    Console::Write("    Contents of arr2:");
    PrintSingleDimensionalArray(arr2);

    Console::Write("    Contents of arr3:");
    PrintSingleDimensionalArray(arr3);
}

//=========================================================================
// MULTI DIMENSIONAL ARRAYS
// The GetLength method of array classes returns the length of a particular
// dimension indexed from zero. The second parameter to the array class
// type is the number of dimensions for the array. The number of parameters
// in the array constructor matches the number of dimensions of the array.
// By default the second array type parameter is one.
//=========================================================================

void MultiDimensional() {
    array<int,2>^ arr4 = gcnew array<int,2>(3,5);
    for(int i = 0; i < arr4->GetLength(0); i++) {
        for(int j = 0; j < arr4->GetLength(1); j++) {
            arr4[i,j] = i*j;
        }
    }

    Console::WriteLine("    Contents of arr4:");
    PrintMultiDimensionalArray(arr4);
}

//=========================================================================
// JAGGED DIMENSIONAL ARRAYS
//=========================================================================

void JaggedArrays() {
    array<array<int>^>^ arr5 = gcnew array<array<int>^>(4);
    for(int i = 0; i < arr5->Length; i++) {
        arr5[i] = gcnew array<int>(i+1);
        for (int j = 1; j <= i+1; j++) {
            arr5[i][j-1] = j;
        }
    }

    Console::WriteLine("    Contents of arr5:");
    PrintJaggedArray(arr5);
}

//=========================================================================
// ARRAY COVARIANCE
//=========================================================================

void ArrayCovariance() {
    array<Object^>^ arr1;
    array<String^>^ arr2;
    array<Version^>^ arr3;

    arr1 = gcnew array<String^>(5);
    try {
        arr1[0] = gcnew Version;
        Console::WriteLine("    Array assignment worked");
    } catch (ArrayTypeMismatchException^) {
        Console::WriteLine("    Array assignment failed");
    }

    try {
        arr2 = (array<String^>^)arr1;
        Console::WriteLine("    Cast to array<String^>^ worked");
    } catch (InvalidCastException^) {
        Console::WriteLine("    Cast to array<String^>^ failed");
    }

    try {
        arr3 = (array<Version^>^)arr1;
        Console::WriteLine("    Cast to array<Version^>^ worked");
    } catch (InvalidCastException^) {
        Console::WriteLine("    Cast to array<Version^>^ failed");
    }
}

//=========================================================================
// PASSING ARRAYS
//=========================================================================

array<String^>^ ReturnArray() {
    return gcnew array<String^> { "Apples", "Cinnamon", "Sugar", "Flour",
                                  "Salt", "Shortening", "Ice Water" };
}

void TakeArray(array<Object^>^ Arr) {
    for(int i = 0; i < Arr->Length; i++) {
        Console::WriteLine("        {0}", Arr[i]);
    }
}

void PassingArrays() {
    array<String^>^ ingredients = ReturnArray();
    Console::WriteLine("    Apple Pie Ingredients:");
    TakeArray(ingredients);
}

//=========================================================================
// ARRAY SAMPLE
//=========================================================================

void Arrays() {
    Console::WriteLine("=== Beginning of Array Sample ===\n");

    SingleDimensional();
    MultiDimensional();
    JaggedArrays();
    ArrayCovariance();
    PassingArrays();

    Console::WriteLine("\n=== End of Array Sample ===");
}