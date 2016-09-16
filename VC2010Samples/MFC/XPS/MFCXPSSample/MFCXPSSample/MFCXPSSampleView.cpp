
// MFCXPSSampleView.cpp : implementation of the CMFCXPSSampleView class
//

#include "stdafx.h"
#include "MFCXPSSample.h"

#include "MFCXPSSampleDoc.h"
#include "MFCXPSSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCXPSSampleView

IMPLEMENT_DYNCREATE(CMFCXPSSampleView, CHtmlView)

BEGIN_MESSAGE_MAP(CMFCXPSSampleView, CHtmlView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CMFCXPSSampleView::OnFilePrint)
END_MESSAGE_MAP()

// CMFCXPSSampleView construction/destruction

CMFCXPSSampleView::CMFCXPSSampleView()
{
	// TODO: add construction code here

}

CMFCXPSSampleView::~CMFCXPSSampleView()
{
}

BOOL CMFCXPSSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CMFCXPSSampleView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	UpdateView();
}

void CMFCXPSSampleView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	UpdateView();
}

void CMFCXPSSampleView::UpdateView()
{
	CString strPath = GetDocument()->GetTempFile();
	Navigate2(strPath, NULL, NULL);
}

// CMFCXPSSampleView printing


void CMFCXPSSampleView::OnFilePrintPreview()
{

	AFXPrintPreview(this);

}

void CMFCXPSSampleView::OnFilePrint()
{
	GetDocument()->PrintXPSFile();
}

void CMFCXPSSampleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCXPSSampleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{

	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CMFCXPSSampleView diagnostics

#ifdef _DEBUG
void CMFCXPSSampleView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMFCXPSSampleView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMFCXPSSampleDoc* CMFCXPSSampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCXPSSampleDoc)));
	return (CMFCXPSSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCXPSSampleView message handlers
