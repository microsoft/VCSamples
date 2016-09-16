// ObjView.cpp : implementation file
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

#include "mainfrm.h"
#include "cntritem.h"
#include "BindDoc.h"
#include "BindView.h"
#include "ObjView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CObjListView

IMPLEMENT_DYNCREATE(CObjListView, CView)

#pragma warning(disable: 4355)  // 'this' : used in base member initializer list
CObjListView::CObjListView()
	: m_listbox(this), m_bFont(FALSE)
{
}
#pragma warning(default: 4355)

CObjListView::~CObjListView()
{
	// if we used a stock font, don't delete it
	if (!m_bFont)
		m_IconFont.Detach();
}


BEGIN_MESSAGE_MAP(CObjListView, CView)
	//{{AFX_MSG_MAP(CObjListView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CObjListView drawing

void CObjListView::OnDraw(CDC* /*pDC*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CObjListView diagnostics

#ifdef _DEBUG
void CObjListView::AssertValid() const
{
	CView::AssertValid();
}

void CObjListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CObjListView message handlers

int CObjListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// Creates the view and creates the listbox that takes up
	// the view's client area.
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a font to draw icon text with.
	LOGFONT lf;
	m_bFont = SystemParametersInfo(SPI_GETICONTITLELOGFONT,
		sizeof(lf), &lf, FALSE);

	if (m_bFont)
		m_bFont = m_IconFont.CreateFontIndirect(&lf);
	if (!m_bFont)
		m_IconFont.Attach(GetStockObject(ANSI_VAR_FONT));

	// create the listbox to fill our client area.
	CRect rc;
	GetClientRect(&rc);
	if (!m_listbox.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY |
			LBS_HASSTRINGS | LBS_OWNERDRAWFIXED | LBS_NOINTEGRALHEIGHT,
				rc, this, ID_LISTBOX))
	{
		return -1;
	}

	return 0;
}

BOOL CObjListView::AddItem(COleClientItem *pObject, CString& name,
	HICON hIcon)
{
	// Creates a CItemIcons data structure to hold item data and
	// adds the item to the list box.

	#pragma warning (suppress: 6014)
	CItemIcons *pitem = new CItemIcons;
	pitem->m_Name = name;
	pitem->m_hIcon = hIcon;
	pitem->m_pObject = pObject;

	int itemID = m_listbox.AddString(name);
	if (itemID != LB_ERR)
		m_listbox.SetItemData(itemID, (DWORD_PTR) pitem);
	m_listbox.SetCurSel(itemID);
	return TRUE;
}

BOOL CObjListView::RemoveItem(COleClientItem *pRemove)
{
	// Removes an item from the list box and sets focus to the previous
	// item in the list, if there is one.
	CItemIcons *pitem = NULL;
	CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

	// We'll have to walk our list control and find the item to remove;
	int nItem;
	for (nItem = 0; nItem < m_listbox.GetCount(); nItem++)
	{
		pitem = (CItemIcons*) m_listbox.GetItemData(nItem);
		if (pitem && pitem->m_pObject == pRemove)
		{
			m_listbox.DeleteString(nItem);//delete item from listbox
			delete pitem; //free up the item
		}
	}

	if (m_listbox.GetCount() == 0) //no items left
		return TRUE;

	// set the previous item in the listbox as the current item

	pitem = (CItemIcons*) m_listbox.GetItemData( m_listbox.GetCount() - 1);
	if (pitem != NULL)
	{
		ENSURE(pitem->m_pObject != NULL);
		pitem->m_pObject->Activate(OLEIVERB_SHOW, pFrame->GetDocView());
		pitem->m_pObject->GetInPlaceWindow()->SetFocus();

		pFrame->GetDocView()->m_pSelection = (CMFCBindCntrItem*) pitem->m_pObject;
	}

	m_listbox.SetCurSel(m_listbox.GetCount() - 1);
	return TRUE;
}

void CObjListView::RemoveAllItems()
{
	//Clears the listbox.  This also has the efect of deleting all of the CItemIcons from
	//the listbox.

	CItemIcons *pItem=0;
	int nItems = m_listbox.GetCount();
	for(int i=0;i<nItems;i++)
	{
		pItem = (CItemIcons*)m_listbox.GetItemData(i);
		if (pItem)
			delete pItem;
	}
	m_listbox.ResetContent();

}

void CObjListView::OnDestroy()
{
	// When we destroy the view, we need to make sure we loop
	// through all the items in the listbox and delete the CItemIcon structs
	// associated with each item in the listbox.

	CView::OnDestroy();

	// We can safely assume that all child windows still exist
	// so, we can go through each item in the list box and delete
	// the CItemIcons objects stored in item data.

	int nItem;
	for (nItem = 0; nItem < m_listbox.GetCount(); nItem++)
	{
		CItemIcons *pitem = (CItemIcons*) m_listbox.GetItemData(nItem);
		if (DWORD_PTR(pitem) != LB_ERR)
			delete pitem;
	}
}

void CObjListView::OnSize(UINT nType, int cx, int cy)
{
	// re-sizes the listbox in the client area when the view gets resized.
	CView::OnSize(nType, cx, cy);
	m_listbox.SetWindowPos(this, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOZORDER);

}

/////////////////////////////////////////////////////////////////////////////
// CCustomList

CCustomList::CCustomList()
{
}

CCustomList::~CCustomList()
{
}


BEGIN_MESSAGE_MAP(CCustomList, CListBox)
	//{{AFX_MSG_MAP(CCustomList)
	ON_CONTROL_REFLECT(LBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomList message handlers

void CCustomList::OnSelchange()
{
	// This function will be called when someone clicks on an item in
	// the listbox. Each item's item data holds a pointer to a CItemIcons
	// structure, which holds pointers to the COleDocObjectItem for the embedded
	// item, pointers to the item's icon's metafile struct and a CString that
	// holds the name of the item.  When someone picks a new item from the list,
	// we should get the item data to get at the CItemIcon struct, check to see
	// if the item clicked on is the same item that is currently activated,
	// and, if it isn't, deactivate the currently activated item and
	// activate the newly selected item.

	// Get a pointer to the view and document that is holding our objects
	CMainFrame *pMainFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;
	ENSURE(pMainFrame != NULL);

	COleDocument *pDocument = (COleDocument*) pMainFrame->GetActiveDocument();
	ENSURE(pDocument != NULL);

	CView *pObjView = (CView*) pMainFrame->GetDocView();

	// get the item data
	int nItem = GetCurSel();
	CItemIcons* pdata = (CItemIcons*) GetItemData(nItem);
	if (DWORD_PTR(pdata) == LB_ERR)
		return;

	COleClientItem *pActiveItem = pDocument->GetInPlaceActiveItem(pObjView);

	// check to see if we're already active
	if (pActiveItem == pdata->m_pObject)
	{
		pActiveItem->GetInPlaceWindow()->SetFocus();
		pMainFrame->GetDocView()->m_pSelection = (CMFCBindCntrItem*) pActiveItem;
		return; // already active, no work to do
	}
	else if (pActiveItem != NULL)
		pActiveItem->Deactivate(); // deactivate the already active item

	// activate the newly selected item
	pActiveItem = pdata->m_pObject;
	pActiveItem->Activate(OLEIVERB_SHOW, pObjView);
	CWnd *pWndEdit = pActiveItem->GetInPlaceWindow();
	if (pWndEdit != NULL)
		pWndEdit->SetFocus();
	pMainFrame->GetDocView()->m_pSelection = (CMFCBindCntrItem*) pActiveItem;
}

void CCustomList::MeasureItem(LPMEASUREITEMSTRUCT lpm)
{
	//specify how high each listbox item will be.
	lpm->itemHeight = GetSystemMetrics(SM_CYICONSPACING);
}

void CCustomList::DrawItem(LPDRAWITEMSTRUCT ldis)
{
	ENSURE(ldis != NULL);

	// drawing code for each item. We fill the entire rectangle
	// depending on whether or not we are drawing a selected item then
	// we draw the icon and the title held in the CItemIcons struct.
	COLORREF oldTextColor=0;
	COLORREF oldBkColor=0;
	CRect rc(ldis->rcItem);
	int cxIcon = GetSystemMetrics(SM_CXICON);
	int cyIcon = GetSystemMetrics(SM_CYICON);

	CDC dc;
	dc.Attach(ldis->hDC);

	// we stored a pointer to our CItemIcons struct in item data

	CItemIcons *pItem = (CItemIcons*) GetItemData(ldis->itemID);
	CFont *pOldFont = dc.SelectObject(&m_pParent->m_IconFont);
	CRect rcText;

	switch(ldis->itemAction)
	{
		case ODA_SELECT:
		case ODA_DRAWENTIRE:
			ASSERT(pItem->m_hIcon != NULL);
			// draw the background with system-wide color preference
			if (ldis->itemState & ODS_SELECTED)
			{
				dc.FillSolidRect(rc, ::GetSysColor(COLOR_HIGHLIGHT));
				oldTextColor = dc.SetTextColor(::GetSysColor(COLOR_WINDOW) );
				oldBkColor = dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT) );
			}
			else
				dc.FillSolidRect(rc, ::GetSysColor(COLOR_WINDOW));

			// Draw the icon
			dc.DrawIcon((rc.Width() / 2) - (cxIcon / 2), rc.top + 5,
				pItem->m_hIcon);

			// calculate a rect to place the text centered below
			// the icon then draw the text
			rcText.SetRect(rc.left, rc.top + cyIcon + 4, rc.right, rc.bottom);
			dc.DrawText(pItem->m_Name, rcText, DT_CENTER | DT_TOP);
			if (ldis->itemState & ODS_SELECTED)
			{
				//we changed the text color in this case
				//so (being good GDI programmers) now we must change it back.
				dc.SetTextColor(oldTextColor);
				dc.SetBkColor(oldBkColor);
			}

			break;

		case ODA_FOCUS:
			break;
	}

	// restore the DC
	dc.SelectObject(pOldFont);
	dc.Detach();
}
