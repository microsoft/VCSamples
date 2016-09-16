
// MFCXPSSampleDoc.cpp : implementation of the CMFCXPSSampleDoc class
//

#include "stdafx.h"
#include "resource.h"
#include "MFCXPSSample.h"

#include "MFCXPSSampleDoc.h"
#include "macros.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const XPS_SIZE pageSize = {816.0, 1056.0};
static const XPS_MATRIX xpsMatrix = { 1.333333333f, 0, 0, 1.333333333f, 0, 0 };
const CStringW g_szFontName = L"Arial";

// CXPSPage
CXPSPage::CXPSPage(CMFCXPSSampleDoc* pDoc) : m_pParentDoc(pDoc), m_bInitialized(FALSE), m_nPageNumber(-1)
{
	SetFlags();
	m_bPrintTicketAdded = FALSE;
}

void CXPSPage::SetFlags(BOOL bValue)
{
	m_bTextAdded = bValue;
	m_bImageAdded = bValue;
	m_bGraphicsAdded = bValue;
}

BOOL CXPSPage::Create(XPS_SIZE pageSize, int nPageNumber)
{
	IXpsOMObjectFactory* pObjectFactory = m_pParentDoc->GetXpsObjectFactory();
	IOpcFactory* pOpcFactory = m_pParentDoc->GetOpcFactory();
	IXpsOMPageReferenceCollection* pRefColl = m_pParentDoc->GetPageRefColl();

	if (pObjectFactory == NULL || pOpcFactory == NULL || pRefColl == NULL)
	{
		return FALSE;
	}

	static const CStringW strPartUriFormat = L"/Documents/1/Pages/%d.fpage";

	CStringW strPartUri;
	strPartUri.Format(strPartUriFormat, nPageNumber);

	IFC(pOpcFactory->CreatePartUri(strPartUri, &m_pPageUri));
	IFC(pObjectFactory->CreatePage(&pageSize, L"en-US", m_pPageUri, &m_pFixedPage));

	IFC(pObjectFactory->CreatePageReference(&pageSize, &m_pFixedPageRef));
    IFC(pRefColl->Append(m_pFixedPageRef));
    IFC(m_pFixedPageRef->SetPage(m_pFixedPage));

	m_nPageNumber = nPageNumber;

	return TRUE;
}

BOOL CXPSPage::Initialize(IXpsOMPageReferenceCollection* pPageRefColl, int nPageNumber)
{
	if (FAILED(pPageRefColl->GetAt(nPageNumber, &m_pFixedPageRef)))
	{
		return FALSE;
	}

	m_nPageNumber = nPageNumber;

	return SUCCEEDED(m_pFixedPageRef->GetPage(&m_pFixedPage));
}

BOOL CXPSPage::InitializeGraphicsContent(XPS_MATRIX xpsMatrix)
{
	if (m_bInitialized)
	{
		return TRUE;
	}

	CComPtr<IXpsOMVisualCollection> pPageVisuals;
	CComPtr<IXpsOMMatrixTransform> pTransform;

	IXpsOMObjectFactory* pObjectFactory = m_pParentDoc->GetXpsObjectFactory();

	if (pObjectFactory == NULL || m_pFixedPage == NULL)
	{
		return FALSE;
	}

	// Create a page-level canvas to contain all of our page content
	IFC(pObjectFactory->CreateCanvas(&m_pCurrentCanvas));
	IFC(m_pFixedPage->GetVisuals(&pPageVisuals));
	IFC(pPageVisuals->Append(m_pCurrentCanvas));

	// Set a transform on our canvas. Makes it easy to scale our content to the desired rendering size
    IFC(pObjectFactory->CreateMatrixTransform(&xpsMatrix, &pTransform));
    IFC(m_pCurrentCanvas->SetTransformLocal(pTransform));

	m_bInitialized = TRUE;

	return TRUE;
}

BOOL CXPSPage::SetPrintTicket(IStream* pPrintTicketStream)
{
	IXpsOMObjectFactory* pObjectFactory = m_pParentDoc->GetXpsObjectFactory();
	if (pObjectFactory == NULL || m_pFixedPage == NULL)
	{
		return FALSE;
	}

	if (pPrintTicketStream == NULL)
	{
		// clear print ticket resource
		IFC(m_pFixedPageRef->SetPrintTicketResource(NULL));
		m_bPrintTicketAdded = FALSE;
		return TRUE;
	}

	CStringW strPTPage;
	strPTPage.Format (L"/Documents/1/Metadata/Page%d_PT.xml", m_nPageNumber);

	CComPtr<IOpcPartUri> pPartUri;
    IFC(pObjectFactory->CreatePartUri((LPWSTR)(LPCWSTR)strPTPage, &pPartUri));

	CComPtr<IXpsOMPrintTicketResource> pPTResource;
	IFC(pObjectFactory->CreatePrintTicketResource(pPrintTicketStream, pPartUri, &pPTResource));

	m_pFixedPageRef->SetPrintTicketResource(pPTResource);
	m_bPrintTicketAdded = TRUE;
	return TRUE;
}

BOOL CXPSPage::ReInitializeAllGraphicsContent(XPS_MATRIX xpsMatrix)
{
	if (m_pFixedPage == NULL)
	{
		return FALSE;
	}

	CComPtr<IXpsOMVisualCollection> pPageVisuals;
	IFC(m_pFixedPage->GetVisuals(&pPageVisuals));

	UINT32 nCanvasCount = 0;
	IFC(pPageVisuals->GetCount(&nCanvasCount));

	for (UINT32 i = 0; i < nCanvasCount; i++)
	{
		pPageVisuals->RemoveAt(0);
	}

	if (m_pCurrentCanvas != NULL)
	{
		m_pCurrentCanvas.Detach()->Release();
	}

	m_bInitialized = FALSE;
	SetFlags();
	return InitializeGraphicsContent(xpsMatrix);
}

BOOL CXPSPage::ClearCanvas(int nCanvasIndex)
{
	CComPtr<IXpsOMCanvas> pCanvas;
	CComPtr<IXpsOMVisualCollection> pCanvasVisuals;

	// Find the root-level canvas for this page that will contain all our content.
	if (!GetPageLevelCanvas(&pCanvas, nCanvasIndex))
	{
		return FALSE;
	}
    
	IFC(pCanvas->GetVisuals(&pCanvasVisuals));

	UINT32 nCount = 0;
	pCanvasVisuals->GetCount(&nCount);

	for (UINT32 i = 0; i < nCount; i++)
	{
		pCanvasVisuals->RemoveAt(0);
	}

	if (m_pCurrentCanvas != NULL && nCanvasIndex == -1)
	{
		m_pCurrentCanvas.Detach()->Release();
	}

	SetFlags();

	return TRUE;
}

BOOL CXPSPage::GetPageLevelCanvas(IXpsOMCanvas** ppCanvas, int nCanvasIndex)
{
	if (ppCanvas == NULL || nCanvasIndex == -1 && m_pCurrentCanvas == NULL)
	{
		return FALSE;
	}

	if (nCanvasIndex == -1)
	{
		*ppCanvas = m_pCurrentCanvas;
		(*ppCanvas)->AddRef();
		return TRUE;
	}

	CComPtr<IXpsOMVisualCollection> pPageVisuals;
	CComPtr<IXpsOMVisual> pCanvasVisual;

	IFC(m_pFixedPage->GetVisuals(&pPageVisuals));
	IFC(pPageVisuals->GetAt(nCanvasIndex, &pCanvasVisual));
	IFC(pCanvasVisual.QueryInterface(ppCanvas));

	return TRUE;
}

// CMFCXPSSampleDoc

