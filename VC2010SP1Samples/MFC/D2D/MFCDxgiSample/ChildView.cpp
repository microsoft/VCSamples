
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "MFCDxgiSample.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const D3D10_INPUT_ELEMENT_DESC CChildView::s_InputLayout[] =
{
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
    { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
};

const SimpleVertex CChildView::s_VertexArray[] =
{
    { D3DXVECTOR3( -1.0f, -1.0f, 1.0f ), D3DXVECTOR2( 1.0f, 1.0f )},
    { D3DXVECTOR3(  1.0f, -1.0f, 1.0f ), D3DXVECTOR2( 0.0f, 1.0f )},
    { D3DXVECTOR3(  1.0f,  1.0f, 1.0f ), D3DXVECTOR2( 0.0f, 0.0f )},
    { D3DXVECTOR3( -1.0f,  1.0f, 1.0f ), D3DXVECTOR2( 1.0f, 0.0f )}
};

const SHORT CChildView::s_FacesIndexArray[] =
{
    3, 1, 0,
    2, 1, 3
};

static CString sc_helloWorld = _T("Hello, World!");

// CChildView

CChildView::CChildView() :
    m_pDevice(NULL),
    m_pSwapChain(NULL),
    m_pRenderTargetView(NULL),
    m_pState(NULL),
    m_pDepthStencil(NULL),
    m_pDepthStencilView(NULL),
    m_pOffscreenTexture(NULL),
    m_pShader(NULL),
    m_pVertexBuffer(NULL),
    m_pVertexLayout(NULL),
    m_pFacesIndexBuffer(NULL),
    m_pTextureRV(NULL),
    m_pBackBufferTextBrush(NULL),
    m_pBackBufferGradientBrush(NULL),
    m_pGridPatternBitmapBrush(NULL),
    m_pLGBrush(NULL),
    m_pBlackBrush(NULL),
    m_pBitmap(NULL),
    m_pTechniqueNoRef(NULL),
    m_pWorldVariableNoRef(NULL),
    m_pViewVariableNoRef(NULL),
    m_pProjectionVariableNoRef(NULL),
    m_pDiffuseVariableNoRef(NULL),
    m_pTextFormat(NULL),
    m_pPathGeometry(NULL)
{
    static const CString msc_fontName = _T("Verdana");
    static const FLOAT msc_fontSize = 50;

	m_pTextFormat = new CD2DTextFormat(&m_Target, msc_fontName, msc_fontSize);

	// Center the text both horizontally and vertically.
	m_pTextFormat->Get()->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	m_pTextFormat->Get()->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	m_pPathGeometry = new CD2DPathGeometry(&m_Target);
	m_pPathGeometry->Create(&m_Target);

    CD2DGeometrySink sink(*m_pPathGeometry);

	sink.SetFillMode(D2D1_FILL_MODE_ALTERNATE);

    sink.BeginFigure(
        D2D1::Point2F(0, 0),
        D2D1_FIGURE_BEGIN_FILLED
        );

    sink.AddLine(D2D1::Point2F(200, 0));

    sink.AddBezier(
        D2D1::BezierSegment(
            D2D1::Point2F(150, 50),
            D2D1::Point2F(150, 150),
            D2D1::Point2F(200, 200))
        );

    sink.AddLine(D2D1::Point2F(0, 200));

    sink.AddBezier(
        D2D1::BezierSegment(
            D2D1::Point2F(50, 150),
            D2D1::Point2F(50, 50),
            D2D1::Point2F(0, 0))
        );

    sink.EndFigure(D2D1_FIGURE_END_CLOSED);
}

CChildView::~CChildView()
{
    SafeRelease(&m_pDevice);
    SafeRelease(&m_pSwapChain);
    SafeRelease(&m_pRenderTargetView);
    SafeRelease(&m_pState);
    SafeRelease(&m_pDepthStencil);
    SafeRelease(&m_pDepthStencilView);
    SafeRelease(&m_pOffscreenTexture);
    SafeRelease(&m_pShader);
    SafeRelease(&m_pVertexBuffer);
    SafeRelease(&m_pVertexLayout);
    SafeRelease(&m_pFacesIndexBuffer);
    SafeRelease(&m_pTextureRV);
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
    HRESULT hr = CreateDeviceResources();
	if (FAILED(hr))
	{
		return;
	}

    static float t = 0.0f;
    static DWORD dwTimeStart = 0;

    DWORD dwTimeCur = GetTickCount();
    if ( dwTimeStart == 0 )
    {
        dwTimeStart = dwTimeCur;
    }
    t = ( dwTimeCur - dwTimeStart) / 3000.0f;

    float a = (t * 360.0f) * ((float)D3DX_PI / 180.0f);
    D3DMatrixRotationY(&m_WorldMatrix, a);

    // Swap chain will tell us how big the back buffer is
    DXGI_SWAP_CHAIN_DESC swapDesc;
    hr = m_pSwapChain->GetDesc(&swapDesc);

    if (SUCCEEDED(hr))
    {
        m_pDevice->ClearDepthStencilView(
            m_pDepthStencilView,
            D3D10_CLEAR_DEPTH,
            1,
            0
            );

        // Draw a gradient background.
        {
            D2D1_SIZE_F targetSize = m_BackBufferRT.GetSize();

            m_BackBufferRT.BeginDraw();

            m_pBackBufferGradientBrush->Get()->SetTransform(
                D2D1::Matrix3x2F::Scale(targetSize)
                );

            D2D1_RECT_F rect = D2D1::RectF(
                0.0f,
                0.0f,
                targetSize.width,
                targetSize.height
                );

            m_BackBufferRT.FillRectangle(&rect, m_pBackBufferGradientBrush);

            hr = m_BackBufferRT.EndDraw();
        }
        if (SUCCEEDED(hr))
        {
            m_pDiffuseVariableNoRef->SetResource(NULL);
            m_pTechniqueNoRef->GetPassByIndex(0)->Apply(0);

            // Draw the D2D content into a D3D surface.
            hr = RenderD2DContentIntoSurface();
        }
        if (SUCCEEDED(hr))
        {
            m_pDiffuseVariableNoRef->SetResource(m_pTextureRV);

            // Update variables that change once per frame.
            m_pWorldVariableNoRef->SetMatrix((float*)&m_WorldMatrix);

            // Set the index buffer.
            m_pDevice->IASetIndexBuffer(m_pFacesIndexBuffer, DXGI_FORMAT_R16_UINT, 0);

            // Render the scene
            m_pTechniqueNoRef->GetPassByIndex(0)->Apply(0);

            m_pDevice->DrawIndexed(
                ARRAYSIZE(s_FacesIndexArray),
                0,
                0
                );

            // Draw some text using a red brush on top of everything
            {
                m_BackBufferRT.BeginDraw();

                m_BackBufferRT.SetTransform(D2D1::Matrix3x2F::Identity());

                // Text format object will center the text in layout
                D2D1_SIZE_F rtSize = m_BackBufferRT.GetSize();
                m_BackBufferRT.DrawText(
                    sc_helloWorld, D2D1::RectF(0.0f, 0.0f, rtSize.width, rtSize.height),
					m_pBackBufferTextBrush, m_pTextFormat);

                hr = m_BackBufferRT.EndDraw();
            }
            if (SUCCEEDED(hr))
            {
                hr = m_pSwapChain->Present(1, 0);
            }
        }
    }

    // If the device is lost for any reason, we need to recreate it
    if (hr == DXGI_ERROR_DEVICE_RESET ||
        hr == DXGI_ERROR_DEVICE_REMOVED ||
        hr == D2DERR_RECREATE_TARGET)
    {
        DiscardDeviceResources();
    }
}

HRESULT CChildView::RenderD2DContentIntoSurface()
{
    D2D1_SIZE_F renderTargetSize = m_Target.GetSize();

	m_Target.BeginDraw();

    m_Target.SetTransform(D2D1::Matrix3x2F::Identity());

    m_Target.Clear(D2D1::ColorF(D2D1::ColorF::White));

    m_Target.FillRectangle(
        D2D1::RectF(0.0f, 0.0f, renderTargetSize.width, renderTargetSize.height),
        m_pGridPatternBitmapBrush);

    D2D1_SIZE_F size = m_pBitmap->GetSize();

    m_Target.DrawBitmap(
        m_pBitmap,
        D2D1::RectF(0.0f, 0.0f, size.width, size.height)
        );

    // Draw the bitmap at the bottom corner of the window
    m_Target.DrawBitmap(
        m_pBitmap,
        D2D1::RectF(
            renderTargetSize.width - size.width,
            renderTargetSize.height - size.height,
            renderTargetSize.width,
            renderTargetSize.height)
        );

    // Set the world transform to a 45 degree rotation at the center of the render target
    // and write "Hello, World"
    m_Target.SetTransform(
        D2D1::Matrix3x2F::Rotation(
            45,
            D2D1::Point2F(
                renderTargetSize.width / 2,
                renderTargetSize.height / 2))
        );

    m_Target.DrawText(
        sc_helloWorld,
		D2D1::RectF(0, 0, renderTargetSize.width, renderTargetSize.height),
        m_pBlackBrush,
        m_pTextFormat
        );

    // Reset back to the identity transform
    m_Target.SetTransform(
        D2D1::Matrix3x2F::Translation(0, renderTargetSize.height - 200)
        );

    m_Target.FillGeometry(m_pPathGeometry, m_pLGBrush);

    m_Target.SetTransform(
        D2D1::Matrix3x2F::Translation(renderTargetSize.width - 200, 0)
        );

    m_Target.FillGeometry(m_pPathGeometry, m_pLGBrush);

	m_Target.EndDraw();

    return S_OK;
}

HRESULT CChildView::CreateDeviceResources()
{
    HRESULT hr = S_OK;
    RECT rcClient;
    ID3D10Device1 *pDevice = NULL;
    IDXGIDevice *pDXGIDevice = NULL;
    IDXGIAdapter *pAdapter = NULL;
    IDXGIFactory *pDXGIFactory = NULL;
    IDXGISurface *pSurface = NULL;

    GetClientRect(&rcClient);

    UINT nWidth = abs(rcClient.right - rcClient.left);
    UINT nHeight = abs(rcClient.bottom - rcClient.top);

    // If we don't have a device, need to create one now and all
    // accompanying D3D resources.
    if (!m_pDevice)
    {
        
        UINT nDeviceFlags = D3D10_CREATE_DEVICE_BGRA_SUPPORT;
        // Create device
        hr = CreateD3DDevice(
            NULL,
            D3D10_DRIVER_TYPE_HARDWARE,
            nDeviceFlags,
            &pDevice
            );

        if (FAILED(hr))
        {
            hr = CreateD3DDevice(
                NULL,
                D3D10_DRIVER_TYPE_WARP,
                nDeviceFlags,
                &pDevice
                );
        }

        if (SUCCEEDED(hr))
        {
            hr = pDevice->QueryInterface(&m_pDevice);
        }
        if (SUCCEEDED(hr))
        {
            hr = pDevice->QueryInterface(&pDXGIDevice);
        }
        if (SUCCEEDED(hr))
        {
            hr = pDXGIDevice->GetAdapter(&pAdapter);
        }
        if (SUCCEEDED(hr))
        {
            hr = pAdapter->GetParent(IID_PPV_ARGS(&pDXGIFactory));
        }
        if (SUCCEEDED(hr))
        {
            DXGI_SWAP_CHAIN_DESC swapDesc;
            ::ZeroMemory(&swapDesc, sizeof(swapDesc));

            swapDesc.BufferDesc.Width = nWidth;
            swapDesc.BufferDesc.Height = nHeight;
            swapDesc.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
            swapDesc.BufferDesc.RefreshRate.Numerator = 60;
            swapDesc.BufferDesc.RefreshRate.Denominator = 1;
            swapDesc.SampleDesc.Count = 1;
            swapDesc.SampleDesc.Quality = 0;
            swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swapDesc.BufferCount = 1;
            swapDesc.OutputWindow = GetSafeHwnd();
            swapDesc.Windowed = TRUE;

            hr = pDXGIFactory->CreateSwapChain(m_pDevice, &swapDesc, &m_pSwapChain);
        }

        if (SUCCEEDED(hr))
        {
            hr = CreateD3DDeviceResources();
        }
        if (SUCCEEDED(hr))
        {
            hr = RecreateSizedResources(nWidth, nHeight);
        }
        if (SUCCEEDED(hr))
        {
            hr = CreateD2DDeviceResources();
        }
    }

    SafeRelease(&pDevice);
    SafeRelease(&pDXGIDevice);
    SafeRelease(&pAdapter);
    SafeRelease(&pDXGIFactory);
    SafeRelease(&pSurface);

    return hr;
}

HRESULT CChildView::CreateD3DDevice(
    IDXGIAdapter *pAdapter,
    D3D10_DRIVER_TYPE driverType,
    UINT flags,
    ID3D10Device1 **ppDevice
    )
{
    HRESULT hr = S_OK;

    static const D3D10_FEATURE_LEVEL1 levelAttempts[] =
    {
        D3D10_FEATURE_LEVEL_10_0,
        D3D10_FEATURE_LEVEL_9_3,
        D3D10_FEATURE_LEVEL_9_2,
        D3D10_FEATURE_LEVEL_9_1,
    };

    for (UINT level = 0; level < ARRAYSIZE(levelAttempts); level++)
    {
        ID3D10Device1 *pDevice = NULL;
        hr = D3D10CreateDevice1(
            pAdapter,
            driverType,
            NULL,
            flags,
            levelAttempts[level],
            D3D10_1_SDK_VERSION,
            &pDevice
            );

        if (SUCCEEDED(hr))
        {
            // transfer reference
            *ppDevice = pDevice;
            pDevice = NULL;
            break;
        }

    }

    return hr;
}

HRESULT CChildView::CreateD3DDeviceResources()
{
    HRESULT hr = S_OK;


    // Create rasterizer state object
    D3D10_RASTERIZER_DESC rsDesc;
    rsDesc.AntialiasedLineEnable = FALSE;
    rsDesc.CullMode = D3D10_CULL_NONE;
    rsDesc.DepthBias = 0;
    rsDesc.DepthBiasClamp = 0;
    rsDesc.DepthClipEnable = TRUE;
    rsDesc.FillMode = D3D10_FILL_SOLID;
    rsDesc.FrontCounterClockwise = FALSE; // Must be FALSE for 10on9
    rsDesc.MultisampleEnable = FALSE;
    rsDesc.ScissorEnable = FALSE;
    rsDesc.SlopeScaledDepthBias = 0;

    hr = m_pDevice->CreateRasterizerState(&rsDesc, &m_pState);
    if (SUCCEEDED(hr))
    {
        m_pDevice->RSSetState(m_pState);
        m_pDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

        // Allocate a offscreen D3D surface for D2D to render our 2D content into
        D3D10_TEXTURE2D_DESC texDesc;
        texDesc.ArraySize = 1;
        texDesc.BindFlags = D3D10_BIND_RENDER_TARGET | D3D10_BIND_SHADER_RESOURCE;
        texDesc.CPUAccessFlags = 0;
        texDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
        texDesc.Height = 512;
        texDesc.Width = 512;
        texDesc.MipLevels = 1;
        texDesc.MiscFlags = 0;
        texDesc.SampleDesc.Count = 1;
        texDesc.SampleDesc.Quality = 0;
        texDesc.Usage = D3D10_USAGE_DEFAULT;

        hr = m_pDevice->CreateTexture2D(&texDesc, NULL, &m_pOffscreenTexture);
    }
    if (SUCCEEDED(hr))
    {
        // Convert the Direct2D texture into a Shader Resource View
        SafeRelease(&m_pTextureRV);
        hr = m_pDevice->CreateShaderResourceView(m_pOffscreenTexture, NULL, &m_pTextureRV);
    }
    if (SUCCEEDED(hr))
    {
        D3D10_BUFFER_DESC bd;
        bd.Usage = D3D10_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(s_VertexArray);
        bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
        bd.CPUAccessFlags = 0;
        bd.MiscFlags = 0;
        D3D10_SUBRESOURCE_DATA InitData;
        InitData.pSysMem = s_VertexArray;

        hr = m_pDevice->CreateBuffer(&bd, &InitData, &m_pVertexBuffer);
        if (SUCCEEDED(hr))
        {
            // Set vertex buffer
            UINT stride = sizeof(SimpleVertex);
            UINT offset = 0;
            ID3D10Buffer *pVertexBuffer = m_pVertexBuffer;

            m_pDevice->IASetVertexBuffers(
                0, // StartSlot
                1, // NumBuffers
                &pVertexBuffer,
                &stride,
                &offset
                );
        }
    }
    if (SUCCEEDED(hr))
    {
        D3D10_BUFFER_DESC bd;
        bd.Usage = D3D10_USAGE_DEFAULT;
        bd.ByteWidth = sizeof(s_FacesIndexArray);
        bd.BindFlags = D3D10_BIND_INDEX_BUFFER;
        bd.CPUAccessFlags = 0;
        bd.MiscFlags = 0;
        D3D10_SUBRESOURCE_DATA InitData;
        InitData.pSysMem = s_FacesIndexArray;

        hr = m_pDevice->CreateBuffer(&bd, &InitData, &m_pFacesIndexBuffer);
    }

    if (SUCCEEDED(hr))
    {
        // Load pixel shader
        hr = LoadResourceShader(
            m_pDevice,
            MAKEINTRESOURCE(IDR_PIXEL_SHADER),
            &m_pShader
            );
    }
    if (SUCCEEDED(hr))
    {
        // Obtain the technique
        m_pTechniqueNoRef = m_pShader->GetTechniqueByName("Render");
        hr = m_pTechniqueNoRef ? S_OK : E_FAIL;
    }
    if (SUCCEEDED(hr))
    {
        // Obtain the variables
        m_pWorldVariableNoRef = m_pShader->GetVariableByName("World")->AsMatrix();
        hr = m_pWorldVariableNoRef ? S_OK : E_FAIL;
    }
    if (SUCCEEDED(hr))
    {
        m_pViewVariableNoRef = m_pShader->GetVariableByName("View")->AsMatrix();
        hr = m_pViewVariableNoRef ? S_OK : E_FAIL;

        if (SUCCEEDED(hr))
        {
            // Initialize the view matrix.
            D3DXVECTOR3 Eye(0.0f, 2.0f, -6.0f);
            D3DXVECTOR3 At(0.0f, 0.0f, 0.0f);
            D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);
            D3DMatrixLookAtLH(&m_ViewMatrix, &Eye, &At, &Up);
            m_pViewVariableNoRef->SetMatrix((float*)&m_ViewMatrix);
        }
    }
    if (SUCCEEDED(hr))
    {
        m_pDiffuseVariableNoRef = m_pShader->GetVariableByName("txDiffuse")->AsShaderResource();
        hr = m_pDiffuseVariableNoRef ? S_OK : E_FAIL;
    }
    if (SUCCEEDED(hr))
    {
        m_pProjectionVariableNoRef = m_pShader->GetVariableByName("Projection")->AsMatrix();
        hr = m_pProjectionVariableNoRef ? S_OK : E_FAIL;
    }
    if (SUCCEEDED(hr))
    {
        // Define the input layout
        UINT numElements = ARRAYSIZE(s_InputLayout);

        // Create the input layout
        D3D10_PASS_DESC PassDesc;
        m_pTechniqueNoRef->GetPassByIndex(0)->GetDesc(&PassDesc);

        hr = m_pDevice->CreateInputLayout(
            s_InputLayout,
            numElements,
            PassDesc.pIAInputSignature,
            PassDesc.IAInputSignatureSize,
            &m_pVertexLayout
            );
        if (SUCCEEDED(hr))
        {
            // Set the input layout
            m_pDevice->IASetInputLayout(m_pVertexLayout);
        }
    }

    return hr;
}

