// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "MSMToolBar.h"

#include "MSMVisualManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMFCToolBarImages CMSMToolBar::m_PressedImages;

/////////////////////////////////////////////////////////////////////////////
// CMSMToolBar

IMPLEMENT_DYNCREATE(CMSMToolBar, CMFCToolBar)

CMSMToolBar::CMSMToolBar()
{
}


CMSMToolBar::~CMSMToolBar()
{
}

BOOL CMSMToolBar::LoadToolBar(UINT uiResID, UINT uiColdResID, UINT uiMenuResID, 
							  BOOL bLocked,
							  UINT uiDisabledResID, UINT uiMenuDisabledResID,
							  UINT uiHotResID, UINT uiPressedResID)
{
	if (!CMFCToolBar::LoadToolBar (uiResID, uiColdResID, uiMenuResID, bLocked, 
		uiDisabledResID, uiMenuDisabledResID, uiHotResID))
	{
		return FALSE;
	}

	if (uiPressedResID != 0)
	{
		m_PressedImages.SetImageSize (m_sizeImage);

		if (!m_PressedImages.Load (uiPressedResID, AfxGetResourceHandle (), TRUE))
		{
			return FALSE;
		}

		ASSERT (m_Images.GetCount () == m_PressedImages.GetCount ());
	}

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMSMToolBar, CMFCToolBar)
	ON_WM_CREATE()
	ON_WM_SYSCOLORCHANGE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMToolBar message handlers

int CMSMToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMFCToolBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetPaneStyle((GetPaneStyle () & 
		~(CBRS_GRIPPER | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT))
		| CBRS_SIZE_DYNAMIC);
	SetBorders ();
	
	SetGrayDisabledButtons (FALSE);

	return 0;
}

BOOL CMSMToolBar::DrawButton(CDC* pDC, CMFCToolBarButton* pButton,
							CMFCToolBarImages* pImages,
							BOOL bHighlighted, BOOL bDrawDisabledImages)
{
	ASSERT_VALID (pDC);
	ASSERT_VALID (pButton);

	CMFCToolBarImages* pNewImages = pImages;

	CAfxDrawState ds;

	if (!m_bMenuMode && (pButton->m_nStyle & (TBBS_PRESSED)) && 
		m_PressedImages.GetCount () > 0)
	{
		pNewImages = &m_PressedImages;
	
		pNewImages->SetTransparentColor (afxGlobalData.clrBtnFace);

		pNewImages->PrepareDrawImage (ds, GetImageSize (), FALSE);
	}

	if (!CMFCToolBar::DrawButton (pDC, pButton, pNewImages, bHighlighted, 
			bDrawDisabledImages))
	{
		return FALSE;
	}

	if (pNewImages != pImages)
	{
		pNewImages->EndDrawImage (ds);
	}

	return TRUE;
}


void CMSMToolBar::OnSysColorChange ()
{
	CMFCToolBar::OnSysColorChange ();

	m_PressedImages.OnSysColorChange ();
}
