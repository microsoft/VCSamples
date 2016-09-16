///////////////////////////////////////////////////////////////////////////////////
// IDrawServ : IDispatch (Dual)
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

template <class T>
class CProxyIDrawServ :
	public IConnectionPointImpl<T, &IID_IDrawServ, CComDynamicUnkArray>
{
public:
//  CProxyIDrawServ(IConnectionPointContainer* pCont) :
//      CComConnectionPoint< CComDynamicArrayCONNECTDATA >(pCont, &IID_IDrawServ)
//  {
//  }

public:
	HRESULT Draw(
		long x1, long y1,
		long x2, long y2,
		unsigned long col)
	{
		T* pT = (T*)this;
		pT->Lock();
		HRESULT hr = S_OK;
		IUnknown** pp = m_vec.begin();
		IUnknown** ppEnd = m_vec.end();
		while (pp < ppEnd && hr == S_OK)
		{
			if (*pp != NULL)
			{
				IDrawServ* pIDrawServ = (IDrawServ*)*pp;
				hr = pIDrawServ->Draw(x1, y1, x2, y2, col);
			}
			pp++;
		}
		pT->Unlock();
		return hr;
	}
};
