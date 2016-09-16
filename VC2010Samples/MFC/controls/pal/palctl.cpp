// palctl.cpp : Implementation of the CPalCtrl OLE control class.
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
#include "pal.h"
#include "palctl.h"
#include "palppg.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Forward declarations

HPALETTE CopyPalette(HPALETTE srcpal);


IMPLEMENT_DYNCREATE(CPalCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPalCtrl, COleControl)
	//{{AFX_MSG_MAP(CPalCtrl)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CPalCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CPalCtrl)
	DISP_PROPERTY_EX(CPalCtrl, "Length", GetLength, SetLength, VT_I2)
	DISP_PROPERTY_EX(CPalCtrl, "Picture", GetPicture, SetPicture, VT_PICTURE)
	DISP_PROPERTY_PARAM(CPalCtrl, "Entry", GetEntry, SetEntry, VT_COLOR, VTS_I2)
	DISP_DEFVALUE(CPalCtrl, "Handle")
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CPalCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CPalCtrl, COleControl)
	//{{AFX_EVENT_MAP(CPalCtrl)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CPalCtrl, 2)
	PROPPAGEID(CPalPropPage::guid)
	PROPPAGEID(CLSID_CPicturePropPage)
END_PROPPAGEIDS(CPalCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPalCtrl, "PAL.PalCtrl.1",
	0x5733f76e, 0xbe58, 0x101a, 0xb5, 0x7a, 0x0, 0x0, 0xc0, 0xc3, 0xed, 0x5f)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CPalCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DPal =
		{ 0x37446b83, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DPalEvents =
		{ 0x37446b84, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwPalOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPalCtrl, IDS_PAL, _dwPalOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::CPalCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CPalCtrl

BOOL CPalCtrl::CPalCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_PAL,
			IDB_PAL,
			FALSE,                      //  Not insertable
			_dwPalOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::CPalCtrl - Constructor

CPalCtrl::CPalCtrl()
{
	InitializeIIDs(&IID_DPal, &IID_DPalEvents);

	m_iPalette = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::~CPalCtrl - Destructor

CPalCtrl::~CPalCtrl()
{
	if (m_iPalette) delete m_iPalette;
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::OnDraw - Drawing function

void CPalCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	CPalette *oldPalette;
	CPalette *pPalette;
	CPalette tempPalette;
	CBrush *oldBrush;
	CBrush *brush;
	int    i;
	int    height;
	int    stripeWidth;
	short  palNumEntries = 0;

	if (m_iPalette)
		pPalette = m_iPalette;
	else
	{
		// Use stock palette if control palette is NULL
		tempPalette.CreateStockObject(DEFAULT_PALETTE);
		pPalette = &tempPalette;
	}

	// Select and realize palette
	oldPalette = pdc->SelectPalette(pPalette, TRUE);
	pdc->RealizePalette();

	// Get number of palettes entries
	pPalette->GetObject(sizeof(palNumEntries), (LPVOID)&palNumEntries);

	height = rcBounds.Height();

	// Calculate width of stripes
	stripeWidth = rcBounds.Width();
	stripeWidth = stripeWidth / (int)palNumEntries;
	++stripeWidth;

	pdc->IntersectClipRect(rcBounds);

	// Draw each stripe
	for (i = 0; i < palNumEntries; i++)
	{
		brush = new CBrush;
		// A palette-relative brush is used for drawing.
		if (brush->CreateSolidBrush(PALETTEINDEX(i)) == TRUE)
		{
			// Setup brush
			oldBrush = pdc->SelectObject(brush);
			brush->UnrealizeObject();

			// Draw stripe
			pdc->PatBlt(rcBounds.left + i*stripeWidth, rcBounds.top,
				stripeWidth, height, PATCOPY);
			pdc->SelectObject(oldBrush);
		}
		delete brush;
	}

	// Back to old palette
	pdc->SelectPalette(oldPalette, TRUE);
	pdc->RealizePalette();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::DoPropExchange - Persistence support

void CPalCtrl::DoPropExchange(CPropExchange* pPX)
{
	short nLength;

	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// Get Length if not loading
	if (!pPX->IsLoading())
		nLength = GetLength();

	// Transfer property value to/from local variable
	PX_Short(pPX, _T("Length"), nLength, 20);

	// Set Length if loading
	if (pPX->IsLoading())
		SetLength(nLength);
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::Serialize - Persistence support

void CPalCtrl::Serialize(CArchive& ar)
{
	short nLength;
	long lEntry;
	short i;

	COleControl::Serialize(ar);

	nLength = GetLength();

	if (ar.IsLoading())
	{
		// Load each entry
		for (i = 0; i < nLength; i++)
		{
			// Load entry
			ar >> lEntry;
			SetEntry(i, lEntry);
		}
	}
	else
	{
		// Store each entry
		for (i = 0; i < nLength; i++)
		{
			// Store entry
			lEntry = GetEntry(i);
		   ar << lEntry;
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::OnResetState - Reset control to default state

void CPalCtrl::OnResetState()
{
	if (m_iPalette) delete m_iPalette;
	m_iPalette = NULL;

	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	SetModifiedFlag(TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::AboutBox - Display an "About" box to the user

void CPalCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_PAL);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::GetLength - Return the length of the palette.

short CPalCtrl::GetLength()
{
	short nLength;
	CPalette *pPalette;
	CPalette tempPalette;

	if (m_iPalette)
		pPalette = m_iPalette;
	else
	{
		// Use stock palette if control palette is NULL
		tempPalette.CreateStockObject(DEFAULT_PALETTE);
		pPalette = &tempPalette;
	}

	// Get number of entries
	pPalette->GetObject(sizeof(nLength), LPVOID(&nLength));

	return nLength;
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::SetLength - Set the length of the palette.  Causes the palette
// to be extended (with black entries) or truncated to the specified length.

void CPalCtrl::SetLength(short nNewValue)
{
	HPALETTE hpal;

	if (!m_iPalette)
	{
		// If control palette is NULL, set it to copy of stock palette
		hpal = CopyPalette((HPALETTE)GetStockObject(DEFAULT_PALETTE));
		if (!hpal)
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		else
		{
			m_iPalette = new CPalette();
			m_iPalette->Attach(hpal);
		}
	}

	// Resize palette
	if (!m_iPalette->ResizePalette(nNewValue))
		ThrowError(PAL_E_CANTRESIZEPALETTE, IDS_EXCEP_CANTRESIZEPALETTE);

	SetModifiedFlag(TRUE);
	InvalidateControl();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::GetPicture - Return a picture containing the palette of the
// palette control.

LPPICTUREDISP CPalCtrl::GetPicture()
{
	HDC       hdcScr;
	HBITMAP   hbmp;
	HPALETTE  hpal;
	CPictureHolder picHolder;

	// Create a picture using a 1x1 bitmap and a copy of our current
	// palette

	// Create 1x1 bitmap
	hdcScr = ::GetDC(NULL);
	hbmp = CreateBitmap(1, 1,
				(BYTE)GetDeviceCaps(hdcScr, PLANES),
				(BYTE)GetDeviceCaps(hdcScr, BITSPIXEL),
				NULL);
	::ReleaseDC(NULL, hdcScr);
	if (!hbmp)
		ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);

	if (m_iPalette)
	{
		// Make a copy of the palette we're using
		hpal = CopyPalette((HPALETTE)m_iPalette->m_hObject);
		if (!hpal)
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
	}
	else
		hpal = NULL;

	// Create picture using bitmap and palette
	picHolder.CreateFromBitmap(hbmp, hpal, TRUE);

	return picHolder.GetPictureDispatch();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::SetPicture - Set the control's palette to the palette of the
// passed picture.

void CPalCtrl::SetPicture(LPPICTUREDISP newValue)
{
	COleDispatchDriver driver;
	HPALETTE hpal1, hpal2;

	if (newValue)
	{
		// Obtain hPal property from picture
		driver.AttachDispatch(newValue, FALSE);
		driver.GetProperty(DISPID_PICT_HPAL, VT_HANDLE, (void*)&hpal1);
		if (hpal1)
		{
			// If palette object exists, free its HPAL
			if (m_iPalette)
				m_iPalette->Detach();
			// Else instantiate a new palette object
			else m_iPalette = new CPalette;

			// Copy the palette from the picture
			hpal2 = CopyPalette(hpal1);
			if (!hpal2)
				ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);

			// Attach new HPAL
			m_iPalette->Attach(hpal2);

			SetModifiedFlag(TRUE);
			InvalidateControl();
			return;
		}
	}

	// If new hPal not obtained, delete palette object so stock palette will
	// be used.
	if (m_iPalette)
	{
		delete m_iPalette;
		m_iPalette = NULL;
	}
	SetModifiedFlag(TRUE);
	InvalidateControl();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::GetEntry - Return a palette entry.

OLE_COLOR CPalCtrl::GetEntry(short nIndex)
{
	PALETTEENTRY palentry;
	CPalette *pPalette;
	CPalette tempPalette;

	if (m_iPalette)
		pPalette = m_iPalette;
	else
	{
		// Use stock palette if control palette is NULL
		tempPalette.CreateStockObject(DEFAULT_PALETTE);
		pPalette = &tempPalette;
	}

	// Get palette entry
	if (!pPalette->GetPaletteEntries(nIndex, 1, &palentry))
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return (OLE_COLOR)RGB(palentry.peRed, palentry.peGreen, palentry.peBlue);
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::SetEntry - Set a palette entry.

void CPalCtrl::SetEntry(short nIndex, OLE_COLOR newValue)
{
	COLORREF colorref;
	PALETTEENTRY    palentry;
	HPALETTE hpal;

	if (!m_iPalette)
	{
		// If control palette is NULL, set it to copy of stock palette
		hpal = CopyPalette((HPALETTE)GetStockObject(DEFAULT_PALETTE));
		if (!hpal)
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		else
		{
			m_iPalette = new CPalette();
			m_iPalette->Attach(hpal);
		}
	}

	// Build an entry and set it in the palette
	colorref = TranslateColor(newValue);
	palentry.peRed   = GetRValue(colorref);
	palentry.peGreen = GetGValue(colorref);
	palentry.peBlue  = GetBValue(colorref);
	palentry.peFlags = 0;

	if (!m_iPalette->SetPaletteEntries(nIndex, 1, &palentry))
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	SetModifiedFlag(TRUE);
	InvalidateControl();
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::OnMapPropertyToPage - Map picture property to picture page.

BOOL CPalCtrl::OnMapPropertyToPage(DISPID dispid, LPCLSID lpclsid,
	BOOL* pbPageOptional)
{
	switch(dispid)
	{
		case dispidPicture:
			*lpclsid = CLSID_CPicturePropPage;
			return TRUE;
	}
	return COleControl::OnMapPropertyToPage(dispid, lpclsid, pbPageOptional);
}


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl::OnEraseBkgnd - Simply return TRUE so background is not erased.

BOOL CPalCtrl::OnEraseBkgnd(CDC*)
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CopyPalette - Return a copy of a GDI palette object.

HPALETTE CopyPalette(HPALETTE srcpal)
{
	HGLOBAL hmem;
	HPALETTE destpal;
	PLOGPALETTE ppal;
	int nNumEntries;

	if (!srcpal)
		return NULL;

	GetObject(srcpal, sizeof(int), (LPSTR)&nNumEntries);

	if (nNumEntries == 0)
		return NULL;

	// Allocate buffer for palette info
	hmem = GlobalAlloc(LPTR, (WORD)(sizeof(LOGPALETTE) + nNumEntries * sizeof(PALETTEENTRY)));
	if (!hmem)
		return NULL;

	ppal = (PLOGPALETTE)GlobalLock(hmem);

	// Init palette header info
	ppal->palVersion  = 0x300;
	ppal->palNumEntries = (WORD)nNumEntries;

	// Copy entries
	GetPaletteEntries(srcpal, 0, (WORD)nNumEntries, ppal->palPalEntry);

	// Create palette
	destpal = CreatePalette(ppal);

	GlobalFree(hmem);
	return destpal;
}
