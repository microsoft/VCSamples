
// MFCGdiInteropSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCGdiInteropSample.h"
#include "MFCGdiInteropSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCGdiInteropSampleDlg dialog




CMFCGdiInteropSampleDlg::CMFCGdiInteropSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCGdiInteropSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE_DEFAULT,
        D2D1::PixelFormat(
            DXGI_FORMAT_B8G8R8A8_UNORM,
            D2D1_ALPHA_MODE_IGNORE),
        0,
        0,
        D2D1_RENDER_TARGET_USAGE_NONE,
        D2D1_FEATURE_LEVEL_DEFAULT
        );

	m_RenderTarget.Create(props);

	m_pBlackBrush = new CD2DSolidColorBrush(&m_RenderTarget, D2D1::ColorF(D2D1::ColorF::Black));
}

BEGIN_MESSAGE_MAP(CMFCGdiInteropSampleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCGdiInteropSampleDlg message handlers

BOOL CMFCGdiInteropSampleDlg::OnInitDialog()
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

void CMFCGdiInteropSampleDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		return;
	}

	#define LINE_WIDTH	3

	CRect rc;
	GetClientRect(rc);

	dc.FillRect(rc, &afxGlobalData.brWindow);

    //
    // Draw the pie chart with Direct2D.
    //

	// Bind the DC to the DC render target.
	m_RenderTarget.BindDC(dc, rc);

    m_RenderTarget.BeginDraw();

    m_RenderTarget.SetTransform(D2D1::Matrix3x2F::Identity());

    m_RenderTarget.Clear(D2D1::ColorF(D2D1::ColorF::White));

    m_RenderTarget.DrawEllipse(CD2DEllipse(CD2DPointF(150.0f, 150.0f), CD2DSizeF(100., 100.)), m_pBlackBrush, LINE_WIDTH);

    m_RenderTarget.DrawLine(CD2DPointF(150.0f, 150.0f), 
        CD2DPointF(
            150.0f + 100.0f * 0.15425f,
            150.0f - 100.0f * 0.988f),
        m_pBlackBrush,
        LINE_WIDTH
        );

    m_RenderTarget.DrawLine(
        CD2DPointF(150.0f, 150.0f),
        CD2DPointF(
            150.0f + 100.0f * 0.525f,
            150.0f + 100.0f * 0.8509f),
        m_pBlackBrush,
        LINE_WIDTH
        );

    m_RenderTarget.DrawLine(
        CD2DPointF(150.0f, 150.0f),
        CD2DPointF(
            150.0f - 100.0f * 0.988f,
            150.0f - 100.0f * 0.15425f),
        m_pBlackBrush,
        LINE_WIDTH
        );

    HRESULT hr = m_RenderTarget.EndDraw();
    if (SUCCEEDED(hr))
    {
        //
        // Draw the pie chart with GDI.
        //

		CPen penBlack(PS_SOLID, LINE_WIDTH, RGB(0, 0, 0));
		CPen* pOldPen = dc.SelectObject(&penBlack);

        dc.Ellipse(300, 50, 500, 250);

        POINT pntArray1[2];
        pntArray1[0].x = 400;
        pntArray1[0].y = 150;
        pntArray1[1].x = static_cast<LONG>(400 + 100 * 0.15425);
        pntArray1[1].y = static_cast<LONG>(150 - 100 * 0.9885);

        POINT pntArray2[2];
        pntArray2[0].x = 400;
        pntArray2[0].y = 150;
        pntArray2[1].x = static_cast<LONG>(400 + 100 * 0.525);
        pntArray2[1].y = static_cast<LONG>(150 + 100 * 0.8509);


        POINT pntArray3[2];
        pntArray3[0].x = 400;
        pntArray3[0].y = 150;
        pntArray3[1].x = static_cast<LONG>(400 - 100 * 0.988);
        pntArray3[1].y = static_cast<LONG>(150 - 100 * 0.15425);

        dc.Polyline(pntArray1, 2);
        dc.Polyline(pntArray2, 2);
        dc.Polyline(pntArray3, 2);

		dc.SelectObject(&pOldPen);
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCGdiInteropSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CMFCGdiInteropSampleDlg::OnEraseBkgnd(CDC*)
{
	return TRUE;
}

