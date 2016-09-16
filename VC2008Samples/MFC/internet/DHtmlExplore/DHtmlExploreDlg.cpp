// DHtmlExploreDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "DHtmlExplore.h"
#include "DHtmlExploreDlg.h"
#include "PropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDHtmlExploreDlg dialog

CDHtmlExploreDlg::CDHtmlExploreDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CDHtmlExploreDlg::IDD, 0, pParent)
{
	//{{AFX_DATA_INIT(CDHtmlExploreDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDHtmlExploreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDHtmlExploreDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_DHtml_ElementInnerText(pDX, _T("currDir"), m_strCurrDir);
}

BEGIN_MESSAGE_MAP(CDHtmlExploreDlg, CDHtmlDialog)
	//{{AFX_MSG_MAP(CDHtmlExploreDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_CONTEXT_BROWSE, OnContextBrowse)
	ON_COMMAND(ID_CONTEXT_EXIT, OnContextExit)
	ON_COMMAND(ID_CONTEXT_PROPERTIES, OnContextProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BEGIN_DHTML_EVENT_MAP(CDHtmlExploreDlg)
	DHTML_EVENT_ONCLICK(_T("browse"), OnBrowse)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("hotElement"),  OnMouseOverElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("hotElement"),  OnMouseOutElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("folder"),  OnMouseOverElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("folder"),  OnMouseOutElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOVER, _T("file"),  OnMouseOverElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONMOUSEOUT, _T("file"),  OnMouseOutElement)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("folder"),  OnClickFolder)
	DHTML_EVENT_CLASS(DISPID_HTMLELEMENTEVENTS_ONCLICK, _T("file"),  OnClickFile)
END_DHTML_EVENT_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDHtmlExploreDlg message handlers

