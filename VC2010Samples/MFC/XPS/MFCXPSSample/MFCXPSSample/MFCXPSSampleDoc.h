
// MFCXPSSampleDoc.h : interface of the CMFCXPSSampleDoc class
//


#pragma once

class CMFCXPSSampleDoc;

static const DWORD gdwPrintSchemaVersion = 1;

class STATE_INFO
{
public:
	STATE_INFO()
	{
		m_hPrinter = NULL;
		m_hProvider = NULL;
	}

	~STATE_INFO()
	{
		ClearContent();
	}

	void ClearContent()
	{
		if (m_hPrinter)
    	{
        	ClosePrinter(m_hPrinter);
        	m_hPrinter = NULL;
    	}

    	if (m_hProvider)
    	{
        	PTCloseProvider(m_hProvider);
        	m_hProvider = NULL;
    	}

		m_strPrinterName.Empty();
	}

	HANDLE GetPrinter()
	{
		if (m_strPrinterName.IsEmpty())
		{
			return NULL;
		}

		if (m_hPrinter != NULL)
		{
			return m_hPrinter;
		}

		if (FAILED(OpenPrinter((LPTSTR)(LPCTSTR)m_strPrinterName, &m_hPrinter, NULL)))
		{
			return NULL;
		}

		return m_hPrinter;
	}

	HPTPROVIDER GetProvider()
	{
		if (m_strPrinterName.IsEmpty())
		{
			return NULL;
		}

		if (m_hProvider != NULL)
		{
			return m_hProvider;
		}

#ifdef _UNICODE
		LPCWSTR lpPrinterName = m_strPrinterName;
#else
		USES_CONVERSION;
		LPCWSTR lpPrinterName = A2W(m_strPrinterName);
#endif

		if (FAILED(PTOpenProvider((LPWSTR)lpPrinterName, gdwPrintSchemaVersion, &m_hProvider)))
		{
			return NULL;
		}

		return m_hProvider;
	}

	void SetPrinterName(LPCTSTR lpcszName)
	{
		ClearContent();
		m_strPrinterName = lpcszName;
	}

	LPCTSTR GetPrinterName () const {return m_strPrinterName;} 

protected:
	HANDLE          	m_hPrinter;
    HPTPROVIDER     	m_hProvider;
	CString			m_strPrinterName;
};

class CXPSPage
{
public:
	CXPSPage(CMFCXPSSampleDoc* pDoc);

	BOOL Create(XPS_SIZE pageSize, int nPageNumber);
	BOOL Initialize(IXpsOMPageReferenceCollection* pPageRefColl, int nPageNumber);
	BOOL InitializeGraphicsContent(XPS_MATRIX xpsMatrix);
	BOOL ReInitializeAllGraphicsContent(XPS_MATRIX xpsMatrix);
	BOOL SetPrintTicket(IStream* pPrintTicketStream);

	void SetFlags(BOOL bValue = FALSE);
	BOOL ClearCanvas(int nCanvasIndex = -1);

	BOOL GetPageLevelCanvas(IXpsOMCanvas** ppCanvas, int nCanvasIndex = -1);
	IXpsOMPage* GetPage() {return m_pFixedPage;}

	BOOL m_bTextAdded;
	BOOL m_bImageAdded;
	BOOL m_bGraphicsAdded;
	BOOL m_bPrintTicketAdded;

protected:
	CComPtr<IOpcPartUri>				m_pPageUri; //  required only for page creation, NULL for existing documets
	CComPtr<IXpsOMPage>				m_pFixedPage;
	CComPtr<IXpsOMPageReference>		m_pFixedPageRef;
	CComPtr<IXpsOMCanvas>			m_pCurrentCanvas;

	CMFCXPSSampleDoc* 				m_pParentDoc;
	BOOL								m_bInitialized;
	int								m_nPageNumber;
};


class CMFCXPSSampleDoc : public CDocument
{
protected: // create from serialization only
	CMFCXPSSampleDoc();
	DECLARE_DYNCREATE(CMFCXPSSampleDoc)

// Attributes
public:
	IXpsOMObjectFactory* 			GetXpsObjectFactory() {return m_pXpsObjectFactory;}
	IOpcFactory* 					GetOpcFactory() {return m_pOpcFactory;}
	IXpsOMPageReferenceCollection* 	GetPageRefColl() {return m_pFixedPageRefColl;}

// Operations
public:
	BOOL InitializeNewXPSDocument();
	BOOL InitializeExistingXPSDocument();

	BOOL GenerateNewPrintTicket(LPCTSTR lpcszPrinterName, IStream** ppNewPrintTicketStream);
	void PrintXPSFile();

	void AddPage();
	BOOL AddTextToXPSPage(CXPSPage* pPage);
	BOOL AddImageToXPSPage(CXPSPage* pPage, int nImageResID);
	BOOL AddGraphicsToXPSPage(CXPSPage* pPage);
	BOOL AddPrintTicketToXPSPage(CXPSPage* pPage);
	BOOL RemoveAllVisualElementsFromXPSPage(CXPSPage* pPage);

