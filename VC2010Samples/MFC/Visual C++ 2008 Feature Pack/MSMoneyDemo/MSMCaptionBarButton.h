// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMCaptionBarButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMSMCaptionBarButton window

class CMSMCaptionBarButton : public CMFCButton
{
	DECLARE_DYNCREATE(CMSMCaptionBarButton);

public:
	CMSMCaptionBarButton ();

	virtual ~CMSMCaptionBarButton ();

	UINT GetSysCommand () const;

	void SetSysCommand (UINT uiSysCommand);

protected:
	virtual void OnDraw (CDC* pDC, const CRect& rect, UINT uiState);

protected:
	DECLARE_MESSAGE_MAP()
};
