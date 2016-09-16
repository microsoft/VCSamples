//Copyright (c) Microsoft Corporation.  All rights reserved.
//
// MeanCalc.h: defines our ATL object
//

#pragma once
#include "resource.h"       // main symbols


// IMeanCalc
[
	object,
	uuid("9AD3BE25-ABF9-4D0B-BC56-4219FC79BBF8"),
	dual,	helpstring("IMeanCalc Interface"),
	pointer_default(unique)
]
__interface IMeanCalc : IDispatch
{
	[id(1), helpstring("method Initialize")] HRESULT Initialize([in] short nMaxEntries);
	[id(2), helpstring("method Clear")] HRESULT Clear(void);
	[id(3), helpstring("method AddDataPoint")] HRESULT AddDataPoint([in] short i);
	[id(4), helpstring("method ArithmeticMean")] HRESULT ArithmeticMean([out,retval] double* pArithmeticMean);
	[id(5), helpstring("method GeometricMean")] HRESULT GeometricMean([out,retval] double* pGeometricMean);
	[id(6), helpstring("method HarmonicMean")] HRESULT HarmonicMean([out,retval] double* pHarmonicMean);
	[id(7), helpstring("method QuadraticMean")] HRESULT QuadraticMean([out,retval] double* pQuadraticMean);
};



// CMeanCalc

[
	coclass,
	threading(apartment),
	vi_progid("QStat.MeanCalc"),
	progid("QStat.MeanCalc.1"),
	version(1.0),
	uuid("5B8E7812-8AF8-4EC3-A559-5C5011597C6B"),
	helpstring("MeanCalc Class"),
	default(IMeanCalc)
]
class ATL_NO_VTABLE CMeanCalc : 
	public IMeanCalc
{
public:
	CMeanCalc() : pIntArr(NULL)
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	STDMETHOD(Initialize)(short nMaxEntries);
	STDMETHOD(Clear)(void);
	STDMETHOD(AddDataPoint)(short i);
	STDMETHOD(ArithmeticMean)(double* pArithmeticMean);
	STDMETHOD(GeometricMean)(double* pGeometricMean);
	STDMETHOD(HarmonicMean)(double* pHarmonicMean);
	STDMETHOD(QuadraticMean)(double* pQuadraticMean);
private:
	unsigned int nMaxElements;
	unsigned int nElementCount;
	BOOL bIsInitialized;
	int *pIntArr;
};

