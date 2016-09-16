// DrawServ.cpp : Implementation of WinMain
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL,
//      run nmake -f DrawServps.mak in the project directory.

#include "predraw.h"
#include "drawres.h"
#include "initguid.h"
#include "DrawServ.h"
#include "DrawObj.h"

#define IID_DEFINED
#include "DrawServ_i.c"


#include <stdio.h>
#include <atlstr.h>

CServiceModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_CDrawServ, CDrawObj)
END_OBJECT_MAP()


// Although some of these functions are big they are declared inline since they are only used once

inline HRESULT CServiceModule::RegisterServer(BOOL bRegTypeLib)
{
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
		return hr;

	// Remove any previous service since it may point to
	// the incorrect file
	Uninstall();
	// Add service entries
	UpdateRegistryFromResource(IDR_DrawServ, TRUE);
	// Create service
	Install();
	// Add object entries
	HRESULT hRes = CComModule::RegisterServer(bRegTypeLib);

	CoUninitialize();
	return hRes;
}

inline HRESULT CServiceModule::UnregisterServer()
{
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
		return hr;

	// Remove service entries
	UpdateRegistryFromResource(IDR_DrawServ, FALSE);
	// Remove service
	Uninstall();
	// Remove object entries
	CComModule::UnregisterServer();

	CoUninitialize();
	return S_OK;
}

inline void CServiceModule::Init(_ATL_OBJMAP_ENTRY* p, HINSTANCE h, UINT nServiceNameID)
{
	CComModule::Init(p, h);

	m_bService = TRUE;

	LoadString(h, nServiceNameID, m_szServiceName, sizeof(m_szServiceName) / sizeof(TCHAR));

	// set up the initial service status
	m_hServiceStatus = NULL;
	m_status.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	m_status.dwCurrentState = SERVICE_STOPPED;
	m_status.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	m_status.dwWin32ExitCode = 0;
	m_status.dwServiceSpecificExitCode = 0;
	m_status.dwCheckPoint = 0;
	m_status.dwWaitHint = 0;
}

LONG CServiceModule::Unlock()
{
	LONG l = CComModule::Unlock();
	if (l == 0 && !m_bService)
		PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
	return l;
}

BOOL CServiceModule::IsInstalled()
{
	BOOL bResult = FALSE;

	SC_HANDLE hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hSCM != NULL)
	{
		SC_HANDLE hService = ::OpenService(hSCM, m_szServiceName, SERVICE_QUERY_CONFIG);
		if (hService != NULL)
		{
			bResult = TRUE;
			::CloseServiceHandle(hService);
		}
		::CloseServiceHandle(hSCM);
	}
	return bResult;
}

inline BOOL CServiceModule::Install()
{
	if (IsInstalled())
		return TRUE;

	SC_HANDLE hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hSCM == NULL)
	{
		MessageBox(NULL, _T("Couldn't open service manager"), m_szServiceName, MB_OK);
		return FALSE;
	}

	// Get the executable file path
	TCHAR szFilePath[_MAX_PATH];
	DWORD dwFLen = ::GetModuleFileName(NULL, szFilePath, _MAX_PATH);
	if( dwFLen == 0 || dwFLen == MAX_PATH )
	{
		MessageBox(NULL, _T("GetModuleFileName failed"), m_szServiceName, MB_OK);
		return FALSE;
	}

	SC_HANDLE hService = ::CreateService(
		hSCM, m_szServiceName, m_szServiceName,
		SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS,
		SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL,
		szFilePath, NULL, NULL, _T("RPCSS\0"), NULL, NULL);

	if (hService == NULL)
	{
		::CloseServiceHandle(hSCM);
		MessageBox(NULL, _T("Couldn't create service"), m_szServiceName, MB_OK);
		return FALSE;
	}

	::CloseServiceHandle(hService);
	::CloseServiceHandle(hSCM);
	return TRUE;
}

