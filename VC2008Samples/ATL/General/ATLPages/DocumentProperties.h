// DocumentProperties.h : Declaration of the CDocumentProperties

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#pragma once

#include "resource.h"       // main symbols

// MSO.dll
#import <libid:2DF8D04C-5BFA-101B-BDE5-00AA0044DE52> version("2.2") \
	rename("RGB", "Rgb")	\
	rename("DocumentProperties", "documentProperties")	\
	rename("DocProperties", "docProperties")	\
	rename("ReplaceText", "replaceText")	\
	rename("FindText", "findText")	\
	rename("GetObject", "getObject")	\
	raw_interfaces_only

// dte.olb
#import <libid:80CC9F66-E7D8-4DDD-85B6-D9E6CD0E93E2> \
	inject_statement("using namespace Office;")	\
	rename("ReplaceText", "replaceText")	\
	rename("FindText", "findText")	\
	rename("GetObject", "getObject")	\
	rename("SearchPath", "searchPath")	\
	raw_interfaces_only

// CDocumentProperties
class ATL_NO_VTABLE CDocumentProperties :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDocumentProperties, &CLSID_DocProperties>,
	public IPropertyPageImpl<CDocumentProperties>,
	public CDialogImpl<CDocumentProperties>
{
public:
	CDocumentProperties() 
	{
		m_dwTitleID = IDS_TITLEDocumentProperties;
		m_dwHelpFileID = IDS_HELPFILEDocumentProperties;
		m_dwDocStringID = IDS_DOCSTRINGDocumentProperties;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

	enum {IDD = IDD_DOCUMENTPROPERTIES};

DECLARE_REGISTRY_RESOURCEID(IDR_DOCUMENTPROPERTIES)


BEGIN_COM_MAP(CDocumentProperties) 
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CDocumentProperties)
	COMMAND_HANDLER(IDC_NAME, EN_CHANGE, OnUIChange)
	COMMAND_HANDLER(IDC_READONLY, BN_CLICKED, OnUIChange)
	CHAIN_MSG_MAP(IPropertyPageImpl<CDocumentProperties>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	// Respond to changes in the UI to update the dirty status of the page
	LRESULT OnUIChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		wNotifyCode; wID; hWndCtl; bHandled;
		SetDirty(true);
		return 0;
	}

	typedef IPropertyPageImpl<CDocumentProperties> PPGBaseClass;
	CComBSTR m_bstrFullName;	// Used to keep track of the original name
	VARIANT_BOOL m_bReadOnly;	// Used to keep track of the original read-only state

	STDMETHOD(SetObjects)(ULONG nObjects, IUnknown** ppUnk)
	{
		// Use SetObjects to perform basic sanity checks on the objects whose properties will be set

		// This page can only handle a single object
		// and that object must support the EnvDTE::Document interface.
		// We return E_INVALIDARG in any other situation

		HRESULT hr = E_INVALIDARG;
		if (nObjects == 1)								// Single object
		{
			CComQIPtr<EnvDTE::Document> pDoc(ppUnk[0]);	// Must support EnvDTE::Document
			if (pDoc)
				hr = PPGBaseClass::SetObjects(nObjects, ppUnk);
		}
		return hr;
	}
			
	STDMETHOD(Activate)(HWND hWndParent, LPCRECT prc, BOOL bModal)
	{
		// If we don't have any objects, this method should not be called
		// Note that OleCreatePropertyFrame will call Activate even if a call to SetObjects fails, so this check is required
		if (!m_ppUnk)
			return E_UNEXPECTED;

		// Use Activate to update the property page's UI with information
		// obtained from the objects in the m_ppUnk array

		// We update the page to display the Name and ReadOnly properties of the document

		// Call the base class
		HRESULT hr = PPGBaseClass::Activate(hWndParent, prc, bModal);
		if (FAILED(hr))
			return hr;

		// Get the EnvDTE::Document pointer
		CComQIPtr<EnvDTE::Document> pDoc(m_ppUnk[0]);
		if (!pDoc)
			return E_UNEXPECTED;
		
		// Get the FullName property
		hr = pDoc->get_FullName(&m_bstrFullName);
		if (FAILED(hr))
			return hr;

		// Set the text box so that the user can see the document name
		USES_CONVERSION;
		SetDlgItemText(IDC_NAME, CW2CT(m_bstrFullName));

		// Get the ReadOnly property
		m_bReadOnly = VARIANT_FALSE;
		hr = pDoc->get_ReadOnly(&m_bReadOnly);
		if (FAILED(hr))
			return hr;

		// Set the check box so that the user can see the document's read-only status
		CheckDlgButton(IDC_READONLY, m_bReadOnly ? BST_CHECKED : BST_UNCHECKED);

		return hr;
	}

	STDMETHOD(Apply)(void)
	{
		// If we don't have any objects, this method should not be called
		if (!m_ppUnk)
			return E_UNEXPECTED;

		// Use Apply to validate the users settings and update the objects' properties

		// Check whether we need to update the object
		// Quite important since standard property frame calls Apply when it doesn't need to
		if (!m_bDirty)
			return S_OK;
		
		HRESULT hr = E_UNEXPECTED;

		// Get a pointer to the document
		CComQIPtr<EnvDTE::Document> pDoc(m_ppUnk[0]);
		if (!pDoc)
			return hr;
		
		// Get the read-only setting
		VARIANT_BOOL bReadOnly = IsDlgButtonChecked(IDC_READONLY) ? VARIANT_TRUE : VARIANT_FALSE;

		// Get the file name
		CComBSTR bstrName;
		if (!GetDlgItemText(IDC_NAME, bstrName.m_str))
			return E_FAIL;

		// Set the read-only property
		if (bReadOnly != m_bReadOnly)
		{
			hr = pDoc->put_ReadOnly(bReadOnly);
			if (FAILED(hr))
				return hr;
		}

		// Save the document
		if (bstrName != m_bstrFullName)
		{
			EnvDTE::vsSaveStatus status;
			hr = pDoc->Save(bstrName, &status);
			if (FAILED(hr))
				return hr;
		}

		// Clear the dirty status of the property page
		SetDirty(false);

		return S_OK;
	}
};


OBJECT_ENTRY_AUTO(__uuidof(DocProperties), CDocumentProperties)
