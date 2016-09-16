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

#define IDC_BOUNCE_WND 1

// COnCmdMsg struct is used to pass the OnCmdMsg parameters via SendMessage
// from the CBounceMDIChildWnd in the main application thread to the
// CBounceWnd in the separate u/i thread.
struct COnCmdMsg
{
	int m_nID;
	int m_nCode;
	void* m_pExtra;
	AFX_CMDHANDLERINFO* m_pHandlerInfo;
};

#define WM_USER_ONCMDMSG (WM_USER + 0x1000)
#define WM_USER_PREPARE_TO_CLOSE (WM_USER + 0x1001)

/////////////////////////////////////////////////////////////////////////////
// A CBounceWnd is a child window of the CBounceMDIChildWnd.
// The CBounceMDIChildWnd executes in the same thread as that of the
// CMainFrame (CMDIFrameWnd), which is the main application thread.

class CBounceMDIChildWnd : public CMDIChildWnd
{
private:
	using CMDIChildWnd::Create;

public:
	CBounceMDIChildWnd();
	BOOL Create(LPCTSTR szTitle, LONG style = 0,
			const RECT& rect = rectDefault,
			CMDIFrameWnd* pParent = NULL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBounceMDIChildWnd)
	public:
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo);
	static CMenu NEAR menu;     // menu for all BOUNCE windows

	// message handlers
	//{{AFX_MSG(CBounceMDIChildWnd)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg LRESULT OnPrepareToClose(WPARAM wParam = 0, LPARAM lParam = 0);

	DECLARE_MESSAGE_MAP()
};

class CBounceWnd : public CWnd
{
private:
	using CWnd::Create;

	DECLARE_DYNAMIC(CBounceWnd)
public:
	CBounceWnd();
	BOOL Create(LPCTSTR szTitle, LONG style, const RECT& rect, CWnd* pParent);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBounceWnd)
	//}}AFX_VIRTUAL

// Implementation
protected:
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	afx_msg LRESULT OnDelegatedCmdMsg(WPARAM, LPARAM);
	afx_msg LRESULT OnPrepareToClose(WPARAM wParam = 0, LPARAM lParam = 0);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // __BOUNCE_H__
