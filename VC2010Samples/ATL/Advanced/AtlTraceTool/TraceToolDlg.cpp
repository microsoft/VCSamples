// TraceToolDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "TraceTool.h"
#include "TraceToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma warning(disable:4127)

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTraceToolDlg dialog



CTraceToolDlg::CTraceToolDlg(CWnd* pParent /*=NULL*/) : 
	CDialog(CTraceToolDlg::IDD, pParent)
{
	InitVariables();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTraceToolDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Check(pDX, ID_PROCESS_CHECKBOX_FILENAMEANDLINENO, m_bFileAndLine);
	DDX_Check(pDX, ID_PROCESS_CHECKBOX_FUNCANDCATNAMES, m_bFuncAndCategory);
	DDX_Check(pDX, ID_PROCESS_CHECKBOX_ENABLED, m_bProcessEnabled);
	DDX_Slider(pDX, ID_CATEGORY_SLIDER_LEVEL, m_nCategoryLevel);
	DDX_Slider(pDX, ID_MODULE_SLIDER_LEVEL, m_nModuleLevel);
	DDX_Slider(pDX, ID_PROCESS_SLIDER_LEVEL, m_nProcessLevel);
	DDX_Control(pDX, ID_TRACE_TREE, m_tree);
	DDX_Radio(pDX, ID_MODULE_RADIO_INHERIT, m_iModuleStatus);
	DDX_Radio(pDX, ID_CATEGORY_RADIO_INHERIT, m_iCategoryStatus);
	DDX_Control(pDX, ID_PROCESS_SLIDER_LEVEL, m_sliderProcessLevel);
	DDX_Control(pDX, ID_MODULE_SLIDER_LEVEL, m_sliderModuleLevel);
	DDX_Control(pDX, ID_CATEGORY_SLIDER_LEVEL, m_sliderCategoryLevel);

	CDialog::DoDataExchange(pDX);
}

static ATLTRACESTATUS IntToStatus( int iStatus ) throw()
{
	switch( iStatus )
	{
	case 0:
		return( ATLTRACESTATUS_INHERIT );
		break;

	case 1:
		return( ATLTRACESTATUS_ENABLED );
		break;

	case 2:
		return( ATLTRACESTATUS_DISABLED );
		break;

	default:
		ASSERT( false );
		__assume( 0 );
		break;
	}
}

static int StatusToInt( ATLTRACESTATUS eStatus ) throw()
{
	switch( eStatus )
	{
	case ATLTRACESTATUS_INHERIT:
		return( 0 );
		break;

	case ATLTRACESTATUS_ENABLED:
		return( 1 );
		break;

	case ATLTRACESTATUS_DISABLED:
		return( 2 );
		break;

	default:
		ASSERT( false );
		__assume( 0 );
		break;
	}
}

BEGIN_MESSAGE_MAP(CTraceToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TVN_SELCHANGED, ID_TRACE_TREE, OnSelchangedTraceTree)
	ON_BN_CLICKED(ID_APPLY, OnClickedApply)
	ON_BN_CLICKED(ID_CLOSE, OnClickedClose)
	ON_BN_CLICKED(ID_CATEGORY_RADIO_DISABLED, OnCategoryChanged)
	ON_BN_CLICKED(ID_CATEGORY_RADIO_ENABLED, OnCategoryChanged)
	ON_BN_CLICKED(ID_CATEGORY_RADIO_INHERIT, OnCategoryChanged)
	ON_BN_CLICKED(ID_MODULE_RADIO_DISABLED, OnModuleChanged)
	ON_BN_CLICKED(ID_MODULE_RADIO_ENABLED, OnModuleChanged)
	ON_BN_CLICKED(ID_MODULE_RADIO_INHERIT, OnModuleChanged)
	ON_BN_CLICKED(ID_PROCESS_CHECKBOX_ENABLED, OnProcessChanged)
	ON_BN_CLICKED(ID_PROCESS_CHECKBOX_FUNCANDCATNAMES, OnProcessChanged)
	ON_BN_CLICKED(ID_PROCESS_CHECKBOX_FILENAMEANDLINENO, OnProcessChanged)
	ON_BN_CLICKED(ID_SAVE, OnBnClickedSave)
	ON_BN_CLICKED(ID_REFRESH, OnBnClickedRefresh)
	ON_BN_CLICKED(ID_LOAD, OnBnClickedLoad)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTraceToolDlg message handlers

