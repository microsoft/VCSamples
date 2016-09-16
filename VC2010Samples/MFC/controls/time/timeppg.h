// timeppg.h : Declaration of the CTimePropPage property page class.
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
// CTimePropPage : See timeppg.cpp for implementation.

class CTimePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTimePropPage)
	DECLARE_OLECREATE_EX(CTimePropPage)

// Constructor
public:
	CTimePropPage();

// Dialog Data
	//{{AFX_DATA(CTimePropPage)
	enum { IDD = IDD_PROPPAGE_TIME };
	BOOL    m_Enabled;
	int     m_Interval;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTimePropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
