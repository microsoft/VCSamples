// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMVisualManager.cpp : implementation file
//

#include "stdafx.h"
#include "MSMVisualManager.h"

#include "MSMCaptionBar.h"
#include "MSMMenuBar.h"
#include "MSMToolBar.h"
#include "MSMTasksPane.h"
#include "MSMCategoryBar.h"
#include "MSMCategoryBarButton.h"
#include "MSMLinksBar.h"
#include "MSMLinksBarButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WP_MINBUTTON		15
#define WP_MAXBUTTON		17
#define WP_CLOSEBUTTON		18
#define WP_RESTOREBUTTON	21

#define CBS_NORMAL			1
#define CBS_HOT				2
#define CBS_PUSHED			3
#define	CBS_DISABLED		4

IMPLEMENT_DYNCREATE(CMSMVisualManager, CMFCVisualManagerOffice2003)

/////////////////////////////////////////////////////////////////////////////
// CMSMVisualManager

BOOL _StretchBitmap (CDC* pDC, const CRect& rectClient, CBitmap& bmp)
{
	ASSERT_VALID (pDC);

	if (bmp.GetSafeHandle () != NULL)
	{
		BITMAP bm;
		ZeroMemory (&bm, sizeof (BITMAP));

		bmp.GetBitmap (&bm);
		
		CDC dc;
		dc.CreateCompatibleDC (pDC);

		// Select the bitmap into the in-memory DC
		CBitmap* pOldBitmap = dc.SelectObject (&bmp);

		int nOldStretchBltMode = pDC->SetStretchBltMode (COLORONCOLOR);

		pDC->StretchBlt(0, 0, rectClient.Width (), rectClient.Height (), &dc, 
						0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);


		dc.SelectObject (pOldBitmap);

		pDC->SetStretchBltMode (nOldStretchBltMode);

		return true;
	}

	return false;
}


void _DrawReflectedGradient (CDC* pDC, COLORREF clrS, COLORREF clrM, COLORREF clrF,
							 const CRect& rect, BOOL bHorz)
{
	ASSERT_VALID (pDC);

	CDrawingManager dm (*pDC);

	long x1 = rect.left;
	long x2 = rect.right;
	long y1 = rect.top;
	long y2 = rect.bottom;

	if (bHorz)
	{
		CRect rt (x1, y1, x2, (y1 + y2) / 2);
		dm.FillGradient (rt, clrM, clrS, TRUE);
		rt.top = rt.bottom;
		rt.bottom = y2;
		dm.FillGradient (rt, clrF, clrM, TRUE);
	}
	else
	{
		CRect rt (x1, y1, (x1 + x2) / 2, y2);
		dm.FillGradient (rt, clrS, clrM, FALSE);
		rt.left  = rt.right;
		rt.right = x2;
		dm.FillGradient (rt, clrM, clrF, FALSE);
	}
}

