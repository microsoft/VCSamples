
// ChildView.h : interface of the CChildView class
//


#pragma once

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

struct SimpleVertex
{
    D3DXVECTOR3 Pos;
    D3DXVECTOR2 Tex;
};

template<class Interface>
inline void
SafeRelease(
    Interface **ppInterfaceToRelease
    )
{
    if (*ppInterfaceToRelease != NULL)
    {
        (*ppInterfaceToRelease)->Release();

        (*ppInterfaceToRelease) = NULL;
    }
}

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
protected:
    HRESULT RenderD2DContentIntoSurface();
	HRESULT CreateDeviceResources();
    HRESULT CreateD3DDeviceResources();
	HRESULT CreateD2DDeviceResources();

    HRESULT CreateD3DDevice(
        IDXGIAdapter *pAdapter,
        D3D10_DRIVER_TYPE driverType,
        UINT flags,
        ID3D10Device1 **ppDevice
        );

	HRESULT RecreateSizedResources(UINT nWidth, UINT nHeight);
	void DiscardDeviceResources();

	CD2DBitmapBrush* CreateGridPatternBrush(CRenderTarget& renderTarget);

    HRESULT LoadResourceShader(
        ID3D10Device *pDevice,
        PCWSTR pszResource,
        ID3D10Effect **ppEffect
        );

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

	CRenderTarget m_Target;

    D3DXMATRIX m_WorldMatrix;
    D3DXMATRIX m_ViewMatrix;
    D3DXMATRIX m_ProjectionMatrix;

    ID3D10Device *m_pDevice;
    IDXGISwapChain *m_pSwapChain;
    ID3D10RenderTargetView *m_pRenderTargetView;
    ID3D10RasterizerState *m_pState;
    ID3D10Texture2D *m_pDepthStencil;
    ID3D10DepthStencilView *m_pDepthStencilView;
    ID3D10Texture2D *m_pOffscreenTexture;
    ID3D10Effect *m_pShader;
    ID3D10Buffer *m_pVertexBuffer;
    ID3D10InputLayout *m_pVertexLayout;
    ID3D10Buffer *m_pFacesIndexBuffer;
    ID3D10ShaderResourceView *m_pTextureRV;

    CRenderTarget m_BackBufferRT;
    CD2DSolidColorBrush *m_pBackBufferTextBrush;
    CD2DLinearGradientBrush *m_pBackBufferGradientBrush;
    CD2DBitmapBrush *m_pGridPatternBitmapBrush;

    CD2DLinearGradientBrush *m_pLGBrush;
    CD2DSolidColorBrush *m_pBlackBrush;
    CD2DBitmap *m_pBitmap;

    ID3D10EffectTechnique *m_pTechniqueNoRef;
    ID3D10EffectMatrixVariable *m_pWorldVariableNoRef;
    ID3D10EffectMatrixVariable *m_pViewVariableNoRef;
    ID3D10EffectMatrixVariable *m_pProjectionVariableNoRef;
    ID3D10EffectShaderResourceVariable *m_pDiffuseVariableNoRef;

    // Device-Independent Resources
    CD2DTextFormat *m_pTextFormat;
    CD2DPathGeometry *m_pPathGeometry;

    static const D3D10_INPUT_ELEMENT_DESC s_InputLayout[];
    static const SimpleVertex s_VertexArray[];
    static const SHORT s_FacesIndexArray[];
};

