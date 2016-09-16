// ListHdrDlg.cpp : implementation file
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
#include "ListHdr.h"
#include "LHdrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListHdrDlg dialog

CListHdrDlg::CListHdrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListHdrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListHdrDlg)
	m_bNoLabelWrap = FALSE;
	m_bAutoArrange = FALSE;
	m_bSingleSel = FALSE;
	m_bEditLabels = FALSE;
	m_bNoColHdr = FALSE;
	m_bNoSortHdr = FALSE;
	m_strViewMode = _T("REPORT");
	m_strAlignMode = _T("ALIGNTOP");
	m_strSortMode = _T("None");
	m_bHoverSelect = FALSE;
	m_bWorkAreas = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bHotCursor= TRUE;
	m_pImageHdrSmall = NULL;
	m_pImageList = NULL;
	m_pImageListSmall = NULL;
}

CListHdrDlg::~CListHdrDlg()
{
	if( m_pImageHdrSmall != NULL)
		delete m_pImageHdrSmall;
	if( m_pImageList != NULL)
		delete m_pImageList;
	if( m_pImageListSmall != NULL)
		delete m_pImageListSmall;
}

void CListHdrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListHdrDlg)
	DDX_Control(pDX, IDC_LISTVIEW1, m_listctrl);
	DDX_Check(pDX, IDC_NOLABELWRAP, m_bNoLabelWrap);
	DDX_Check(pDX, IDC_AUTOARRANGE, m_bAutoArrange);
	DDX_Check(pDX, IDC_SINGLESEL, m_bSingleSel);
	DDX_Check(pDX, IDC_EDITLABELS, m_bEditLabels);
	DDX_Check(pDX, IDC_NOCOLUMNHEADER, m_bNoColHdr);
	DDX_Check(pDX, IDC_NOSORTHEADER, m_bNoSortHdr);
	DDX_CBString(pDX, IDC_VIEWMODE, m_strViewMode);
	DDX_CBString(pDX, IDC_ALIGN, m_strAlignMode);
	DDX_CBString(pDX, IDC_SORT, m_strSortMode);
	DDX_Check(pDX, IDC_HOVER, m_bHoverSelect);
	DDX_Check(pDX, IDC_WORKAREAS, m_bWorkAreas);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListHdrDlg, CDialog)
	//{{AFX_MSG_MAP(CListHdrDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NOLABELWRAP, OnNoLabelWrap)
	ON_BN_CLICKED(IDC_AUTOARRANGE, OnAutoArrange)
	ON_BN_CLICKED(IDC_EDITLABELS, OnEditLabels)
	ON_BN_CLICKED(IDC_NOCOLUMNHEADER, OnNoColHdr)
	ON_BN_CLICKED(IDC_NOSORTHEADER, OnNoSortHdr)
	ON_BN_CLICKED(IDC_SINGLESEL, OnSingleSel)
	ON_CBN_SELCHANGE(IDC_ALIGN, OnChangeAlign)
	ON_CBN_SELCHANGE(IDC_VIEWMODE, OnChangeView)
	ON_BN_CLICKED(IDC_HOVER, OnHover)
	ON_BN_CLICKED(IDC_MYHOTCUR, OnMyHotCur)
	ON_CBN_SELCHANGE(IDC_SORT, OnChangeSort)
	ON_BN_CLICKED(IDC_WORKAREAS, OnWorkAreas)
	ON_BN_CLICKED(IDC_STDHOTCUR, OnStdHotCur)
	ON_BN_CLICKED(IDABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListHdrDlg message handlers

BOOL CListHdrDlg::OnInitDialog()
{
	CListHdrApp     *pApp;
	CRect           rect;

	CDialog::OnInitDialog();  // let the base class do the default work
	UpdateData(TRUE);  // bring the information from the dialog.
	pApp = (CListHdrApp *)AfxGetApp();
	srand((unsigned) time(NULL));  // start the random number generator

	// create image list for header items
	m_pImageHdrSmall = new CImageList();
	ASSERT(m_pImageHdrSmall != NULL);    // serious allocation failure checking
	m_pImageHdrSmall->Create(16, 16, ILC_MASK, 2, 2);
	m_pImageHdrSmall->Add(pApp->LoadIcon(IDI_HDRICON1));
	m_pImageHdrSmall->Add(pApp->LoadIcon(IDI_HDRICON2));

	// fill in image lists
	m_pImageList = new CImageList();
	m_pImageListSmall = new CImageList();
	ASSERT(m_pImageList != NULL && m_pImageListSmall != NULL);    // serious allocation failure checking
	m_pImageList->Create(32, 32, TRUE,  4, 4);
	m_pImageListSmall->Create(16, 16, TRUE, 4, 4);
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST2));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST3));
	m_pImageList->Add(pApp->LoadIcon(IDI_ICONLIST4));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST2));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST3));
	m_pImageListSmall->Add(pApp->LoadIcon(IDI_ICONLIST4));

	// initialize the standard and custom hot cursors
	m_hMyHotCursor= pApp->LoadCursor(IDC_SPYGLASS);
	m_hStdHotCursor= m_listctrl.GetHotCursor();

	FillListCtrl();

	// Enable/disable inter-dependent list control styles
	((CButton*)GetDlgItem(IDC_STDHOTCUR))->SetCheck(m_bHotCursor);
	GetDlgItem(IDC_STDHOTCUR)->EnableWindow(m_bHoverSelect);
	GetDlgItem(IDC_MYHOTCUR)->EnableWindow(m_bHoverSelect);
	GetDlgItem(IDC_WORKAREAS)->EnableWindow(FALSE);
	GetDlgItem(IDC_ALIGN)->EnableWindow(FALSE);  // default is  report mode Does not support this
	GetDlgItem(IDC_AUTOARRANGE)->EnableWindow(FALSE);

	return FALSE;  // there is no change in any control focus stuff here.
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CListHdrDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CListHdrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListHdrDlg::FillListCtrl()
{
	CRect           rect;
	int             iIcon, iItem, iSubItem, iActualItem;
	LV_ITEM         lvitem;
	CString         strItem1= _T("ITEM");
	CString         strItem2= _T("SUB_ITEM");
	CString         strIconDesc[4], strIconShortDesc[4];
	LPTSTR          pStrTemp1, pStrTemp2;
	CListHdrApp     *pApp;
	
	iIcon = iItem = iSubItem = iActualItem = 0;

	strIconDesc[0]= _T("Blue Ellipse, Yellow Triangle, Red Rectangle");
	strIconDesc[1]= _T("Yellow Ellipse, Red Triangle, Blue Rectangle");
	strIconDesc[2]= _T("Red Ellipse, Blue Triangle, Yellow Rectangle");
	strIconDesc[3]= _T("Red Ellipse, Yellow Triangle, Blue Rectangle");
	strIconShortDesc[0]= _T("BE, YT, RR (Title)");
	strIconShortDesc[1]= _T("YE, RT, BR (Title)");
	strIconShortDesc[2]= _T("RE, BT, YR (Title)");
	strIconShortDesc[3]= _T("RE, YT, BR (Title)");


	pApp = (CListHdrApp *)AfxGetApp();
	m_listctrl.SetImageList(m_pImageList, LVSIL_NORMAL);
	m_listctrl.SetImageList(m_pImageListSmall, LVSIL_SMALL);

	// insert two columns (REPORT mode) and modify the new header items
	m_listctrl.GetWindowRect(&rect);
	m_listctrl.InsertColumn(0, strItem1, LVCFMT_LEFT,
		rect.Width() * 1/3, 0);
	m_listctrl.InsertColumn(1, strItem2, LVCFMT_LEFT,
		rect.Width() * 2/3, 1);
	ModifyHeaderItems();

	for (iItem = 0; iItem < 20; iItem++)  // insert the items and subitems into the list view.
		for (iSubItem = 0; iSubItem < 2; iSubItem++)
		{
			if (iSubItem == 0) {
				iIcon = rand() % 4;  // choose the icon and legend for the entry
			}

			lvitem.mask = LVIF_TEXT | (iSubItem == 0? LVIF_IMAGE : 0);
			lvitem.iItem = (iSubItem == 0)? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;

			// calculate the main and sub-item strings for the current item
			pStrTemp1= strIconShortDesc[iIcon].GetBuffer(strIconShortDesc[iIcon].GetLength());
			pStrTemp2= strIconDesc[iIcon].GetBuffer(strIconDesc[iIcon].GetLength());
			lvitem.pszText = iSubItem == 0? pStrTemp1 : pStrTemp2;

			lvitem.iImage = iIcon;
			if (iSubItem == 0)
				iActualItem = m_listctrl.InsertItem(&lvitem); // insert new item
			else
				m_listctrl.SetItem(&lvitem); // modify existing item (the sub-item text)
		}
}