inline BOOL CServiceModule::Uninstall()
{
	if (!IsInstalled())
		return TRUE;

	SC_HANDLE hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

	if (hSCM == NULL)
	{
		MessageBox(NULL, _T("Couldn't open service manager"), m_szServiceName, MB_OK);
		return FALSE;
	}

	SC_HANDLE hService = ::OpenService(hSCM, m_szServiceName, SERVICE_STOP | DELETE);

	if (hService == NULL)
	{
		::CloseServiceHandle(hSCM);
		MessageBox(NULL, _T("Couldn't open service"), m_szServiceName, MB_OK);
		return FALSE;
	}
	SERVICE_STATUS status;
	::ControlService(hService, SERVICE_CONTROL_STOP, &status);

	BOOL bDelete = ::DeleteService(hService);
	::CloseServiceHandle(hService);
	::CloseServiceHandle(hSCM);

	if (bDelete)
		return TRUE;

	MessageBox(NULL, _T("Service could not be deleted"), m_szServiceName, MB_OK);
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////
// Logging functions
void CServiceModule::LogEvent(LPCTSTR pFormat, ...)
{
	TCHAR    chMsg[256];
	HANDLE  hEventSource;
	LPTSTR  lpszStrings[1];
	va_list pArg;

	va_start(pArg, pFormat);
	_vsntprintf_s(chMsg, sizeof(chMsg), 256, pFormat, pArg);
	chMsg[255] = 0;
	va_end(pArg);

	lpszStrings[0] = chMsg;

	if (m_bService)
	{
		/* Get a handle to use with ReportEvent(). */
		hEventSource = RegisterEventSource(NULL, m_szServiceName);
		if (hEventSource)
		{
			/* Write to event log. */
			ReportEvent(hEventSource, EVENTLOG_INFORMATION_TYPE, 0, 0, NULL, 1, 0, (LPCTSTR*) &lpszStrings[0], NULL);
			DeregisterEventSource(hEventSource);
		}
	}
	else
	{
		// As we are not running as a service, just write the error to the console.
		_putts(chMsg);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Service startup and registration
inline void CServiceModule::Start()
{
	SERVICE_TABLE_ENTRY st[] =
	{
		{ m_szServiceName, _ServiceMain },
		{ NULL, NULL }
	};
	if (m_bService && !::StartServiceCtrlDispatcher(st))
	{
		m_bService = FALSE;
	}
	if (m_bService == FALSE)
		Run();
}


inline void CServiceModule::ServiceMain(DWORD /* dwArgc */, LPTSTR* /* lpszArgv */)
{
	// Register the control request handler
	m_status.dwCurrentState = SERVICE_START_PENDING;
	m_hServiceStatus = RegisterServiceCtrlHandler(m_szServiceName, _Handler);
	if (m_hServiceStatus == NULL)
	{
		LogEvent(_T("Handler not installed"));
		return;
	}
	SetServiceStatus(SERVICE_START_PENDING);

	m_status.dwWin32ExitCode = S_OK;
	m_status.dwCheckPoint = 0;
	m_status.dwWaitHint = 0;

	// When the Run function returns, the service has stopped.
	Run();

	SetServiceStatus(SERVICE_STOPPED);
	LogEvent(_T("Service stopped"));
}

inline void CServiceModule::Handler(DWORD dwOpcode)
{
	switch (dwOpcode)
	{
	case SERVICE_CONTROL_STOP:
		SetServiceStatus(SERVICE_STOP_PENDING);
		PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
		break;
	case SERVICE_CONTROL_PAUSE:
		break;
	case SERVICE_CONTROL_CONTINUE:
		break;
	case SERVICE_CONTROL_INTERROGATE:
		break;
	case SERVICE_CONTROL_SHUTDOWN:
		break;
	default:
		LogEvent(_T("Bad service request"));
	}
}

void WINAPI CServiceModule::_ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv)
{
	_Module.ServiceMain(dwArgc, lpszArgv);
}
void WINAPI CServiceModule::_Handler(DWORD dwOpcode)
{
	_Module.Handler(dwOpcode);
}

void CServiceModule::SetServiceStatus(DWORD dwState)
{
	m_status.dwCurrentState = dwState;
	::SetServiceStatus(m_hServiceStatus, &m_status);
}

void CServiceModule::Run()
{
	HRESULT hr;

	_Module.dwThreadID = GetCurrentThreadId();

//  If you are running on NT 4.0 or higher you can use the following call
//  to make your service free threaded.
//  This means that calls come in on a random RPC thread
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

//  Otherwise, for single threaded use
//  hr = CoInitialize(NULL);

	ATLASSERT(SUCCEEDED(hr));

//  In NT 4.0 and higher where DCOM is supported you may wish to initialize
//  the security layer.  The following code will give you a DCOM service which
//  would allow ALL users access to objects
	CSecurityDescriptor sd;
	sd.InitializeFromThreadToken();

	hr = CoInitializeSecurity(NULL, -1, NULL, NULL,
		RPC_C_AUTHN_LEVEL_NONE, RPC_C_IMP_LEVEL_IDENTIFY, NULL, EOAC_NONE, NULL);
	ATLASSERT(SUCCEEDED(hr));

//  If you wish to have your object creatable remotely using DCOM use the following
	hr = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER, REGCLS_MULTIPLEUSE);
//  Otherwise, only local activation
//  hr = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE);
	ATLASSERT(SUCCEEDED(hr));

	LogEvent(_T("Service started"));
	SetServiceStatus(SERVICE_RUNNING);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
		DispatchMessage(&msg);

	_Module.RevokeClassObjects();

	CoUninitialize();
}

/////////////////////////////////////////////////////////////////////////////
//
extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /* hPrevInstance */,
	LPTSTR lpCmdLine, int /* nShowCmd */)
{
	_Module.Init(ObjectMap, hInstance, IDS_SERVICENAME);
	_Module.m_bService = TRUE;

	TCHAR szTokens[] = _T("-/");
	TCHAR *szContext;
	LPTSTR lpszToken = _tcstok_s(lpCmdLine, szTokens, &szContext);
	while (lpszToken != NULL)
	{
		if (_tcsicmp(lpszToken, _T("UnregServer"))==0)
			return _Module.UnregisterServer();

		if (_tcsicmp(lpszToken, _T("RegServer"))==0)
			return _Module.RegisterServer(TRUE);

		if (_tcsicmp(lpszToken, _T("Embedding"))==0)
			_Module.m_bService = FALSE;

		if (_tcsicmp(lpszToken, _T("LocalServer"))==0)
		{
			_Module.SetupAsLocalServer();
			return 0;
		}
		lpszToken = _tcstok_s(NULL, szTokens, &szContext);
	}
	_Module.Start();

	// When we get here, the service has been stopped
	return _Module.m_status.dwWin32ExitCode;
}

void CServiceModule::SetupAsLocalServer()
{
	USES_CONVERSION;
	CRegKey keyClasses,key;
	LPOLESTR pCLSID;

	Uninstall();

	if (keyClasses.Open(HKEY_CLASSES_ROOT, _T("CLSID")) != ERROR_SUCCESS)
		return;

	_ATL_OBJMAP_ENTRY* pEntry = m_pObjMap;
	while (pEntry->pclsid != NULL)
	{
		StringFromCLSID(*pEntry->pclsid, &pCLSID);
		CString csTemp = pCLSID;
		if (key.Open(keyClasses, (LPCTSTR)csTemp) == ERROR_SUCCESS)
		{
			TCHAR szModule[_MAX_PATH];
			key.DeleteValue(_T("AppID"));
			key.DeleteValue(_T("_LocalServer32"));
			GetModuleFileName(GetModuleInstance(), szModule, _MAX_PATH);
			key.SetKeyValue(_T("LocalServer32"), szModule, _T(""));
		}
		pEntry++;
	}
}
