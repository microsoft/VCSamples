// propsht2.h : interface of the CModelessShapePropSheet class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CModelessShapePropSheet;

class CModelessShapePropSheet : public CPropertySheet
{
public:
	DECLARE_DYNAMIC(CModelessShapePropSheet)
	CModelessShapePropSheet(CWnd* pWndParent);

// Attributes
	CStylePage m_stylePage;
	CColorPage m_colorPage;

// Operations
	void SetSheetPropsFromShape(CShape* pShape);
	void SetShapePropsFromSheet(CShape* pShape);

// Overrides
	virtual void PostNcDestroy();

// Message Handlers
protected:
	//{{AFX_MSG(CModelessShapePropSheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
