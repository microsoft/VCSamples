//Copyright (c) Microsoft Corporation.  All rights reserved.
//
// netMeanCalc.cpp
//
// Implements our .net wrapper.  Note that we #import the COM class and export a public
// __gc class that will be consumed by .Net clients.

#include "stdafx.h"
#using <mscorlib.dll>


#import "qstat.dll" raw_interfaces_only

using namespace QStat;

// This class is used as a wrapper to consume the COM object and supply
// that com object pointer to the .net class.
class nativeMeanCalc {
public:
	IMeanCalcPtr pCOMMeanCalc;
	nativeMeanCalc() {
		CoInitialize(NULL);
		pCOMMeanCalc.CreateInstance(__uuidof(CMeanCalc));
	}
	~nativeMeanCalc() {
		CoUninitialize();
	}
};

// netMeanCalc is the class that will ultimately be consumed by .net clients
public __gc class netMeanCalc {
private:
	nativeMeanCalc* pnativeMeanCalc;
public:
	netMeanCalc() {
		pnativeMeanCalc = new nativeMeanCalc;
	}

	BOOL Initialize(short nMaxEntries) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->Initialize(nMaxEntries);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL Clear(void) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->Clear();
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL AddDataPoint(short i) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->AddDataPoint(i);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL ArithmeticMean(double* pArithmeticMean) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->ArithmeticMean(pArithmeticMean);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL GeometricMean(double* pGeometricMean) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->GeometricMean(pGeometricMean);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL HarmonicMean(double* pHarmonicMean) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->HarmonicMean(pHarmonicMean);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	BOOL QuadraticMean(double* pQuadraticMean) {
		HRESULT ret = pnativeMeanCalc->pCOMMeanCalc->QuadraticMean(pQuadraticMean);
		if SUCCEEDED(ret) {
			return TRUE;
		} else {
			return FALSE;
		}
	}

	~netMeanCalc() {
		delete pnativeMeanCalc;
	}
};

