// iviewers.cpp : Defines the class behaviors for the application.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and Microsoft
// QuickHelp and/or WinHelp documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "iviewers.h"

#include "typelib.h"
#include "iview.h"
#include "util.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIViewersApp:
// See iviewers.cpp for the implementation of this class
//

class CIViewersApp : public CWinApp
{
public:
	CIViewersApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIViewersApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CIViewersApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// CIViewersApp

BEGIN_MESSAGE_MAP(CIViewersApp, CWinApp)
	//{{AFX_MSG_MAP(CIViewersApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIViewersApp construction

CIViewersApp::CIViewersApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIViewersApp object

CIViewersApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CIViewersApp initialization

BOOL CIViewersApp::InitInstance()
{
	SetRegistryKey( IDS_REGISTRYKEY );
#if (!defined(_USRDLL) && !defined(_AFXDLL))
//  COleObjectFactory::UpdateRegistryAll();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	m_pMainWnd = (CFrameWnd*)new CTypeLibWnd ;
	ASSERT(m_pMainWnd) ;

	if (m_lpCmdLine && *m_lpCmdLine)
	{
		HRESULT hr = LoadTypeLib( m_lpCmdLine, &((CTypeLibWnd*)m_pMainWnd)->m_ptlb ) ;
		if (FAILED(hr))
		{
			CString str ;
			str.Format( _T("LoadTypeLib(%s) failed"), m_lpCmdLine ) ;
			ErrorMessage( str, hr ) ;
			return FALSE ;
		}
	}
	else
	{
		static TCHAR szFilter[] = _T("TypeLib Files (*.tlb;*.olb;*.dll;*.ocx;*.exe)|*.tlb;*.olb;*.dll;*.ocx;*.exe|AllFiles(*.*)|*.*|") ;

		CFileDialog dlg( TRUE, _T("*.tlb"), NULL,
						OFN_FILEMUSTEXIST | OFN_HIDEREADONLY |
						OFN_PATHMUSTEXIST
						, szFilter, NULL )  ;

		if (IDOK != dlg.DoModal())
			return FALSE ;

		HRESULT hr = LoadTypeLib( dlg.GetPathName(), &((CTypeLibWnd*)m_pMainWnd)->m_ptlb ) ;
		if (FAILED(hr))
		{
			CString str ;
			str.Format( _T("LoadTypeLib(%s) failed"), dlg.GetPathName() ) ;
			ErrorMessage( str, hr ) ;
			return FALSE ;
		}

	}

	if (((CTypeLibWnd*)m_pMainWnd)->LoadFrame(IDR_TYPELIBWND, WS_OVERLAPPEDWINDOW, NULL, NULL) == FALSE)
	{
		TRACE(_T("LoadFrame failed\n") );
		if (((CTypeLibWnd*)m_pMainWnd)->m_ptlb)
			((CTypeLibWnd*)m_pMainWnd)->m_ptlb->Release() ;
		return FALSE ;
	}
	ASSERT(m_pMainWnd) ;

	((CTypeLibWnd*)m_pMainWnd)->RestorePosition() ;
	((CTypeLibWnd*)m_pMainWnd)->UpdateWindow() ;

#endif

	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	return TRUE;
}

int CIViewersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// Special entry points required for iviewers servers

#if (defined(_USRDLL) || defined(_AFXDLL))
extern "C"{
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	return AfxDllCanUnloadNow();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	HRESULT hr ;
	COleObjectFactory::UpdateRegistryAll();
	hr = DllRegisterInterfaceViewer( CLSID_ITypeLibViewer, IID_ITypeLib );
	if (FAILED(hr))
		return hr ;
	hr = DllRegisterInterfaceViewer( CLSID_IDispatchViewer, IID_IDispatch );
	if (FAILED(hr))
		return hr ;
	return DllRegisterInterfaceViewer( CLSID_IDataObjectViewer, IID_IDataObject );
}
#endif //_USRDLL

STDAPI DllRegisterInterfaceViewer( REFCLSID rclsid, REFIID riid )
{
	HRESULT hr = S_OK ;
	HKEY hk = NULL ;

	LPOLESTR lpszOleIID = NULL;
	LPOLESTR lpszOleCLSID = NULL;
	IMalloc* pmal = NULL ;

	if (FAILED(hr = ::CoGetMalloc(MEMCTX_TASK, &pmal)))
		return hr;
	ASSERT(pmal != NULL);

	TRY
	{
		LONG cb ;
		TCHAR szKey[1024];
		TCHAR szValue[1024];

		// \Interface\{iid} exists?
		if (FAILED(hr = StringFromCLSID(riid, &lpszOleIID)))
			AfxThrowMemoryException() ;

		COLE2T lpszIID(lpszOleIID);
		_stprintf_s( szKey, 1024, _T("Interface\\%s"), lpszIID );
		cb = sizeof(szValue);
		if ((hr = ::RegQueryValue(HKEY_CLASSES_ROOT, szKey, szValue, &cb)) != ERROR_SUCCESS)
			AfxThrowMemoryException() ;

		// Create \Interface\{iid}\Ole2ViewIViewerCLSID
		_stprintf_s( szKey, 1024, _T("Interface\\%s\\Ole2ViewIViewerCLSID"), lpszIID);
		if ((hr = ::RegCreateKey(HKEY_CLASSES_ROOT, szKey, &hk)) != ERROR_SUCCESS)
			AfxThrowMemoryException() ;

		// Set = {clsid}
		if (FAILED(hr = ::StringFromCLSID(rclsid, &lpszOleCLSID)))
			AfxThrowMemoryException() ;

		COLE2T lpszCLSID(lpszOleCLSID);
		ENSURE (lpszCLSID);
		cb = lstrlen(lpszCLSID);
		if ((hr = ::RegSetValue(hk, NULL, REG_SZ, lpszCLSID, cb)) != ERROR_SUCCESS)
			AfxThrowMemoryException() ;
	}
	CATCH(CException, pException)
	{
	}
	END_CATCH

	if (hk)
		RegCloseKey( hk ) ;

	if (lpszOleIID && pmal)
		pmal->Free(lpszOleIID) ;

	if (lpszOleCLSID && pmal)
		pmal->Free(lpszOleCLSID) ;

	if (pmal)
		pmal->Release() ;

	return hr ;
}

}; // extern "C"

/////////////////////////////////////////////////////////////////////////////
// CIViewersApp commands