BOOL CTraceToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_sliderProcessLevel.SetRange( 0, 4 );
	m_sliderModuleLevel.SetRange( 0, 4 );
	m_sliderCategoryLevel.SetRange( 0, 4 );

	m_hShutdownEvent.Create( NULL, TRUE, FALSE, NULL );

	PopulateTree();

	m_hNotifyThread.Attach( ::CreateThread( NULL, 0, NotifyThread, this, 0, NULL ) );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTraceToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTraceToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTraceToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

static void GetProcessIds( CArray< DWORD >& aid );

DWORD CTraceToolDlg::NotifyThread( void* pContext )
{
	CTraceToolDlg* pThis = static_cast< CTraceToolDlg* >( pContext );

	bool bDone = false;
	while( !bDone )
	{
		HANDLE ahProcesses[32];
		ahProcesses[0] = pThis->m_hShutdownEvent;
		ahProcesses[1] = theApp.m_hSingleInstanceEvent;
		for( UINT iProcess = 0; iProcess < pThis->m_ahProcesses.GetCount(); iProcess++ )
		{
			ahProcesses[iProcess+2] = pThis->m_ahProcesses[iProcess];
		}

		DWORD dwResult = ::WaitForMultipleObjects( ULONG( pThis->m_ahProcesses.GetCount()+2 ), &ahProcesses[0], FALSE, INFINITE );
		if( dwResult == WAIT_OBJECT_0 )
		{
			bDone = true;
		}
		else if( dwResult == (WAIT_OBJECT_0+1) )
		{
			pThis->SetForegroundWindow();
		}
	}

	return( 0 );
}

void CTraceToolDlg::PopulateTree()
{
	CArray< DWORD > aidProcesses;

	GetProcessIds( aidProcesses );

	for( int iProcess = 0; iProcess < aidProcesses.GetSize(); iProcess++ )
	{
		DWORD idProcess = aidProcesses[iProcess];

		DWORD_PTR dwProcess = AtlTraceOpenProcess( idProcess );
		if( dwProcess != 0 )
		{
			AtlTraceSnapshotProcess( dwProcess );

			ATLTRACEPROCESSINFO info;
			AtlTraceGetProcessInfo( dwProcess, &info );
			
			const int MAX_TEXT_SIZE = 256;
			TCHAR szText[MAX_TEXT_SIZE];
			USES_CONVERSION_EX;
							
			CW2T pszName(info.szName);
			LPTSTR lpszName = pszName;
			_sntprintf_s(szText, MAX_TEXT_SIZE, _TRUNCATE, _T( "%s:0x%08x" ), lpszName, idProcess );
			szText[MAX_TEXT_SIZE - 1] = 0;
			

			HTREEITEM hProcessItem = m_tree.InsertItem( szText );

			PROCESSSETTINGS *pPS = NULL;
			pPS = new PROCESSSETTINGS;			
			pPS->bModified = FALSE;
			pPS->dwProcess = dwProcess;
			pPS->ps.nLevel = info.settings.nLevel;
			pPS->ps.bEnabled = info.settings.bEnabled;
			pPS->ps.bFuncAndCategoryNames = info.settings.bFuncAndCategoryNames;
			pPS->ps.bFileNameAndLineNo = info.settings.bFileNameAndLineNo;
			m_tree.SetItemData( hProcessItem, reinterpret_cast<DWORD_PTR>(pPS) );

			for( int iModule = 0; iModule < info.nModules; iModule++ )
			{
				ATLTRACEMODULEINFO module;
				AtlTraceGetModuleInfo( dwProcess, iModule, &module );

				CW2T pszModuleName(module.szName);
				LPTSTR lpszModuleName = pszModuleName; 
#ifndef _UNICODE
				if(lpszModuleName == NULL)
					lpszModuleName = _T("");
#endif
				HTREEITEM hModuleItem = m_tree.InsertItem( lpszModuleName, hProcessItem );
				DWORD_PTR dwModule = module.dwModule;

				TRACESETTINGS *pTS = NULL;
				pTS = new TRACESETTINGS;
				ENSURE(pTS); /* prefast noise */
				pTS->bModified = FALSE;
				pTS->dwHandle = dwModule;
				pTS->ts.nLevel = module.settings.nLevel;
				pTS->ts.eStatus = module.settings.eStatus;
				m_tree.SetItemData( hModuleItem, reinterpret_cast<DWORD_PTR>(pTS) );

				for( int iCategory = 0; iCategory < module.nCategories; iCategory++ )
				{
					ATLTRACECATEGORYINFO category;
					AtlTraceGetCategoryInfo( dwProcess, dwModule, iCategory, &category );
					DWORD_PTR dwCategory = category.dwCategory;
					
					CW2T pszCategoryName(category.szName);
					LPTSTR lpszCategoryName = pszCategoryName;
#ifndef _UNICODE
					if(lpszCategoryName == NULL)
						lpszCategoryName = _T("");
#endif
					HTREEITEM hCategoryItem = m_tree.InsertItem( lpszCategoryName, hModuleItem );

					TRACESETTINGS *pTS2 = NULL;
					pTS2 = new TRACESETTINGS;
					ENSURE(pTS2); /* prefast noise */
					pTS2->bModified = FALSE;
					pTS2->dwHandle = dwCategory;
					pTS2->ts.nLevel = category.settings.nLevel;
					pTS2->ts.eStatus = category.settings.eStatus;
					m_tree.SetItemData( hCategoryItem, reinterpret_cast<DWORD_PTR>(pTS2) );
				}
			}
		}
	}
}