CMSMVisualManager::CMSMVisualManager()
{
	//SetOfficeStyleMenus (TRUE);
	SetMenuShadowDepth  (0);

	m_MemoryFilled = false;
	m_MemorySize   = CSize (0, 0);

	m_CaptionButtonSize = CSize (0, 0);

	m_brMenuBarButtonHighlighted.CreateSolidBrush (RGB ( 57, 134, 206));
	m_clrMenuBarButtonBorderHighlighted = RGB ( 57, 134, 206);

	m_clrMenuBarButtonTextRegular       = RGB (255, 255, 255);
	m_clrMenuBarButtonTextPressed       = RGB (255, 255, 255);
	m_clrMenuBarButtonTextHighlighted   = RGB (255, 255, 255);

	m_clrToolBarButtonTextRegular       = RGB (255, 255, 255);
	m_clrToolBarButtonTextPressed       = RGB (255, 223, 127);
	m_clrToolBarButtonTextHighlighted   = RGB (255, 223, 127);

	m_clrCategorieBarButtonTextRegular	= RGB (232, 243, 253);
	m_clrCategorieBarButtonTextPressed	= RGB (255, 223, 127);
	m_clrCategorieBarButtonTextHighlighted
										= RGB (255, 223, 127);

	m_clrToolBarSeparatorS              = RGB (119, 162, 211);
	m_clrToolBarSeparatorM              = RGB (255, 255, 255);
	m_clrToolBarSeparatorF              = RGB ( 85, 136, 198);

	m_clrComboBoxBorder					= RGB ( 78, 122, 171);

	m_clrComboBoxBtnRegularF			= RGB (208, 220, 252);
	m_clrComboBoxBtnRegularL			= RGB (182, 205, 251);
	m_clrComboBoxBtnRegularBorder		= RGB (177, 197, 245);
	m_clrComboBoxBtnHighlightedF		= RGB (226, 244, 254);
	m_clrComboBoxBtnHighlightedL		= RGB (203, 219, 252);
	m_clrComboBoxBtnHighlightedBorder	= RGB (140, 165, 225);
	m_clrComboBoxBtnPressedF			= RGB (122, 153, 242);
	m_clrComboBoxBtnPressedL			= RGB (159, 178, 235);
	m_clrComboBoxBtnPressedBorder		= RGB (181, 198, 242);

	m_clrCategorieBarButtonBorder       = RGB ( 53,  94, 159);
	m_clrCategorieBarButtonBorderM      = RGB (191, 209, 231);
	m_clrCategorieBarButtonLine         = RGB (123, 165, 210);
	m_clrCategorieBarButtonF            = RGB ( 77, 127, 193);
	m_clrCategorieBarButtonL            = RGB ( 40,  74, 144);

	m_brLinksBarBack.CreateSolidBrush (RGB ( 49,  85, 153));

	m_brLinksBarButtonHighlighted.CreateSolidBrush (RGB ( 38,  69, 135));
	m_clrLinksBarButtonBorderHighlighted
										= RGB ( 38,  69, 135);
}

BOOL CMSMVisualManager::LoadMSMCaptionButtonsIcons (LPCTSTR lpszID)
{
	CBitmap bmp;

	m_CaptionButtonSize = CSize (0, 0);

	if (bmp.LoadBitmap (lpszID))
	{
		BITMAP bm;
		ZeroMemory (&bm, sizeof (BITMAP));

		bmp.GetBitmap (&bm);

		if (m_CaptionButtonIconst.GetSafeHandle() != NULL && 
			m_CaptionButtonIconst.GetImageCount () > 0)
		{
			m_CaptionButtonIconst.DeleteImageList ();
		}

		UINT nFlags = ILC_MASK;

		switch (bm.bmBitsPixel)
		{
		case 4 :
			nFlags |= ILC_COLOR4;
			break;
		case 8 :
			nFlags |= ILC_COLOR8;
			break;
		case 16:
			nFlags |= ILC_COLOR16;
			break;
		case 24:
			nFlags |= ILC_COLOR24;
			break;
		case 32:
			nFlags |= ILC_COLOR32;
			break;
		default:
			ASSERT (FALSE);
		}

		m_CaptionButtonSize.cx = bm.bmWidth / 12;
		m_CaptionButtonSize.cy = bm.bmHeight;

		m_CaptionButtonIconst.Create (m_CaptionButtonSize.cx, 
			m_CaptionButtonSize.cy, nFlags, 0, 3);
		m_CaptionButtonIconst.Add (&bmp, RGB (255, 0, 255));

		return true;
	}

	return false;
}

void CMSMVisualManager::OnUpdateSystemColors ()
{

	CMFCVisualManagerOffice2003::OnUpdateSystemColors();

	m_clrMenuLight						= RGB (210, 232, 253);
	m_brMenuLight.DeleteObject ();
	m_brMenuLight.CreateSolidBrush (m_clrMenuLight);

	m_clrHighlight						= RGB (152, 192, 235);
	m_brHighlight.DeleteObject ();
	m_brHighlight.CreateSolidBrush (m_clrHighlight);

	m_clrHighlightDn					= RGB (152, 192, 235);
	m_brHighlightDn.DeleteObject ();
	m_brHighlightDn.CreateSolidBrush (m_clrHighlightDn);

	m_clrHighlightChecked				= RGB (152, 192, 235);
	m_brHighlightChecked.DeleteObject ();
	m_brHighlightChecked.CreateSolidBrush (m_clrHighlightChecked);

	m_clrMenuItemBorder 				= RGB (152, 192, 235);

	m_clrMenuBorder 					= RGB (128, 128, 128);
}

CMSMVisualManager::~CMSMVisualManager()
{
}

