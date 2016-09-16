// ThelpCtl.cpp : Implementation of the CTesthelpCtrl OLE control class.

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "testhelp.h"
#include "ThelpCtl.h"
#include "ThelpPpg.h"
#include <msstkppg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// This help id is also defined and used in the
// testhelp.hpj help project file.  It references
// a topic in the testhelp.hlp help file.

IMPLEMENT_DYNCREATE(CTesthelpCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTesthelpCtrl, COleControl)
		//{{AFX_MSG_MAP(CTesthelpCtrl)
		ON_WM_CREATE()
		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_WM_MOUSEMOVE()
		//}}AFX_MSG_MAP

		ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)

		ON_MESSAGE(WM_HELP, OnHelpCommand)  //We'll respond to the WM_HELP message
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTesthelpCtrl, COleControl)
		  //{{AFX_DISPATCH_MAP(CTesthelpCtrl)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "Name1", m_szName1, OnName1Changed, VT_BSTR)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "Name2", m_szName2, OnName2Changed, VT_BSTR)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "Name3", m_szName3, OnName3Changed, VT_BSTR)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "UseMyHelp", m_bUseMyHelp, OnUseMyHelpChanged, VT_BOOL)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "ShowToolTip", m_bShowToolTip, OnShowToolTipChanged, VT_BOOL)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "ToolTipText", m_szToolTipText, OnToolTipTextChanged, VT_BSTR)
		  DISP_PROPERTY_NOTIFY(CTesthelpCtrl, "UsePopupHelp", m_nUsePopupHelp, OnUsePopupHelpChanged, VT_I2)
		  DISP_STOCKPROP_FONT()
		  DISP_STOCKPROP_BACKCOLOR()
		  DISP_STOCKPROP_FORECOLOR()
		  DISP_STOCKPROP_BORDERSTYLE()
	//}}AFX_DISPATCH_MAP
		  DISP_FUNCTION_ID(CTesthelpCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTesthelpCtrl, COleControl)
		  //{{AFX_EVENT_MAP(CTesthelpCtrl)
		  // NOTE - ClassWizard will add and remove event map entries
		  //    DO NOT EDIT what you see in these blocks of generated code !
		  //}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTesthelpCtrl, 3)
		  PROPPAGEID(CTesthelpPropPage::guid)
		  // added stock property pages
		  PROPPAGEID(CLSID_StockColorPage);
		  PROPPAGEID(CLSID_StockFontPage);

END_PROPPAGEIDS(CTesthelpCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTesthelpCtrl, "TESTHELP.TesthelpCtrl.1",
	0x31a2b283, 0x8c11, 0x11cf, 0xb3, 0x7f, 0, 0xaa, 0, 0xb9, 0x2b, 0x50)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTesthelpCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTesthelp =
		{ 0x31a2b281, 0x8c11, 0x11cf, { 0xb3, 0x7f, 0, 0xaa, 0, 0xb9, 0x2b, 0x50 } };