void CTraceToolDlg::UpdateControls()
{
	GetDlgItem( ID_APPLY )->EnableWindow( m_bDirty );
	GetDlgItem( ID_MODULE_RADIO_INHERIT )->EnableWindow( m_pTSModule != NULL );
	GetDlgItem( ID_MODULE_RADIO_ENABLED )->EnableWindow( m_pTSModule != NULL );
	GetDlgItem( ID_MODULE_RADIO_DISABLED )->EnableWindow( m_pTSModule != NULL );
	GetDlgItem( ID_MODULE_GROUPBOX )->EnableWindow( m_pTSModule != NULL );
	GetDlgItem( ID_MODULE_SLIDER_LEVEL )->EnableWindow( (m_pTSModule != NULL) && (m_iModuleStatus == 1)  );
	GetDlgItem( ID_MODULE_STATIC1 )->EnableWindow( (m_pTSModule != NULL) && (m_iModuleStatus == 1)  );
	GetDlgItem( ID_MODULE_STATIC2 )->EnableWindow( (m_pTSModule != NULL) && (m_iModuleStatus == 1)  );
	GetDlgItem( ID_MODULE_STATIC3 )->EnableWindow( (m_pTSModule != NULL) && (m_iModuleStatus == 1)  );
	GetDlgItem( ID_CATEGORY_RADIO_INHERIT )->EnableWindow( m_pTSCategory != NULL );
	GetDlgItem( ID_CATEGORY_RADIO_ENABLED )->EnableWindow( m_pTSCategory != NULL );
	GetDlgItem( ID_CATEGORY_RADIO_DISABLED )->EnableWindow( m_pTSCategory != NULL );
	GetDlgItem( ID_CATEGORY_GROUPBOX )->EnableWindow( m_pTSCategory != NULL );
	GetDlgItem( ID_CATEGORY_SLIDER_LEVEL )->EnableWindow( (m_pTSCategory != NULL) && (m_iCategoryStatus == 1) );
	GetDlgItem( ID_CATEGORY_STATIC1 )->EnableWindow( (m_pTSCategory != NULL) && (m_iCategoryStatus == 1) );
	GetDlgItem( ID_CATEGORY_STATIC2 )->EnableWindow( (m_pTSCategory != NULL) && (m_iCategoryStatus == 1) );
	GetDlgItem( ID_CATEGORY_STATIC3 )->EnableWindow( (m_pTSCategory != NULL) && (m_iCategoryStatus == 1) );
}

void CTraceToolDlg::OnSelchangedTraceTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_bDeleting)
		return;

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;

	UpdateSelectedItem(pNMTreeView->itemNew.hItem);
}