void CMSMVisualManager::SetupMemoryBitmapSize (CDC* pDC, const CSize& size)
{
	if (pDC == NULL && size == CSize (0, 0))
	{
		return;
	}

	if (m_MemoryDC.GetSafeHdc () != NULL)
	{
		if (pDC && pDC->GetDeviceCaps (BITSPIXEL) != m_MemoryDC.GetDeviceCaps (BITSPIXEL))
		{
			m_MemoryBitmap.DeleteObject ();
			m_MemoryDC.DeleteDC ();
		}
	}

	if (m_MemoryDC.GetSafeHdc () == NULL)
	{
		m_MemoryDC.CreateCompatibleDC (pDC);
	}

	if (m_MemorySize != size || m_MemoryBitmap.GetSafeHandle () == NULL)
	{
		m_MemorySize = size;

		if (m_MemoryBitmap.GetSafeHandle () != NULL)
		{
			m_MemoryBitmap.DeleteObject ();
		}

		m_MemoryBitmap.CreateCompatibleBitmap (pDC, m_MemorySize.cx, m_MemorySize.cy);
		m_MemoryDC.SelectObject (m_MemoryBitmap);

		m_MemoryFilled = false;
	}

	if (m_MSMFrameBitmap.GetSafeHandle () != NULL)
	{
		m_MemoryFilled = _StretchBitmap (&m_MemoryDC, CRect (CPoint (0, 0), m_MemorySize), m_MSMFrameBitmap);
	}
}

void CMSMVisualManager::OnFillBarBackground (CDC* pDC, CBasePane* pBar,
		CRect rectClient, CRect rectClip, BOOL /*bNCArea*/)
{
	if (m_MSMFrameBitmap.GetSafeHandle () == NULL)
	{
		m_MSMFrameBitmap.LoadBitmap (_T("IDB_MSM_FRAME_BKGND"));

		if (!m_MemoryFilled)
		{
			m_MemoryFilled = 
				_StretchBitmap (&m_MemoryDC, CRect (CPoint (0, 0), m_MemorySize), m_MSMFrameBitmap);
		}
	}

	ASSERT_VALID (pDC);
	ASSERT_VALID (pBar);

	if (rectClip.IsRectEmpty ())
	{
		rectClip = rectClient;
	}

	CRuntimeClass* pBarClass = pBar->GetRuntimeClass ();

	if (pBarClass == NULL || pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMFCPopupMenuBar)))
	{
		pDC->FillRect (rectClip, &m_brMenuLight);

		return;
	}

	BOOL bDefault = true;

	if (pBarClass != NULL &&
		(pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMSMCaptionBar)) ||
		 pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMSMMenuBar)) ||
		 pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMSMToolBar))
		))
	{
		if (pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMSMLinksBar)))
		{
			pDC->FillRect (rectClip, &m_brLinksBarBack);
			return;
		}

		if (!pBar->IsFloating ())
		{
			CRect rt (rectClient);

			CWnd* pWnd = pBar->GetTopLevelFrame ();
			if (pWnd != NULL)
			{
				CRect rtW;
				pBar->GetWindowRect (rtW);
				pWnd->ScreenToClient (rtW);

				rt.OffsetRect (rtW.TopLeft ());
			}

			int nOldStretchBltMode = pDC->SetStretchBltMode (COLORONCOLOR);

			pDC->BitBlt(rectClient.left, rectClient.top,
						rectClient.Width (), rectClient.Height (), 
						&m_MemoryDC, 
						rt.left, rt.top, 
						SRCCOPY);

			pDC->SetStretchBltMode (nOldStretchBltMode);

			bDefault = false;

			if (pBarClass->IsDerivedFrom (RUNTIME_CLASS (CMSMCategoryBar)))
			{
				CDrawingManager dm (*pDC);

				CRect rect (rectClient);
				rect.top += 3;

				rect.bottom = rect.top + 1;
				dm.HighlightRect (rect, 15, (COLORREF)-1, 0, RGB (255, 255, 255));

				rect.top++;
				rect.bottom++;
				dm.HighlightRect (rect, 40, (COLORREF)-1, 0, RGB (255, 255, 255));

				rect.top++;
				rect.bottom = rectClient.bottom - 1;
				dm.HighlightRect (rect, 30, (COLORREF)-1, 0, RGB (255, 255, 255));

				rect.top = rect.bottom;
				rect.bottom++;
				dm.HighlightRect (rect, 10, (COLORREF)-1, 0, RGB (255, 255, 255));
			}
		}
	}

	if (bDefault)
	{
		CMFCVisualManagerOffice2003::OnFillBarBackground (pDC, pBar, rectClient, rectClip);
	}
}

