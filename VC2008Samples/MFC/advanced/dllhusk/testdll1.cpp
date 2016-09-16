// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#include "resource.h"       // main symbols
#include "testres1.h"       // symbols unique to this DLL

#include "testdll1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Initialization of MFC Extension DLL

#include "afxdllx.h"    // standard MFC Extension DLL routines

static AFX_EXTENSION_MODULE NEAR extensionDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		// Extension DLL one-time initialization.
		if (!AfxInitExtensionModule(extensionDLL, hInstance))
		   return 0;

		// Other initialization could be done here, as long as
		// it doesn't result in direct or indirect calls to AfxGetApp.
		// This extension DLL needs to add doc templates to the
		// app object, so it waits for the application to boot
		// and call an initialization function (see below).
	}
	return 1;   // ok
}

// Exported DLL initialization is run in context of running application
extern "C" void WINAPI InitTestDLL1()
{
	// create a new CDynLinkLibrary for this app
	#pragma warning(push)
	#pragma warning(disable:6211) //silence prefast warning because CDynLinkLibrary is cleaned up elsewhere
	new CDynLinkLibrary(extensionDLL);
	#pragma warning(pop)

	// Register the doc templates we provide to the app
	CWinApp* pApp = AfxGetApp();
	ENSURE(pApp != NULL);
	pApp->AddDocTemplate(new CMultiDocTemplate(IDR_TEXTTYPE,
			RUNTIME_CLASS(CTextDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CEditView)));
	pApp->AddDocTemplate(new CMultiDocTemplate(IDR_HELLOTYPE,
			RUNTIME_CLASS(CDummyDoc),
			RUNTIME_CLASS(CMDIChildWnd),
			RUNTIME_CLASS(CHelloView)));
	// add other initialization here
}

/////////////////////////////////////////////////////////////////////////////
// Example of a Simple CEditView (taken from MultiPad)

IMPLEMENT_DYNCREATE(CTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextDoc, CDocument)
	//{{AFX_MSG_MAP(CTextDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CTextDoc::Serialize(CArchive& ar)
{
	CEditView* pView = (CEditView*)m_viewList.GetHead();
	ASSERT_KINDOF(CEditView, pView);
	pView->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CHelloView : example of a simple output only document and view
//      (taken from Hello/MDI)

IMPLEMENT_DYNCREATE(CHelloView, CView)

BEGIN_MESSAGE_MAP(CHelloView, CView)
	//{{AFX_MSG_MAP(CHelloView)
	ON_WM_PAINT()
	ON_COMMAND(IDM_BLACK, OnColor)
	ON_COMMAND(IDM_CUSTOM, OnCustomColor)
	ON_COMMAND(IDM_RED, OnColor)
	ON_COMMAND(IDM_GREEN, OnColor)
	ON_COMMAND(IDM_BLUE, OnColor)
	ON_COMMAND(IDM_WHITE, OnColor)
	ON_UPDATE_COMMAND_UI(IDM_BLACK, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLUE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_GREEN, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_RED, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_WHITE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_CUSTOM, OnUpdateColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CHelloView::CHelloView()
{
	m_nIDColor = IDM_BLACK;
	m_clrText = RGB(0, 0, 0);
}

// OnDraw: Draw a string in the center of the client area.
void CHelloView::OnDraw(CDC* pDC)
{
	CRect rect;

	pDC->SetTextColor(m_clrText);
	pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
	GetClientRect(rect);
	pDC->DrawText(_T("Hello, World!"), -1, rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

/////////////////////////////////////////////////////////////////////////////
// CHelloView command

void CHelloView::OnUpdateColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nIDColor);
}

// Color array maps to order of the Color menu
static COLORREF NEAR colorArray[] =
{
	RGB (0, 0, 0),
	RGB (255, 0, 0),
	RGB (0, 255, 0),
	RGB (0, 0, 255),
	RGB (255, 255, 255)
};

void CHelloView::OnColor()
{
	m_nIDColor = LOWORD(GetCurrentMessage()->wParam);
	m_clrText = colorArray[m_nIDColor - IDM_BLACK];

	// Force the client area text to be repainted in the new color
	Invalidate();
}

void CHelloView::OnCustomColor()
{
	CColorDialog dlgColor(m_clrText);
	if (dlgColor.DoModal() == IDOK)
	{
		m_clrText = dlgColor.GetColor();
		m_nIDColor = IDM_CUSTOM;
		Invalidate();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDummyDoc : a do-nothing document that can be used with non-data views

IMPLEMENT_DYNCREATE(CDummyDoc, CDocument)

BEGIN_MESSAGE_MAP(CDummyDoc, CDocument)
	//{{AFX_MSG_MAP(CDummyDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
