// varassoc.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc command target

class CVariantAssoc : public CCmdTarget
{
	DECLARE_DYNCREATE(CVariantAssoc)

// Constructors
public:
	CVariantAssoc();           // protected constructor used by dynamic creation

// Attributes
public:
	COleVariant m_varKey;
	COleVariant m_varValue;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVariantAssoc)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CVariantAssoc();

	// Generated message map functions
	//{{AFX_MSG(CVariantAssoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CVariantAssoc)
	afx_msg VARIANT GetKey();
	afx_msg VARIANT GetValue();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