void CListHdrDlg::ModifyHeaderItems()
{
	HD_ITEM curItem;

	// retrieve embedded header control
	CHeaderCtrl* pHdrCtrl= NULL;
	pHdrCtrl= m_listctrl.GetHeaderCtrl();

	pHdrCtrl->SetImageList(m_pImageHdrSmall);
	// add bmaps to each header item
	memset(&curItem, 0, sizeof(curItem));
	pHdrCtrl->GetItem(0, &curItem);
	curItem.mask= HDI_IMAGE | HDI_FORMAT;
	curItem.iImage= 0;
	curItem.fmt= HDF_LEFT | HDF_IMAGE | HDF_STRING;
	pHdrCtrl->SetItem(0, &curItem);

	pHdrCtrl->GetItem(1, &curItem);
	curItem.mask= HDI_IMAGE | HDI_FORMAT;
	curItem.iImage= 1;
	curItem.fmt= HDF_LEFT | HDF_IMAGE | HDF_STRING;
	pHdrCtrl->SetItem(1, &curItem);
}

// this function is used when a requested style
// LVS_NOLABELWRAP, LVS_NOCOLUMNHEADER, and LVS_NOSORTHEADER
// forces the current control to be re-created with the new style.
void CListHdrDlg::RenewListCtrl(DWORD dwStyle, BOOL bSetBits)
{
	DWORD   dwStyleOld, dwExtStyles;
	CRect   rect;

	dwStyleOld = GetWindowLong(m_listctrl.m_hWnd, GWL_STYLE);
	if (bSetBits)
		dwStyleOld |= dwStyle;   // turn on bits specified by caller.
	else
		dwStyleOld &= ~dwStyle;  // turn off bits specified by caller.

	m_listctrl.GetWindowRect(&rect);
	ScreenToClient(&rect);
	dwExtStyles= m_listctrl.GetExtendedStyle(); //save extended styles
	m_listctrl.DestroyWindow();
	m_listctrl.Create(dwStyleOld, rect, this, IDC_LISTVIEW1);
	m_listctrl.ModifyStyleEx(0,WS_EX_CLIENTEDGE); // renew the 3D border of the control
	m_listctrl.SetExtendedStyle(dwExtStyles);

	FillListCtrl(); // repopulate with a new item group

	// work areas are not carried over with the new control
	m_listctrl.SetWorkAreas(0, NULL);
	m_bWorkAreas= FALSE;
	UpdateData(FALSE);  // update the dialog

}

