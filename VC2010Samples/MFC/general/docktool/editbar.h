// editbar.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "searchbx.h"

/////////////////////////////////////////////////////////////////////////////
// CEditBar window

class CEditBar : public CToolBar
{
// Construction
public:
	BOOL m_bColor;
	CSearchBox m_SearchBox;

	CEditBar();
	BOOL Init(CWnd* pParentWnd, BOOL bColor, BOOL bToolTips);
	BOOL SetColor(BOOL bColor);
	BOOL SetHorizontal();
	BOOL SetVertical();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bVertical;

	virtual ~CEditBar();
//  virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);
	virtual CSize CalcDynamicLayout(int nLength, DWORD dwMode);

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditBar)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