void CMSMVisualManager::MSMDrawCaptionButton (CDC* pDC, CRect rect, AFX_BUTTON_STATE state, UINT id)
{
	int nState = CBS_NORMAL;

	int nPart = 0;

	if (m_CaptionButtonIconst.GetSafeHandle () != NULL &&
		m_CaptionButtonIconst.GetImageCount () >= 12)
	{
		long index = 0;

		switch (id)
		{
		case SC_CLOSE:
			index = 9;
			break;
		case SC_MINIMIZE:
			index = 0;
			break;
		case SC_MAXIMIZE:
			index = 3;
			break;
		case SC_RESTORE:
			index = 6;
			break;
		default:
			ASSERT (FALSE);
		}

		switch (state)
		{
		case ButtonsIsHighlighted:
			index += 1;
			break;
		case ButtonsIsPressed:
			index += 2;
			break;
		}

		m_CaptionButtonIconst.Draw (pDC, index, rect.TopLeft (), ILD_NORMAL);

		return;
	}

	if (m_pfDrawThemeBackground == NULL || m_hThemeWindow == NULL)
	{
		switch (state)
		{
		case ButtonsIsRegular:
		case ButtonsIsHighlighted:
			nState = 0;
			break;
		case ButtonsIsPressed:
			nState = DFCS_PUSHED;
			break;
		}

		switch (id)
		{
		case SC_CLOSE:
			nPart = DFCS_CAPTIONCLOSE;
			break;
		case SC_MINIMIZE:
			nPart = DFCS_CAPTIONMIN;
			break;
		case SC_MAXIMIZE:
			nPart = DFCS_CAPTIONMAX;
			break;
		case SC_RESTORE:
			nPart = DFCS_CAPTIONRESTORE;
			break;
		default:
			ASSERT (FALSE);
		}

		pDC->DrawFrameControl (rect, DFC_CAPTION, nPart | nState);
		return;
	}

	switch (state)
	{
	case ButtonsIsRegular:
		nState = CBS_NORMAL;
		break;
	case ButtonsIsPressed:
		nState = CBS_PUSHED;
		break;
	case ButtonsIsHighlighted:
		nState = CBS_HOT;
		break;
	}

	switch (id)
	{
	case SC_CLOSE:
		nPart = WP_CLOSEBUTTON;
		break;
	case SC_MINIMIZE:
		nPart = WP_MINBUTTON;
		break;
	case SC_MAXIMIZE:
		nPart = WP_MAXBUTTON;
		break;
	case SC_RESTORE:
		nPart = WP_RESTOREBUTTON;
		break;
	default:
		ASSERT (FALSE);
	}

	(*m_pfDrawThemeBackground) (m_hThemeWindow, pDC->GetSafeHdc(), nPart,
		nState, &rect, 0);
}

COLORREF CMSMVisualManager::GetToolbarButtonTextColor (CMFCToolBarButton* pButton,
												CMFCVisualManager::AFX_BUTTON_STATE state)
{
	COLORREF clr = COLORREF (-1);

	CMFCToolBarMenuButton* pMenuButton = 
		DYNAMIC_DOWNCAST (CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuButton = pMenuButton != NULL;

	BOOL bIsPopupMenu = bIsMenuButton &&
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar));

	if (bIsMenuButton && !bIsPopupMenu)
	{
		switch (state)
		{
		case ButtonsIsRegular:
			clr = m_clrMenuBarButtonTextRegular;
			break;
		case ButtonsIsPressed:
			clr = m_clrMenuBarButtonTextPressed;
			break;
		case ButtonsIsHighlighted:
			clr = m_clrMenuBarButtonTextHighlighted;
			break;
		}
	}
	else
	{
		if (pButton->IsKindOf (RUNTIME_CLASS (CMSMCategoryBarButton)))
		{
			switch (state)
			{
			case ButtonsIsRegular:
				clr = m_clrCategorieBarButtonTextRegular;
				break;
			case ButtonsIsPressed:
				clr = m_clrCategorieBarButtonTextPressed;
				break;
			case ButtonsIsHighlighted:
				clr = m_clrCategorieBarButtonTextHighlighted;
				break;
			}
		}
		else
		{
			switch (state)
			{
			case ButtonsIsRegular:
				clr = m_clrToolBarButtonTextRegular;
				break;
			case ButtonsIsPressed:
				clr = m_clrToolBarButtonTextPressed;
				break;
			case ButtonsIsHighlighted:
				clr = m_clrToolBarButtonTextHighlighted;
				break;
			}
		}
	}

	if (clr == COLORREF (-1))
	{
		clr = CMFCVisualManagerOffice2003::GetToolbarButtonTextColor (pButton, state);
	}

	return clr;
}

