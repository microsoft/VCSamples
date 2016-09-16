// AllControlsSheet.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CAllControlsSheet

#include "treecpg.h"
#include "animctrl.h"
#include "toolpage.h"
#include "datetime.h"
#include "monthcal.h"

class CAllControlsSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CAllControlsSheet)

// Construction
public:
	CAllControlsSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CAllControlsSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

protected:
	void AddControlPages(void);

// Attributes
public:

	CTreeCtrlPage       m_treectrlpage;
	CAnimateCtrlPage    m_animctrlpage;
	CToolBarCtrlPage    m_toolbarpage;
	CDateTimePage       m_datetimepage;
	CMonthCalPage       m_monthcalpage;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllControlsSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAllControlsSheet();
	virtual BOOL OnInitDialog();

	// Generated message map functions
protected:

	HICON m_hIcon;

	//{{AFX_MSG(CAllControlsSheet)
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