	BOOL IsXPSCapableDriver(HDC hdc);

	void UpdateDocumentContent();

	const CString& GetTempFile() const {return m_strTempFileName;}

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);

	virtual void DeleteContents();
// Implementation
public:
	virtual ~CMFCXPSSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL WriteToTempFile();

protected:
	CComPtr<IXpsOMObjectFactory>				m_pXpsObjectFactory;
	CComPtr<IOpcFactory>						m_pOpcFactory;
	CComPtr<IXpsOMPackage>					m_pXpsPackage;
	CComPtr<IXpsOMDocumentSequence>			m_pFixedDocSequence;
	CComPtr<IXpsOMDocument>					m_pFixedDoc;
	CComPtr<IXpsOMDocumentCollection>			m_pFixedDocColl;
	CComPtr<IXpsOMPageReferenceCollection>	m_pFixedPageRefColl;

	CComPtr<IOpcPartUri>						m_pDocUri;
	CComPtr<IOpcPartUri>						m_pDocSeqUri;

	CList<CXPSPage*, CXPSPage*>				m_pages;
	int										m_nPageCount;

	CString									m_strTempFileName; // used to display XPS document in HtmlView

// Generated message map functions
protected:
	afx_msg void OnAddText();
	afx_msg void OnUpdateAddText(CCmdUI* pCmdUI);
	afx_msg void OnAddImage();
	afx_msg void OnUpdateAddImage(CCmdUI* pCmdUI);
	afx_msg void OnAddGraphics();
	afx_msg void OnUpdateAddGraphics(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddPrintTicket(CCmdUI* pCmdUI);
	afx_msg void OnAddPrintTicket();
	afx_msg void OnRemoveAll();
	DECLARE_MESSAGE_MAP()

	BOOL AppendSimpleText(IXpsOMObjectFactory* pXpsFactory, IXpsOMFontResource* pXpsFont, float fFontEmSize, XPS_COLOR &xpsColor, 
							 float fOriginX, float fOriginY, LPCWSTR lpUnicodeString, IXpsOMCanvas* pXpsCanvas);
	BOOL GenerateNewFontPartUri(IOpcFactory *pOpcFactory, IOpcPartUri  **ppPartUri);
	void SetXPSColorToARGB(XPS_COLOR& xpsColor, COLORREF color, UINT8 alpha = 0xFF);
	BOOL LoadImageToStream(LPCTSTR lpcszImageResID, IStream** ppStream, LPCTSTR lpszType = _T("JPG"));
	BOOL CreateFontResourceForFont(LPCWSTR lpcszfontName, IXpsOMFontResource** pFontResource);

	// Methods to generate PrintTickets
	BOOL CreateNewPrintTicket(STATE_INFO* psi, IXMLDOMDocument2* pPrintCapsDOM, IStream* pBasePrintTicketStream, 
							IXMLDOMDocument2* pBasePrintTicketDOM, IStream** ppNewPrintTicketStream);
	BOOL GetUserPrintTicketStream(STATE_INFO* psi, IStream** ppStream);
	BOOL GetDevmodeFromDocProperty(STATE_INFO* psi, LPDEVMODEW *ppDevMode);
	BOOL ConvertDevmodeToPrintTicketStream(HPTPROVIDER hProvider, LPDEVMODEW pDevMode, IStream** ppPrintTicketStream);
	BOOL GetPrintCapsBasedOnPrintTicket(HPTPROVIDER hProvider, IStream* pPrintTicketStream, IStream** ppPrintCapsStream);

	// XML support for Print Tickets
	BOOL ConvertFullPrintTicketToMinimalPrintTicket(IXMLDOMDocument2* pPrintTicketDOM);
	BOOL IStreamToDOMDocument(IStream *pStream, IXMLDOMDocument2** ppXmlDocument);
	BOOL DOMDocumentToIStream(IXMLDOMDocument2* pDocument, IStream* pStream);
	BOOL GetNodeFromPrintCapsDOM(IXMLDOMDocument2* pPrintCapsDOM, LPCWSTR lpcszFeatureName, LPCWSTR lpcszOptionName, IXMLDOMNode** ppOutNote);
	BOOL XPathQueryOnPrintCaps(IXMLDOMDocument2* pPrintCapsDOM, BSTR bstrXPathQuery, IXMLDOMNodeList **ppIXMLDOMNodeList);
	BOOL MergeNodeIntoMinimalPrintTicket(IXMLDOMDocument2* pPrintTicketMinimal, IXMLDOMNode* pNode);
	BOOL CreatePTFeatureOptionNodeFromPrintCapOptionNode(IXMLDOMNode* pPrintCapsOptionNode, IXMLDOMNode** ppPrintTicketFeatureNode);
	BOOL ConvertPrintCapOptionNodeToPrintTicketOptionNode(IXMLDOMNode* pOptionNode);
	BOOL RemoveAllAttributesExceptNameFromOptionNode(IXMLDOMNode* pNode);
	BOOL RemoveAllChildrenWithProperty(IXMLDOMNode* pNode);

	BOOL SelectPrinter(CString& strPrinter);
};
