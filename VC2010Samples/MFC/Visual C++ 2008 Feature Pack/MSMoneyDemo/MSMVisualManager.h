// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMVisualManager.h : header file
//

class CMSMVisualManager : public CMFCVisualManagerOffice2003
{
	DECLARE_DYNCREATE(CMSMVisualManager)

// Construction
public:
	CMSMVisualManager();

	virtual ~CMSMVisualManager();

	virtual void MSMDrawCaptionButton (CDC* pDC, CRect rect, AFX_BUTTON_STATE state, UINT id);

	void SetupMemoryBitmapSize (CDC* pDC, const CSize& size);

	BOOL LoadMSMCaptionButtonsIcons (LPCTSTR lpszID);

	const CSize& GetMSMCaptionButtonsSize () const;

protected:
	virtual void OnUpdateSystemColors ();

	virtual void OnDrawSeparator (CDC* pDC, CBasePane* pBar,
							  CRect rect, BOOL bHorz);

	virtual COLORREF GetToolbarButtonTextColor (CMFCToolBarButton* pButton,
										 CMFCVisualManager::AFX_BUTTON_STATE state);

	virtual void OnFillBarBackground (CDC* pDC, CBasePane* pBar,
					 CRect rectClient, CRect rectClip, BOOL bNCArea = FALSE);

	virtual void OnFillHighlightedArea (CDC* pDC, CRect rect, 
						 CBrush* pBrush, CMFCToolBarButton* pButton);

	virtual void OnDrawMenuBorder (CDC* pDC, CMFCPopupMenu* pMenu, CRect rect);

	virtual void OnDrawButtonBorder (CDC* pDC,
						 CMFCToolBarButton* pButton, CRect rect, AFX_BUTTON_STATE state);

	virtual void OnHighlightMenuItem (CDC*pDC, CMFCToolBarMenuButton* pButton,
								 CRect rect, COLORREF& clrText);

	virtual void OnDrawComboBorder (CDC* pDC, CRect rect,
									 BOOL bDisabled,
									 BOOL bIsDropped,
									 BOOL bIsHighlighted,
									 CMFCToolBarComboBoxButton* pButton);

	virtual void OnDrawComboDropButton (CDC* pDC, CRect rect,
									 BOOL bDisabled,
									 BOOL bIsDropped,
									 BOOL bIsHighlighted,
									 CMFCToolBarComboBoxButton* pButton);

	virtual void OnFillTasksPaneBackground(CDC* pDC, CRect rectWorkArea);
	virtual void OnFillTasksGroupInterior(CDC* /*pDC*/, CRect /*rect*/, BOOL /*bSpecial*/ = FALSE) {}
	virtual void OnDrawTasksGroupAreaBorder(CDC* /*pDC*/, CRect /*rect*/, BOOL /*bSpecial*/ = FALSE, BOOL /*bNoTitle*/ = FALSE) {}
	virtual void OnDrawTask(CDC* pDC, CMFCTasksPaneTask* pTask, CImageList* pIcons, BOOL bIsHighlighted = FALSE, BOOL bIsSelected = FALSE);

private:
	CSize	   m_MemorySize;
	CDC 	   m_MemoryDC;
	CBitmap    m_MemoryBitmap;
	BOOL	   m_MemoryFilled;

	CImageList m_CaptionButtonIconst;
	CSize	   m_CaptionButtonSize;

	CBitmap    m_MSMFrameBitmap;
	CBitmap    m_MSMViewBitmap;

	CBrush	   m_brMenuBarButtonHighlighted;
	COLORREF   m_clrMenuBarButtonBorderHighlighted;

	COLORREF   m_clrMenuBarButtonTextRegular;
	COLORREF   m_clrMenuBarButtonTextPressed;
	COLORREF   m_clrMenuBarButtonTextHighlighted;

	COLORREF   m_clrToolBarButtonTextRegular;
	COLORREF   m_clrToolBarButtonTextPressed;
	COLORREF   m_clrToolBarButtonTextHighlighted;

	COLORREF   m_clrCategorieBarButtonTextRegular;
	COLORREF   m_clrCategorieBarButtonTextPressed;
	COLORREF   m_clrCategorieBarButtonTextHighlighted;

	COLORREF   m_clrToolBarSeparatorS;
	COLORREF   m_clrToolBarSeparatorM;
	COLORREF   m_clrToolBarSeparatorF;

	COLORREF   m_clrComboBoxBorder;

	COLORREF   m_clrComboBoxBtnRegularF;
	COLORREF   m_clrComboBoxBtnRegularL;
	COLORREF   m_clrComboBoxBtnRegularBorder;
	COLORREF   m_clrComboBoxBtnHighlightedF;
	COLORREF   m_clrComboBoxBtnHighlightedL;
	COLORREF   m_clrComboBoxBtnHighlightedBorder;
	COLORREF   m_clrComboBoxBtnPressedF;
	COLORREF   m_clrComboBoxBtnPressedL;
	COLORREF   m_clrComboBoxBtnPressedBorder;

	COLORREF   m_clrCategorieBarButtonBorder;
	COLORREF   m_clrCategorieBarButtonBorderM;
	COLORREF   m_clrCategorieBarButtonLine;
	COLORREF   m_clrCategorieBarButtonF;
	COLORREF   m_clrCategorieBarButtonL;

	CBrush	   m_brLinksBarBack;
	CBrush	   m_brLinksBarButtonHighlighted;
	COLORREF   m_clrLinksBarButtonBorderHighlighted;
};


inline
const CSize&
CMSMVisualManager::GetMSMCaptionButtonsSize () const
{
	return m_CaptionButtonSize;
}
