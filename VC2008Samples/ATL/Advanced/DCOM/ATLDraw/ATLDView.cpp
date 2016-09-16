// ATLDrawView.cpp : implementation of the CATLDrawView class
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
//

#include "preatldr.h"
#include "ATLDraw.h"

#include "ATLDDoc.h"
#include "ATLDView.h"

#define IID_DEFINED
#include "..\DrawServ\DrawServ_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView

IMPLEMENT_DYNCREATE(CATLDrawView, CView)

BEGIN_MESSAGE_MAP(CATLDrawView, CView)
	//{{AFX_MSG_MAP(CATLDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_SERVER_CONNECT, OnServerConnect)
	ON_COMMAND(ID_SERVER_DISCONNENT, OnServerDisconnent)
	ON_UPDATE_COMMAND_UI(ID_SERVER_CONNECT, OnUpdateServerConnect)
	ON_UPDATE_COMMAND_UI(ID_SERVER_DISCONNENT, OnUpdateServerDisconnent)
	ON_COMMAND(ID_VIEW_COLOR, OnViewColor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

BEGIN_INTERFACE_MAP(CATLDrawView, CCmdTarget)
	INTERFACE_PART(CATLDrawView, IID_IDrawServ, DrawServ)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView construction/destruction

CATLDrawView::CATLDrawView()
{
	HRESULT hr;

	hr = CoInitialize(NULL);
	ASSERT(SUCCEEDED(hr));

	hr = CoInitializeSecurity(NULL, -1, NULL, NULL,
		RPC_C_AUTHN_LEVEL_NONE, RPC_C_IMP_LEVEL_IDENTIFY, NULL, EOAC_NONE, NULL);
	ASSERT(SUCCEEDED(hr));

	m_bDragging = FALSE;
	m_pDrawServ = NULL;
	m_col = RGB(255, 0, 0);
}

CATLDrawView::~CATLDrawView()
{
	if (m_pDrawServ != NULL)
	{
		DisconnectSink(IID_IDrawServ,m_dwDrawServ);
		m_pDrawServ->Release();
	}
	CoUninitialize();
}

BOOL CATLDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView drawing

void CATLDrawView::OnDraw(CDC* pDC)
{
	pDC;
	CATLDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView printing

BOOL CATLDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CATLDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CATLDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView diagnostics

#ifdef _DEBUG
void CATLDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CATLDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CATLDrawDoc* CATLDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CATLDrawDoc)));
	return (CATLDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView message handlers

void CATLDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bDragging = TRUE;
	m_pos = point;

	CView::OnLButtonDown(nFlags, point);
}

void CATLDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDragging)
	{
		if (m_pDrawServ != NULL)
		{
			HRESULT hr;
			hr = m_pDrawServ->Draw(
				m_pos.x, m_pos.y,
				point.x, point.y,
				m_col);
			if (FAILED(hr))
			{
				TCHAR buf[32];
				wsprintf(buf, _T("%xd"), hr);
				AfxMessageBox(buf);
			}
		}
		m_pos = point;
	}

	CView::OnMouseMove(nFlags, point);
}

void CATLDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bDragging = FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CATLDrawView::Draw(long x1, long y1, long x2, long y2, unsigned long col)
{
	CClientDC dc(this);

	CPen pen(PS_SOLID, 2, (COLORREF) col);
	CPen* oldPen = dc.SelectObject(&pen);
	dc.MoveTo(x1, y1);
	dc.LineTo(x2, y2);
	dc.SelectObject(oldPen);
}

void CATLDrawView::OnServerConnect()
{
	HRESULT hr;

	hr = CoCreateInstance(CLSID_CDrawServ, NULL, CLSCTX_SERVER, IID_IDrawServ, (void**)&m_pDrawServ);
	if (FAILED(hr))
	{
		AfxMessageBox(_T("Failed to connect to server"));
		return;
	}

	IUnknown* pUnk;
	m_xDrawServ.QueryInterface(IID_IUnknown, (void**) &pUnk);
	if (ConnectSink(IID_IDrawServ, pUnk) == FALSE)
	{
		m_pDrawServ->Release();
		m_pDrawServ = NULL;
	}
	pUnk->Release();
}

