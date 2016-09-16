
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

//	virtual BOOL OnDraw2D(CHwndRenderTarget& renderTarget);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg LRESULT OnDraw2D(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

    CD2DTextFormat*	m_pTextFormat;
	CD2DSolidColorBrush* m_pBlackBrush;
};

