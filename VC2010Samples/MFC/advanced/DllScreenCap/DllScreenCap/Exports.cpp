// File: Exports.cpp
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include <AtlImage.h>
#include "DllScreenCap.h"
#include "ScreenCapApi.h"
#include "ConfigDlg.h"

static CString GetTempName(CString strPath);

BOOL WINAPI ConfigureCapture(HWND hWndParent, CaptureData* lpData)
{
	ASSERT(lpData);
	if (!lpData)
		return(FALSE);

	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CConfigDlg dlg(lpData->bCaptureFullScreen, 
		CA2T(lpData->szCapturePath), CWnd::FromHandle(hWndParent));
	BOOL bStat = FALSE;
	if (dlg.DoModal() == IDOK) {
		bStat = TRUE;
		lpData->bCaptureFullScreen = dlg.m_nFullScreen > 0;
		strncpy_s(lpData->szCapturePath, MAX_PATH, CT2A(dlg.m_strPath), _TRUNCATE);
		*lpData->szCaptureFilename = '\0';
	}
	return(bStat);
}

void WINAPI CaptureScreen(CaptureData* lpData)
{
	ASSERT(lpData);
	if (!lpData)
		return;

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	BOOL bStat;
	CImage image;
	CWnd *pWnd;
	CRect rect;
	if (lpData->bCaptureFullScreen) {
		pWnd = CWnd::GetDesktopWindow();
	}
	else {
		pWnd = CWnd::GetActiveWindow();
	}
	ASSERT(pWnd);
	if (pWnd == NULL)
		return;

	CWindowDC  winDC(pWnd);
	pWnd->GetWindowRect(rect);
	int nBPP = winDC.GetDeviceCaps(BITSPIXEL) * winDC.GetDeviceCaps(PLANES);
	if (nBPP < 24)
		nBPP = 24;
	bStat = image.Create(rect.Width(), rect.Height(), nBPP);
	ASSERT(bStat);
	if (!bStat)
		return;
	CImageDC imageDC(image);
	::BitBlt(imageDC, 0, 0, rect.Width(), rect.Height(), winDC, 0, 0, SRCCOPY);
	CString strTempName = GetTempName(CString(lpData->szCapturePath));
	HRESULT hr = image.Save(strTempName);
	if (FAILED(hr)) {
		TRACE("Couldn't Save File: %s, %x\n", (LPCTSTR)strTempName, hr);
		return;
	}
	strncpy_s(lpData->szCaptureFilename, MAX_PATH, CT2A(::PathFindFileName(strTempName)), _TRUNCATE);
}

BOOL WINAPI FilterDllMsg(LPMSG lpMsg)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRY
	{
		return AfxGetThread()->PreTranslateMessage(lpMsg);
	}
	END_TRY
	return FALSE;
}

void WINAPI ProcessDllIdle()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	TRY
	{
		// flush it all at once
		long lCount = 0;
		while (AfxGetThread()->OnIdle(lCount))
			lCount++;
	}
	END_TRY
}

static CString GetTempName(CString strPath)
{
	const int nMin = 0;
	const int nMax = 999;
	const CString strBase(_T("ScreenCap"));
	static int nLastKnown = nMin;
	
	// count up sequentially to make sure we take the next available
	// slot
	if (strPath.Right(1) != "\\")
		strPath += '\\';

	bool bFound = false;
	CString strPathName;
	while (!bFound) {
		if (nLastKnown > nMax)
			break;
		strPathName = strPath + strBase;
		strPathName.AppendFormat(_T("%03.3d.png"), nLastKnown++);
		HANDLE hFile = ::CreateFile(strPathName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile != INVALID_HANDLE_VALUE) {
			::CloseHandle(hFile);
			bFound = TRUE;
		}
	}
	if (!bFound)
		strPathName.Empty();
	return(strPathName);
}
