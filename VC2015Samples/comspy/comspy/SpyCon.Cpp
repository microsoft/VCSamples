// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "COMSpy.h"
#include "ComSpyCtl.h"
#include "SpyCon.h"

static LPTSTR gsSubKey = _T("Software\\Microsoft\\COMSpy");
/////////////////////////////////////////////////////////////////////////////
// CSpyCon


STDMETHODIMP CSpyCon::Run()
{
	RECT rcPos = { CW_USEDEFAULT, 0, 0, 0 };
	HMENU hMenu = LoadMenu(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MENU1));
	Create(GetDesktopWindow(), rcPos, _T("COM Spy"), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 0, PtrToUint(hMenu));
	//
	//	Set the right icon
	//
	HICON hIcon = LoadIcon(_Module.GetModuleInstance(), MAKEINTRESOURCE(IDI_MAIN));
	if (hIcon)
		SetIcon(hIcon, TRUE);

	// create the spy control
	CoCreateInstance(CLSID_ComSpy, NULL, CLSCTX_INPROC, IID_IOleObject, (void**)&m_pOleObject);
	if (!m_pOleObject)
	{
		MessageBox(_T("CoCreateInstance failed"));
		return 0;
	}
	m_pOleObject->SetClientSite(this);
	m_pOleObject -> QueryInterface(IID_IComSpy, (void **)&m_pSpy);
	_ASSERTE(m_pSpy);

// get our window state from the registry
	HKEY hKey = NULL;
	DWORD dwDisp;
	LONG lRes = RegCreateKeyEx(HKEY_LOCAL_MACHINE, gsSubKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,  NULL,  &hKey, &dwDisp);
	if (hKey)
	{

		DWORD dwType = REG_DWORD;
		DWORD dwSize = sizeof(m_wp.rcNormalPosition.left);
		lRes = RegQueryValueEx(hKey, _T("Left"), NULL, &dwType, (BYTE *)&m_wp.rcNormalPosition.left, &dwSize);
		lRes = RegQueryValueEx(hKey, _T("Top"), NULL, &dwType, (BYTE *)&m_wp.rcNormalPosition.top, &dwSize);
		lRes = RegQueryValueEx(hKey, _T("Right"), NULL, &dwType, (BYTE *)&m_wp.rcNormalPosition.right, &dwSize);
		lRes = RegQueryValueEx(hKey, _T("Bottom"), NULL, &dwType, (BYTE *)&m_wp.rcNormalPosition.bottom, &dwSize);
		lRes = RegQueryValueEx(hKey, _T("ShowWindow"), NULL, &dwType, (BYTE *)&m_wp.showCmd, &dwSize);			
		//always on top option
		lRes = RegQueryValueEx(hKey, _T("AlwaysOnTop"), NULL, &dwType, (BYTE *)&m_bTopmost, &dwSize);
		m_bTopmost = 1 - m_bTopmost;
		BOOL bHandled;
		OnAlwaysOnTop(0,0,0,bHandled);

		// save on exit
		lRes = RegQueryValueEx(hKey, _T("SaveOnExit"), NULL, &dwType, (BYTE *)&m_bSaveOnExit, &dwSize);

		// get the stream from the registry
		dwType = REG_BINARY;				
		lRes = RegQueryValueEx(hKey, _T("ControlProperties"), NULL, &dwType, NULL, &dwSize);
		if (lRes == ERROR_SUCCESS)
		{
			HGLOBAL hGlobal = GlobalAlloc(GPTR, dwSize);
			BYTE * pByte = (BYTE *)GlobalLock(hGlobal);
			lRes = RegQueryValueEx(hKey, _T("ControlProperties"), NULL, &dwType, (BYTE *)pByte, &dwSize);
			GlobalUnlock(hGlobal);
			IStream * pStream;
			CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);			
			
			CComQIPtr<IPersistStreamInit, &IID_IPersistStreamInit> pPersist(m_pSpy);
			_ASSERTE(pPersist.p);

			if (pPersist != NULL)
			{
				pPersist -> Load(pStream);

			}
			pStream -> Release();
		}		
	}


	if (!( ( m_wp.rcNormalPosition.right - m_wp.rcNormalPosition.left < 10) && (m_wp.rcNormalPosition.bottom - m_wp.rcNormalPosition.top < 10)))
		SetWindowPlacement(&m_wp);
	else
		ShowWindow(SW_SHOWNORMAL);

	GetClientRect(&rcPos);
	MSG msg;
	m_pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, &msg, this, 0, m_hWnd, &rcPos);	
	return S_OK;
}

