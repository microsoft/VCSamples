// wordpvw.cpp : implementation of the CWordPadView class
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
#include "wordpad.h"
#include "cntritem.h"
#include "srvritem.h"

#include "wordpdoc.h"
#include "wordpvw.h"
#include "formatta.h"
#include "datedial.h"
#include "formatpa.h"
#include "formatba.h"
#include "ruler.h"
#include "strings.h"
#include "colorlis.h"
#include "pageset.h"

extern CLIPFORMAT cfEmbeddedObject;
extern CLIPFORMAT cfRTO;

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

BOOL CCharFormat::operator==(CCharFormat& cf)
{
	return
	dwMask == cf.dwMask
	&& dwEffects == cf.dwEffects
	&& yHeight == cf.yHeight
	&& yOffset == cf.yOffset
	&& crTextColor == cf.crTextColor
	&& bPitchAndFamily == cf.bPitchAndFamily
	&& (lstrcmp(szFaceName, cf.szFaceName) == 0);
}

BOOL CParaFormat::operator==(PARAFORMAT2& pf)
{
	if(
		dwMask != pf.dwMask
		|| wNumbering != pf.wNumbering
		|| wEffects != pf.wEffects
		|| dxStartIndent != pf.dxStartIndent
		|| dxRightIndent != pf.dxRightIndent
		|| dxOffset != pf.dxOffset
		|| cTabCount != pf.cTabCount
		|| dySpaceBefore != pf.dySpaceBefore
		|| dySpaceAfter != pf.dySpaceAfter
		|| dyLineSpacing != pf.dyLineSpacing
		|| sStyle != pf.sStyle
		|| bLineSpacingRule != pf.bLineSpacingRule
		|| bOutlineLevel != pf.bOutlineLevel
		|| wShadingWeight != pf.wShadingWeight
		|| wShadingStyle != pf.wShadingStyle
		|| wNumberingStart != pf.wNumberingStart
		|| wNumberingStyle != pf.wNumberingStyle
		|| wNumberingTab != pf.wNumberingTab
		|| wBorderSpace != pf.wBorderSpace
		|| wBorderWidth != pf.wBorderWidth
		|| wBorders != pf.wBorders
		)
	{
		return FALSE;
	}
	for (int i=0;i<pf.cTabCount;i++)
	{
		if (rgxTabs[i] != pf.rgxTabs[i])
			return FALSE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadView

IMPLEMENT_DYNCREATE(CWordPadView, CRichEditView)

//WM_SETTINGCHANGE -- default printer might have changed
//WM_FONTCHANGE -- pool of fonts changed
//WM_DEVMODECHANGE -- printer settings changes

BEGIN_MESSAGE_MAP(CWordPadView, CRichEditView)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	//{{AFX_MSG_MAP(CWordPadView)
	ON_COMMAND(ID_PAGE_SETUP, OnPageSetup)
	ON_COMMAND(ID_CHAR_BOLD, OnCharBold)
	ON_UPDATE_COMMAND_UI(ID_CHAR_BOLD, OnUpdateCharBold)
	ON_COMMAND(ID_CHAR_ITALIC, OnCharItalic)
	ON_UPDATE_COMMAND_UI(ID_CHAR_ITALIC, OnUpdateCharItalic)
	ON_COMMAND(ID_CHAR_UNDERLINE, OnCharUnderline)
	ON_UPDATE_COMMAND_UI(ID_CHAR_UNDERLINE, OnUpdateCharUnderline)
	ON_COMMAND(ID_PARA_CENTER, OnParaCenter)
	ON_UPDATE_COMMAND_UI(ID_PARA_CENTER, OnUpdateParaCenter)
	ON_COMMAND(ID_PARA_LEFT, OnParaLeft)
	ON_UPDATE_COMMAND_UI(ID_PARA_LEFT, OnUpdateParaLeft)
	ON_COMMAND(ID_PARA_RIGHT, OnParaRight)
	ON_UPDATE_COMMAND_UI(ID_PARA_RIGHT, OnUpdateParaRight)
	ON_WM_CREATE()
	ON_COMMAND(ID_INSERT_DATE_TIME, OnInsertDateTime)
	ON_COMMAND(ID_FORMAT_PARAGRAPH, OnFormatParagraph)
	ON_COMMAND(ID_FORMAT_TABS, OnFormatTabs)
	ON_COMMAND(ID_COLOR16, OnColorDefault)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_MEASUREITEM()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, OnFilePrint)
	ON_WM_DROPFILES()
	ON_WM_PALETTECHANGED()
	ON_WM_QUERYNEWPALETTE()
	ON_WM_SETTINGCHANGE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_INSERT_BULLET, CRichEditView::OnBullet)
	ON_UPDATE_COMMAND_UI(ID_INSERT_BULLET, CRichEditView::OnUpdateBullet)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_COLOR0, ID_COLOR16, OnColorPick)
	ON_EN_CHANGE(AFX_IDW_PANE_FIRST, OnEditChange)
	ON_WM_MOUSEACTIVATE()
	ON_REGISTERED_MESSAGE(CWordPadApp::m_nPrinterChangedMsg, OnPrinterChangedMsg)
	ON_NOTIFY(FN_GETFORMAT, ID_VIEW_FORMATBAR, OnGetCharFormat)
	ON_NOTIFY(FN_SETFORMAT, ID_VIEW_FORMATBAR, OnSetCharFormat)
	ON_NOTIFY(NM_SETFOCUS, ID_VIEW_FORMATBAR, OnBarSetFocus)
	ON_NOTIFY(NM_KILLFOCUS, ID_VIEW_FORMATBAR, OnBarKillFocus)
	ON_NOTIFY(NM_RETURN, ID_VIEW_FORMATBAR, OnBarReturn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordPadView construction/destruction

CWordPadView::CWordPadView()
{
	m_bSyncCharFormat = m_bSyncParaFormat = TRUE;
	m_uTimerID = 0;
	m_bDelayUpdateItems = FALSE;
	m_bOnBar = FALSE;
	m_bInPrint = FALSE;
	m_nPasteType = 0;
	m_rectMargin = theApp.m_rectPageMargin;
}

BOOL CWordPadView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bRes = CRichEditView::PreCreateWindow(cs);
	cs.style |= ES_SELECTIONBAR;
	return bRes;
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadView attributes

BOOL CWordPadView::IsFormatText()
{
	// this function checks to see if any formatting is not default text
	BOOL bRes = FALSE;
	CHARRANGE cr;
	CCharFormat cf;
	CParaFormat pf;
	GetRichEditCtrl().GetSel(cr);
	GetRichEditCtrl().HideSelection(TRUE, FALSE);
	GetRichEditCtrl().SetSel(0,-1);

	if (!(GetRichEditCtrl().GetSelectionType() & (SEL_OBJECT|SEL_MULTIOBJECT)))
	{
		GetRichEditCtrl().GetSelectionCharFormat(cf);
		if (cf == m_defTextCharFormat)
		{
			GetRichEditCtrl().GetParaFormat(pf);
			if (pf == m_defParaFormat) //compared using CParaFormat::operator==
				bRes = TRUE;
		}
	}

	GetRichEditCtrl().SetSel(cr);
	GetRichEditCtrl().HideSelection(FALSE, FALSE);
	return bRes;
}

HMENU CWordPadView::GetContextMenu(WORD, LPOLEOBJECT, CHARRANGE* )
{
	CRichEditCntrItem* pItem = GetSelectedItem();
	if (pItem == NULL || !pItem->IsInPlaceActive())
	{
		CMenu menuText;
		menuText.LoadMenu(IDR_TEXT_POPUP);
		CMenu* pMenuPopup = menuText.GetSubMenu(0);
		menuText.RemoveMenu(0, MF_BYPOSITION);
		if (!GetSystemMetrics(SM_PENWINDOWS))
		{
			//delete pen specific stuff
			// remove Insert Keystrokes
			pMenuPopup->DeleteMenu(ID_PEN_LENS, MF_BYCOMMAND);
			int nIndex = pMenuPopup->GetMenuItemCount()-1; //index of last item
			// remove Edit Text...
			pMenuPopup->DeleteMenu(nIndex, MF_BYPOSITION);
			// remove separator
			pMenuPopup->DeleteMenu(nIndex-1, MF_BYPOSITION);
		}
		return pMenuPopup->Detach();
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadView operations

void CWordPadView::WrapChanged()
{
	CWaitCursor wait;
	CFrameWnd* pFrameWnd = GetParentFrame();
	ENSURE(pFrameWnd != NULL);
	pFrameWnd->SetMessageText(IDS_FORMATTING);
	CWnd* pBarWnd = pFrameWnd->GetMessageBar();
	if (pBarWnd != NULL)
		pBarWnd->UpdateWindow();

	CRichEditView::WrapChanged();

	pFrameWnd->SetMessageText(AFX_IDS_IDLEMESSAGE);
	if (pBarWnd != NULL)
		pBarWnd->UpdateWindow();
}

void CWordPadView::SetUpdateTimer()
{
	if (m_uTimerID != 0) // if outstanding timer kill it
		KillTimer(m_uTimerID);
	m_uTimerID = SetTimer(1, 1000, NULL); //set a timer for 1000 milliseconds
	if (m_uTimerID == 0) // no timer available so force update now
		GetDocument()->UpdateAllItems(NULL);
	else
		m_bDelayUpdateItems = TRUE;
}

void CWordPadView::DeleteContents()
{
	ASSERT_VALID(this);
	ASSERT(m_hWnd != NULL);
	CRichEditView::DeleteContents();
	SetDefaultFont(IsTextType(GetDocument()->m_nNewDocType));
}

void CWordPadView::SetDefaultFont(BOOL bText)
{
	ASSERT_VALID(this);
	ASSERT(m_hWnd != NULL);
	m_bSyncCharFormat = m_bSyncParaFormat = TRUE;
	CHARFORMAT* pCharFormat = bText ? &m_defTextCharFormat : &m_defCharFormat;
	// set the default character format -- the FALSE makes it the default
	GetRichEditCtrl().SetSel(0,-1);
	GetRichEditCtrl().SetDefaultCharFormat(*pCharFormat);
	GetRichEditCtrl().SetSelectionCharFormat(*pCharFormat);

	GetRichEditCtrl().SetParaFormat(m_defParaFormat);

	GetRichEditCtrl().SetSel(0,0);
	GetRichEditCtrl().EmptyUndoBuffer();
	GetRichEditCtrl().SetModify(FALSE);
	ASSERT_VALID(this);
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadView drawing

/////////////////////////////////////////////////////////////////////////////
// CWordPadView printing

void CWordPadView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CRichEditView::OnPrint(pDC, pInfo);
	if (pInfo != NULL && pInfo->m_bPreview)
		DrawMargins(pDC);
}

void CWordPadView::DrawMargins(CDC* pDC)
{
	if (pDC->m_hAttribDC != NULL)
	{
		CRect rect;
		rect.left = m_rectMargin.left;
		rect.right = m_sizePaper.cx - m_rectMargin.right;
		rect.top = m_rectMargin.top;
		rect.bottom = m_sizePaper.cy - m_rectMargin.bottom;
		//rect in twips
		int logx = ::GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);
		int logy = ::GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);
		rect.left = MulDiv(rect.left, logx, 1440);
		rect.right = MulDiv(rect.right, logx, 1440);
		rect.top = MulDiv(rect.top, logy, 1440);
		rect.bottom = MulDiv(rect.bottom, logy, 1440);
		CPen pen(PS_DOT, 0, pDC->GetTextColor());
		CPen* ppen = pDC->SelectObject(&pen);
		pDC->MoveTo(0, rect.top);
		pDC->LineTo(10000, rect.top);
		pDC->MoveTo(rect.left, 0);
		pDC->LineTo(rect.left, 10000);
		pDC->MoveTo(0, rect.bottom);
		pDC->LineTo(10000, rect.bottom);
		pDC->MoveTo(rect.right, 0);
		pDC->LineTo(rect.right, 10000);
		pDC->SelectObject(ppen);
	}
}

BOOL CWordPadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

inline int roundleast(int n)
{
	int mod = n%10;
	n -= mod;
	if (mod >= 5)
		n += 10;
	else if (mod <= -5)
		n -= 10;
	return n;
}

static void RoundRect(LPRECT r1)
{
	r1->left = roundleast(r1->left);
	r1->right = roundleast(r1->right);
	r1->top = roundleast(r1->top);
	r1->bottom = roundleast(r1->bottom);
}

static void MulDivRect(LPRECT r1, LPRECT r2, int num, int div)
{
	r1->left = MulDiv(r2->left, num, div);
	r1->top = MulDiv(r2->top, num, div);
	r1->right = MulDiv(r2->right, num, div);
	r1->bottom = MulDiv(r2->bottom, num, div);
}

void CWordPadView::OnPageSetup()
{
	CPageSetupDialog dlg;
	PAGESETUPDLG& psd = dlg.m_psd;
	BOOL bMetric = theApp.GetUnits() == 1; //centimeters
	psd.Flags |= PSD_MARGINS | (bMetric ? PSD_INHUNDREDTHSOFMILLIMETERS :
		PSD_INTHOUSANDTHSOFINCHES);
	int nUnitsPerInch = bMetric ? 2540 : 1000;
	MulDivRect(&psd.rtMargin, m_rectMargin, nUnitsPerInch, 1440);
	RoundRect(&psd.rtMargin);
	// get the current device from the app
	PRINTDLG pd;
	pd.hDevNames = NULL;
	pd.hDevMode = NULL;
	theApp.GetPrinterDeviceDefaults(&pd);
	psd.hDevNames = pd.hDevNames;
	psd.hDevMode = pd.hDevMode;
	if (dlg.DoModal() == IDOK)
	{
		RoundRect(&psd.rtMargin);
		MulDivRect(m_rectMargin, &psd.rtMargin, 1440, nUnitsPerInch);
		theApp.m_rectPageMargin = m_rectMargin;
		theApp.SelectPrinter(psd.hDevNames, psd.hDevMode);
		theApp.NotifyPrinterChanged();
	}
	// PageSetupDlg failed
	if (CommDlgExtendedError() != 0)
	{
		CPageSetupDlg pageDlg;
		pageDlg.m_nBottomMargin = m_rectMargin.bottom;
		pageDlg.m_nLeftMargin = m_rectMargin.left;
		pageDlg.m_nRightMargin = m_rectMargin.right;
		pageDlg.m_nTopMargin = m_rectMargin.top;
		if (pageDlg.DoModal() == IDOK)
		{
			m_rectMargin.SetRect(pageDlg.m_nLeftMargin, pageDlg.m_nTopMargin,
				pageDlg.m_nRightMargin, pageDlg.m_nBottomMargin);
			// m_page will be changed at this point
			theApp.m_rectPageMargin = m_rectMargin;
			theApp.NotifyPrinterChanged();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CWordPadView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadView diagnostics

#ifdef _DEBUG
void CWordPadView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CWordPadView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CWordPadDoc* CWordPadView::GetDocument() // non-debug version is inline
{
	return (CWordPadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWordPadView message helpers

/////////////////////////////////////////////////////////////////////////////
// CWordPadView message handlers

int CWordPadView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CRichEditView::OnCreate(lpCreateStruct) == -1)
		return -1;
	theApp.m_listPrinterNotify.AddTail(m_hWnd);

	if (theApp.m_bWordSel)
		GetRichEditCtrl().SetOptions(ECOOP_OR, ECO_AUTOWORDSELECTION);
	else
		GetRichEditCtrl().SetOptions(ECOOP_AND, ~(DWORD)ECO_AUTOWORDSELECTION);
//  GetRichEditCtrl().SetOptions(ECOOP_OR, ECO_SELECTIONBAR);

	GetDefaultFont(m_defTextCharFormat, IDS_DEFAULTTEXTFONT);
	GetDefaultFont(m_defCharFormat, IDS_DEFAULTFONT);

	GetRichEditCtrl().GetParaFormat(m_defParaFormat);
	m_defParaFormat.cTabCount = 0;

	return 0;
}

void CWordPadView::GetDefaultFont(CCharFormat& cf, UINT nFontNameID)
{
	USES_CONVERSION;
	CString strDefFont;
	VERIFY(strDefFont.LoadString(nFontNameID));
	ASSERT(cf.cbSize == sizeof(CHARFORMAT2));
	cf.dwMask = CFM_BOLD|CFM_ITALIC|CFM_UNDERLINE|CFM_STRIKEOUT|CFM_SIZE|
		CFM_COLOR|CFM_OFFSET|CFM_PROTECTED;
	cf.dwEffects = CFE_AUTOCOLOR;
	cf.yHeight = 200; //10pt
	cf.yOffset = 0;
	cf.crTextColor = RGB(0, 0, 0);
	cf.bCharSet = 0;
	cf.bPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	ASSERT(strDefFont.GetLength() < LF_FACESIZE);
	_tcsncpy_s(cf.szFaceName, LF_FACESIZE, strDefFont, _TRUNCATE);
	cf.dwMask |= CFM_FACE;
}

void CWordPadView::OnInsertDateTime()
{
	CDateDialog dlg;
	if (dlg.DoModal() == IDOK)
		GetRichEditCtrl().ReplaceSel(dlg.m_strSel);;
}

void CWordPadView::OnFormatParagraph()
{
	CFormatParaDlg dlg(GetParaFormatSelection());
	dlg.m_nWordWrap = m_nWordWrap;
	if (dlg.DoModal() == IDOK)
		SetParaFormat(dlg.m_pf);
}

void CWordPadView::OnFormatTabs()
{
	CFormatTabDlg dlg(GetParaFormatSelection());
	if (dlg.DoModal() == IDOK)
		SetParaFormat(dlg.m_pf);
}

void CWordPadView::OnTextNotFound(LPCTSTR lpStr)
{
	ASSERT_VALID(this);
	MessageBeep(0);
	AfxMessageBox(IDS_FINISHED_SEARCH,MB_OK|MB_ICONINFORMATION);
	CRichEditView::OnTextNotFound(lpStr);
}

void CWordPadView::OnColorPick(UINT nID)
{
	CRichEditView::OnColorPick(CColorMenu::GetColor(nID));
}

void CWordPadView::OnTimer(UINT_PTR nIDEvent)
{
	if (m_uTimerID != nIDEvent) // not our timer
		CRichEditView::OnTimer(nIDEvent);
	else
	{
		KillTimer(m_uTimerID); // kill one-shot timer
		m_uTimerID = 0;
		if (m_bDelayUpdateItems)
			GetDocument()->UpdateAllItems(NULL);
		m_bDelayUpdateItems = FALSE;
	}
}

void CWordPadView::OnEditChange()
{
	SetUpdateTimer();
}

void CWordPadView::OnDestroy()
{
	POSITION pos = theApp.m_listPrinterNotify.Find(m_hWnd);
	ASSERT(pos != NULL);
	theApp.m_listPrinterNotify.RemoveAt(pos);

	CRichEditView::OnDestroy();

	if (m_uTimerID != 0) // if outstanding timer kill it
		OnTimer((UINT)m_uTimerID);
	ASSERT(m_uTimerID == 0);
}

void CWordPadView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType)
{
	CRichEditView::CalcWindowRect(lpClientRect, nAdjustType);

	if (theApp.m_bWin4 && nAdjustType != 0 && (GetStyle() & WS_VSCROLL))
		lpClientRect->right--;

	// if the ruler is visible then slide the view up under the ruler to avoid
	// showing the top border of the view
	if (GetExStyle() & WS_EX_CLIENTEDGE)
	{
		CFrameWnd* pFrame = GetParentFrame();
		if (pFrame != NULL)
		{
			CRulerBar* pBar = (CRulerBar*)pFrame->GetControlBar(ID_VIEW_RULER);
			if (pBar != NULL)
			{
				BOOL bVis = pBar->IsVisible();
				if (pBar->m_bDeferInProgress)
					bVis = !bVis;
				if (bVis)
					lpClientRect->top -= 2;
			}
		}
	}
}

void CWordPadView::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMIS)
{
	lpMIS->itemID = (UINT)(WORD)lpMIS->itemID;
	CRichEditView::OnMeasureItem(nIDCtl, lpMIS);
}

void CWordPadView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_F10 && GetKeyState(VK_SHIFT) < 0)
	{
		long nStart, nEnd;
		GetRichEditCtrl().GetSel(nStart, nEnd);
		CPoint pt = GetRichEditCtrl().GetCharPos(nEnd);
		SendMessage(WM_CONTEXTMENU, (WPARAM)m_hWnd, MAKELPARAM(pt.x, pt.y));
	}

	CRichEditView::OnKeyDown(nChar, nRepCnt, nFlags);
}

