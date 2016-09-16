// preview.cpp : implementation of the CModalShapePropSheet class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "preview.h"
#include "resource.h"
#include "colorpge.h"
#include "stylepge.h"
#include "shapeobj.h"
#include "propsht.h"

BEGIN_MESSAGE_MAP(CShapePreviewWnd, CWnd)
//{{AFX_MSG_MAP(CShapePreviewWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CShapePreviewWnd::CShapePreviewWnd()
{
}

void CShapePreviewWnd::OnPaint()
{
	CPaintDC dc(this);
	CModalShapePropSheet* pShapePropSheet =
		STATIC_DOWNCAST(CModalShapePropSheet, GetParent());
	CRect rect;
	GetClientRect(rect);
	CShape shape(
		(SHAPE_COLOR_ENUM)pShapePropSheet->m_colorPage.m_nColor,
		(SHAPE_STYLE)pShapePropSheet->m_stylePage.m_nShapeStyle,
		rect);
	shape.Draw(&dc, FALSE);
}

BOOL CShapePreviewWnd::OnEraseBkgnd(CDC* pDC)
{
	// Use the same background color as that of the dialog
	//  (property sheet).

	CWnd* pParentWnd = GetParent();
	HBRUSH hBrush = (HBRUSH)pParentWnd->SendMessage(WM_CTLCOLORDLG,
		(WPARAM)pDC->m_hDC, (LPARAM)pParentWnd->m_hWnd);
	CRect rect;
	GetClientRect(rect);
	pDC->FillRect(&rect, CBrush::FromHandle(hBrush));
	return TRUE;
}
