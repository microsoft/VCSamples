// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "DrawClient.h"
#include "LineWeightDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CLineWeightDlg::CLineWeightDlg(CWnd* pParent /*=NULL*/) :
	CDialog(CLineWeightDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineWeightDlg)
	m_penSize = 0;
	//}}AFX_DATA_INIT
}

void CLineWeightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineWeightDlg)
	DDX_Control(pDX, IDC_SPIN1, m_SpinCtrl);
	DDX_Text(pDX, IDC_WEIGHT, m_penSize);
	DDV_MinMaxUInt(pDX, m_penSize, 0, 100);
	//}}AFX_DATA_MAP
}

BOOL CLineWeightDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_SpinCtrl.SetRange(0, 100);
	m_SpinCtrl.SetBase(10);
	m_SpinCtrl.SetPos(max(m_penSize, 0));
	return TRUE;
}

BEGIN_MESSAGE_MAP(CLineWeightDlg, CDialog)
	//{{AFX_MSG_MAP(CLineWeightDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
