// File: COMMapIface.h
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
		uuid("A2FFAC63-301D-48A0-BC0A-9B4954112E0C"),
		dual,
		helpstring("IOuter Interface"),
		pointer_default(unique)
	]
	__interface IOuter : IDispatch
	{
		HRESULT GetName([in] short n, [out, retval] BSTR* pbstrName);
	};

	[
		object,
		uuid("DFF2676C-9DFA-4E89-A73A-6707AEE93936"),
		dual,
		helpstring("ITearOff1 Interface"),
		pointer_default(unique)
	]
	__interface ITearOff1 : IDispatch
	{
		[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
	};

	[
		object,
		uuid("DC9000DA-F6B4-44C1-BF3C-75C28DE5F993"),
		dual,
		helpstring("ITearOff2 Interface"),
		pointer_default(unique)
	]
	__interface ITearOff2 : IDispatch
	{
		[propget, id(0)] HRESULT Name([out, retval] BSTR* pbstrName);
	};


	[
		object,
		uuid("DCCD0C8A-7C0D-4FA2-A9CA-719219A51F45"),
		dual,
		helpstring("IChain Interface"),
		pointer_default(unique)
	]
	__interface IChain : IDispatch
	{
		[propget, id(0)] HRESULT Name2([out, retval] BSTR* pbstrName);
	};
