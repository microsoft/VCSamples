// ObjOne.h : header file
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

/////////////////////////////////////////////////////////////////////////////
// CObjectOne command target

class CObjectOne : public CCmdTarget
{
	DECLARE_DYNCREATE(CObjectOne)

	CObjectOne();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CObjectOne)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CObjectOne();

	// Generated message map functions
	//{{AFX_MSG(CObjectOne)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CObjectOne)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CObjectOne)
	afx_msg BSTR SayHello();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
