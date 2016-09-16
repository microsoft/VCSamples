// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// LinkButton.cpp: implementation of the CMSMLinksBarButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MSMLinksBarButton.h"
#include "MSMVisualManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static const int nTextMargin = 3;

IMPLEMENT_SERIAL(CMSMLinksBarButton, CMFCToolBarButton, 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMSMLinksBarButton::CMSMLinksBarButton ()
{
	Initialize ();
}

//***************************************************************************************
CMSMLinksBarButton::CMSMLinksBarButton (LPCTSTR lpszLabel, UINT nID)
{
	m_strText = lpszLabel;
	m_nID     = nID;

	Initialize ();
}
//***************************************************************************************
CMSMLinksBarButton::~CMSMLinksBarButton ()
{

}
//***************************************************************************************
void CMSMLinksBarButton::Initialize ()
{
	m_bText = TRUE;
}

void CMSMLinksBarButton::OnDraw (CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages,
								BOOL bHorz, BOOL bCustomizeMode, BOOL bHighlight,
								BOOL bDrawBorder, BOOL /*bGrayDisabledButtons*/)
{
	ASSERT_VALID (pDC);
	ASSERT_VALID (this);

	m_bHorz = bHorz;

	//----------------------
	// Fill button interior:
	//----------------------
	BOOL bChecked = (m_nStyle & TBBS_CHECKED) != 0;

	if (bChecked)
	{
		m_nStyle &= ~TBBS_CHECKED;
	}

	FillInterior (pDC, rect, bHighlight);

	if (bChecked)
	{
		m_nStyle |= TBBS_CHECKED;
	}

	BOOL bHot = bHighlight;
	CSize sizeImage = (pImages == NULL) ? CSize (0, 0) : pImages->GetImageSize (TRUE);

	CRect rectInternal = rect;

	//--------------------
	// Draw button's text:
	//--------------------
	CMFCVisualManager::AFX_BUTTON_STATE state = CMFCVisualManager::ButtonsIsRegular;

	CFont* pOldFont = NULL;

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

	if (m_nStyle & TBBS_CHECKED)
	{
		pOldFont = (CFont*)(pDC->SelectObject (&afxGlobalData.fontBold)); 
	}
	else
	{
		pOldFont = (CFont*)(pDC->SelectObject (&afxGlobalData.fontRegular)); 
	}

	COLORREF clrText = CMFCVisualManager::GetInstance ()->GetToolbarButtonTextColor (
		this, state);

	pDC->SetTextColor (clrText);
	CString strText = m_strText;
	CRect rectText = rectInternal;
	UINT uiTextFormat = 0;

	uiTextFormat = DT_SINGLELINE;

	if (bHorz)
	{
		pDC->DrawText (strText, &rectText, uiTextFormat | DT_VCENTER | DT_CENTER | DT_END_ELLIPSIS);
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
			if ((m_nStyle & TBBS_PRESSED) || bHighlight)
			{
				CMFCVisualManager::GetInstance ()->OnDrawButtonBorder (pDC,
					this, rect, CMFCVisualManager::ButtonsIsPressed);
			}
		}
		else if (bHot && !(m_nStyle & TBBS_DISABLED) &&
			!(m_nStyle & (TBBS_CHECKED | TBBS_INDETERMINATE)))
		{
			CMFCVisualManager::GetInstance ()->OnDrawButtonBorder (pDC,
				this, rect, CMFCVisualManager::ButtonsIsHighlighted);
		}
	}
}


SIZE CMSMLinksBarButton::OnCalculateSize (
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

			size.cx = max (size.cx, m_sizeText.cx);
			size.cy = m_sizeText.cy + 4 * nTextMargin;

			pDC->SelectObject (pOldFont);
		}
	}

	return size;
}
