// DuckInt.h : Declaration of the CDuckInt
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __DUCKINT_H_
#define __DUCKINT_H_

#include "resource.h"       // main symbols

[ dispinterface,
  uuid(78A7BED6-B940-4B38-8261-4E6B4094F9ED),
  helpstring("IDuckInt Interface")
]
__interface IDuckInt : IDispatch
{
	[id(0),helpstring("method Quack")] HRESULT Quack(BSTR szWhosCalling);
	[id(1),helpstring("method Flap")] HRESULT Flap(BSTR szWhosCalling);
	[id(2),helpstring("method Paddle")] HRESULT Paddle(BSTR szWhosCalling);
	[id(3),helpstring("method Walk")] HRESULT Walk(BSTR szWhosCalling);
};

/////////////////////////////////////////////////////////////////////////////
// CDuckInt
[ coclass,
  uuid(B4D60C36-95A0-4EEA-8481-626E8A60AF18),
  helpstring("DuckInt Attrib Class"),
  progid("Atlduck.DuckAttrib.1"),
  vi_progid("Atlduck.DuckAttrib"),
  default("IDuckInt"),
  aggregatable(never),
  event_receiver(com,true)
]
class ATL_NO_VTABLE CDuckInt :
	public IDuckInt
{
public:
	CDuckInt()
	{
	}
	STDMETHOD(Adv)(IUnknown* cp)
	{
		return __hook(IDuckInt,cp);
	}

	STDMETHOD(UnAdv)(IUnknown* cp)
	{
		return __unhook(IDuckInt,cp);
	}

// IDuckInt
public:
	STDMETHOD(Walk)(BSTR szWhosCalling);
	STDMETHOD(Paddle)(BSTR szWhosCalling);
	STDMETHOD(Flap)(BSTR szWhosCalling);
	STDMETHOD(Quack)(BSTR szWhosCalling);
protected:
};

#endif //__DUCKINT_H_
