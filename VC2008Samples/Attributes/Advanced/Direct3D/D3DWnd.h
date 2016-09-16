// D3DWnd.h : Declaration of CDirect3DWindow & CD3DMatrix
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include <math.h>
#include <ddraw.h>
#include "initguid.h"
#include <d3d.h>

#include "resource.h"


/***********************************************************************
 *
 * Constants
 *
 ***********************************************************************/

/*
 * Half height of the view window.
 */
#define HALF_HEIGHT           D3DVAL(0.5)

/*
 * Front and back clipping planes.
 */
#define FRONT_CLIP            D3DVAL(1.0)
#define BACK_CLIP             D3DVAL(1000.0)

#define MAX_DEVICE_NAME       256
#define MAX_DEVICE_DESC       256

/*
 * Amount to rotate per frame.
 */
#ifndef M_PI
#define M_PI                  3.14159265359
#endif
#define M_2PI                 6.28318530718
#define ROTATE_ANGLE_DELTA    (M_2PI / 150.0)

/*
 * Execute buffer contents
 */
#define NUM_VERTICES          3UL
#define NUM_INSTRUCTIONS      6UL
#define NUM_STATES            8UL
#define NUM_PROCESSVERTICES   1UL
#define NUM_TRIANGLES         1UL

/***********************************************************************
 *
 * Macro funtions.
 *
 ***********************************************************************/

/*
 * Extract the error code from an HRESULT
 */
#define CODEFROMHRESULT(hRes) ((hRes) & 0x0000FFFFUL)

/*
 * Globals used for selecting the Direct3D device. They are
 * globals as it makes it easy for the enumeration callback
 * to read and write from them.
 */
extern BOOL          fDeviceFound;
extern DWORD         dwDeviceBitDepth;
extern GUID          guidDevice;
extern char          szDeviceName[MAX_DEVICE_NAME];
extern char          szDeviceDesc[MAX_DEVICE_DESC];
extern D3DDEVICEDESC d3dHWDeviceDesc;
extern D3DDEVICEDESC d3dSWDeviceDesc;


class CD3DMatrix : public _D3DMATRIX
{
public:
	CD3DMatrix(
		D3DVALUE v11, D3DVALUE v12, D3DVALUE v13, D3DVALUE v14,
		D3DVALUE v21, D3DVALUE v22, D3DVALUE v23, D3DVALUE v24,
		D3DVALUE v31, D3DVALUE v32, D3DVALUE v33, D3DVALUE v34,
		D3DVALUE v41, D3DVALUE v42, D3DVALUE v43, D3DVALUE v44)
	{
		_11 = v11;
		_12 = v12;
		_13 = v13;
		_14 = v14;
		_21 = v21;
		_22 = v22;
		_23 = v23;
		_24 = v24;
		_31 = v31;
		_32 = v32;
		_33 = v33;
		_34 = v34;
		_41 = v41;
		_42 = v42;
		_43 = v43;
		_44 = v44;
	}
};

class CDirect3DWindow
{
public:
	CDirect3DWindow();

	~CDirect3DWindow()
	{
		// Clean everything up.
		ReleaseScene();
		ReleaseDevice();
		ReleasePrimary();
		ReleaseDirect3D();
	}

	void ReportError(HWND hwnd, LPSTR lpszMessage, HRESULT hRes)
	{
		TCHAR szBuffer[256];
		TCHAR szError[128];
		int  nStrID;

		// Turn the animation loop off.
		m_bIsSuspended = TRUE;

		// We issue sensible error messages for common run time errors. For
		// errors which are internal or coding errors we simply issue an
		// error number (they should never occur).
		switch (hRes)
		{
			case DDERR_EXCEPTION:        nStrID = IDS_ERR_EXCEPTION;        break;
			case DDERR_GENERIC:          nStrID = IDS_ERR_GENERIC;          break;
			case DDERR_OUTOFMEMORY:      nStrID = IDS_ERR_OUTOFMEMORY;      break;
			case DDERR_OUTOFVIDEOMEMORY: nStrID = IDS_ERR_OUTOFVIDEOMEMORY; break;
			case DDERR_SURFACEBUSY:      nStrID = IDS_ERR_SURFACEBUSY;      break;
			case DDERR_SURFACELOST:      nStrID = IDS_ERR_SURFACELOST;      break;
			case DDERR_WRONGMODE:        nStrID = IDS_ERR_WRONGMODE;        break;
			default:                     nStrID = IDS_ERR_INTERNALERROR;    break;
		}
		LoadString(_pModule->GetResourceInstance(), nStrID, szError, sizeof(szError));

		// Convert the error code into a string.
		_stprintf_s(szBuffer, 256, _T("%s\n%s (Error #%d)"), lpszMessage, szError, CODEFROMHRESULT(hRes));
		MessageBox(hwnd, szBuffer, _T(""), MB_OK | MB_APPLMODAL);
	}

	/***********************************************************************/

	void FatalError(HWND hwnd, LPSTR lpszMessage, HRESULT hRes)
	{
		// Report the error.
		ReportError(hwnd, lpszMessage, hRes);

		// And shut down.
		// NOTE: We don't attempt to clean up. That will be done
		// in the destructor
		m_bShuttingDown = TRUE;
	}

	/***********************************************************************/

	DWORD BitDepthToFlags(DWORD dwBitDepth)
	{
		switch (dwBitDepth)
		{
			case  1UL: return DDBD_1;
			case  2UL: return DDBD_2;
			case  4UL: return DDBD_4;
			case  8UL: return DDBD_8;
			case 16UL: return DDBD_16;
			case 24UL: return DDBD_24;
			case 32UL: return DDBD_32;
			default:   return 0UL;
		}
	}

	/***********************************************************************/

	/*
	 * Convert bit depth flags to an acutal bit count. Selects the smallest
	 * bit count in the mask if more than one flag is present.
	 */
	DWORD FlagsToBitDepth(DWORD dwFlags)
	{
		if (dwFlags & DDBD_1)
			return 1UL;
		else if (dwFlags & DDBD_2)
			return 2UL;
		else if (dwFlags & DDBD_4)
			return 4UL;
		else if (dwFlags & DDBD_8)
			return 8UL;
		else if (dwFlags & DDBD_16)
			return 16UL;
		else if (dwFlags & DDBD_24)
			return 24UL;
		else if (dwFlags & DDBD_32)
			return 32UL;
		else
			return 0UL; /* Oh, please... */
	}

	/***********************************************************************/

