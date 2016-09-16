// SplitButtonCtrlPage.cpp : implementation file
//

#include "stdafx.h"

#include "CmnCtrl3.h"
#include "SplitButtonCtrlPage.h"

static const struct
{
	UINT    nStyle;
	LPCTSTR lpszDisplay;
} styles[] = 
{
	{BCSS_NOSPLIT,		_T("BCSS_NOSPLIT")},
	{BCSS_STRETCH,		_T("BCSS_STRETCH")},
	{BCSS_ALIGNLEFT,	_T("BCSS_ALIGNLEFT")},
	{BCSS_IMAGE,		_T("BCSS_IMAGE")},
};

// CSplitButton dialog

IMPLEMENT_DYNAMIC(CSplitButtonCtrlPage, CPropertyPage)

CSplitButtonCtrlPage::CSplitButtonCtrlPage()
	: CPropertyPage(CSplitButtonCtrlPage::IDD)
{
}

CSplitButtonCtrlPage::~CSplitButtonCtrlPage()
{
}

void CSplitButtonCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPLIT_BUTTON, m_splitButton);
	DDX_Text(pDX, IDC_X_SIZE, m_xSize);
	DDX_Text(pDX, IDC_Y_SIZE, m_ySize);
	DDX_Control(pDX, IDC_LIST_STYLE, m_listSplitStyle);
	DDX_Control(pDX, IDC_CHECK_STATE, m_checkState);
}

BOOL CSplitButtonCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Init UI
	m_image.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));
	OnBnClickedSetMenu1();

	SIZE size;
	BOOL ret = m_splitButton.GetSplitSize(&size);
	m_xSize = size.cx;
	m_ySize = size.cy;
	UpdateData(FALSE);

	// Fill in all the Split Button styles
	for (int i = 0; i < _countof(styles); i++)
		m_listSplitStyle.AddString(styles[i].lpszDisplay);

	m_splitButton.SetSplitStyle(styles[1].nStyle);	// BCSS_STRETCH
	m_listSplitStyle.SetSel(1);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CSplitButtonCtrlPage, CPropertyPage)
	ON_BN_CLICKED(IDC_SET_MENU1, &CSplitButtonCtrlPage::OnBnClickedSetMenu1)
	ON_BN_CLICKED(IDC_SET_MENU2, &CSplitButtonCtrlPage::OnBnClickedSetMenu2)
	ON_BN_CLICKED(IDC_SET_SIZE, &CSplitButtonCtrlPage::OnBnClickedSetSize)
	ON_LBN_SELCHANGE(IDC_LIST_STYLE, &CSplitButtonCtrlPage::OnLbnSelchangeListStyle)
	ON_BN_CLICKED(IDC_SPLIT_BUTTON, &CSplitButtonCtrlPage::OnBnClickedSplitButton)
	ON_BN_CLICKED(IDC_CHECK_STATE, &CSplitButtonCtrlPage::OnBnClickedCheckState)
END_MESSAGE_MAP()

// CSplitButton message handlers

void CSplitButtonCtrlPage::OnBnClickedSetMenu1()
{
	m_splitButton.SetDropDownMenu(IDR_SPLIT_DROPDOWN_MENU, 0);
	m_splitButton.SetWindowText(_T("using MENU 1"));
}

void CSplitButtonCtrlPage::OnBnClickedSetMenu2()
{
	m_splitButton.SetDropDownMenu(IDR_SPLIT_DROPDOWN_MENU, 1);
	m_splitButton.SetWindowText(_T("using MENU 2"));
}

void CSplitButtonCtrlPage::OnBnClickedSetSize()
{
	UpdateData(TRUE);

	SIZE size;
	size.cx = m_xSize;
	size.cy = m_ySize;
	m_splitButton.SetSplitSize(&size);
	m_splitButton.RedrawWindow();

	m_splitButton.GetSplitSize(&size);
	m_xSize = size.cx;
	m_ySize = size.cy;

	UpdateData(FALSE);
}

void CSplitButtonCtrlPage::OnLbnSelchangeListStyle()
{
	// Get selected styles
	int nCount = m_listSplitStyle.GetSelCount();
	int *selectedItems = new int[nCount];
	m_listSplitStyle.GetSelItems(nCount, selectedItems);

	UINT nStyle = 0;
	for (int i = 0; i < nCount; i++)
		nStyle |= styles[selectedItems[i]].nStyle;

	delete[] selectedItems;

	// Some UI adjustments
	if (nStyle & BCSS_NOSPLIT)
		m_splitButton.SetSplitImageList(NULL);
	else if (nStyle & BCSS_IMAGE)
		m_splitButton.SetSplitImageList(&m_image);
	else
		m_splitButton.SetSplitGlyph('6');			// The default glyph

	m_splitButton.SetSplitStyle(nStyle);
	m_splitButton.RedrawWindow();

	// The split size could be reset
	SIZE size;
	m_splitButton.GetSplitSize(&size);
	m_xSize = size.cx;
	m_ySize = size.cy;
	UpdateData(FALSE);
}

void CSplitButtonCtrlPage::OnBnClickedSplitButton()
{
	CString text;
	m_splitButton.GetWindowText(text);
	::MessageBox(m_hWnd, CString(_T("You are ")) + text, _T("Thank you"), 0);
}

void CSplitButtonCtrlPage::OnBnClickedCheckState()
{
	m_splitButton.SetDropDownState(m_checkState.GetCheck() == BST_CHECKED);
}
