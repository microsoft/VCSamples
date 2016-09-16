// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMCaptionBar.h : header file
//

#include "MSMCaptionBarButton.h"

/////////////////////////////////////////////////////////////////////////////
// CMSMCaptionBar window

static const UINT uiCaprionBarID = AFX_IDW_DIALOGBAR + 1;

class CMSMCaptionBar : public CPane
{
	DECLARE_DYNCREATE(CMSMCaptionBar)

// Construction
public:
	CMSMCaptionBar ();

	virtual ~CMSMCaptionBar ();
	
	virtual void SetIcon (HICON hIcon);

	void SetCaptionHeight (int nHeight);

	int GetCaptionHeight () const;

	void SetCaptionFont (const LOGFONT& lf);

	HFONT GetCaptionFont () const;

	virtual COLORREF GetCaptionTextColor () const;

	void SetParentActive (BOOL bParentActive = true);

	BOOL IsParentActive () const;

	void SetParentMaximize (BOOL bParentMaximize = true);

	BOOL IsParentMaximize () const;

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL Create(CWnd* pParentWnd, UINT nID = uiCaprionBarID);
	virtual BOOL CreateEx(CWnd* pParentWnd, UINT nID = uiCaprionBarID);
	virtual CSize CalcFixedLayout(BOOL, BOOL);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPaint(CDC* pDCPaint);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

protected:
	afx_msg LRESULT OnSetText(WPARAM, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

	virtual UINT HitTest (const CPoint& pt) const;
	virtual void ShowSysMenu (const CPoint& point);

public:
	CString 				 m_strCaption;

	HICON					 m_hIcon;
	CSize					 m_szIcon;

	BOOL					 m_bParentActive;
	BOOL					 m_bParentMaximize;

	int						 m_SystemHeight;
	int						 m_CaptionHeight;
	CFont					 m_CaptionFont;

	CMSMCaptionBarButton m_BtnMinimize;
	CMSMCaptionBarButton m_BtnMaximize;
	CMSMCaptionBarButton m_BtnClose;
};


inline
int CMSMCaptionBar::GetCaptionHeight () const
{
	return m_CaptionHeight;
}


inline
HFONT CMSMCaptionBar::GetCaptionFont () const
{
	return (HFONT)m_CaptionFont.GetSafeHandle ();
}


inline
BOOL CMSMCaptionBar::IsParentActive () const
{
	return m_bParentActive;
}


inline
BOOL CMSMCaptionBar::IsParentMaximize () const
{
	return m_bParentMaximize;
}
