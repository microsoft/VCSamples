//Copyright (c) Microsoft Corporation.  All rights reserved.
//
// netClient.cpp
//
// Implements our .net client

#include "stdafx.h"
typedef int BOOL;
const int TRUE = 1;
const int FALSE = 0;

#using <mscorlib.dll>
using namespace System;

#using "netQStat.dll"

// This is the entry point for this application
#ifdef _UNICODE
int wmain(void)
#else
int main(void)
#endif
{
	netMeanCalc^ pnetMeanCalc = gcnew netMeanCalc;
	pnetMeanCalc->Initialize(1000);

	for (short k = 1; k <= 10; k++) {
		pnetMeanCalc->AddDataPoint(k);
	}

	double nArithmeticMean = 0;
	double nGeometricMean = 0;
	double nHarmonicMean = 0;
	double nQuadraticMean = 0;
	
	BOOL ret;

	ret = pnetMeanCalc->ArithmeticMean(&nArithmeticMean);
	if (ret == TRUE) {
		Console::Write("The Arithmetic Mean is: ");
		Console::WriteLine(nArithmeticMean.ToString("n2"));
	} else {
		Console::WriteLine("Unable to calculate Arithmetic Mean");
	}
	
	ret = pnetMeanCalc->GeometricMean(&nGeometricMean);
	if (ret == TRUE) {
		Console::Write("The Geometric Mean is: ");
		Console::WriteLine(nGeometricMean.ToString("n2"));
	} else {
		Console::WriteLine("Unable to calculate Geometric Mean");
	}
	
	ret = pnetMeanCalc->HarmonicMean(&nHarmonicMean);
	if (ret == TRUE) {
		Console::Write("The Harmonic Mean is: ");
		Console::WriteLine(nHarmonicMean.ToString("n2"));
	} else {
		Console::WriteLine("Unable to calculate Harmonic Mean");
	}

	ret = pnetMeanCalc->QuadraticMean(&nQuadraticMean);
	if (ret == TRUE) {
		Console::Write("The Quadratic Mean is: ");
		Console::WriteLine(nQuadraticMean.ToString("n2"));
	} else {
		Console::WriteLine("Unable to calculate Quadratic Mean");
	}

	return 0;
}