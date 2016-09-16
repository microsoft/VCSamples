// xlistppg.h : Declaration of the CXlistPropPage property page class.
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
// CXlistPropPage : See xlistppg.cpp for implementation.

class CXlistPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CXlistPropPage)
	DECLARE_OLECREATE_EX(CXlistPropPage)

// Constructor
public:
	CXlistPropPage();

// Dialog Data
	//{{AFX_DATA(CXlistPropPage)
	enum { IDD = IDD_PROPPAGE_XLIST };
	BOOL    m_InvertFlag;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CXlistPropPage)
		//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
