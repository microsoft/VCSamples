// RListVw.cpp : implementation of the CRowListView class
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
#include "RowList.h"

#include "RListDoc.h"

#include "ListVwEx.h"   // base class for CRowListView
#include "RListVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRowListView

IMPLEMENT_DYNCREATE(CRowListView, CListViewEx)

BEGIN_MESSAGE_MAP(CRowListView, CListViewEx)
	//{{AFX_MSG_MAP(CRowListView)
	ON_COMMAND(ID_VIEW_SMALLICONS, OnViewSmallIcons)
	ON_COMMAND(ID_VIEW_LARGEICONS, OnViewLargeIcons)
	ON_COMMAND(ID_VIEW_LIST, OnViewList)
	ON_COMMAND(ID_VIEW_DETAILS, OnViewDetails)
	ON_COMMAND(ID_VIEW_ROWDETAILS, OnViewFullRowDetails)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SMALLICONS, OnUpdateViewSmallIcons)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LARGEICONS, OnUpdateViewLargeIcons)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LIST, OnUpdateViewList)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DETAILS, OnUpdateViewDetails)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ROWDETAILS, OnUpdateViewFullRowDetails)
	ON_COMMAND(ID_VIEW_STATEICONS, OnViewStateIcons)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STATEICONS, OnUpdateViewStateIcons)
	ON_COMMAND(ID_VIEW_CLIENTWIDTHSEL, OnViewClientWidthSel)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CLIENTWIDTHSEL, OnUpdateViewClientWidthSel)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRowListView construction/destruction

CRowListView::CRowListView()
{
	m_bStateIcons = TRUE;
	m_nCheckedItem = -1;
	m_hSmallIcon = NULL;
	m_hLargeIcon = NULL;
}

CRowListView::~CRowListView()
{
}

BOOL CRowListView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= LVS_SHOWSELALWAYS | LVS_REPORT;

	return CListViewEx::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// data for the list view control

#define NUM_COLUMNS 8
#define NUM_ITEMS   7

static _TCHAR *_gszColumnLabel[NUM_COLUMNS] =
{
	_T("Color"), _T("Red"), _T("Green"), _T("Blue"),
	_T("Hue"), _T("Sat"), _T("Lum"), _T("Type")
};

static int _gnColumnFmt[NUM_COLUMNS] =
{
	LVCFMT_LEFT, LVCFMT_RIGHT, LVCFMT_RIGHT, LVCFMT_RIGHT,
		LVCFMT_RIGHT, LVCFMT_RIGHT, LVCFMT_RIGHT, LVCFMT_CENTER
};

static int _gnColumnWidth[NUM_COLUMNS] =
{
	150, 50, 50, 50, 100, 50, 50, 150
};

static _TCHAR *_gszItem[NUM_ITEMS][NUM_COLUMNS] =
{
	_T("Yellow"),  _T("255"), _T("255"), _T("0"),   _T("40"),  _T("240"), _T("120"), _T("Neutral"),
	_T("Red"),     _T("255"), _T("0"),   _T("0"),   _T("0"),   _T("240"), _T("120"), _T("Warm"),
	_T("Green"),   _T("0"),   _T("255"), _T("0"),   _T("80"),  _T("240"), _T("120"), _T("Cool"),
	_T("Magenta"), _T("255"), _T("0"),   _T("255"), _T("200"), _T("240"), _T("120"), _T("Warm"),
	_T("Cyan"),    _T("0"),   _T("255"), _T("255"), _T("120"), _T("240"), _T("120"), _T("Cool"),
	_T("Blue"),    _T("0"),   _T("0"),   _T("255"), _T("160"), _T("240"), _T("120"), _T("Cool"),
	_T("Gray"),    _T("192"), _T("192"), _T("192"), _T("160"), _T("0"),   _T("181"), _T("Neutral")
};

/////////////////////////////////////////////////////////////////////////////
// CRowListView initialization

