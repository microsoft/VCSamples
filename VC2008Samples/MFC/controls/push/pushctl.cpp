// pushctl.cpp : Implementation of the CPushCtrl OLE control class.
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
#include "push.h"
#include "pushctl.h"
#include "pushppg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CPushCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPushCtrl, COleControl)
	//{{AFX_MSG_MAP(CPushCtrl)
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_MESSAGE(OCM_DRAWITEM, OnOcmDrawItem)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CPushCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CPushCtrl)
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_CAPTION()
	DISP_STOCKPROP_ENABLED()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CPushCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CPushCtrl, COleControl)
	//{{AFX_EVENT_MAP(CPushCtrl)
	EVENT_CUSTOM("CustomClick", FireCustomClick, VTS_BSTR  VTS_I2)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CPushCtrl, 1)
	PROPPAGEID(CPushPropPage::guid)
END_PROPPAGEIDS(CPushCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPushCtrl, "PUSH.PushCtrl.1",
	0x75303863, 0xb925, 0x101a, 0xb5, 0x7a, 0x0, 0x0, 0xc0, 0xc3, 0xed, 0x5f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CPushCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DPush =
		{ 0x37446b86, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DPushEvents =
		{ 0x37446b87, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwPushOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPushCtrl, IDS_PUSH, _dwPushOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::CPushCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CPushCtrl

BOOL CPushCtrl::CPushCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_PUSH,
			IDB_PUSH,
			FALSE,                      //  Not insertable
			_dwPushOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::CPushCtrl - Constructor

CPushCtrl::CPushCtrl()
{
	InitializeIIDs(&IID_DPush, &IID_DPushEvents);

	SetInitialSize(28, 28);
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::~CPushCtrl - Destructor

CPushCtrl::~CPushCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::OnDraw - Drawing function

void CPushCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	DoSuperclassPaint(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::DoPropExchange - Persistence support

void CPushCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::OnResetState - Reset control to default state

void CPushCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::AboutBox - Display an "About" box to the user

void CPushCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_PUSH);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CPushCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	cs.style |= BS_PUSHBUTTON | BS_OWNERDRAW;
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::IsSubclassedControl - This is a subclassed control

BOOL CPushCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::OnOcmCommand - Handle command messages

LRESULT CPushCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	lParam;
	WORD wNotifyCode = HIWORD(wParam);
#else
	wParam;
	WORD wNotifyCode = HIWORD(lParam);
#endif

	switch (wNotifyCode)
	{
	case BN_CLICKED:

		// Fire custom click event, sending caption
		CString strCaption = InternalGetText();
		FireCustomClick(strCaption, (short) strCaption.GetLength());

		break;
	}

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::OnEraseBkgnd - Simply return TRUE so background is not erased.

BOOL CPushCtrl::OnEraseBkgnd(CDC*)
{
	return TRUE;
}


////////////////////////////////////////////////////////////////////////////
// CPushCtrl::OnOcmDrawItem - Draw an item.

LRESULT CPushCtrl::OnOcmDrawItem(WPARAM, LPARAM lParam)
{
	DrawItem((LPDRAWITEMSTRUCT)lParam);

	return 1;
}


/////////////////////////////////////////////////////////////////////////////
// CPushCtrl::DrawItem - Draw an item.

void CPushCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC *pdc;
	int bmpId;
	CBitmap bitmap;
	BITMAP  bmp;
	CPictureHolder picHolder;
	CRect rcSrcBounds;

	CPen* pOldPen;
	RECT    rect;
	SHORT   inflate;

	pdc = CDC::FromHandle(lpDrawItemStruct->hDC);

	switch (lpDrawItemStruct->itemAction)
	{
		case ODA_DRAWENTIRE:
		case ODA_SELECT:
			// Load "up" or "down" bitmap depending on selection state
			bmpId = (lpDrawItemStruct->itemState & ODS_SELECTED) ? IDB_DOWNBITMAP
				: IDB_UPBITMAP;
			bitmap.LoadBitmap(bmpId);
			bitmap.GetObject(sizeof(BITMAP), &bmp);
			rcSrcBounds.right = bmp.bmWidth;
			rcSrcBounds.bottom = bmp.bmHeight;

			// Create picture and render
			picHolder.CreateFromBitmap((HBITMAP)bitmap.m_hObject, NULL, FALSE);
			picHolder.Render(pdc, lpDrawItemStruct->rcItem, rcSrcBounds);

			break;

		case ODA_FOCUS:
			// Just draw focus rect
			pOldPen = (CPen*)pdc->SelectStockObject(BLACK_PEN);
			if (lpDrawItemStruct->itemState & ODS_FOCUS)
			{
				CopyRect((LPRECT)&rect, (LPRECT)&lpDrawItemStruct->rcItem);
				inflate = (SHORT)min(3,min(rect.right  - rect.left + 1,
					rect.bottom - rect.top  + 1) / 5);
				InflateRect(&rect, -inflate, -inflate);
				pdc->DrawFocusRect(&rect);
			}
			pdc->SelectObject(pOldPen);
			break;
	}
}
