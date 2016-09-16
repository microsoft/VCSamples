// svrview.cpp : implementation of the CServerView class
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
#include "afxdlgs.h"        // for FileOpen
#include "hiersvr.h"

#include "svrdoc.h"
#include "svrview.h"
#include "svritem.h"
#include "zoomdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

CServerNode* NEAR CServerView::m_pDragNode = NULL;

static int ReadString(CArchive& ar, char* pString, int nMaxLen);
static BOOL FindItemRect(CDC* pDC, CServerNode* pItemFind, LPRECT lpRect,
	CPoint& ptStart, CServerNode* pRoot);
static CServerNode* HitDetect(CDC* pDC, CPoint point,
	CPoint& ptStart, CServerNode* pRoot);

/////////////////////////////////////////////////////////////////////////////
// support for zooming

static int NEAR rgiZoomFactor[] =
{
	25, 50, 75, 100, 125, 150, 175, 200, 250, 300
};

/////////////////////////////////////////////////////////////////////////////
// CServerView

IMPLEMENT_DYNCREATE(CServerView, CScrollView)

BEGIN_MESSAGE_MAP(CServerView, CScrollView)
	//{{AFX_MSG_MAP(CServerView)
	ON_COMMAND(ID_CHANGE_NAME, OnChangeName)
	ON_COMMAND(ID_ADD_NODE, OnAddNode)
	ON_UPDATE_COMMAND_UI(ID_CHANGE_NAME, OnUpdateHasSel)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_IMPORT_TEXT, OnImportText)
	ON_COMMAND(ID_VIEW_ZOOMCUSTOM, OnViewZoomCustom)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_TREE_COLLAPSEBRANCH, OnTreeCollapsebranch)
	ON_COMMAND(ID_TREE_EXPANDALL, OnTreeExpandall)
	ON_COMMAND(ID_TREE_EXPANDBRANCH, OnTreeExpandbranch)
	ON_COMMAND(ID_TREE_EXPANDONELEVEL, OnTreeExpandonelevel)
	ON_UPDATE_COMMAND_UI(ID_TREE_COLLAPSEBRANCH, OnUpdateTreeCollapsebranch)
	ON_UPDATE_COMMAND_UI(ID_TREE_EXPANDONELEVEL, OnUpdateTreeExpandonelevel)
	ON_UPDATE_COMMAND_UI(ID_TREE_EXPANDALL, OnUpdateTreeExpandall)
	ON_UPDATE_COMMAND_UI(ID_TREE_EXPANDBRANCH, OnUpdateTreeExpandbranch)
	ON_WM_KEYDOWN()
	ON_UPDATE_COMMAND_UI(ID_ADD_NODE, OnUpdateHasSel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateHasSel)
	ON_UPDATE_COMMAND_UI(ID_IMPORT_TEXT, OnUpdateHasSel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateHasSel)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateHasSel)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_VIEW_ZOOM25, ID_VIEW_ZOOM300, OnZoom)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_ZOOM25, ID_VIEW_ZOOM300, OnUpdateZoom)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerView construction/destruction

CServerView::CServerView()
{
	m_pSelectedNode = NULL;
	m_ptStart = CPoint(CX_MARGIN, CY_MARGIN);   // upper left position

	// initialize zoom state (100% from size cache)
	m_zoomNum = CSize(100, 100);
	m_zoomDenom = CSize(100, 100);
	m_prevDropEffect = DROPEFFECT_NONE;
}

CServerView::~CServerView()
{
}

/////////////////////////////////////////////////////////////////////////////
// Attributes -- public

void CServerView::SetSelection(CServerNode* pNewSel, CDC* pDC)
{
	if (pNewSel == m_pSelectedNode)
		return;     // already set
	InvalidateItem(m_pSelectedNode, pDC);
	m_pSelectedNode = pNewSel;
	InvalidateItem(m_pSelectedNode, pDC);
}

void CServerView::SetSelection(CServerNode* pNewSel)
{
	CServerDC dc(this);
	SetSelection(pNewSel, &dc);
}

/////////////////////////////////////////////////////////////////////////////
// Operations -- public