void CTraceToolDlg::OnClickedApply(void)
{
	for( HTREEITEM hProcess = m_tree.GetChildItem( TVI_ROOT ); hProcess != NULL; hProcess = m_tree.GetNextSiblingItem( hProcess ) )
	{
		PROCESSSETTINGS *pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData( hProcess ));	
		if (pPS->bModified == FALSE)
			continue;

		AtlTraceModifyProcess( pPS->dwProcess, pPS->ps.nLevel, pPS->ps.bEnabled, pPS->ps.bFuncAndCategoryNames, pPS->ps.bFileNameAndLineNo );
		pPS->bModified = FALSE;

		for (HTREEITEM hModule = m_tree.GetChildItem( hProcess ); hModule != NULL; hModule = m_tree.GetNextSiblingItem( hModule ) )
		{
			TRACESETTINGS *pTSModule = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hModule ));
			if (pTSModule->bModified == FALSE)
				continue;

			AtlTraceModifyModule( pPS->dwProcess, pTSModule->dwHandle, pTSModule->ts.nLevel, pTSModule->ts.eStatus );
			pTSModule->bModified = FALSE;

			for (HTREEITEM hCategory = m_tree.GetChildItem( hModule ); hCategory != NULL; hCategory = m_tree.GetNextSiblingItem( hCategory ) )
			{
				TRACESETTINGS *pTSCategory = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hCategory ));
				if (pTSCategory->bModified == TRUE)
				{
					AtlTraceModifyCategory( pPS->dwProcess, pTSCategory->dwHandle, pTSCategory->ts.nLevel, pTSCategory->ts.eStatus );
					pTSCategory->bModified = FALSE;
				}
			}
		}
	}
	m_bDirty = FALSE;
	UpdateControls();
}

void CTraceToolDlg::OnClickedClose(void)
{
	OnCancel();
}

void CTraceToolDlg::OnDestroy()
{
	Cleanup();

	if( m_hNotifyThread != NULL )
	{
		m_hShutdownEvent.Set();
		::WaitForSingleObject( m_hNotifyThread, INFINITE );
		m_hShutdownEvent.Close();
		m_hNotifyThread.Close();
	}

	CDialog::OnDestroy();
}

static void GetProcessIds( CArray< DWORD >& aid )
{
	OSVERSIONINFO ver;
	HINSTANCE hInst;
	ver.dwOSVersionInfoSize = sizeof(ver);
	GetVersionEx(&ver);

	if( ver.dwPlatformId == VER_PLATFORM_WIN32_NT )
	{
		// NT and Windows 2000 (although ToolHelp32 will work for W2K)
		TCHAR  infoBuf[MAX_PATH+1];
		UINT nChars=GetSystemDirectory(infoBuf, _countof(infoBuf));
		ATLENSURE(nChars<_countof(infoBuf));
		infoBuf[_countof(infoBuf)-1]=_T('\0');
		_tcscat_s(infoBuf, sizeof(infoBuf) / sizeof(TCHAR), _T("\\PSAPI.DLL"));
		hInst = LoadLibrary(infoBuf);
		if( hInst != NULL )
		{
			BOOL (WINAPI* pfnEnumProcesses)(DWORD*, DWORD, DWORD*) =
				(BOOL (WINAPI*)(DWORD*, DWORD, DWORD*))GetProcAddress( hInst, "EnumProcesses" );
			if( pfnEnumProcesses != NULL )
			{
				aid.SetSize( 256 );
				ULONG nBytes = 256*sizeof( DWORD );
				ULONG nActualBytes = 0;

				bool bDone = false;
				while( !bDone )
				{
					pfnEnumProcesses( aid.GetData(), nBytes, &nActualBytes );
					if( nActualBytes < nBytes )
					{
						// Got all of them
						aid.SetSize( nActualBytes/sizeof( DWORD ) );
						bDone = true;
					}
					else
					{
						nBytes *= 2;
						aid.SetSize( aid.GetSize()*2 );
						nActualBytes = 0;
					}
				}
			}
			FreeLibrary( hInst );
		}
	}
	else
	{
		// Win95/98
		hInst = GetModuleHandle( _T( "Kernel32.dll" ) );
		ASSERT( hInst != NULL );
		if( hInst != NULL )
		{
			HANDLE (WINAPI *pfnCreateSnapshot)(DWORD, DWORD) =
				(HANDLE (WINAPI *)(DWORD, DWORD)) 
				GetProcAddress( hInst, "CreateToolhelp32Snapshot" );

			BOOL (WINAPI *pfnProcessFirst)(HANDLE, LPPROCESSENTRY32) =
				(BOOL (WINAPI *)(HANDLE, LPPROCESSENTRY32))
				GetProcAddress( hInst, "Process32First" );

			BOOL (WINAPI *pfnProcessNext)(HANDLE, LPPROCESSENTRY32) =
				(BOOL (WINAPI *)(HANDLE, LPPROCESSENTRY32))
				GetProcAddress( hInst, "Process32Next" );

			if( (pfnCreateSnapshot != NULL) &&
				(pfnProcessFirst != NULL) &&
				(pfnProcessNext != NULL) )
			{
				PROCESSENTRY32 pe;
				HANDLE hSnapShot = pfnCreateSnapshot( TH32CS_SNAPPROCESS, 0 );

				if( hSnapShot != INVALID_HANDLE_VALUE)
				{
					if( pfnProcessFirst( hSnapShot, &pe ) )
					{
						do
						{
							aid.Add( pe.th32ProcessID );
						}
						while( pfnProcessNext( hSnapShot, &pe ) );
					}
					CloseHandle( hSnapShot );
				}
			}
		}
	}
}

