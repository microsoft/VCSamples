// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// OptionsPane.cpp : implementation file
//

#include "stdafx.h"
#include "GestureDemo.h"
#include "OptionsPane.h"

// COptionsPane

IMPLEMENT_DYNAMIC(COptionsPane, CPaneDialog)

COptionsPane::COptionsPane()
{
	m_bGestureZoom = FALSE;
	m_bGestureRotation = FALSE;
	m_bGesture2FingerTap = FALSE;
	m_bGesturePressAndTap = FALSE;
	m_bGesturePanlAll = FALSE;
	m_bGesturePanVert = FALSE;
	m_bGestureHorz = FALSE;
	m_bGesturePanGutter = FALSE;
	m_bGesturePanInertia = FALSE;
}

COptionsPane::~COptionsPane()
{
}


BEGIN_MESSAGE_MAP(COptionsPane, CPaneDialog)
	ON_COMMAND(IDC_PAN_GESTURE_ALL, &COptionsPane::OnPanGestureAll)
	ON_COMMAND_RANGE(IDC_ZOOM_GESTURE, IDC_PAN_WITH_INTERTIA, &COptionsPane::OnApplyGestureConfig)
END_MESSAGE_MAP()

// COptionsPane message handlers

void COptionsPane::DoDataExchange(CDataExchange* pDX)
{
	CPaneDialog::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_ZOOM_GESTURE, m_bGestureZoom);
	DDX_Check(pDX, IDC_ROTATION_GESTURE, m_bGestureRotation);
	DDX_Check(pDX, IDC_2FINGER_TAP_GESTURE, m_bGesture2FingerTap);
	DDX_Check(pDX, IDC_PRESS_AND_TAP_GESTURE, m_bGesturePressAndTap);
	DDX_Check(pDX, IDC_PAN_GESTURE_ALL, m_bGesturePanlAll);
	DDX_Check(pDX, IDC_PAN_WITH_SINGLE_FINGER_VERTICALLY, m_bGesturePanVert);
	DDX_Check(pDX, IDC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY, m_bGestureHorz);
	DDX_Check(pDX, IDC_PAN_WITH_GUTTER, m_bGesturePanGutter);
	DDX_Check(pDX, IDC_PAN_WITH_INTERTIA, m_bGesturePanInertia);
}


void COptionsPane::OnApplyGestureConfig(UINT /*nCmd*/)
{
	UpdateData();

	CView* pView = GetTopLevelFrame()->GetActiveView();
	if (pView == NULL)
	{
		ASSERT(FALSE);
		return;
	}
	
	CGestureConfig config;

	config.EnableZoom(m_bGestureZoom);
	config.EnableRotate(m_bGestureRotation);
	config.EnablePressAndTap(m_bGesturePressAndTap);
	config.EnableTwoFingerTap(m_bGesture2FingerTap);

	DWORD dwPanFlags = 0;

	if (m_bGestureHorz)
	{
		dwPanFlags |= GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY;
	}

	if (m_bGesturePanVert)
	{
		dwPanFlags |= GC_PAN_WITH_SINGLE_FINGER_VERTICALLY;
	}

	if (m_bGesturePanGutter)
	{
		dwPanFlags |= GC_PAN_WITH_GUTTER;
	}

	if (m_bGesturePanInertia)
	{
		dwPanFlags |= GC_PAN_WITH_INERTIA;
	}

	config.EnablePan(m_bGesturePanlAll, dwPanFlags);

	pView->SetGestureConfig(&config);
}


void COptionsPane::OnResetGestureConfig(CWnd* pWnd)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pWnd);

	CGestureConfig config;	// Default configuration

	m_bGestureZoom = config.IsZoomEnabled();
	m_bGestureRotation = config.IsRotateEnabled();
	m_bGesture2FingerTap = config.IsTwoFingerTapEnabled();
#if defined(GID_PRESSANDTAP) && defined(GC_PRESSANDTAP)
	m_bGesturePressAndTap = config.IsPressAndTapEnabled();
#endif
	m_bGesturePanlAll = config.IsPanAllEnabled();
	m_bGesturePanVert = config.IsPanVerticalEnabled();
	m_bGestureHorz = config.IsPanHorizontalEnabled();
	m_bGesturePanGutter = config.IsPanWithGutterEnabled();
	m_bGesturePanInertia = config.IsPanWithInertiaEnabled();

	UpdateData(FALSE);
	OnPanGestureAll();

	pWnd->SetGestureConfig(&config);
}

void COptionsPane::OnPanGestureAll()
{
	UpdateData();

	for (UINT nCtrlID = IDC_PAN_WITH_SINGLE_FINGER_VERTICALLY; nCtrlID <= IDC_PAN_WITH_INTERTIA; nCtrlID++)
	{
		GetDlgItem(nCtrlID)->EnableWindow(m_bGesturePanlAll);
	}

	OnApplyGestureConfig(IDC_PAN_GESTURE_ALL);
}