void CRowListView::OnInitialUpdate()
{
	CListViewEx::OnInitialUpdate();

	CListCtrl& ListCtrl = GetListCtrl();

// set image lists

	m_LargeImageList.Create(IDB_LARGEICONS, 32, 1, RGB(255, 255, 255));
	m_SmallImageList.Create(IDB_SMALLICONS, 16, 1, RGB(255, 255, 255));
	m_StateImageList.Create(IDB_STATEICONS, 16, 1, RGB(255, 0, 0));

	m_LargeImageList.SetOverlayImage(NUM_ITEMS, 1);
	m_SmallImageList.SetOverlayImage(NUM_ITEMS, 1);

	ListCtrl.SetImageList(&m_LargeImageList, LVSIL_NORMAL);
	ListCtrl.SetImageList(&m_SmallImageList, LVSIL_SMALL);
	ListCtrl.SetImageList(&m_StateImageList, LVSIL_STATE);

// insert columns

	int i, j;
	LV_COLUMN lvc;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

	for(i = 0; i<NUM_COLUMNS; i++)
	{
		lvc.iSubItem = i;
		lvc.pszText = _gszColumnLabel[i];
		lvc.cx = _gnColumnWidth[i];
		lvc.fmt = _gnColumnFmt[i];
		ListCtrl.InsertColumn(i,&lvc);
	}

// insert items

	LV_ITEM lvi;

	for(i = 0; i < NUM_ITEMS; i++)
	{
		lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
		lvi.iItem = i;
		lvi.iSubItem = 0;
		lvi.pszText = _gszItem[i][0];
		lvi.iImage = i;
		lvi.stateMask = LVIS_STATEIMAGEMASK;
		lvi.state = INDEXTOSTATEIMAGEMASK(1);

		ListCtrl.InsertItem(&lvi);
	}

// set item text for additional columns

	for(i = 0; i<NUM_ITEMS; i++)
	{
		for(j = 1; j<NUM_COLUMNS; j++)
		{
			ListCtrl.SetItemText(i,j,_gszItem[i][j]);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRowListView diagnostics

#ifdef _DEBUG
void CRowListView::AssertValid() const
{
	CListViewEx::AssertValid();
}

void CRowListView::Dump(CDumpContext& dc) const
{
	CListViewEx::Dump(dc);
}

CRowListDoc* CRowListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRowListDoc)));
	return (CRowListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRowListView helpers

BOOL CRowListView::SetViewType(DWORD dwViewType)
{
	return(ModifyStyle(LVS_TYPEMASK,dwViewType & LVS_TYPEMASK));
}

DWORD CRowListView::GetViewType()
{
	return(GetStyle() & LVS_TYPEMASK);
}

void CRowListView::CheckItem(int nNewCheckedItem)
{
	CListCtrl& ListCtrl = GetListCtrl();

// reset if there is checked item

	if (m_nCheckedItem != -1)
	{
		if (m_bStateIcons)
		{
			ListCtrl.SetItemState(m_nCheckedItem,
				INDEXTOSTATEIMAGEMASK(1), LVIS_STATEIMAGEMASK);
		}
		else
		{
			ListCtrl.SetItemState(m_nCheckedItem,
				INDEXTOSTATEIMAGEMASK(1),
				LVIS_STATEIMAGEMASK | LVIS_OVERLAYMASK);
		}

		::DestroyIcon(m_hSmallIcon);
		::DestroyIcon(m_hLargeIcon);
	}

// check new item and set its icon as the app icon

	CWnd* pMainWnd = AfxGetMainWnd();

	if (m_nCheckedItem == nNewCheckedItem)
	{
		m_nCheckedItem = -1;
		pMainWnd->SetIcon(NULL, FALSE);
		pMainWnd->SetIcon(NULL, TRUE);
	}
	else if ((m_nCheckedItem = nNewCheckedItem) != -1)
	{
		if (m_bStateIcons)
		{
			ListCtrl.SetItemState(m_nCheckedItem,
				INDEXTOSTATEIMAGEMASK(2), LVIS_STATEIMAGEMASK);
		}
		else
		{
			ListCtrl.SetItemState(m_nCheckedItem,
				INDEXTOSTATEIMAGEMASK(2) | INDEXTOOVERLAYMASK(1),
				LVIS_STATEIMAGEMASK | LVIS_OVERLAYMASK);
		}

		m_hSmallIcon =
			ListCtrl.GetImageList(LVSIL_SMALL)->ExtractIcon(nNewCheckedItem);
		pMainWnd->SetIcon(m_hSmallIcon,FALSE);
		m_hLargeIcon =
			ListCtrl.GetImageList(LVSIL_NORMAL)->ExtractIcon(nNewCheckedItem);
		pMainWnd->SetIcon(m_hLargeIcon,TRUE);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRowListView message handlers

void CRowListView::OnViewSmallIcons()
{
	if (GetViewType() != LVS_SMALLICON)
		SetViewType(LVS_SMALLICON);
}

void CRowListView::OnViewLargeIcons()
{
	if (GetViewType() != LVS_ICON)
		SetViewType(LVS_ICON);
}

void CRowListView::OnViewList()
{
	if (GetViewType() != LVS_LIST)
		SetViewType(LVS_LIST);
}

void CRowListView::OnViewDetails()
{
	if ((GetViewType() != LVS_REPORT) || GetFullRowSel())
	{
		SetFullRowSel(FALSE);
		if (GetViewType() != LVS_REPORT)
			SetViewType(LVS_REPORT);
	}
}

void CRowListView::OnViewFullRowDetails()
{
	if ((GetViewType() != LVS_REPORT) || !GetFullRowSel())
	{
		SetFullRowSel(TRUE);
		if (GetViewType() != LVS_REPORT)
			SetViewType(LVS_REPORT);
	}
}

void CRowListView::OnUpdateViewSmallIcons(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetViewType() == LVS_SMALLICON);
}

void CRowListView::OnUpdateViewLargeIcons(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetViewType() == LVS_ICON);
}

void CRowListView::OnUpdateViewList(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetViewType() == LVS_LIST);
}

