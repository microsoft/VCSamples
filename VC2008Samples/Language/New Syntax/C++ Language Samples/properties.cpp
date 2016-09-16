///////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp.  All rights reserved.
//
//  Description:
//
///////////////////////////////////////////////////////////////////////////

#include "samples.h"

//=========================================================================
// TRIVIAL PROPERTY
//=========================================================================

value class P1 {
public:
    property int X;
};

void TrivialProperty() {
    P1 p;
    Console::WriteLine("    Value of P1's X is {0}", p.X);
    p.X = 42;
    Console::WriteLine("    And now value of P1's X is {0}", p.X);
}

//=========================================================================
// READ-WRITE PROPERTY
//=========================================================================

value class P2 {
    int MyX;
public:
    property int X {
        int get() {
            Console::WriteLine("    Getting P2's X value ({0})", MyX);
            return MyX;
        }

        void set(int value) {
            Console::WriteLine("    Setting P2's X value ({0})", value);
            MyX = value;
        }
    }
};

void ReadWriteProperty() {
    P2 p;
    p.X = 42;
    p.X = p.X + 1;
}

//=========================================================================
// READ-ONLY PROPERTY
//=========================================================================

value class P3 {
    int MyX;
public:
    P3(int value) : MyX(value) {}

    property int X {
        int get() {
            return MyX;
        }
    }
};

void ReadOnlyProperty() {
    P3 p(42);
    Console::WriteLine("    Value of P3's X is {0}", p.X);
}

//=========================================================================
// INDEXED PROPERTY
//=========================================================================

value class P4 {
    ref class LinkList {
    public:
        LinkList(int key, int value) : Key(key), Value(value) {}
        int Key;
        int Value;
        LinkList^ NextNode;
    };

    LinkList^ Root;
public:
    property int Map[int]{
        int get(int x) {
            LinkList^ current = Root;
            while (current) {
                if (x == current->Key) {
                    Console::WriteLine("    P4 maps {0} to {1}",
                        current->Key, current->Value);
                    return current->Value;
                }
                current = current->NextNode;
            }
            Console::WriteLine("    P4 does not map {0} to anything", x);
            throw gcnew InvalidOperationException;
        }

        void set(int x, int value) {
            Console::WriteLine("    P4 mapping {0} to {1}", x, value);
            if (Root == nullptr) {
                Root = gcnew LinkList(x, value);
                return;
            }

            LinkList^ current = Root;

            while ((current->NextNode != nullptr) && (current->Key != x)) {
                current = current->NextNode;
            }

            if (current->Key == x) {
                current->Value = value;
                return;
            }

            current->NextNode = gcnew LinkList(x, value);
        }
    }
};

void IndexedProperty() {
    P4 p;
    p.Map[5503] = 4527;
    p.Map[1340] = 3869;
    p.Map[1] = p.Map[5503] + p.Map[1340];
}

//=========================================================================
// DEFAULT INDEXED PROPERTY
//=========================================================================

ref class P5 {
    ref class LinkList {
    public:
        LinkList(int key, int value) : Key(key), Value(value) {}
        int Key;
        int Value;
        LinkList^ NextNode;
    };

    LinkList^ Root;
public:
    property int default[int] {
        int get(int x) {
            LinkList^ current = Root;
            while (current) {
                if (x == current->Key) {
                    Console::WriteLine("    P5 maps {0} to {1}",
                        current->Key, current->Value);
                    return current->Value;
                }
                current = current->NextNode;
            }
            Console::WriteLine("    P5 does not map {0} to anything", x);
            throw gcnew InvalidOperationException;
        }

        void set(int x, int value) {
            Console::WriteLine("    P5 mapping {0} to {1}", x, value);
            if (Root == nullptr) {
                Root = gcnew LinkList(x, value);
                return;
            }

            LinkList^ current = Root;

            while ((current->NextNode != nullptr) && (current->Key != x)) {
                current = current->NextNode;
            }

            if (current->Key == x) {
                current->Value = value;
                return;
            }

            current->NextNode = gcnew LinkList(x, value);
        }
    }
};

void DefaultIndexedProperty() {
    P5^ p = gcnew P5;
    p[7768] = 3597;
    p[8899] = 3647;
    p[1] = p[7768] + p[8899];
}

//=========================================================================
// PROPERTIES SAMPLE
//=========================================================================

void Properties() {
    Console::WriteLine("=== Beginning of Properties Sample ===\n");

    TrivialProperty();
    ReadWriteProperty();
    ReadOnlyProperty();
    IndexedProperty();
    DefaultIndexedProperty();

    Console::WriteLine("\n=== End of Properties Sample ===");
}