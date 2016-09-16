// localppg.h : Declaration of the CLocalizePropPage property page class.
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
// CLocalizePropPage : See localppg.cpp for implementation.

class CLocalizePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLocalizePropPage)
	DECLARE_OLECREATE_EX(CLocalizePropPage)

// Constructor
public:
	CLocalizePropPage();

// Dialog Data
	//{{AFX_DATA(CLocalizePropPage)
	enum { IDD = IDD_PROPPAGE_LOCALIZE };
	BOOL    m_Invert;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual void OnSetPageSite();
	virtual void OnFinalRelease();
	virtual HINSTANCE GetResourceHandle(LCID lcid);

// Message maps
protected:
	//{{AFX_MSG(CLocalizePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	HINSTANCE hResHandle;
};