void CServerView::SetScrollInfo()
{
	CServerNode* pRoot = GetDocument()->m_pRoot;
	ENSURE(pRoot != NULL);

	//BLOCK: determine new scrolling sizes
	CSize sizeLine;
	CSize sizePage;
	CSize sizeTotal;
	{
		CServerDC dc(this);

		pRoot->CalcNodeSize(&dc, sizeLine);
		sizeLine.cx = sizeDefault.cx;
		sizeLine.cy += CY_SEPARATOR;
		sizePage.cx = sizeDefault.cx;
		sizePage.cy = sizeLine.cy * 10;

		// set the scroll sizes dependent on the zoom factor
		dc.LPtoDP(&sizePage);
		dc.LPtoDP(&sizeLine);
		sizeTotal = CalcActualViewSize(&dc);
		// subtract out the right and bottom margins
		// these are not interesting and this way we avoid
		// some problems with nonlinear scaling of fonts
		CSize sizeMargin(CX_MARGIN, CY_MARGIN);
		CRect rect(CPoint(0, 0), sizeMargin);
		dc.LPtoDP(rect);
		sizeTotal -= rect.Size();
	}

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}

BOOL CServerView::SetZoomFactor(CSize zoomNum, CSize zoomDenom)
{
	if (zoomDenom != m_zoomDenom || zoomNum != m_zoomNum)
	{
		// sync to new zoom factor
		m_zoomNum = zoomNum;
		m_zoomDenom = zoomDenom;

		// resync to new sizes
		Invalidate();
		return TRUE;
	}
	return FALSE;
}

void CServerView::UpdateServerView()
{
	CServerDoc* pDoc = GetDocument();
	pDoc->SetModifiedFlag();
	pDoc->UpdateAllItems(NULL);
	pDoc->UpdateAllViews(NULL);
}

CSize CServerView::CalcActualViewSize(CDC *pDC)
{
	return CalcActualItemSize(GetDocument()->m_pRoot, pDC);
}

CSize CServerView::CalcActualItemSize(CServerNode* pItem, CDC *pDC)
{
	CSize sizeTotal(0, 0);
	CPoint ptStart = m_ptStart;
	pItem->CalcBounding(pDC, ptStart, sizeTotal);
	sizeTotal.cx += CX_MARGIN;
	// sizeTotal is the extent in logical coords
	// convert from logical to device
	CRect rc(CPoint(0,0),sizeTotal);
	pDC->LPtoDP(rc);
	return rc.Size();
}

CSize CServerView::CalcScaledViewSize()
{
	return CalcScaledItemSize(GetDocument()->m_pRoot);
}

CSize CServerView::CalcScaledItemSize(CServerNode* pItem)
{
	CServerDC dc(this);
	// set extent to 100%
	dc.SetViewportExt(CSize(1,1));
	dc.SetWindowExt(CSize(1,1));

	CSize sizeTotal(0, 0);
	CPoint ptStart = m_ptStart;
	pItem->CalcBounding(&dc, ptStart, sizeTotal);
	sizeTotal.cx += CX_MARGIN;
	// sizeTotal is the native extent in device coords
	sizeTotal.cx = MulDiv(sizeTotal.cx,m_zoomNum.cx,m_zoomDenom.cx);
	sizeTotal.cy = MulDiv(sizeTotal.cy,m_zoomNum.cy,m_zoomDenom.cy);
	return sizeTotal;
}

BOOL CServerView::DoPasteItem(COleDataObject* pDataObject)
{
	ENSURE(pDataObject != NULL);
	ASSERT_VALID(this);
	ENSURE(m_pSelectedNode != NULL);

	BeginWaitCursor();

	TRY
	{
		if (pDataObject->IsDataAvailable(CServerDoc::m_cfPrivate))
			DoPasteNative(pDataObject);
		else if (pDataObject->IsDataAvailable(CF_TEXT))
			DoPasteText(pDataObject);
		else
			AfxThrowNotSupportedException();
	}
	CATCH_ALL(e)
	{
		// general cleanup
		TRACE0("failed to embed/link an OLE object\n");
		EndWaitCursor();
		return FALSE;
	}
	END_CATCH_ALL

	EndWaitCursor();
	return TRUE;
}

void CServerView::DoPasteNative(COleDataObject *pDataObject)
{
	ASSERT(m_pSelectedNode != NULL);
	CServerNode* pItem = new CServerNode(GetDocument());
	ASSERT_VALID(pItem);

	// get file refering to clipboard data
	CFile *pFile = pDataObject->GetFileData(CServerDoc::m_cfPrivate);
	if (pFile == NULL)
	{
		delete pItem;
		return;
	}

	// connect the file to the archive and read the contents
	CArchive ar(pFile, CArchive::load);
	ar.m_pDocument = GetDocument(); // for COleClientItem serialize
	pItem->Serialize(ar);
	ar.Close();
	delete pFile;

	// add the item to selected node
	m_pSelectedNode->m_listChild.AddHead(pItem);
	SetSelection(pItem);
}