void CTraceToolDlg::OnBnClickedSave()
{
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem)
	{
		OnClickedApply();
				
		HTREEITEM hItemCheck = m_tree.GetParentItem(hItem);
		while(hItemCheck)
		{
			hItem = hItemCheck;
			hItemCheck = m_tree.GetParentItem(hItem);
		}

		if (!hItem)
			return;

		PROCESSSETTINGS *pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData(hItem));
		ATLTRACEPROCESSINFO	pi;
		if (!AtlTraceGetProcessInfo(pPS->dwProcess, &pi))
			return;

		CString strFileName = pi.szName;
		int nDot = strFileName.ReverseFind('.');
		if (nDot != -1)
		{
			strFileName = strFileName.Left(nDot + 1);
			strFileName += _T("trc");
		}
		else
			strFileName += _T(".trc");

		CFileDialog dlg(FALSE, _T("trc"), strFileName, OFN_HIDEREADONLY | 
			OFN_NOREADONLYRETURN | OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT, 
			_T("ATL Trace Files (*.trc)|*.trc||"), this);

		CString strPath = pi.szPath;
		int nSlash = strPath.ReverseFind('\\');
		if (nSlash != -1)
			strPath = strPath.Left(nSlash);

		dlg.m_ofn.lpstrInitialDir = strPath;

		if (IDOK == dlg.DoModal())
		{
			BOOL bOK=AtlTraceSaveSettings(dlg.GetPathName(), pPS->dwProcess);
			if (bOK==FALSE)
			{
				AfxMessageBox(IDS_INVALIDFILENAME);
			}
		}
	}
}

void CTraceToolDlg::OnBnClickedLoad()
{
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem)
	{
		OnClickedApply();
				
		HTREEITEM hItemCheck = m_tree.GetParentItem(hItem);
		while(hItemCheck)
		{
			hItem = hItemCheck;
			hItemCheck = m_tree.GetParentItem(hItem);
		}

		if (!hItem)
			return;

		PROCESSSETTINGS *pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData(hItem));
		ATLTRACEPROCESSINFO	pi;
		if (!AtlTraceGetProcessInfo(pPS->dwProcess, &pi))
			return;

		CFileDialog dlg(TRUE, _T("trc"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST, 
			_T("ATL Trace Files (*.trc)|*.trc||"), this);

		CString strPath = pi.szPath;
		int nSlash = strPath.ReverseFind('\\');
		if (nSlash != -1)
			strPath = strPath.Left(nSlash);

		dlg.m_ofn.lpstrInitialDir = strPath;

		if (IDOK == dlg.DoModal())
		{
			AtlTraceLoadSettings(dlg.GetPathName(), pPS->dwProcess);
			RefreshProcess(pPS->dwProcess);
		}
	}
}

void CTraceToolDlg::OnBnClickedRefresh()
{
	Cleanup();
	m_bDeleting = TRUE;
	m_tree.DeleteAllItems();
	m_bDeleting = FALSE;
	InitVariables();
	UpdateData(FALSE);
	PopulateTree();
}

