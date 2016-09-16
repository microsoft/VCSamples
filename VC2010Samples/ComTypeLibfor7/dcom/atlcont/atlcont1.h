// AtlCont1.h : Declaration of the CAtlCont

#include "resource.h"       // main symbols
#include <oledlg.h>

/////////////////////////////////////////////////////////////////////////////
// CAtlCont
class CAtlCont : 
    public CComObjectRoot,
    public CComCoClass<CAtlCont, &CLSID_CAtlCont>,
    public CWindowImpl<CAtlCont>,
    public IAtlCont,
    public IOleClientSite,
    public IOleInPlaceSite
{
    class CAtlContDialog : public CDialogImpl<CAtlContDialog>
    {
        BSTR m_bstr;
    public:
        enum { IDD = IDD_DIALOG1 };

    BEGIN_MSG_MAP(CAtlContDialog)
        COMMAND_ID_HANDLER(IDC_CONNECT, OnConnect)
        COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    END_MSG_MAP()

        CAtlContDialog() { m_bstr = 0; }
        ~CAtlContDialog() { if (m_bstr) ::SysFreeString(m_bstr); }

        LRESULT OnConnect(WORD /* wNotifyCode */, WORD /* wID */, HWND /* hWndCtl */, BOOL& /* bHandled */)
        {   
            GetDlgItemText(IDC_EDIT1, m_bstr); 
            EndDialog(0);
            return 0;
        }
    
        LRESULT OnCancel(WORD /* wNotifyCode */, WORD /* wID */, HWND /* hWndCtl */, BOOL& /* bHandled */)
        {
            EndDialog(1);
            return 0;
        }

        const BSTR GetString() const { return m_bstr; }
    };


public:
    CAtlCont() { m_bInPlaceActive = FALSE; }

DECLARE_REGISTRY_RESOURCEID(IDR_AtlCont)

BEGIN_COM_MAP(CAtlCont)
    COM_INTERFACE_ENTRY(IAtlCont)
    COM_INTERFACE_ENTRY(IOleClientSite)
    COM_INTERFACE_ENTRY(IOleWindow)
    COM_INTERFACE_ENTRY(IOleInPlaceSite)
END_COM_MAP()

BEGIN_MSG_MAP(CAtlCont)
    MESSAGE_HANDLER(WM_NCDESTROY, OnNCDestroy)
    COMMAND_ID_HANDLER(ID_CONNECT, OnConnect)
    COMMAND_ID_HANDLER(ID_DISCONNECT, OnDisconnect)
    COMMAND_ID_HANDLER(ID_CLEAR, OnClear)
    MESSAGE_HANDLER(WM_SIZE, OnSize)
    MESSAGE_HANDLER(WM_ERASEBKGND, OnErase)
END_MSG_MAP()

    LRESULT OnNCDestroy(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& /* lResult */)
    {
        Stop();
        return 0;
    }

    LRESULT OnErase(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& bHandled)
    {
        if (m_bInPlaceActive)
            return 0;
        bHandled = FALSE;
        return 1;
    }

    LRESULT OnSize(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& /* lResult */)
    {
        if (m_pOleObject && m_bInPlaceActive)
        {
            CComQIPtr<IOleInPlaceObject, &IID_IOleInPlaceObject> pInPlaceObject(m_pOleObject);
            RECT rcClient;
            GetClientRect(&rcClient);
            pInPlaceObject->SetObjectRects(&rcClient, &rcClient);
        }
        return 0;
    }

    LRESULT OnConnect(WORD /* wNotifyCode */, WORD /* wID */, HWND /* hWndCtl */, BOOL& /* bHandled */)
    {
        CAtlContDialog dialog;
        if (dialog.DoModal())
            return 0;

        HCURSOR hPrevCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));

        if (m_pOleObject)
        {
            m_pOleObject->Close(OLECLOSE_NOSAVE);
            m_pOleObject.Release();
        }
        m_bInPlaceActive = FALSE;

        HRESULT hr = CoCreateInstance(__uuidof(CDrawCtl), NULL, CLSCTX_INPROC, IID_IOleObject, (void**)&m_pOleObject);
        if (!m_pOleObject || FAILED(hr))
        {
            MessageBox(_T("CoCreateInstance failed"));
            return 0;
        }

        hr = m_pOleObject->SetClientSite(this);

        MSG msg;
        RECT rcPos;
        GetClientRect(&rcPos);

        if (SUCCEEDED(hr))
        {
            m_pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, &msg, this, 0, m_hWnd, &rcPos);
            m_pDrawCtl = m_pOleObject;
            if (m_pDrawCtl)
            hr = m_pDrawCtl->Connect(dialog.GetString());
        }
        
        if (FAILED(hr))
            MessageBox(_T("Connected failed!"));
        else
        {
            //MessageBox(_T("Connected!"), _T("Success"));
            ::EnableMenuItem(GetMenu(), ID_DISCONNECT, MF_ENABLED);
            ::EnableMenuItem(GetMenu(), ID_CONNECT, MF_GRAYED);
            DrawMenuBar();
        }
        SetCursor(hPrevCursor);
        return 0;
    }

    LRESULT OnDisconnect(WORD /* wNotifyCode */, WORD /* wID */, HWND /* hWndCtl */, BOOL& /* bHandled */)
    {
        HCURSOR hPrevCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
        HRESULT hr = m_pDrawCtl->Disconnect();
        if (FAILED(hr))
            MessageBox(_T("Disconnect failed!"));
        else
        {
            //MessageBox(_T("Disconnected!"), _T("Success"));
            ::EnableMenuItem(GetMenu(), ID_CONNECT, MF_ENABLED);
            ::EnableMenuItem(GetMenu(), ID_DISCONNECT, MF_GRAYED);
            DrawMenuBar();
        }
        SetCursor(hPrevCursor);
        return 0;
    }

    LRESULT OnClear(WORD /* wNotifyCode */, WORD /* wID */, HWND /* hWndCtl */, BOOL& /* bHandled */)
    {
        HRESULT hr = m_pDrawCtl->Clear();
        if (FAILED(hr))
            MessageBox(_T("Clear failed!"), _T("Success"));
        return 0;
    }

