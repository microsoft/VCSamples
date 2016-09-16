// DrawObj.h : Declaration of the CDrawObj
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "drawres.h"       // main symbols
#include "CPIDServ.h"

/////////////////////////////////////////////////////////////////////////////
// DrawServ

class CDrawObj :
	public IDispatchImpl<IDrawServ, &IID_IDrawServ, &LIBID_DRAWSERVLib>,
	public IConnectionPointContainerImpl<CDrawObj>,
	public CProxyIDrawServ<CDrawObj>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CDrawObj,&CLSID_CDrawServ>
{
public:
	DECLARE_CLASSFACTORY_SINGLETON(CDrawObj);

BEGIN_COM_MAP(CDrawObj)
	COM_INTERFACE_ENTRY2(IDispatch,IDrawServ)
	COM_INTERFACE_ENTRY(IDrawServ)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CDrawObj)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

BEGIN_CONNECTION_POINT_MAP(CDrawObj)
	CONNECTION_POINT_ENTRY(IID_IDrawServ)
END_CONNECTION_POINT_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_DrawServ1)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IDrawServ
public:
	STDMETHOD(Draw)(
		long x1, long y1,
		long x2, long y2,
		unsigned long col)
	{
		return CProxyIDrawServ<CDrawObj>::Draw(x1, y1, x2, y2, col);
	}
};
