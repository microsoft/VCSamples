// ActiveCtl.h : Declaration of the CActiveDoc class
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "resource.h"       // main symbols
#include "OleDocument.h"
#include "Menu.h"
#include "ToolBar.h"
#include <RichEdit.h>

/////////////////////////////////////////////////////////////////////////////
// CActiveDoc
class CActiveDoc :
	public CComObjectRoot,
	public CComCoClass<CActiveDoc, &CLSID_CActiveDoc>,
	public CComControl<CActiveDoc>,
	public IDispatchImpl<IActiveDoc, &IID_IActiveDoc, &LIBID_ACTIVEDOCLib>,
	public IProvideClassInfoImpl<&CLSID_CActiveDoc, &LIBID_ACTIVEDOCLib>,
	public IPersistStreamInitImpl<CActiveDoc>,
	public IPersistStorageImpl<CActiveDoc>,
	public IQuickActivateImpl<CActiveDoc>,
	public IOleControlImpl<CActiveDoc>,
	public IOleObjectImpl<CActiveDoc>,
	public IOleInPlaceActiveObjectImpl<CActiveDoc>,
	public IViewObjectExImpl<CActiveDoc>,
	public IOleInPlaceObjectWindowlessImpl<CActiveDoc>,
	public IDataObjectImpl<CActiveDoc>,
	public ISupportErrorInfo,
	public IOleDocumentImpl<CActiveDoc>,
	public IOleDocumentViewImpl<CActiveDoc>,
	public CMenu<CActiveDoc>,
	public CToolbar<CActiveDoc>,
	public IPersistFile
{
public:
	CActiveDoc() :
	  m_wndRTF(_T("RichEdit"), this, 1)
	{
		m_wndRTF.m_hWnd = NULL;
		m_bWindowOnly = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ActiveDoc)

BEGIN_COM_MAP(CActiveDoc)
	COM_INTERFACE_ENTRY(IActiveDoc)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY_IMPL(IOleControl)
	COM_INTERFACE_ENTRY_IMPL(IOleObject)
	COM_INTERFACE_ENTRY_IMPL(IQuickActivate)
	COM_INTERFACE_ENTRY_IMPL(IPersistStorage)
	COM_INTERFACE_ENTRY_IMPL(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IOleDocument)
	COM_INTERFACE_ENTRY(IOleDocumentView)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IPersistFile)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CActiveDoc)
END_PROPERTY_MAP()

BEGIN_MSG_MAP(CActiveDoc)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackgnd)
	COMMAND_RANGE_HANDLER(ID_BLACK, ID_BLUE, OnColorChange)
	COMMAND_ID_HANDLER(ID_HELP_ABOUT, OnHelpAbout)
	NOTIFY_CODE_HANDLER(TTN_NEEDTEXT, OnToolbarNeedText)

	ALT_MSG_MAP(1)
END_MSG_MAP()

BEGIN_TOOLBAR_MAP(CActiveDoc)
	TOOLBAR_BUTTON(ID_BLACK)
	TOOLBAR_BUTTON(ID_RED)
	TOOLBAR_BUTTON(ID_GREEN)
	TOOLBAR_BUTTON(ID_BLUE)
	TOOLBAR_SEPARATOR()
	TOOLBAR_BUTTON(ID_HELP_ABOUT)
END_TOOLBAR_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IActiveDoc
public:

// Override SetClientSite
	HRESULT IOleObject_SetClientSite(IOleClientSite *pClientSite)
	{
		// If we currently have a document site pointer, release it.
		m_spDocSite.Release();
        m_bDocObject=FALSE;
        
		if (pClientSite != NULL)
		{
			pClientSite->QueryInterface(&m_spDocSite);
			if (m_spDocSite != NULL)
				m_bDocObject = true;
        }
		return CComControlBase::IOleObject_SetClientSite(pClientSite);
	}