// this function is used when a requested style
// can be applied to the existing control, and demonstrated.
void CListHdrDlg::ChangeListCtrlStyle(DWORD dwStyle, BOOL bSetBits)
{
	CRect   rect;

	m_listctrl.GetWindowRect(&rect);
	ScreenToClient(&rect);
	ASSERT(dwStyle != 0);  // watch out for LVS_foo DEFINITIONS which are 0.
	if (bSetBits)
		m_listctrl.ModifyStyle(0, dwStyle);
	else
		m_listctrl.ModifyStyle(dwStyle, 0);

	InvalidateRect(rect);
	UpdateData(FALSE);  // send information back to the dialog
}

void CListHdrDlg::OnAutoArrange()
{
	UpdateData(TRUE);  // get the information from the dialog
	ChangeListCtrlStyle(LVS_AUTOARRANGE, m_bAutoArrange);
}

void CListHdrDlg::OnEditLabels()
{
	UpdateData(TRUE);
	ChangeListCtrlStyle(LVS_EDITLABELS, m_bEditLabels);
}

void CListHdrDlg::OnNoColHdr()
{
	UpdateData(TRUE);
	RenewListCtrl(LVS_NOCOLUMNHEADER, m_bNoColHdr);
}

void CListHdrDlg::OnNoSortHdr()
{
	UpdateData(TRUE);
	RenewListCtrl(LVS_NOSORTHEADER, m_bNoSortHdr);
}