void CMSMVisualManager::OnFillHighlightedArea (CDC* pDC, CRect rect, 
		CBrush* pBrush, CMFCToolBarButton* pButton)
{
	if (pButton == NULL)
	{
		CMFCVisualManagerOffice2003::OnFillHighlightedArea (pDC, rect,
												pBrush, pButton);
		return;
	}

	ASSERT_VALID (pDC);
	ASSERT_VALID (pBrush);

	CMFCToolBarMenuButton* pMenuButton = 
		DYNAMIC_DOWNCAST (CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuButton = pMenuButton != NULL;

	BOOL bIsPopupMenu = bIsMenuButton &&
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar));
	
	CBrush* pBr = pBrush;

	bIsMenuButton = bIsMenuButton && 
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCMenuBar));

	BOOL bDefault = true;

	if (bIsMenuButton || bIsPopupMenu)
	{
		if (!bIsPopupMenu)
		{
			pBr = &m_brMenuBarButtonHighlighted;
		}
	}
	else if (pButton->IsKindOf (RUNTIME_CLASS (CMSMLinksBarButton)))
	{
		pBr = &m_brLinksBarButtonHighlighted;
		rect.InflateRect (0, 0, 1, 1);
	}
	else
	{
		bDefault = false;
	}

	if (bDefault)
	{
		CMFCVisualManagerOfficeXP::OnFillHighlightedArea (pDC, rect, pBr, pButton);
		return;
	}
	else if (pButton->IsKindOf (RUNTIME_CLASS (CMSMCategoryBarButton)))
	{
		if ((pButton->m_nStyle & TBBS_CHECKED) != 0)
		{
			CDrawingManager dm(*pDC);
	
			dm.FillGradient (rect,
				m_clrCategorieBarButtonL, m_clrCategorieBarButtonF, TRUE);
		}
	}
	else
	{
		if (pMenuButton != NULL &&
			pMenuButton->GetParentWnd () != NULL &&
			pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMSMToolBar)))
		{
			rect.InflateRect (0, 0, 1, 1);

			CDrawingManager dm (*pDC);

			dm.HighlightRect (rect, 10, (COLORREF)-1, 0, RGB (255, 255, 255));
		}
		else // other buttons
		{
			// TODO: paint toolbar buttons
			//CMFCVisualManagerOffice2003::OnFillHighlightedArea (pDC, rect, pBr, pButton);
		}
	}
}

void CMSMVisualManager::OnDrawMenuBorder (CDC* pDC, CMFCPopupMenu* /*pMenu*/, CRect rect)
{
	ASSERT_VALID (pDC);

	pDC->Draw3dRect (rect, m_clrMenuBorder, m_clrMenuBorder);

	rect.DeflateRect (1, 1);
	pDC->Draw3dRect (rect, m_clrMenuLight, m_clrMenuLight);

	CRect rectLeft (1, 1, 2, rect.bottom - 1);
	pDC->FillRect (rectLeft, &m_brBarBkgnd);

}

