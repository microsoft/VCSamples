// svrdoc.cpp : implementation of the CServerDoc class
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
#include "hiersvr.h"

#include "svrdoc.h"
#include "svritem.h"
#include "svrview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

CLIPFORMAT NEAR CServerDoc::m_cfPrivate = NULL;

/////////////////////////////////////////////////////////////////////////////
// CServerDoc

IMPLEMENT_DYNCREATE(CServerDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CServerDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CServerDoc)
	ON_COMMAND(ID_OPTIONS_FONT, OnOptionsFont)
	ON_COMMAND(ID_CANCEL_INPLACE, OnCancelInplace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDoc construction/destruction

CServerDoc::CServerDoc()
{
	m_pRoot = CServerNode::CreateRootNode(this);

	// determine default font for document
	memset(&m_logfont, 0, sizeof m_logfont);
	m_logfont.lfHeight = -10;
	_tcscpy_s(m_logfont.lfFaceName, LF_FACESIZE, _T("Arial"));
	m_logfont.lfOutPrecision = OUT_TT_PRECIS;
	m_logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	m_logfont.lfQuality = PROOF_QUALITY;
	m_logfont.lfPitchAndFamily = FF_SWISS | VARIABLE_PITCH;

	// use default window text color
	m_crText = COLOR_WINDOWTEXT+1;

	if (m_cfPrivate == NULL)
	{
		m_cfPrivate = (CLIPFORMAT)
			::RegisterClipboardFormat(_T("MFC HierSvr Sample"));
	}
}

CServerDoc::~CServerDoc()
{
	delete m_pRoot;     // delete kills child nodes
}

void CServerDoc::DeleteContents()
{
	COleServerDoc::DeleteContents();

	if (m_pRoot != NULL)
		m_pRoot->InitRootNode();
}

BOOL CServerDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// Note: m_pRoot is created in the constructor
	return (m_pRoot != NULL);
}

COleServerItem* CServerDoc::OnGetEmbeddedItem()
{
	ASSERT_VALID(m_pRoot);

	// allocate embedded item first time requested
	if (m_pRoot->m_pServerItem == NULL)
		m_pRoot->m_pServerItem = new CServerItem(this, m_pRoot);

	// and return it
	ASSERT_VALID(m_pRoot->m_pServerItem);
	return m_pRoot->m_pServerItem;
}

COleServerItem* CServerDoc::OnGetLinkedItem(LPCTSTR lpszItemName)
{
	ASSERT_VALID(m_pRoot);

	// look in current list first
	COleServerItem* pItem = COleServerDoc::OnGetLinkedItem(lpszItemName);
	if (pItem != NULL)
		return pItem;

	// look in document itself for an item with that link name
	CString strItemName = lpszItemName;
	CServerNode* pNode = m_pRoot->FindNode(strItemName);
	if (pNode == NULL)
		return NULL;    // node does not exist

	ASSERT(pNode->m_pServerItem == NULL);   // should not be connected
	pItem = new CServerItem(this, pNode);
	ASSERT_VALID(pItem);

	// return new item that matches lpszItemName
	return pItem;
}

CFont* CServerDoc::SelectDocFont(CDC* pDC, CFont& font)
{
	// convert points in m_logfont.lfHeight to logical
	LOGFONT logfont = m_logfont;
	logfont.lfHeight = -::MulDiv(-logfont.lfHeight,
		pDC->GetDeviceCaps(LOGPIXELSY), 72);

	// set the text color as appropriate
	COLORREF cr = m_crText;
	if (cr == COLOR_WINDOW+1)
		cr = GetSysColor(COLOR_WINDOW);
	pDC->SetTextColor(m_crText);

	// create the font object
	if (!font.CreateFontIndirect(&logfont))
		return NULL;

	// select the font
	return pDC->SelectObject(&font);
}

