// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CMSMLinksBarButton : public CMFCToolBarButton  
{
	DECLARE_SERIAL(CMSMLinksBarButton)

public:
	CMSMLinksBarButton ();
	CMSMLinksBarButton (LPCTSTR lpszLabel, UINT nID);

	virtual ~CMSMLinksBarButton ();

	virtual void OnDraw (CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages,
					 BOOL bHorz = TRUE, BOOL bCustomizeMode = FALSE,
					 BOOL bHighlight = FALSE,
					 BOOL bDrawBorder = TRUE,
					 BOOL bGrayDisabledButtons = TRUE);

protected:
	void Initialize ();

	virtual BOOL IsEditable () const
				 {
					 return FALSE;
				 }

	virtual SIZE OnCalculateSize (
					 CDC* pDC,
					 const CSize& sizeDefault,
					 BOOL bHorz);
};
