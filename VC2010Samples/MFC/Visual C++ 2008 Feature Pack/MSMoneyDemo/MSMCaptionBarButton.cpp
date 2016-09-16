// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// MSMCaptionBarButton.cpp : implementation file
//

#include "stdafx.h"
#include "MSMCaptionBarButton.h"

#include "MSMVisualManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMCaptionBarButton

IMPLEMENT_DYNCREATE(CMSMCaptionBarButton, CMFCButton);

CMSMCaptionBarButton::CMSMCaptionBarButton ()
{
	m_bDrawFocus = FALSE;
}

CMSMCaptionBarButton::~CMSMCaptionBarButton ()
{
}

void CMSMCaptionBarButton::OnDraw (CDC* pDC, const CRect& /*rect*/, UINT /*uiState*/)
{
	CMSMVisualManager* pManager = DYNAMIC_DOWNCAST (CMSMVisualManager,
		CMFCVisualManager::GetInstance ());

	long nID = GetSysCommand ();

	if (pManager == NULL || nID == 0)
	{
		ASSERT (FALSE);
	}
	else
	{
		CRect rt;
		GetClientRect(rt);

		CMFCVisualManager::AFX_BUTTON_STATE state = 
			CMFCVisualManager::ButtonsIsRegular;

		if (m_bPushed)
		{
			state = CMFCVisualManager::ButtonsIsPressed;
		}
		else if (m_bHighlighted)
		{
			state = CMFCVisualManager::ButtonsIsHighlighted;
		}

		pManager->MSMDrawCaptionButton (pDC, rt, state, nID);
	}
}

UINT CMSMCaptionBarButton::GetSysCommand () const
{
    HWND hWnd = GetSafeHwnd();

    ASSERT(hWnd != NULL);

    if (hWnd != NULL)
    {
        return ::GetWindowLong (hWnd, GWL_ID);
    }

    return 0;
}

void CMSMCaptionBarButton::SetSysCommand (UINT uiSysCommand)
{
	HWND hWnd = GetSafeHwnd();

	ASSERT(hWnd != NULL);

	if (GetSysCommand () != uiSysCommand && hWnd != NULL)
	{
		::SetWindowLong (hWnd, GWL_ID, uiSysCommand);
	}
}

BEGIN_MESSAGE_MAP(CMSMCaptionBarButton, CMFCButton)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMCaptionBarButton message handlers
