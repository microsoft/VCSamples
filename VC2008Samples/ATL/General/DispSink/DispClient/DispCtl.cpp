// DispCtl.cpp : Implementation of CDispCtl
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "DispClient.h"
#include "DispCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CDispCtl


STDMETHODIMP CDispCtl::Connect()
{
	if(!m_bConnected){
		HRESULT hr = CoCreateInstance(CLSID_DispServ, NULL, CLSCTX_ALL ,IID_IDispServ, (void **)&m_pIServ);
		AtlGetObjectSourceInterface(m_pIServ, &m_libid, &m_iid, &m_wMajorVerNum, &m_wMinorVerNum);
		hr = DispEventAdvise(m_pIServ, &m_iid); 
		if(hr == S_OK)
		{
			m_bConnected = TRUE;
			SysFreeString(m_OutText.bstrVal);
			m_OutText.bstrVal = SysAllocString(L"Connected");
			FireViewChange();
		}
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CDispCtl::Disconnect()
{
	if(m_bConnected){
		HRESULT hr = DispEventUnadvise(m_pIServ); 
		((IUnknown*)m_pIServ)->Release();
		if(hr == S_OK)
		{
			m_bConnected = FALSE;
			SysFreeString(m_OutText.bstrVal);
			m_OutText.bstrVal = SysAllocString(L"Disconnected");
			FireViewChange();
		}
		return hr;
	}
	return S_OK;
}

STDMETHODIMP CDispCtl::Send(VARIANT data)
{
	if(m_bConnected) m_pIServ->Send(data);
	return S_OK;
}

STDMETHODIMP CDispCtl::OnTransmit(VARIANT data)
{
	if(data.vt == VT_BSTR)
	{
		VariantClear(&m_OutText);
		HRESULT hr = VariantCopy(&m_OutText, &data);
		if (hr != S_OK)
		{
			return hr;
		}
	}
	FireViewChange();
	return S_OK;
}