HRESULT CWordPadView::GetClipboardData(CHARRANGE* lpchrg, DWORD /*reco*/,
	LPDATAOBJECT lpRichDataObj, LPDATAOBJECT* lplpdataobj)
{
	CHARRANGE& cr = *lpchrg;

	if ((cr.cpMax - cr.cpMin == 1) &&
		GetRichEditCtrl().GetSelectionType() == SEL_OBJECT)
	{
		return E_NOTIMPL;
	}

	BeginWaitCursor();
	//create the data source
	COleDataSource* pDataSource = new COleDataSource;

	// put the formats into the data source
	LPENUMFORMATETC lpEnumFormatEtc;
	lpRichDataObj->EnumFormatEtc(DATADIR_SET, &lpEnumFormatEtc);
	if (lpEnumFormatEtc != NULL)
	{
		FORMATETC etc;
		while (lpEnumFormatEtc->Next(1, &etc, NULL) == S_OK)
		{
			STGMEDIUM stgMedium;
			lpRichDataObj->GetData(&etc, &stgMedium);
			pDataSource->CacheData(etc.cfFormat, &stgMedium, &etc);
		}
		lpEnumFormatEtc->Release();
	}

	CEmbeddedItem item(GetDocument(), cr.cpMin, cr.cpMax);
	item.m_lpRichDataObj = lpRichDataObj;
	// get wordpad formats
	item.GetClipboardData(pDataSource);

	// get the IDataObject from the data source
	*lplpdataobj =  (LPDATAOBJECT)pDataSource->GetInterface(&IID_IDataObject);

	EndWaitCursor();
	return S_OK;
}

