// AtlCon1.h : Declaration of the CAtlCon
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
#include <oledlg.h>
#include "PropBrowseCtl.h"
#pragma comment(lib, "oledlg.lib")

/////////////////////////////////////////////////////////////////////////////
// CFileOpenDlg

class CFileOpenDlg : public CDialogImpl<CFileOpenDlg>
{
	BEGIN_MSG_MAP(CFileOpenDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnEndDialog)
		COMMAND_ID_HANDLER(IDCANCEL, OnEndDialog)
		COMMAND_ID_HANDLER(IDC_BROWSE, OnBrowse)
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Let the system set the focus
		return 1;
	}
	LRESULT OnEndDialog(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		CWindow(GetDlgItem(IDC_EDIT1)).GetWindowText(&m_bstrName);
		EndDialog(wID);
		return 0;
	}
	LRESULT OnBrowse(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		OLEUIINSERTOBJECT   io;
		TCHAR               szFile[_MAX_PATH];

		ZeroMemory(&io, sizeof(io));
		io.cbStruct = sizeof(io);
		szFile[0] = 0;
		io.lpszFile = szFile;
		io.cchFile = _MAX_PATH;
		io.dwFlags = IOF_DISABLELINK | IOF_DISABLEDISPLAYASICON | IOF_SHOWINSERTCONTROL | IOF_SELECTCREATECONTROL;

		if (OleUIInsertObject(&io) == OLEUI_OK)
		{
			if (io.dwFlags & IOF_CREATELINKOBJECT)
				MessageBox(_T("Sorry. Creation from a file is not currently supported."));
			else
			{
				LPOLESTR pszClsid = NULL;
				StringFromCLSID(io.clsid, &pszClsid);
				m_bstrName = pszClsid;
				CoTaskMemFree(pszClsid);
				EndDialog(IDOK);
			}
		}
		return 0;
	}

	enum { IDD = IDD_FILEOPEN };

	CComBSTR m_bstrName;
};

/////////////////////////////////////////////////////////////////////////////
// CAtlCon - Example of generic ActiveX Hosting window

class CAtlCon : public CWindowImpl<CAtlCon, CWindow, CWinTraits<WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE> >
{
public:
	DECLARE_WND_CLASS_EX(NULL, 0, 0)

	BEGIN_MSG_MAP(CAtlCon)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_FILE_OPEN, OnFileOpen)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		MESSAGE_HANDLER(WM_SIZE, OnSize)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnErase)
	END_MSG_MAP()

	void OnFinalMessage(HWND /*hWnd*/)
	{
		::PostQuitMessage(0);
		delete this;
	}

	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_spBrowserControl->put_Dispatch(NULL);
		m_spBrowserContainer->put_Dispatch(NULL);
		m_spBrowserControl.Release();
		m_spBrowserContainer.Release();
		bHandled = FALSE;
		return 0;
	}
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		AtlAxWinInit();
		RECT rcClient;
		GetClientRect(&rcClient);
		
		m_wndView.Create(m_hWnd, rcClient, COLE2T(m_dlgOpen.m_bstrName), WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, WS_EX_CLIENTEDGE);
		m_wndBrowserControl.Create(m_hWnd, rcClient, _T(""), WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
		m_wndBrowserContainer.Create(m_hWnd, rcClient, _T(""), WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
		// Create two instances of the property browser
		CPropertyBrowseControl::CreateInstance(&m_spBrowserControl);
		CPropertyBrowseControl::CreateInstance(&m_spBrowserContainer);
		{
			// Obtain a pointer to the container object
			CComPtr<IAxWinHostWindow> spContainer;
			m_wndBrowserControl.QueryHost(&spContainer);
			// Attach the browser control to the container
			spContainer->AttachControl(m_spBrowserControl, m_wndBrowserControl);
		}
		{
			// Obtain a pointer to the container object
			CComPtr<IAxWinHostWindow> spContainer;
			m_wndBrowserContainer.QueryHost(&spContainer);
			// Attach the browser control to the container
			spContainer->AttachControl(m_spBrowserContainer, m_wndBrowserContainer);
			// Get the container for the users control window
			CComPtr<IDispatch> spDispatch;
			m_wndView.QueryHost(&spDispatch);
			// Tell the browser to browse it
			m_spBrowserContainer->put_Dispatch(spDispatch);
		}
		return 0;
	}

	LRESULT OnErase(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& bHandled)
	{
		return 1;
	}

	LRESULT OnSize(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& /* lResult */)
	{
		RECT rcClient;
		GetClientRect(&rcClient);
		m_wndBrowserControl.MoveWindow(rcClient.left, rcClient.top, 250, rcClient.bottom / 2);
		m_wndBrowserContainer.MoveWindow(rcClient.left, rcClient.bottom / 2, 250, rcClient.bottom / 2);
		m_wndView.MoveWindow(rcClient.left+250, rcClient.top, rcClient.right-250, rcClient.bottom);
		return 0;
	}

	LRESULT OnFileOpen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		if (m_dlgOpen.DoModal(m_hWnd) == IDOK)
		{
			m_spBrowserControl->put_Dispatch(NULL);
			CComPtr<IAxWinHostWindow> spHost;
			m_wndView.QueryHost(&spHost);
			spHost->CreateControl(m_dlgOpen.m_bstrName, m_wndView, 0);
			CComPtr<IDispatch> spDispatch;
			m_wndView.QueryControl(&spDispatch);
			m_spBrowserControl->put_Dispatch(spDispatch);
		}
		return 0;
	}
	LRESULT OnFileExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		DestroyWindow();
		return 0;
	}

	CComPtr<IATLConPropertyBrowser> m_spBrowserContainer;
	CComPtr<IATLConPropertyBrowser> m_spBrowserControl;
	// This ActiveX control will browse the container
	CAxWindow m_wndBrowserContainer;
	// This ActiveX control will browse the control
	CAxWindow m_wndBrowserControl;
	// This ActiveX control will be defined by the user
	CAxWindow m_wndView;
	CFileOpenDlg m_dlgOpen;
};