// IAtlCont
public:
    STDMETHOD(Run)()
    {
        RECT rcPos = { CW_USEDEFAULT, 0, 0, 0 };
        HMENU hMenu = LoadMenu(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
        Create(GetDesktopWindow(), rcPos, _T("ATL Container"), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 0, (_U_MENUorID) hMenu);
        ShowWindow(SW_SHOWNORMAL);
        ::EnableMenuItem(GetMenu(), ID_DISCONNECT, MF_GRAYED);
        DrawMenuBar();
        return S_OK;
    }
    STDMETHOD(Stop)()
    {
        PostQuitMessage(0);
        return S_OK;
    }

// IOleClientSite
public:
    STDMETHOD(SaveObject)(void)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::SaveObject"));
    }
    STDMETHOD(GetMoniker)(DWORD /* dwAssign */, DWORD /* dwWhichMoniker */, IMoniker ** /* ppmk */)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::GetMoniker"));
    }
    STDMETHOD(GetContainer)(IOleContainer ** /* ppContainer */)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::GetContainer"));
    }
    STDMETHOD(ShowObject)(void)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::ShowObject"));
    }
    STDMETHOD(OnShowWindow)(BOOL /* fShow */)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::OnShowWindow"));
    }
    STDMETHOD(RequestNewObjectLayout)(void)
    {
        ATLTRACENOTIMPL(_T("IOleClientSite::RequestNewObjectLayout"));
    }


// IOleWindow
public:
    STDMETHOD(GetWindow)(HWND *phwnd)
    {
        *phwnd = m_hWnd;
        return S_OK;
    }
    STDMETHOD(ContextSensitiveHelp)(BOOL /* fEnterMode */)
    {
        ATLTRACENOTIMPL(_T("IOleWindow::CanInPlaceActivate"));
    }

// IOleInPlaceSite
public:
    STDMETHOD(CanInPlaceActivate)(void)
    {
        return S_OK;
    }
    STDMETHOD(OnInPlaceActivate)(void)
    {
        m_bInPlaceActive = TRUE;
        return S_OK;
    }
    STDMETHOD(OnUIActivate)(void)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::OnUIActivate"));
    }
    STDMETHOD(GetWindowContext)(IOleInPlaceFrame ** /* ppFrame */, IOleInPlaceUIWindow ** /* ppDoc */,
        LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO /* lpFrameInfo */)
    {
        GetClientRect(lprcPosRect);
        GetClientRect(lprcClipRect);
        return S_OK;
    }
    STDMETHOD(Scroll)(SIZE /* scrollExtant */)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::Scroll"));
    }
    STDMETHOD(OnUIDeactivate)(BOOL /* fUndoable */)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::OnUIDeactivate"));
    }
    STDMETHOD(OnInPlaceDeactivate)( void)
    {
        m_bInPlaceActive = FALSE;
        return S_OK;
    }
    STDMETHOD(DiscardUndoState)( void)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::DiscardUndoState"));
    }
    STDMETHOD(DeactivateAndUndo)( void)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::DeactivateAndUndo"));
    }
    STDMETHOD(OnPosRectChange)(LPCRECT /* lprcPosRect */)
    {
        ATLTRACENOTIMPL(_T("IOleInPlaceSite::OnPosRectChange"));
    }

    CComPtr<IOleObject> m_pOleObject;
    CComQIPtr<IDrawCtl, &__uuidof(IDrawCtl)> m_pDrawCtl;
    BOOL m_bInPlaceActive;
};
