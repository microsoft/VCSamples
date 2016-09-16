// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CLineStyleMenuItem : public CMFCToolBarMenuButton  
{
	DECLARE_DYNCREATE(CLineStyleMenuItem)

public:
	CLineStyleMenuItem(int nWidth = 1, UINT uiCmdID = 0, LPCTSTR lpszText = NULL,
						BOOL bIsChecked = FALSE);
	virtual ~CLineStyleMenuItem();

protected:
	virtual void OnDraw (CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages,
						BOOL bHorz = TRUE, BOOL bCustomizeMode = FALSE,
						BOOL bHighlight = FALSE,
						BOOL bDrawBorder = TRUE,
						BOOL bGrayDisabledButtons = TRUE);

	virtual void CopyFrom (const CMFCToolBarButton& src);
	virtual SIZE OnCalculateSize (CDC* pDC, const CSize& sizeDefault, BOOL bHorz);

	int	m_nWidth;	// Line width
};