//
//	show the select filter dialog
//
LRESULT CSpyCon::OnSelectFilter(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	_ASSERTE(m_pSpy);
	m_pSpy->SelectApplications();
	return 0;
}
//
//	the user clicks on the system menu
//
LRESULT CSpyCon::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{

	bHandled = FALSE; // always do default processing

	if (wParam == SC_CLOSE)
		OnExit(NULL, NULL, NULL, bHandled);
		

	return 0;
}
//
//	sets a glog to log to file
//	if the user hasn't chosen a log file, show the common dialog to allow them to select one
//
LRESULT CSpyCon::OnLogToFile(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{

	_ASSERTE(m_pSpy);
	BOOL bVal;
	m_pSpy -> get_LogToFile(&bVal);
	bVal = 1 - bVal;
	m_pSpy -> put_LogToFile(bVal);
	return 0;	
}
//
//	User wants to choose a log file -- show the common dialog
//
LRESULT CSpyCon::OnChooseLogFile(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	CComBSTR sFileName;
	BOOL bCanceled;
	m_pSpy -> ChooseLogFile(&sFileName, &bCanceled);
	return 0;
	
}
//
//	toggle the save on exit flag
//
LRESULT CSpyCon::OnToggleSaveOnExit(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)

{
	m_bSaveOnExit = 1 - m_bSaveOnExit;
	//
	//	the UI semantics are odd here...if you have this selected, and deselect it
	//  the fact you deselected it won't be saved (you have to click on "Save Now"
	//	so I'm going to always write what you choose to the registry if you deselect it

	if (FALSE == m_bSaveOnExit)
	{
		HKEY hKey = NULL;
		DWORD dwDisp;
		LONG lRes = RegCreateKeyEx(HKEY_LOCAL_MACHINE, gsSubKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,  NULL,  &hKey, &dwDisp);
		if (hKey)
		{
			lRes = RegSetValueEx(hKey, _T("SaveOnExit"), NULL, REG_DWORD, (BYTE *)&m_bSaveOnExit, sizeof(BOOL));
			RegCloseKey(hKey);
		}
	}

	return 0;	

}
//
//	toggle the show on screen flag
//
LRESULT CSpyCon::OnToggleShowOnScreen(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	_ASSERTE(m_pSpy);
	BOOL bVal;
	m_pSpy -> get_ShowOnScreen(&bVal);
	bVal = 1 - bVal;
	m_pSpy -> put_ShowOnScreen(bVal);
	return 0;	

}
//
//	update the UI in menus
//
LRESULT CSpyCon::OnInitMenu(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{

	HMENU hMenu = (HMENU)wParam;
	CComBSTR temp = "&Log to File ";
	CComBSTR sFileName;
	m_pSpy -> get_LogFile(&sFileName);
	if (sFileName.Length() > 5)
		temp += sFileName;
	else
		temp = "&Log To file...";

	USES_CONVERSION;
	ModifyMenu(hMenu, ID_LOG, MF_BYCOMMAND|MF_STRING, ID_LOG, OLE2T(temp));
	BOOL bVal;
	m_pSpy -> get_LogToFile(&bVal);
	CheckMenuItem(hMenu, ID_LOG,   bVal ? MF_BYCOMMAND|MF_CHECKED : MF_BYCOMMAND|MF_UNCHECKED); 
	m_pSpy -> get_ShowGridLines(&bVal);	
	CheckMenuItem(hMenu, ID_OPTIONS_GRID_LINES,  bVal ? MF_BYCOMMAND|MF_CHECKED : MF_BYCOMMAND|MF_UNCHECKED); 
	m_pSpy -> get_ShowOnScreen(&bVal);
	CheckMenuItem(hMenu, ID_SHOW_ON_SCREEN,  bVal ? MF_BYCOMMAND|MF_CHECKED : MF_BYCOMMAND|MF_UNCHECKED); 
	CheckMenuItem(hMenu, IDM_ON_TOP,  m_bTopmost ? MF_BYCOMMAND|MF_CHECKED : MF_BYCOMMAND|MF_UNCHECKED); 
	CheckMenuItem(hMenu, ID_SAVE_ON_EXIT,  m_bSaveOnExit ? MF_BYCOMMAND|MF_CHECKED : MF_BYCOMMAND|MF_UNCHECKED); 

	return 0;
}

//
//	show/hide gridlines in the list
//
//	NOTE:  This will only work if the user has installed IE 3.0 or greater
//
LRESULT CSpyCon::OnToggleGridLines(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{

	_ASSERTE(m_pSpy);
	BOOL bVal;
	m_pSpy -> get_ShowGridLines(&bVal);
	bVal = 1 - bVal;
	m_pSpy -> put_ShowGridLines(bVal);	
	return 0;
}
//
//	Toggle the Always on top option
//
LRESULT CSpyCon::OnAlwaysOnTop(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{

	m_bTopmost = 1 - m_bTopmost;
	if (m_bTopmost)
		SetWindowPos(HWND_TOPMOST, 0,0,0,0,	SWP_NOMOVE|SWP_NOSIZE);
	else
		SetWindowPos(HWND_NOTOPMOST, 0,0,0,0,	SWP_NOMOVE|SWP_NOSIZE);
	return 0;
}
//
//	show the standard Shell About box
//
LRESULT CSpyCon::OnAbout(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	m_pSpy -> About();
	return 0;
}
//
//	pick the font to use in the list
//
LRESULT CSpyCon::OnChooseFont(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	m_pSpy -> ChooseFont();
	return 0;
}
//
//	called on a WM_CLOSE & WM_SYSCOMMAND (SC_CLOSE) message.  If appropriate, save settings
//	and then destroy the window
//
LRESULT CSpyCon::OnExit(WORD /*wNotifyCode*/, WORD /* wID */, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	if (m_bSaveOnExit)
		SaveSettings();	
	m_pOleObject->Close(OLECLOSE_NOSAVE);
	SafeRelease(m_pOleObject);
	SafeRelease(m_pSpy);
	DestroyWindow();
	return 0;
}

//
//	save current settings to the registyr
//
LRESULT CSpyCon::OnSaveNow(WORD /*wNotifyCode*/, WORD /* wID */, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	SaveSettings();
	return 0;
}


//
//	clear the list box
//
LRESULT CSpyCon::OnClear(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	m_pSpy -> ClearAllEvents();
	return 0;
}


//
//	save the items in the list box to the log file
//
LRESULT CSpyCon::OnSave(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	m_pSpy -> SaveToFile();
	return 0;

}
//
//	saves settings.  asks the control fro a stream to save its state
//
HRESULT CSpyCon::SaveSettings()
{
	_ASSERTE(m_pSpy);
	if(!m_pSpy)
		return E_UNEXPECTED;
	HKEY hKey = NULL;
	DWORD dwDisp;
	LONG lRes = RegCreateKeyEx(HKEY_LOCAL_MACHINE, gsSubKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,  NULL,  &hKey, &dwDisp);
	if (hKey)
	{
		lRes = RegSetValueEx(hKey, _T("Left"), NULL, REG_DWORD, (BYTE *)&m_wp.rcNormalPosition.left, sizeof(m_wp.rcNormalPosition.left));
		lRes = RegSetValueEx(hKey, _T("Top"), NULL, REG_DWORD, (BYTE *)&m_wp.rcNormalPosition.top, sizeof(m_wp.rcNormalPosition.left));
		lRes = RegSetValueEx(hKey, _T("Right"), NULL, REG_DWORD, (BYTE *)&m_wp.rcNormalPosition.right, sizeof(m_wp.rcNormalPosition.left));
		lRes = RegSetValueEx(hKey, _T("Bottom"), NULL, REG_DWORD, (BYTE *)&m_wp.rcNormalPosition.bottom, sizeof(m_wp.rcNormalPosition.left));
		lRes = RegSetValueEx(hKey, _T("ShowWindow"), NULL, REG_DWORD, (BYTE *)&m_wp.showCmd, sizeof(BOOL));
		lRes = RegSetValueEx(hKey, _T("AlwaysOnTop"), NULL, REG_DWORD, (BYTE *)&m_bTopmost, sizeof(BOOL));
		lRes = RegSetValueEx(hKey, _T("SaveOnExit"), NULL, REG_DWORD, (BYTE *)&m_bSaveOnExit, sizeof(BOOL));


		CComQIPtr<IPersistStreamInit, &IID_IPersistStreamInit> pPersist(m_pSpy);
		_ASSERTE(pPersist.p);
		IStream * pStream;
		CreateStreamOnHGlobal(NULL, TRUE, &pStream);
		if (pPersist != NULL)
		{
			pPersist -> Save(pStream, TRUE);
			HGLOBAL hGlobal;
			GetHGlobalFromStream(pStream, &hGlobal);
			BYTE * pStByte = (BYTE *)GlobalLock(hGlobal);
			SIZE_T dwSize = GlobalSize(hGlobal);
			lRes = RegSetValueEx(hKey, _T("ControlProperties"), NULL, REG_BINARY, (BYTE *)pStByte, (DWORD) dwSize);
			GlobalUnlock(hGlobal);			
			
		}
		pStream -> Release();
		RegCloseKey(hKey);
	}
	return S_OK;
}
