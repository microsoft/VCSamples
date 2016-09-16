// CPCDINFO.H : CDInfo manager class proxy declarations
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

//////////////////////////////////////////////////////////////////////////////
// CProxyCDEvents
#include "CDInfoIface.h"
template <class T>
// CPCDINFO.H : proxy class declaration
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

class CProxyCDEvents :
public IConnectionPointImpl<T, &__uuidof(CDEvents), CComDynamicUnkArray>
{
public:
//methods:
//CDEvents : IDispatch
public:
	void Click(
		short nTrack)
	{
		VARIANTARG* pvars = new VARIANTARG[1];
		for (int i = 0; i < 1; i++)
			VariantInit(&pvars[i]);
		T* pT = (T*)this;
		pT->Lock();
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				pvars[0].vt = VT_I2;
				pvars[0].iVal= nTrack;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				IDispatch* pDispatch = reinterpret_cast<IDispatch*>(*pp);
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT,
					DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
			pp++;
		}
		pT->Unlock();
		delete[] pvars;
	}

};
