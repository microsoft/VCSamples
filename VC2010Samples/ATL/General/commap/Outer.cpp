// Outer.cpp : Implementation of CCOMMapApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "premap.h"
#include "COMMap.h"
#include "Outer.h"


/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP COuter::InterfaceSupportsErrorInfo(REFIID riid)
{
	if (CChainBase::InterfaceSupportsErrorInfo(riid) == S_OK)
		return S_OK;
	if (riid == IID_IOuter)
		return S_OK;
	return S_FALSE;
}

HRESULT COuter::FinalConstruct()
{
	IUnknown* pUnkOuter = GetControllingUnknown();

	HRESULT hRes = CoCreateInstance(CLSID_CAgg, pUnkOuter, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pUnkAgg);
	if (hRes != S_OK)
		return hRes;

	hRes = CoCreateInstance(CLSID_CAggBlind, pUnkOuter, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pUnkAggBlind);
	if (hRes != S_OK)
		return hRes;

	return S_OK;
}

void COuter::FinalRelease()
{
	m_pUnkTearOff2.Release();
	m_pUnkAgg.Release();
	m_pUnkAggBlind.Release();
	m_pUnkAutoAgg.Release();
	m_pUnkAutoAggB.Release();
}

STDMETHODIMP COuter::GetName(short n, BSTR* pbstrName)
{
	switch(n)
	{
	case 0:
			*pbstrName = ::SysAllocString(L"IOuter"); return S_OK;
	case 1:
		{
			CComQIPtr<ITearOff1, &IID_ITearOff1> pITearOff1(GetControllingUnknown());
			if (pITearOff1 != NULL)
				return pITearOff1->get_Name(pbstrName);
			break;
		}
	case 2:
		{
			CComQIPtr<ITearOff2, &IID_ITearOff2> pITearOff2(GetControllingUnknown());
			if (pITearOff2 != NULL)
				return pITearOff2->get_Name(pbstrName);
			break;
		}
	case 3:
		{
			CComQIPtr<IChain, &IID_IChain> pIChain(GetControllingUnknown());
			if (pIChain != NULL)
				return pIChain->get_Name2(pbstrName);
			break;
		}
	case 4:
		{
			CComQIPtr<IAgg, &IID_IAgg> pIAgg(GetControllingUnknown());
			if (pIAgg != NULL)
				return pIAgg->get_Name(pbstrName);
			break;
		}
	case 5:
		{
			CComQIPtr<IAutoAgg, &IID_IAutoAgg> pIAutoAgg(GetControllingUnknown());
			if (pIAutoAgg != NULL)
				return pIAutoAgg->get_Name(pbstrName);
			break;
		}
	case 6:
		{
			CComQIPtr<IAggBlind, &IID_IAggBlind> pIAggBlind(GetControllingUnknown());
			if (pIAggBlind != NULL)
				return pIAggBlind->get_Name(pbstrName);
			break;
		}
	case 7:
		{
			CComQIPtr<IAutoAggB, &IID_IAutoAggB> pIAutoAggB(GetControllingUnknown());
			if (pIAutoAggB != NULL)
				return pIAutoAggB->get_Name(pbstrName);
			break;
		}
	}
	return Error(_T("Interface type out of range"));
}