void CServerView::DoPasteText(COleDataObject *pDataObject)
{
	ASSERT(m_pSelectedNode != NULL);

	// get file refering to clipboard data
	CFile *pFile = pDataObject->GetFileData(CF_TEXT);
	if (pFile == NULL)
		return;

	// connect the file to the archive and read the contents
	CArchive ar(pFile, CArchive::load);
	DoImportText(ar);
	ar.Close();
	delete pFile;
}

void CServerView::DoImportText(CArchive &ar)
{
	// read in lines appending items from this node
	char szNode[256];
#ifdef _UNICODE
	TCHAR szT[256];
#endif
	int nCurLevel = 0;
	CServerNode* parents[MAX_LEVEL];
	parents[0] = m_pSelectedNode;   // must have a parent at the current level
	CServerNode* pNewSel = NULL;

	while (ReadString(ar, szNode, sizeof(szNode)) != NULL)
	{
		int cch = (int)strlen(szNode);
		if (cch == 0)
			continue;
		if (szNode[cch-1] != '\n')
		{
			AfxMessageBox(
				_T("Text file contains too long a line - aborting read\n"));
			break;      // leaves items loaded so far
		}
		szNode[cch-1] = '\0';
		// check the indentation level
		char* pch = szNode;
		while (*pch == '\t')
			pch++;
		int nLevel = (int)((pch - szNode)+1);
		ENSURE(nLevel >= 1);        // levels are 1 based, 0 is the root

		if (*pch == '\0')
			continue;       // skip blank lines
		if (nLevel > nCurLevel + 1 || nLevel >= MAX_LEVEL)
		{
			AfxMessageBox(
				_T("Text file contains too many tabs = aborting read\n"));
			break;      // leaves items loaded so far
		}

#ifdef _UNICODE
		int n = MultiByteToWideChar(CP_ACP, 0, pch, -1, 
			szT, sizeof(szT)/sizeof(szT[0]));
		if (n > 0)
			szT[n-1] = 0;
		parents[nLevel] = parents[nLevel-1]->CreateChildNode(szT);
#else
		parents[nLevel] = parents[nLevel-1]->CreateChildNode(pch);
#endif
		nCurLevel = nLevel;
		if (pNewSel == NULL)
			pNewSel = parents[nLevel];
	}
	if (nCurLevel == 0)
		return;     // nothing added

	SetSelection(pNewSel);
	UpdateServerView();
}

void CServerView::ScrollToItem(CServerNode *pItem, BOOL bScrollUp)
{
	CServerDC dc(this);

	CRect rect;
	CPoint ptStart = m_ptStart;
	if (FindItemRect(&dc, pItem, &rect, ptStart, GetDocument()->m_pRoot))
	{
		CRect rc;
		dc.LPtoDP(rect);
		if (GetDocument()->IsInPlaceActive())
		{
			CRect rcPos,rcClip;
			GetDocument()->GetItemPosition(&rcPos);
			GetDocument()->GetItemClipRect(&rcClip);
			rc.IntersectRect(&rcPos,&rcClip);
			rc.OffsetRect(-rcPos.left,-rcPos.top);
			if (!rc.PtInRect(rect.TopLeft()) || !rc.PtInRect(rect.BottomRight()))
			{
				CSize size(0, 0);
				// scroll inplace site
				if (bScrollUp)
					size.cy = rect.top - rc.top;
				else
					size.cy = rect.bottom + rcPos.top - rcClip.bottom;
				GetDocument()->ScrollContainerBy(size);
			}
		}
		else
		{
			GetClientRect(rc);
			if (!rc.PtInRect(rect.TopLeft()) || !rc.PtInRect(rect.BottomRight()))
			{
				CPoint ptDevScroll = GetDeviceScrollPosition();
				if (bScrollUp)
					ScrollToPosition(CPoint(0,rect.top + ptDevScroll.y));
				else
					ScrollToPosition(
						CPoint(0,ptDevScroll.y + rect.bottom - rc.Height()));
			}
		}
	}
}

