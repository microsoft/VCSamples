// localctl.cpp : Implementation of the CLocalizeCtrl OLE control class.
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
#include "localize.h"
#include "localctl.h"
#include "localppg.h"

#ifdef _WIN32
  #include <winnt.h>
#else
  #include <olenls.h>
#endif


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLocalizeCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLocalizeCtrl, COleControl)
	//{{AFX_MSG_MAP(CLocalizeCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CLocalizeCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CLocalizeCtrl)
	DISP_PROPERTY_NOTIFY(CLocalizeCtrl, "Invert", m_invert, OnInvertChanged, VT_BOOL)
	DISP_STOCKPROP_CAPTION()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CLocalizeCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CLocalizeCtrl, COleControl)
	//{{AFX_EVENT_MAP(CLocalizeCtrl)
	EVENT_CUSTOM_ID("Click", DISPID_CLICK, FireClick, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CLocalizeCtrl, 1)
	PROPPAGEID(CLocalizePropPage::guid)
END_PROPPAGEIDS(CLocalizeCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLocalizeCtrl, "LOCALIZE.LocalizeCtrl.1",
	0x879d6fe0, 0x5470, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CLocalizeCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DLocalize =
		{ 0x35e3e52, 0x6745, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DLocalizeEvents =
		{ 0x35e3e53, 0x6745, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwLocalizeOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLocalizeCtrl, IDS_LOCALIZE, _dwLocalizeOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::CLocalizeCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CLocalizeCtrl

BOOL CLocalizeCtrl::CLocalizeCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LOCALIZE,
			IDB_LOCALIZE,
			FALSE,                      //  Not insertable
			_dwLocalizeOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::CLocalizeCtrl - Constructor

CLocalizeCtrl::CLocalizeCtrl()
{
	InitializeIIDs(&IID_DLocalize, &IID_DLocalizeEvents);

	// Initialize inverted flag
	m_inverted = FALSE;
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::~CLocalizeCtrl - Destructor

CLocalizeCtrl::~CLocalizeCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnDraw - Drawing function

void CLocalizeCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	CFont *pOldFont;
	TEXTMETRIC tm;

	// Load localized caption as Caption property
	const CString& strCaption = InternalGetText();

	// Draw caption
	pOldFont = SelectStockFont(pdc);
	pdc->SetTextAlign(TA_CENTER | TA_TOP);
	GetStockTextMetrics(&tm);

	pdc->ExtTextOut((rcBounds.left + rcBounds.right) / 2, (rcBounds.top + rcBounds.bottom - tm.tmHeight) / 2,
		ETO_CLIPPED | ETO_OPAQUE, rcBounds, strCaption, strCaption.GetLength(), NULL);
	pdc->SelectObject(pOldFont);
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::DoPropExchange - Persistence support

void CLocalizeCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("Invert"), m_invert, TRUE);

	if (pPX->IsLoading())
	{
		CFontHolder& stockFont = InternalGetFont();
		stockFont.InitializeFont();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnResetState - Reset control to default state

void CLocalizeCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	LoadCaption();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::AboutBox - Display a localized "About" box to the user

void CLocalizeCtrl::AboutBox()
{
	BOOL bError = FALSE;

	// Load resource module
	HINSTANCE hResHandle = GetResourceHandle(AmbientLocaleID());

	if (!hResHandle)
		bError = TRUE;

	if (!bError)
	{
		// Load dialog resource from resource module
		HINSTANCE hResPrev = AfxGetResourceHandle();
		AfxSetResourceHandle(hResHandle);

		// Execute dialog
		CDialog dlgAbout(IDD_ABOUTBOX_LOCALIZE);
		dlgAbout.DoModal();

		AfxSetResourceHandle(hResPrev);
		FreeLibrary(hResHandle);
	}
	else
	{
		// Execute dialog, using resource in control module
		CDialog dlgAbout(IDD_ABOUTBOX_LOCALIZE);
		dlgAbout.DoModal();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnInvertChanged sets the modified flag of the control

void CLocalizeCtrl::OnInvertChanged()
{
	SetModifiedFlag();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnLButtonDown inverts the control if the Invert property
// is TRUE

void CLocalizeCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDC* pdc;
	CRect cRect;

	// If Invert property is set to TRUE
	if (m_invert)
	{
		// Invert the control
		pdc = GetDC();
		GetClientRect(&cRect);
		pdc->InvertRect(&cRect);
		ReleaseDC(pdc);

		// Capture the mouse
		SetCapture();

		// Set inverted flag
		m_inverted = TRUE;
	}

	COleControl::OnLButtonDown(nFlags, point);
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnLButtonUp fires the Click event.  First releases the
// mouse capture and invalidates the control, if the control was inverted
// and the mouse was captured in OnLButtonDown.

void CLocalizeCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	// If inverted flag is set
	if (m_inverted)
	{
		// Release the mouse
		ReleaseCapture();

		// Invalidate to redraw (without inversion)
		InvalidateControl();

		// Reset inverted flag
		m_inverted = FALSE;
	}

	COleControl::OnLButtonUp(nFlags, point);

	// Fire click event
	FireClick();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnCancelMode invalidates the control if the control was
// inverted in OnLButtonDown.

void CLocalizeCtrl::OnCancelMode()
{
	// If inverted flag is set
	if (m_inverted)
	{
		// Invalidate to redraw (without inversion)
		InvalidateControl();

		// Reset inverted flag
		m_inverted = FALSE;
	}

	// Default processing will release the mouse, if captured
	COleControl::OnCancelMode();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::OnAmbientPropertyChange - Reload locale-specific caption
// and invalidate if the ambient LocaleID has changed.

void CLocalizeCtrl::OnAmbientPropertyChange(DISPID dispid)
{
	if (dispid == DISPID_AMBIENT_LOCALEID)
	{
		LoadCaption();

		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizeCtrl::LoadCaption - Load the locale-specific caption of the
// control.

void CLocalizeCtrl::LoadCaption()
{
	CString caption;
	BOOL bError = FALSE;

	// Get the handle of the resource module
	HINSTANCE hResHandle = GetResourceHandle(AmbientLocaleID());

	if (!hResHandle)
		bError = TRUE;

	if (!bError)
	{
		// Load caption from resource module
		HINSTANCE hResPrev = AfxGetResourceHandle();
		AfxSetResourceHandle(hResHandle);
		caption.LoadString(IDS_CAPTION);
		AfxSetResourceHandle(hResPrev);
		FreeLibrary(hResHandle);
	}
	else
		// Load caption from control module resource
		caption.LoadString(IDS_CAPTION);

	// Set caption property
	SetText(caption);
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::GetResourceHandle - Load module which contains
// locale-specific resources

HINSTANCE CLocalizeCtrl::GetResourceHandle(LCID lcid)
{
	LPCTSTR lpszResModule = NULL;
	HINSTANCE hResHandle = NULL;

	// Use lcid to determine module that contains resources
	LANGID langID = LANGIDFROMLCID(lcid);
	unsigned short priLangID = (unsigned short) PRIMARYLANGID(langID);
	switch (priLangID)
	{
		case LANG_ENGLISH:
			break;
		case LANG_FRENCH:
			#ifdef _WIN32
				lpszResModule = (LPCTSTR)_T("lresfr32.dll");
			#else
				lpszResModule = (LPCTSTR)_T("locresfr.dll");
			#endif
			break;
		case LANG_GERMAN:
			#ifdef _WIN32
				lpszResModule = (LPCTSTR)_T("lresde32.dll");
			#else
				lpszResModule = (LPCTSTR)_T("locresde.dll");
			#endif
			break;
		case 0:
		default:
			 break;
	}

	// Load resource module
	if (lpszResModule != NULL)
		hResHandle = LoadLibrary(lpszResModule);

#ifndef _WIN32
	if (hResHandle <= HINSTANCE_ERROR)
		hResHandle = NULL;
#endif

	return hResHandle;
}
