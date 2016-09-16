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

#pragma once

class CLineWeightDlg : public CDialog
{
// Construction
public:
	CLineWeightDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineWeightDlg)
	enum { IDD = IDD_LINEWEIGHT };
	CSpinButtonCtrl m_SpinCtrl;
	UINT    m_penSize;
	//}}AFX_DATA

// Overrides
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

// Implementation
protected:
	//{{AFX_MSG(CLineWeightDlg)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
