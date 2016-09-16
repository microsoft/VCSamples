// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// LinkButton.cpp: implementation of the CMSMCategoryBarButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MSMCategoryBarButton.h"
#include "MSMVisualManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static const int nTextMargin = 3;
static const int nSeparatorWidth = 8;
static const CString strDummyAmpSeq = _T("\001\001");

IMPLEMENT_SERIAL(CMSMCategoryBarButton, CMFCToolBarButton, 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMSMCategoryBarButton::CMSMCategoryBarButton ()
{
	Initialize ();
}

//***************************************************************************************
CMSMCategoryBarButton::CMSMCategoryBarButton (LPCTSTR lpszLabel, UINT nID)
{
	m_strText = lpszLabel;
	m_nID     = nID;

	Initialize ();
}

CMSMCategoryBarButton::~CMSMCategoryBarButton ()
{

}

void CMSMCategoryBarButton::Initialize ()
{
	m_bText = TRUE;
}

void CMSMCategoryBarButton::OnDraw (CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages,
								BOOL bHorz, BOOL bCustomizeMode, BOOL bHighlight,
								BOOL bDrawBorder, BOOL /*bGrayDisabledButtons*/)
{
	ASSERT_VALID (pDC);
	ASSERT_VALID (this);

	m_bHorz = bHorz;

	//----------------------
	// Fill button interior:
	//----------------------
	FillInterior (pDC, rect, bHighlight);

	BOOL bHot = bHighlight;
	CSize sizeImage = (pImages == NULL) ? CSize (0, 0) : pImages->GetImageSize (TRUE);

	CRect rectInternal = rect;

	CFont* pOldFont = (CFont*)(pDC->SelectObject (&afxGlobalData.fontBold)); 

	//--------------------
	// Draw button's text:
	//--------------------
	CMFCVisualManager::AFX_BUTTON_STATE state = CMFCVisualManager::ButtonsIsRegular;

	if (bHighlight)
	{
		state = CMFCVisualManager::ButtonsIsHighlighted;
	}
	else if (m_nStyle & (TBBS_PRESSED | TBBS_CHECKED))
	{
		//-----------------------
		// Pressed in or checked:
		//-----------------------
		state = CMFCVisualManager::ButtonsIsPressed;
	}

	COLORREF clrText = CMFCVisualManager::GetInstance ()->GetToolbarButtonTextColor (
		this, state);

	pDC->SetTextColor (clrText);
	CString strText = m_strText;
	CRect rectText = rectInternal;
	UINT uiTextFormat = 0;

	rectText.top += 7;
	uiTextFormat = DT_SINGLELINE;

	if (bHorz)
	{
		pDC->DrawText (strText, &rectText, uiTextFormat | DT_CENTER);
	}

	pDC->SelectObject (pOldFont); 

	//--------------------
	// Draw button border:
	//--------------------
	if (!bCustomizeMode && HaveHotBorder () && bDrawBorder)
	{
		if (m_nStyle & (TBBS_PRESSED | TBBS_CHECKED))
		{
			//-----------------------
			// Pressed in or checked:
			//-----------------------
			CMFCVisualManager::GetInstance ()->OnDrawButtonBorder (pDC,
				this, rect, CMFCVisualManager::ButtonsIsPressed);
		}
		else if (bHot && !(m_nStyle & TBBS_DISABLED) &&
			!(m_nStyle & (TBBS_CHECKED | TBBS_INDETERMINATE)))
		{
			CMFCVisualManager::GetInstance ()->OnDrawButtonBorder (pDC,
				this, rect, CMFCVisualManager::ButtonsIsHighlighted);
		}
	}
}

SIZE CMSMCategoryBarButton::OnCalculateSize (
								CDC* pDC,
								const CSize& sizeDefault,
								BOOL bHorz)
{
	ASSERT_VALID (pDC);

	CMSMVisualManager* pManager = DYNAMIC_DOWNCAST (CMSMVisualManager,
		CMFCVisualManager::GetInstance ());

	if (pManager == NULL)
	{
		return CMFCToolBarButton::OnCalculateSize (pDC, sizeDefault, bHorz);
	}

	if(!IsVisible())
	{
		return CSize(0,0);
	}

	CSize size = sizeDefault;

	if ((m_nStyle & TBBS_SEPARATOR) == 0)
	{
		if (!IsDrawImage () || GetImage () < 0)
		{
			CSize sizeExtra = m_bExtraSize ? 
				CMFCVisualManager::GetInstance ()->GetButtonExtraBorder () : CSize (0, 0);

			if (bHorz)
			{
				size.cx = sizeExtra.cx;
			}
			else
			{
				size.cy = sizeExtra.cy;
			}
		}

		m_sizeText = CSize (0, 0);

		if (!m_strText.IsEmpty () && IsDrawText ())
		{
			CFont* pOldFont = (CFont*)(pDC->SelectObject (&afxGlobalData.fontBold)); 

			CRect rectText (0, 0, 
				sizeDefault.cx * 3, sizeDefault.cy);

			UINT uiTextFormat = DT_CENTER | DT_CALCRECT;
			if (m_bWrapText)
			{
				uiTextFormat |= DT_WORDBREAK;
			}

			pDC->DrawText (	m_strText, rectText, uiTextFormat);
			m_sizeText = rectText.Size ();
			m_sizeText.cx += 2 * nTextMargin;

			size.cx = max (size.cx, m_sizeText.cx) + 6 * nTextMargin;
			size.cy = m_sizeText.cy + 11;

			pDC->SelectObject (pOldFont);
		}
	}

	return size;
}
