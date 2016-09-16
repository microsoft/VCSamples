// hello.h : Declares the class interfaces for the Hello child window.
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

#ifndef __HELLO_H__
#define __HELLO_H__

/////////////////////////////////////////////////////////////////////////////

// class CHelloWnd

class CHelloWnd : public CMDIChildWnd
{
private:
	using CMDIChildWnd::Create;

public:
	CHelloWnd();
	BOOL Create(LPCTSTR szTitle, LONG style = 0,
				const RECT& rect = rectDefault,
				CMDIFrameWnd* pParent = NULL);

// Implementation
protected:
	static CMenu NEAR menu;     // menu for all HELLO windows

	UINT m_nIDColor;
	COLORREF m_clrText;

	// message handlers
	//{{AFX_MSG(CHelloWnd)
	afx_msg void OnPaint();
	afx_msg void OnColor();
	afx_msg void OnCustomColor();
	afx_msg void OnUpdateColor(CCmdUI* pCmdUI);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif // __HELLO_H__
