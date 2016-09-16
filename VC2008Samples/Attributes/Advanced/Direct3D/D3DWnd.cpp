// d3dwnd.cpp : implementation of CDirect3DWindow & CD3DMatrix
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "d3dwnd.h"


// Globals used for selecting the Direct3D device. They are
// globals as it makes it easy for the enumeration callback
// to read and write from them.
BOOL          fDeviceFound              = FALSE;
DWORD         dwDeviceBitDepth          = 0UL;
GUID          guidDevice;
char          szDeviceName[MAX_DEVICE_NAME];
char          szDeviceDesc[MAX_DEVICE_DESC];
D3DDEVICEDESC d3dHWDeviceDesc;
D3DDEVICEDESC d3dSWDeviceDesc;

CDirect3DWindow::CDirect3DWindow() :
	d3dWorldMatrix(
		D3DVAL( 1.0), D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 1.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 1.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 1.0)),
	d3dViewMatrix(
		D3DVAL( 1.0), D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 1.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 1.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 5.0), D3DVAL( 1.0)),
	d3dProjMatrix(
		D3DVAL( 2.0), D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 2.0), D3DVAL( 0.0), D3DVAL( 0.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL( 1.0), D3DVAL( 1.0),
		D3DVAL( 0.0), D3DVAL( 0.0), D3DVAL(-1.0), D3DVAL( 0.0))
{
	m_bShuttingDown = FALSE;
	m_bIsSuspended  = FALSE;
	m_bIsActive     = TRUE;
	m_bDebug        = FALSE;

	// DirectDraw interfaces
	lpdd                      = NULL;
	lpddPrimary               = NULL;
	lpddDevice                = NULL;
	lpddZBuffer               = NULL;
	lpddPalette               = NULL;

	// Direct3D interfaces
	lpd3d                     = NULL;
	lpd3dDevice               = NULL;
	lpd3dMaterial             = NULL;
	lpd3dBackgroundMaterial   = NULL;
	lpd3dViewport             = NULL;
	lpd3dLight                = NULL;
	lpd3dExecuteBuffer        = NULL;

	// Direct3D handles
	hd3dWorldMatrix           = 0UL;
	hd3dViewMatrix            = 0UL;
	hd3dProjMatrix            = 0UL;
	hd3dSurfaceMaterial       = 0UL;
	hd3dBackgroundMaterial    = 0UL;

	m_dAngleOfRotation = 0.0;
}