void CMSMVisualManager::OnDrawButtonBorder (CDC* pDC,
		CMFCToolBarButton* pButton, CRect rect, AFX_BUTTON_STATE state)
{
	ASSERT_VALID (pDC);
	ASSERT_VALID (pButton);

	if (state != ButtonsIsPressed && state != ButtonsIsHighlighted)
	{
		ASSERT ((pButton->m_nStyle & TBBS_CHECKED) == 0);
		return;
	}

	CMFCToolBarMenuButton* pMenuButton = 
		DYNAMIC_DOWNCAST (CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuButton = pMenuButton != NULL;

	BOOL bIsPopupMenu = bIsMenuButton &&
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar));

	bIsMenuButton = bIsMenuButton &&
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCMenuBar));

	if (bIsMenuButton || bIsPopupMenu)
	{
		COLORREF clrBorder = m_clrMenuItemBorder;

		switch (state)
		{
		case ButtonsIsPressed:
		case ButtonsIsHighlighted:
			clrBorder = bIsPopupMenu 
				? m_clrMenuItemBorder
				: m_clrMenuBarButtonBorderHighlighted;
			break;
		}


		if (!bIsPopupMenu || state != ButtonsIsHighlighted)
		{
			rect.right--;
			rect.bottom--;
		}

		if (bIsMenuButton && !bIsPopupMenu && 
			pMenuButton->IsDroppedDown ())
		{
			CMFCPopupMenu* pPopupMenu= pMenuButton->GetPopupMenu ();
			if (pPopupMenu != NULL && 
				(pPopupMenu->IsWindowVisible () || pPopupMenu->IsShown()))
			{
				ExtendMenuButton (pMenuButton, rect);

				BOOL bRTL = pPopupMenu->GetExStyle() & WS_EX_LAYOUTRTL;

				if (m_bShdowDroppedDownMenuButton && !bRTL && 
					CMFCMenuBar::IsMenuShadows () &&
					!CMFCToolBar::IsCustomizeMode () &&
					afxGlobalData.m_nBitsPerPixel > 8 &&
					!afxGlobalData.m_bIsBlackHighContrast &&
					!pPopupMenu->IsRightAlign ())
				{
					CDrawingManager dm (*pDC);

					dm.DrawShadow (rect, m_nMenuShadowDepth, 100, 75, NULL, NULL,
						m_clrMenuShadowBase);
				}
			}
		}

		if (state == ButtonsIsPressed || state == ButtonsIsHighlighted)
		{
			if (bIsPopupMenu && (pButton->m_nStyle & TBBS_CHECKED))
			{
				rect.bottom ++;
			}

			pDC->Draw3dRect (rect, clrBorder, clrBorder);
		}
	}
	else if (pButton->IsKindOf (RUNTIME_CLASS (CMSMCategoryBarButton)))
	{
		if ((pButton->m_nStyle & TBBS_CHECKED) != 0)
		{
			_DrawReflectedGradient (pDC, m_clrCategorieBarButtonBorder, 
				m_clrCategorieBarButtonBorderM, m_clrCategorieBarButtonBorder, 
				CRect (rect.left, rect.top, rect.right, rect.top + 1), false);

			CDrawingManager dm(*pDC);

			dm.FillGradient (CRect (rect.left, rect.top, rect.left + 1, rect.bottom),
				m_clrCategorieBarButtonL, m_clrCategorieBarButtonBorder, TRUE);

			dm.FillGradient (CRect (rect.right - 1, rect.top, rect.right, rect.bottom),
				m_clrCategorieBarButtonL, m_clrCategorieBarButtonBorder, TRUE);

			{
				CPen pen (PS_SOLID, 0, m_clrCategorieBarButtonLine);

				CPen* pOldPen = pDC->SelectObject (&pen);

				pDC->MoveTo (rect.left + 1, rect.top + 1);
				pDC->LineTo (rect.right - 1, rect.top + 1);

				pDC->SelectObject (pOldPen);
			}

			{
				CPen pen (PS_SOLID, 0, m_clrCategorieBarButtonL);

				CPen* pOldPen = pDC->SelectObject (&pen);

				pDC->MoveTo (rect.left + 1, rect.bottom - 1);
				pDC->LineTo (rect.right - 1, rect.bottom - 1);

				pDC->SelectObject (pOldPen);
			}
		}
	}
	else if (pButton->IsKindOf (RUNTIME_CLASS (CMSMLinksBarButton)))
	{
		if (state == ButtonsIsPressed || state == ButtonsIsHighlighted)
		{
			pDC->Draw3dRect (rect, m_clrLinksBarButtonBorderHighlighted, m_clrLinksBarButtonBorderHighlighted);
		}
	}
	else
	{
		if (pMenuButton != NULL &&
			pMenuButton->GetParentWnd () != NULL &&
			pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMSMToolBar)))
		{
			CRect rt (rect);

			CDrawingManager dm (*pDC);

			rt.bottom = rt.top + 1;
			dm.HighlightRect (rt, 15, (COLORREF)-1, 0, RGB (255, 255, 255));

			rt.bottom = rect.bottom;
			rt.top    = rt.bottom - 1;
			dm.HighlightRect (rt, 15, (COLORREF)-1, 0, RGB (255, 255, 255));

			rt.top    = rect.top    + 1;
			rt.bottom = rect.bottom - 1;
			rt.right  = rt.left + 1;
			dm.HighlightRect (rt, 15, (COLORREF)-1, 0, RGB (255, 255, 255));

			rt.right  = rect.right;
			rt.left   = rt.right - 1;
			dm.HighlightRect (rt, 15, (COLORREF)-1, 0, RGB (255, 255, 255));
		}
		else
		{
			// TODO: paint toolbar buttons
			//CMFCVisualManagerOffice2003::OnDrawButtonBorder (pDC, pButton, rect, state);
		}
	}
}

