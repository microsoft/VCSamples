// File: AggregIface.h
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
	uuid("C38266AF-50F3-40B1-82D8-4AAF5EDA1BC7"),
	dual,
	helpstring("IAgg Interface"),
	pointer_default(unique)
]
__interface IAgg : IDispatch
{
	[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
};

[
	object,
	uuid("0A0DDEDC-C422-4BB3-9869-4FED020B66C5"),
	dual,
	helpstring("IAggBlind Interface"),
	pointer_default(unique)
]
__interface IAggBlind : IDispatch
{
	[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
};

[
	object,
	uuid("2D12F117-2C91-4385-A0E4-2E8E690C5EDF"),
	dual,
	helpstring("IAutoAgg Interface"),
	pointer_default(unique)
]
__interface IAutoAgg : IDispatch
{
	[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
};

[
	object,
	uuid("5F77FE09-2289-4C0C-B435-9EDEE7FECEC8"),
	dual,
	helpstring("IAutoAggB Interface"),
	pointer_default(unique)
]
__interface IAutoAggB : IDispatch
{
	[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
};