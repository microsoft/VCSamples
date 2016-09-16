// ATLDrawView.cpp : implementation of the CATLDrawView class
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.
//

#include "preatldr.h"
#include "ATLDraw.h"

#include "ATLDDoc.h"
#include "ATLDView.h"

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
    ON_COMMAND(ID_CLEAR, OnClear)
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

BEGIN_INTERFACE_MAP(CATLDrawView, CCmdTarget)
    INTERFACE_PART(CATLDrawView, __uuidof(IDrawServ), DrawServ)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CATLDrawView construction/destruction

CATLDrawView::CATLDrawView()
{
    HRESULT hr;

    hr = CoInitialize(NULL);
    _ASSERTE(SUCCEEDED(hr));

    hr = CoInitializeSecurity(NULL, -1, NULL, NULL,
        RPC_C_AUTHN_LEVEL_NONE, RPC_C_IMP_LEVEL_IDENTIFY, NULL, EOAC_NONE, NULL);
    _ASSERTE(SUCCEEDED(hr));

    m_bDragging = FALSE;
    m_col = RGB(255, 0, 0);
}

CATLDrawView::~CATLDrawView()
{
    if ((bool) m_pDrawServ)
    {
        DisconnectSink(__uuidof(IDrawServ), m_dwDrawServ);
        m_pDrawServ = 0;
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
            hr = m_pDrawServ->raw_Draw(
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
    if (SUCCEEDED(m_pDrawServ.CreateInstance(__uuidof(CDrawServ), NULL, CLSCTX_SERVER)))
    {
        IUnknown* pUnk;
        m_xDrawServ.QueryInterface(__uuidof(IUnknown), (void**) &pUnk);
        if (ConnectSink(__uuidof(IDrawServ), pUnk) == FALSE)
            m_pDrawServ = 0;
        pUnk->Release();
    }
    else
        AfxMessageBox(_T("Connect failed!"));
}

void CATLDrawView::OnServerDisconnent() 
{
    if ((bool) m_pDrawServ)
    {
        DisconnectSink(__uuidof(IDrawServ), m_dwDrawServ);  
        m_pDrawServ = 0;
    }
}

BOOL CATLDrawView::ConnectSink(REFIID iid, LPUNKNOWN punkSink)
{
    ASSERT((bool) m_pDrawServ);

    IConnectionPointContainerPtr pCPC;
    IConnectionPointPtr pCP;

    try {
    pCPC = m_pDrawServ;
    ASSERT((bool) pCPC);
    pCPC->FindConnectionPoint(iid, &pCP);
    ASSERT((bool) pCP);
    pCP->Advise(punkSink, &m_dwDrawServ);
    ASSERT(punkSink != NULL);
    } catch(_com_error& e) {
    dump_com_error(e);
    AfxMessageBox(_T("Connect failed!"));
    return FALSE;
    }
    
    AfxMessageBox(_T("Connected"));
    pCP = 0;
    pCPC = 0;
    return TRUE;
}

void CATLDrawView::DisconnectSink(REFIID iid, DWORD dwCookie)
{
    if (dwCookie == 0)
        return;

    ASSERT((bool) m_pDrawServ);

    IConnectionPointContainerPtr pCPC;
    IConnectionPointPtr pCP;

    try {
    pCPC = m_pDrawServ;
    ASSERT((bool) pCPC);
    pCPC->FindConnectionPoint(iid, &pCP);
    ASSERT((bool) pCP);
    pCP->Unadvise(dwCookie);
    } catch(_com_error& e) {
    dump_com_error(e);
    AfxMessageBox(_T("Disconnect failed!"));
    }
    
    AfxMessageBox(_T("Disconnected"));
    pCP = 0;
    pCPC = 0;
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

STDMETHODIMP CATLDrawView::XDrawServ::raw_Draw(
    long x1, long y1, long x2, long y2, unsigned long col)
{
    METHOD_PROLOGUE_EX(CATLDrawView, DrawServ)
    pThis->Draw(x1, y1, x2, y2, col);
    return S_OK;
}

void CATLDrawView::OnUpdateServerConnect(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(!(bool)m_pDrawServ);
}

void CATLDrawView::OnUpdateServerDisconnent(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable((bool) m_pDrawServ); 
}

void CATLDrawView::OnViewColor() 
{
    CColorDialog dlg;

    if (dlg.DoModal() == IDOK)
    {
        m_col = dlg.GetColor();
    }   
}

void CATLDrawView::OnClear() 
{
    Invalidate();   
}