// Override DoVerb
	STDMETHOD(DoVerb)(LONG iVerb, LPMSG pMsg, IOleClientSite* pActiveSite, LONG lindex,
									 HWND hwndParent, LPCRECT lprcPosRect)
	{
		// Check if we should activate as a docobject or not
		// (client supports IOleDocumentSite)
		if (m_bDocObject)
		{
			switch (iVerb)
			{
			case OLEIVERB_SHOW:
			case OLEIVERB_OPEN:
			case OLEIVERB_UIACTIVATE:
				if (!m_bUIActive)
					return m_spDocSite->ActivateMe(NULL);
			break;
			}
		}
		return IOleObjectImpl<CActiveDoc>::DoVerb(iVerb, pMsg, pActiveSite, lindex, hwndParent, lprcPosRect);
	}

	STDMETHOD(InPlaceDeactivate)(void)
	{
		// Release the pointers we have no need for now.
		m_spDocSite.Release();
		m_spInPlaceFrame.Release();

		return IOleInPlaceObjectWindowlessImpl<CActiveDoc>::InPlaceDeactivate();
	}

	// Override IOleInPlaceActiveObjectImpl::OnDocWindowActivate
	STDMETHOD(OnDocWindowActivate)(BOOL fActivate)
	{
		ATLTRACE(_T("CActiveDoc::OnDocWindowActivate\n"));
		if (fActivate)
		{
			InPlaceMenuCreate();
			SetupToolbar(NULL);
		}
		else
		{
			DestroyToolbar();
			InPlaceMenuDestroy();
		}
		return S_OK;
	}
	STDMETHOD(TranslateAccelerator)(MSG *pMsg)
	{
		ATLTRACE(_T("CActiveDoc::TranslateAccelerator\n"));

		if (pMsg == NULL)
			return E_POINTER;

		if (m_spInPlaceFrame != NULL)
			return OleTranslateAccelerator(m_spInPlaceFrame, &m_frameInfo, pMsg);
		else
			return S_FALSE;
	}
	// Override IPersistStorageImpl::IsDirty
	STDMETHOD(IsDirty)()
	{
		ATLTRACE(_T("CActiveDoc::IsDirty\n"));
		if (m_wndRTF.m_hWnd != NULL)
		{
			return (m_wndRTF.SendMessage(EM_GETMODIFY, 0, 0)) ? S_OK : S_FALSE;
		}
		else
			return S_FALSE;
	}
	// Override IPersistStreamInitImp::Save
	STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty)
	{
		ATLTRACE(_T("CActiveDoc::Save\n"));
		// We can only save if we have an RTF control to save data from
		if (m_wndRTF.m_hWnd != NULL)
		{
			EDITSTREAM  es;
			es.dwCookie     = (DWORD_PTR)pStm;
			es.dwError      = 0;
			es.pfnCallback  = RTFSave;
			m_wndRTF.SendMessage(EM_STREAMOUT, SF_RTF, (LPARAM)&es);
			if (fClearDirty)
				SetRTFModified(FALSE); // We're no longer dirty
		}
		return S_OK;
	}
	// Override IPersistStreamInitImp::Load
	STDMETHOD(Load)(LPSTREAM pStm)
	{
		ATLTRACE(_T("CActiveDoc::Load\n"));
		// Ensure the RTF window has been created, so that we can load data into it.
		if (m_wndRTF.m_hWnd == NULL)
			CreateRTFWindow();

		EDITSTREAM  es;
		es.dwCookie     = (DWORD_PTR)pStm;
		es.dwError      = 0;
		es.pfnCallback  = RTFLoad;
		m_wndRTF.SendMessage(EM_STREAMIN, SF_RTF, (LPARAM)&es);
		SetRTFModified(FALSE); // We're not dirty
		return S_OK;
	}
	static DWORD CALLBACK RTFSave(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG FAR *pcb)
	{
		HRESULT  hr;
		LPSTREAM pStm = (LPSTREAM)dwCookie;

		hr = pStm->Write(pbBuff, cb, (ULONG*)pcb);
		if (SUCCEEDED(hr))
			return 0;
		else
			return 1; // Failed so stop calling us.
	}
	static DWORD CALLBACK RTFLoad(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG FAR *pcb)
	{
		HRESULT  hr;
		LPSTREAM pStm = (LPSTREAM)dwCookie;

		hr = pStm->Read(pbBuff, cb, (ULONG*)pcb);
		if (SUCCEEDED(hr))
			return 0;
		else
			return 1; // Failed so stop calling us.
	}

	HRESULT OnDraw(ATL_DRAWINFO& /* di */)
	{
		// Drawing handled by RTF control
		return 0;
	}
	LRESULT OnEraseBackgnd(UINT, WPARAM, LPARAM, BOOL&)
	{
		return 0;
	}
	LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&)
	{
		// If we haven't created the RTF window then we need to create it. If not, is has already
		// been created by the Load procedure so we just make sure it is a parent of our window.
		if (m_wndRTF.m_hWnd == NULL)
			CreateRTFWindow();
		else
		{
			m_wndRTF.ModifyStyle(WS_POPUP, WS_CHILD | WS_VISIBLE);
			m_wndRTF.SetParent(m_hWnd);
		}
		return 0;
	}
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
	{
		// Destroy RTF window and unload the DLL
		m_wndRTF.DestroyWindow();
		FreeLibrary(m_hLibRTF);
		return 0;
	}
	LRESULT OnSetFocus(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// When the control window get's the focus, set the focus to the
		// RTF control.
		CComControl<CActiveDoc>::OnSetFocus(nMsg, wParam, lParam, bHandled);
		m_wndRTF.SetFocus();
		return 0;
	}
	void CreateRTFWindow()
	{
		DWORD dwStyle;
		RECT  rc;
		// If the control window has been created then we can use it's size otherwise default
		// to zero.
		if (m_hWnd == NULL)
		{
			// If the window isn't going to be a child at the moment, then don't set
			// WS_CHILD and don't make it visible yet
			dwStyle = WS_POPUP;
			ZeroMemory(&rc, sizeof(RECT));
		}
		else
		{
			dwStyle = WS_CHILD | WS_VISIBLE;
			GetWindowRect(&rc);
			rc.right -= rc.left;
			rc.bottom -= rc.top;
			rc.top = rc.left = 0;
		}
		
		TCHAR  infoBuf[MAX_PATH+1];
		GetSystemDirectory(infoBuf, sizeof(infoBuf) / sizeof(TCHAR));
		strcat_s(infoBuf, sizeof(infoBuf) / sizeof(TCHAR), _T("\\Riched32.dll"));
		m_hLibRTF = LoadLibrary(infoBuf);
		m_wndRTF.Create(m_hWnd, rc, NULL, dwStyle | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL, 0);
		ATLASSERT(m_wndRTF != NULL);
	}
	void SetRTFModified(BOOL bModified)
	{
		if (m_wndRTF.m_hWnd != NULL)
		{
			m_wndRTF.SendMessage(EM_SETMODIFY, (WPARAM)bModified, 0);
		}
	}
	// IOleInPlaceActiveObject::ResizeBorder
	STDMETHOD(ResizeBorder)(LPCRECT prcBorder, IOleInPlaceUIWindow* /* pUIWindow */, BOOL /* bFrameWindow */)
	{
		ATLTRACE(_T("CActiveDoc::ResizeBorder\n"));
	
		MoveToolbar(prcBorder);

		return S_OK;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		ATLTRACE("CActiveDoc::SetObjectRects(%d, %d,  %d, %d)\n", prcPos->left, prcPos->top, prcPos->right, prcPos->bottom);

		MoveToolbar();

		// When our control window moves, move the toolbar and the RTF window.
		IOleInPlaceObjectWindowlessImpl<CActiveDoc>::SetObjectRects(prcPos, prcClip);

		// Move the RTF control		
		if (m_wndRTF.m_hWnd != NULL)
		{
			m_wndRTF.SetWindowPos(NULL, 0, 0, prcPos->right - prcPos->left, prcPos->bottom - prcPos->top,
				SWP_NOZORDER | SWP_NOACTIVATE);
		}
		return S_OK;
	}
	HRESULT OnColorChange(WORD, WORD nID, HWND, BOOL&)
	{
		COLORREF col[4] =
		{
			RGB(0, 0, 0),   // Black
			RGB(255, 0, 0), // Red
			RGB(0, 255, 0), // Green
			RGB(0, 0, 255)  // Blue
		};
		CHARFORMAT cf;
		int nColor;
		nColor = nID - ID_BLACK;
		ATLENSURE(nColor >=0 && nColor <= sizeof(col)/sizeof(COLORREF));
		cf.cbSize = sizeof(CHARFORMAT);
		cf.dwMask = CFM_COLOR;
		cf.dwEffects = 0;
		cf.crTextColor = col[nColor];
		m_wndRTF.SendMessage(EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
		return 0;
	}


	// IPersistFile
    STDMETHODIMP GetClassID(CLSID* pClassID)
    {
		*pClassID = GetObjectCLSID();
		return S_OK;
    }

    STDMETHOD(Load)(LPCOLESTR pszFileName, DWORD dwMode)
	{
		USES_CONVERSION;
		HRESULT hr;
		CComPtr<IStorage>	spStorage;

		if (dwMode == 0)
			dwMode = STGM_DIRECT | STGM_READ | STGM_SHARE_DENY_WRITE;

		hr = ::StgOpenStorage(OLE2CW(pszFileName), NULL, 
			dwMode, 
			NULL, 0, &spStorage);
		if (FAILED(hr))
			return hr;

		// If the load fails we'll just start with an empty document
		IPersistStorageImpl<CActiveDoc>::Load(spStorage);

		return S_OK;
	}
    
    STDMETHOD(Save)(LPCOLESTR pszFileName, BOOL /* fRemember */)
	{
		USES_CONVERSION;
		HRESULT hr;
		CComPtr<IStorage>	spStorage;

		hr = ::StgOpenStorage(OLE2CW(pszFileName), NULL, 
			STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 
			NULL, 0, &spStorage);

		return IPersistStorageImpl<CActiveDoc>::Save(spStorage, false);
	}
    
    STDMETHOD(SaveCompleted)(LPCOLESTR /* pszFileName */) { return S_OK; }
    
    STDMETHOD(GetCurFile)(LPOLESTR* /* ppszFileName */) { return E_NOTIMPL; }

	class CAboutDlg : public CDialogImpl<CAboutDlg>
	{
	public:
		enum { IDD = IDD_ABOUT };
		BEGIN_MSG_MAP(CAboutDlg)
			COMMAND_ID_HANDLER(IDOK, OnOK)
		END_MSG_MAP()
		HRESULT OnOK(WORD, WORD, HWND, BOOL&)
		{
			EndDialog(0);
			return 0;
		}
	};
	HRESULT OnHelpAbout(WORD, WORD, HWND, BOOL&)
	{
		CAboutDlg dlg;
		dlg.DoModal();
		return 0;
	}

// Data
	CContainedWindow			m_wndRTF;
	HINSTANCE					m_hLibRTF;
	bool						m_bDocObject;
	CComPtr<IOleDocumentSite>	m_spDocSite;
	CComPtr<IOleInPlaceFrame>	m_spInPlaceFrame;
	OLEINPLACEFRAMEINFO			m_frameInfo;
};