void CMSMVisualManager::OnHighlightMenuItem (CDC*pDC, CMFCToolBarMenuButton* pButton,
											CRect rect, COLORREF& clrText)
{
	CMFCToolBarMenuButton* pMenuButton = 
		DYNAMIC_DOWNCAST (CMFCToolBarMenuButton, pButton);

	BOOL bIsMenuButton = pMenuButton != NULL;

	BOOL bIsPopupMenu = bIsMenuButton &&
		pMenuButton->GetParentWnd () != NULL &&
		pMenuButton->GetParentWnd ()->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar));

	if (bIsPopupMenu && rect.Width() > pButton->Rect ().Width () / 2)
	{
		rect.right--;
	}

	CMFCVisualManagerOfficeXP::OnHighlightMenuItem (pDC, pButton, rect, clrText);
}

void CMSMVisualManager::OnDrawSeparator (CDC* pDC, CBasePane* pBar,
										 CRect rect, BOOL bHorz)
{
	ASSERT_VALID (pDC);
	ASSERT_VALID (pBar);

	if (pBar->IsDialogControl () || 
		pBar->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar)) || 
		pBar->IsKindOf (RUNTIME_CLASS (CMFCColorBar)))
	{
		CMFCVisualManagerOffice2003::OnDrawSeparator (pDC, pBar, rect, bHorz);
		return;
	}


	CRect rectSeparator = rect;

	int x1, x2;
	int y1, y2;

	if (bHorz)
	{
		x1 = x2 = (rect.left + rect.right) / 2;
		y1 = rect.top;
		y2 = rect.bottom - 1;
	}
	else
	{
		y1 = y2 = (rect.top + rect.bottom) / 2;
		x1 = rect.left;
		x2 = rect.right;

		if (pBar->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar)) &&
			!pBar->IsKindOf (RUNTIME_CLASS (CMFCColorBar)))
		{
			
			x1 = rect.left + CMFCToolBar::GetMenuImageSize ().cx + 
						GetMenuImageMargin () + 1;

			CRect rectBar;
			pBar->GetClientRect (rectBar);

			if (rectBar.right - x2 < 50) // Last item in row
			{
				x2 = rectBar.right;
			}

			if (((CMFCPopupMenuBar*) pBar)->m_bDisableSideBarInXPMode)
			{
				x1 = 0;
			}

			//---------------------------------
			//	Maybe Quick Customize separator
			//---------------------------------
			if (pBar->IsKindOf (RUNTIME_CLASS (CMFCPopupMenuBar)))
			{
				CWnd* pWnd = pBar->GetParent();
				if (pWnd != NULL && pWnd->IsKindOf (RUNTIME_CLASS (CMFCPopupMenu)))
				{
					CMFCPopupMenu* pMenu = (CMFCPopupMenu*)pWnd;
					if (pMenu->IsCustomizePane())
					{
						x1 = rect.left + 2*CMFCToolBar::GetMenuImageSize ().cx + 
								3*GetMenuImageMargin () + 2;
					}
				}
			}
		}
	}

	if (x1 == x2)
	{
		x2++;
	}

	if (y1 == y2)
	{
		y2++;
	}

	_DrawReflectedGradient (pDC, m_clrToolBarSeparatorS, 
		m_clrToolBarSeparatorM, m_clrToolBarSeparatorF, CRect (x1, y1, x2, y2), !!bHorz);
}