IMPLEMENT_DYNCREATE(CMFCXPSSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCXPSSampleDoc, CDocument)
	ON_COMMAND(ID_XPS_ADDTEXT, &CMFCXPSSampleDoc::OnAddText)
	ON_UPDATE_COMMAND_UI(ID_XPS_ADDTEXT, &CMFCXPSSampleDoc::OnUpdateAddText)
	ON_COMMAND(ID_XPS_ADDIMAGE, &CMFCXPSSampleDoc::OnAddImage)
	ON_UPDATE_COMMAND_UI(ID_XPS_ADDIMAGE, &CMFCXPSSampleDoc::OnUpdateAddImage)
	ON_COMMAND(ID_XPS_ADDGRAPHICS, &CMFCXPSSampleDoc::OnAddGraphics)
	ON_UPDATE_COMMAND_UI(ID_XPS_ADDGRAPHICS, &CMFCXPSSampleDoc::OnUpdateAddGraphics)
	ON_COMMAND(ID_XPS_ADDPRINTTICKET, &CMFCXPSSampleDoc::OnAddPrintTicket)
	ON_UPDATE_COMMAND_UI(ID_XPS_ADDPRINTTICKET, &CMFCXPSSampleDoc::OnUpdateAddPrintTicket)
	ON_COMMAND(ID_XPS_REMOVEALL, &CMFCXPSSampleDoc::OnRemoveAll)
END_MESSAGE_MAP()


// CMFCXPSSampleDoc construction/destruction

CMFCXPSSampleDoc::CMFCXPSSampleDoc()
{
	// TODO: add one-time construction code here
	m_nPageCount = 0;
}

CMFCXPSSampleDoc::~CMFCXPSSampleDoc()
{
}

BOOL CMFCXPSSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if (!InitializeNewXPSDocument())
	{
		DeleteContents();
		return FALSE;
	}

	AddPage();
	OnAddText();

	UpdateDocumentContent();

	return TRUE;
}

BOOL CMFCXPSSampleDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
#ifdef _UNICODE 
	LPCWSTR lpPathName = lpszPathName;
#else
	USES_CONVERSION;
	LPCWSTR lpPathName = A2W(lpszPathName);
#endif

	DeleteContents();
	SetModifiedFlag(FALSE);

	CComPtr<IStream> pStream;

	IFC(m_pXpsObjectFactory.CoCreateInstance(__uuidof(XpsOMObjectFactory))); 
	IFC(m_pOpcFactory.CoCreateInstance(__uuidof(OpcFactory)));
	IFC(m_pXpsObjectFactory->CreateReadOnlyStreamOnFile(lpPathName, &pStream));
	IFC(m_pXpsObjectFactory->CreatePackageFromStream(pStream, FALSE, &m_pXpsPackage));

	if (!WriteToTempFile())
	{
		return FALSE;
	}

	if (!InitializeExistingXPSDocument())
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CMFCXPSSampleDoc::InitializeNewXPSDocument()
{
	DeleteContents();

	// Initialize factories
	IFC(m_pXpsObjectFactory.CoCreateInstance(__uuidof(XpsOMObjectFactory))); 
	IFC(m_pOpcFactory.CoCreateInstance(__uuidof(OpcFactory)));

	// Create needed OpcPartUris
    IFC(m_pOpcFactory->CreatePartUri(L"/FixedDocumentSequence.fdseq", &m_pDocSeqUri));
    IFC(m_pOpcFactory->CreatePartUri(L"/Documents/1/FixedDoc.fdoc", &m_pDocUri));

	// Call factory to create XPS package root, FDS, FD
	IFC(m_pXpsObjectFactory->CreatePackage(&m_pXpsPackage));
    IFC(m_pXpsObjectFactory->CreateDocumentSequence(m_pDocSeqUri, &m_pFixedDocSequence));
    IFC(m_pXpsObjectFactory->CreateDocument(m_pDocUri, &m_pFixedDoc));

	// Now connect trunk objects - SetParent happens internally !
	IFC(m_pXpsPackage->SetDocumentSequence(m_pFixedDocSequence));

    IFC(m_pFixedDocSequence->GetDocuments(&m_pFixedDocColl));
    IFC(m_pFixedDocColl->Append(m_pFixedDoc));

	IFC(m_pFixedDoc->GetPageReferences(&m_pFixedPageRefColl));

	return TRUE;
}

BOOL CMFCXPSSampleDoc::InitializeExistingXPSDocument()
{
	if (m_pXpsPackage == NULL)
	{
		AfxMessageBox(_T("XPS package is not created!"));
		return FALSE;
	}

	IFC(m_pXpsPackage->GetDocumentSequence(&m_pFixedDocSequence));
	IFC(m_pFixedDocSequence->GetDocuments(&m_pFixedDocColl));
	IFC(m_pFixedDocColl->GetAt(0, &m_pFixedDoc));
	IFC(m_pFixedDoc->GetPageReferences(&m_pFixedPageRefColl));

	m_nPageCount = 0;
	IFC(m_pFixedPageRefColl->GetCount((UINT32*)&m_nPageCount));

	for (int i = 0; i < m_nPageCount; i++)
	{
		CXPSPage* pPage = new CXPSPage(this);
		if (!pPage->Initialize(m_pFixedPageRefColl, i) || !pPage->InitializeGraphicsContent(xpsMatrix))
		{
			delete pPage;
			return FALSE;
		}

		pPage->SetFlags(TRUE);
		m_pages.AddTail(pPage);
	}

	return TRUE;
}

void CMFCXPSSampleDoc::AddPage()
{
	CXPSPage* pPage = new CXPSPage(this);
	if (!pPage->Create(pageSize, m_nPageCount + 1) || !pPage->InitializeGraphicsContent(xpsMatrix))
	{
		delete pPage;
		return;
	}

	m_nPageCount++;
	m_pages.AddTail(pPage);
}

void CMFCXPSSampleDoc::DeleteContents()
{
	m_strTempFileName.Empty();

	RELEASE(m_pXpsObjectFactory);
	RELEASE(m_pOpcFactory);
	RELEASE(m_pDocSeqUri);
	RELEASE(m_pDocUri);
	RELEASE(m_pFixedDoc);
	RELEASE(m_pFixedDocSequence);
	RELEASE(m_pFixedDocColl);
	RELEASE(m_pFixedPageRefColl);
	RELEASE(m_pXpsPackage);

	m_nPageCount = 0;
	while (!m_pages.IsEmpty())
	{
		delete m_pages.RemoveHead();
	}
}

// CMFCXPSSampleDoc serialization

void CMFCXPSSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

BOOL CMFCXPSSampleDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	if (m_pXpsPackage == NULL)
	{
		return FALSE;
	}

#ifdef _UNICODE 
	LPCWSTR lpPathName = lpszPathName;
#else
	USES_CONVERSION;
	LPCWSTR lpPathName = A2W(lpszPathName);
#endif

	IFC(m_pXpsPackage->WriteToFile(lpPathName, NULL, FILE_ATTRIBUTE_NORMAL, FALSE));
	return TRUE;
}

BOOL CMFCXPSSampleDoc::WriteToTempFile()
{
	CString strTempPath;
	GetTempPath(MAX_PATH - 15, strTempPath.GetBuffer(MAX_PATH - 15));
	strTempPath.ReleaseBuffer();

	GetTempFileName(strTempPath, _T("_MF"), 0, m_strTempFileName.GetBuffer(MAX_PATH));
	m_strTempFileName.ReleaseBuffer();
	TRY
	{
		CFile::Remove(m_strTempFileName);
	}
	CATCH_ALL(e)
	{
		e->Delete();
	}
	END_CATCH_ALL

	m_strTempFileName += _T(".xps");

#ifdef _UNICODE 
	LPCWSTR lpTempFile = m_strTempFileName;
#else
	USES_CONVERSION;
	LPCWSTR lpTempFile = A2W(m_strTempFileName);
#endif

	IFC(m_pXpsPackage->WriteToFile(lpTempFile, NULL, FILE_ATTRIBUTE_NORMAL, FALSE));

	return TRUE;
}