HRESULT CChildView::RecreateSizedResources(UINT nWidth, UINT nHeight)
{
    HRESULT hr = S_OK;
    IDXGISurface *pBackBuffer = NULL;
    ID3D10Resource *pBackBufferResource = NULL;
    ID3D10RenderTargetView *viewList[1] = {NULL};

    // Ensure that nobody is holding onto one of the old resources
	m_BackBufferRT.Destroy(FALSE);
	SafeRelease(&m_pRenderTargetView);
    m_pDevice->OMSetRenderTargets(1, viewList, NULL);

    // Resize render target buffers
    hr = m_pSwapChain->ResizeBuffers(1, nWidth, nHeight, DXGI_FORMAT_B8G8R8A8_UNORM, 0);

    if (SUCCEEDED(hr))
    {
        D3D10_TEXTURE2D_DESC texDesc;
        texDesc.ArraySize = 1;
        texDesc.BindFlags = D3D10_BIND_DEPTH_STENCIL;
        texDesc.CPUAccessFlags = 0;
        texDesc.Format = DXGI_FORMAT_D16_UNORM;
        texDesc.Height = nHeight;
        texDesc.Width = nWidth;
        texDesc.MipLevels = 1;
        texDesc.MiscFlags = 0;
        texDesc.SampleDesc.Count = 1;
        texDesc.SampleDesc.Quality = 0;
        texDesc.Usage = D3D10_USAGE_DEFAULT;

        SafeRelease(&m_pDepthStencil);
        hr = m_pDevice->CreateTexture2D(&texDesc, NULL, &m_pDepthStencil);
    }

    if (SUCCEEDED(hr))
    {
        // Create the render target view and set it on the device
        hr = m_pSwapChain->GetBuffer(
            0,
            IID_PPV_ARGS(&pBackBufferResource)
            );
    }
    if (SUCCEEDED(hr))
    {
        D3D10_RENDER_TARGET_VIEW_DESC renderDesc;
        renderDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
        renderDesc.ViewDimension = D3D10_RTV_DIMENSION_TEXTURE2D;
        renderDesc.Texture2D.MipSlice = 0;

        SafeRelease(&m_pRenderTargetView);
        hr = m_pDevice->CreateRenderTargetView(pBackBufferResource, &renderDesc, &m_pRenderTargetView);
    }
    if (SUCCEEDED(hr))
    {
        D3D10_DEPTH_STENCIL_VIEW_DESC depthViewDesc;
        depthViewDesc.Format = DXGI_FORMAT_D16_UNORM;
        depthViewDesc.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2D;
        depthViewDesc.Texture2D.MipSlice = 0;

        SafeRelease(&m_pDepthStencilView);
        hr = m_pDevice->CreateDepthStencilView(m_pDepthStencil, &depthViewDesc, &m_pDepthStencilView);
    }
    if (SUCCEEDED(hr))
    {
        viewList[0] = m_pRenderTargetView;
        m_pDevice->OMSetRenderTargets(1, viewList, m_pDepthStencilView);

        // Set a new viewport based on the new dimensions
        D3D10_VIEWPORT viewport;
        viewport.Width = nWidth;
        viewport.Height = nHeight;
        viewport.TopLeftX = 0;
        viewport.TopLeftY = 0;
        viewport.MinDepth = 0;
        viewport.MaxDepth = 1;
        m_pDevice->RSSetViewports(1, &viewport);

        // Get a surface in the swap chain
        hr = m_pSwapChain->GetBuffer(
            0,
            IID_PPV_ARGS(&pBackBuffer)
            );
    }

    if (SUCCEEDED(hr))
    {
        // Reset the projection matrix now that the swapchain is resized.
        D3DMatrixPerspectiveFovLH(
            &m_ProjectionMatrix,
            (float)D3DX_PI * 0.24f, // fovy
            nWidth / (float)nHeight, // aspect
            0.1f, // zn
            100.0f // zf
            );

        m_pProjectionVariableNoRef->SetMatrix((float*)&m_ProjectionMatrix);
        // Create the DXGI Surface Render Target.
        FLOAT dpiX;
        FLOAT dpiY;
        afxGlobalData.GetDirect2dFactory()->GetDesktopDpi(&dpiX, &dpiY);

        D2D1_RENDER_TARGET_PROPERTIES props =
            D2D1::RenderTargetProperties(
                D2D1_RENDER_TARGET_TYPE_DEFAULT,
                D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED),
                dpiX,
                dpiY
                );

        // Create a Direct2D render target which can draw into the surface in the swap chain
		ID2D1RenderTarget* pRenderTarget = NULL;

        hr = afxGlobalData.GetDirect2dFactory()->CreateDxgiSurfaceRenderTarget(
            pBackBuffer,
            &props,
            &pRenderTarget
            );

		if (m_BackBufferRT.IsValid())
		{
			m_BackBufferRT.Destroy(FALSE);
		}

		m_BackBufferRT.Attach(pRenderTarget);
    }

    SafeRelease(&pBackBuffer);
    SafeRelease(&pBackBufferResource);

    return hr;
}

