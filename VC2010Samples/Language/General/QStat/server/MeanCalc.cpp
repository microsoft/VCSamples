//Copyright (c) Microsoft Corporation.  All rights reserved.
//
// MeanCalc.cpp
//
// This is the implementation for our ATL server.
// MeanCalc.cpp : Implementation of CMeanCalc

#include "stdafx.h"
#include "MeanCalc.h"
#define _USE_MATH_DEFINES
#include <math.h>


// CMeanCalc


STDMETHODIMP CMeanCalc::Initialize(short nMaxEntries)
{
	this->nMaxElements = nMaxEntries;		// maximum number of entries possible
	this->nElementCount = 0;				// current count of elements
	if(this->pIntArr) {
		delete [] this->pIntArr;						// yes, delete old array
	}
	this->pIntArr = new int[this->nMaxElements];	// allocate array for data entry
	if (this->pIntArr != 0) {						// out of memory?
		this->bIsInitialized = TRUE;						// no, ready
	} else {											// yes, fail
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP CMeanCalc::Clear(void)
{
	this->nElementCount = 0;		// reset element count
	return S_OK;
}

STDMETHODIMP CMeanCalc::AddDataPoint(short i)
{
	if ( (this->nMaxElements) > this->nElementCount ) {
		pIntArr[nElementCount++] = i;
	} else {
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP CMeanCalc::ArithmeticMean(double* pArithmeticMean)
{
	if (this->nElementCount == 0) {
		return E_FAIL;
	}
	double Accum = 0;
	for (unsigned int i = 0; i < this->nElementCount; i++) {
		Accum += pIntArr[i];
	}
	*pArithmeticMean = Accum / this->nElementCount;
	return S_OK;
}

STDMETHODIMP CMeanCalc::GeometricMean(double* pGeometricMean)
{
	if (this->nElementCount == 0) {
		return E_FAIL;
	}
	// calculate ln GM, then calc GM from that ( e^ln(GM) )
	double LogGM = 0;
	double Accum = 0;
	// ln GM = 1/n SUMM(ln x)
	for (unsigned int i = 0; i < this->nElementCount; i++) {
		if (pIntArr[i] <= 0) {
			*pGeometricMean = 0;
			return E_FAIL;
		}
		Accum += log((double) pIntArr[i]);
	}
	LogGM = Accum / (double) this->nElementCount;

	*pGeometricMean = pow(M_E,LogGM);
	return S_OK;
}

STDMETHODIMP CMeanCalc::HarmonicMean(double* pHarmonicMean)
{
	if (this->nElementCount == 0) {
		return E_FAIL;
	}
	double Accum = 0;
	for (unsigned int i = 0; i < this->nElementCount; i++) {
		if (pIntArr[i] == 0) {	// to avoid divide by zero
			*pHarmonicMean = 0;
			return E_FAIL;
		}
		else {
			Accum += ((double) 1 / (double) pIntArr[i]);
		}
	}
	*pHarmonicMean = (double) (this->nElementCount) / Accum;
	return S_OK;
}

STDMETHODIMP CMeanCalc::QuadraticMean(double* pQuadraticMean)
{
	if (this->nElementCount == 0) {
		return E_FAIL;
	}
	double Accum = 0;
	for (unsigned int i = 0; i < this->nElementCount; i++) {
		Accum+=( (double) pIntArr[i] * (double) pIntArr[i]);
	}
	*pQuadraticMean = sqrt((Accum / (double) this->nElementCount));
	return S_OK;
}