BOOL CMFCXPSSampleDoc::AddTextToXPSPage(CXPSPage* pPage)
{
	if (pPage == NULL)
	{
		return FALSE;
	}

	if (pPage->m_bTextAdded)
	{
		return TRUE;
	}

	IXpsOMPage* pFixedPage = pPage->GetPage();

	CComPtr<IStream> pFontStream;
    CComPtr<IOpcPartUri> pFontUri;
	CComPtr<IXpsOMFontResource> pFontResource;
	CComPtr<IXpsOMCanvas> pCanvas;
	XPS_COLOR xpsColorCaptionText;
	XPS_COLOR xpsColorDescriptionText;

    // Create new XPS font resource
	if (!CreateFontResourceForFont(g_szFontName, &pFontResource))
	{
		return FALSE;
	}

	// Find the root-level canvas for this page that will contain all our content.
	if (!pPage->GetPageLevelCanvas(&pCanvas))
	{
		return FALSE;
	}

	SetXPSColorToARGB(xpsColorCaptionText, RGB(0x70, 0x36, 0x40));
	SetXPSColorToARGB(xpsColorDescriptionText, RGB(0x0, 0x0, 0x0));

	AppendSimpleText(m_pXpsObjectFactory, pFontResource, 25.00f, xpsColorCaptionText, 135.5f, 80.98f, L"Demonstrating XPS Technology", pCanvas);
	AppendSimpleText(m_pXpsObjectFactory, pFontResource, 10.00f, xpsColorDescriptionText, 55.5f, 124.98f, L"Select XPS | Add Image and XPS | Add Graphics from the main menu in order to dynamically build document content.", pCanvas);
	AppendSimpleText(m_pXpsObjectFactory, pFontResource, 10.00f, xpsColorDescriptionText, 55.5f, 144.98f, L"Select XPS | Add PrintTicket to add a custom PrintTicket (Orientation - Landscape, Page Size - A4) to the first page.", pCanvas);
	AppendSimpleText(m_pXpsObjectFactory, pFontResource, 10.00f, xpsColorDescriptionText, 55.5f, 164.98f, L"Select XPS | Remove All to clear graphics and PrintTicket.", pCanvas);
	AppendSimpleText(m_pXpsObjectFactory, pFontResource, 10.00f, xpsColorDescriptionText, 55.5f, 184.98f, L"Select File | Print... to print XPS document on available XPS capable printer.", pCanvas);

	UpdateDocumentContent();

	pPage->m_bTextAdded = TRUE;

	return TRUE;
}

BOOL CMFCXPSSampleDoc::AddImageToXPSPage(CXPSPage* pPage, int nImageResID)
{
	if (pPage == NULL)
	{
		return FALSE;
	}

	if (pPage->m_bImageAdded)
	{
		return TRUE;
	}

	IXpsOMPage* pFixedPage = pPage->GetPage();

	CComPtr<IStream> pImageStream;
    CComPtr<IXpsOMCanvas> pCanvas;
	CComPtr<IXpsOMVisualCollection> pCanvasVisuals;
	CComPtr<IXpsOMPath> pImagePath;
	CComPtr<IXpsOMGeometry> pXpsGeometry;
	CComPtr<IXpsOMGeometryFigure> pXpsFigure;
	CComPtr<IXpsOMGeometryFigureCollection> pXpsFigureCollection;
	CComPtr<IXpsOMImageBrush> pImageBrush;
	CComPtr<IOpcPartUri> pImageUri;
	CComPtr<IXpsOMImageResource> pImageResource;

	XPS_RECT xpsViewbox  = {0.0f,      0.0f, 453.76f, 464.0f};
	XPS_RECT xpsViewport = {147.2f, 215.15f,  238.4f, 243.6f};
	XPS_POINT startPoint;

    // Image stream from resource.
	if (!LoadImageToStream(MAKEINTRESOURCE(nImageResID), &pImageStream))
	{
		return FALSE;
	}

	CStringW strImageUri;
	strImageUri.Format(L"/Resources/Images/%d.jpg", nImageResID);

	// create the image resource
    IFC(m_pOpcFactory->CreatePartUri(strImageUri, &pImageUri));
	IFC(m_pXpsObjectFactory->CreateImageResource(pImageStream, XPS_IMAGE_TYPE_JPEG, pImageUri, &pImageResource));

	// Create the image brush
	IFC(m_pXpsObjectFactory->CreateImageBrush(pImageResource, &xpsViewbox, &xpsViewport, &pImageBrush) );

	// Create the geometry needed for the image
    startPoint.x = 147.2f;
	startPoint.y = 485.75f;
    XPS_SEGMENT_TYPE segmentTypes[3] = 
	{
        XPS_SEGMENT_TYPE_LINE, 
        XPS_SEGMENT_TYPE_LINE, 
        XPS_SEGMENT_TYPE_LINE
    };
    FLOAT segmentData[6] = 
	{
        147.2f, 215.15f,
        385.6f, 215.15f,
		385.6f, 458.75f
    };
    BOOL segmentStrokes[3] = 
	{
        FALSE, FALSE, FALSE
    };

    IFC(m_pXpsObjectFactory->CreateGeometryFigure(&startPoint, &pXpsFigure));
    IFC(pXpsFigure->SetIsClosed(TRUE));
    IFC(pXpsFigure->SetIsFilled(TRUE));
    IFC(pXpsFigure->SetSegments(3, 6, segmentTypes, segmentData, segmentStrokes));
	IFC(m_pXpsObjectFactory->CreateGeometry(&pXpsGeometry));
    IFC(pXpsGeometry->GetFigures(&pXpsFigureCollection));
	IFC(pXpsFigureCollection->Append(pXpsFigure));

    // Create our image
	IFC(m_pXpsObjectFactory->CreatePath(&pImagePath));
	IFC(pImagePath->SetFillBrushLocal(pImageBrush));
	IFC(pImagePath->SetGeometryLocal(pXpsGeometry));

	// Find the root-level canvas for this page that will contain all our content.
	if (!pPage->GetPageLevelCanvas(&pCanvas))
	{
		return FALSE;
	}

	IFC(pCanvas->GetVisuals(&pCanvasVisuals));
	IFC(pCanvasVisuals->InsertAt(0, pImagePath)); // We insert at the start so the extra part of the image falls behind the sidebar.

	UpdateDocumentContent();

	pPage->m_bImageAdded = TRUE;

	return TRUE;
}

