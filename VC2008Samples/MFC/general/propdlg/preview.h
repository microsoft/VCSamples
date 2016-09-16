// preview.h : interface of the CShapePreviewWnd class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CModalShapePropSheet;

class CShapePreviewWnd : public CWnd
{
	friend class CModalShapePropSheet;

	CShapePreviewWnd();

	//{{AFX_MSG(CShapePreviewWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
