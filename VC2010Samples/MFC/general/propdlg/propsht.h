// propsht.h : interface of the CModalShapePropSheet class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CModalShapePropSheet : public CPropertySheet
{
public:
	DECLARE_DYNAMIC(CModalShapePropSheet)
	CModalShapePropSheet(CWnd* pWndParent = NULL);

// Attributes
	CStylePage m_stylePage;
	CColorPage m_colorPage;
	CShapePreviewWnd m_wndPreview;

// Operations
	void SetSheetPropsFromShape(CShape* pShape);
	void SetShapePropsFromSheet(CShape* pShape);
	void UpdateShapePreview();

// Overrides
	virtual BOOL OnInitDialog();

// Message Handlers
protected:
	//{{AFX_MSG(CModalShapePropSheet)
	afx_msg void OnApplyNow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
