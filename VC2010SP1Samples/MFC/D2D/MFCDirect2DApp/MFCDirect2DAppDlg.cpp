// MFCDirect2DAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDirect2DApp.h"
#include "MFCDirect2DAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCDirect2DAppDlg dialog

CMFCDirect2DAppDlg::CMFCDirect2DAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCDirect2DAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableD2DSupport();

	m_pTextFormat = new CD2DTextFormat(GetRenderTarget(), _T("Verdana"), 50);

	if (m_pTextFormat->IsValid())
	{
		m_pTextFormat->Get()->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		m_pTextFormat->Get()->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	}

    static const D2D1_GRADIENT_STOP stops[] =
    {
        {   0.f,  { 0.f, 1.f, 1.f, 0.25f }  },
        {   1.f,  { 0.f, 0.f, 1.f, 1.f }  },
    };

	m_pLinearGradientBrush = new CD2DLinearGradientBrush(GetRenderTarget(), stops, ARRAYSIZE(stops),
				D2D1::LinearGradientBrushProperties(D2D1::Point2F(100, 0), D2D1::Point2F(100, 200)));

	m_pBlackBrush = new CD2DSolidColorBrush(GetRenderTarget(), D2D1::ColorF::Black);
	m_pBitmap = new CD2DBitmap(GetRenderTarget(), IDR_IMAGE1, NULL, CSize(100, 0));
	m_pAnotherBitmap = new CD2DBitmap(GetRenderTarget(), IDR_IMAGE1, NULL, CSize(100, 0));

	m_pPathGeometry = CreatePathGeometry(*GetRenderTarget());

	// Should be create later:
	m_pGridPatternBitmapBrush = NULL;
}

BEGIN_MESSAGE_MAP(CMFCDirect2DAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_REGISTERED_MESSAGE(AFX_WM_DRAW2D, &CMFCDirect2DAppDlg::OnAfxDraw2D)
END_MESSAGE_MAP()


// CMFCDirect2DAppDlg message handlers

BOOL CMFCDirect2DAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDirect2DAppDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectClient;
	GetClientRect(rectClient);

	CString strError = _T("There is no D2D available...");

	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(10, 10, strError);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDirect2DAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CD2DBitmapBrush* CMFCDirect2DAppDlg::CreateGridPatternBrush(CRenderTarget& renderTarget)
{
    // Create a compatible render target.
	CBitmapRenderTarget compatibleRenderTarget;
    if (!renderTarget.CreateCompatibleRenderTarget(compatibleRenderTarget, CSize(10, 10)))
	{
		return NULL;
	}

    // Draw a pattern.
    CD2DSolidColorBrush gridBrush(&compatibleRenderTarget, D2D1::ColorF(0.93f, 0.94f, 0.96f, 1.0f));

	compatibleRenderTarget.BeginDraw();
    compatibleRenderTarget.FillRectangle(CRect(0, 0, 10, 1), &gridBrush);
    compatibleRenderTarget.FillRectangle(CRect(0, 1, 1, 10), &gridBrush);
    compatibleRenderTarget.EndDraw();

    // Choose the tiling mode for the bitmap brush.
    D2D1_BITMAP_BRUSH_PROPERTIES brushProperties =
        D2D1::BitmapBrushProperties(D2D1_EXTEND_MODE_WRAP, D2D1_EXTEND_MODE_WRAP);

    // Create the bitmap brush.
	CD2DBitmapBrush* pBrush = new CD2DBitmapBrush(&renderTarget, &brushProperties);

    // Retrieve the bitmap from the render target.
    compatibleRenderTarget.GetBitmap(*pBrush->GetBitmap());
	return pBrush;
}

CD2DPathGeometry* CMFCDirect2DAppDlg::CreatePathGeometry(CRenderTarget& renderTarget)
{
	CD2DPathGeometry* pPathGeometry = new CD2DPathGeometry(&renderTarget);
	pPathGeometry->Create(&renderTarget);
	if (!pPathGeometry->IsValid())
	{
		delete pPathGeometry;
		return NULL;
	}

	CD2DGeometrySink sink(*pPathGeometry);
	if (!sink.IsValid())
	{
		delete pPathGeometry;
		return NULL;
	}

    sink.SetFillMode(D2D1_FILL_MODE_ALTERNATE);

    sink.BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);

    sink.AddLine(D2D1::Point2F(200, 0));
    sink.AddBezier(D2D1::BezierSegment(D2D1::Point2F(150, 50), D2D1::Point2F(150, 150), D2D1::Point2F(200, 200)));
    sink.AddLine(D2D1::Point2F(0, 200));
    sink.AddBezier(D2D1::BezierSegment(D2D1::Point2F(50, 150), D2D1::Point2F(50, 50), D2D1::Point2F(0, 0)));

    sink.EndFigure(D2D1_FIGURE_END_CLOSED);

	return pPathGeometry;
}


afx_msg LRESULT CMFCDirect2DAppDlg::OnAfxDraw2D(WPARAM /*wParam*/, LPARAM lParam)
{
	CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;
	ASSERT_VALID(pRenderTarget);

	if (m_pGridPatternBitmapBrush == NULL)
	{
		m_pGridPatternBitmapBrush = CreateGridPatternBrush(*pRenderTarget);
	}

    CString sc_helloWorld = _T("Hello, World!");

    // Retrieve the size of the render target.
    CSize renderTargetSize = pRenderTarget->GetSize();

    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    // Paint a grid background.
    pRenderTarget->FillRectangle(CRect (CPoint(0, 0), renderTargetSize), m_pGridPatternBitmapBrush);

    CSize size = m_pBitmap->GetSize();

    // Draw a bitmap in the upper-left corner of the window.
    pRenderTarget->DrawBitmap(m_pBitmap, CRect(0, 0, size.cx, size.cy));

    // Draw a bitmap at the lower-right corner of the window.
    size = m_pAnotherBitmap->GetSize();
    
	pRenderTarget->DrawBitmap(m_pAnotherBitmap,
        CRect(renderTargetSize.cx - size.cx, renderTargetSize.cy - size.cy, renderTargetSize.cx, renderTargetSize.cy));

    // Set the world transform to a 45 degree rotation at the center of the render target
    // and write "Hello, World".
	D2D1::Matrix3x2F rotation;
//	afxGlobalData.D2D1MakeRotateMatrix(45, D2D1::Point2F((float)renderTargetSize.cx / 2, (float)renderTargetSize.cy / 2), &rotation);
    pRenderTarget->SetTransform(rotation);

    pRenderTarget->DrawText(sc_helloWorld,
		CRect(0, 0, renderTargetSize.cx, renderTargetSize.cy), m_pBlackBrush, m_pTextFormat);

    // Reset back to the identity transform
    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(0, (float)renderTargetSize.cy - 200));

    // Fill the hour glass geometry with a gradient.
    pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);

    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Translation((float)renderTargetSize.cx - 200, 0));

    // Fill the hour glass geometry with a gradient.
    pRenderTarget->FillGeometry(m_pPathGeometry, m_pLinearGradientBrush);

	return TRUE;
}
