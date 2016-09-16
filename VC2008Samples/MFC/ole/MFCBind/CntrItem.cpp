// CntrItem.cpp : implementation of the CMFCBindCntrItem class
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
#include "MFCBind.h"

#include "BindDoc.h"
#include "BindView.h"
#include "CntrItem.h"
#include "mainfrm.h"
#include "ObjView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCBindCntrItem implementation

int CMFCBindCntrItem::m_nDocID = 1;

IMPLEMENT_SERIAL(CMFCBindCntrItem, COleDocObjectItem, 0)

CMFCBindCntrItem::CMFCBindCntrItem(CMFCBindDoc* pContainer)
	: COleDocObjectItem(pContainer)
{
}

CMFCBindCntrItem::~CMFCBindCntrItem()
{
	// TODO: add cleanup code here

}

void CMFCBindCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);
	GetDocument()->UpdateAllViews(NULL);
}

BOOL CMFCBindCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;
	return TRUE;
}

void CMFCBindCntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);
	m_pView->GetClientRect(rPosition);
}

void CMFCBindCntrItem::OnActivate()
{
   CFrameWnd* pFrame = DYNAMIC_DOWNCAST(CFrameWnd, AfxGetApp()->m_pMainWnd);
   ENSURE(pFrame != NULL);

   CWnd* pView = pFrame->GetActiveView();
   ENSURE(pView != NULL);

   COleDocObjectItem* pItem =
	  (COleDocObjectItem*) GetDocument()->GetInPlaceActiveItem(pView);

   // if this isn't the item being activated, deactivate it.
   if (pItem != NULL && pItem != this)
	  pItem->Deactivate();

   COleDocObjectItem::OnActivate();
}

void CMFCBindCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleDocObjectItem::OnDeactivateUI(bUndoable);
}

void CMFCBindCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleDocObjectItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CMFCBindCntrItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleDocObjectItem::Serialize(ar);

	// now store/retrieve data specific to CMFCBindCntrItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCBindCntrItem diagnostics

#ifdef _DEBUG
void CMFCBindCntrItem::AssertValid() const
{
	COleDocObjectItem::AssertValid();
}

void CMFCBindCntrItem::Dump(CDumpContext& dc) const
{
	COleDocObjectItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
//

void CMFCBindCntrItem::ProcessNewObject()
{
	// This function get's an HICON for the server from the registry by
	// using our GetObjectIconFromRegistry function.  We also generate a
	// name and tell the object list view to add this information to
	// the list box.

	if (!m_lpObject)
		return; //no object, something must've gone wrong

	CString strName;
	strName.Format(_T("Section %d "), m_nDocID);
	m_nDocID++;

	HICON hIcon = GetIconFromRegistry();
	if (hIcon != NULL)
	{
		CMainFrame* pFrame = DYNAMIC_DOWNCAST(CMainFrame, AfxGetApp()->m_pMainWnd);
		ENSURE(pFrame != NULL);
		CObjListView *pListView = pFrame->GetObjListView();
		if (pListView == NULL)
			return;

		pListView->AddItem((COleDocObjectItem*) this, strName, hIcon);
	}
}

BOOL CMFCBindCntrItem::FinishCreate(SCODE sc)
{
	// FinishCreate is an undocumented virtual function that we
	// override here to do some extra processing after the object
	// has been created.

	if (FAILED(sc))
	{
		AfxMessageBox(_T("OleCreate failed to create this item!"));
		return FALSE;
	}

	BOOL bRet = COleDocObjectItem::FinishCreate(sc);
	if (bRet)
		ProcessNewObject();
	return bRet;

}

void CMFCBindCntrItem::LoadFromMoniker(LPUNKNOWN pUnk, OLECHAR* szwName)
{
	HRESULT hr;
	// Ask the system for a URL Moniker
	IMoniker* pIMoniker;
	hr = CreateURLMoniker(NULL, (LPWSTR)szwName, &pIMoniker);
	if ( SUCCEEDED(hr) )
	{
		// Get the IPersistMoniker interface
		IPersistMoniker* pPMk;
		hr = pUnk->QueryInterface(
								IID_IPersistMoniker,
								(void **)&pPMk);
		if ( SUCCEEDED(hr) )
		{
				// note: do not register our BSC when calling IPM::Load directly
			IBindCtx *pBCtx;
			hr = CreateBindCtx(0, &pBCtx);
			if ( SUCCEEDED(hr) )
			{
				// Call Load on the IPersistMoniker
				hr = pPMk->Load(FALSE, pIMoniker, pBCtx, STGM_READ);
					pBCtx->Release();
			}
			pPMk->Release();
		}
		pIMoniker->Release( );
	}
}
