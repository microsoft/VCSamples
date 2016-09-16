// ImageCtl.cpp : Implementation of the CImageCtrl OLE control class.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "image.h"
#include "BmpProp.h"
#include "ImageCtl.h"
#include "ImagePpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CImageCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CImageCtrl, COleControl)
	//{{AFX_MSG_MAP(CImageCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CImageCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CImageCtrl)
	DISP_PROPERTY_NOTIFY(CImageCtrl, "AutoSize", m_bAutoSize, OnAutoSizeChanged, VT_BOOL)
	DISP_PROPERTY_EX(CImageCtrl, "ImagePath", GetImagePath, SetImagePath, VT_BSTR)
	DISP_STOCKPROP_READYSTATE()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CImageCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CImageCtrl, COleControl)
	//{{AFX_EVENT_MAP(CImageCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	EVENT_STOCK_READYSTATECHANGE()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

BEGIN_PROPPAGEIDS(CImageCtrl, 1)
	PROPPAGEID(CImagePropPage::guid)
END_PROPPAGEIDS(CImageCtrl)

/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CImageCtrl, "IMAGE.ImageCtrl.1",
	0x346685e3, 0xc383, 0x11cf, 0xa5, 0xa4, 0, 0xaa, 0, 0xa4, 0x57, 0x5)

/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CImageCtrl, _tlid, _wVerMajor, _wVerMinor)

/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DImage =
		{ 0x346685e1, 0xc383, 0x11cf, { 0xa5, 0xa4, 0, 0xaa, 0, 0xa4, 0x57, 0x5 } };
const IID BASED_CODE IID_DImageEvents =
		{ 0x346685e2, 0xc383, 0x11cf, { 0xa5, 0xa4, 0, 0xaa, 0, 0xa4, 0x57, 0x5 } };

/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwImageOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CImageCtrl, IDS_IMAGE, _dwImageOleMisc)

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::CImageCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CImageCtrl

BOOL CImageCtrl::CImageCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_IMAGE,
			IDB_IMAGE,
			afxRegInsertable | afxRegApartmentThreading,
			_dwImageOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::CImageCtrl - Constructor

#pragma warning(disable : 4355)

CImageCtrl::CImageCtrl() : m_bitprop(this), m_bAutoSize(TRUE)
{
	InitializeIIDs(&IID_DImage, &IID_DImageEvents);

	m_lReadyState = READYSTATE_UNINITIALIZED;
}

#pragma warning(default : 4355)

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::~CImageCtrl - Destructor

CImageCtrl::~CImageCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::OnDraw - Drawing function

void CImageCtrl::OnDraw(
			CDC* pDC, const CRect& rcBounds, const CRect& /*rcInvalid*/)
{
	if (m_bitprop.m_Bitmap.m_hObject != NULL)
	{
		CWindowDC screenDC(NULL);
		CDC dc;
		dc.CreateCompatibleDC(&screenDC);
		CBitmap* pBitmap = dc.SelectObject(&m_bitprop.m_Bitmap);

		int cx(min(rcBounds.Width(), m_bitprop.m_BitmapSize.cx));
		int cy(min(rcBounds.Height(), m_bitprop.m_BitmapSize.cy));

		pDC->BitBlt(rcBounds.left, rcBounds.top, cx, cy, &dc, 0, 0, SRCCOPY);
		if (cx < rcBounds.Width())
			pDC->PatBlt(cx, rcBounds.top, rcBounds.Width() - cx, rcBounds.Height(), BLACKNESS);
		if (cy < rcBounds.Height())
			pDC->PatBlt(rcBounds.left, cy, rcBounds.Width(), rcBounds.Height() - cy, BLACKNESS);

		if (!IsOptimizedDraw())
		{
			// The container does not support optimized drawing.
			// So, we'll have to clean up what we did to the DC

			dc.SelectObject(pBitmap);
		}
	}
	else
	{
		pDC->PatBlt(rcBounds.left, rcBounds.top,
					rcBounds.Width(), rcBounds.Height(), BLACKNESS);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::DoPropExchange - Persistence support

void CImageCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	if (pPX->IsLoading())
		InternalSetReadyState(READYSTATE_LOADING);

	PX_DataPath(pPX, _T("ImagePath"), m_bitprop);
	PX_Bool(pPX, _T("AutoSize"), m_bAutoSize, TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::GetControlFlags -
// Flags to customize MFC's implementation of ActiveX controls.
//
// For information on using these flags, please see MFC technical note
// #nnn, "Optimizing an ActiveX Control".
DWORD CImageCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();

	// The control can activate without creating a window.
	dwFlags |= windowlessActivate;

	// The control can optimize its OnDraw method, by not restoring
	// the original GDI objects in the device context.
	dwFlags |= canOptimizeDraw;
	return dwFlags;
}

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::OnResetState - Reset control to default state

void CImageCtrl::OnResetState()
{
	m_bitprop.ResetData();
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CImageCtrl::AboutBox - Display an "About" box to the user

void CImageCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_IMAGE);
	dlgAbout.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CImageCtrl message handlers

void CImageCtrl::InformDlStatus(CBitmapProperty::DLState dlState)
{
	InvalidateControl(NULL);
	if (dlState == CBitmapProperty::dlDone)
		InternalSetReadyState(READYSTATE_COMPLETE);
}

void CImageCtrl::AutoSize()
{
	ASSERT(m_bAutoSize);

	SetControlSize(m_bitprop.m_BitmapSize.cx, m_bitprop.m_BitmapSize.cy);
}

void CImageCtrl::OnAutoSizeChanged()
{
	if (m_bAutoSize)
		AutoSize();

	SetModifiedFlag();
}

void CImageCtrl::InformSize()
{
	if (m_bAutoSize)
		AutoSize();
	InternalSetReadyState(READYSTATE_INTERACTIVE);
}

BSTR CImageCtrl::GetImagePath()
{
	return m_bitprop.GetPath().AllocSysString();
}

void CImageCtrl::SetImagePath(LPCTSTR lpszNewValue)
{
	Load(lpszNewValue, m_bitprop);
	InvalidateControl(NULL);
	SetModifiedFlag();
}
