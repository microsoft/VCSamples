// ctlcommDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ctlcomm.h"
#include "ctlcommDlg.h"

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
// CCtlcommDlg dialog

CCtlcommDlg::CCtlcommDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CCtlcommDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CCtlcommDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtlcommDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CCtlcommDlg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCtlcommDlg, CDialog)
    //{{AFX_MSG_MAP(CCtlcommDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_COM1, OnCom1)
    ON_BN_CLICKED(IDC_COM2, OnCom2)
    ON_BN_CLICKED(IDC_COM3, OnCom3)
    ON_BN_CLICKED(IDC_COM4, OnCom4)
    ON_BN_CLICKED(IDC_COM5, OnCom5)
    ON_BN_CLICKED(IDC_COM6, OnCom6)
    ON_BN_CLICKED(IDC_COM7, OnCom7)
    ON_BN_CLICKED(IDC_COM8, OnCom8)
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_RESET, OnReset)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtlcommDlg message handlers

BOOL CCtlcommDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    OnReset();

    CoInitialize(NULL);
    HRESULT hr = pOuter.CreateInstance(__uuidof(COuter), NULL, CLSCTX_INPROC_SERVER);
    if (FAILED(hr))
    {
        TCHAR buf[64];
        _stprintf_s(buf, 64, _T("CreateInstance failed(hr=0x%x)\n"), hr);
        AfxMessageBox(buf);
        if ((bool) pOuter)
            pOuter.Release();
        CoUninitialize();
        CDialog::EndDialog(IDCANCEL);
    }
    
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
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon
    
    // TODO: Add extra initialization here
    
    
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCtlcommDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCtlcommDlg::OnPaint() 
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
HCURSOR CCtlcommDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CCtlcommDlg::OnCom1() 
{
    SetDlgItemText(IDC_COM1, pOuter->GetName(0));
}

void CCtlcommDlg::OnCom2() 
{
    SetDlgItemText(IDC_COM2, pOuter->GetName(1));
}

void CCtlcommDlg::OnCom3() 
{
    SetDlgItemText(IDC_COM3, pOuter->GetName(2));
}

void CCtlcommDlg::OnCom4() 
{
    SetDlgItemText(IDC_COM4, pOuter->GetName(3));
}

void CCtlcommDlg::OnCom5() 
{
    SetDlgItemText(IDC_COM5, pOuter->GetName(4));
}

void CCtlcommDlg::OnCom6() 
{
    SetDlgItemText(IDC_COM6, pOuter->GetName(5));
}

void CCtlcommDlg::OnCom7() 
{
    SetDlgItemText(IDC_COM7, pOuter->GetName(6));
}

void CCtlcommDlg::OnCom8() 
{
    SetDlgItemText(IDC_COM8, pOuter->GetName(7));
}

void CCtlcommDlg::OnReset() 
{
    SetDlgItemText(IDC_COM1, "COM_INTERFACE_ENTRY");
    SetDlgItemText(IDC_COM2, "COM_INTERFACE_ENTRY_TEAR_OFF");
    SetDlgItemText(IDC_COM3, "COM_INTERFACE_ENTRY_CACHED_TEAR_OFF");
    SetDlgItemText(IDC_COM4, "COM_INTERFACE_ENTRY_CHAIN");
    SetDlgItemText(IDC_COM5, "COM_INTERFACE_ENTRY_AGGREGATE");
    SetDlgItemText(IDC_COM6, "COM_INTERFACE_ENTRY_AUTOAGGREGATE");
    SetDlgItemText(IDC_COM7, "COM_INTERFACE_ENTRY_AGGREGATE_BLIND");
    SetDlgItemText(IDC_COM8, "COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND");
}

void CCtlcommDlg::OnClose() 
{
    if ((bool) pOuter)
        pOuter.Release();
    OleUninitialize();
    CDialog::OnClose();
}

