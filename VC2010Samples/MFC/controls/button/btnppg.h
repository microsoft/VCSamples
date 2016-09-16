// btnppg.h : Declaration of the CButtonPropPage property page class.
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
// CButtonPropPage : See btnppg.cpp for implementation.

class CButtonPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CButtonPropPage)
	DECLARE_OLECREATE_EX(CButtonPropPage)

// Constructor
public:
	CButtonPropPage();

// Dialog Data
	//{{AFX_DATA(CButtonPropPage)
	enum { IDD = IDD_PROPPAGE_BUTTON };
	CString m_Caption;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CButtonPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