HRESULT CWordPadView::QueryAcceptData(LPDATAOBJECT lpdataobj,
	CLIPFORMAT* lpcfFormat, DWORD reco, BOOL bReally,
	HGLOBAL hMetaPict)
{
	if (bReally && *lpcfFormat == 0 && (m_nPasteType == 0))
	{
		COleDataObject dataobj;
		dataobj.Attach(lpdataobj, FALSE);
		if (!dataobj.IsDataAvailable(cfRTO)) // native avail, let richedit do as it wants
		{
			if (dataobj.IsDataAvailable(cfEmbeddedObject))
			{
				if (PasteNative(lpdataobj))
					return S_FALSE;
			}
		}
	}
	return CRichEditView::QueryAcceptData(lpdataobj, lpcfFormat, reco, bReally,
		hMetaPict);
}

BOOL CWordPadView::PasteNative(LPDATAOBJECT lpdataobj)
{
	// check data object for wordpad object
	// if true, suck out RTF directly
	FORMATETC etc = {NULL, NULL, DVASPECT_CONTENT, -1, TYMED_ISTORAGE};
	etc.cfFormat = (CLIPFORMAT)cfEmbeddedObject;
	STGMEDIUM stgMedium = {TYMED_ISTORAGE, 0, NULL};

	// create an IStorage to transfer the data in
	LPLOCKBYTES lpLockBytes;
	if (FAILED(::CreateILockBytesOnHGlobal(NULL, TRUE, &lpLockBytes)))
		return FALSE;
	ENSURE(lpLockBytes != NULL);

	HRESULT hr = ::StgCreateDocfileOnILockBytes(lpLockBytes,
		STGM_SHARE_EXCLUSIVE|STGM_CREATE|STGM_READWRITE, 0, &stgMedium.pstg);
	lpLockBytes->Release(); //storage addref'd
	if (FAILED(hr))
		return FALSE;

	ASSERT(stgMedium.pstg != NULL);
	CLSID clsid;
	BOOL bRes = FALSE; //let richedit do what it wants
	if (SUCCEEDED(lpdataobj->GetDataHere(&etc, &stgMedium)) &&
		SUCCEEDED(ReadClassStg(stgMedium.pstg, &clsid)) &&
		clsid == GetDocument()->GetClassID())
	{
		//suck out RTF now
		// open Contents stream
		COleStreamFile file;
		CFileException fe;
		if (file.OpenStream(stgMedium.pstg, szContents,
			CFile::modeReadWrite|CFile::shareExclusive, &fe))
		{

			// load it with CArchive (loads from Contents stream)
			CArchive loadArchive(&file, CArchive::load |
				CArchive::bNoFlushOnDelete);
			Stream(loadArchive, TRUE); //stream in selection
			bRes = TRUE; // don't let richedit do anything
		}
	}
	::ReleaseStgMedium(&stgMedium);
	return bRes;
}

