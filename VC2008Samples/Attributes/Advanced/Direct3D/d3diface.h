// File: d3diface.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

[ object,
  uuid(1C1B3F56-928B-433E-BE52-3BE2D36E3075),
  dual,
  helpstring("IDirect3DCtl Interface"),
  pointer_default(unique)
]
__interface IDirect3DCtl : IDispatch
{
	HRESULT DisplayScene();
};