void CATLDrawView::OnServerDisconnent()
{
	if (m_pDrawServ != NULL)
	{
		DisconnectSink(IID_IDrawServ,m_dwDrawServ);
		m_pDrawServ->Release();
		m_pDrawServ = NULL;
		AfxMessageBox("Disconnected");
	}
}

BOOL CATLDrawView::ConnectSink(REFIID iid, LPUNKNOWN punkSink)
{
	BOOL    bRC = FALSE;
	ASSERT(m_pDrawServ != NULL);

	LPCONNECTIONPOINTCONTAINER pConnPtCont;

	if ((m_pDrawServ != NULL) &&
		SUCCEEDED(m_pDrawServ->QueryInterface(IID_IConnectionPointContainer,
			(LPVOID*)&pConnPtCont)))
	{
		ATLENSURE(pConnPtCont != NULL);
		LPCONNECTIONPOINT pConnPt = NULL;

		HRESULT hRes = pConnPtCont->FindConnectionPoint(iid, &pConnPt);
		ASSERT(hRes == S_OK);
		if (SUCCEEDED(hRes))
		{
			ATLENSURE(pConnPt != NULL);
			hRes = pConnPt->Advise(punkSink, &m_dwDrawServ);
			if (FAILED(hRes))
			{
				TCHAR buf[32];
				wsprintf(buf, _T("%x"), hRes);
				AfxMessageBox(buf);
				return FALSE;
			}
			AfxMessageBox(_T("Connected"));
			bRC = TRUE;
			pConnPt->Release();
		}
		pConnPtCont->Release();
	}
	return bRC;
}

void CATLDrawView::DisconnectSink(REFIID iid, DWORD dwCookie)
{
	if (dwCookie == 0)
		return;

	ASSERT(m_pDrawServ != NULL);

	LPCONNECTIONPOINTCONTAINER pConnPtCont;

	if ((m_pDrawServ != NULL) &&
		SUCCEEDED(m_pDrawServ->QueryInterface(IID_IConnectionPointContainer,
			(LPVOID*)&pConnPtCont)))
	{
		ATLENSURE(pConnPtCont != NULL);
		LPCONNECTIONPOINT pConnPt = NULL;

		if (SUCCEEDED(pConnPtCont->FindConnectionPoint(iid, &pConnPt)))
		{
			ATLENSURE(pConnPt != NULL);
			pConnPt->Unadvise(dwCookie);
			pConnPt->Release();
		}

		pConnPtCont->Release();
	}
}

STDMETHODIMP_(ULONG) CATLDrawView::XDrawServ::AddRef()
{
	METHOD_PROLOGUE_EX(CATLDrawView, DrawServ)
	TRACE("AddRef\n");
	return (ULONG)pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CATLDrawView::XDrawServ::Release()
{
	METHOD_PROLOGUE_EX(CATLDrawView, DrawServ)
	TRACE("Release\n");
	return (ULONG)pThis->ExternalRelease();
}

STDMETHODIMP CATLDrawView::XDrawServ::QueryInterface(
	REFIID iid, LPVOID far * ppvObj)
{
	METHOD_PROLOGUE_EX(CATLDrawView, DrawServ)
	TRACE("QueryInterface\n");
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CATLDrawView::XDrawServ::Draw(
	long x1, long y1, long x2, long y2, unsigned long col)
{
	METHOD_PROLOGUE_EX(CATLDrawView, DrawServ)

	pThis->Draw(x1, y1, x2, y2, col);

	return S_OK;
}

void CATLDrawView::OnUpdateServerConnect(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pDrawServ == NULL);
}

void CATLDrawView::OnUpdateServerDisconnent(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pDrawServ != NULL);
}

void CATLDrawView::OnViewColor()
{
	CColorDialog dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_col = dlg.GetColor();
	}
}
