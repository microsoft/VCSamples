// spinctl.cpp : Implementation of the CSpindialCtrl OLE control class.
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
#include "spindial.h"
#include "spinctl.h"
#include "spinppg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Numeric constants

const int MAX_POSITIONS = 4;
const int TICK_LEN = 6;


IMPLEMENT_DYNCREATE(CSpindialCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CSpindialCtrl, COleControl)
	//{{AFX_MSG_MAP(CSpindialCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CSpindialCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CSpindialCtrl)
	DISP_PROPERTY_EX(CSpindialCtrl, "NeedlePosition", GetNeedlePosition, SetNeedlePosition, VT_I2)
	DISP_DEFVALUE(CSpindialCtrl, "NeedlePosition")
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CSpindialCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CSpindialCtrl, COleControl)
	//{{AFX_EVENT_MAP(CSpindialCtrl)
	EVENT_CUSTOM("SpinPositive", FireSpinPositive, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CSpindialCtrl, 1)
	PROPPAGEID(CSpindialPropPage::guid)
END_PROPPAGEIDS(CSpindialCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSpindialCtrl, "SPINDIAL.SpindialCtrl.1",
	0x6889605, 0xb8d0, 0x101a, 0x91, 0xf1, 0x0, 0x60, 0x8c, 0xea, 0xd5, 0xb3)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CSpindialCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DSpindial =
		{ 0x37446b89, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DSpindialEvents =
		{ 0x37446b8a, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwSpindialOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSpindialCtrl, IDS_SPINDIAL, _dwSpindialOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::CSpindialCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CSpindialCtrl

BOOL CSpindialCtrl::CSpindialCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SPINDIAL,
			IDB_SPINDIAL,
			FALSE,                      //  Not insertable
			_dwSpindialOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::CSpindialCtrl - Constructor

CSpindialCtrl::CSpindialCtrl()
{
	InitializeIIDs(&IID_DSpindial, &IID_DSpindialEvents);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::~CSpindialCtrl - Destructor

CSpindialCtrl::~CSpindialCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::OnDraw - Drawing function

void CSpindialCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	LPRECT      lpr;
	OLE_COLOR   color;
	CBrush      br;
	POINT       centerPt;
	POINT       tickpos[MAX_POSITIONS];
	CPen* pOldPen;

	lpr = (LPRECT)(LPCRECT)rcBounds;

	// Paint background using the ambient background color
	color = AmbientBackColor();
	br.CreateSolidBrush(TranslateColor(color));
	pdc->FillRect(lpr, &br);

	// Draw the dial using a black pen
	pOldPen = (CPen*)pdc->SelectStockObject(BLACK_PEN);
	pdc->Ellipse(lpr);

	// Determine coordinates of center point
	centerPt.x = lpr->left + ((lpr->right - lpr->left) / 2);
	centerPt.y = lpr->top + ((lpr->bottom - lpr->top) / 2);

	// Determine coordinates of intersections of tick marks and dial
	tickpos[0].x = centerPt.x;
	tickpos[0].y = lpr->top;
	tickpos[1].x = lpr->right;
	tickpos[1].y = centerPt.y;
	tickpos[2].x = centerPt.x;
	tickpos[2].y = lpr->bottom;
	tickpos[3].x = lpr->left;
	tickpos[3].y = centerPt.y;

	// Draw each tick mark
	pdc->MoveTo(tickpos[0]);
	pdc->LineTo(tickpos[0].x, tickpos[0].y+TICK_LEN);
	pdc->MoveTo(tickpos[1]);
	pdc->LineTo(tickpos[1].x-TICK_LEN, tickpos[1].y);
	pdc->MoveTo(tickpos[2]);
	pdc->LineTo(tickpos[2].x,tickpos[2].y-TICK_LEN);
	pdc->MoveTo(tickpos[3]);
	pdc->LineTo(tickpos[3].x+TICK_LEN, tickpos[3].y);

	// Draw pointer of dial
	pdc->MoveTo(centerPt);
	pdc->LineTo(tickpos[m_needlePosition]);

	pdc->SelectObject(pOldPen);

	return;
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::DoPropExchange - Persistence support

void CSpindialCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Short(pPX, _T("NeedlePosition"), m_needlePosition, 0);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::OnResetState - Reset control to default state

void CSpindialCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::AboutBox - Display an "About" box to the user

void CSpindialCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_SPINDIAL);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::GetNeedlePosition - Return needle position.

short CSpindialCtrl::GetNeedlePosition()
{
	return m_needlePosition;
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::SetNeedlePosition - Set needle position.

void CSpindialCtrl::SetNeedlePosition(short nNewValue)
{
	// Constrain value to 0..3 range
	if ( (nNewValue > 3) || (nNewValue < 0) )
		m_needlePosition = 0;
	else
		m_needlePosition = nNewValue;

	SetModifiedFlag(TRUE);

	InvalidateControl();
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::OnLButtonDown - Spin needle and fire event.

void CSpindialCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	//  Spin needle position
	SpinNeedlePosition();

	// Fire "spin positive" event
	FireSpinPositive();

	COleControl::OnLButtonDown(nFlags, point);
}


/////////////////////////////////////////////////////////////////////////////
// CSpindialCtrl::SpinNeedlePosition - Spin needle to next position.

void CSpindialCtrl::SpinNeedlePosition()
{
	 short np = GetNeedlePosition();
	 if (np == 3) np = 0;
		 else np++;
	 SetNeedlePosition(np);
}
