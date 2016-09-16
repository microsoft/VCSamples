///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp 2000.  All rights reserved.
//
//  Run: To throw an exception from managed-code to unmanaged-code: managed2unmanaged.cmd
//       To throw an exception from unmanaged-code to managed-code: unmanaged2managed.cmd
//
//  Description: Shows how to throw and handle CLR Exceptions in C++
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

class CException {
public:
    CException()
        : m_excode(0xFFFFFFFF) {
    }

    CException(unsigned int code)
        : m_excode(code) {
    }

    friend std::ostream &operator<<(std::ostream &out, const CException &e) {
        return out << "CException[" << e.m_excode << "]";
    }

    ~CException() {
    }

private:
    unsigned int m_excode;
};