	void SetPerspectiveProjection(LPD3DMATRIX lpd3dMatrix,
							 double      dHalfHeight,
							 double      dFrontClipping,
							 double      dBackClipping)
	{
		double dTmp1;
		double dTmp2;

		ATLENSURE(NULL != lpd3dMatrix);

		dTmp1 = dHalfHeight / dFrontClipping;
		dTmp2 = dBackClipping / (dBackClipping - dFrontClipping);

		lpd3dMatrix->_11 =  D3DVAL(2.0);
		lpd3dMatrix->_12 =  D3DVAL(0.0);
		lpd3dMatrix->_13 =  D3DVAL(0.0);
		lpd3dMatrix->_14 =  D3DVAL(0.0);
		lpd3dMatrix->_21 =  D3DVAL(0.0);
		lpd3dMatrix->_22 =  D3DVAL(2.0);
		lpd3dMatrix->_23 =  D3DVAL(0.0);
		lpd3dMatrix->_24 =  D3DVAL(0.0);
		lpd3dMatrix->_31 =  D3DVAL(0.0);
		lpd3dMatrix->_32 =  D3DVAL(0.0);
		lpd3dMatrix->_33 =  D3DVAL(dTmp1 * dTmp2);
		lpd3dMatrix->_34 =  D3DVAL(dTmp1);
		lpd3dMatrix->_41 =  D3DVAL(0.0);
		lpd3dMatrix->_42 =  D3DVAL(0.0);
		lpd3dMatrix->_43 =  D3DVAL(-dHalfHeight * dTmp2);
		lpd3dMatrix->_44 =  D3DVAL(0.0);
	}


	/***********************************************************************/

	void SetRotationAboutY(LPD3DMATRIX lpd3dMatrix, double dAngleOfRotation)
	{
		D3DVALUE dvCos;
		D3DVALUE dvSin;

		ATLENSURE(NULL != lpd3dMatrix);

		dvCos = D3DVAL(cos(dAngleOfRotation));
		dvSin = D3DVAL(sin(dAngleOfRotation));

		lpd3dMatrix->_11 =  dvCos;
		lpd3dMatrix->_12 =  D3DVAL(0.0);
		lpd3dMatrix->_13 = -dvSin;
		lpd3dMatrix->_14 =  D3DVAL(0.0);
		lpd3dMatrix->_21 =  D3DVAL(0.0);
		lpd3dMatrix->_22 =  D3DVAL(1.0);
		lpd3dMatrix->_23 =  D3DVAL(0.0);
		lpd3dMatrix->_24 =  D3DVAL(0.0);
		lpd3dMatrix->_31 =  dvSin;
		lpd3dMatrix->_32 =  D3DVAL(0.0);
		lpd3dMatrix->_33 =  dvCos;
		lpd3dMatrix->_34 =  D3DVAL(0.0);
		lpd3dMatrix->_41 =  D3DVAL(0.0);
		lpd3dMatrix->_42 =  D3DVAL(0.0);
		lpd3dMatrix->_43 =  D3DVAL(0.0);
		lpd3dMatrix->_44 =  D3DVAL(1.0);
	}

	/***********************************************************************/