void CServerView::Locate(int nCount, BOOL bScrollUp)
{
	CServerNode* pRoot = GetDocument()->m_pRoot;
	CServerNode* pItem = pRoot;

	if (m_pSelectedNode == NULL)
		SetSelection(pRoot);

	if (nCount == 0) // goto top or bottom depending on direction
	{
		if (bScrollUp)
			pItem = pRoot;
		else
		{
			while (pItem->HasChildren())
				pItem = (CServerNode *)(pItem->m_listChild.GetTail());
		}
	}
	else if (bScrollUp)
	{
		pItem = m_pSelectedNode;
		while (nCount--)
			pItem = pRoot->GetPrev(pItem);
	}
	else // going down
	{
		pItem = m_pSelectedNode;
		while (nCount--)
			pItem = pRoot->GetNext(pItem);
	}
	ScrollToItem(pItem, bScrollUp);
	SetSelection(pItem);
	UpdateWindow();
}

void CServerView::InvalidateItem(CServerNode *pItem, CDC* pDC)
{
	if (pItem != NULL)
	{
		CRect rect;
		CPoint ptStart = m_ptStart;
		if (FindItemRect(pDC, pItem, &rect, ptStart, GetDocument()->m_pRoot))
		{
			pDC->LPtoDP(rect);
			InvalidateRect(rect, FALSE);
		}
	}
}

void CServerView::InvalidateItem(CServerNode* pItem)
{
	CServerDC dc(this);
	InvalidateItem(pItem, &dc);
}

void CServerView::ToggleSelectedItem()
{
	if (m_pSelectedNode != NULL && m_pSelectedNode->HasChildren())
	{
		if (m_pSelectedNode->m_bHideChildren)
			OnTreeExpandonelevel();
		else
			OnTreeCollapsebranch();
	}
}

/////////////////////////////////////////////////////////////////////////////
// Implementation

void CServerView::OnDraw(CDC* pDC)
{
	if (GetDocument()->DrawTree(pDC, m_ptStart, m_pSelectedNode) == -1)
		TRACE0("Error: CServerDoc::DrawTree failed!!\n");
}

void CServerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CScrollView::OnUpdate(pSender, lHint, pHint);
	CServerDoc* pDoc = GetDocument();
	CServerNode* pRoot = pDoc->m_pRoot;
	ASSERT(pRoot != NULL);

	if (m_pSelectedNode == NULL)
		m_pSelectedNode = pRoot;

	if (pDoc->IsInPlaceActive())
	{
		ASSERT_VALID(pDoc->m_pRoot);
		CRect rect;
		pDoc->GetItemPosition(rect);

		// adjust rect for new size of view
		rect.BottomRight() = rect.TopLeft() + CalcScaledViewSize();
		pDoc->RequestPositionChange(rect);
			// may resize the window before returning
	}
	SetScrollInfo();
}

void CServerView::OnInitialUpdate()
{
	// initialize zoom state (100% from size cache)
	m_zoomNum = CSize(100, 100);
	m_zoomDenom = CSize(100, 100);

	// call base class last (will call OnUpdate)
	CScrollView::OnInitialUpdate();
}

void CServerView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CScrollView::OnPrepareDC(pDC, pInfo);

	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportExt(m_zoomNum);
	pDC->SetWindowExt(m_zoomDenom);
}

void CServerView::SelectAtPoint(CPoint point, CPoint& pointHit)
{
	CServerDC dc(this);

	// change the selection as appropriate
	pointHit = m_ptStart;
	CServerNode* pSelection = HitDetect(&dc, point, pointHit,
		GetDocument()->m_pRoot);

	// now set the selection to new hit-tested node
	SetSelection(pSelection, &dc);
}

void CServerView::DoBranch(CServerNode *pItem, BOOL bHide)
{
	if (pItem->HasChildren())
	{
		pItem->m_bHideChildren = bHide;
		POSITION pos = pItem->m_listChild.GetHeadPosition();
		while (pos != NULL)
			DoBranch((CServerNode *)pItem->m_listChild.GetNext(pos),bHide);
	}
}

BOOL CServerView::OnDrop(COleDataObject* pDataObject, DROPEFFECT, CPoint)
{
	ASSERT_VALID(this);
	OnDragLeave();
	if (DoPasteItem(pDataObject))
	{
		UpdateServerView();
		return TRUE;
	}
	else
		return FALSE;
}

