// licenctl.cpp : Implementation of the CLicensedCtrl OLE control class.
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
#include "licensed.h"
#include "licenctl.h"
#include "licenppg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLicensedCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLicensedCtrl, COleControl)
	//{{AFX_MSG_MAP(CLicensedCtrl)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CLicensedCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CLicensedCtrl)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CLicensedCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CLicensedCtrl, COleControl)
	//{{AFX_EVENT_MAP(CLicensedCtrl)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CLicensedCtrl, 1)
	PROPPAGEID(CLicensedPropPage::guid)
END_PROPPAGEIDS(CLicensedCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLicensedCtrl, "LICENSED.LicensedCtrl.1",
	0x973b27a3, 0xf232, 0x101a, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CLicensedCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DLicensed =
		{ 0x37446b80, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DLicensedEvents =
		{ 0x37446b81, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwLicensedOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLicensedCtrl, IDS_LICENSED, _dwLicensedOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::CLicensedCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CLicensedCtrl

BOOL CLicensedCtrl::CLicensedCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LICENSED,
			IDB_LICENSED,
			FALSE,                      //  Not insertable
			_dwLicensedOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("licensed.lic");

static const OLECHAR BASED_CODE _szLicString[] =
	OLESTR("Licensed Control Copyright (c) Microsoft Corporation");


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::CLicensedCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

//Looks for "licensed.lic" file in the current output directory (Release or Debug)

BOOL CLicensedCtrl::CLicensedCtrlFactory::VerifyUserLicense()
{
	BOOL foundLicFile = AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);

	// Display message box reporting whether or not license file was found
	if (foundLicFile)
		::MessageBox(0, _T("Found license file !"), _T("VerifyUserLicense"), MB_OK | MB_ICONINFORMATION);
	else
		::MessageBox(0, _T("Couldn't find license file !"), _T("VerifyUserLicense"), MB_OK | MB_ICONSTOP);

	return (foundLicFile);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::CLicensedCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CLicensedCtrl::CLicensedCtrlFactory::GetLicenseKey(DWORD,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::CLicensedCtrl - Constructor

CLicensedCtrl::CLicensedCtrl()
{
	InitializeIIDs(&IID_DLicensed, &IID_DLicensedEvents);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::~CLicensedCtrl - Destructor

CLicensedCtrl::~CLicensedCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::OnDraw - Drawing function

void CLicensedCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	TEXTMETRIC tm;
	CString line1("Licensed");
	CString line2("Control");

	// Draw caption

	CFont* pOldFont = SelectStockFont(pdc);
	GetStockTextMetrics(&tm);

	pdc->SetTextAlign(TA_CENTER | TA_TOP);
	pdc->ExtTextOut((rcBounds.left + rcBounds.right) / 2, rcBounds.top, ETO_CLIPPED | ETO_OPAQUE, rcBounds, line1,
		line1.GetLength(), NULL);
	pdc->ExtTextOut((rcBounds.left + rcBounds.right) / 2, rcBounds.top + tm.tmHeight, ETO_CLIPPED, rcBounds,
		line2, line2.GetLength(), NULL);
	pdc->SelectObject(pOldFont);
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::DoPropExchange - Persistence support

void CLicensedCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	if (pPX->IsLoading())
	{
		CFontHolder& stockFont = InternalGetFont();
		stockFont.InitializeFont();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::OnResetState - Reset control to default state

void CLicensedCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CLicensedCtrl::AboutBox - Display an "About" box to the user

void CLicensedCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_LICENSED);
	dlgAbout.DoModal();
}