// things to fix
// if format==0 we are doing a straight EM_PASTE
//  look for native formats
//      richedit specific -- allow richedit to handle (these will be first)
//      look for RTF, CF_TEXT.  If there paste special as these
//  Do standard OLE scenario

// if pasting a particular format (format != 0)
//  if richedit specific, allow through
//  if RTF, CF_TEXT. paste special
//  if OLE format, do standard OLE scenario


void CWordPadView::OnFilePrint()
{
	// don't allow winini changes to occur while printing
	m_bInPrint = TRUE;
	CRichEditView::OnFilePrint();
	// printer may have changed
	theApp.NotifyPrinterChanged(); // this will cause a GetDocument()->PrinterChanged();
	m_bInPrint = FALSE;
}

int CWordPadView::OnMouseActivate(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (m_bOnBar)
	{
		SetFocus();
		return MA_ACTIVATEANDEAT;
	}
	else
		return CRichEditView::OnMouseActivate(pWnd, nHitTest, message);
}

LONG_PTR CWordPadView::OnPrinterChangedMsg(UINT_PTR, LONG_PTR)
{
	CDC dc;
	AfxGetApp()->CreatePrinterDC(dc);
	OnPrinterChanged(dc);
	return 0;
}

static void ForwardPaletteChanged(HWND hWndParent, HWND hWndFocus)
{
	// Fix to send the WM_QUERYNEWPALETTE to a window that is interested
	HWND hWnd = NULL;
	for (hWnd = ::GetWindow(hWndParent, GW_CHILD); hWnd != NULL; hWnd = ::GetWindow(hWnd, GW_HWNDNEXT))
	{
		if (hWnd != hWndFocus)
		{
			::SendMessage(hWnd, WM_PALETTECHANGED, (WPARAM)hWndFocus, 0L);
			ForwardPaletteChanged(hWnd, hWndFocus);
		}
	}
}

