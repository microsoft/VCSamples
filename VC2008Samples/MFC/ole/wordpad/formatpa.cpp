// formatpa.cpp : implementation file
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
#include "wordpad.h"
#include "formatpa.h"
#include "ddxm.h"
#include "helpids.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

const DWORD CFormatParaDlg::m_nHelpIDs[] =
{
	IDC_EDIT_LEFT, IDH_WORDPAD_INDENT_LEFT,
	IDC_EDIT_RIGHT, IDH_WORDPAD_INDENT_RIGHT,
	IDC_EDIT_FIRST_LINE, IDH_WORDPAD_INDENT_FIRST,
	IDC_BOX, IDH_COMM_GROUPBOX,
	IDC_COMBO_ALIGNMENT, IDH_WORDPAD_ALIGN,
	IDC_TEXT_ALIGNMENT, IDH_WORDPAD_ALIGN,
	IDC_EDIT_BEFORE, IDH_WORDPAD_SPACE_BEFORE,
	IDC_EDIT_AFTER, IDH_WORDPAD_SPACE_AFTER,
	IDC_CHECK_PAGEBREAK, IDH_WORDPAD_PAGEBREAK,
	0, 0
};

/////////////////////////////////////////////////////////////////////////////
// CFormatParaDlg dialog

static CString FormatAsPoints(int nPoints)
{
	CString str;
	str.Format(_T("%d pt"), nPoints);
	return str;
}

CFormatParaDlg::CFormatParaDlg(PARAFORMAT2& pf, CWnd* pParent /*=NULL*/)
	: CCSDialog(CFormatParaDlg::IDD, pParent)
{
	m_pf = pf;
	if (m_pf.dwMask & PFM_ALIGNMENT)
	{
		if (m_pf.wAlignment & PFA_LEFT && m_pf.wAlignment & PFA_RIGHT)
			m_nAlignment = 2;
		else
			m_nAlignment = (m_pf.wAlignment & PFA_LEFT) ? 0 : 1;
	}
	else
		m_nAlignment = -1;

	m_nAfter = m_pf.dySpaceAfter;
	m_nBefore = m_pf.dySpaceBefore;

	//{{AFX_DATA_INIT(CFormatParaDlg)
	m_nFirst = 0;
	m_nLeft = 0;
	m_nRight = 0;
	m_bPageBreak = FALSE;
	//}}AFX_DATA_INIT
}

void CFormatParaDlg::DoDataExchange(CDataExchange* pDX)
{
	CCSDialog::DoDataExchange(pDX);

	// semi-custom formatting for "pt" in the value for
	// before- and after-paragraph spacing

	CString strBefore;
	CString strAfter;

	if (pDX->m_bSaveAndValidate)
	{
		GetDlgItemText(IDC_EDIT_BEFORE, strBefore);
		m_nBefore = _ttoi(strBefore);

		GetDlgItemText(IDC_EDIT_AFTER, strAfter);
		m_nAfter = _ttoi(strAfter);
	}

	strBefore = FormatAsPoints(m_nBefore);
	strAfter = FormatAsPoints(m_nAfter);

	DDX_Text(pDX, IDC_EDIT_AFTER, strAfter);
	DDX_Text(pDX, IDC_EDIT_BEFORE, strBefore);

	//{{AFX_DATA_MAP(CFormatParaDlg)
	DDX_CBIndex(pDX, IDC_COMBO_ALIGNMENT, m_nAlignment);
	DDX_Twips(pDX, IDC_EDIT_FIRST_LINE, m_nFirst);
	DDV_MinMaxTwips(pDX, m_nFirst, -31680, 31680);
	DDX_Twips(pDX, IDC_EDIT_LEFT, m_nLeft);
	DDV_MinMaxTwips(pDX, m_nLeft, -31680, 31680);
	DDX_Twips(pDX, IDC_EDIT_RIGHT, m_nRight);
	DDV_MinMaxTwips(pDX, m_nRight, -31680, 31680);
	DDX_Check(pDX, IDC_CHECK_PAGEBREAK, m_bPageBreak);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFormatParaDlg, CCSDialog)
	//{{AFX_MSG_MAP(CFormatParaDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BEFORE, OnDeltaposSpinBefore)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_AFTER, OnDeltaposSpinAfter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFormatParaDlg message handlers

