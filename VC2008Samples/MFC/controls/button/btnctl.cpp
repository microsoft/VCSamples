// btnctl.cpp : Implementation of the CButtonCtrl OLE control class.
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
#include "button.h"
#include "btnctl.h"
#include "btnppg.h"
#include <msstkppg.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CButtonCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CButtonCtrl, COleControl)
	//{{AFX_MSG_MAP(CButtonCtrl)
	ON_COMMAND(ID_HELP_BUTTONCONTROL, CmdAbout)
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_COMMAND(ID_OPTIONS_OPTION1, OnOptionsOption1)
	ON_COMMAND(ID_OPTIONS_OPTION2, OnOptionsOption2)
	ON_COMMAND(ID_OPTIONS_OPTION3, OnOptionsOption3)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CButtonCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CButtonCtrl)
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_CAPTION()
	DISP_STOCKPROP_ENABLED()
	DISP_STOCKPROP_FONT()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CButtonCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CButtonCtrl, COleControl)
	//{{AFX_EVENT_MAP(CButtonCtrl)
	EVENT_CUSTOM_ID("Click", DISPID_CLICK, FireClick, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

BEGIN_PROPPAGEIDS(CButtonCtrl, 2)
	PROPPAGEID(CButtonPropPage::guid)
	PROPPAGEID(CLSID_StockFontPage)
END_PROPPAGEIDS(CButtonCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CButtonCtrl, "BUTTON.ButtonCtrl.1",
	0x4a8c998f, 0x7713, 0x101b, 0xa5, 0xa1, 0x4, 0x2, 0x1c, 0x0, 0x94, 0x2)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CButtonCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DButton =
		{ 0x4a8c9990, 0x7713, 0x101b, { 0xa5, 0xa1, 0x4, 0x2, 0x1c, 0x0, 0x94, 0x2 } };
const IID BASED_CODE IID_DButtonEvents =
		{ 0x4a8c9991, 0x7713, 0x101b, { 0xa5, 0xa1, 0x4, 0x2, 0x1c, 0x0, 0x94, 0x2 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwButtonOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_ACTSLIKEBUTTON;

IMPLEMENT_OLECTLTYPE(CButtonCtrl, IDS_BUTTON, _dwButtonOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::CButtonCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CButtonCtrl

BOOL CButtonCtrl::CButtonCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_BUTTON,
			IDB_BUTTON,
			FALSE,                      //  Not insertable
			_dwButtonOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::CButtonCtrl - Constructor

CButtonCtrl::CButtonCtrl()
{
	InitializeIIDs(&IID_DButton, &IID_DButtonEvents);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::~CButtonCtrl - Destructor

CButtonCtrl::~CButtonCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::OnDraw - Drawing function

void CButtonCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /*rcInvalid*/)
{
	DoSuperclassPaint(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::DoPropExchange - Persistence support

void CButtonCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::OnResetState - Reset control to default state

void CButtonCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::AboutBox - Display an "About" box to the user

void CButtonCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_BUTTON);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CButtonCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::IsSubclassedControl - This is a subclassed control

BOOL CButtonCtrl::IsSubclassedControl()
{
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::PreTranslateMessage - Translate accelerator keys

BOOL CButtonCtrl::PreTranslateMessage(MSG* pMsg)
{
	// give container a shot at processing accelerators 
	if (pMsg->message >= WM_KEYFIRST && pMsg->message <= WM_KEYLAST)
		if (::OleTranslateAccelerator(m_pInPlaceFrame,&m_frameInfo,pMsg)==S_OK)
			return TRUE;

	return COleControl::PreTranslateMessage(pMsg);
}
/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::OnOcmCommand - Handle command messages

LRESULT CButtonCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
	lParam;
#else
	WORD wNotifyCode = HIWORD(lParam);
	wParam;
#endif
	switch (wNotifyCode)
	{
	case BN_CLICKED:
		// Fire click event when button is clicked
		FireClick();
		break;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl message handlers


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::CmdAbout - Displays About box in response to selection of
// menu item.

void CButtonCtrl::CmdAbout()
{
	AboutBox();
}


/////////////////////////////////////////////////////////////////////////////
// CButtonCtrl::OnGetInPlaceMenu - Return in-place menu

HMENU CButtonCtrl::OnGetInPlaceMenu(void)
{
	if (m_menuInPlace.m_hMenu == NULL)
		m_menuInPlace.LoadMenu(IDR_INPLACEMENU);

	return m_menuInPlace.m_hMenu;
}

void CButtonCtrl::OnOptionsOption1() 
{
	// TODO: Add your command handler code here
	
}

void CButtonCtrl::OnOptionsOption2() 
{
	// TODO: Add your command handler code here
	
}

void CButtonCtrl::OnOptionsOption3() 
{
	// TODO: Add your command handler code here
	
}
