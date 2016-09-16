// CommandLinkCtrlPage.cpp : implementation file
//

#include "stdafx.h"
#include "CmnCtrl3.h"
#include "CommandLinkCtrlPage.h"


// CCommandLinkCtrlPage dialog

IMPLEMENT_DYNAMIC(CCommandLinkCtrlPage, CPropertyPage)

CCommandLinkCtrlPage::CCommandLinkCtrlPage()
	: CPropertyPage(CCommandLinkCtrlPage::IDD)
{
}

CCommandLinkCtrlPage::~CCommandLinkCtrlPage()
{
}

void CCommandLinkCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NOTE, m_editNote);
	DDX_Control(pDX, IDC_CHECK_ELEV, m_checkShowElev);
	DDX_Control(pDX, IDC_COMMAND, m_cmdbtn);
}

BOOL CCommandLinkCtrlPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// Init UI
	LPCTSTR szInitialNote = _T("and the note goes here ...");
	m_editNote.SetWindowText(szInitialNote);
	OnBnClickedSetButtonNote();

	return TRUE;
}


BEGIN_MESSAGE_MAP(CCommandLinkCtrlPage, CPropertyPage)
	ON_BN_CLICKED(IDC_SET_BUTTON_NOTE, &CCommandLinkCtrlPage::OnBnClickedSetButtonNote)
	ON_BN_CLICKED(IDC_CHECK_ELEV, &CCommandLinkCtrlPage::OnBnClickedCheckElev)
END_MESSAGE_MAP()

void CCommandLinkCtrlPage::OnBnClickedSetButtonNote()
{
	CString note;
	m_editNote.GetWindowText(note);
	m_cmdbtn.SetNote(note);
}

void CCommandLinkCtrlPage::OnBnClickedCheckElev()
{
	m_cmdbtn.SetShield(m_checkShowElev.GetCheck() == BST_CHECKED);
}
