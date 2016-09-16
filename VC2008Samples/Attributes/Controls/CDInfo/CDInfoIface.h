// File: CDInfoIface.h
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
	uuid("CD73CB20-85C3-4B0B-A1D4-EBB911AF3E68"),
	dual,
	helpstring("ICDInfo Interface"),
	pointer_default(unique)
]
__interface ICDInfo : IDispatch
{

	[propget, id(0)] HRESULT Tracks([out, retval] short* pTracks);
	[propput, id(0)] HRESULT Tracks([in] short Tracks);
	[propget, id(1)] HRESULT Length([in] short Track, [out, retval] short* pLength);
	[propput, id(1)] HRESULT Length([in] short Track, [in] short nLength);
	[propget, id(2)] HRESULT TotalLength([out, retval] short* pLength);
	HRESULT	Read([out, retval] short* pTracks);
	HRESULT Redraw();
	HRESULT Play([in] short Track);
};

[	dispinterface,
	uuid("7A4C656C-EDC3-45FE-84CE-0D7C96C45B85"),
	helpstring("Event interface for CDInfo Control")
]
__interface CDEvents: IDispatch
{
	[id(1)] void Click([in] short nTrack);
};