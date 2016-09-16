// cpevent.h : proxy for circ events
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
// CProxy_CircEvents

template <class T>
class CProxy_CircEvents : public IConnectionPointImpl<T, &DIID__CircEvents, CComDynamicUnkArray>
{
public:
	void Fire_Click()
	{
		// Dispatch ID : 0x1
		T* pT = static_cast<T*>(this);
		int i;
		int nConnections = m_vec.GetSize();

		for (i = 0; i < nConnections; i++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(i);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { NULL, NULL, 0, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}

	}
	void Fire_KeyPress(short KeyAscii)
	{
		// Dispatch ID : 0x2
		T* pT = static_cast<T*>(this);
		int i;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();

		for (i = 0; i < nConnections; i++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(i);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0].vt = VT_I2;
				pvars[0].iVal= KeyAscii;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;

	}
};
