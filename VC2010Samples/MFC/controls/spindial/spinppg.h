// spinppg.h : Declaration of the CSpindialPropPage property page class.
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
// CSpindialPropPage : See spinppg.cpp for implementation.

class CSpindialPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSpindialPropPage)
	DECLARE_OLECREATE_EX(CSpindialPropPage)

// Constructor
public:
	CSpindialPropPage();

// Dialog Data
	//{{AFX_DATA(CSpindialPropPage)
	enum { IDD = IDD_PROPPAGE_SPINDIAL };
	int     m_NeedlePosition;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CSpindialPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
