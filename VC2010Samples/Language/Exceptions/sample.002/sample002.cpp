///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp 2000.  All rights reserved.
//
//  Run: Build sample002.sln
//
//  Description: Shows how to throw and handle CLR Exceptions in C++
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>
#include <eh.h>

using namespace std;

__declspec(dllimport) void thrower();

class CMyException {
  unsigned int m_ErrorCode;

  EXCEPTION_POINTERS *m_pExp;

private:
    ostream &PrintExceptionRecord(ostream &out, const EXCEPTION_RECORD &er) const {
        out << "ExceptionRecord:\n";
        out << "\tExceptionCode: " << er.ExceptionCode << endl;
        out << "\tExceptionFlags: " << er.ExceptionFlags << endl;
        out << "\t*ExceptionRecord: " << er.ExceptionRecord << endl;
        out << "\tExceptionAddress: " << er.ExceptionAddress << endl;
        out << "\tNumberParameters: " << er.NumberParameters << endl;

        for(DWORD i = 0; i < er.NumberParameters; i++) {
            out << "\tExceptionInformation[" << i << "] = " << 
                er.ExceptionInformation[i] << endl;
        }

        if (er.ExceptionRecord) {
            out << "\n\nPrinting next exception:\n";
            PrintExceptionRecord(out, *(er.ExceptionRecord));
        }

        return out;
    }

    ostream &PrintException(ostream &out, const PEXCEPTION_POINTERS ptr) const {
        if (!ptr) {
            return out;
        }

        if (ptr->ExceptionRecord) {
            PrintExceptionRecord(out, *(ptr->ExceptionRecord));
        }

        return out;
    }

public:
    CMyException()
        : m_ErrorCode(0), m_pExp(NULL) {
    }

    CMyException(unsigned int i, EXCEPTION_POINTERS* pExp) 
        : m_ErrorCode(i), m_pExp(pExp) {
    }

    CMyException(CMyException &c) 
        : m_ErrorCode(c.m_ErrorCode), m_pExp(c.m_pExp) {
    }

    friend ostream &operator<<(ostream &out, const CMyException &inst)  { 
		out << "CMyException:\n" << "Error Code: " << (hex) << inst.m_ErrorCode << endl; 
        return inst.PrintException(out, inst.m_pExp);
    }
};

void TransFunc(unsigned int u, PEXCEPTION_POINTERS pExp)
{
  cout << "In TransFunc.\n";

  CMyException e(u, pExp);
  throw e;
}

int main() {
    //
    // Catch a CLR exception as a C++ exception
    //
    _set_se_translator(TransFunc);

    cout << "Com+ exception code will be " << (hex) << (0xE0000000 | 'COM') << endl;

    try {
        thrower();
    }
    catch(CMyException e) {
        cout << e << endl;
    }

    cout << "**DONE**" << endl;

    return 0;
}
