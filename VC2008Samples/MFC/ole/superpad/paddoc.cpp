// paddoc.cpp : implementation of the CPadDoc class
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
#include "superpad.h"
#include "paddoc.h"
#include "paditem.h"
#include "linkitem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPadDoc

IMPLEMENT_DYNCREATE(CPadDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CPadDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CPadDoc)
	ON_COMMAND(ID_VIEW_UPDATENOW, OnViewUpdatenow)
	ON_COMMAND(ID_CANCEL_INPLACE, OnCancelInplace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPadDoc delegation to CEditView

CPadDoc::CPadDoc()
{
}

CPadDoc::~CPadDoc()
{
}

void CPadDoc::DeleteContents()
{
	COleServerDoc::DeleteContents();
	if (m_viewList.IsEmpty())
		return;
	CEditView* pView = (CEditView*)m_viewList.GetHead();
	ASSERT_KINDOF(CEditView, pView);
	pView->DeleteContents();
}

void CPadDoc::Serialize(CArchive& ar)
{
	CEditView* pView = (CEditView*)m_viewList.GetHead();
	ASSERT_KINDOF(CEditView, pView);
	pView->SerializeRaw(ar);
}

COleServerItem* CPadDoc::OnGetEmbeddedItem()
{
	CEmbeddedItem* pItem = new CEmbeddedItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}

COleServerItem* CPadDoc::OnGetLinkedItem(LPCTSTR lpszItemName)
{
	CPadLinkItem *pItem =
		(CPadLinkItem*)COleServerDoc::OnGetLinkedItem(lpszItemName);
	if (pItem == NULL)
		pItem = new CPadLinkItem(this, lpszItemName);

	ASSERT_VALID(pItem);
	return pItem;
}

/////////////////////////////////////////////////////////////////////////////

void CPadDoc::OnViewUpdatenow()
{
	UpdateAllItems(NULL);
}

// Note: both the server and the container should have a keyboard method
//  of deactivating an active in-place item.

void CPadDoc::OnCancelInplace()
{
	if (IsInPlaceActive())
		OnDeactivateUI(FALSE);
}

void CPadDoc::SetSelection(int nBeg, int nEnd)
{
	CEditView* pView = (CEditView*)m_viewList.GetHead();
	ASSERT_KINDOF(CEditView, pView);
	pView->GetEditCtrl().SetSel(nBeg, nEnd);
}
