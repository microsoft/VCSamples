// LoggingDlg.Cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "StdAfx.H"
#include "TestCon.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoggingDlg dialog


CLoggingDlg::CLoggingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoggingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoggingDlg)
	m_strFileName = _T("");
	m_iLogType = -1;
	//}}AFX_DATA_INIT
}


void CLoggingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoggingDlg)
	DDX_Control(pDX, IDC_FILENAME_BROWSE, m_butFileNameBrowse);
	DDX_Control(pDX, IDC_FILENAME, m_eboxFileName);
	DDX_Text(pDX, IDC_FILENAME, m_strFileName);
	DDX_Radio(pDX, IDC_LOGTONULL, m_iLogType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoggingDlg, CDialog)
	//{{AFX_MSG_MAP(CLoggingDlg)
	ON_BN_CLICKED(IDC_LOGTODEBUG, OnLogToDebug)
	ON_BN_CLICKED(IDC_LOGTOFILE, OnLogToFile)
	ON_BN_CLICKED(IDC_FILENAME_BROWSE, OnFileNameBrowse)
	ON_BN_CLICKED(IDC_LOGTONULL, OnLogToNull)
	ON_BN_CLICKED(IDC_LOGTOOUTPUT, OnLogToOutput)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoggingDlg message handlers

BOOL CLoggingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

   m_eboxFileName.EnableWindow( m_iLogType == 3 );
   m_butFileNameBrowse.EnableWindow( m_iLogType == 3 );

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoggingDlg::OnLogToDebug()
{
   m_eboxFileName.EnableWindow( FALSE );
   m_butFileNameBrowse.EnableWindow( FALSE );
}

void CLoggingDlg::OnLogToFile()
{
   m_eboxFileName.EnableWindow( TRUE );
   m_butFileNameBrowse.EnableWindow( TRUE );
}

void CLoggingDlg::OnFileNameBrowse()
{
   int nResult;

   CFileDialog dlg( FALSE, _T( "Log" ) );

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   m_strFileName = dlg.GetPathName();
   m_eboxFileName.SetWindowText( m_strFileName );
}

void CLoggingDlg::OnLogToNull()
{
   m_eboxFileName.EnableWindow( FALSE );
   m_butFileNameBrowse.EnableWindow( FALSE );
}

void CLoggingDlg::OnLogToOutput()
{
   m_eboxFileName.EnableWindow( FALSE );
   m_butFileNameBrowse.EnableWindow( FALSE );
}


static DWORD rgmapCHID[] =
{
   IDC_FILENAME_BROWSE, HIDC_FILENAME_BROWSE,
   IDC_FILENAME, HIDC_FILENAME,
   IDC_LOGTOFILE, HIDC_LOGTOFILE,
   IDC_LOGTODEBUG, HIDC_LOGTODEBUG,
   IDC_LOGTOOUTPUT, HIDC_LOGTOOUTPUT,
   IDC_LOGTONULL, HIDC_LOGTONULL,
   0, 0
};

BOOL CLoggingDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CLoggingDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
