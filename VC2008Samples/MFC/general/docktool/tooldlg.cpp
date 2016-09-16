// tooldlg.cpp : implementation file
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
#include "docktool.h"
#include "tooldlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToolDlg dialog


CToolDlg::CToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToolDlg)
	m_bBrowse = FALSE;
	m_bDebug = FALSE;
	m_bEdit = FALSE;
	m_bMain = FALSE;
	m_bResource = FALSE;
	m_nToolTips = -1;
	m_bPalette = FALSE;
	m_nColumns = -1;
	m_nColor = -1;
	//}}AFX_DATA_INIT
}


void CToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToolDlg)
	DDX_Check(pDX, IDC_BROWSE, m_bBrowse);
	DDX_Check(pDX, IDC_DEBUG, m_bDebug);
	DDX_Check(pDX, IDC_EDIT, m_bEdit);
	DDX_Check(pDX, IDC_MAIN, m_bMain);
	DDX_Check(pDX, IDC_RESOURCE, m_bResource);
	DDX_Radio(pDX, IDC_SHOW, m_nToolTips);
	DDX_Check(pDX, IDC_PALETTE, m_bPalette);
	DDX_Radio(pDX, IDC_TWO, m_nColumns);
	DDX_Radio(pDX, IDC_COLOR, m_nColor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToolDlg, CDialog)
	//{{AFX_MSG_MAP(CToolDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CToolDlg message handlers