BOOL CMFCXPSSampleDoc::AddGraphicsToXPSPage(CXPSPage* pPage)
{
	if (pPage == NULL)
	{
		return FALSE;
	}

	if (pPage->m_bGraphicsAdded)
	{
		return TRUE;
	}

	CComPtr<IXpsOMCanvas> pCanvas;
	CComPtr<IXpsOMVisualCollection> pCanvasVisuals;
	CComPtr<IXpsOMPath> pPathTopbar;
	CComPtr<IXpsOMGeometry> pXpsGeometry;
	CComPtr<IXpsOMGeometryFigure> pXpsFigure;
	CComPtr<IXpsOMGeometryFigureCollection> pXpsFigureCollection;
	CComPtr<IXpsOMLinearGradientBrush> pTopbarBrush;
	CComPtr<IXpsOMGradientStop> pXpsGradientStop1;
	CComPtr<IXpsOMGradientStop> pXpsGradientStop2;

	XPS_COLOR xpsColorTopbar;
	XPS_POINT startPoint; 
	XPS_POINT endPoint;

	// Find the root-level canvas for this page that will contain all our content.
	if (!pPage->GetPageLevelCanvas(&pCanvas))
	{
		return FALSE;
	}

    // First we need to get the top-level Canvas visual collection
	IFC(pCanvas->GetVisuals(&pCanvasVisuals));

	// Create the brush needed for the topbar
	SetXPSColorToARGB(xpsColorTopbar, RGB(0xE4, 0x3B, 0x2F));
	IFC(m_pXpsObjectFactory->CreateGradientStop(&xpsColorTopbar, NULL, 0.0f, &pXpsGradientStop1));

	SetXPSColorToARGB(xpsColorTopbar, RGB(0xEF, 0x79, 0x2F));
	IFC(m_pXpsObjectFactory->CreateGradientStop(&xpsColorTopbar, NULL, 1.0f, &pXpsGradientStop2));

	startPoint.x = 375.75f;
	startPoint.y = 18.0f;
	endPoint.x   = 375.75f;
	endPoint.y   = 134.6f;

	IFC(m_pXpsObjectFactory->CreateLinearGradientBrush(pXpsGradientStop1, pXpsGradientStop2, &startPoint, &endPoint, &pTopbarBrush));

	// Create the geometry needed for the topbar
    startPoint.x = 20.5f;
	startPoint.y = 18.0f;
    XPS_SEGMENT_TYPE topbarSegmentTypes[3] = 
	{
        XPS_SEGMENT_TYPE_LINE, 
        XPS_SEGMENT_TYPE_BEZIER,  
		XPS_SEGMENT_TYPE_LINE
    };
    FLOAT topbarSegmentData[10] = 
	{
        20.5f,   134.6f,
        322.76f, 102.91f, 476.79f, 105.27f, 594.0f, 116.63f,
		594.0f,    18.0f
    };
    BOOL topbarSegmentStrokes[3] = 
	{
        FALSE, FALSE, FALSE
    };
    IFC(m_pXpsObjectFactory->CreateGeometryFigure( &startPoint, &pXpsFigure));
    IFC(pXpsFigure->SetIsClosed(TRUE));
    IFC(pXpsFigure->SetIsFilled(TRUE));
    IFC(pXpsFigure->SetSegments(3, 10, topbarSegmentTypes, topbarSegmentData, topbarSegmentStrokes));
	IFC(m_pXpsObjectFactory->CreateGeometry(&pXpsGeometry));
    IFC(pXpsGeometry->GetFigures(&pXpsFigureCollection));
	IFC(pXpsFigureCollection->Append(pXpsFigure));

    // Create our topbar
	IFC(m_pXpsObjectFactory->CreatePath(&pPathTopbar));
	IFC(pPathTopbar->SetFillBrushLocal(pTopbarBrush));
	IFC(pPathTopbar->SetGeometryLocal(pXpsGeometry));

	// Add the topbar to the page
	IFC(pCanvasVisuals->InsertAt(0, pPathTopbar));

	UpdateDocumentContent();

	pPage->m_bGraphicsAdded = TRUE;

	return TRUE;
}