CD2DBitmapBrush* CChildView::CreateGridPatternBrush(CRenderTarget& renderTarget)
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

//	pBrush->Get()->SetOpacity(0.5f);
	return pBrush;
}

HRESULT CChildView::LoadResourceShader(
    ID3D10Device *pDevice,
    PCWSTR pszResource,
    ID3D10Effect **ppShader)
{
    HRESULT hr;

    HRSRC hResource = ::FindResource(HINST_THISCOMPONENT, pszResource, RT_RCDATA);
    hr = hResource ? S_OK : E_FAIL;

    if (SUCCEEDED(hr))
    {
        HGLOBAL hResourceData = ::LoadResource(HINST_THISCOMPONENT, hResource);
        hr = hResourceData ? S_OK : E_FAIL;

        if (SUCCEEDED(hr))
        {
            LPVOID pData = ::LockResource(hResourceData);
            hr = pData ? S_OK : E_FAIL;

            if (SUCCEEDED(hr))
            {
                hr = ::D3D10CreateEffectFromMemory(
                    pData,
                    ::SizeofResource(HINST_THISCOMPONENT, hResource),
                    0,
                    pDevice,
                    NULL,
                    ppShader
                    );
            }
        }
    }

    return hr;
}

HRESULT CChildView::CreateD2DDeviceResources()
{
    HRESULT hr = S_OK;
    
    IDXGISurface *pDxgiSurface = NULL;
    hr = m_pOffscreenTexture->QueryInterface(&pDxgiSurface);

	if (FAILED(hr))
	{
		return hr;
	}

	ID2D1RenderTarget* pRenderTarget = NULL;

	// Create a D2D render target which can draw into our offscreen D3D
    // surface. Given that we use a constant size for the texture, we
    // fix the DPI at 96.
    D2D1_RENDER_TARGET_PROPERTIES props =
        D2D1::RenderTargetProperties(
            D2D1_RENDER_TARGET_TYPE_DEFAULT,
            D2D1::PixelFormat(DXGI_FORMAT_UNKNOWN, D2D1_ALPHA_MODE_PREMULTIPLIED),
            96,
            96
            );

	hr = afxGlobalData.GetDirect2dFactory()->CreateDxgiSurfaceRenderTarget(
        pDxgiSurface,
        &props,
        &pRenderTarget
        );
    
	if (FAILED(hr))
	{
		return hr;
	}

	m_Target.Attach(pRenderTarget);

	// Create a linear gradient brush for the window background
    static const D2D1_GRADIENT_STOP stopsBackground[] =
    {
        { 0.f, { 0.f, 0.f, 0.2f, 1.f}}, // Starting with blue
        { 1.f, { 0.f, 0.f, 0.5f, 1.f}}  // Toward black
    };

    m_pBackBufferGradientBrush = new CD2DLinearGradientBrush(
        &m_BackBufferRT, 
        stopsBackground,
        ARRAYSIZE(stopsBackground),
		D2D1::LinearGradientBrushProperties(
            D2D1::Point2F(0.0f, 0.0f),
            D2D1::Point2F(0.0f, 1.0f)));

    // Create a red brush for text drawn into the back buffer
	m_pBackBufferTextBrush = new CD2DSolidColorBrush(&m_BackBufferRT, D2D1::ColorF(D2D1::ColorF::Red));

    // Create a linear gradient brush for the 2D geometry
    static const D2D1_GRADIENT_STOP stopsGeometry[] =
    {
        { 0.f, { 0.f, 1.f, 1.f, 0.25f}}, // Starting with lt.blue
        { 1.f, { 0.f, 0.f, 1.f, 1.f}},   // Toward blue
    };

    m_pLGBrush = new CD2DLinearGradientBrush(&m_Target, stopsGeometry, ARRAYSIZE(stopsGeometry), 
		D2D1::LinearGradientBrushProperties(
            D2D1::Point2F(100, 0),
            D2D1::Point2F(100, 200)));

	// create a black brush
	m_pBlackBrush = new CD2DSolidColorBrush(&m_Target, D2D1::ColorF(D2D1::ColorF::Black));

	m_pBitmap = new CD2DBitmap(&m_Target, IDR_SAMPLE_IMAGE, L"Image", CSize(100, 0));

	m_pGridPatternBitmapBrush = CreateGridPatternBrush(m_Target);

	return S_OK;
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
    if (m_pDevice == NULL)
    {
        // Recreate all device-dependent resources.
		if (cx > 0 && cy > 0)
		{
        	CreateDeviceResources();
		}
    }
    else
    {
        // Recreate only those resources that depend
        // on the window size.
        RecreateSizedResources(cx, cy);
    }
}

void CChildView::DiscardDeviceResources()
{
    SafeRelease(&m_pDevice);
    SafeRelease(&m_pSwapChain);
    SafeRelease(&m_pRenderTargetView);
    SafeRelease(&m_pState);

    SafeRelease(&m_pDepthStencil);
    SafeRelease(&m_pDepthStencilView);
    SafeRelease(&m_pOffscreenTexture);
    SafeRelease(&m_pShader);
    SafeRelease(&m_pVertexBuffer);
    SafeRelease(&m_pVertexLayout);
    SafeRelease(&m_pFacesIndexBuffer);
    SafeRelease(&m_pTextureRV);

	m_BackBufferRT.Destroy();
	m_Target.Destroy();
}

BOOL CChildView::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;
}