void CListHdrDlg::OnSingleSel()
{
	UpdateData(TRUE);
	ChangeListCtrlStyle(LVS_SINGLESEL, m_bSingleSel);
}

void CListHdrDlg::OnNoLabelWrap()
{
	UpdateData(TRUE);
	RenewListCtrl(LVS_NOLABELWRAP, m_bNoLabelWrap);
}

void CListHdrDlg::OnChangeView()
{

	long        lStyle, lStyleOld;
	BOOL        bReport, bIconic;

	// retrieve view mode selection
	UpdateData(TRUE);
	if (m_strViewMode == _T("ICON"))
		lStyle = LVS_ICON;
	else if (m_strViewMode == _T("SMALL ICON"))
		lStyle = LVS_SMALLICON;
	else if (m_strViewMode == _T("REPORT"))
		lStyle = LVS_REPORT;
	else
	{
		ASSERT(m_strViewMode == _T("LIST"));
		lStyle = LVS_LIST;
	}

	// update interdependent styles, depending on view mode choice
	bReport = lStyle == LVS_REPORT;
	bIconic = lStyle == LVS_ICON || lStyle == LVS_SMALLICON;
	GetDlgItem(IDC_NOSORTHEADER)->EnableWindow(bReport);
	GetDlgItem(IDC_NOCOLUMNHEADER)->EnableWindow(bReport);
	GetDlgItem(IDC_WORKAREAS)->EnableWindow(bIconic);
	GetDlgItem(IDC_ALIGN)->EnableWindow(bIconic);
	GetDlgItem(IDC_AUTOARRANGE)->EnableWindow(bIconic);

	lStyleOld = GetWindowLong(m_listctrl.m_hWnd, GWL_STYLE);
	lStyleOld &= ~(LVS_TYPEMASK);  // turn off all the style (view mode) bits
	lStyleOld |= lStyle;        // Set the new style for the control
	SetWindowLong(m_listctrl.m_hWnd, GWL_STYLE, lStyleOld);

	//In order to change the alignment, the control must be re-created.
	//However, changing the view mode of a list control does not force a re-creation.
	//Therefore, if the list view is in iconic mode, the control must be re-created
	//to carry over the current alignment mode.
	if(bIconic) //need to keep alignment also
		RenewListCtrl(0, 0);
}

void CListHdrDlg::OnChangeAlign()
{
	// this function takes into consideration that LVS_ALIGNTOP is defined as zero.
	UpdateData(TRUE);
	ASSERT(m_strAlignMode == _T("ALIGNTOP") || m_strAlignMode == _T("ALIGNLEFT"));
	RenewListCtrl(LVS_ALIGNLEFT, (m_strAlignMode == _T("ALIGNLEFT")));
}

