// File: PolygonIface.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once
[
	object,
	uuid("38CA75B5-7047-4E70-93F8-6597FD98C535"),
	dual,
	helpstring("IPolyCtl Interface"),
	pointer_default(unique)
]
__interface IPolyCtl : IDispatch
{
	[propput, id(DISPID_FILLCOLOR)]
	HRESULT FillColor([in]OLE_COLOR clr);
	[propget, id(DISPID_FILLCOLOR)]
	HRESULT FillColor([out, retval]OLE_COLOR* pclr);
	[propget, id(1), helpstring("property Sides")] HRESULT Sides([out, retval] short *pVal);
	[propput, id(1), helpstring("property Sides")] HRESULT Sides([in] short newVal);
};

[
	dispinterface,
	uuid(5284604A-3160-4FAE-A564-6E6A3372CA1A),
	helpstring("_IPolyCtlEvents Interface")
]
__interface _IPolyCtlEvents: IDispatch
{
	[id(1), helpstring("method ClickIn")] void ClickIn([in] long x, [in] long y);
	[id(2), helpstring("method ClickOut")] void ClickOut([in] long x, [in] long y );
};