void CTraceToolDlg::Cleanup()
{
	for( HTREEITEM hProcess = m_tree.GetChildItem( TVI_ROOT ); hProcess != NULL; hProcess = m_tree.GetNextSiblingItem( hProcess ) )
	{
		for (HTREEITEM hModule = m_tree.GetChildItem( hProcess ); hModule != NULL; hModule = m_tree.GetNextSiblingItem( hModule ) )
		{
			for (HTREEITEM hCategory = m_tree.GetChildItem( hModule ); hCategory != NULL; hCategory = m_tree.GetNextSiblingItem( hCategory ) )
			{
				TRACESETTINGS *pTSCategory = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hCategory ));
				delete pTSCategory;
			}

			TRACESETTINGS *pTSModule = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hModule ));
			delete pTSModule;
		}

		PROCESSSETTINGS *pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData( hProcess ));
		AtlTraceCloseProcess( pPS->dwProcess );
		delete pPS;
	}
}

void CTraceToolDlg::InitVariables()
{
	m_nProcessLevel = 0;
	m_nModuleLevel = 0;
	m_nCategoryLevel = 0;
	m_pPS = NULL;	
	m_pTSModule = NULL;	
	m_pTSCategory = NULL;	
	m_bFuncAndCategory = FALSE;
	m_bFileAndLine = FALSE;
	m_bProcessEnabled = TRUE;
	m_iModuleStatus = 0;
	m_iCategoryStatus = 0;
	m_bDeleting = FALSE;
	m_bDirty = FALSE;
}

void CTraceToolDlg::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl *pSlider = reinterpret_cast<CSliderCtrl*>(pScrollBar);
	ENSURE(pSlider);

	int nID = pSlider->GetDlgCtrlID();
	switch (nID)
	{
		case ID_PROCESS_SLIDER_LEVEL:
			OnProcessChanged();
			break;
		case ID_MODULE_SLIDER_LEVEL:
			OnModuleChanged();
			break;
		case ID_CATEGORY_SLIDER_LEVEL:
			OnCategoryChanged();
			break;
	}

	return CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTraceToolDlg::OnProcessChanged()
{
	if (!m_pPS)
		return;

	UpdateData(TRUE);

	m_pPS->bModified = TRUE;
	m_pPS->ps.bEnabled = m_bProcessEnabled;
	m_pPS->ps.bFileNameAndLineNo = m_bFileAndLine;
	m_pPS->ps.bFuncAndCategoryNames = m_bFuncAndCategory;
	m_pPS->ps.nLevel = m_nProcessLevel;

	m_bDirty = TRUE;
	UpdateControls();
}

void CTraceToolDlg::OnModuleChanged()
{
	if (!m_pTSModule)
		return;

	UpdateData(TRUE);

	m_pTSModule->bModified = TRUE;
	m_pTSModule->ts.eStatus = IntToStatus(m_iModuleStatus);
	m_pTSModule->ts.nLevel = m_nModuleLevel;

	if (m_pPS)
		m_pPS->bModified = TRUE;

	m_bDirty = TRUE;
	UpdateControls();
}

void CTraceToolDlg::OnCategoryChanged()
{
	if (!m_pTSCategory)
		return;

	UpdateData(TRUE);

	m_pTSCategory->bModified = TRUE;
	m_pTSCategory->ts.eStatus = IntToStatus(m_iCategoryStatus);
	m_pTSCategory->ts.nLevel = m_nCategoryLevel;

	if (m_pTSModule)
		m_pTSModule->bModified = TRUE;

	if (m_pPS)
		m_pPS->bModified = TRUE;

	m_bDirty = TRUE;
	UpdateControls();
}

BOOL CTraceToolDlg::OnWndMsg( UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult )
{
	if (WM_CLOSE == message)
	{
		if (m_bDirty)
		{
			if (IDNO == AfxMessageBox(IDS_CLOSEWITHOUTAPPLY, MB_YESNO))
				return TRUE;
		}
	}
	return CDialog::OnWndMsg( message, wParam, lParam, pResult );
}

void CTraceToolDlg::OnCancel()
{
	if (m_bDirty)
	{
		if (IDNO == AfxMessageBox(IDS_CLOSEWITHOUTAPPLY, MB_YESNO))
			return;
	}
	CDialog::OnCancel();
}