void CWordPadView::OnPaletteChanged(CWnd* pFocusWnd)
{
	ForwardPaletteChanged(m_hWnd, pFocusWnd->GetSafeHwnd());
	// allow the richedit control to realize its palette
	// remove this if if richedit fixes their code so that
	// they don't realize their palette into foreground
	if (::GetWindow(m_hWnd, GW_CHILD) == NULL)
		CRichEditView::OnPaletteChanged(pFocusWnd);
}

static BOOL FindQueryPalette(HWND hWndParent)
{
	//Fix to send the WM_QUERYNEWPALETTE to a window that is interested
	HWND hWnd = NULL;
	for (hWnd = ::GetWindow(hWndParent, GW_CHILD); hWnd != NULL; hWnd = ::GetWindow(hWnd, GW_HWNDNEXT))
	{
		if (::SendMessage(hWnd, WM_QUERYNEWPALETTE, 0, 0L))
			return TRUE;
		else if (FindQueryPalette(hWnd))
			return TRUE;
	}
	return FALSE;
}

BOOL CWordPadView::OnQueryNewPalette()
{
	if(FindQueryPalette(m_hWnd))
		return TRUE;
	return CRichEditView::OnQueryNewPalette();
}

void CWordPadView::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CRichEditView::OnSettingChange(uFlags, lpszSection);
	//printer might have changed
	if (!m_bInPrint)
	{
#pragma warning(suppress:6400)
		if (lstrcmpi(lpszSection, _T("windows")) == 0)
			theApp.NotifyPrinterChanged(TRUE); // force update to defaults
	}
}

void CWordPadView::OnSize(UINT nType, int cx, int cy)
{
	CRichEditView::OnSize(nType, cx, cy);
	CRect rect(HORZ_TEXTOFFSET, VERT_TEXTOFFSET, cx, cy);
	GetRichEditCtrl().SetRect(rect);
}

void CWordPadView::OnGetCharFormat(NMHDR* pNMHDR, LRESULT* pRes)
{
	ENSURE(pNMHDR != NULL);
	ENSURE(pRes != NULL);
	((CHARHDR*)pNMHDR)->cf = GetCharFormatSelection();
	*pRes = 1;
}

void CWordPadView::OnSetCharFormat(NMHDR* pNMHDR, LRESULT* pRes)
{
	ENSURE(pNMHDR != NULL);
	ENSURE(pRes != NULL);
	SetCharFormat(((CHARHDR*)pNMHDR)->cf);
	*pRes = 1;
}

void CWordPadView::OnBarSetFocus(NMHDR*, LRESULT*)
{
	m_bOnBar = TRUE;
}

void CWordPadView::OnBarKillFocus(NMHDR*, LRESULT*)
{
	m_bOnBar = FALSE;
}

void CWordPadView::OnBarReturn(NMHDR*, LRESULT* )
{
	SetFocus();
}
