// timectl.cpp : Implementation of the CTimeCtrl OLE control class.
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
#include "time.h"
#include "timectl.h"
#include "timeppg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Numeric constants

const short ID_TIMER = 1;


IMPLEMENT_DYNCREATE(CTimeCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTimeCtrl, COleControl)
	//{{AFX_MSG_MAP(CTimeCtrl)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTimeCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTimeCtrl)
	DISP_PROPERTY_NOTIFY(CTimeCtrl, "Interval", m_interval, OnIntervalChanged, VT_I2)
	DISP_STOCKPROP_ENABLED()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTimeCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTimeCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTimeCtrl)
	EVENT_CUSTOM("Timer", FireTimer, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTimeCtrl, 1)
	PROPPAGEID(CTimePropPage::guid)
END_PROPPAGEIDS(CTimeCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTimeCtrl, "TIME.TimeCtrl.1",
	0xdcf0768d, 0xba7a, 0x101a, 0xb5, 0x7a, 0x0, 0x0, 0xc0, 0xc3, 0xed, 0x5f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTimeCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTime =
		{ 0x37446b91, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DTimeEvents =
		{ 0x37446b92, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTimeOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTimeCtrl, IDS_TIME, _dwTimeOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::CTimeCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTimeCtrl

BOOL CTimeCtrl::CTimeCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TIME,
			IDB_TIME,
			FALSE,                      //  Not insertable
			_dwTimeOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::CTimeCtrl - Constructor

CTimeCtrl::CTimeCtrl()
{
	InitializeIIDs(&IID_DTime, &IID_DTimeEvents);

	SetInitialSize(24, 22);
	m_interval = (short) DEFAULT_INTERVAL; // initialize interval property
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::~CTimeCtrl - Destructor

CTimeCtrl::~CTimeCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnDraw - Drawing function

void CTimeCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	CBitmap bitmap;
	BITMAP  bmp;
	CPictureHolder picHolder;
	CRect rcSrcBounds;

	// Load clock bitmap
	bitmap.LoadBitmap(IDB_CLOCK);
	bitmap.GetObject(sizeof(BITMAP), &bmp);
	rcSrcBounds.right = bmp.bmWidth;
	rcSrcBounds.bottom = bmp.bmHeight;

	// Create picture and render
	picHolder.CreateFromBitmap((HBITMAP)bitmap.m_hObject, NULL, FALSE);
	picHolder.Render(pdc, rcBounds, rcSrcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::DoPropExchange - Persistence support

void CTimeCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	short nInterval = m_interval;
	PX_Short(pPX, _T("Interval"), (short) m_interval, (short) DEFAULT_INTERVAL);

	if (pPX->IsLoading())
	{
		if (nInterval != m_interval)
			OnIntervalChanged();    // Force timer to recreate w/ correct interval
		OnEnabledChanged();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnResetState - Reset control to default state

void CTimeCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::AboutBox - Display an "About" box to the user

void CTimeCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TIME);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnEnabledChanged - Start/stop the timer when the enable state
// has changed.

void CTimeCtrl::OnEnabledChanged()
{
	if (AmbientUserMode())
	{
		if (GetEnabled())
		{
			if (GetHwnd() != NULL)
				StartTimer();
		}
		else
			StopTimer();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnIntervalChanged - Respond to a change of interval.

void CTimeCtrl::OnIntervalChanged()
{
	// Restart timer if it's enabled
	if (GetEnabled() && AmbientUserMode())
	{
		StopTimer();
		StartTimer();
	}

	SetModifiedFlag(TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnSetClientSite - Force creation of window

void CTimeCtrl::OnSetClientSite()
{
	RecreateControlWindow();
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnCreate - Start the timer if it's enabled.

int CTimeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Start timer if in user mode and if enabled
	if (AmbientUserMode() && GetEnabled())
		StartTimer();

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnDestroy - Stop the timer before the control is destroyed.

void CTimeCtrl::OnDestroy()
{
	StopTimer();

	COleControl::OnDestroy();
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnEraseBkgnd - Simply return TRUE so background is not erased.

BOOL CTimeCtrl::OnEraseBkgnd(CDC*)
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnTimer - Fire the timer event.

void CTimeCtrl::OnTimer(UINT_PTR)
{
	FireTimer();
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::OnAmbientPropertyChange - Start the timer if user mode ambient
// property has changed and if timer is enabled.  Stop the timer if user
// mode ambient property has changed and if timer is enabled.

void CTimeCtrl::OnAmbientPropertyChange(DISPID dispid)
{
	if (dispid == DISPID_AMBIENT_USERMODE)
	{
		// Start or stop the timer
		if (GetEnabled())
		{
			if (AmbientUserMode())
				StartTimer();
			else
				StopTimer();
		}

		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::StartTimer - Start the timer.

void CTimeCtrl::StartTimer()
{
	SetTimer(ID_TIMER, m_interval, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl::StopTimer - Stop the timer.

void CTimeCtrl::StopTimer()
{
	KillTimer(ID_TIMER);
}
