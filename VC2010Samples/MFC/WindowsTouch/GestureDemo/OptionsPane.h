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


// COptionsPane

class COptionsPane : public CPaneDialog
{
	DECLARE_DYNAMIC(COptionsPane)

public:
	COptionsPane();
	virtual ~COptionsPane();

	void OnResetGestureConfig(CWnd* pWnd);

protected:
	afx_msg void OnPanGestureAll();
	afx_msg void OnApplyGestureConfig(UINT nCmdID);
	DECLARE_MESSAGE_MAP()

	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL m_bGestureZoom;
	BOOL m_bGestureRotation;
	BOOL m_bGesture2FingerTap;
	BOOL m_bGesturePressAndTap;
	BOOL m_bGesturePanlAll;
	BOOL m_bGesturePanVert;
	BOOL m_bGestureHorz;
	BOOL m_bGesturePanGutter;
	BOOL m_bGesturePanInertia;
};


