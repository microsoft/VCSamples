// ImagePpg.h : Declaration of the CImagePropPage property page class.
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
// CImagePropPage : See ImagePpg.cpp for implementation.

class CImagePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CImagePropPage)
	DECLARE_OLECREATE_EX(CImagePropPage)

// Constructor
public:
	CImagePropPage();

// Dialog Data
	//{{AFX_DATA(CImagePropPage)
	enum { IDD = IDD_PROPPAGE_IMAGE };
	CString m_strImagePath;
	BOOL    m_bAutoSize;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CImagePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
