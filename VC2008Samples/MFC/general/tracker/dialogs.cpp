// dialogs.cpp : implementation file
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
#include "trackapp.h"
#include "dialogs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHandleSize dialog


CHandleSize::CHandleSize(CWnd* pParent /*=NULL*/)
	: CDialog(CHandleSize::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHandleSize)
	m_nHandleSize = 0;
	//}}AFX_DATA_INIT
}

void CHandleSize::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHandleSize)
	DDX_Text(pDX, IDC_EDIT1, m_nHandleSize);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHandleSize, CDialog)
	//{{AFX_MSG_MAP(CHandleSize)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CHandleSize message handlers
/////////////////////////////////////////////////////////////////////////////
// CMinSize dialog


CMinSize::CMinSize(CWnd* pParent /*=NULL*/)
	: CDialog(CMinSize::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMinSize)
	m_nMinX = 0;
	m_nMinY = 0;
	//}}AFX_DATA_INIT
}

void CMinSize::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMinSize)
	DDX_Text(pDX, IDC_EDIT1, m_nMinX);
	DDX_Text(pDX, IDC_EDIT2, m_nMinY);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMinSize, CDialog)
	//{{AFX_MSG_MAP(CMinSize)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMinSize message handlers
