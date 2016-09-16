// ImagePpg.cpp : Implementation of the CImagePropPage property page class.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "image.h"
#include "ImagePpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CImagePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CImagePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CImagePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CImagePropPage, "IMAGE.ImagePropPage.1",
	0x346685e4, 0xc383, 0x11cf, 0xa5, 0xa4, 0, 0xaa, 0, 0xa4, 0x57, 0x5)


/////////////////////////////////////////////////////////////////////////////
// CImagePropPage::CImagePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CImagePropPage

BOOL CImagePropPage::CImagePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_IMAGE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CImagePropPage::CImagePropPage - Constructor

CImagePropPage::CImagePropPage() :
	COlePropertyPage(IDD, IDS_IMAGE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CImagePropPage)
	m_strImagePath = _T("");
	m_bAutoSize = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CImagePropPage::DoDataExchange - Moves data between page and properties

void CImagePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CImagePropPage)
	DDP_Text(pDX, IDC_IMAGEPATH, m_strImagePath, _T("ImagePath") );
	DDX_Text(pDX, IDC_IMAGEPATH, m_strImagePath);
	DDP_Check(pDX, IDC_AUTOSIZE, m_bAutoSize, _T("AutoSize") );
	DDX_Check(pDX, IDC_AUTOSIZE, m_bAutoSize);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CImagePropPage message handlers
