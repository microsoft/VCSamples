// EditDlg.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "DBViewer.h"
#include "ctrlext.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDlg

CEditDlg::CEditDlg() : CDialog(CEditDlg::IDD)
{
	m_pListCtrl = NULL;
	m_nItem = 0;
	m_nFields = 0;
	m_nCurSel = 0;
}

CEditDlg::CEditDlg(CListCtrlEx* pCtrl, int nItem, int nFields)
	: CDialog(CEditDlg::IDD)
{
	//{{AFX_DATA_INIT(CEditDlg)
	m_strEdit = _T("");
	//}}AFX_DATA_INIT
	m_pListCtrl = pCtrl;
	m_nItem = nItem;
	m_nFields = nFields;
	m_nCurSel = 0;
	m_bMode = FALSE;
}

CEditDlg::CEditDlg(CMapStringToString& mapData)
	: CDialog(CEditDlg::IDD)
{
	m_pListCtrl = NULL;
	m_nCurSel = 0;
	m_bMode = TRUE;

	POSITION pos = mapData.GetStartPosition();
	while(pos != NULL)
	{
		CString strKey, strValue;
		mapData.GetNextAssoc(pos, strKey, strValue);
		m_mapField.SetAt(strKey, strValue);
	}

	m_nFields = (int)m_mapField.GetCount();
}

CEditDlg::~CEditDlg()
{
	m_pListCtrl = NULL;
	m_nItem = 0;
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnFieldChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers


BOOL CEditDlg::OnInitDialog()
{
	LV_COLUMN   lvCol;
	LV_ITEM     lvItem;
	TCHAR       szColName[40];
	TCHAR       szItem[40];

	CDialog::OnInitDialog();

	// If using procedures, don't get data from list view
	if (m_bMode)
	{
		// We were created with a map
		POSITION pos = m_mapField.GetStartPosition();
		while(pos != NULL)
		{
			CString strKey, strValue;
			m_mapField.GetNextAssoc(pos, strKey, strValue);
			m_ctlListBox.AddString(strKey);
		}

		return TRUE;
	}

	// Populate List Control and Map
	ASSERT(m_pListCtrl);
	ASSERT(m_nItem != -1);

	lvCol.mask          = LVCF_TEXT;
	lvCol.pszText       = &szColName[0];
	lvCol.cchTextMax    = 40;

	lvItem.mask         = LVIF_TEXT;
	lvItem.iItem        = m_nItem;
	lvItem.pszText      = &szItem[0];
	lvItem.cchTextMax   = 40;

	for (int i=0; i<m_nFields; i++)
	{
		lvItem.iSubItem = i;

		m_pListCtrl->GetColumn(i, &lvCol);
		m_pListCtrl->GetItem(&lvItem);

		CString strKey = lvCol.pszText;
		CString strValue = lvItem.pszText;

//      if (m_nItem==0)
//          strValue = _T("");

		m_mapField.SetAt(strKey, strValue);
		m_ctlListBox.AddString(strKey);

		if (i==0)
			m_ctlEdit.SetWindowText(strValue);
	}

	m_ctlListBox.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CEditDlg)
	DDX_Control(pDX, IDC_EDIT2, m_ctlEdit);
	DDX_Control(pDX, IDC_LIST1, m_ctlListBox);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit);
	DDV_MaxChars(pDX, m_strEdit, 39);
	//}}AFX_DATA_MAP
}

void CEditDlg::OnFieldChange()
{
	// This gets called whenever the user changes the selection
	// Place the data in the map.
	CString strField, strValue, strValueOld;

	// Update the contents of the previous selection, necessary.
	m_ctlListBox.GetText(m_nCurSel, strField);
	m_ctlEdit.GetWindowText(strValue);
	m_mapField.Lookup(strField, strValueOld);

	if (strValueOld != strValue)
		m_mapField.SetAt(strField, strValue);

	// Load in the contents of the new key.
	m_nCurSel = m_ctlListBox.GetCurSel();

	if (m_nCurSel == -1)
		m_nCurSel = 0;

	m_ctlListBox.GetText(m_nCurSel, strField);
	m_mapField.Lookup(strField, strValue);
	m_ctlEdit.SetWindowText(strValue);
}

CString CEditDlg::GetValue(CString strKey)
{
	return m_mapField[strKey];
}

void CEditDlg::OnOK()
{
	OnFieldChange();
	CDialog::OnOK();
}