int CServerDoc::DrawTree(CDC* pDC, CPoint ptStart, CServerNode* pNodeSel,
	CServerNode* pRoot)
{
	if (pRoot == NULL)
		pRoot = m_pRoot;
	// select correct font for the document
	CFont font;
	CFont* pOldFont = SelectDocFont(pDC, font);
	if (pOldFont == NULL)
		return -1;

	// draw the hierachy list
	int iResult = pRoot->DrawTree(pDC, ptStart, pNodeSel);

	// restore state of the dc
	pDC->SelectObject(pOldFont);
	return iResult;
}

void CServerDoc::CalcBounding(CDC* pDC, CServerNode* pNodeStart,
	CPoint ptStart, CSize& sizeMax)
{
	ASSERT_VALID(pNodeStart);

	// select correct font for the document
	CFont font;
	CFont* pOldFont = SelectDocFont(pDC, font);

	// calculate the bounding rect
	pNodeStart->CalcBounding(pDC, ptStart, sizeMax);

	// restore state of the dc
	if (pOldFont != NULL)
		pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CServerDoc serialization

// this serializes the OLE Server document as a stand-alone file
void CServerDoc::Serialize(CArchive& ar)
{
	ASSERT(m_pRoot != NULL);
	SerializeFontInfo(ar);
	m_pRoot->Serialize(ar);
}

void CServerDoc::SerializeFontInfo(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar.Write(&m_logfont, sizeof(m_logfont) - sizeof(m_logfont.lfFaceName));
		// lfFaceName is stored as CString so it is UNICODE/ANSI independent
		ar << CString(m_logfont.lfFaceName);
		ar << m_crText;
	}
	else
	{
		ar.Read(&m_logfont, sizeof(m_logfont) - sizeof(m_logfont.lfFaceName));
		// lfFaceName must be read as a CString
		CString strFaceName;
		ar >> strFaceName;
		_tcscpy_s(m_logfont.lfFaceName, LF_FACESIZE, strFaceName);
		ar >> m_crText;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CServerDoc in-place editing

void CServerDoc::OnSetItemRects(LPCRECT lpPosRect, LPCRECT lpClipRect)
{
	// get first view of document
	POSITION pos = GetFirstViewPosition();
	ASSERT(pos != NULL);
	CServerView* pView = (CServerView*)GetNextView(pos);
	ASSERT_KINDOF(CServerView, pView);
	ASSERT_VALID(pView);

	CSize sizeNum(lpPosRect->right - lpPosRect->left,
		lpPosRect->bottom - lpPosRect->top);
	// for denom -- get extent in device
	// create a view dc
	CServerDC dc(pView);
	// set zoom to 100%
	dc.SetViewportExt(CSize(1,1));
	dc.SetWindowExt(CSize(1,1));
	// get extents in device
	CSize sizeDenom = pView->CalcActualItemSize(m_pRoot, &dc);

	// notify first view of potential zoom factor change!
	pView->SetZoomFactor(sizeNum, sizeDenom);
	// resize the window
	COleServerDoc::OnSetItemRects(lpPosRect, lpClipRect);
	// set scrollbar state (if necessary)
	pView->SetScrollInfo();
}

void CServerDoc::OnOptionsFont()
{
	CClientDC dc(NULL);
	LOGFONT lf = m_logfont;
	lf.lfHeight = -::MulDiv(-lf.lfHeight, dc.GetDeviceCaps(LOGPIXELSY), 72);
	CFontDialog dlg(&lf);
	dlg.m_cf.rgbColors = m_crText;
	if (dlg.DoModal() == IDOK)
	{
		lf.lfHeight = -::MulDiv(-lf.lfHeight, 72, dc.GetDeviceCaps(LOGPIXELSY));
		m_crText = dlg.GetColor();
		m_logfont = lf;
		SetModifiedFlag();
		UpdateAllItems(NULL);
		UpdateAllViews(NULL);
	}
}

// Note: both the server and the container should have a keyboard method
//  of deactivating an active in-place item.

void CServerDoc::OnCancelInplace()
{
	if (IsInPlaceActive())
		OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CServerDoc diagnostics

#ifdef _DEBUG
void CServerDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CServerDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