void CTraceToolDlg::RefreshProcess(DWORD_PTR dwProcess)
{
	HTREEITEM hProcess = m_tree.GetSelectedItem();
	if (hProcess)
	{
		HTREEITEM hItemCheck = m_tree.GetParentItem(hProcess);
		while(hItemCheck)
		{
			hProcess = hItemCheck;
			hItemCheck = m_tree.GetParentItem(hProcess);
		}
		if (!hProcess)
			return;

		PROCESSSETTINGS *pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData(hProcess));
		pPS->bModified = FALSE;
		AtlTraceGetProcess(dwProcess, &pPS->ps.nLevel, &pPS->ps.bEnabled, &pPS->ps.bFuncAndCategoryNames, &pPS->ps.bFileNameAndLineNo);

		for (HTREEITEM hModule = m_tree.GetChildItem( hProcess ); hModule != NULL; hModule = m_tree.GetNextSiblingItem( hModule ) )
		{
			TRACESETTINGS *pTSModule = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hModule ));
			pTSModule->bModified = FALSE;
			AtlTraceGetModule( dwProcess, pTSModule->dwHandle, &pTSModule->ts.nLevel, &pTSModule->ts.eStatus );

			for (HTREEITEM hCategory = m_tree.GetChildItem( hModule ); hCategory != NULL; hCategory = m_tree.GetNextSiblingItem( hCategory ) )
			{
				TRACESETTINGS *pTSCategory = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hCategory ));
				pTSCategory->bModified = FALSE;
				AtlTraceGetCategory( dwProcess, pTSCategory->dwHandle, &pTSCategory->ts.nLevel, &pTSCategory->ts.eStatus );
			}
		}
		UpdateSelectedItem(m_tree.GetSelectedItem());
	}
}

void CTraceToolDlg::UpdateSelectedItem(HTREEITEM hSelection)
{
	HTREEITEM hParent = NULL;
	HTREEITEM hGrandparent = NULL;
	if( hSelection != NULL )
	{
		hParent = m_tree.GetParentItem( hSelection );
	}
	if( hParent != NULL )
	{
		hGrandparent = m_tree.GetParentItem( hParent );
	}

	HTREEITEM hProcessItem = NULL;
	HTREEITEM hModuleItem = NULL;
	HTREEITEM hCategoryItem = NULL;
	if( hGrandparent != NULL )
	{
		// hSelection is a category
		hCategoryItem = hSelection;
		hModuleItem = hParent;
		hProcessItem = hGrandparent;
	}
	else if( hParent != NULL )
	{
		// hSelection is a module
		hModuleItem = hSelection;
		hProcessItem = hParent;
	}
	else if( hSelection != NULL )
	{
		// hSelection is a process
		hProcessItem = hSelection;
	}

	m_pPS = 0;
	m_pTSModule = 0;
	m_pTSCategory = 0;
	if( hProcessItem != NULL )
	{
		m_pPS = reinterpret_cast<PROCESSSETTINGS*>(m_tree.GetItemData( hProcessItem ));
		m_nProcessLevel = m_pPS->ps.nLevel;
		m_bProcessEnabled = m_pPS->ps.bEnabled;
		m_bFuncAndCategory = m_pPS->ps.bFuncAndCategoryNames;
		m_bFileAndLine = m_pPS->ps.bFileNameAndLineNo;
	}
	else
	{
		m_nProcessLevel = 0;
		m_bProcessEnabled = FALSE;
		m_bFuncAndCategory = FALSE;
		m_bFileAndLine = FALSE;
	}
	if( hModuleItem != NULL )
	{
		m_pTSModule = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hModuleItem ));
		m_nModuleLevel = m_pTSModule->ts.nLevel;
		ATLTRACESTATUS eModuleStatus = m_pTSModule->ts.eStatus;
		m_iModuleStatus = StatusToInt( eModuleStatus );
	}
	else
	{
		m_nModuleLevel = 0;
		m_iModuleStatus = -1;
	}
	if( hCategoryItem != NULL )
	{
		m_pTSCategory = reinterpret_cast<TRACESETTINGS*>(m_tree.GetItemData( hCategoryItem ));
		m_nCategoryLevel = m_pTSCategory->ts.nLevel;
		ATLTRACESTATUS eCategoryStatus = m_pTSCategory->ts.eStatus;
		m_iCategoryStatus = StatusToInt( eCategoryStatus );
	}
	else
	{
		m_nCategoryLevel = 0;
		m_iCategoryStatus = -1;
	}

	UpdateData( false );

	UpdateControls();
}
