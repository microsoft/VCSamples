// bounce.h : Declares the class interfaces for the Bounce child window.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

#ifndef __BOUNCE_H__
#define __BOUNCE_H__

/////////////////////////////////////////////////////////////////////////////

class CBounceWnd : public CMDIChildWnd
{
private:
	using CMDIChildWnd::Create;

public:
	CBounceWnd();
	BOOL Create(LPCTSTR szTitle, LONG style = 0,
				const RECT& rect = rectDefault,
				CMDIFrameWnd* pParent = NULL);

// Implementation
protected:
	static CMenu NEAR menu;     // menu for all BOUNCE windows

	// bounce window client area and bouncing ball color/size parameters
	UINT m_nIDColor;
	COLORREF m_clrBall;

	BOOL m_bFastSpeed;          // current speed

	CPoint m_ptPixel;           // pixel size
	CSize m_sizeRadius;         // radius of ball
	CSize m_sizeMove;           // move speed
	CSize m_sizeTotal;          // total size for ball bitmap
	CPoint m_ptCenter;          // current center for the ball

	// for replicating bouncing ball
	CBitmap m_bmBall;

	void MakeNewBall();
	void ChangeSpeed();

	// message handlers
	//{{AFX_MSG(CBounceWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUpdateColor(CCmdUI* pCmdUI);
	afx_msg void OnColor();
	afx_msg void OnCustomColor();
	afx_msg void OnUpdateSlow(CCmdUI* pCmdUI);
	afx_msg void OnSlow();
	afx_msg void OnUpdateFast(CCmdUI* pCmdUI);
	afx_msg void OnFast();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // __BOUNCE_H__