void CMSMVisualManager::OnDrawComboBorder (CDC* pDC, CRect rect,
												BOOL bDisabled,
												BOOL bIsDropped,
												BOOL bIsHighlighted,
												CMFCToolBarComboBoxButton* pButton)
{
	if (afxGlobalData.m_nBitsPerPixel <= 8 || afxGlobalData.m_bIsBlackHighContrast)
	{
		CMFCVisualManagerOffice2003::OnDrawComboBorder (pDC, rect,
												bDisabled,
												bIsDropped,
												bIsHighlighted,
												pButton);
		return;
	}

	rect.DeflateRect (1, 1);

	COLORREF colorBorder = bDisabled ? afxGlobalData.clrBtnShadow : m_clrComboBoxBorder;
	pDC->Draw3dRect (&rect, colorBorder, colorBorder);
}

void CMSMVisualManager::OnDrawComboDropButton (CDC* pDC, CRect rect,
												BOOL bDisabled,
												BOOL bIsDropped,
												BOOL bIsHighlighted,
												CMFCToolBarComboBoxButton* pButton)
{
	if (afxGlobalData.m_nBitsPerPixel <= 8 || afxGlobalData.m_bIsBlackHighContrast)
	{
		CMFCVisualManagerOfficeXP::OnDrawComboDropButton (pDC, rect,
												bDisabled, bIsDropped,
												bIsHighlighted, pButton);
		return;
	}

	ASSERT_VALID(pDC);
	ASSERT_VALID (this);

	CPoint pointTriangle (
		rect.left + (rect.Width () - CMenuImages::Size ().cx) / 2 + 1,
		rect.top + (rect.Height () - CMenuImages::Size ().cy) / 2 + 1);

	if (!bDisabled)
	{
		COLORREF clr1 = m_clrComboBoxBtnRegularF;
		COLORREF clr2 = m_clrComboBoxBtnRegularL;
		COLORREF clrB = m_clrComboBoxBtnRegularBorder;

		if (bIsHighlighted)
		{
			clr1 = m_clrComboBoxBtnHighlightedF;
			clr2 = m_clrComboBoxBtnHighlightedL;
			clrB = m_clrComboBoxBtnHighlightedBorder;
		}
		else if (bIsDropped)
		{
			clr1 = m_clrComboBoxBtnPressedF;
			clr2 = m_clrComboBoxBtnPressedL;
			clrB = m_clrComboBoxBtnPressedBorder;
		}

		CDrawingManager dm (*pDC);
		dm.FillGradient (rect, clr2, clr1, TRUE);

		pDC->Draw3dRect (rect, clrB, clrB);
	}

	CMenuImages::Draw (pDC, CMenuImages::IdArrowDown, pointTriangle,
		bDisabled ? CMenuImages::ImageGray : (bIsDropped && bIsHighlighted) ? 
			CMenuImages::ImageWhite : CMenuImages::ImageBlack);
}

void CMSMVisualManager::OnFillTasksPaneBackground(CDC* pDC, CRect rectWorkArea)
{
	CDrawingManager dm (*pDC);
	dm.FillGradient (rectWorkArea, RGB (203, 228, 252), RGB (226, 242, 254), FALSE);

	CPen penLeft (PS_SOLID, 1, RGB (188, 218, 247));
	CPen* pOldPen = pDC->SelectObject (&penLeft);

	pDC->MoveTo (rectWorkArea.right - 1, rectWorkArea.top);
	pDC->LineTo (rectWorkArea.right - 1, rectWorkArea.bottom);

	pDC->SelectObject (pOldPen);
}

void CMSMVisualManager::OnDrawTask(CDC* pDC, CMFCTasksPaneTask* pTask, 
									   CImageList* pIcons, BOOL bIsHighlighted, BOOL bIsSelected)
{
	if (pTask != NULL)
	{
		pTask->m_clrText = pTask->m_clrTextHot = RGB (16, 37, 127);
	}

	CMFCVisualManagerOffice2003::OnDrawTask(pDC, pTask, pIcons, bIsHighlighted, bIsSelected);
}
