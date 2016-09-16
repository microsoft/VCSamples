// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMSMToolBar window

class CMSMToolBar : public CMFCToolBar
{
	DECLARE_DYNCREATE(CMSMToolBar)

// Construction
public:
	CMSMToolBar();

	virtual ~CMSMToolBar ();

// Attributes
public:

// Operations
public:

// Implementation
public:

	virtual BOOL LoadToolBar (UINT uiResID, UINT uiColdResID = 0, 
					UINT uiMenuResID = 0, BOOL bLocked = FALSE,
					UINT uiDisabledResID = 0, UINT uiMenuDisabledResID = 0,
  				    UINT uiHotResID = 0, UINT uiPressedResID = 0);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSysColorChange();

	DECLARE_MESSAGE_MAP()

	virtual BOOL DrawButton (CDC* pDC, CMFCToolBarButton* pButton, 
		CMFCToolBarImages* pImages, BOOL bHighlighted,
		BOOL bDrawDisabledImages);

protected:

	static CMFCToolBarImages m_PressedImages; // Shared pressed images
};
