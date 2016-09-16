// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "padview.h"
#include "paddoc.h"
#include "paditem.h"
#include <limits.h>
#include <winnls.h>

IMPLEMENT_DYNAMIC(CEmbeddedItem, COleServerItem)

CEmbeddedItem::CEmbeddedItem(CPadDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	m_nBeg = 0;
	m_nEnd = UINT_MAX;

	// support CF_TEXT format
	GetDataSource()->DelayRenderFileData(CF_TEXT);
}

BOOL CEmbeddedItem::OnRenderFileData(LPFORMATETC lpFormatEtc, CFile* pFile)
{
	ENSURE(lpFormatEtc != NULL);
	if (lpFormatEtc->cfFormat != CF_TEXT)
		return COleServerItem::OnRenderFileData(lpFormatEtc, pFile);

	BOOL bResult = FALSE;
	TRY
	{
		// save contents of this item to the file
		SaveToFile(pFile);

		// CF_TEXT has NUL termination
		char chZero = '\0';
		pFile->Write(&chZero, sizeof(char));

		bResult = TRUE; // success
	}
	END_TRY

	return bResult;
}

CPadView* CEmbeddedItem::GetView() const
{
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	POSITION pos = pDoc->GetFirstViewPosition();
	if (pos == NULL)
		return NULL;

	CPadView* pView = (CPadView*)pDoc->GetNextView(pos);
	ASSERT_VALID(pView);
	ASSERT_KINDOF(CPadView, pView);
	return pView;
}

void CEmbeddedItem::SaveToFile(CFile* pFile)
{
	CPadView* pView = GetView();
	LPCTSTR lpszText = NULL;

	TRY
	{
		// get access to the edit buffer
		lpszText = pView->LockBuffer();

		// get range (make sure inside of text length)
		UINT nEnd = pView->GetWindowTextLength();
		UINT nBeg = min(m_nBeg, nEnd);
		nEnd = min(m_nEnd, nEnd);
#ifdef _UNICODE
		// copy to temp buffer, convert, then write to file
		int nLen = WideCharToMultiByte(CP_ACP, 0, lpszText+nBeg, nEnd-nBeg,
			NULL, 0, NULL, NULL);
		char* pszTemp = new char[nLen];
		WideCharToMultiByte(CP_ACP, 0, lpszText+nBeg, nEnd-nBeg,
			pszTemp, nLen, NULL, NULL);
		pFile->Write(pszTemp, nLen);
		delete[] pszTemp;
#else
		// write it out to the file
		pFile->Write(lpszText+nBeg, (nEnd-nBeg) * sizeof(char));
#endif
	}
	END_TRY

	// release access to edit buffer
	if (lpszText != NULL)
		pView->UnlockBuffer();
}

void CEmbeddedItem::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// save just the portion this item refers to
		ar.Flush();
		CFile* pFile = ar.GetFile();
		SaveToFile(pFile);
	}
	else
	{
		// otherwise, read in the entire file
		GetDocument()->Serialize(ar);
	}
}

BOOL CEmbeddedItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// no drawing will happen if cliprect is NULL
	CClientDC dc(NULL);
	dc.IntersectClipRect(0, 0, 0, 0);
	return OnDraw(&dc, rSize);
}

BOOL CEmbeddedItem::OnDraw(CDC* pDC, CSize& rSize)
{
	// get view attached to the item
	CPadView* pView = GetView();

	// In some situations, OLE1 servers will ask for the presentation data
	//  during shutdown, even though it is not necessary (since the picture
	//  has not changed).  This will happen when closing a frame window
	//  for example.  By this time all the views are gone and there is no
	//  way to produce the metafile data, since the actual text is
	//  stored by the edit control (the view).  In this case, we simply
	//  fail the call.
	if (pView == NULL)
		return FALSE;

	// edit controls have a border around them
	CRect rectClient;
	CRect margin;

	{ // Calculate correct ClientRect
		pView->GetClientRect(&rectClient);
		rectClient.InflateRect(-1,-1);

		if (pView->GetStyle() & WS_HSCROLL)
			rectClient.bottom++;
		if (pView->GetStyle() & WS_VSCROLL)
			rectClient.right++;
	}

	{ // Calculate margins
		CRect rectEdit;
		pView->GetEditCtrl().GetRect(&rectEdit);

		if (rectEdit.IsRectEmpty())
			rectEdit.SetRect(4,4,4,4);

		int HorzMargin = rectEdit.left - rectClient.left;
		int VertMargin = rectEdit.top - rectClient.top;

		margin.SetRect(HorzMargin,VertMargin,HorzMargin,VertMargin);

		if (pView->GetStyle() & WS_HSCROLL)
			margin.bottom++;
		if (pView->GetStyle() & WS_VSCROLL)
			margin.right++;
	}

	// get the font from the CEditView
	CFont* pFont = pView->GetFont();
	CFont* pOldFont = NULL;
	if (pFont != NULL)
		pOldFont = pDC->SelectObject(pFont);

	// get formatting rectangle
	CRect rect(rectClient);
	rect.left += margin.left;
	rect.top += margin.top;
	rect.right -= margin.right;
	rect.bottom = INT_MAX;

	pDC->SetBkMode(TRANSPARENT);

	// first just determine the correct extents of the text
	pDC->SaveDC();
	pDC->IntersectClipRect(0, 0, 0, 0); // no drawing with NULL clipping
	if (pView->PrintInsideRect(pDC, rect, m_nBeg, m_nEnd) == 0)
	{
		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);
		rect.bottom = rect.top + tm.tmHeight + tm.tmExternalLeading;
	}
	pDC->RestoreDC(-1);

	// then, really output the text
	pDC->SetWindowOrg(rect.left-margin.left,rect.top-margin.top);
	pDC->SetWindowExt(margin.left + rect.Width() + margin.right,
		margin.top + rect.Height() + margin.bottom);
	pView->PrintInsideRect(pDC, rect, m_nBeg, m_nEnd);

	// adjust for border (rect.left is already adjusted)
	rect.left -= margin.left;
	rect.top -= margin.top;
	rect.right += margin.right;
	rect.bottom += margin.bottom;

	// select previous font
	if (pOldFont != NULL)
		pDC->SelectObject(pOldFont);

	// return HIMETRIC size
	rSize = rect.Size();
	pDC->LPtoHIMETRIC(&rSize);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