DROPEFFECT CServerView::OnDragEnter(COleDataObject* pDataObject,
	DWORD grfKeyState, CPoint point)
{
	ASSERT(m_prevDropEffect == DROPEFFECT_NONE);
	return OnDragOver(pDataObject, grfKeyState, point);
}

DROPEFFECT CServerView::OnDragOver(COleDataObject* pDataObject,
	DWORD grfKeyState, CPoint point)
{
	DROPEFFECT dropEffect = DROPEFFECT_NONE;
	if (pDataObject->IsDataAvailable(CServerDoc::m_cfPrivate) ||
		pDataObject->IsDataAvailable(CF_TEXT))
	{
		CPoint pointHit;
		SelectAtPoint(point, pointHit);
		UpdateWindow();
		if (m_pSelectedNode != NULL)
		{
			// don't allow a node to drop on itself
			if (m_pDragNode == m_pSelectedNode)
				dropEffect = DROPEFFECT_NONE;
			// if drop target is a child of drag source
			// then don't drop
			else if (m_pDragNode != NULL && m_pDragNode->IsChild(m_pSelectedNode))
				dropEffect = DROPEFFECT_NONE;
			// check for force link
			else if ((grfKeyState & (MK_CONTROL|MK_SHIFT)) == (MK_CONTROL|MK_SHIFT))
				dropEffect = DROPEFFECT_COPY;
			// check for force copy
			else if ((grfKeyState & MK_CONTROL) == MK_CONTROL)
				dropEffect = DROPEFFECT_COPY;
			// check for force move
			else if ((grfKeyState & MK_ALT) == MK_ALT)
				dropEffect = DROPEFFECT_MOVE;
			// if m_pDragNode == NULL then not dropping on self
			// so make default effect be copy
			// if dropping on self make default be move
			else
				dropEffect = (m_pDragNode == NULL) ? DROPEFFECT_COPY :
					DROPEFFECT_MOVE;
		}
	}
	m_prevDropEffect = dropEffect;
	return dropEffect;
}

void CServerView::OnDragLeave()
{
	m_prevDropEffect = DROPEFFECT_NONE;
}

/////////////////////////////////////////////////////////////////////////////
// CServerView commands

void CServerView::OnUpdateHasSel(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelectedNode != NULL);
}

void CServerView::OnChangeName()
{
	if (m_pSelectedNode != NULL && m_pSelectedNode->PromptChangeNode())
	{
		GetDocument()->SetModifiedFlag();
		GetDocument()->UpdateAllItems(NULL);
		GetDocument()->UpdateAllViews(NULL);
	}
}

void CServerView::OnAddNode()
{
	if (m_pSelectedNode == NULL)
		AfxThrowNotSupportedException();
	CServerNode* pNew;
	if ((pNew = m_pSelectedNode->PromptNewChildNode()) == NULL)
		return;

	SetSelection(pNew);
	UpdateServerView();
}

void CServerView::OnEditCopy()
{
	ASSERT_VALID(this);
	if (m_pSelectedNode == NULL)
		return;

	// get a server item suitable to generate the clipboard data
       CServerItem* pItem = m_pSelectedNode->m_pServerItem;
       if (pItem == NULL)
					#pragma warning (suppress: 6014)
               pItem = new CServerItem(GetDocument(), m_pSelectedNode);
       ASSERT_VALID(pItem);
       pItem->CopyToClipboard(TRUE);
}

void CServerView::OnLButtonDown(UINT, CPoint point)
{
	// m_pDragNode != NULL only when drag in progress
	ASSERT(m_pDragNode == NULL);
	CPoint pointHit;
	SelectAtPoint(point, pointHit);
	UpdateWindow();

	// maybe start drag drop operation on selection
	if (m_pSelectedNode != NULL)
	{
		// record current selection because a drop back in same view
		// will change the current selection
		m_pDragNode = m_pSelectedNode;

		// determine rectangle of object we'll be dragging
		CServerDC dc(this);
		CSize size = CalcActualItemSize(m_pSelectedNode, &dc);
		CRect rect(pointHit, size);

		// get a server item suitable to generate the clipboard data
      CServerItem* pItem = m_pSelectedNode->m_pServerItem;
      if (pItem == NULL)
               pItem = new CServerItem(GetDocument(), m_pSelectedNode);

      ASSERT_VALID(pItem);

		// rect must be in screen co-ordinates
		dc.LPtoDP(&rect);
		CPoint ptOffset = point - rect.TopLeft();
		ClientToScreen(&rect);

		// drag the object
		if (pItem->DoDragDrop(rect, ptOffset, TRUE,
			DROPEFFECT_COPY | DROPEFFECT_MOVE) == DROPEFFECT_MOVE)
		{
			// the object was moved, need to delete/move depending on dest
			CServerDoc* pDoc = GetDocument();
			if (m_pSelectedNode == m_pDragNode)
				SetSelection(pDoc->m_pRoot->GetPrev(m_pSelectedNode));
			if (m_pDragNode == pDoc->m_pRoot)
				pDoc->m_pRoot->InitRootNode();
			else
				pDoc->m_pRoot->FindAndDelete(m_pDragNode);

			// if drop was not back in same view clear selected node
			UpdateServerView();
		}
		m_pDragNode = NULL;
	}
}

