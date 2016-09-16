// iviewers.h
//
// Definitions for Ole2View 2.0's interface viewers
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __IVIEWERS_H__
#define __IVIEWERS_H__

DEFINE_GUID(IID_IInterfaceViewer, /* fc37e5ba-4a8e-11ce-870b-0800368d2302 */
	0xfc37e5ba,
	0x4a8e,
	0x11ce,
	0x87, 0x0b, 0x08, 0x00, 0x36, 0x8d, 0x23, 0x02
  );

#ifndef __IInterfaceViewer__
#define __IInterfaceViewer__
DECLARE_INTERFACE_(IInterfaceViewer, IUnknown)
{
	// *** IUnknown methods ***
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
	STDMETHOD_(ULONG,AddRef) (THIS) PURE;
	STDMETHOD_(ULONG,Release) (THIS) PURE;

	// *** IInterfaceViewer methods ***
	STDMETHOD(View) (HWND hwndParent, REFIID riid, LPUNKNOWN punk) PURE;
};
#endif // __IInterfaceViewer__


// IInterfaceViewer::View can return the following SCODEs
//
// S_OK
// E_INVALIDARG
// E_UNEXPECTED
// E_OUTOFMEMORY
//

// CLSIDs of viewers implemented in IVIEWER.DLL
//
DEFINE_GUID(CLSID_ITypeLibViewer,    0x57efbf49, 0x4a8b, 0x11ce, 0x87, 0xb,  0x8,  0x0,  0x36, 0x8d, 0x23, 0x2 ) ;
DEFINE_GUID(CLSID_IDataObjectViewer, 0x28d8aba0, 0x4b78, 0x11ce, 0xb2, 0x7d, 0x0,  0xaa, 0x0,  0x1f, 0x73, 0xc1);
DEFINE_GUID(CLSID_IDispatchViewer,   0xd2af7a60, 0x4c42, 0x11ce, 0xb2, 0x7d, 0x00, 0xaa, 0x00, 0x1f, 0x73, 0xc1) ;

// Helper function exported from iviewers.dll.  Make sure OLE is initialized
// before calling.   rclsid is the clsid of the interface viewer and riid
// is the iid of the interface.
//
STDAPI DllRegisterInterfaceViewer( REFCLSID rclsid, REFIID riid );

#endif // __IVIEWERS_H__
