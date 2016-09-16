
// SampleView.cpp : implementation of the CSampleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sample.h"
#endif

#include "SampleDoc.h"
#include "SampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleView

IMPLEMENT_DYNCREATE(CSampleView, CView)

BEGIN_MESSAGE_MAP(CSampleView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CSampleView construction/destruction

CSampleView::CSampleView()
{
	m_hWndElementHost = NULL;
	m_gotFocusHandler.SetEventHandler(this, &CSampleView::WpfElementHost_OnGotFocus);
}

CSampleView::~CSampleView()
{
	m_elementHost.GotFocus_RemoveEventHandler(m_gotFocusHandler);
	m_elementHost.Dispose();
}

BOOL CSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

// CSampleView drawing

void CSampleView::OnDraw(CDC* /*pDC*/)
{
	CSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSampleView diagnostics

#ifdef _DEBUG
void CSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleDoc* CSampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleDoc)));
	return (CSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleView message handlers


int CSampleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rcClient;
	GetClientRect(&rcClient);
	m_hWndElementHost = m_elementHost.Create(0, WS_VISIBLE | WS_CHILD, 0, 0, 0, rcClient.Width(), rcClient.Height(), L"", m_hWnd);
	m_elementHost.Element = m_sampleContent;
	m_elementHost.GotFocus_AddEventHandler(m_gotFocusHandler);

	return 0;
}


void CSampleView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if (m_hWndElementHost != NULL)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		::SetWindowPos(m_hWndElementHost, NULL, 0, 0, rcClient.Width(), rcClient.Height(), SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOOWNERZORDER);
	}
}

void CSampleView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	CWnd *pWndFocus = GetFocus();
	if (pWndFocus != NULL && IsChild(pWndFocus))
		return;

	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}


void CSampleView::OnSetFocus(CWnd* pOldWnd)
{
	if (m_hWndElementHost != NULL)
		::SetFocus(m_hWndElementHost);
	else
		CView::OnSetFocus(pOldWnd);
}


void CSampleView::WpfElementHost_OnGotFocus(const CManagedObjectProxy &sender, const CGotFocusEventArgsProxy &args)
{
	CFrameWnd* pParentFrame = GetParentFrame();
	if (pParentFrame)
		pParentFrame->SetActiveView(this);
}

BOOL CSampleView::PreTranslateMessage(MSG* pMsg)
{
	if (CView::PreTranslateMessage(pMsg))
		return TRUE;
	
	switch (pMsg->message)
	{
	case WM_KEYUP:
	case WM_KEYDOWN:
	case WM_SYSKEYUP:
	case WM_SYSKEYDOWN:
		{
			const IKeyboardInputSinkProxy &keyboardInputSink = m_elementHost.KeyboardInputSink;
			if (!keyboardInputSink.IsNull() && keyboardInputSink.TranslateAccelerator(pMsg))
				return TRUE;
		}
		break;
	default:
		break;
	}

	return FALSE;
}
