// RateDlg.cpp : Implementation file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/*****************************************************************************
  Purpose:
	Implements CRateDlg, which allows the user to specify how often to
	update the main dialog display.

  Functions:
	CRateDlg::CRateDlg()            -- constructor
	CRateDlg::DoDataExchange()      -- dialog data exchange/validation
	CRateDlg::OnInitDialog()        -- initialize dialog

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#include "stdafx.h"
#include "resource.h"
#include "ratedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRateDlg dialog

CRateDlg::CRateDlg(UINT iRate, CWnd* pParent /*=NULL*/)
	: CDialog(CRateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRateDlg)
	//}}AFX_DATA_INIT
	m_iRate = iRate;
}

void CRateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRateDlg)
	DDX_Text(pDX, IDC_INTERVAL, m_iRate);
	DDV_MinMaxUInt(pDX, m_iRate, 0, 3600);
	//}}AFX_DATA_MAP
}

BOOL CRateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CRateDlg, CDialog)
	//{{AFX_MSG_MAP(CRateDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
