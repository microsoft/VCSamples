// ScreenCapApi.h: Defines DllScreenCap.DLL application interface
// This interface can be included by C or C++ code
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

struct CaptureData
{
	BOOL    bCaptureFullScreen;
	char	szCapturePath[MAX_PATH]; // no unicode path support
	char	szCaptureFilename[MAX_PATH];
};

BOOL WINAPI ConfigureCapture(HWND hWndParent, CaptureData* lpData);
void WINAPI CaptureScreen(CaptureData* lpData);
BOOL WINAPI FilterDllMsg(LPMSG lpMsg);
void WINAPI ProcessDllIdle();

#ifdef __cplusplus
}
#endif
