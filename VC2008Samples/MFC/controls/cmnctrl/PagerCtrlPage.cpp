// PagerCtrlPage.cpp : implementation file
//

#include "stdafx.h"

#include "CmnCtrl3.h"
#include "PagerCtrlPage.h"

static const struct
{
	COLORREF      color;
	LPCTSTR lpszDisplay;
} colors[] = 
{
	{RGB(127,127,127),	_T("Gray")},
	{RGB(255,255,255),	_T("White")},
	{RGB(0,0,0),	_T("Black")},
};

// CPagerCtrlPage dialog

IMPLEMENT_DYNAMIC(CPagerCtrlPage, CPropertyPage)

CPagerCtrlPage::CPagerCtrlPage()
	: CPropertyPage(CPagerCtrlPage::IDD)
{
}

CPagerCtrlPage::~CPagerCtrlPage()
{
}

void CPagerCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BUTTON_SIZE, m_nSize);
	DDX_Control(pDX, IDC_SLIDER_BORDER, m_sliderBorderSize);
	DDX_Control(pDX, IDC_STATIC_BORDERSIZE, m_staticBorderSize);
	DDX_Control(pDX, IDC_BACK_COLOR, m_comboColor);
}

BOOL CPagerCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Init the pager control and the embedded toolbar control
	CRect clientRect;
	this->GetClientRect(&clientRect);
	BOOL nRet;
	nRet = m_pagerctrl.Create(WS_VISIBLE | WS_CHILD | PGS_HORZ,
					CRect(32, 32, clientRect.right - 32, 102),
					this,
					IDC_PAGER_CTRL);

	m_toolbar.CreateEx(&m_pagerctrl);
	m_toolbar.LoadToolBar(IDR_TOOLBAR1);

	m_pagerctrl.SetChild(m_toolbar.m_hWnd);
	
	// Init the controls that display/set the border size
	m_sliderBorderSize.SetRange(0, 32);
	int nBorderSize = m_pagerctrl.GetBorder();
	m_sliderBorderSize.SetPos(nBorderSize);
	
	CString strSize;
	strSize.Format(_T("%d"), nBorderSize);
	m_staticBorderSize.SetWindowText(strSize);

	// Init the controls that display/set the button size
	m_pagerctrl.SetButtonSize(32);
	m_nSize = m_pagerctrl.GetButtonSize();

	// Init the control that display/set the color
	for (int i = 0; i < _countof(colors); i++)
		m_comboColor.AddString(colors[i].lpszDisplay);
	m_comboColor.SetCurSel(0);
	m_pagerctrl.SetBkColor(colors[0].color);

	UpdateData(FALSE);
	return TRUE;
}

BEGIN_MESSAGE_MAP(CPagerCtrlPage, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_BACK_COLOR, &CPagerCtrlPage::OnCbnSelchangeBackColor)
	ON_BN_CLICKED(IDC_SET_BUTTON_SIZE, &CPagerCtrlPage::OnBnClickedSetButtonSize)
	ON_NOTIFY(PGN_CALCSIZE, IDC_PAGER_CTRL, OnCalcSize)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

void CPagerCtrlPage::OnCbnSelchangeBackColor()
{
	m_pagerctrl.SetBkColor(colors[m_comboColor.GetCurSel()].color);
}

void CPagerCtrlPage::OnBnClickedSetButtonSize()
{
	UpdateData(TRUE);
	m_pagerctrl.SetButtonSize(m_nSize);
}

void CPagerCtrlPage::OnCalcSize(NMHDR * pNotifyStruct, LRESULT * result)
{
	LPNMPGCALCSIZE pNMPGCALCSIZE = (LPNMPGCALCSIZE)pNotifyStruct;

	if (pNMPGCALCSIZE->dwFlag == PGF_CALCWIDTH)
	{
		SIZE size;
		m_toolbar.SendMessage(TB_GETMAXSIZE, 0, (LPARAM)&size);
		pNMPGCALCSIZE->iWidth = size.cx;
	}
}

void CPagerCtrlPage::OnHScroll(UINT /*nSBCode*/, UINT /*nPos*/, CScrollBar* /*pScrollBar*/)
{
	int nBorderSize = m_sliderBorderSize.GetPos();
	CString strSize;
	strSize.Format(_T("%d"), nBorderSize);
	m_staticBorderSize.SetWindowText(strSize);

	m_pagerctrl.SetBorder(nBorderSize);
}