BOOL CMFCXPSSampleDoc::AddPrintTicketToXPSPage(CXPSPage* pPage)
{
	CString strPrinterName = _T("Microsoft XPS Document Writer");

	CComPtr<IStream> pNewPrintTicketStream;
	if (!GenerateNewPrintTicket(strPrinterName, &pNewPrintTicketStream))
	{
		return FALSE;
	}

	if (!pPage->SetPrintTicket(pNewPrintTicketStream))
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CMFCXPSSampleDoc::GenerateNewPrintTicket(LPCTSTR lpcszPrinterName, IStream** ppNewPrintTicketStream)
{
	STATE_INFO si;
	si.SetPrinterName(lpcszPrinterName);

	CComPtr<IStream> pBasePrintTicketStream;
	if (!GetUserPrintTicketStream(&si, &pBasePrintTicketStream))
	{
		return FALSE;
	}

	CComPtr<IXMLDOMDocument2> pBasePrintTicketDOM;
	if (!IStreamToDOMDocument(pBasePrintTicketStream, &pBasePrintTicketDOM))
	{
		return FALSE;
	}

	// stram position could be moved by IStreamToDOMDocument
	LARGE_INTEGER li = {0,0};
    if (FAILED(pBasePrintTicketStream->Seek(li, STREAM_SEEK_SET, NULL)))
	{
		return FALSE;
	}

	CComPtr<IStream> pPrintCapsStream;
	if (!GetPrintCapsBasedOnPrintTicket(si.GetProvider(), pBasePrintTicketStream, &pPrintCapsStream))
	{
		return FALSE;
	}

	CComPtr<IXMLDOMDocument2> pPrintCapsDOM;
	if (!IStreamToDOMDocument(pPrintCapsStream, &pPrintCapsDOM))
	{
		return FALSE;
	}

	if (!CreateNewPrintTicket(&si, pPrintCapsDOM, pBasePrintTicketStream, pBasePrintTicketDOM, ppNewPrintTicketStream))
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CMFCXPSSampleDoc::RemoveAllVisualElementsFromXPSPage(CXPSPage* pPage)
{
	if (!pPage->ReInitializeAllGraphicsContent(xpsMatrix))
	{
		return FALSE;	
	}

	UpdateDocumentContent();
	return TRUE;
}

void CMFCXPSSampleDoc::UpdateDocumentContent()
{
	WriteToTempFile();
	UpdateAllViews(NULL);
}

// CMFCXPSSampleDoc diagnostics

#ifdef _DEBUG
void CMFCXPSSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCXPSSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCXPSSampleDoc commands
void CMFCXPSSampleDoc::OnAddText()
{
	CXPSPage* pPage = m_pages.GetHead();

	if (!AddTextToXPSPage(pPage))
	{
		AfxMessageBox(_T("Failed to add text to XPS page."));
	}
}

void CMFCXPSSampleDoc::OnAddImage()
{
	CXPSPage* pPage = m_pages.GetHead();

	if (!AddImageToXPSPage(pPage, IDR_BOXSHOT_IMAGE))
	{
		AfxMessageBox(_T("Failed to add image to XPS page."));
	}
}

void CMFCXPSSampleDoc::OnAddGraphics()
{
	CXPSPage* pPage = m_pages.GetHead();

	if (!AddGraphicsToXPSPage(pPage))
	{
		AfxMessageBox(_T("Failed to add graphics to XPS page."));
	}
}

void CMFCXPSSampleDoc::OnAddPrintTicket()
{
	CXPSPage* pPage = m_pages.GetHead();
	if (!AddPrintTicketToXPSPage(pPage))
	{
		AfxMessageBox(_T("Failed to add Print Ticket to XPS page."));
	}
}

void CMFCXPSSampleDoc::PrintXPSFile()
{
	if (m_pages.GetCount() == 0 || m_pXpsPackage == NULL)
	{
		AfxMessageBox(_T("XPS document is empty."));
		return;
	}

	CPrintDialog dlg(TRUE, PD_ALLPAGES | PD_USEDEVMODECOPIES | PD_NOPAGENUMS | PD_HIDEPRINTTOFILE | PD_NOSELECTION | PD_RETURNDC);

	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	HDC hdc = dlg.GetPrinterDC();

	BOOL bIsXPSDriver = IsXPSCapableDriver(hdc);
	DeleteDC(hdc);
	
	if (!bIsXPSDriver)
	{
		if (AfxMessageBox(_T("Selected device does not provide an XPS capable driver. Continue printing?"), MB_YESNO) != IDYES)
			return;	
	}

	HANDLE completionEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	CComPtr<IXpsPrintJob> pJob;
	IXpsPrintJobStream* pJobStream = NULL;

	CString strPrinterName = dlg.GetDeviceName();

#ifdef _UNICODE
	LPCWSTR lpPrinterName = strPrinterName; 
#else
	USES_CONVERSION;
	LPCWSTR lpPrinterName = A2W(strPrinterName);
#endif

	HRESULT hr = theApp.StartPrintJob(lpPrinterName, NULL, NULL, NULL, completionEvent, 
			NULL, 0, &pJob, &pJobStream, NULL);

	// Write package to print job stream
	if (SUCCEEDED(hr))
	{
		hr = m_pXpsPackage->WriteToStream ((IStream*)pJobStream, FALSE);

		// Close the stream to tell the print job
		// that the entire document has been sent.
		if (SUCCEEDED(hr) && pJobStream != NULL)
		{
			hr = pJobStream->Close();

			// Wait for the print job to finish spooling...
			if (NULL != completionEvent) 
			{
			    if (WaitForSingleObject(completionEvent, INFINITE) == WAIT_OBJECT_0)
			    {
			        // Get the print job status to see why the wait completed.
			        //  Note that without waiting for a completion event, 
			        //  the print job may not be complete when the status is queried.
			        XPS_JOB_STATUS jobStatus;
			        hr = pJob->GetJobStatus(&jobStatus);

			        // Evaluate the job status returned.
			        switch (jobStatus.completion)
			        {
			            case XPS_JOB_COMPLETED:
			                // The job completed as expected.
			                hr = S_OK;
			                break;
			            case XPS_JOB_CANCELLED:
			                // The job was canceled.
			                hr = E_FAIL;
			                break;
			            case XPS_JOB_FAILED:
			                // The job failed, 
			                // jobStatus.jobStatus has the reason.
			                hr = E_FAIL;
			                break;
			            default:
			                // An unexpected value was returned.
			                hr = E_UNEXPECTED;
			                break;
			        }
			            
			        // Release completion event handle
			        CloseHandle(completionEvent);
			    }
			    else
			    {    // there was a problem, set hr to error status
			        hr  = HRESULT_FROM_WIN32(GetLastError());
			    }
			}
		}
	}

	if (pJobStream != NULL)
	{
		pJobStream->Release();
	}

	// hr contains the result of the print operation
}

void CMFCXPSSampleDoc::OnRemoveAll()
{
	CXPSPage* pPage = m_pages.GetHead();
	if (!RemoveAllVisualElementsFromXPSPage(pPage))
	{
		AfxMessageBox(_T("Failed to reinitialize graphics content for XPS page."));
	}

	// remove PrintTicket
	pPage->SetPrintTicket(NULL);
}

void CMFCXPSSampleDoc::OnUpdateAddText(CCmdUI* pCmdUI)
{
	if (!m_pages.IsEmpty())
	{
		CXPSPage* pPage = m_pages.GetHead();
		pCmdUI->Enable(!pPage->m_bTextAdded);
	}
}

void CMFCXPSSampleDoc::OnUpdateAddImage(CCmdUI* pCmdUI)
{
	if (!m_pages.IsEmpty())
	{
		CXPSPage* pPage = m_pages.GetHead();
		pCmdUI->Enable(!pPage->m_bImageAdded);
	}
}

void CMFCXPSSampleDoc::OnUpdateAddGraphics(CCmdUI* pCmdUI)
{
	if (!m_pages.IsEmpty())
	{
		CXPSPage* pPage = m_pages.GetHead();
		pCmdUI->Enable(!pPage->m_bGraphicsAdded);
	}
}

void CMFCXPSSampleDoc::OnUpdateAddPrintTicket(CCmdUI* pCmdUI)
{
	if (!m_pages.IsEmpty())
	{
		CXPSPage* pPage = m_pages.GetHead();
		pCmdUI->Enable(!pPage->m_bPrintTicketAdded);
	}
}

// Helpers
BOOL CMFCXPSSampleDoc::AppendSimpleText(IXpsOMObjectFactory* pXpsFactory, 
	IXpsOMFontResource* pXpsFont, float fFontEmSize, XPS_COLOR &xpsColor, 
	float fOriginX, float fOriginY, LPCWSTR lpUnicodeString, IXpsOMCanvas* pXpsCanvas)
{
	XPS_POINT glyphsOrigin = {fOriginX, fOriginY};
	CComPtr<IXpsOMGlyphsEditor> pGlyphsEditor;
	CComPtr<IXpsOMGlyphs> pXpsGlyphs;
	CComPtr<IXpsOMVisualCollection> pCanvasVisuals;
	CComPtr<IXpsOMSolidColorBrush> pXpsBrush;

    // Create a brush from the solid color provided
    IFC(pXpsFactory->CreateSolidColorBrush(&xpsColor, NULL, &pXpsBrush));

    // Create a new Glyphs object and set its properties
	IFC(pXpsFactory->CreateGlyphs(pXpsFont, &pXpsGlyphs));
	IFC(pXpsGlyphs->SetOrigin(&glyphsOrigin));
	IFC(pXpsGlyphs->SetFontRenderingEmSize(fFontEmSize));
	IFC(pXpsGlyphs->SetFillBrushLocal(pXpsBrush));

    // Some properties are inter-dependent so must be changed through a GlyphsEditor
	IFC(pXpsGlyphs->GetGlyphsEditor(&pGlyphsEditor));
	IFC(pGlyphsEditor->SetUnicodeString(lpUnicodeString));
	IFC(pGlyphsEditor->ApplyEdits());

	// Add the new Glyphs object to the provided canvas
	IFC(pXpsCanvas->GetVisuals(&pCanvasVisuals));
	IFC(pCanvasVisuals->Append(pXpsGlyphs));
	
	return TRUE;
}

BOOL CMFCXPSSampleDoc::CreateFontResourceForFont(LPCWSTR lpcszfontName, IXpsOMFontResource** pFontResource)
{
	CDC dc;
	LOGFONTW logFont = {};
	CFont font;
	ULONG privStatus = 0;
	LONG ttStatus;
	XPS_FONT_EMBEDDING embedding = XPS_FONT_EMBEDDING_NORMAL;
	DWORD fontDataLen = GDI_ERROR;
	HGLOBAL hGlobal = NULL;
	LPVOID ptr = NULL;
	CComPtr<IStream> pFontStream = NULL;
	GUID fontObfuscationGuid = {};
	CComPtr<IOpcPartUri> pPartUri;
	CString strMessage;

	if (m_pXpsObjectFactory == NULL || m_pOpcFactory == NULL)
	{
		return FALSE;
	}

	if (!dc.CreateDC(_T("DISPLAY"), NULL, NULL, NULL))
	{
		return FALSE;
	}

	if (wcscpy_s(logFont.lfFaceName, lpcszfontName) != 0)
	{
		return FALSE;
	}
    
	HFONT hFont = CreateFontIndirectW(&logFont);
	if (hFont == NULL)
	{
		return FALSE;
	}

	font.Attach(hFont);

	if (dc.SelectObject(&font) == NULL)
	{
		return FALSE;
	}

	if ((ttStatus = TTGetEmbeddingType(dc.m_hDC, &privStatus)) != E_NONE)
	{
		if (ttStatus == E_NOTATRUETYPEFONT)
		{
			strMessage.Format(_T("ERROR: %s is not a TrueType font"), lpcszfontName);
			AfxMessageBox(strMessage);
		}
		else
		{
			strMessage.Format(_T("ERROR: Could not get embedding type: %08X"), ttStatus);
			AfxMessageBox(strMessage);
		}

		return FALSE;
	}
    
	switch (privStatus)
	{
	case EMBED_PREVIEWPRINT:
		// Restricted font
		embedding = XPS_FONT_EMBEDDING_RESTRICTED;
		break;
	case EMBED_EDITABLE:
		// Editable font - MUST obfuscate
		embedding = XPS_FONT_EMBEDDING_OBFUSCATED;
		break;
	case EMBED_INSTALLABLE:
		// Installable font - SHOULD obfuscate
		embedding = XPS_FONT_EMBEDDING_OBFUSCATED;
		break;
	case EMBED_NOEMBEDDING:
		strMessage.Format(_T("ERROR: %s may not be embedded"), lpcszfontName);
		AfxMessageBox(strMessage);
		return FALSE;
	default:
		strMessage.Format(_T("ERROR: Unrecognized embedding privileges: %08X"), privStatus);
		return FALSE;
	}

	fontDataLen = GetFontData(dc.m_hDC, 0, 0, NULL, 0);
	if (fontDataLen == GDI_ERROR)
	{
		return FALSE;
	}

	hGlobal = GlobalAlloc(GMEM_MOVEABLE, fontDataLen);
	if (!hGlobal)
	{
		return FALSE;
	}

	ptr = GlobalLock(hGlobal);
	if (!ptr)
	{
		return FALSE;
	}
	else
	{
		if (GetFontData(dc.m_hDC, 0, 0, ptr, fontDataLen) == GDI_ERROR)
		{
			GlobalUnlock(hGlobal);
			return FALSE;
		}
	}

    if (FAILED(CreateStreamOnHGlobal(hGlobal, TRUE, &pFontStream)))
    {
		GlobalFree(hGlobal);
        return FALSE;
    }

	if (!GenerateNewFontPartUri(m_pOpcFactory, &pPartUri))
	{
		return FALSE;
	}

	IFC(m_pXpsObjectFactory->CreateFontResource(pFontStream, embedding, pPartUri, FALSE, pFontResource));

    return TRUE;
}

BOOL CMFCXPSSampleDoc::GenerateNewFontPartUri(IOpcFactory *pOpcFactory, IOpcPartUri  **ppPartUri)
{
    GUID guid;
    WCHAR guidString[128] = {0};
    WCHAR uriString[256] = {0};

    IFC(CoCreateGuid(&guid));
    IFC(StringFromGUID2(guid, guidString, ARRAYSIZE(guidString)));

    wcscpy_s(uriString, ARRAYSIZE(uriString), L"/Resources/Fonts/");
    wcsncat_s(uriString, ARRAYSIZE(uriString), guidString + 1, wcslen(guidString) - 2); // guid string start and ends with curly braces so they are removed
    wcscat_s(uriString, ARRAYSIZE(uriString), L".odttf");

    IFC(pOpcFactory->CreatePartUri(uriString, ppPartUri));

    return TRUE;
}

void CMFCXPSSampleDoc::SetXPSColorToARGB(XPS_COLOR& xpsColor, COLORREF color, UINT8 alpha)
{
	xpsColor.colorType = XPS_COLOR_TYPE_SRGB;
    xpsColor.value.sRGB.alpha = alpha;
    xpsColor.value.sRGB.red = GetRValue(color);
    xpsColor.value.sRGB.green = GetGValue(color);
    xpsColor.value.sRGB.blue = GetBValue(color);
}

BOOL CMFCXPSSampleDoc::LoadImageToStream(LPCTSTR lpcszImageResID, IStream** ppStream, LPCTSTR lpcszType)
{
	HGLOBAL hData = NULL;
	HINSTANCE hHandle = AfxGetResourceHandle();

	HRSRC hRes = FindResource(hHandle, lpcszImageResID, lpcszType);

	if (hRes == NULL)
	{
		return FALSE;
	}

    hData = LoadResource(hHandle, hRes);
    if (!hData)
    {
        return FALSE;
    }

	DWORD dwSize = SizeofResource(hHandle, hRes);
    if (dwSize <= 0)
    {
        return FALSE;
    }
    
	PVOID pData = LockResource(hData);
    if (!pData)
    {
        return FALSE;
    }

	PVOID pBuf = GlobalLock(GlobalAlloc(GMEM_MOVEABLE, dwSize)); 
	if (!pBuf)
	{
		return FALSE;
	}

	CopyMemory(pBuf, pData, dwSize);
	if (FAILED(CreateStreamOnHGlobal(pBuf, TRUE, ppStream)))
	{
		GlobalFree(pBuf);
	}

	return TRUE;
}

BOOL CMFCXPSSampleDoc::CreateNewPrintTicket(STATE_INFO* psi, IXMLDOMDocument2* pPrintCapsDOM,
					IStream* pBasePrintTicketStream, IXMLDOMDocument2* pBasePrintTicketDOM, 
    				IStream** ppNewPrintTicketStream)
{
	if (ppNewPrintTicketStream == NULL)
	{
		return FALSE;
	}

	 // Create a duplicate print ticket from the same print ticket stream as the base print ticket.
    CComPtr<IXMLDOMDocument2> pDeltaPrintTicket;
    IFC(IStreamToDOMDocument(pBasePrintTicketStream, &pDeltaPrintTicket));
    
    // From the Cloned Print Ticket, take away all off feature-option pairs
    // so that only a minimal (or you may call it sparse) print ticket remains.
    if (!ConvertFullPrintTicketToMinimalPrintTicket(pDeltaPrintTicket))
	{
		return FALSE;
	}

	// Find node with A4 paper size
	CComPtr<IXMLDOMNode> pPrintCapsA4Node;
	if (GetNodeFromPrintCapsDOM(pPrintCapsDOM, L"PageMediaSize", L"ISOA4", &pPrintCapsA4Node))
	{
		CComPtr<IXMLDOMNode> pPrintTicketFeatureNode;
		if (CreatePTFeatureOptionNodeFromPrintCapOptionNode(pPrintCapsA4Node, &pPrintTicketFeatureNode))
		{
			MergeNodeIntoMinimalPrintTicket(pDeltaPrintTicket, pPrintTicketFeatureNode);
		}
	}

	// Find node with Landscape orientation
	CComPtr<IXMLDOMNode> pPrintCapsOrientationNode;
	if (GetNodeFromPrintCapsDOM(pPrintCapsDOM, L"PageOrientation", L"Landscape", &pPrintCapsOrientationNode))
	{
		CComPtr<IXMLDOMNode> pPrintTicketFeatureNode;
		if (CreatePTFeatureOptionNodeFromPrintCapOptionNode(pPrintCapsOrientationNode, &pPrintTicketFeatureNode))
		{
			MergeNodeIntoMinimalPrintTicket(pDeltaPrintTicket, pPrintTicketFeatureNode);
		}
	}

    CComPtr<IStream> pDeltaPrintTicketStream;
    IFC(CreateStreamOnHGlobal(NULL, TRUE, &pDeltaPrintTicketStream));
    
    if (!DOMDocumentToIStream(pDeltaPrintTicket, pDeltaPrintTicketStream))
	{
		return FALSE;
    }

    IFC(CreateStreamOnHGlobal(NULL, TRUE, ppNewPrintTicketStream));
    
    //
    // Make sure printticket stream points to the begining
    //
    LARGE_INTEGER li = {0,0};
    IFC(pBasePrintTicketStream->Seek(li, STREAM_SEEK_SET, NULL));
    IFC(pDeltaPrintTicketStream->Seek(li, STREAM_SEEK_SET, NULL));

	// Finally merge
	IFC(PTMergeAndValidatePrintTicket(psi->GetProvider(), pBasePrintTicketStream, pDeltaPrintTicketStream, kPTPageScope, *ppNewPrintTicketStream, NULL));

	//Uncomment for debug of delta tickets
	//CComVariant varDest = _T("d:\\minimal.xml");
	//pDeltaPrintTicket->save(varDest);

	return TRUE;
}

BOOL CMFCXPSSampleDoc::GetUserPrintTicketStream(STATE_INFO* psi, IStream** ppStream)
{
	HRESULT     hr       = S_OK;
    LPDEVMODEW  pDevMode = NULL;

	// it internally allocates LPDEVMODE by new, so we will need to delete it at the end
	if (!GetDevmodeFromDocProperty(psi, &pDevMode))
	{
		return FALSE;
	}

  	BOOL bResult = ConvertDevmodeToPrintTicketStream(psi->GetProvider(), pDevMode, ppStream);
    
    // Don't need devmode anymore;
	if (pDevMode != NULL)
	{
		delete pDevMode;
	}

    pDevMode = NULL;
    return bResult;
}

BOOL CMFCXPSSampleDoc::GetDevmodeFromDocProperty(STATE_INFO* psi, LPDEVMODEW *ppDevMode)
{
    PDEVMODEW pdm = NULL;
    LONG lRetVal = -1;
	HANDLE hPrinter = psi->GetPrinter();

	if (hPrinter == NULL)
		return FALSE;

    *ppDevMode = NULL;

#ifdef _UNICODE
	LPCWSTR lpPrinterName = psi->GetPrinterName();
#else
	USES_CONVERSION;
	LPCWSTR lpPrinterName = A2W(psi->GetPrinterName());
#endif

    lRetVal = DocumentPropertiesW(NULL, hPrinter, (LPWSTR)lpPrinterName, NULL, NULL, 0);

    if (lRetVal == 0)   
	{
		return FALSE;
	}

	pdm = (PDEVMODEW) new BYTE [lRetVal];
    
    lRetVal = DocumentPropertiesW(NULL, hPrinter, (LPWSTR)lpPrinterName, pdm, NULL, DM_OUT_BUFFER);
                
    if (lRetVal == IDOK)
    {
        *ppDevMode = pdm;
    }
	else 
    {
		delete pdm;
        return FALSE;
    }

    return TRUE;
}

BOOL CMFCXPSSampleDoc::ConvertDevmodeToPrintTicketStream(HPTPROVIDER hProvider, LPDEVMODEW pDevMode, IStream** ppPrintTicketStream)
{
	if (hProvider == NULL || ppPrintTicketStream == NULL)
	{
		return FALSE;
	}

	*ppPrintTicketStream = NULL;
    IFC(CreateStreamOnHGlobal(NULL, TRUE, ppPrintTicketStream));
	
    DWORD dwDevModeBytes = pDevMode->dmSize + pDevMode->dmDriverExtra;
	HRESULT hr = PTConvertDevModeToPrintTicket(hProvider, dwDevModeBytes, (PDEVMODE)pDevMode, kPTJobScope, *ppPrintTicketStream);
    return SUCCEEDED(hr);
}

BOOL CMFCXPSSampleDoc::GetPrintCapsBasedOnPrintTicket(HPTPROVIDER hProvider, IStream* pPrintTicketStream, IStream** ppPrintCapsStream)
{
    if ( hProvider == NULL || NULL == pPrintTicketStream || NULL == ppPrintCapsStream) 
    {
        return FALSE;
    }
    
	*ppPrintCapsStream = NULL;
    IFC(CreateStreamOnHGlobal(NULL, TRUE, ppPrintCapsStream));

    return SUCCEEDED(PTGetPrintCapabilities(hProvider, pPrintTicketStream, *ppPrintCapsStream, NULL));
}

BOOL CMFCXPSSampleDoc::ConvertFullPrintTicketToMinimalPrintTicket(IXMLDOMDocument2* pPrintTicketDOM)
{
    CComPtr<IXMLDOMElement> pXMLDOMElement;
    CComPtr<IXMLDOMNodeList> pXMLDOMNodeList;

    IFC(pPrintTicketDOM->get_documentElement(&pXMLDOMElement));
    IFC(pXMLDOMElement->get_childNodes(&pXMLDOMNodeList));
    
	HRESULT hr = S_OK;
    IXMLDOMNode* pXMLChild = NULL;
    while (SUCCEEDED(hr) && S_OK == (hr = pXMLDOMNodeList->nextNode(&pXMLChild)))
    {
        hr = pXMLDOMElement->removeChild(pXMLChild, NULL);
        pXMLChild->Release();
    }
    
    return TRUE;
}

BOOL CMFCXPSSampleDoc::IStreamToDOMDocument(IStream *pStream, IXMLDOMDocument2** ppXmlDocument)
{
    *ppXmlDocument = NULL;

    IFC(CoCreateInstance(CLSID_DOMDocument60, NULL, CLSCTX_INPROC_SERVER, 
							IID_IXMLDOMDocument2,(LPVOID*) ppXmlDocument));
    
	LARGE_INTEGER pos = {0, 0};
    IFC(pStream->Seek(pos, STREAM_SEEK_SET, NULL));

    //
    // Load the XML synchronously
    //
    VARIANT_BOOL loadResult = 0; // Inidicates the result of loading the XML
    VARIANT      streamVar;      // Variant wrapper for the IStream to pass to load.

    VariantInit(&streamVar);
    V_VT(&streamVar) = VT_UNKNOWN;
    V_UNKNOWN(&streamVar) = pStream;
    pStream->AddRef();

    BOOL bResult = SUCCEEDED((*ppXmlDocument)->load(streamVar, &loadResult));
	VariantClear(&streamVar);

    return bResult;
}

BOOL CMFCXPSSampleDoc::DOMDocumentToIStream(IXMLDOMDocument2* pDocument, IStream* pStream)
{
    //
    // Write the document to the stream using a variant.  The stream
    // will automatically grow to the correct size.
    //
    VARIANT outputStream;
    VariantInit(&outputStream);
    V_VT(&outputStream) = VT_UNKNOWN;
    pStream->AddRef();
    V_UNKNOWN(&outputStream) = pStream;

    IFC(pDocument->save(outputStream));

    VariantClear(&outputStream);

    return TRUE;
}

BOOL CMFCXPSSampleDoc::XPathQueryOnPrintCaps(IXMLDOMDocument2* pPrintCapsDOM, BSTR bstrXPathQuery,
    										 IXMLDOMNodeList** ppIXMLDOMNodeList)
{
    CComBSTR bstrSelectionLanguage    = (L"SelectionLanguage");
    CComBSTR bstrXPath                = (L"XPath");
    CComBSTR bstrSelectionNamespaces  = (L"SelectionNamespaces");

    CComBSTR bstrNS = (L" \
                        xmlns:psf=\"http://schemas.microsoft.com/windows/2003/08/printing/printschemaframework\" \
                        xmlns:psk=\"http://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords\" \
                        ");

    *ppIXMLDOMNodeList = NULL;

	VARIANT varXPath;
	VariantInit (&varXPath);
	varXPath.vt      = VT_BSTR;
	varXPath.bstrVal = bstrXPath;
	IFC(pPrintCapsDOM->setProperty(bstrSelectionLanguage, varXPath))

    VARIANT varNS;
    VariantInit (&varNS);
    varNS.vt      = VT_BSTR;
    varNS.bstrVal = bstrNS;
	IFC(pPrintCapsDOM->setProperty(bstrSelectionNamespaces, varNS));

    IFC(pPrintCapsDOM->selectNodes(bstrXPathQuery, ppIXMLDOMNodeList));
	return TRUE;
}

static const CStringW szXpathQueryForPrintCapsFormat =
                                            L"psf:PrintCapabilities/psf:Feature[substring-after(@name,':')='%s']" \
                                            L"[name(namespace::*[.='http://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords'])=substring-before(@name,':')]" \
                                            L"/psf:Option" \
                                            L"[substring-after(@name,':')='%s']" \
                                            L"[name(namespace::*[.='http://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords'])=substring-before(@name,':')]";

BOOL CMFCXPSSampleDoc::GetNodeFromPrintCapsDOM(IXMLDOMDocument2* pPrintCapsDOM, LPCWSTR lpcszFeatureName, 
												LPCWSTR lpcszOptionName, IXMLDOMNode** ppOutNote)
{
	CStringW strQuery;
	strQuery.Format(szXpathQueryForPrintCapsFormat, lpcszFeatureName, lpcszOptionName);
	CComBSTR bstrXPathQuery = strQuery; 

	CComPtr<IXMLDOMNodeList> pNodeList;
	if (!XPathQueryOnPrintCaps(pPrintCapsDOM, bstrXPathQuery, &pNodeList))
	{
		return FALSE;
	}

	IFC(pNodeList->nextNode(ppOutNote));
	return TRUE;
}

BOOL CMFCXPSSampleDoc::MergeNodeIntoMinimalPrintTicket(IXMLDOMDocument2* pPrintTicketMinimal, IXMLDOMNode* pNode)
{
    CComPtr<IXMLDOMElement> pXMLDOMElement;

    IFC(pPrintTicketMinimal->get_documentElement(&pXMLDOMElement));
    IFC(pXMLDOMElement->appendChild(pNode, NULL));

    return TRUE;
}

BOOL CMFCXPSSampleDoc::CreatePTFeatureOptionNodeFromPrintCapOptionNode(IXMLDOMNode* pPrintCapsOptionNode, IXMLDOMNode** ppPrintTicketFeatureNode)
{
    CComPtr<IXMLDOMNode> pParentNode;
    CComPtr<IXMLDOMNode> pOptionNode;
    VARIANT_BOOL varDeep = VARIANT_TRUE;

    //
    // To Create a new PrintTicket Node from a corresponding print capabilties node
    // the following steps need to be followed.
    // 1. Clone the option node.
    // 2. From the Option node, remove the "constrained" attribute
    // 3. From the option node, remove the Property "DisplayName"
    // 4. Since the pPrintCapabilitiesNode only indicates the option, but doesn't indicate which feature
    //    we have to go to the parent to get the feature Node.
    // 5. Clone the feauture node and then add the cloned option node as a child.  
    
    *ppPrintTicketFeatureNode = NULL;
    IFC(pPrintCapsOptionNode->cloneNode(varDeep, &pOptionNode));
    
    
    if (!ConvertPrintCapOptionNodeToPrintTicketOptionNode(pOptionNode))
	{
		return FALSE;
	}

    IFC(pPrintCapsOptionNode->get_parentNode(&pParentNode));
    varDeep = VARIANT_FALSE;
	IFC(pParentNode->cloneNode(varDeep, ppPrintTicketFeatureNode));
    
	IFC((*ppPrintTicketFeatureNode)->appendChild(pOptionNode, NULL));
    
    return TRUE;
}

BOOL CMFCXPSSampleDoc::ConvertPrintCapOptionNodeToPrintTicketOptionNode(IXMLDOMNode* pOptionNode)
{
    // Remove the "constrained" attribute.
    if (!RemoveAllAttributesExceptNameFromOptionNode(pOptionNode))
	{
		return FALSE;
	}

    // Iterate through the children and remove all those that are property nodes. This is required
    // to convert the PrintCap node into a PrintTicket node.
    return RemoveAllChildrenWithProperty(pOptionNode);
}

BOOL CMFCXPSSampleDoc::RemoveAllAttributesExceptNameFromOptionNode(IXMLDOMNode* pNode)
{
    LONG cAttributes;
    CComPtr<IXMLDOMNamedNodeMap> pAttrMap;
    
    IFC(pNode->get_attributes(&pAttrMap));
	IFC(pAttrMap->get_length(&cAttributes));

	HRESULT hr = S_OK;
    for (INT i = 0; SUCCEEDED(hr) && i < cAttributes; i++)
    {    
        CComBSTR bstrAttrName;
        CComPtr<IXMLDOMNode> pCurrentAttrNode;
        CComPtr<IXMLDOMAttribute> pCurrentAttr;

        hr = pAttrMap->get_item(i, &pCurrentAttrNode);
        if (SUCCEEDED(hr))
        {
            hr = pCurrentAttrNode->QueryInterface(IID_IXMLDOMAttribute, (void**)&pCurrentAttr);
        }

        if (SUCCEEDED(hr))
        {
            hr = pCurrentAttr->get_baseName(&bstrAttrName);
        }
        
        if (SUCCEEDED(hr))
        {
            // If an attribute is not named "name", remove it
            if (wcscmp(bstrAttrName, L"name") != 0)
            {
                hr = pAttrMap->removeNamedItem(bstrAttrName, NULL);
            }
        }
    }
    
    return TRUE;
}

BOOL CMFCXPSSampleDoc::RemoveAllChildrenWithProperty(IXMLDOMNode* pNode)
{
    HRESULT hr = S_OK;
    CComPtr<IXMLDOMNodeList> pXMLDOMNodeList;

    hr = pNode->get_childNodes(&pXMLDOMNodeList);

    if (SUCCEEDED(hr))
    {
        IXMLDOMNode* pXMLChild = NULL;
        while (SUCCEEDED(hr) && (S_OK == (hr = pXMLDOMNodeList->nextNode(&pXMLChild))))           
        {
            CComBSTR bstrName;
            pXMLChild->get_baseName(&bstrName);
            if (wcscmp(bstrName, L"Property") == 0)
            {
                hr = pNode->removeChild(pXMLChild, NULL);
            }

            pXMLChild->Release();
        }
    }
    
    return TRUE;
}

const char gszTechnologyIdentifier[] = "http://schemas.microsoft.com/xps/2005/06";

BOOL CMFCXPSSampleDoc::IsXPSCapableDriver(HDC hdc)
{
    CHAR    lpszOutData[ARRAYSIZE(gszTechnologyIdentifier)] = {0};
    INT     cbOutput                                        = (INT) ( strlen(gszTechnologyIdentifier) + 1 );

    if (ExtEscape(hdc, GETTECHNOLOGY, 0, NULL, cbOutput, lpszOutData) < 0)
    {
        return FALSE;
    }
    
    return (strcmp(lpszOutData, gszTechnologyIdentifier) == 0);
}

/// This method is not used but may be a good examplle how to enumerate printers
BOOL CMFCXPSSampleDoc::SelectPrinter(CString& strPrinter)
{
	DWORD dwNeeded = 0;
	DWORD dwReturned = 0;

	EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 1, NULL, 0, &dwNeeded, &dwReturned);

	if (dwNeeded == 0)
	{
		return FALSE;
	}
	
	LPBYTE pPrinterData = new BYTE [dwNeeded];
	CStringArray arNames;

	if (EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 1, (LPBYTE)pPrinterData, dwNeeded, &dwNeeded, &dwReturned))
	{
		for (UINT i = 0; i < dwReturned; i++)
		{
			PRINTER_INFO_1* pPrintInfo = (PRINTER_INFO_1*)(pPrinterData + sizeof(PRINTER_INFO_1) * i); 
			arNames.Add(pPrintInfo->pName);
		}

		// display a dialog with printer names
		// for now set to Microsoft XPS Document Writer
		strPrinter = _T("Microsoft XPS Document Writer");
	}

	delete pPrinterData;
	return TRUE;
}
