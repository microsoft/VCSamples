// Random.cpp : Implementation of CConnectApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "preconn.h"
#include "Connect.h"
#include "Random.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CRandom::InterfaceSupportsErrorInfo(REFIID riid)
{
	if (riid == IID_IRandom)
		return S_OK;
	return S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
//

DWORD WINAPI RandomSessionThreadEntry(void* pv)
{
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	CRandom::RandomSessionData* pS = (CRandom::RandomSessionData*)pv;
	CRandom* p = pS->pRandom;
	while (WaitForSingleObject(pS->m_hEvent, 0) != WAIT_OBJECT_0)
		p->Fire(pS->m_nID);
	
	CoUninitialize();
	return 0;
}

CRandom::~CRandom()
{
	StopAll();
}

void CRandom::CreateRandomSession(RandomSessionData& rs)
{
	DWORD dwThreadID = 0;
	ATLASSERT(rs.m_hEvent == NULL);
	ATLASSERT(rs.m_hThread == NULL);
	rs.pRandom = this;
	rs.m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	rs.m_hThread = CreateThread(NULL, 0, &RandomSessionThreadEntry, &rs, 0, &dwThreadID);
}

STDMETHODIMP CRandom::Start(long* pnID)
{
	if (pnID == NULL)
		return E_POINTER;
	*pnID = 0;
	HRESULT hRes = S_OK;
	m_cs.Lock();
	long i;
	for (i=0;i<nMaxSessions;i++)
	{
		if (m_rsArray[i].m_hEvent == NULL)
		{
			m_rsArray[i].m_nID = i;
			CreateRandomSession(m_rsArray[i]);
			*pnID = i;
			break;
		}
	}
	if (i == nMaxSessions) //fell through
		hRes = E_FAIL;
	m_cs.Unlock();
	return hRes;
}


STDMETHODIMP CRandom::Stop(long nID)
{
	HRESULT hRes = S_OK;
	m_cs.Lock();
	if (m_rsArray[nID].m_hEvent != NULL)
	{
		SetEvent(m_rsArray[nID].m_hEvent);
		WaitForSingleObject(m_rsArray[nID].m_hThread, INFINITE);
		CloseHandle(m_rsArray[nID].m_hThread);
		memset(&m_rsArray[nID], 0, sizeof(RandomSessionData));
	}
	else
		hRes = E_INVALIDARG;
	m_cs.Unlock();
	return hRes;
}

STDMETHODIMP CRandom::StopAll()
{
	m_cs.Lock();
	for (long i=0;i<nMaxSessions;i++)
	{
		if (m_rsArray[i].m_hEvent != NULL)
		{
			SetEvent(m_rsArray[i].m_hEvent);
			WaitForSingleObject(m_rsArray[i].m_hThread, INFINITE);
			CloseHandle(m_rsArray[i].m_hThread);
			memset(&m_rsArray[i], 0, sizeof(RandomSessionData));
		}
	}
	m_cs.Unlock();
	return S_OK;
}

// broadcast to all the objects
HRESULT CRandom::Fire(long nID)
{
	IConnectionPointImpl<CRandom, &IID_IRandomEvent, CComDynamicUnkArray>* p = this;
	Lock();
	HRESULT hr = S_OK;
	IUnknown** pp = p->m_vec.begin();
	while (pp < p->m_vec.end() && hr == S_OK)
	{
		if (*pp != NULL)
		{
			IRandomEvent* pIRandomEvent = (IRandomEvent*)*pp;
			hr = pIRandomEvent->Fire(nID);
		}
		pp++;
	}
	Unlock();
	return hr;
}