void CRowListView::OnUpdateViewDetails(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck((GetViewType() == LVS_REPORT) && !GetFullRowSel());
}

void CRowListView::OnUpdateViewFullRowDetails(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck((GetViewType() == LVS_REPORT) && GetFullRowSel());
}

void CRowListView::OnViewStateIcons()
{
	m_bStateIcons =! m_bStateIcons;

	CListCtrl& ListCtrl = GetListCtrl();

	if (m_bStateIcons)
	{
		ListCtrl.SetImageList(&m_StateImageList, LVSIL_STATE);
		ListCtrl.SetItemState(m_nCheckedItem, 0, LVIS_OVERLAYMASK);
	}
	else
	{
		ListCtrl.SetImageList(NULL,LVSIL_STATE);
		if (m_nCheckedItem != -1)
		{
			ListCtrl.SetItemState(m_nCheckedItem,
				INDEXTOOVERLAYMASK(1), LVIS_OVERLAYMASK);
		}
	}
}

void CRowListView::OnUpdateViewStateIcons(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bStateIcons);
}

void CRowListView::OnViewClientWidthSel()
{
	m_bClientWidthSel = !m_bClientWidthSel;

	Invalidate();
	UpdateWindow();
}

void CRowListView::OnUpdateViewClientWidthSel(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bClientWidthSel);
	pCmdUI->Enable((GetViewType() == LVS_REPORT) && GetFullRowSel());
}

void CRowListView::OnLButtonDown(UINT nFlags, CPoint point)
{
	UINT uFlags = 0;
	int nHitItem = GetListCtrl().HitTest(point, &uFlags);

	// we need additional checking in owner-draw mode
	// because we only get LVHT_ONITEM
	BOOL bHit = FALSE;
	if (uFlags == LVHT_ONITEM && (GetStyle() & LVS_OWNERDRAWFIXED))
	{
		CRect rect;
		GetListCtrl().GetItemRect(nHitItem, rect, LVIR_ICON);

		// check if hit was on a state icon
		if (m_bStateIcons && point.x < rect.left)
			bHit = TRUE;
	}
	else if (uFlags & LVHT_ONITEMSTATEICON)
		bHit = TRUE;

	if (bHit)
		CheckItem(nHitItem);
	else
		CListViewEx::OnLButtonDown(nFlags, point);
}

void CRowListView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	UINT uFlags = 0;
	int nHitItem = GetListCtrl().HitTest(point, &uFlags);

	if (uFlags & LVHT_ONITEM)
	{
		// double click works only if we don't have state icons,
		// or if we are in icon or small icon view
		if (!m_bStateIcons || GetViewType() == LVS_ICON ||
			GetViewType()==LVS_SMALLICON)
		{
			CheckItem(nHitItem);
		}
	}

	CListViewEx::OnLButtonDblClk(nFlags, point);
}
