// localppg.cpp : Implementation of the CLocalizePropPage property page class.
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
#include "localize.h"
#include "localppg.h"

#ifdef _WIN32
  #include <winnt.h>
#else
  #include <olenls.h>
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CLocalizePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CLocalizePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CLocalizePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CLocalizePropPage, "LOCALIZE.LocalizePropPage.1",
	0x35e3e54, 0x6745, 0x101b, 0xb5, 0x7b, 0x0, 0x60, 0x8c, 0xc9, 0x6a, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::CLocalizePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CLocalizePropPage

BOOL CLocalizePropPage::CLocalizePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LOCALIZE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::CLocalizePropPage - Constructor

CLocalizePropPage::CLocalizePropPage() :
	COlePropertyPage(IDD, IDS_LOCALIZE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CLocalizePropPage)
	m_Invert = FALSE;
	//}}AFX_DATA_INIT

	hResHandle = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::DoDataExchange - Moves data between page and properties

void CLocalizePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CLocalizePropPage)
	DDP_Check(pDX, IDC_CHECK1, m_Invert, _T("Invert") );
	DDX_Check(pDX, IDC_CHECK1, m_Invert);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// Set the resource handle to the module which contains locale-specific
// resources

void CLocalizePropPage::OnSetPageSite()
{
	BOOL bError = FALSE;
	LCID lcid = 0;

	LPPROPERTYPAGESITE pSite = GetPageSite();
	if (pSite != NULL)
		pSite->GetLocaleID(&lcid);

	// Get the handle of the resource module
	hResHandle = GetResourceHandle(lcid);

	#ifdef _WIN32
		if (!hResHandle)
		bError = TRUE;
	#else
		if (hResHandle <= HINSTANCE_ERROR)
		bError = TRUE;
	#endif

	if (!bError)
	{
		// Use resources from resource module
		HINSTANCE hResPrev = AfxGetResourceHandle();
		AfxSetResourceHandle(hResHandle);
		COlePropertyPage::OnSetPageSite();
		AfxSetResourceHandle(hResPrev);
	}
	else
		// Use resources from control module
		COlePropertyPage::OnSetPageSite();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::OnFinalRelease - Frees locale-specific resource
// module, if any.

void CLocalizePropPage::OnFinalRelease()
{
	if (hResHandle != NULL)
	{
		FreeLibrary(hResHandle);
		hResHandle = NULL;
	}

	COlePropertyPage::OnFinalRelease();
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage::GetResourceHandle - Load module which contains
// locale-specific resources

HINSTANCE CLocalizePropPage::GetResourceHandle(LCID lcid)
{
	LPCTSTR lpszResModule = NULL;
	HINSTANCE hResHandle = NULL;

	// Use lcid to determine module that contains resources
	LANGID langID = LANGIDFROMLCID(lcid);
	unsigned short priLangID = (unsigned short) PRIMARYLANGID(langID);
	switch (priLangID)
	{
		case LANG_ENGLISH:
			break;
		case LANG_FRENCH:
			#ifdef _WIN32
				lpszResModule = (LPCTSTR)_T("lresfr32.dll");
			#else
				lpszResModule = (LPCTSTR)_T("locresfr.dll");
			#endif
			break;
		case LANG_GERMAN:
			#ifdef _WIN32
				lpszResModule = (LPCTSTR)_T("lresde32.dll");
			#else
				lpszResModule = (LPCTSTR)_T("locresde.dll");
			#endif
			break;
		case 0:
		default:
			 break;
	}

	// Load resource module
	if (lpszResModule != NULL)
		hResHandle = LoadLibrary(lpszResModule);

	return hResHandle;
}


/////////////////////////////////////////////////////////////////////////////
// CLocalizePropPage message handlers
