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

class CRibbonListButton : public CMFCRibbonGallery
{
	DECLARE_DYNCREATE(CRibbonListButton)

	// Construction:
public:
	CRibbonListButton();
	CRibbonListButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex, BOOL    bRightAlignedText = TRUE);
	CRibbonListButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex, UINT uiImagesPaletteResID, int cxPaletteImage, const CStringArray& arLabels, BOOL bRightAlignedText = TRUE);

	virtual ~CRibbonListButton();

public:
	void AddGroup(LPCTSTR lpszGroupName, UINT uiImagesPaletteResID, int cxPaletteImage, const CStringArray& arLabels);

	virtual void Clear();

	void SetRightAlignedText(BOOL bSet = TRUE);

protected:
	virtual CSize GetIconSize() const;
	virtual void OnDrawPaletteIcon(CDC* pDC, CRect rectIcon, int nIconIndex, CMFCRibbonGalleryIcon* pIcon, COLORREF clrText);
	virtual void CopyFrom(const CMFCRibbonBaseElement& src);
	virtual void OnShowPopupMenu();

	virtual BOOL IsItemMenuLook() const
	{
		return m_bRightAlignedText;
	}

	void RecalcTextSizes(CDC* pDC);

protected:
	CMFCToolBarImages m_listImages;
	CStringArray m_arLabels;
	CSize m_sizeMargins;
	BOOL m_bRightAlignedText;
	CSize m_sizeMaxText;
};