BOOL CDHtmlExploreDlg::OnInitDialog()
{
	SetHostFlags(DOCHOSTUIFLAG_FLAT_SCROLLBAR);

	CDHtmlDialog::OnInitDialog();

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
	
	// TODO: Add extra initialization here
	LoadFromResource(IDR_EXPLORE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDHtmlExploreDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDHtmlExploreDlg::OnPaint() 
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
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDHtmlExploreDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDHtmlExploreDlg::OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl)
{
	CDHtmlDialog::OnDocumentComplete(pDisp, szUrl);
	RefreshDir();
}

void CDHtmlExploreDlg::RefreshDir()
{
	CTempBuffer<TCHAR, MAX_PATH> strBuffer(MAX_PATH);
	strBuffer[0] = _T('\0');
	DWORD length = GetCurrentDirectory(MAX_PATH, strBuffer);

	if (length > MAX_PATH)
	{
		// We need to reallocate the string => MAX_PATH wasn't space enough.
		strBuffer.Reallocate(length);
		strBuffer[0] = _T('\0');
		GetCurrentDirectory(length, strBuffer);
	}

	m_strCurrDir = strBuffer;
	UpdateData(FALSE);

	CString strTable;
	strTable = _T("<TABLE border=1 cols=4 width=100%>\n")
		_T("<THEAD><TR><TD width=20>&nbsp;</TD><TD>File Name</TD><TD>Size</TD><TD>Modified</TD></TR></THEAD>");


	// recreate the filelist table
	CComPtr<IHTMLElement> spfileList;
	GetElementInterface(_T("fileList"), IID_IHTMLElement, (void **) &spfileList);
	
	if (spfileList == NULL)
		return;

	CString strFilter = m_strCurrDir + _T("\\*.*");
	WIN32_FIND_DATA finddata;
	HANDLE hFind = FindFirstFile(strFilter, &finddata);
	if (hFind==INVALID_HANDLE_VALUE)
		return;
	CWaitCursor cur;
	CString str, strDate;

	do
	{

		CTime t(finddata.ftLastWriteTime);
		strDate = t.Format(_T("%A, %B %d, %Y"));
		
		str.Format(_T("<TR><TD width=20><IMG src=%s.gif></TD><TD><SPAN class=%s>%s</SPAN></TD><TD>%lu</TD><TD>%s</TD></TR>"),
			((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? _T("folder") : _T("file")),
			((finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? _T("folder") : _T("file")),
			finddata.cFileName, finddata.nFileSizeLow, (LPCTSTR) strDate);
		strTable += str;
	} while (FindNextFile(hFind, &finddata));
	strTable += _T("</TABLE>");
	FindClose(hFind);
	CComBSTR bstrTable = strTable;
	spfileList->put_innerHTML(bstrTable);
}

HRESULT CDHtmlExploreDlg::OnBrowse(IHTMLElement* /*phtmlElement*/)
{
	BROWSEINFO bi;
	TCHAR szDisplayName[MAX_PATH];
	memset(&bi, 0x00, sizeof(bi));
	bi.hwndOwner = m_hWnd;
	bi.pszDisplayName = szDisplayName;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	if (pidl)
	{
		SHGetPathFromIDList(pidl, szDisplayName);
		SetCurrentDirectory(szDisplayName);
		RefreshDir();

		// free the pidl
		CComPtr<IMalloc> spSHMalloc;
		if(FAILED(SHGetMalloc(&spSHMalloc)))
		{
			return S_FALSE;
		}
		if (spSHMalloc != NULL)
			spSHMalloc->Free(pidl);
	}

	return S_OK;
}

HRESULT CDHtmlExploreDlg::OnMouseOverElement(IHTMLElement *phtmlElement)
{
	IHTMLStyle *phtmlStyle;
	phtmlElement->get_style(&phtmlStyle);
	if (phtmlStyle)
	{
		VARIANT varColor;
		varColor.vt = VT_I4;
		varColor.lVal = 0xff0000;
		phtmlStyle->put_textDecorationUnderline(VARIANT_TRUE);
		phtmlStyle->put_color(varColor);
		phtmlStyle->put_cursor(L"hand");
		phtmlStyle->Release();
	}
	m_spCurrElement = phtmlElement;
	return S_OK;
}

HRESULT CDHtmlExploreDlg::OnMouseOutElement(IHTMLElement *phtmlElement)
{
	IHTMLStyle *phtmlStyle;
	phtmlElement->get_style(&phtmlStyle);
	if (phtmlStyle)
	{
		VARIANT varColor;
		varColor.vt = VT_I4;
		varColor.lVal = 0x000000;
		phtmlStyle->put_textDecorationUnderline(VARIANT_FALSE);
		phtmlStyle->put_color(varColor);
		phtmlStyle->Release();
	}
	m_spCurrElement = NULL;
	return S_OK;
}

HRESULT CDHtmlExploreDlg::OnClickFolder(IHTMLElement *phtmlElement)
{
	CComBSTR bstr;
	phtmlElement->get_innerText(&bstr);
	if (bstr)
	{
		CString strNewDir;
		strNewDir = m_strCurrDir + _T("\\") + CString(bstr);
		SetCurrentDirectory(strNewDir);
		RefreshDir();
	}
	return S_OK;
}

HRESULT CDHtmlExploreDlg::OnClickFile(IHTMLElement *phtmlElement)
{
	CComBSTR bstr;
	phtmlElement->get_innerText(&bstr);
	if (bstr)
	{
		CString strFullPath;
		strFullPath = m_strCurrDir + _T("\\") + CString(bstr);
		ShellExecute(NULL, NULL, strFullPath, NULL, NULL, SW_SHOWNORMAL);
	}
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CDHtmlExploreDlg::ShowContextMenu(DWORD /*dwID*/, POINT *ppt, IUnknown* /*pcmdtReserved*/, IDispatch* /*pdispReserved*/)
{
	CMenu ctxMenu;

	m_strCtxFileName.Empty();
	if (m_spCurrElement != NULL)
	{

		CComBSTR bstrFileName;
		m_spCurrElement->get_innerText(&bstrFileName);
		if (bstrFileName)
			m_strCtxFileName = bstrFileName;
	}
	ctxMenu.LoadMenu(IDR_CONTEXT_MENU);
	
	ctxMenu.GetSubMenu(0)->EnableMenuItem(ID_CONTEXT_PROPERTIES, MF_BYCOMMAND | 
		((m_spCurrElement==NULL) ? MF_GRAYED : MF_ENABLED));
	ctxMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, ppt->x, ppt->y, this, NULL);
	return S_OK;
}

void CDHtmlExploreDlg::OnContextBrowse() 
{
	// TODO: Add your command handler code here
	OnBrowse(NULL);
}

void CDHtmlExploreDlg::OnContextExit() 
{
	// TODO: Add your command handler code here
	EndDialog(IDOK);
}

void CDHtmlExploreDlg::OnContextProperties() 
{
	// TODO: Add your command handler code here
	ASSERT(!m_strCtxFileName.IsEmpty());
	CPropertiesDlg dlg;
	dlg.m_strFileName = m_strCurrDir + _T("\\") + m_strCtxFileName;
	dlg.DoModal();
}
