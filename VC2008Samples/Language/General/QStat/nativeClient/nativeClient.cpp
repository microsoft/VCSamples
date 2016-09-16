//Copyright (c) Microsoft Corporation.  All rights reserved.

//
// nativeClient.cpp
//
// Implements our COM client.
#include "stdafx.h"
#include <TCHAR.h>

// #import imports declerations from the type library and allows us to access
// the coclass and its interface methods.

#import "qstat.dll" raw_interfaces_only

// A global structure for initializing COM. At startup, the constructor calls
// CoInitialize.  At shutdown, the descructor calls CoUninitialize.
struct StartUpCom {
    StartUpCom() { CoInitialize(NULL); }
    ~StartUpCom() { CoUninitialize(); }
} _global_com_inst;

// Dumps error information to the screen.
void dump_com_error(_com_error &e)
{
    _tprintf(_T("Oops - hit an error!\n"));
    _tprintf(_T("\a\tCode = %08lx\n"), e.Error());
    _tprintf(_T("\tCode meaning = %s\n"), e.ErrorMessage());
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    _tprintf(_T("\tSource = %s\n"), (LPCTSTR) bstrSource);
    _tprintf(_T("\tDescription = %s\n"), (LPCTSTR) bstrDescription);
}

using namespace QStat;

#ifdef _UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main()
#endif
{
	try {
		IMeanCalcPtr pMeanCalc(__uuidof(CMeanCalc));
		pMeanCalc->Initialize(20);

		for (short k = 1; k <= 10; k++) {
			pMeanCalc->AddDataPoint(k);
		}
		pMeanCalc->AddDataPoint(-10);
		double d;
		HRESULT ret;

		ret = pMeanCalc->ArithmeticMean(&d);
		if (SUCCEEDED(ret)) {
			printf("The Arithmetic Mean is: %.2f\n", d);
		} else {
			printf("Unable to calculate Arithmetic Mean\n");
		}
		
		ret = pMeanCalc->GeometricMean(&d);
		if (SUCCEEDED(ret)) {
			printf("The Geometric Mean is:  %.2f\n", d);
		} else {
			printf("Unable to calculate Geometric Mean\n");
		}
		
		ret = pMeanCalc->HarmonicMean(&d);
		if (SUCCEEDED(ret)) {
			printf("The Harmonic Mean is:  %.2f\n", d);
		} else {
			printf("Unable to calculate Harmonic Mean\n");
		}

		ret = pMeanCalc->QuadraticMean(&d);
		if (SUCCEEDED(ret)) {
			printf("The Quadratic Mean is:  %.2f\n", d);
		} else {
			printf("Unable to calculate Quadratic Mean\n");
		}

		pMeanCalc = 0;	// release it
	}
	catch(_com_error& e) {
			dump_com_error(e);
	}
	return 0;
}