// ChildDialog.cpp : implementation file
//

#include "stdafx.h"
#include "UIAnimationTest.h"
#include "ChildDialog.h"
#include "afxdialogex.h"


// CChildDialog dialog

IMPLEMENT_DYNAMIC(CChildDialog, CDialogEx)

CChildDialog::CChildDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChildDialog::IDD, pParent)
{

}

CChildDialog::~CChildDialog()
{
}

void CChildDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO1, m_wndCombo);
    DDX_Control(pDX, IDC_SLIDER1, m_wndSlider);
    DDX_Control(pDX, IDC_PROGRESS1, m_wndProgress);
}


BEGIN_MESSAGE_MAP(CChildDialog, CDialogEx)
    ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CChildDialog message handlers


void CChildDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    if (((CSliderCtrl*)pScrollBar) == &m_wndSlider)
    {
        m_wndProgress.SetPos(m_wndSlider.GetPos());
    }

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CChildDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_wndCombo.SetCurSel(0);

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}
