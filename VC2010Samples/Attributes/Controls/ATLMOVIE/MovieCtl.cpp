// MovieCtl.cpp : Implementation of CMovieCtl
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
#include "ATLMovie.h"
#include "MovieCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CMovieCtl

HRESULT CMovieCtl::OnDraw(ATL_DRAWINFO& di)
{
	// If we can get the ambient background color from the container then we
	// will use it to fill our background
	CComVariant var;
	if (SUCCEEDED(m_spAmbientDispatch.GetProperty(DISPID_AMBIENT_BACKCOLOR, &var)))
	{
		LOGBRUSH    logbrush;
		COLORREF    col;
		logbrush.lbStyle = BS_SOLID;
		OleTranslateColor(var.lVal, NULL, &col);
		logbrush.lbColor = col;
		HBRUSH hBrush = CreateBrushIndirect(&logbrush);
		FillRect(di.hdcDraw, (RECT*)di.prcBounds, hBrush);
		DeleteObject(hBrush);
	}
	return S_OK;
}

STDMETHODIMP CMovieCtl::put_FileName(BSTR newVal)
{
	// Initialize Active Movie with the new filename
	CreateFilterGraph(newVal);

	SysFreeString(newVal);
	return S_OK; //hr;
}

// Initialize Active Movie with the passed movie filename
HRESULT CMovieCtl::CreateFilterGraph(LPCOLESTR strFile)
{
	HRESULT hr;

	// If we are resetting the filename we need to close the existing one,
	// otherwise we'll get another window created.
	if (m_spVideoWindow)
	{
		m_spVideoWindow->Visible = FALSE;   // Hide the video window
		m_spVideoWindow->Owner = NULL;
		m_spMediaControl.Release();
		m_spVideoWindow.Release();
	}
	// Create the Active Movie object
	hr = m_spVideoWindow.CreateInstance(__uuidof(FilgraphManager));
	m_spMediaControl = m_spVideoWindow;

	// Open the passed file
	hr = m_spMediaControl->RenderFile(strFile);

	// Now initialize the video window
	HWND hWnd;
	RECT rc = m_rcPos;
	if (m_bWndLess)
	{
		// Obtain the HWND of the client's window
		HDC hDC;
		m_spInPlaceSite->GetDC(NULL, OLEDC_NODRAW, &hDC);
		hWnd = WindowFromDC(hDC);
	}
	else
	{
		hWnd = m_hWnd;
		OffsetRect(&rc, -rc.left, -rc.top);
	}
	LPARAM lWnd = (LPARAM)hWnd;
	m_spVideoWindow->Owner = (LONG)lWnd;
	m_spVideoWindow->WindowStyle = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	m_spVideoWindow->SetWindowPosition(rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top);

	return hr;
}

// Play the movie
STDMETHODIMP CMovieCtl::Play()
{
	HRESULT hr;

	if (m_spVideoWindow == NULL)
		return E_FAIL;

	// Find out if we've reached the end of the movie and if we have
	// rewind to the beginning
	IMediaPositionPtr spMP = m_spVideoWindow;
	if (spMP)
	{
		if (spMP->CurrentPosition >= spMP->Duration)
			spMP->CurrentPosition = 0;
	}

	// Start the movie
	if (m_spMediaControl)
		hr = m_spMediaControl->Run();
	else
		hr = E_FAIL;

	return hr;
}

// Pause the movie
STDMETHODIMP CMovieCtl::Pause()
{
	if (m_spMediaControl)
		m_spMediaControl->Pause();

	return S_OK;
}

// Rewind the movie to the beginning
STDMETHODIMP CMovieCtl::Reset()
{
	if (m_spVideoWindow)
	{
		IMediaPositionPtr spMP = m_spVideoWindow;
		if (spMP)
			spMP->CurrentPosition = 0;
	}
	return S_OK;
}

// Stop the movie
STDMETHODIMP CMovieCtl::Stop()
{
	if (m_spMediaControl)
	{
		m_spMediaControl->Stop();
		Reset();                            // Go back to the beginning
		m_spVideoWindow->Visible = FALSE;   // Hide the video window
	}
	return S_OK;
}

// Override function so the COM support doesnt throw exeptions
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) //throw(_com_error)
{
}
