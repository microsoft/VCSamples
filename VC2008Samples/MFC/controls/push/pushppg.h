// pushppg.h : Declaration of the CPushPropPage property page class.
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
// CPushPropPage : See pushppg.cpp for implementation.

class CPushPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPushPropPage)
	DECLARE_OLECREATE_EX(CPushPropPage)

// Constructor
public:
	CPushPropPage();

// Dialog Data
	//{{AFX_DATA(CPushPropPage)
	enum { IDD = IDD_PROPPAGE_PUSH };
	BOOL    m_Border;
	CString m_Caption;
	BOOL    m_Enabled;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CPushPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
