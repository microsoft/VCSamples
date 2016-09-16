// TreeCtrlPage.cpp : implementation file
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
#include "CmnCtrl1.h"
#include "treecpg.h"
#include "mtreectl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlPage property page

IMPLEMENT_DYNCREATE(CTreeCtrlPage, CPropertyPage)

CTreeCtrlPage::CTreeCtrlPage() : CPropertyPage(CTreeCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CTreeCtrlPage)
	m_bDisableDragDrop = FALSE;
	m_bHasButtons = FALSE;
	m_bHasLines = FALSE;
	m_bLinesAtRoot = FALSE;
	m_bEditLabels = FALSE;
	m_bShowSelAlways = FALSE;
	m_cstrStatus = _T("");
	m_bSingleExpand = FALSE;
	//}}AFX_DATA_INIT
	m_psp.dwFlags &= ~PSP_HASHELP;  // Lose the Help button
}

CTreeCtrlPage::~CTreeCtrlPage()
{
}

void CTreeCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeCtrlPage)
	DDX_Control(pDX, IDC_TREESTATUS, m_notifshowcase);
	DDX_Control(pDX, IDC_TREEVIEW1, m_mytreectrl);
	DDX_Check(pDX, IDC_TVDISABLEDDRAGDROP, m_bDisableDragDrop);
	DDX_Check(pDX, IDC_TVHASBUTTONS, m_bHasButtons);
	DDX_Check(pDX, IDC_TVHASLINES, m_bHasLines);
	DDX_Check(pDX, IDC_TVLINESATROOT, m_bLinesAtRoot);
	DDX_Check(pDX, IDC_TVEDITLABELS, m_bEditLabels);
	DDX_Check(pDX, IDC_TVSHOWSELALWAYS, m_bShowSelAlways);
	DDX_Text(pDX, IDC_TREESTATUS, m_cstrStatus);
	DDX_Check(pDX, IDC_TVSSINGELEXPAND, m_bSingleExpand);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTreeCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CTreeCtrlPage)
	ON_BN_CLICKED(IDC_TVEDITLABELS, OnEditLabels)
	ON_BN_CLICKED(IDC_TVHASBUTTONS, OnHasButtons)
	ON_BN_CLICKED(IDC_TVHASLINES, OnHasLines)
	ON_BN_CLICKED(IDC_TVLINESATROOT, OnLinesAtRoot)
	ON_BN_CLICKED(IDC_TVDISABLEDDRAGDROP, OnDisabledDragDrop)
	ON_BN_CLICKED(IDC_TVSHOWSELALWAYS, OnShowSelAlways)
	ON_NOTIFY(TVN_BEGINLABELEDIT, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_SELCHANGING, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_GETDISPINFO, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_SETDISPINFO, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_ITEMEXPANDED, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_BEGINDRAG, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_KEYDOWN, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_SELCHANGING, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_ITEMEXPANDED, IDC_TREEVIEW1, ShowNotification)
	ON_NOTIFY(TVN_DELETEITEM, IDC_TREEVIEW1, ShowNotification)
	ON_BN_CLICKED(IDC_TVSSINGELEXPAND, OnSingleExpand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlPage message handlers
BOOL CTreeCtrlPage::OnInitDialog()
{
	CImageList          *pImageList;
	CBitmap             bitmap;
	CString             strItems[12];
	CCmnCtrl1App        *pApp;
	int                 iItem;
	UINT                nID;
	TV_INSERTSTRUCT     curTreeItem;

	strItems[0]= _T("Dogs");
	strItems[1]= _T("German Shepherd");
	strItems[2]= _T("Dalmatian");
	strItems[3]= _T("Great Dane");
	strItems[4]= _T("Birds");
	strItems[5]= _T("Hummingbird");
	strItems[6]= _T("Pigeon");
	strItems[7]= _T("Eagle");
	strItems[8]= _T("Fish");
	strItems[9]= _T("Snapper");
	strItems[10]= _T("Sole");
	strItems[11]= _T("Salmon");

	pApp = (CCmnCtrl1App *)AfxGetApp();
	CPropertyPage::OnInitDialog();  // let the base class do the default work
	pImageList = new CImageList();
	pImageList->Create(32, 16, ILC_MASK, 6, 4);

	for (nID = IDB_BMTREEFIRST; nID <= IDB_BMTREELAST; nID++)  // load bitmaps for dog, bird and fish
	{
		bitmap.LoadBitmap(nID);
		pImageList->Add(&bitmap, (COLORREF)0xFFFFFF);
		bitmap.DeleteObject();
	}

	m_mytreectrl.SetImageList(pImageList, TVSIL_NORMAL);
	for (iItem = 0; iItem < CELEMS(strItems); iItem ++)
	{
		curTreeItem.hParent = (iItem % 4 == 0)? NULL : m_rghItem[iItem / 4 * 4];
		curTreeItem.hInsertAfter = TVI_SORT;
		curTreeItem.item.iImage = iItem / 4 * 2;
		curTreeItem.item.iSelectedImage = curTreeItem.item.iImage + 1;
		curTreeItem.item.pszText = strItems[iItem].GetBuffer(strItems[iItem].GetLength());
		curTreeItem.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;
		m_rghItem[iItem] = m_mytreectrl.InsertItem(&curTreeItem);
	}

	return FALSE;
}

void CTreeCtrlPage::OnEditLabels()
{
	UpdateData(TRUE/*bSaveAndValidate*/);  // get information from the dialog
	m_mytreectrl.SetNewStyle(TVS_EDITLABELS, m_bEditLabels);
}

void CTreeCtrlPage::OnHasButtons()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_HASBUTTONS, m_bHasButtons);
}

void CTreeCtrlPage::OnHasLines()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_HASLINES, m_bHasLines);
}

void CTreeCtrlPage::OnLinesAtRoot()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_LINESATROOT, m_bLinesAtRoot);
}

void CTreeCtrlPage::OnDisabledDragDrop()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_DISABLEDRAGDROP, m_bDisableDragDrop);
}

void CTreeCtrlPage::OnShowSelAlways()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_SHOWSELALWAYS, m_bShowSelAlways);
}

void CTreeCtrlPage::ShowNotification(LPNMHDR pnmhdr, LRESULT* /*pResult*/)
{
	((CNotifyShowCase *)GetDlgItem(IDC_TREESTATUS))->ShowNotification(pnmhdr->code);
}

void CTreeCtrlPage::OnSingleExpand()
{
	UpdateData(TRUE);
	m_mytreectrl.SetNewStyle(TVS_SINGLEEXPAND, m_bSingleExpand);
}