void CListHdrDlg::OnHover()
{
	UpdateData(TRUE);

	if(m_bHoverSelect) // "hover selection" is enabled
	{
	// LVS_EX_ONECLICKACTIVATE (or LVS_EX_TWOCLICKACTIVATE must also be
	// set before  "hover selection" is enabled
		m_listctrl.SetExtendedStyle(LVS_EX_TRACKSELECT |
			LVS_EX_ONECLICKACTIVATE);
		GetDlgItem(IDC_STDHOTCUR)->EnableWindow(m_bHoverSelect);
		GetDlgItem(IDC_MYHOTCUR)->EnableWindow(m_bHoverSelect);
	}
	else // "hover selection" is disabled
	{
		m_listctrl.SetExtendedStyle(0);
		GetDlgItem(IDC_STDHOTCUR)->EnableWindow(m_bHoverSelect);
		GetDlgItem(IDC_MYHOTCUR)->EnableWindow(m_bHoverSelect);
	}
}

void CListHdrDlg::OnMyHotCur()
{
	m_listctrl.SetHotCursor(m_hMyHotCursor);
	m_bHotCursor= FALSE;
}

void CListHdrDlg::OnChangeSort()
{
	long    lStyle;

	UpdateData(TRUE);
	lStyle = GetWindowLong(m_listctrl.m_hWnd, GWL_STYLE);
	lStyle &= ~(LVS_SORTASCENDING | LVS_SORTDESCENDING);
	SetWindowLong(m_listctrl.m_hWnd, GWL_STYLE, lStyle);  // set style without sorting
	if (m_strSortMode == _T("None"))
		RenewListCtrl(LVS_SORTASCENDING | LVS_SORTDESCENDING, FALSE);
	else if (m_strSortMode == _T("ASCENDING"))
		RenewListCtrl(LVS_SORTASCENDING, TRUE);
	else
	{
		ASSERT(m_strSortMode == _T("DESCENDING"));
		RenewListCtrl(LVS_SORTDESCENDING, TRUE);
	}
}

void CListHdrDlg::OnWorkAreas()
{
	UpdateData(TRUE);

	if(m_bWorkAreas)
	{
		CRect curRect;
		CSize size;

		size= m_listctrl.ApproximateViewRect();
		size.cx+= 100;
		size.cy+= 100;

/*      Work area layout
		_____________________
		|          |         |
		|          |         |
		|   0      |    1    |
		|          |         |
		|--------------------|
		|          |         |
		|   2      |    3    |
		|          |         |
		|__________|_________|*/

		CRect rcWorkAreas[4];

		rcWorkAreas[0].SetRect(0, 0, (size.cx / 2) - 5, (size.cy / 2) - 5);
		rcWorkAreas[1].SetRect((size.cx / 2) + 5, 0, size.cx, (size.cy / 2) - 5);
		rcWorkAreas[2].SetRect(0, (size.cy / 2) + 5, (size.cx / 2) - 5, size.cy);
		rcWorkAreas[3].SetRect((size.cx / 2) + 5, (size.cy / 2) + 5, size.cx, size.cy);

		//set work areas
		m_listctrl.SetWorkAreas(4, rcWorkAreas);

		// set insertion points for each work area
		CPoint  rgptWork[4];
		int i;
		for (i = 0; i < 4; i++)
		{
			rgptWork[i].x = rcWorkAreas[i].left + 10;
			rgptWork[i].y = rcWorkAreas[i].top + 10;
		}
		// now move all the items to the different quadrants
		for (i = 0; i < 20; i++)
			m_listctrl.SetItemPosition(i, rgptWork[i % 4]);
	}
	else    //delete all work areas and re-organize items
	{
		m_listctrl.SetWorkAreas(0, NULL);

		CPoint pt(0, 0);
		for (int i = 0; i < 20; i++)
			m_listctrl.SetItemPosition(i, pt);  // move all the items to the origin
	}
	m_listctrl.Arrange(LVA_DEFAULT); // force the control to re-arrange the shuffled items
}

void CListHdrDlg::OnStdHotCur()
{
	m_listctrl.SetHotCursor(m_hStdHotCursor);
	m_bHotCursor= TRUE;
}

void CListHdrDlg::OnAbout()
{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
}