	HRESULT CreateDirect3D(HWND hwnd)
	{
		HRESULT hRes;

		ATLENSURE(NULL == lpdd);
		ATLENSURE(NULL == lpd3d);

		hRes = DirectDrawCreate(NULL, &lpdd, NULL);
		if (FAILED(hRes))
			return hRes;

		hRes = lpdd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
		if (FAILED(hRes))
			return hRes;

		hRes = lpdd->QueryInterface(IID_IDirect3D, (void**)&lpd3d);
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT ReleaseDirect3D(void)
	{
		if (NULL != lpd3d)
		{
			lpd3d->Release();
			lpd3d = NULL;
		}
		if (NULL != lpdd)
		{
			lpdd->Release();
			lpdd = NULL;
		}

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT CreatePrimary(HWND hwnd)
	{
		HRESULT             hRes;
		DDSURFACEDESC       ddsd;
		LPDIRECTDRAWCLIPPER lpddClipper;
		HDC                 hdc;
		int                 i;
		PALETTEENTRY        peColorTable[256];

		ATLENSURE(NULL != hwnd);
		ATLENSURE(NULL != lpdd);
		ATLENSURE(NULL == lpddPrimary);
		ATLENSURE(NULL == lpddPalette);

		/*
		 * Create the primary surface.
		 */
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize         = sizeof(ddsd);
		ddsd.dwFlags        = DDSD_CAPS;
		ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		hRes = lpdd->CreateSurface(&ddsd, &lpddPrimary, NULL);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Create the clipper. We bind the application's window to the
		 * clipper and attach it to the primary. This ensures then when we
		 * blit from the rendering surface to the primary we don't write
		 * outside the visible region of the window.
		 */
		hRes = DirectDrawCreateClipper(0UL, &lpddClipper, NULL);
		if (FAILED(hRes))
			return hRes;
		hRes = lpddClipper->SetHWnd(0UL, hwnd);
		if (FAILED(hRes))
		{
			lpddClipper->Release();
			return hRes;
		}
		hRes = lpddPrimary->SetClipper(lpddClipper);
		if (FAILED(hRes))
		{
			lpddClipper->Release();
			return hRes;
		}

		/*
		 * We release the clipper interface after attaching it to the surface
		 * as we don't need to use it again and the surface holds a reference
		 * to the clipper when its been attached. The clipper will therefore
		 * be released when the surface is released.
		 */
		lpddClipper->Release();

		/*
		 * If the primary is palettized then so will the rendering target (we
		 * ensure the rendering target has the same pixel format as the primary
		 * for optimal performance). Hence, if the primary is palettized we
		 * need to create a palette and attach it to the primary (and eventually
		 * to the rendering target).
		 *
		 * NOTE: We don't initialize the color table of the palette. We leave
		 * that upto Direct3D.
		 */
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		hRes = lpddPrimary->GetSurfaceDesc(&ddsd);
		if (FAILED(hRes))
			return hRes;
		if (ddsd.ddpfPixelFormat.dwFlags & DDPF_PALETTEINDEXED8)
		{
			/*
			 * The primary is palettized so create a palette and attach it to
			 * the primary.
			 */
			hdc = GetDC(NULL);
			GetSystemPaletteEntries(hdc, 0, 256, peColorTable);
			ReleaseDC(NULL, hdc);
			for (i = 0; i < 10; i++)
				peColorTable[i].peFlags = D3DPAL_READONLY;
			for (i = 10; i < 246; i++)
				peColorTable[i].peFlags = D3DPAL_FREE | PC_RESERVED;
			for (i = 246; i < 256; i++)
				peColorTable[i].peFlags = D3DPAL_READONLY;
			hRes = lpdd->CreatePalette(DDPCAPS_8BIT,
									   peColorTable,
									   &lpddPalette,
									   NULL);
			if (FAILED(hRes))
				return hRes;

			hRes = lpddPrimary->SetPalette(lpddPalette);
				return hRes;
		}

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT RestorePrimary(void)
	{
		ATLENSURE(NULL != lpddPrimary);

		return lpddPrimary->Restore();
	}

	/***********************************************************************/

	HRESULT ReleasePrimary(void)
	{
		if (NULL != lpddPalette)
		{
			lpddPalette->Release();
			lpddPalette = NULL;
		}
		if (NULL != lpddPrimary)
		{
			lpddPrimary->Release();
			lpddPrimary = NULL;
		}

		return DD_OK;
	}

	/***********************************************************************/

	static HRESULT WINAPI EnumDeviceCallback(
						LPGUID          lpGUID,
						LPSTR           lpszDeviceDesc,
						LPSTR           lpszDeviceName,
						LPD3DDEVICEDESC lpd3dHWDeviceDesc,
						LPD3DDEVICEDESC lpd3dSWDeviceDesc,
						LPVOID          /* lpUserArg */)
	{
		BOOL            fIsHardware;
		LPD3DDEVICEDESC lpd3dDeviceDesc;

		/*
		 * If there is no hardware support then the color model is zero.
		 */
		fIsHardware     = (0UL != lpd3dHWDeviceDesc->dcmColorModel);
		lpd3dDeviceDesc = (fIsHardware ? lpd3dHWDeviceDesc : lpd3dSWDeviceDesc);


		/*
		 * Does the device render at the depth we want?
		 */
		if (0UL == (lpd3dDeviceDesc->dwDeviceRenderBitDepth & dwDeviceBitDepth))
		{
			/*
			 * No skip this device.
			 */
			return D3DENUMRET_OK;
		}

		/*
		 * The device must support gouraud shaded triangles.
		 */
		if (D3DCOLOR_MONO == lpd3dDeviceDesc->dcmColorModel)
		{
			if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDMONO))
			{
				/*
				 * No gouraud shading. Skip this device.
				 */
				return D3DENUMRET_OK;
			}
		}
		else
		{
			if (!(lpd3dDeviceDesc->dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_COLORGOURAUDRGB))
			{
				/*
				 * No gouraud shading. Skip this device.
				 */
				return D3DENUMRET_OK;
			}
		}

		if (!fIsHardware && fDeviceFound && (D3DCOLOR_RGB == lpd3dDeviceDesc->dcmColorModel))
		{
			/*
			 * If this is software RGB and we already have found a software
			 * mono already then we are not interested. Skip it.
			 */
			return D3DENUMRET_OK;
		}

		/*
		 * This is a device we are interested in. Cache its details away.
		 */
		fDeviceFound = TRUE;
	
		memcpy_s(&guidDevice, sizeof(GUID),lpGUID, sizeof(GUID));


		strcpy_s(szDeviceDesc, MAX_DEVICE_DESC, lpszDeviceDesc);
		strcpy_s(szDeviceName, MAX_DEVICE_NAME, lpszDeviceName);
		memcpy_s(&d3dHWDeviceDesc, sizeof(D3DDEVICEDESC),lpd3dHWDeviceDesc, sizeof(D3DDEVICEDESC));
		memcpy_s(&d3dSWDeviceDesc, sizeof(D3DDEVICEDESC),lpd3dSWDeviceDesc, sizeof(D3DDEVICEDESC));

		/*
		 * If this is a hardware device we have found what we are looking
		 * for.
		 */
		if (fIsHardware)
			return D3DENUMRET_CANCEL;

		/*
		 * Keep going.
		 */
		return D3DENUMRET_OK;
	}

	/***********************************************************************/

	HRESULT ChooseDevice(void)
	{
		DDSURFACEDESC ddsd;
		HRESULT       hRes;

		ATLENSURE(NULL != lpd3d);
		ATLENSURE(NULL != lpddPrimary);

		/*
		 * As we are running in a window we will not be changing the screen
		 * depth and hence the pixel format of the rendering target must match
		 * the pixel format of the current primary. Therefore, we need to
		 * determine the pixel format of the primary.
		 */
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		hRes = lpddPrimary->GetSurfaceDesc(&ddsd);
		if (FAILED(hRes))
			return hRes;

		dwDeviceBitDepth = BitDepthToFlags(ddsd.ddpfPixelFormat.dwRGBBitCount);

		/*
		 * Now we will enumerate the devices and pick the best match. The
		 * criteria for selecting the device are pretty simple. They are
		 * as follows:
		 *
		 * 1) Discard any device which does not support rendering at the
		 *    primary's display depth.
		 * 2) Favour hardware rasterizers over software ones unless we
		 *    are debugging (fDebug == TRUE) in which case we always
		 *    pick a software device.
		 */
		fDeviceFound = FALSE;
		hRes = lpd3d->EnumDevices(EnumDeviceCallback, &fDeviceFound);
		if (FAILED(hRes))
			return hRes;

		if (!fDeviceFound)
		{
			/*
			 * No suitable device was found. We have not alternative but to
			 * fail creation entirely.
			 */
			return DDERR_NOTFOUND;
		}

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT CreateDevice(DWORD dwWidth, DWORD dwHeight)
	{
		LPD3DDEVICEDESC      lpd3dDeviceDesc;
		DWORD                dwDeviceMemType;
		DWORD                dwZBufferMemType;
		DDSURFACEDESC        ddsd;
		HRESULT              hRes;
		DWORD                dwZBufferBitDepth;

		ATLENSURE(NULL != lpdd);
		ATLENSURE(NULL != lpd3d);
		ATLENSURE(NULL != lpddPrimary);
		ATLENSURE(NULL == lpddDevice);

		/*
		 * The first step is to determine the kind of memory (system or
		 * video) from which the rendering target surface should be
		 * allocated.
		 */
		if (0UL != d3dHWDeviceDesc.dcmColorModel)
		{
			lpd3dDeviceDesc = &d3dHWDeviceDesc;

			/*
			 * Device has a hardware rasterizer. Currently this means that
			 * the rendering target must be in video memory.
			 */
			dwDeviceMemType  = DDSCAPS_VIDEOMEMORY;
			dwZBufferMemType = DDSCAPS_VIDEOMEMORY;
		}
		else
		{
			lpd3dDeviceDesc = &d3dSWDeviceDesc;

			/*
			 * Device has a software rasterizer. We will let DirectDraw
			 * decide where the rendering target resides unless we are
			 * running in debug mode in which case we will force it into
			 * system memory. For a software rasterizer the z-buffer should
			 * always go into system memory. A z-buffer in video memory will
			 * kill performance.
			 */
			dwDeviceMemType  = (m_bDebug ? DDSCAPS_SYSTEMMEMORY : 0UL);
			dwZBufferMemType = DDSCAPS_SYSTEMMEMORY;
		}

		/*
		 * Create the rendering target. The pixel format will be identical
		 * to the primary so we don't have to explicitly specify it. We do
		 * need to explicity specify the size, memory type and capabilities
		 * of the surface.
		 */
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize         = sizeof(ddsd);
		ddsd.dwFlags        = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT;
		ddsd.dwWidth        = dwWidth;
		ddsd.dwHeight       = dwHeight;
		ddsd.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_OFFSCREENPLAIN | dwDeviceMemType;
		hRes = lpdd->CreateSurface(&ddsd, &lpddDevice, NULL);
		if (FAILED(hRes))
			return hRes;

		/*
		 * If we have created a palette then we have already determined that
		 * the primary (and hence the rendering target) is palettized so
		 * attach the palette to the back buffer (its already attached to the
		 * front buffer).
		 */
		if (NULL != lpddPalette)
		{
			hRes = lpddDevice->SetPalette(lpddPalette);
			if (FAILED(hRes))
				return hRes;
		}

		/*
		 * We now determine whether we need a z-buffer or not and if so
		 * its depth and the kind of memory from which the z-buffer should
		 * be allocated.
		 */
		if (0UL != lpd3dDeviceDesc->dwDeviceZBufferBitDepth)
		{
			/*
			 * The device supports z-buffering. Determine the depth. We
			 * select the lowest supported z-buffer resolution to save
			 * memory. Accuracy is not too important for this demo.
			 */
			dwZBufferBitDepth = FlagsToBitDepth(lpd3dDeviceDesc->dwDeviceZBufferBitDepth);

			/*
			 * Create the z-buffer.
			 */
			ZeroMemory(&ddsd, sizeof(ddsd));
			ddsd.dwSize            = sizeof(ddsd);
			ddsd.dwFlags           = DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_ZBUFFERBITDEPTH;
			ddsd.ddsCaps.dwCaps    = DDSCAPS_ZBUFFER | dwZBufferMemType;
			ddsd.dwWidth           = dwWidth;
			ddsd.dwHeight          = dwHeight;
			ddsd.dwZBufferBitDepth = dwZBufferBitDepth;
			hRes = lpdd->CreateSurface(&ddsd, &lpddZBuffer, NULL);
			if (FAILED(hRes))
				return hRes;

			/*
			 * Attach it to the rendering target.
			 */
			hRes = lpddDevice->AddAttachedSurface(lpddZBuffer);
			if (FAILED(hRes))
				return hRes;
		}

		/*
		 * Now we can actually get the Direct3D device interface.
		 */
		hRes = lpddDevice->QueryInterface(guidDevice, (void**)&lpd3dDevice);
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT RestoreDevice(void)
	{
		HRESULT hRes;

		ATLENSURE(NULL != lpddZBuffer);
		ATLENSURE(NULL != lpddDevice);

		hRes = lpddZBuffer->Restore();
		if (FAILED(hRes))
			return hRes;

		hRes = lpddDevice->Restore();
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT ReleaseDevice(void)
	{
		if (NULL != lpd3dDevice)
		{
			lpd3dDevice->Release();
			lpd3dDevice = NULL;
		}
		if (NULL != lpddZBuffer)
		{
			lpddZBuffer->Release();
			lpddZBuffer = NULL;
		}
		if (NULL != lpddDevice)
		{
			lpddDevice->Release();
			lpddDevice = NULL;
		}

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT FillExecuteBuffer(void)
	{
		HRESULT              hRes;
		D3DEXECUTEBUFFERDESC d3dExeBufDesc;
		LPD3DVERTEX          lpVertex;
		LPD3DINSTRUCTION     lpInstruction;
		LPD3DPROCESSVERTICES lpProcessVertices;
		LPD3DTRIANGLE        lpTriangle;
		LPD3DSTATE           lpState;

		ATLENSURE(NULL != lpd3dExecuteBuffer);
		ATLENSURE(0UL  != hd3dSurfaceMaterial);
		ATLENSURE(0UL  != hd3dWorldMatrix);
		ATLENSURE(0UL  != hd3dViewMatrix);
		ATLENSURE(0UL  != hd3dProjMatrix);

		/*
		 * Lock the execute buffer.
		 */
		ZeroMemory(&d3dExeBufDesc, sizeof(d3dExeBufDesc));
		d3dExeBufDesc.dwSize = sizeof(d3dExeBufDesc);
		hRes = lpd3dExecuteBuffer->Lock(&d3dExeBufDesc);
		if (FAILED(hRes))
			return hRes;

		lpVertex = (LPD3DVERTEX)d3dExeBufDesc.lpData;

		/*
		 * First vertex.
		 */
		lpVertex->dvX  = D3DVAL( 0.0);
		lpVertex->dvY  = D3DVAL( 1.0);
		lpVertex->dvZ  = D3DVAL( 0.0);
		lpVertex->dvNX = D3DVAL( 0.0);
		lpVertex->dvNY = D3DVAL( 0.0);
		lpVertex->dvNZ = D3DVAL(-1.0);
		lpVertex->dvTU = D3DVAL( 0.0);
		lpVertex->dvTV = D3DVAL( 1.0);
		lpVertex++;

		/*
		 * Second vertex.
		 */
		lpVertex->dvX  = D3DVAL(-1.0);
		lpVertex->dvY  = D3DVAL(-1.0);
		lpVertex->dvZ  = D3DVAL( 0.0); // -0.3
		lpVertex->dvNX = D3DVAL( 0.0);
		lpVertex->dvNY = D3DVAL( 0.0);
		lpVertex->dvNZ = D3DVAL(-1.0);
		lpVertex->dvTU = D3DVAL( 1.0);
		lpVertex->dvTV = D3DVAL( 1.0);
		lpVertex++;

		/*
		 * Third vertex.
		 */
		lpVertex->dvX  = D3DVAL( 1.0);
		lpVertex->dvY  = D3DVAL(-1.0);
		lpVertex->dvZ  = D3DVAL( 0.0); // -0.3
		lpVertex->dvNX = D3DVAL( 0.0);
		lpVertex->dvNY = D3DVAL( 0.0);
		lpVertex->dvNZ = D3DVAL(-1.0);
		lpVertex->dvTU = D3DVAL( 1.0);
		lpVertex->dvTV = D3DVAL( 0.0);
		lpVertex++;
#if 0
		/*
		 * Fourth vertex.
		 */
		lpVertex->dvX  = D3DVAL( 0.0);
		lpVertex->dvY  = D3DVAL(-1.0);
		lpVertex->dvZ  = D3DVAL( 1.044);
		lpVertex->dvNX = D3DVAL( 0.0);
		lpVertex->dvNY = D3DVAL( 0.0);
		lpVertex->dvNZ = D3DVAL(-1.0);
		lpVertex->dvTU = D3DVAL( 1.0);
		lpVertex->dvTV = D3DVAL( 0.0);
		lpVertex++;
#endif
		/*
		 * Transform state - world, view and projection.
		 */
		lpInstruction = (LPD3DINSTRUCTION)lpVertex;
		lpInstruction->bOpcode = D3DOP_STATETRANSFORM;
		lpInstruction->bSize   = sizeof(D3DSTATE);
		lpInstruction->wCount  = 3U;
		lpInstruction++;
		lpState = (LPD3DSTATE)lpInstruction;
		lpState->dtstTransformStateType = D3DTRANSFORMSTATE_WORLD;
		lpState->dwArg[0] = hd3dWorldMatrix;
		lpState++;
		lpState->dtstTransformStateType = D3DTRANSFORMSTATE_VIEW;
		lpState->dwArg[0] = hd3dViewMatrix;
		lpState++;
		lpState->dtstTransformStateType = D3DTRANSFORMSTATE_PROJECTION;
		lpState->dwArg[0] = hd3dProjMatrix;
		lpState++;

		/*
		 * Lighting state.
		 */
		lpInstruction = (LPD3DINSTRUCTION)lpState;
		lpInstruction->bOpcode = D3DOP_STATELIGHT;
		lpInstruction->bSize   = sizeof(D3DSTATE);
		lpInstruction->wCount  = 2U;
		lpInstruction++;
		lpState = (LPD3DSTATE)lpInstruction;
		lpState->dlstLightStateType = D3DLIGHTSTATE_MATERIAL;
		lpState->dwArg[0] = hd3dSurfaceMaterial;
		lpState++;
		lpState->dlstLightStateType = D3DLIGHTSTATE_AMBIENT;
		lpState->dwArg[0] = RGBA_MAKE(128, 128, 128, 128);
		lpState++;

		/*
		 * Render state.
		 */
		lpInstruction = (LPD3DINSTRUCTION)lpState;
		lpInstruction->bOpcode = D3DOP_STATERENDER;
		lpInstruction->bSize = sizeof(D3DSTATE);
		lpInstruction->wCount = 3U;
		lpInstruction++;
		lpState = (LPD3DSTATE)lpInstruction;
		lpState->drstRenderStateType = D3DRENDERSTATE_FILLMODE;
		lpState->dwArg[0] = D3DFILL_SOLID;
		lpState++;
		lpState->drstRenderStateType = D3DRENDERSTATE_SHADEMODE;
		lpState->dwArg[0] = D3DSHADE_GOURAUD;
		lpState++;
		lpState->drstRenderStateType = D3DRENDERSTATE_DITHERENABLE;
		lpState->dwArg[0] = FALSE;
		lpState++;

		lpInstruction = (LPD3DINSTRUCTION)lpState;
		lpInstruction->bOpcode = D3DOP_PROCESSVERTICES;
		lpInstruction->bSize   = sizeof(D3DPROCESSVERTICES);
		lpInstruction->wCount  = 1U;
		lpInstruction++;
		lpProcessVertices = (LPD3DPROCESSVERTICES)lpInstruction;
		lpProcessVertices->dwFlags    = D3DPROCESSVERTICES_TRANSFORMLIGHT;
		lpProcessVertices->wStart     = 0U;
		lpProcessVertices->wDest      = 0U;
		lpProcessVertices->dwCount    = NUM_VERTICES;
		lpProcessVertices->dwReserved = 0UL;
		lpProcessVertices++;

		/*
		 * Triangle.
		 */
		lpInstruction = (LPD3DINSTRUCTION)lpProcessVertices;
		lpInstruction->bOpcode = D3DOP_TRIANGLE;
		lpInstruction->bSize   = sizeof(D3DTRIANGLE);
		lpInstruction->wCount  = NUM_TRIANGLES;
		lpInstruction++;
		lpTriangle = (LPD3DTRIANGLE)lpInstruction;
		lpTriangle->wV1    = 2U;
		lpTriangle->wV2    = 1U;
		lpTriangle->wV3    = 0U;
		lpTriangle->wFlags = D3DTRIFLAG_EDGEENABLETRIANGLE;
		lpTriangle++;
#if 0
		lpTriangle->wV1    = 2U;
		lpTriangle->wV2    = 0U;
		lpTriangle->wV3    = 3U;
		lpTriangle->wFlags = D3DTRIFLAG_EDGEENABLETRIANGLE || D3DTRIFLAG_EVEN;
		lpTriangle++;

		lpTriangle->wV1    = 3U;
		lpTriangle->wV2    = 0U;
		lpTriangle->wV3    = 1U;
		lpTriangle->wFlags = D3DTRIFLAG_EDGEENABLETRIANGLE || D3DTRIFLAG_ODD;
		lpTriangle++;
#endif
		lpInstruction = (LPD3DINSTRUCTION)lpTriangle;
		lpInstruction->bOpcode = D3DOP_EXIT;
		lpInstruction->bSize   = 0UL;
		lpInstruction->wCount  = 0U;

		/*
		 * Unlock the execute buffer.
		 */
		lpd3dExecuteBuffer->Unlock();

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT CreateScene(void)
	{
		HRESULT              hRes;
		D3DMATERIAL          d3dMaterial;
		D3DLIGHT             d3dLight;
		DWORD                dwVertexSize;
		DWORD                dwInstructionSize;
		DWORD                dwExecuteBufferSize;
		D3DEXECUTEBUFFERDESC d3dExecuteBufferDesc;
		D3DEXECUTEDATA       d3dExecuteData;

		ATLENSURE(NULL != lpd3d);
		ATLENSURE(NULL != lpd3dDevice);
		ATLENSURE(NULL == lpd3dViewport);
		ATLENSURE(NULL == lpd3dMaterial);
		ATLENSURE(NULL == lpd3dBackgroundMaterial);
		ATLENSURE(NULL == lpd3dExecuteBuffer);
		ATLENSURE(NULL == lpd3dLight);
		ATLENSURE(0UL  == hd3dWorldMatrix);
		ATLENSURE(0UL  == hd3dViewMatrix);
		ATLENSURE(0UL  == hd3dProjMatrix);

		/*
		 * Create a light.
		 */
		hRes = lpd3d->CreateLight(&lpd3dLight, NULL);
		if (FAILED(hRes))
			return hRes;

		ZeroMemory(&d3dLight, sizeof(d3dLight));
		d3dLight.dwSize = sizeof(d3dLight);
		d3dLight.dltType = D3DLIGHT_POINT;
		d3dLight.dcvColor.dvR    = D3DVAL( 1.0);
		d3dLight.dcvColor.dvG    = D3DVAL( 1.0);
		d3dLight.dcvColor.dvB    = D3DVAL( 1.0);
		d3dLight.dcvColor.dvA    = D3DVAL( 1.0);
		d3dLight.dvPosition.dvX  = D3DVAL( 1.0);
		d3dLight.dvPosition.dvY  = D3DVAL(-1.0);
		d3dLight.dvPosition.dvZ  = D3DVAL(-1.0);
		d3dLight.dvAttenuation0  = D3DVAL( 1.0);
		d3dLight.dvAttenuation1  = D3DVAL( 0.1);
		d3dLight.dvAttenuation2  = D3DVAL( 0.0);
		hRes = lpd3dLight->SetLight(&d3dLight);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Create the background material.
		 */
		hRes = lpd3d->CreateMaterial(&lpd3dBackgroundMaterial, NULL);
		if (FAILED(hRes))
			return hRes;

		ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
		d3dMaterial.dwSize = sizeof(d3dMaterial);
		d3dMaterial.dcvDiffuse.r  = D3DVAL(0.0);
		d3dMaterial.dcvDiffuse.g  = D3DVAL(0.0);
		d3dMaterial.dcvDiffuse.b  = D3DVAL(0.0);
		d3dMaterial.dcvAmbient.r  = D3DVAL(0.0);
		d3dMaterial.dcvAmbient.g  = D3DVAL(0.0);
		d3dMaterial.dcvAmbient.b  = D3DVAL(0.0);
		d3dMaterial.dcvSpecular.r = D3DVAL(0.0);
		d3dMaterial.dcvSpecular.g = D3DVAL(0.0);
		d3dMaterial.dcvSpecular.b = D3DVAL(0.0);
		d3dMaterial.dvPower       = D3DVAL(0.0);
		d3dMaterial.dwRampSize    = 1UL;

		hRes = lpd3dBackgroundMaterial->SetMaterial(&d3dMaterial);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dBackgroundMaterial->GetHandle(lpd3dDevice, &hd3dBackgroundMaterial);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Create the viewport.
		 */
		hRes = lpd3d->CreateViewport(&lpd3dViewport, NULL);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dDevice->AddViewport(lpd3dViewport);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dViewport->SetBackground(hd3dBackgroundMaterial);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dViewport->AddLight(lpd3dLight);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Create the matrices.
		 */
		hRes = lpd3dDevice->CreateMatrix(&hd3dWorldMatrix);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dDevice->SetMatrix(hd3dWorldMatrix, &d3dWorldMatrix);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dDevice->CreateMatrix(&hd3dViewMatrix);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dDevice->SetMatrix(hd3dViewMatrix, &d3dViewMatrix);
		if (FAILED(hRes))
			return hRes;
		hRes = lpd3dDevice->CreateMatrix(&hd3dProjMatrix);
		if (FAILED(hRes))
			return hRes;
		SetPerspectiveProjection(&d3dProjMatrix, HALF_HEIGHT, FRONT_CLIP, BACK_CLIP);
		hRes = lpd3dDevice->SetMatrix(hd3dProjMatrix, &d3dProjMatrix);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Create the material.
		 */
		hRes = lpd3d->CreateMaterial(&lpd3dMaterial, NULL);
		if (FAILED(hRes))
			return hRes;
		ZeroMemory(&d3dMaterial, sizeof(d3dMaterial));
		d3dMaterial.dwSize = sizeof(d3dMaterial);

		/*
		 * Base green with white specular.
		 */
		d3dMaterial.dcvDiffuse.r  = D3DVAL(0.0);
		d3dMaterial.dcvDiffuse.g  = D3DVAL(1.0);
		d3dMaterial.dcvDiffuse.b  = D3DVAL(0.0);
		d3dMaterial.dcvAmbient.r  = D3DVAL(0.0);
		d3dMaterial.dcvAmbient.g  = D3DVAL(0.4);
		d3dMaterial.dcvAmbient.b  = D3DVAL(0.0);
		d3dMaterial.dcvSpecular.r = D3DVAL(1.0);
		d3dMaterial.dcvSpecular.g = D3DVAL(1.0);
		d3dMaterial.dcvSpecular.b = D3DVAL(1.0);
		d3dMaterial.dvPower       = D3DVAL(20.0);
		d3dMaterial.dwRampSize    = 256UL;

		hRes = lpd3dMaterial->SetMaterial(&d3dMaterial);
		if (FAILED(hRes))
			return hRes;

		hRes = lpd3dMaterial->GetHandle(lpd3dDevice, &hd3dSurfaceMaterial);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Build the execute buffer.
		 */
		dwVertexSize        = (NUM_VERTICES        * sizeof(D3DVERTEX));
		dwInstructionSize   = (NUM_INSTRUCTIONS    * sizeof(D3DINSTRUCTION))     +
							  (NUM_STATES          * sizeof(D3DSTATE))           +
							  (NUM_PROCESSVERTICES * sizeof(D3DPROCESSVERTICES)) +
							  (NUM_TRIANGLES       * sizeof(D3DTRIANGLE));
		dwExecuteBufferSize = dwVertexSize + dwInstructionSize;
		ZeroMemory(&d3dExecuteBufferDesc, sizeof(d3dExecuteBufferDesc));
		d3dExecuteBufferDesc.dwSize       = sizeof(d3dExecuteBufferDesc);
		d3dExecuteBufferDesc.dwFlags      = D3DDEB_BUFSIZE;
		d3dExecuteBufferDesc.dwBufferSize = dwExecuteBufferSize;
		hRes = lpd3dDevice->CreateExecuteBuffer(&d3dExecuteBufferDesc,
												&lpd3dExecuteBuffer,
												NULL);
		if (FAILED(hRes))
			return hRes;

		hRes = FillExecuteBuffer();
		if (FAILED(hRes))
			return hRes;

		ZeroMemory(&d3dExecuteData, sizeof(d3dExecuteData));
		d3dExecuteData.dwSize = sizeof(d3dExecuteData);
		d3dExecuteData.dwVertexCount       = NUM_VERTICES;
		d3dExecuteData.dwInstructionOffset = dwVertexSize;
		d3dExecuteData.dwInstructionLength = dwInstructionSize;
		hRes = lpd3dExecuteBuffer->SetExecuteData(&d3dExecuteData);
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT ReleaseScene(void)
	{
		if (NULL != lpd3dExecuteBuffer)
		{
			lpd3dExecuteBuffer->Release();
			lpd3dExecuteBuffer = NULL;
		}
		if (NULL != lpd3dBackgroundMaterial)
		{
			lpd3dBackgroundMaterial->Release();
			lpd3dBackgroundMaterial = NULL;
		}
		if (NULL != lpd3dMaterial)
		{
			lpd3dMaterial->Release();
			lpd3dMaterial = NULL;
		}
		if (0UL != hd3dWorldMatrix)
		{
			lpd3dDevice->DeleteMatrix(hd3dWorldMatrix);
			hd3dWorldMatrix = 0UL;
		}
		if (0UL != hd3dViewMatrix)
		{
			lpd3dDevice->DeleteMatrix(hd3dViewMatrix);
			hd3dViewMatrix = 0UL;
		}
		if (0UL != hd3dProjMatrix)
		{
			lpd3dDevice->DeleteMatrix(hd3dProjMatrix);
			hd3dProjMatrix = 0UL;
		}
		if (NULL != lpd3dLight)
		{
			lpd3dLight->Release();
			lpd3dLight = NULL;
		}
		if (NULL != lpd3dViewport)
		{
			lpd3dViewport->Release();
			lpd3dViewport = NULL;
		}

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT TickScene(void)
	{
		HRESULT hRes;

		ATLENSURE(NULL != lpd3dDevice);
		ATLENSURE(0UL  != hd3dWorldMatrix);

		/*
		 * We rotate the triangle by setting thr world transform to a
		 * rotation matrix.
		 */
		SetRotationAboutY(&d3dWorldMatrix, m_dAngleOfRotation);
		m_dAngleOfRotation += ROTATE_ANGLE_DELTA;
		hRes = lpd3dDevice->SetMatrix(hd3dWorldMatrix, &d3dWorldMatrix);
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT UpdateViewport(void)
	{
		D3DVIEWPORT d3dViewport;

		ATLENSURE(NULL != lpd3dViewport);

		ZeroMemory(&d3dViewport, sizeof(d3dViewport));
		d3dViewport.dwSize   = sizeof(d3dViewport);
		d3dViewport.dwX      = 0UL;
		d3dViewport.dwY      = 0UL;
		d3dViewport.dwWidth  = (DWORD)m_rcSrc.right;
		d3dViewport.dwHeight = (DWORD)m_rcSrc.bottom;
		d3dViewport.dvScaleX = D3DVAL((float)d3dViewport.dwWidth / 2.0);
		d3dViewport.dvScaleY = D3DVAL((float)d3dViewport.dwHeight / 2.0);
		d3dViewport.dvMaxX   = D3DVAL(1.0);
		d3dViewport.dvMaxY   = D3DVAL(1.0);
		return lpd3dViewport->SetViewport(&d3dViewport);
	}

	/***********************************************************************/

	HRESULT RenderScene(void)
	{
		HRESULT hRes;
		D3DRECT d3dRect;

		ATLENSURE(NULL != lpd3dViewport);
		ATLENSURE(NULL != lpd3dDevice);
		ATLENSURE(NULL != lpd3dExecuteBuffer);

		/*
		 * Clear both back and z-buffer.
		 */
		d3dRect.lX1 = m_rcSrc.left;
		d3dRect.lX2 = m_rcSrc.right;
		d3dRect.lY1 = m_rcSrc.top;
		d3dRect.lY2 = m_rcSrc.bottom;
		hRes = lpd3dViewport->Clear(1UL,
									&d3dRect,
									D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER);
		if (FAILED(hRes))
			return hRes;

		/*
		 * Start the scene.
		 */
		hRes = lpd3dDevice->BeginScene();
		if (FAILED(hRes))
			return hRes;

		/*
		 * Submit the execute buffer.
		 */
		hRes = lpd3dDevice->Execute(lpd3dExecuteBuffer,
									lpd3dViewport,
									D3DEXECUTE_CLIPPED);
		if (FAILED(hRes))
		{
			lpd3dDevice->EndScene();
			return hRes;
		}

		/*
		 * End the scene.
		 */
		hRes = lpd3dDevice->EndScene();
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	HRESULT DoFrame(void)
	{
		HRESULT hRes = S_OK;

		hRes = RenderScene();
		if (SUCCEEDED(hRes))
			hRes = PaintClient();
		
		while (DDERR_SURFACELOST == hRes)
		{
			if(DD_OK == RestoreSurfaces())
				hRes = RenderScene();

			if (SUCCEEDED(hRes))
				hRes = PaintClient();
		}

		return hRes;
	}

	/***********************************************************************/

	HRESULT PaintClient(void)
	{
		if ((NULL != lpddPrimary) && (NULL != lpddDevice))
		{
			return lpddPrimary->Blt(&m_rcDst,
								   lpddDevice,
								   &m_rcSrc,
								   DDBLT_WAIT,
								   NULL);
		}
		else
		{
			return DD_OK;
		}
	}

	/***********************************************************************/

	LRESULT RestoreSurfaces(void)
	{
		HRESULT hRes;

		hRes = RestorePrimary();
		if (FAILED(hRes))
			return hRes;

		hRes = RestoreDevice();
		if (FAILED(hRes))
			return hRes;

		return DD_OK;
	}

	/***********************************************************************/

	LRESULT OnCreate(HWND hwnd, const RECT& rcPos)
	{
		HRESULT hRes;

		// Store our initial position
		m_rcDst = rcPos;

		hRes = CreateDirect3D(hwnd);
		if (FAILED(hRes))
		{
			ReportError(hwnd, "Could not initialize DirectDraw and Direct3D", hRes);
			return -1L;
		}

		hRes = CreatePrimary(hwnd);
		if (FAILED(hRes))
		{
			ReportError(hwnd, "Could not create the primary surface", hRes);
			return -1L;
		}

		hRes = ChooseDevice();
		if (FAILED(hRes))
		{
			ReportError(hwnd, "Could not find a suitable Direct3D device", hRes);
			return -1L;
		}

		return 0L;
	}

	/***********************************************************************/

	LRESULT OnMove(HWND /* hwnd */, int x, int y)
	{
		int     xDelta;
		int     yDelta;

		/*
		 * Don't bother doing any of this stuff if we are shutting down.
		 */
		if (!m_bShuttingDown)
		{
			/*
			 * Update the destination rectangle for the new client position.
			 */
			xDelta = x - m_rcDst.left;
			yDelta = y - m_rcDst.top;

			m_rcDst.left   += xDelta;
			m_rcDst.top    += yDelta;
			m_rcDst.right  += xDelta;
			m_rcDst.bottom += yDelta;
		}
		return 0L;
	}

	/***********************************************************************/

	LRESULT OnSize(HWND hwnd, int w, int h)
	{
		HRESULT       hRes;
		DDSURFACEDESC ddsd;

		/*
		 * Again no point in doing this stuff if we are in the process
		 * of shutting down.
		 */
		if (!m_bIsSuspended && !m_bShuttingDown)
		{
			m_rcDst.right  = m_rcDst.left + w;
			m_rcDst.bottom = m_rcDst.top  + h;
			m_rcSrc.top = 0;
			m_rcSrc.left    = 0;
			m_rcSrc.right  = w;
			m_rcSrc.bottom = h;

			if (NULL != lpd3dDevice)
			{
				/*
				 * We already have a device. But is it big enough for the the
				 * new window client size?
				 */
				ZeroMemory(&ddsd, sizeof(ddsd));
				ddsd.dwSize = sizeof(ddsd);
				hRes = lpddDevice->GetSurfaceDesc(&ddsd);
				if (FAILED(hRes))
				{
					FatalError(hwnd, "Could not get the size of the 3D surface", hRes);
					return 0L;
				}

				if ((w > (int)ddsd.dwWidth) || (h > (int)ddsd.dwHeight))
				{
					/*
					 * Nope, the device is too small. We need to shut it down
					 * and rebuild it.
					 */
					ReleaseScene();
					ReleaseDevice();
				}
			}

			if (NULL == lpd3dDevice)
			{
				/*
				 * No Direct3D device yet. This is either because this is the
				 * first time through the loop or because we discarded the
				 * existing device because it was not big enough for the new
				 * window client size.
				 */
				hRes = CreateDevice((DWORD)w, (DWORD)h);
				if (FAILED(hRes))
				{
					FatalError(hwnd, "Could not recreate the Direct3D device", hRes);
					return 0L;
				}
				hRes = CreateScene();
				if (FAILED(hRes))
				{
					FatalError(hwnd, "Could not recreate the 3D scene", hRes);
					return 0L;
				}
			}

			hRes = UpdateViewport();
			if (FAILED(hRes))
			{
				FatalError(hwnd, "Could not update the 3D viewport", hRes);
				return 0L;
			}

#if 0
			hRes = DoFrame();
			if (FAILED(hRes))
			{
				FatalError(hwnd, "Could not show the 3D scene", hRes);
				return 0L;
			}
#endif
		}

		return 0L;
	}

	/***********************************************************************/

	LRESULT OnPaint(HWND hwnd, HDC /* hdc */, LPPAINTSTRUCT /* lpps */)
	{
		HRESULT hRes;

		if (m_bIsActive && !m_bIsSuspended & !m_bShuttingDown)
		{
			hRes = DoFrame();
			if (FAILED(hRes))
			{
				FatalError(hwnd, "Could not show the 3D scene", hRes);
				return 0L;
			}
		}

		return 0L;
	}

	/***********************************************************************/

	LRESULT SetPalette()
	{
		if (m_bIsActive && !m_bIsSuspended && !m_bShuttingDown)
		{
			if (NULL != lpddPalette)
				lpddPrimary->SetPalette(lpddPalette);
		}

		return 0L;
	}

	/***********************************************************************/

private:
	// DirectDraw interfaces
	LPDIRECTDRAW            lpdd;
	LPDIRECTDRAWSURFACE     lpddPrimary;
	LPDIRECTDRAWSURFACE     lpddDevice;
	LPDIRECTDRAWSURFACE     lpddZBuffer;
	LPDIRECTDRAWPALETTE     lpddPalette;

	// Direct3D interfaces
	LPDIRECT3D              lpd3d;
	LPDIRECT3DDEVICE        lpd3dDevice;
	LPDIRECT3DMATERIAL      lpd3dMaterial;
	LPDIRECT3DMATERIAL      lpd3dBackgroundMaterial;
	LPDIRECT3DVIEWPORT      lpd3dViewport;
	LPDIRECT3DLIGHT         lpd3dLight;
	LPDIRECT3DEXECUTEBUFFER lpd3dExecuteBuffer;

	// Direct3D handles
	D3DMATRIXHANDLE         hd3dWorldMatrix;
	D3DMATRIXHANDLE         hd3dViewMatrix;
	D3DMATRIXHANDLE         hd3dProjMatrix;
	D3DMATERIALHANDLE       hd3dSurfaceMaterial;
	D3DMATERIALHANDLE       hd3dBackgroundMaterial;

	// The screen coordinates of the client area of the window. This
	// rectangle defines the destination into which we blit to update
	// the client area of the window with the results of the 3D rendering.
	RECT m_rcDst;

	// This rectangle defines the portion of the rendering target surface
	// into which we render. The top left coordinates of this rectangle
	// are always zero and the right and bottom give the size of the
	// viewport.
	RECT m_rcSrc;

	BOOL m_bIsActive;
	BOOL m_bIsSuspended;
	BOOL m_bShuttingDown;
	BOOL m_bDebug;

	// Angle of rotation of the world matrix.
	double m_dAngleOfRotation;

	// Predefined transformations
	CD3DMatrix d3dWorldMatrix;
	CD3DMatrix d3dViewMatrix;
	CD3DMatrix d3dProjMatrix;
};
