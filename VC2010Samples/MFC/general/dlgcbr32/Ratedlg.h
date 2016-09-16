// RateDlg.h : header file
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
	Interface to CRateDlg, which allows the user to specify how often to
	update the main dialog display.

  Functions:
	CRateDlg::CRateDlg()            -- constructor
	CRateDlg::DoDataExchange()      -- dialog data exchange/validation
	CRateDlg::GetRate()             -- retrieve update rate
	CRateDlg::OnInitDialog()        -- initialize dialog

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __RATEDLG_H__
#define __RATEDLG_H__

class CRateDlg : public CDialog
{
// Construction
public:
	CRateDlg(UINT iRate, CWnd* pParent = NULL);

// Attributes
	UINT GetRate() const { return m_iRate; }

// Dialog Data
protected:
	//{{AFX_DATA(CRateDlg)
	enum { IDD = IDD_RATE };
	UINT    m_iRate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRateDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif //__RATEDLG_H__