const IID BASED_CODE IID_DTesthelpEvents =
		{ 0x31a2b282, 0x8c11, 0x11cf, { 0xb3, 0x7f, 0, 0xaa, 0, 0xb9, 0x2b, 0x50 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTesthelpOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTesthelpCtrl, IDS_TESTHELP, _dwTesthelpOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::CTesthelpCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTesthelpCtrl

BOOL CTesthelpCtrl::CTesthelpCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TESTHELP,
			IDB_TESTHELP,
			afxRegApartmentThreading,
			_dwTesthelpOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::CTesthelpCtrl - Constructor

CTesthelpCtrl::CTesthelpCtrl()
{
	InitializeIIDs(&IID_DTesthelp, &IID_DTesthelpEvents);
}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::~CTesthelpCtrl - Destructor

CTesthelpCtrl::~CTesthelpCtrl()
{
		  // TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::OnDraw - Drawing function

void CTesthelpCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& /*rcInvalid*/)
{
	// Drawing code, mostly plagiarized from the Circ MFC sample.
	// The only thing done here is setting the border and drawing text
	// specified by our name properties in the control's client area.
		if(!GetBorderStyle())   //Control will always have a border.
					SetBorderStyle(TRUE);

		// Set up variables to use for drawing text background.
		// Use our current BackColor for the background color.
		CBrush* pOldBrush;
		CBrush bkBrush(TranslateColor(GetBackColor()));
		CPen* pOldPen;
		CRect rc = rcBounds;
		CFont* pOldFont;

		// Set up background mode and text color.  Use the
		// current ForeColor for the text color.
		pdc->SetTextColor(TranslateColor(GetForeColor()));
		pdc->SetBkMode(TRANSPARENT);

		// Fill our window with the current BackColor
		pdc->FillRect(rcBounds, &bkBrush);

		// Save off the existing brush and pen so they
		// can be restored when we're done.
		pOldBrush = pdc->SelectObject(&bkBrush);
		pOldPen = (CPen*)pdc->SelectStockObject(BLACK_PEN);

		// Save off the current font so we can restore it and
		// select our current stock font into this DC
		pOldFont = SelectStockFont(pdc);

		// Draw the text on our window
		pdc->ExtTextOut(rc.left+10, rc.top +2,
			ETO_CLIPPED, rc, m_szName1, m_szName1.GetLength(), NULL);
		pdc->ExtTextOut(rc.left+10, rc.top +22,
			ETO_CLIPPED, rc, m_szName2, m_szName2.GetLength(), NULL);
		pdc->ExtTextOut(rc.left+10, rc.top +42,
			ETO_CLIPPED, rc, m_szName3, m_szName3.GetLength(), NULL);

		// Restore our DC to it's original state.
		pdc->SelectObject(pOldFont);
		pdc->SelectObject(pOldPen);
		pdc->SelectObject(pOldBrush);

}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::DoPropExchange - Persistence support

void CTesthelpCtrl::DoPropExchange(CPropExchange* pPX)
{
		  ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
		  COleControl::DoPropExchange(pPX);
		  // custom DDX
		  PX_String(pPX, _T("Name1"), m_szName1);
		  PX_String(pPX, _T("Name2"), m_szName2);
		  PX_String(pPX, _T("Name3"), m_szName3);
		  PX_Bool(pPX, _T("UseMyHelp"),m_bUseMyHelp, TRUE);
		  PX_Bool(pPX, _T("ShowToolTip"), m_bShowToolTip,FALSE);
		  PX_Short(pPX, _T("UsePopupHelp"), m_nUsePopupHelp,0);
		  PX_String(pPX, _T("ToolTipText"),m_szToolTipText,"");

}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::OnResetState - Reset control to default state

void CTesthelpCtrl::OnResetState()
{
		  COleControl::OnResetState();  // Resets defaults found in DoPropExchange

}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl::AboutBox - Display an "About" box to the user

void CTesthelpCtrl::AboutBox()
{
		  CDialog dlgAbout(IDD_ABOUTBOX_TESTHELP);
		  dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl message handlers

void CTesthelpCtrl::OnName1Changed()
{

		  SetModifiedFlag();
		  InvalidateControl();
}

void CTesthelpCtrl::OnName2Changed()
{

		  SetModifiedFlag();
		  InvalidateControl();
}

void CTesthelpCtrl::OnName3Changed()
{
		  SetModifiedFlag();
		  InvalidateControl();
}

LRESULT CTesthelpCtrl::OnHelpCommand(UINT_PTR /*wParam*/, LONG_PTR lParam)
{
		  LPHELPINFO hi;

		  // If the control is in a running application
		  // we'll just show context help.
		  hi = (LPHELPINFO)lParam;
		  if( (AmbientUserMode()||IsWindow(m_hWnd)) && m_bUseMyHelp )
		  {
					if(m_nUsePopupHelp==0)
					{
						CString strPath = AfxGetApp()->m_pszHelpFilePath;
						strPath += _T("::/popups.txt");

						HH_POPUP popup;
						ZeroMemory(&popup, sizeof(popup));
						popup.cbStruct = sizeof(HH_POPUP);
						popup.idString = IDH_WHATISTHISTHING;
						popup.clrBackground = (COLORREF)-1; //Default
						popup.clrForeground = (COLORREF)-1; //Default
						RECT rDefault = {-1,-1,-1,-1}; //Default
						popup.rcMargins = rDefault;
						popup.pt = hi->MousePos;

						::HtmlHelp((HWND)hi->hItemHandle, strPath, HH_DISPLAY_TEXT_POPUP, (DWORD_PTR)&popup);
						return TRUE;
					}
					else
					{
						AfxGetApp()->HtmlHelp(NULL, HH_DISPLAY_TOC);
						return TRUE;
					}


		  }

		  return (LONG)Default();
}

void CTesthelpCtrl::OnUseMyHelpChanged()
{
		  // TODO: Add notification handler code

		  SetModifiedFlag();
}


void CTesthelpCtrl::RelayEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
		  // This function will create a MSG structure, fill it in a pass it to
		  // the ToolTip control, m_ttip.  Note that we ensure the point is in window
		  // coordinates (relative to the control's window).
		  if(NULL != m_ttip.m_hWnd)
		  {
					MSG msg;
					msg.hwnd = m_hWnd;
					msg.message = message;
					msg.wParam = wParam;
					msg.lParam = lParam;
					msg.time = 0;
					msg.pt.x = LOWORD(lParam);
					msg.pt.y = HIWORD(lParam);

					m_ttip.RelayEvent(&msg);
		  }

}

int CTesthelpCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
		  if (COleControl::OnCreate(lpCreateStruct) == -1)
					return -1;
		  // The following code will create a the ToolTip control
		  // once the ocx's window is created.
		  if(!m_ttip.Create(this))
			 TRACE(_T("Unable to Create ToolTip"));
		  else
			 if(!m_ttip.AddTool(this, LPCTSTR(m_szToolTipText)))
				 TRACE(_T("Unable to add tip for the control window"));
			 else
				 m_ttip.Activate(m_bShowToolTip);


		  return 0;
}

void CTesthelpCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
		  // pass this message to the ToolTip control
		  RelayEvent(WM_LBUTTONDOWN, (WPARAM)nFlags,
					MAKELPARAM(LOWORD(point.x), LOWORD(point.y)));
		  COleControl::OnLButtonDown(nFlags, point);
}

void CTesthelpCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
		  // pass this message to the ToolTip control
		  RelayEvent(WM_LBUTTONUP, (WPARAM)nFlags,
					MAKELPARAM(LOWORD(point.x), LOWORD(point.y)));

		  COleControl::OnLButtonUp(nFlags, point);
}

void CTesthelpCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
		  // pass this message to the ToolTip control
		  RelayEvent(WM_MOUSEMOVE, (WPARAM)nFlags,
					MAKELPARAM(LOWORD(point.x), LOWORD(point.y)));

		  COleControl::OnMouseMove(nFlags, point);
}

void CTesthelpCtrl::OnShowToolTipChanged()
{
		  // Activate or DeActivate the ToolTip
		  if(m_ttip.m_hWnd && AmbientUserMode())
		  {
			  m_ttip.Activate(m_bShowToolTip);
			  SetModifiedFlag();
		  }
}

void CTesthelpCtrl::OnToolTipTextChanged()
{
		  // Change the ToolTip's text
		  if(m_ttip.m_hWnd && AmbientUserMode())
		  {
			  m_ttip.UpdateTipText((LPCTSTR)m_szToolTipText,this);
			  SetModifiedFlag();
		  }

}


void CTesthelpCtrl::OnUsePopupHelpChanged()
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}
