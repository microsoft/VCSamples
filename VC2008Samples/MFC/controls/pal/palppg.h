// palppg.h : Declaration of the CPalPropPage property page class.
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
// CPalPropPage : See palppg.cpp for implementation.

class CPalPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPalPropPage)
	DECLARE_OLECREATE_EX(CPalPropPage)

// Constructor
public:
	CPalPropPage();

// Dialog Data
	//{{AFX_DATA(CPalPropPage)
	enum { IDD = IDD_PROPPAGE_PAL };
	int     m_Length;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CPalPropPage)
		//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
