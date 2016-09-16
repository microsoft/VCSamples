// licenppg.h : Declaration of the CLicensedPropPage property page class.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

////////////////////////////////////////////////////////////////////////////
// CLicensedPropPage : See licenppg.cpp for implementation.

class CLicensedPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLicensedPropPage)
	DECLARE_OLECREATE_EX(CLicensedPropPage)

// Constructor
public:
	CLicensedPropPage();

// Dialog Data
	//{{AFX_DATA(CLicensedPropPage)
	enum { IDD = IDD_PROPPAGE_LICENSED };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CLicensedPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