void CServerView::OnRButtonDown(UINT /*nFlags*/, CPoint point)
{
	// make sure window is active
	GetParentFrame()->ActivateFrame();

	CPoint pointHit;
	SelectAtPoint(point, pointHit); // select node first
	UpdateWindow();

	int iSub;
	if (m_pSelectedNode == NULL ||
	  (iSub = m_pSelectedNode->GetPopupMenuIndex()) == -1)
	   return;  // nothing if no selection or no popup

	CMenu popups;
	if (!popups.LoadMenu(IDR_POPUPS))
		AfxThrowResourceException();
	CMenu* pMenu = popups.GetSubMenu(iSub);
	ENSURE(pMenu != NULL);

	ClientToScreen(&point);
	pMenu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON,
		point.x, point.y, AfxGetMainWnd());
}

void CServerView::OnImportText()
{
	if (m_pSelectedNode == NULL)
		AfxThrowNotSupportedException();

	CFileDialog dlg(TRUE, _T("txt"), NULL,
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
		_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"));
	if (dlg.DoModal() != IDOK)
		return;                 // stay with old data file

	CFile file;
	if (!file.Open(dlg.GetPathName(), CFile::modeRead))
	{
		AfxMessageBox(_T("Failed to open text file"));
		return;
	}

	CArchive ar(&file,CArchive::load);
	DoImportText(ar);
	ar.Close();
	file.Close();
}

static int ReadString(CArchive& ar, char* pString, int nMaxLen)
{
	unsigned int nCount = 0;
	BYTE ch;
	pString[nCount] = (char)0;
	TRY
	{
		do
		{
			ar >> ch;

			// watch out for ^Z (EOF under DOS)
			if ((char)ch == 0x1A)
				break;

			// combine "\r\n" pair into single "\n"
			if (ch == '\n' && nCount != 0 && pString[nCount-1] == '\r')
				nCount--;

			pString[nCount++] = ch;

		} while (nCount < (unsigned int)nMaxLen-1 && ch != '\n');
	}
	END_TRY

#ifdef _OLD
	// insert newline if missing
	if (nCount != 0 && pString[nCount-1] != '\n' && nCount < (unsigned int)nMaxLen-1)
		pString[nCount++] = '\n';
	pString[nCount] = (char)0;
#else
	// insert newline if missing
	if (nCount != 0 && pString[nCount-1] != '\n' && nCount < (unsigned int)nMaxLen-1)
	{
		if (pString[nCount-1] == '\0')
			pString[nCount-1] = '\n';
		else
			pString[nCount++] = '\n';
	}
	pString[nCount] = (char)0;
#endif
	return nCount;
}

/////////////////////////////////////////////////////////////////////////////
// Zooming user interface

void CServerView::OnZoom(UINT nID)
{
	ENSURE(nID >= ID_VIEW_ZOOM25 && nID <= ID_VIEW_ZOOM300);

	CSize zoomDenom;
	CSize zoomNum;

	// all of our zoom factors use denominator of 100
	zoomDenom.cx = 100;
	zoomDenom.cy = 100;

	// get zoom factor numerator and set it
	ASSERT(nID-ID_VIEW_ZOOM25 < sizeof(rgiZoomFactor)/sizeof(rgiZoomFactor[0]));
	int iZoomFactor = rgiZoomFactor[nID-ID_VIEW_ZOOM25];
	zoomNum.cx = iZoomFactor;
	zoomNum.cy = iZoomFactor;

	// change the zoom factor to new zoom factor
	SetZoomFactor(zoomNum, zoomDenom);
	SetScrollInfo();
}

void CServerView::OnUpdateZoom(CCmdUI* pCmdUI)
{
	UINT nID = pCmdUI->m_nID;

	if (m_zoomDenom.cx == 100 && m_zoomDenom.cy == 100 &&
		nID != ID_VIEW_ZOOMCUSTOM)
	{
		ASSERT(nID-ID_VIEW_ZOOM25 <
			sizeof(rgiZoomFactor)/sizeof(rgiZoomFactor[0]));
		int iZoomFactor = rgiZoomFactor[nID-ID_VIEW_ZOOM25];

		if (iZoomFactor == m_zoomNum.cx && iZoomFactor == m_zoomNum.cy)
		{
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}

	// default to not checked
	pCmdUI->SetCheck(FALSE);
}

void CServerView::OnViewZoomCustom()
{
	// prepare dialog data
	CZoomDlg dlg;
	dlg.m_zoomX = m_zoomNum.cx;
	dlg.m_zoomY = m_zoomNum.cy;

	// launch dialog
	if (dlg.DoModal() == IDOK)
	{
		// set new zoom factors
		CSize zoomNum(dlg.m_zoomX, dlg.m_zoomY);
		SetZoomFactor(zoomNum, m_zoomDenom);
		SetScrollInfo();
	}
}

/////////////////////////////////////////////////////////////////////////////

void CServerView::OnEditCut()
{
	ASSERT(m_pSelectedNode != NULL);
	CServerDoc* pDoc = GetDocument();
	OnEditCopy();
	if (m_pSelectedNode == pDoc->m_pRoot)
		pDoc->m_pRoot->InitRootNode();
	else if (pDoc->m_pRoot->FindAndDelete(m_pSelectedNode))
		m_pSelectedNode = NULL;
	UpdateServerView();
}

void CServerView::OnLButtonDblClk(UINT /*nFlags*/, CPoint point)
{
	CPoint pointHit;
	SelectAtPoint(point, pointHit);
	ToggleSelectedItem();
}

void CServerView::OnEditPaste()
{
	COleDataObject clipboardData;
	clipboardData.AttachClipboard();
	DoPasteItem(&clipboardData);
	UpdateServerView();
}

void CServerView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
	// determine if private or standard OLE formats are on the clipboard
	COleDataObject dataObj;
	BOOL bEnable = m_pSelectedNode != NULL &&
		dataObj.AttachClipboard() &&
		(dataObj.IsDataAvailable(CServerDoc::m_cfPrivate) ||
		 dataObj.IsDataAvailable(CF_TEXT));
	// enable command based on availability
	pCmdUI->Enable(bEnable);
}

int CServerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// register drop target
	m_dropTarget.Register(this);

	// setup scroll state so it is possible to calculate the extent
	SetScrollSizes(MM_TEXT, CSize(0, 0));

	return 0;
}

