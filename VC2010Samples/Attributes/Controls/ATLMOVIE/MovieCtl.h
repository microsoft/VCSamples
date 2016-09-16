// MovieCtl.h : Declaration of the CMovieCtl
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __MOVIECTL_H_
#define __MOVIECTL_H_

#include "resource.h"       // main symbols

// This is the ActiveMovie DLL. You might need to specify an explicit path
// here if the DLL isn't intalled along the PATH or INCLUDE directories on
// your machine.
#import <quartz.dll> no_namespace rename("GUID","_GUID") exclude("LONG_PTR")

[ emitidl ];
[
	object,
	uuid(5C5F5688-8481-46F6-AEC4-B2752E5E4F83),
	dual,
	oleautomation,
	helpstring("IMovieCtl Interface"),
	pointer_default(unique)
]
__interface IMovieCtl : IDispatch
{
	[id(1), helpstring("method Play")] HRESULT Play();
	[propput, id(2), helpstring("property FileName")] HRESULT FileName([in] BSTR newVal);
	[id(3), helpstring("method Pause")] HRESULT Pause();
	[id(4), helpstring("method Reset")] HRESULT Reset();
	[id(5), helpstring("method Stop")] HRESULT Stop();
};

/////////////////////////////////////////////////////////////////////////////
// CMovieCtl
[
	coclass,
	threading(single),
	uuid("7F296092-A510-4510-9ABA-1EE1A65A238D"),
	progid("MovieCtl.MovieCtlAttrib.1"),
	vi_progid("MovieCtl.MovieCtlAttrib"),
	default("IMovieCtl"),
	registration_script("MovieCtl.rgs")
]
class ATL_NO_VTABLE CMovieCtl :
	public IMovieCtl,
	public CComControl<CMovieCtl>,
	public IPersistStreamInitImpl<CMovieCtl>,
	public IPersistStorageImpl<CMovieCtl>,
	public IOleControlImpl<CMovieCtl>,
	public IOleObjectImpl<CMovieCtl>,
	public IOleInPlaceActiveObjectImpl<CMovieCtl>,
	public IViewObjectExImpl<CMovieCtl>,
	public IOleInPlaceObjectWindowlessImpl<CMovieCtl>,
	public IProvideClassInfoImpl<&__uuidof(CMovieCtl)>,
	public IObjectSafetyImpl<CMovieCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	CMovieCtl()
	{
	}

BEGIN_PROPERTY_MAP(CMovieCtl)
END_PROPERTY_MAP()

BEGIN_MSG_MAP(CMovieCtl)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
END_MSG_MAP()

// IMovieCtl
public:
	STDMETHOD(Stop)();
	STDMETHOD(Reset)();
	STDMETHOD(Pause)();
	void FinalRelease()
	{
		if (m_spVideoWindow)
		{
			// Hide the video window before we reset the owner
			m_spVideoWindow->Visible = FALSE;
			m_spVideoWindow->Owner = NULL;
		}
	}
	STDMETHOD(put_FileName)(/*[in]*/ BSTR newVal);
	STDMETHOD(Play)();
	HRESULT CreateFilterGraph(LPCOLESTR strFile);
	HRESULT OnDraw(ATL_DRAWINFO& di);

	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		HRESULT hr = IOleInPlaceObjectWindowlessImpl<CMovieCtl>::SetObjectRects(prcPos, prcClip);

		// Resize the video window if we have one
		if (m_spVideoWindow)
		{
			RECT rc = m_rcPos;
			if (!m_bWndLess)
				OffsetRect(&rc, -rc.left, -rc.top);
			m_spVideoWindow->SetWindowPosition(rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top);
		}

		return hr;
	}

protected:
	IMediaControlPtr    m_spMediaControl;
	IVideoWindowPtr     m_spVideoWindow;
};

#endif //__MOVIECTL_H_
