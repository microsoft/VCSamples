// cpduck.h: Declaration of CProxyIDuckInt
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef _INC_CPDUCK_H
#define _INC_CPDUCK_H

#include "iduckint.h"
extern const IID IID_IDuckInt;
//////////////////////////////////////////////////////////////////////////////
// CProxyIDuckInt
template <class T>
class CProxyIDuckInt : public IConnectionPointImpl<T, &IID_IDuckInt, CComDynamicUnkArray>
{
public:

//IDuckInt : IUnknown
public:
	HRESULT Fire_Quack(
		BSTR szWhosCalling)
	{
		int n = 1;
		WCHAR* pch = szWhosCalling;
		while (*pch != L'X')
			pch++;

		T* pT = (T*)this;
		pT->Lock();
		HRESULT ret = S_OK;
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				*pch = (WCHAR)((n / 10) + L'0');
				*(pch + 1)= (WCHAR)((n % 10) + L'0');
				n++;

				IDuckInt* pIDuckInt = reinterpret_cast<IDuckInt*>(*pp);
				ret = pIDuckInt->Quack(szWhosCalling);
			}
			pp++;
		}
		pT->Unlock();
		return ret;
	}
	HRESULT Fire_Flap(
		BSTR szWhosCalling)
	{
		int n = 1;
		WCHAR* pch = szWhosCalling;
		while (*pch != L'X')
			pch++;

		T* pT = (T*)this;
		pT->Lock();
		HRESULT ret = S_OK;
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				*pch = (WCHAR)((n / 10) + L'0');
				*(pch + 1)= (WCHAR)((n % 10) + L'0');
				n++;

				IDuckInt* pIDuckInt = reinterpret_cast<IDuckInt*>(*pp);
				ret = pIDuckInt->Flap(szWhosCalling);
			}
			pp++;
		}
		pT->Unlock();
		return ret;
	}
	HRESULT Fire_Paddle(
		BSTR szWhosCalling)
	{
		int n = 1;
		WCHAR* pch = szWhosCalling;
		while (*pch != L'X')
			pch++;

		T* pT = (T*)this;
		pT->Lock();
		HRESULT ret = S_OK;
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				*pch = (WCHAR)((n / 10) + L'0');
				*(pch + 1)= (WCHAR)((n % 10) + L'0');
				n++;

				IDuckInt* pIDuckInt = reinterpret_cast<IDuckInt*>(*pp);
				ret = pIDuckInt->Paddle(szWhosCalling);
			}
			pp++;
		}
		pT->Unlock();
		return ret;
	}
	HRESULT Fire_Walk(
		BSTR szWhosCalling)
	{
		int n = 1;
		WCHAR* pch = szWhosCalling;
		while (*pch != L'X')
			pch++;

		T* pT = (T*)this;
		pT->Lock();
		HRESULT ret = S_OK;
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				*pch = (WCHAR)((n / 10) + L'0');
				*(pch + 1)= (WCHAR)((n % 10) + L'0');
				n++;

				IDuckInt* pIDuckInt = reinterpret_cast<IDuckInt*>(*pp);
				ret = pIDuckInt->Walk(szWhosCalling);
			}
			pp++;
		}
		pT->Unlock();
		return ret;
	}
};

#endif