void CServerView::OnEditClear()
{
	CServerNode* pRoot = GetDocument()->m_pRoot;
	if (m_pSelectedNode == NULL)
		return;
	if (m_pSelectedNode == pRoot)
		pRoot->InitRootNode();
	else
	{
		CServerNode *pItem = pRoot->GetPrev(m_pSelectedNode);
		if (pRoot->FindAndDelete(m_pSelectedNode))
			m_pSelectedNode = pRoot->GetNext(pItem);
	}
	UpdateServerView();
}

void CServerView::OnTreeCollapsebranch()
{
	DoBranch(m_pSelectedNode,TRUE);
	UpdateServerView();
}

void CServerView::OnTreeExpandall()
{
	DoBranch(GetDocument()->m_pRoot,FALSE);
	UpdateServerView();
}

void CServerView::OnTreeExpandbranch()
{
	DoBranch(m_pSelectedNode,FALSE);
	UpdateServerView();
}

void CServerView::OnTreeExpandonelevel()
{
	if (m_pSelectedNode->HasChildren())
	{
		m_pSelectedNode->m_bHideChildren = FALSE;
		UpdateServerView();
	}
}

void CServerView::OnUpdateTreeCollapsebranch(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelectedNode != NULL && m_pSelectedNode->HasChildren() &&
		!m_pSelectedNode->m_bHideChildren);
}

void CServerView::OnUpdateTreeExpandonelevel(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelectedNode != NULL && m_pSelectedNode->HasChildren() &&
		m_pSelectedNode->m_bHideChildren);
}