void CFormatParaDlg::OnOK()
{
	CCSDialog::OnOK();
	m_pf.dwMask = 0;
	if (m_nAlignment >= 0)
	{
		ASSERT(m_nAlignment < 3);
		m_pf.dwMask |= PFM_ALIGNMENT;
		m_pf.wAlignment = (WORD)((m_nAlignment == 0) ? PFA_LEFT :
			(m_nAlignment == 1) ? PFA_RIGHT : PFA_CENTER);
	}
	if (m_nRight != DDXM_BLANK)
		m_pf.dwMask |= PFM_RIGHTINDENT;
	if (m_nLeft != DDXM_BLANK && m_nFirst != DDXM_BLANK)
		m_pf.dwMask |= PFM_STARTINDENT;
	if (m_nFirst != DDXM_BLANK)
		m_pf.dwMask |= PFM_OFFSET;

	if (m_bPageBreak)
	{
		m_pf.dwMask |= PFM_PAGEBREAKBEFORE;
		m_pf.wEffects |= PFE_PAGEBREAKBEFORE;
	}

	m_pf.dxRightIndent = m_nRight;
	m_pf.dxOffset = -m_nFirst;
	m_pf.dxStartIndent = m_nLeft + m_nFirst;

	m_pf.dwMask |= PFM_SPACEAFTER | PFM_SPACEBEFORE;
	m_pf.dySpaceBefore = m_nBefore * 20;
	m_pf.dySpaceAfter = m_nAfter * 20;
}

BOOL CFormatParaDlg::OnInitDialog()
{
	CComboBox* pBox = (CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT);
	CString str;
	str.LoadString(IDS_LEFT);
	pBox->AddString(str);
	str.LoadString(IDS_RIGHT);
	pBox->AddString(str);
	str.LoadString(IDS_CENTER);
	pBox->AddString(str);

	if (m_nWordWrap == 0)
	{
		GetDlgItem(IDC_COMBO_ALIGNMENT)->EnableWindow(FALSE);
		GetDlgItem(IDC_TEXT_ALIGNMENT)->EnableWindow(FALSE);
	}

	m_bPageBreak = (m_pf.dwMask & PFM_PAGEBREAKBEFORE) &&
				   (m_pf.wEffects & PFE_PAGEBREAKBEFORE);

	m_nRight = (m_pf.dwMask & PFM_RIGHTINDENT) ? m_pf.dxRightIndent : DDXM_BLANK;
	if (m_pf.dwMask & PFM_OFFSET)
	{
		m_nFirst = -m_pf.dxOffset;
		m_nLeft = (m_pf.dwMask & PFM_STARTINDENT) ?
			m_pf.dxStartIndent + m_pf.dxOffset : DDXM_BLANK;
	}
	else
		m_nLeft = m_nFirst = DDXM_BLANK;

	if (m_pf.dwMask & PFM_SPACEBEFORE)
		m_nBefore = m_pf.dySpaceBefore / 20;
	if (m_pf.dwMask & PFM_SPACEAFTER)
		m_nAfter = m_pf.dySpaceAfter / 20;

	CCSDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CFormatParaDlg::OnDeltaposSpinBefore(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	m_nBefore = pNMUpDown->iPos;
	*pResult = 0;
	UpdateData(FALSE);
}

void CFormatParaDlg::OnDeltaposSpinAfter(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	m_nAfter = pNMUpDown->iPos;
	*pResult = 0;
	UpdateData(FALSE);
}

