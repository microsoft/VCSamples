// xlistctl.cpp : Implementation of the CXlistCtrl OLE control class.
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
#include "xlist.h"
#include "xlistctl.h"
#include "xlistppg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// Numeric constants

const int LSTITEMSPACING       =   4;
const int MAXTEXTLEN        = 128;


/////////////////////////////////////////////////////////////////////////////
// Forward declarations

short GetFontHeight(LPFONTDISP lpfd);
long GetPictureHeight(LPPICTUREDISP lppd);
long GetPictureWidth(LPPICTUREDISP lppd);
void GetProperty(LPDISPATCH lpd, short dispId, short propType, void *value);
STDAPI_(int) XformWidthInHimetricToPixels(HDC hDC, int iWidthInHiMetric);
STDAPI_(int) XformHeightInHimetricToPixels(HDC hDC, int iHeightInHiMetric);

#define HIMETRIC_PER_INCH   2540      // number HIMETRIC units per inch
#define MAP_LOGHIM_TO_PIX(x,ppli)   MulDiv((ppli), (x), HIMETRIC_PER_INCH)


/////////////////////////////////////////////////////////////////////////////
// CItemData::CItemData - Constructor

CItemData::CItemData(const TCHAR *pstrText, LPFONTDISP lpFontDisp, LPPICTUREDISP lpPicDisp)
{
	pBack = NULL;
	pFore = NULL;

	// Init text
	if (pstrText)
		pText = new CString(pstrText);
	else
		pText = NULL;

	// Init picture holder
	if (lpPicDisp)
	{
	   pPicHolder = new CPictureHolder;
	   pPicHolder->SetPictureDispatch(lpPicDisp);
	}
	else pPicHolder = NULL;

	// Init font holder
	if (lpFontDisp)
	{
	   pFontHolder = new CFontHolder(NULL);
	   pFontHolder->InitializeFont(NULL, lpFontDisp);
	}
	else pFontHolder = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::CItemData - Destructor

CItemData::~CItemData()
{
	if (pBack) delete pBack;
	if (pFore) delete pFore;
	if (pText) delete pText;
	if (pFontHolder) delete pFontHolder;
	if (pPicHolder) delete pPicHolder;
}

/////////////////////////////////////////////////////////////////////////////
// CItemData::GetBackColor - Return the item's background color.

OLE_COLOR *CItemData::GetBackColor()
{
	return pBack;
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::SetBackColor - Set the item's background color.

void CItemData::SetBackColor(OLE_COLOR *pNewBack)
{
	if (pNewBack)
	{
		if (!pBack)
		{
			pBack = new OLE_COLOR;
		}
		*pBack = *pNewBack;
	}
	else
		if (pBack)
		{
			delete pBack;
			pBack = NULL;
		}
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::GetForeColor - Return the item's foreground color.

OLE_COLOR *CItemData::GetForeColor()
{
	return pFore;
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::SetForeColor - Set the item's foreground color.

void CItemData::SetForeColor(OLE_COLOR *pNewFore)
{
	if (pNewFore)
	{
		if (!pFore)
		{
			pFore = new OLE_COLOR;
		}
		*pFore = *pNewFore;
	}
	else
		if (pFore)
		{
			delete pFore;
			pFore = NULL;
		}
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::GetText - Return the item's text.

void CItemData::GetText(LPTSTR buffer, short szBuffer)
{
	if (pText)
	{
		_tcscpy_s(buffer, szBuffer, pText->GetBuffer(szBuffer));
		pText->ReleaseBuffer();
	}
	else
		_tcscpy_s(buffer, szBuffer, _T(""));
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::SetText - Set the item's text.

void CItemData::SetText(const TCHAR *pstrText)
{
	if (_tcslen(pstrText) > 0)
	{
		if (!pText)
		{
			pText = new CString(pstrText);
		}
		else *pText = pstrText;
	}
	else
		if (pText)
		{
			delete pText;
			pText = NULL;
		}
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::GetFont - Return the item's font.

CFontHolder *CItemData::GetFont()
{
	return pFontHolder;
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::SetFont - Set the item's font.

void CItemData::SetFont(LPFONTDISP pNewFontDisp)
{
   if (pNewFontDisp)
   {
		if (!pFontHolder)
		{
			pFontHolder = new CFontHolder(NULL);
		}
		pFontHolder->InitializeFont(NULL, pNewFontDisp);
	}
	else
		if (pFontHolder)
		{
			delete pFontHolder;
			pFontHolder = NULL;
		}
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::GetPicture - Return the item's picture.

CPictureHolder *CItemData::GetPicture()
{
	return pPicHolder;
}


/////////////////////////////////////////////////////////////////////////////
// CItemData::SetPicture - Set the item's picture.

void CItemData::SetPicture(LPPICTUREDISP pNewPicDisp)
{
	if (pNewPicDisp)
	{
		if (!pPicHolder)
		{
			pPicHolder = new CPictureHolder;
		}
		 pPicHolder->SetPictureDispatch(pNewPicDisp);
	}
	else
		if (pPicHolder)
		{
			delete pPicHolder;
			pPicHolder = NULL;
		}
}


IMPLEMENT_DYNCREATE(CXlistCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CXlistCtrl, COleControl)
	//{{AFX_MSG_MAP(CXlistCtrl)
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_WM_ERASEBKGND()
	ON_MESSAGE(OCM_DRAWITEM,    OnOcmDrawItem)
	ON_MESSAGE(OCM_MEASUREITEM, OnOcmMeasureItem)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CXlistCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CXlistCtrl)
	DISP_PROPERTY_NOTIFY(CXlistCtrl, "InvertFlag", m_invertFlag, OnInvertFlagChanged, VT_BOOL)
	DISP_FUNCTION(CXlistCtrl, "RemoveItem", RemoveItem, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CXlistCtrl, "Clear", Clear, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CXlistCtrl, "AddTextFontItem", AddTextFontItem, VT_EMPTY, VTS_I2 VTS_BSTR VTS_FONT)
	DISP_FUNCTION(CXlistCtrl, "AddTextItem", AddTextItem, VT_EMPTY, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CXlistCtrl, "AddPicItem", AddPicItem, VT_EMPTY, VTS_I2 VTS_PICTURE)
	DISP_PROPERTY_PARAM(CXlistCtrl, "ItemBackColor", GetItemBackColor, SetItemBackColor, VT_COLOR, VTS_I2)
	DISP_PROPERTY_PARAM(CXlistCtrl, "ItemForeColor", GetItemForeColor, SetItemForeColor, VT_COLOR, VTS_I2)
	DISP_PROPERTY_PARAM(CXlistCtrl, "ItemText", GetItemText, SetItemText, VT_BSTR, VTS_I2)
	DISP_PROPERTY_PARAM(CXlistCtrl, "ItemFont", GetItemFont, SetItemFont, VT_FONT, VTS_I2)
	DISP_PROPERTY_PARAM(CXlistCtrl, "ItemPicture", GetItemPicture, SetItemPicture, VT_PICTURE, VTS_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CXlistCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CXlistCtrl, COleControl)
	//{{AFX_EVENT_MAP(CXlistCtrl)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CXlistCtrl, 1)
	PROPPAGEID(CXlistPropPage::guid)
END_PROPPAGEIDS(CXlistCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CXlistCtrl, "XLIST.XlistCtrl.1",
	0x37446b99, 0x5870, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CXlistCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DXlist =
		{ 0x37446b9a, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };
const IID BASED_CODE IID_DXlistEvents =
		{ 0x37446b9b, 0x5870, 0x101b, { 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwXlistOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CXlistCtrl, IDS_XLIST, _dwXlistOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::CXlistCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CXlistCtrl

BOOL CXlistCtrl::CXlistCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_XLIST,
			IDB_XLIST,
			FALSE,                      //  Not insertable
			_dwXlistOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::CXlistCtrl - Constructor

CXlistCtrl::CXlistCtrl()
{
	InitializeIIDs(&IID_DXlist, &IID_DXlistEvents);

	m_itemDefHeight = 0;
	m_sBorderStyle = 1;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::~CXlistCtrl - Destructor

CXlistCtrl::~CXlistCtrl()
{
	// Cleanup any and all CItemData objects

	for (int i=0; i<=m_itemData.GetUpperBound(); i++)
	{
		CItemData* pItem = (CItemData*)m_itemData.GetAt(i);

		if (pItem != NULL)
			delete pItem;
	}

	m_itemData.RemoveAll();
}


BOOL CXlistCtrl::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_DOWN || pMsg->wParam == VK_UP)
		{
			SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
			return TRUE;
		}
	}
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnDraw - Drawing function

void CXlistCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect&)
{
	LPRECT      lpr;
	CBrush      br;

	lpr = (LPRECT)(LPCRECT)rcBounds;

	// Paint background with the ambient background color
	br.CreateSolidBrush(TranslateColor(AmbientBackColor()));
	pdc->FillRect(lpr, &br);

	// Adjust rectangle size to account for listbox idiosyncracies
	// (it paints its own nonclient stuff during WM_PAINT)
	CRect rect(rcBounds);

	if (!pdc->IsKindOf(RUNTIME_CLASS(CPaintDC)))
	{
		if (m_bUIActive && m_pRectTracker != NULL)
		{
			UINT nAdjust = 2 * m_pRectTracker->m_nHandleSize;
			rect.right -= nAdjust;
			rect.bottom -= nAdjust;
		}

		if (m_bInPlaceActive && (GetStyle() & WS_VSCROLL))
			rect.right -= GetSystemMetrics(SM_CXVSCROLL);
	}

	DoSuperclassPaint(pdc, rect);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::DoPropExchange - Persistence support

void CXlistCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("InvertFlag"), m_invertFlag, TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnResetState - Reset control to default state

void CXlistCtrl::OnResetState()
{
	Clear();

	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::AboutBox - Display an "About" box to the user

void CXlistCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_XLIST);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CXlistCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("LISTBOX");
	cs.style |= LBS_STANDARD | LBS_OWNERDRAWVARIABLE;
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::IsSubclassedControl - This is a subclassed control

BOOL CXlistCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnOcmCommand - Handle command messages

LRESULT CXlistCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
	lParam;
#else
	WORD wNotifyCode = HIWORD(lParam);
	wParam;
#endif
	wNotifyCode;
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnInvertFlagChanged - Respond when the invert flag is changed.

void CXlistCtrl::OnInvertFlagChanged()
{
	SetModifiedFlag(TRUE);
	InvalidateControl();
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemBackColor - Return an item's background color.

OLE_COLOR CXlistCtrl::GetItemBackColor(short nIndex)
{
	OLE_COLOR *pColor;
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		pColor = pItemData->GetBackColor();
		if (pColor)
			return *pColor;
	}
	return (OLE_COLOR)-1;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SetItemBackColor - Set an item's background color.

void CXlistCtrl::SetItemBackColor(short nIndex, OLE_COLOR newValue)
{
	OLE_COLOR *pColor;
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		newValue == -1 ? pColor = NULL : pColor = &newValue;

		TRY
		{
			pItemData->SetBackColor(pColor);
		}
		CATCH(CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemForeColor - Return an item's foreground color.

OLE_COLOR CXlistCtrl::GetItemForeColor(short nIndex)
{
	OLE_COLOR *pColor;
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		pColor = pItemData->GetForeColor();
		if (pColor)
			return *pColor;
	}
	return (OLE_COLOR)-1;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SetItemForeColor - Set an item's foreground color.

void CXlistCtrl::SetItemForeColor(short nIndex, OLE_COLOR newValue)
{
	OLE_COLOR *pColor;
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		newValue == -1 ? pColor = NULL : pColor = &newValue;
		TRY
		{
			pItemData->SetForeColor(pColor);
		}
		CATCH (CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemText - Get an item's text.

BSTR CXlistCtrl::GetItemText(short nIndex)
{
	TCHAR textBuffer[MAXTEXTLEN];
	LPTSTR lpTextBuffer = (LPTSTR)textBuffer;

	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		pItemData->GetText(lpTextBuffer, sizeof(textBuffer)/sizeof(*textBuffer));

		CString s = lpTextBuffer;
		return s.AllocSysString();
	}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SetItemText - Set an item's text.

void CXlistCtrl::SetItemText(short nIndex, LPCTSTR lpszNewValue)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		TRY
		{
			pItemData->SetText(lpszNewValue);
		}
		CATCH (CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemFont - Return an item's font.

LPFONTDISP CXlistCtrl::GetItemFont(short nIndex)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		CFontHolder *pFontHolder = pItemData->GetFont();
		if (pFontHolder)
			return pFontHolder->GetFontDispatch();
	}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SetItemFont - Set an item's font.

void CXlistCtrl::SetItemFont(short nIndex, LPFONTDISP newValue)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		TRY
		{
			pItemData->SetFont(newValue);
		}
		CATCH (CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		// Update item positions because font size may have changed
		UpdateItems();

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl:GetItemPicture - Get an item's picture.

LPPICTUREDISP CXlistCtrl::GetItemPicture(short nIndex)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		CPictureHolder *pPictureHolder = pItemData->GetPicture();
		if (pPictureHolder)
			return pPictureHolder->GetPictureDispatch();
	}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SetItemPicture - Set an item's picture.

void CXlistCtrl::SetItemPicture(short nIndex, LPPICTUREDISP newValue)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		CItemData *pItemData = (CItemData *)m_itemData.GetAt(nIndex);
		TRY
		{
			pItemData->SetPicture(newValue);
		}
		CATCH (CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		// Update item positions because picture size may have changed
		UpdateItems();

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::AddTextItem - Add a text item.

void CXlistCtrl::AddTextItem(short nIndex, LPCTSTR lpstrText)
{
	AddItem(nIndex, lpstrText, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::AddTextFontItem - Add a text item which has its own font.

void CXlistCtrl::AddTextFontItem(short nIndex, LPCTSTR lpstrText, LPFONTDISP font)
{
	AddItem(nIndex, lpstrText, font, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::AddPicItem - Add a picture item.

void CXlistCtrl::AddPicItem(short nIndex, LPPICTUREDISP pic)
{
	AddItem(nIndex, NULL, NULL, pic);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::AddItem - Add an item.

void CXlistCtrl::AddItem(short nIndex, LPCTSTR lpstrText, LPFONTDISP lpFontDisp, LPPICTUREDISP lpPicDisp)
{
	if ((int)nIndex <= m_itemData.GetSize())
	{
		// Init item data
		CItemData* pItemData = NULL;

		TRY
		{
			pItemData = new CItemData(lpstrText, lpFontDisp, lpPicDisp);
		}
		CATCH (CMemoryException, e)
		{
			ThrowError(CTL_E_OUTOFMEMORY, AFX_IDP_E_OUTOFMEMORY);
		}
		END_CATCH

		// Add item data to collection
		m_itemData.InsertAt(nIndex, pItemData);

		// Add item text to listbox
		SendMessage(LB_INSERTSTRING, nIndex, (LONG_PTR)lpstrText);

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::RemoveItem - Remove an item.

void CXlistCtrl::RemoveItem(short nIndex)
{
	if ((int)nIndex <= m_itemData.GetSize() - 1)
	{
		// Free item data
		delete m_itemData.GetAt(nIndex);

		// Remove item from item array
		m_itemData.RemoveAt(nIndex);

		// Remove item text from listbox
		SendMessage(LB_DELETESTRING, nIndex, 0L);

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::Clear - Clear all items in the list.

void CXlistCtrl::Clear()
{
	if (m_itemData.GetSize() > 0)
	{
		// For each item
		for (int i = 0; i < m_itemData.GetSize(); i++)
		{
			// Free item data
			delete m_itemData.GetAt( i );
		}

		// Remove all items from item array
		m_itemData.RemoveAll();

		// Remove all text from listbox
		SendMessage(LB_RESETCONTENT, 0, 0L);

		SetModifiedFlag(TRUE);
		InvalidateControl();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnAmbientPropertyChange - If the ambient font has changed,
// update default item height and item positions.

void CXlistCtrl::OnAmbientPropertyChange(DISPID dispid)
{
	if (dispid == DISPID_AMBIENT_FONT)
	{
		// Update item default height
		UpdateDefHeight();

		// Update item positions
		UpdateItems();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnEraseBkgnd

BOOL CXlistCtrl::OnEraseBkgnd(CDC* pDC)
{
	return COleControl::OnEraseBkgnd(pDC);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnSetClientSite - Set the default item height.

void CXlistCtrl::OnSetClientSite()
{
	COleControl::OnSetClientSite();

	UpdateDefHeight();
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnOcmDrawItem - Draw an item.

LRESULT CXlistCtrl::OnOcmDrawItem(WPARAM, LPARAM lParam)
{
	DrawItem((LPDRAWITEMSTRUCT)lParam);

	return 1;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::DrawItem - Draw an item.

void CXlistCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CItemData *pItemData;
	CDC *pdc;
	CPen* pOldPen;

	// Return if id is invalid
	if ( (lpDrawItemStruct->itemID == (UINT)-1) ||
		 ((int)lpDrawItemStruct->itemID >= m_itemData.GetSize()))
		return;

	// Get item data
	pItemData = (CItemData *)m_itemData.GetAt(lpDrawItemStruct->itemID);

	// Construct CDC object for drawing
	pdc = CDC::FromHandle(lpDrawItemStruct->hDC);

	switch (lpDrawItemStruct->itemAction)
	{
		case ODA_DRAWENTIRE:

			 // Brush item background and set background color
			SelectItemBackColor(pItemData, &lpDrawItemStruct->rcItem, pdc);

			// Draw item's picture
			DrawItemPicture(pItemData, &lpDrawItemStruct->rcItem, pdc);

			// Draw item's text
			DrawItemText(pItemData, &lpDrawItemStruct->rcItem, pdc);

			// Break if item is not selected
			if (lpDrawItemStruct->itemState != ODS_SELECTED)
				break;

		case ODA_SELECT:

			// If invert flag is set, invert item when selected
			if (m_invertFlag)
				pdc->InvertRect(&lpDrawItemStruct->rcItem);
			break;

		case ODA_FOCUS:

			// Draw focus rect when item gets the focus
			pOldPen = (CPen*)pdc->SelectStockObject(BLACK_PEN);
			pdc->DrawFocusRect(&lpDrawItemStruct->rcItem);
			pdc->SelectObject(pOldPen);
			break;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SelectItemBackColor - Brushes an item's background and
// selects the background color

void CXlistCtrl::SelectItemBackColor(CItemData *pItemData, LPRECT lpRect, CDC *pdc)
{
	OLE_COLOR color;
	OLE_COLOR *pColor;

	// Get item background color
	pColor = pItemData->GetBackColor();

	// If background color is not specified, use ambient background color
	if (!pColor)
	{
		color = AmbientBackColor();
		pColor = (OLE_COLOR *)&color;
	}

	// Brush background
	CBrush brush;
	brush.CreateSolidBrush(TranslateColor(*pColor));
	pdc->FillRect(lpRect, &brush);

	// Set background color
	pdc->SetBkMode(TRANSPARENT);
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::DrawItemPicture - Draws an item's picture.  Draws nothing if
// the item has no picture.

void CXlistCtrl::DrawItemPicture(CItemData *pItemData, LPRECT lpRect, CDC *pdc)
{
	CPictureHolder *pPicHolder;
	LPPICTUREDISP pPicDisp;

	int picHeight;
	int picWidth;
	long tempPicHeight;
	long tempPicWidth;

	// Get item picture
	pPicHolder = pItemData->GetPicture();

	// Draw item picture
	if (pPicHolder)
	{
		// Get height and width of picture
		pPicDisp = pPicHolder->GetPictureDispatch();
		tempPicHeight = GetPictureHeight(pPicDisp);
		tempPicWidth = GetPictureWidth(pPicDisp);
		pPicDisp->Release();

		// Convert height and width to pixels
		picHeight = XformHeightInHimetricToPixels(pdc->m_hDC, (int)LOWORD(tempPicHeight));
		picWidth = XformWidthInHimetricToPixels(pdc->m_hDC, (int)LOWORD(tempPicWidth));

		// Set up draw rect
		lpRect->right = lpRect->left + picWidth;
		lpRect->bottom = lpRect->top + picHeight;

		// Center rect
		lpRect->top += LSTITEMSPACING/2;
		lpRect->bottom += LSTITEMSPACING/2;

		// Draw picture
		pPicHolder->Render(pdc, *lpRect, *lpRect);
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::DrawItemText - Draws an item's text.  Draws nothing if the
// item has no text.

void CXlistCtrl::DrawItemText(CItemData *pItemData, LPRECT lpRect, CDC *pdc)
{
	TCHAR textBuffer[MAXTEXTLEN];
	LPTSTR lpTextBuffer = (LPTSTR)textBuffer;
	USHORT usLen;
	CFont* pOldFont;

	// Get item text
	pItemData->GetText(lpTextBuffer,
		sizeof(textBuffer)/sizeof(*textBuffer));

	// If item has text
	usLen = (USHORT)_tcslen(lpTextBuffer);
	if (usLen)
	{
		// Set item foreground color
		SelectItemForeColor(pItemData, pdc);

		// Select item font
		CFontHolder fontHolder(NULL);
		pOldFont = SelectItemFont(pItemData, pdc, fontHolder);

		// Draw text
		pdc->ExtTextOut(lpRect->left, lpRect->top, ETO_CLIPPED, lpRect, lpTextBuffer, usLen, NULL);

		// Reselect old font
		pdc->SelectObject(pOldFont);
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SelectItemForeColor - Selects item's foreground color

void CXlistCtrl::SelectItemForeColor(CItemData *pItemData, CDC *pdc)
{
	OLE_COLOR color;
	OLE_COLOR *pColor;

	// Get item foreground color
	pColor = pItemData->GetForeColor();
	if (!pColor)
	{
		// If foreground color is not specified, use ambient foreground color
		color = AmbientForeColor();
		pColor = (OLE_COLOR *)&color;
	}
	pdc->SetTextColor(TranslateColor(*pColor));
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::SelectItemFont - Selects item's font

CFont* CXlistCtrl::SelectItemFont(CItemData *pItemData, CDC *pdc,
	CFontHolder& fontHolder)
{
	CFontHolder *pFontHolder;
	CFont* pOldFont;
	LPFONTDISP pFontDisp;

	// Get item font
	pFontHolder = pItemData->GetFont();

	// If font is not specified, use ambient font
	if (!pFontHolder)
	{
		pFontHolder = &fontHolder;
		pFontDisp = AmbientFont();
		pFontHolder->InitializeFont(NULL, pFontDisp);
		if (pFontDisp != NULL)
			pFontDisp->Release();
	}

	pOldFont = SelectFontObject(pdc, *pFontHolder);
	return pOldFont;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::OnOcmMeasureItem - Return the height of an item.

LRESULT CXlistCtrl::OnOcmMeasureItem(WPARAM, LPARAM lParam)
{
	MeasureItem((LPMEASUREITEMSTRUCT)lParam);

	return 1;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::MeasureItem - Return the height of an item.

void CXlistCtrl::MeasureItem
(
	LPMEASUREITEMSTRUCT lpMI
)
{
	CItemData *pItemData;
	int textHeight;
	int picHeight;
	int tempHeight;

	// Return if id is invalid
	if ((lpMI->itemID == 0xffff) || ((int)lpMI->itemID >= m_itemData.GetSize()))
		return;

	pItemData = (CItemData *)m_itemData.GetAt(lpMI->itemID);

	// Get item's text height - zero if item has no text
	textHeight = GetItemTextHeight(pItemData);

	// Get item's picture height - zero if item has no picture
	picHeight = GetItemPictureHeight(pItemData);

	// Calculate item height using font height, picture height and spacing

	// tempHeight = max of textHeight and picHeight
	tempHeight = (textHeight > picHeight)  ? textHeight : picHeight;

	// if zero, set to default item height, else add item spacing
	tempHeight = (tempHeight == 0) ? m_itemDefHeight : tempHeight + LSTITEMSPACING;

	lpMI->itemHeight = tempHeight;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemTextHeight - Return an item's text height.  Returns
// zero if the item has no text.

int CXlistCtrl::GetItemTextHeight(CItemData *pItemData)
{
	TCHAR textBuffer[MAXTEXTLEN];
	LPTSTR lpTextBuffer = (LPTSTR)textBuffer;

	CFontHolder *pFontHolder;
	LPFONTDISP pFontDisp;
	int textHeight;

	// Get item text
	pItemData->GetText(lpTextBuffer,
		sizeof(textBuffer)/sizeof(*textBuffer));

	// If item has text
	if (_tcslen(lpTextBuffer) > 0)
	{
		// Get item font
		pFontHolder = pItemData->GetFont();

		if (pFontHolder)
		{
			// Get font dispatch ID
			pFontDisp = pFontHolder->GetFontDispatch();

			// Get font height using dispatch ID
			textHeight = GetFontHeight(pFontDisp);
			if (pFontDisp != NULL)
				pFontDisp->Release();

			textHeight += LSTITEMSPACING;
		}
		else
			//If item font is not specified, use default item height
			textHeight = m_itemDefHeight;
	}
	else
		textHeight = 0;

	return textHeight;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::GetItemPictureHeight - Return an item's picture height.
// Returns zero if the item has no picture.

int CXlistCtrl::GetItemPictureHeight(CItemData *pItemData)
{
	CPictureHolder *pPicHolder;
	LPPICTUREDISP pPicDisp;
	long tempPicHeight;
	HDC dc;
	int picHeight;

	// Get item picture
	pPicHolder = pItemData->GetPicture();

	// If item has picture
	if (pPicHolder)
	{
		// Get picture height
		pPicDisp = pPicHolder->GetPictureDispatch();
		tempPicHeight = GetPictureHeight(pPicDisp);
		pPicDisp->Release();

		// Convert height to pixels
		dc = ::GetDC(m_hWnd);
		picHeight = XformHeightInHimetricToPixels(dc, (int)LOWORD(tempPicHeight));
		::ReleaseDC(m_hWnd, dc);
	}
	else
		picHeight = 0;

	return picHeight;
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::UpdateItems - Readds all items to reflect changes in size

void CXlistCtrl::UpdateItems()
{
	CItemData *pItemData;
	TCHAR textBuffer[MAXTEXTLEN];
	LPTSTR lpTextBuffer = (LPTSTR)textBuffer;

	if (m_itemData.GetSize() > 0)
	{
		// Delete items
		SendMessage(LB_RESETCONTENT, 0, 0L);

		// Readd items
		for (int i = 0; i < m_itemData.GetSize(); i++)
		{
			pItemData = (CItemData *)m_itemData.GetAt(i);
			pItemData->GetText(lpTextBuffer, sizeof(textBuffer)/sizeof(*textBuffer));

			// Add item text to listbox
			SendMessage(LB_INSERTSTRING, i, (LONG_PTR)lpTextBuffer);
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl::UpdateDefHeight - Update the default item height

void CXlistCtrl::UpdateDefHeight()
{
	CFontHolder fontHolder(NULL);
	LPFONTDISP pFontDisp;

	// Get height of ambient font
	pFontDisp = AmbientFont();

	if (pFontDisp != NULL)
	{
		m_itemDefHeight = GetFontHeight(pFontDisp);
		pFontDisp->Release();
	}
	if (m_itemDefHeight == 0)
	{
		// Initialize with default font
		fontHolder.InitializeFont(NULL, NULL);
		pFontDisp = fontHolder.GetFontDispatch();
		m_itemDefHeight = GetFontHeight(pFontDisp);
		pFontDisp->Release();
	}

	m_itemDefHeight += LSTITEMSPACING;
}


/////////////////////////////////////////////////////////////////////////////
// GetFontHeight - Return the height of the font with the specified
// dispatch id.

short GetFontHeight(LPFONTDISP lpfd)
{
	short fontHeight = 0;
	GetProperty(lpfd, DISPID_FONT_SIZE, VT_I2, (void*)&fontHeight);
	return fontHeight;
}


/////////////////////////////////////////////////////////////////////////////
// GetPictureHeight - Return the height of the picture with the specified
// dispatch id.

long GetPictureHeight(LPPICTUREDISP lppd)
{
	long picHeight = 0;
	GetProperty(lppd, DISPID_PICT_HEIGHT, VT_I4, (void*)&picHeight);
	return picHeight;
}


/////////////////////////////////////////////////////////////////////////////
// GetPictureWidth - Return the width of the picture with the specified
// dispatch id.

long GetPictureWidth(LPPICTUREDISP lppd)
{
	long picWidth = 0;
	GetProperty(lppd, DISPID_PICT_WIDTH, VT_I4, (void*)&picWidth);
	return picWidth;
}


/////////////////////////////////////////////////////////////////////////////
// GetProperty - Return the property with the specified dispatch id.

void GetProperty(LPDISPATCH lpd, short dispId, short propType, void *value)
{
	COleDispatchDriver driver;

	if (lpd)
	{
		driver.AttachDispatch(lpd, TRUE);
		if (driver.m_lpDispatch != NULL)
		{
			TRY
			{
				driver.GetProperty(dispId, propType, value);
			}
			END_TRY
			driver.DetachDispatch();
		}
	}
}


/////////////////////////////////////////////////////////////////////////////
// XformWidthInHimetricToPixels - Transform the specified himetric width
// to pixels.

STDAPI_(int) XformWidthInHimetricToPixels(HDC hDC, int iWidthInHiMetric)
{
	int     iXppli;     // Pixels per logical inch along width
	int     iWidthInPix;
	BOOL    fSystemDC=FALSE;

	if (NULL==hDC)
	{
		hDC=GetDC(NULL);
		fSystemDC=TRUE;
	}

	iXppli = GetDeviceCaps (hDC, LOGPIXELSX);

	// We've got logical HIMETRIC along the display, convert to pixel units
	iWidthInPix = MAP_LOGHIM_TO_PIX(iWidthInHiMetric, iXppli);

	if (fSystemDC)
		ReleaseDC(NULL, hDC);

	return iWidthInPix;
}


/////////////////////////////////////////////////////////////////////////////
// XformHeightInHimetricToPixels - Transform the specified himetric height
// to pixels.

STDAPI_(int) XformHeightInHimetricToPixels(HDC hDC, int iHeightInHiMetric)
{
	int     iYppli;     // Pixels per logical inch along height
	int     iHeightInPix;
	BOOL    fSystemDC=FALSE;

	if (NULL==hDC)
	{
		hDC=GetDC(NULL);
		fSystemDC=TRUE;
	}

	iYppli = GetDeviceCaps (hDC, LOGPIXELSY);

	// We've got logical HIMETRIC along the display, convert to pixel units
	iHeightInPix = MAP_LOGHIM_TO_PIX(iHeightInHiMetric, iYppli);

	if (fSystemDC)
		ReleaseDC(NULL, hDC);

	return iHeightInPix;
}