void CServerView::OnUpdateTreeExpandall(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(GetDocument()->m_pRoot != NULL &&
		GetDocument()->m_pRoot->HasChildren());
}

void CServerView::OnUpdateTreeExpandbranch(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelectedNode != NULL && m_pSelectedNode->HasChildren());
}

void CServerView::OnKeyDown(UINT nChar, UINT /*nRepCnt*/, UINT /*nFlags*/)
{
	switch (nChar)
	{
		case VK_RETURN:
			ToggleSelectedItem();
			break;
		case VK_UP:
			Locate(1, TRUE);
			break;
		case VK_DOWN:
			Locate(1, FALSE);
			break;
		case VK_HOME:
			Locate(0, TRUE);
			break;
		case VK_END:
			Locate(0, FALSE);
			break;
		case VK_PRIOR:
			Locate(10, TRUE);
			break;
		case VK_NEXT:
			Locate(10, FALSE);
			break;
	}
}

void CServerView::OnSize(UINT nType, int cx, int cy)
{
	// update scroll bar size before handling the size message
	//  (this avoids multiple updates during in-place activation)
	SetScrollInfo();

	CScrollView::OnSize(nType, cx, cy);
}

/////////////////////////////////////////////////////////////////////////////
// CServerDC class -- helper for setting up and cleaning up DC

CServerDC::CServerDC(CServerView *pView) : CClientDC(pView)
{
	pView->OnPrepareDC(this);
	pOldFont = pView->GetDocument()->SelectDocFont(this, font);
}

CServerDC::~CServerDC()
{
	if (pOldFont != NULL)
		SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// non-member static functions

// calculate the bounding rect for a given item in the context of this view
static BOOL FindItemRect(CDC* pDC, CServerNode* pItemFind, LPRECT lpRect,
	CPoint& ptStart, CServerNode* pRoot)
{
	ENSURE(pItemFind != NULL);
	ENSURE(lpRect != NULL);
	ENSURE(pRoot != NULL);

	CSize sizeNode;
	pRoot->CalcNodeSize(pDC, sizeNode);
	if (pItemFind == pRoot)
	{
		// item rect does not include separator
		lpRect->right = (lpRect->left = ptStart.x) + sizeNode.cx;
		lpRect->bottom = (lpRect->top = ptStart.y) + sizeNode.cy;
		return TRUE;
	}

	CPoint pt(CX_INDENT, CY_SEPARATOR);
	ptStart.x += CX_INDENT; // not essential for calculation
	ptStart.y += sizeNode.cy + CY_SEPARATOR;

	// check the kids
	if (!pRoot->m_bHideChildren)
	{
		POSITION pos = pRoot->m_listChild.GetHeadPosition();
		while (pos != NULL)
		{
			CServerNode* pChild = (CServerNode*) (pRoot->m_listChild.GetNext(pos));
			if (FindItemRect(pDC, pItemFind, lpRect, ptStart, pChild))
				return TRUE;    // found
		}
	}
	ptStart.x -= CX_INDENT;
	return FALSE;
}

// calculate the bounding rect for a given item in the context of this view
static CServerNode* HitDetect(CDC* pDC, CPoint point,
	CPoint& ptStart, CServerNode* pRoot)
{
	ENSURE(pRoot != NULL);

	CSize sizeNode;
	pRoot->CalcNodeSize(pDC, sizeNode);
	CRect rect(ptStart, sizeNode);
	pDC->LPtoDP(rect);
	if (rect.PtInRect(point))
		return pRoot;

	ptStart.x += CX_INDENT;
	ptStart.y += sizeNode.cy + CY_SEPARATOR;
	CPoint pt = ptStart;
	pDC->LPtoDP(&pt);
	if (pt.y >= point.y)
		return FALSE;       // no point in looking any lower

	// check the kids
	if (!pRoot->m_bHideChildren)
	{
		POSITION pos = pRoot->m_listChild.GetHeadPosition();
		while (pos != NULL)
		{
			CServerNode* pChild = (CServerNode*) (pRoot->m_listChild.GetNext(pos));
			CServerNode* pItem = HitDetect(pDC, point, ptStart, pChild);
			if (pItem != NULL)
				return pItem;   // found
		}
	}
	ptStart.x -= CX_INDENT;
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// CServerView diagnostics

#ifdef _DEBUG
void CServerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CServerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG
