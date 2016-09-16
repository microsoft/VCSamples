// calcdlg.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "mfccalc.h"
#include "calcdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
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

// Implementation
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //{{AFX_MSG(CAboutDlg)
    virtual BOOL OnInitDialog();
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
// CAboutDlg message handlers

BOOL CAboutDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg dialog

IMPLEMENT_DYNCREATE(CCalcDlg, CDialog)

BEGIN_DISPATCH_MAP(CCalcDlg, CDialog)
    //{{AFX_DISPATCH_MAP(CCalcDlg)
    DISP_PROPERTY_EX(CCalcDlg, "Accum", GetAccum, SetAccum, VT_I4)
    DISP_PROPERTY_EX(CCalcDlg, "Operand", GetOperand, SetOperand, VT_I4)
    DISP_PROPERTY_EX(CCalcDlg, "Operation", GetOperation, SetOperation, VT_I2)
    DISP_PROPERTY_EX(CCalcDlg, "Visible", GetVisible, SetVisible, VT_BOOL)
    DISP_FUNCTION(CCalcDlg, "Evaluate", Evaluate, VT_BOOL, VTS_NONE)
    DISP_FUNCTION(CCalcDlg, "Clear", Clear, VT_EMPTY, VTS_NONE)
    DISP_FUNCTION(CCalcDlg, "Display", Display, VT_EMPTY, VTS_NONE)
    DISP_FUNCTION(CCalcDlg, "Close", Close, VT_EMPTY, VTS_NONE)
    DISP_FUNCTION(CCalcDlg, "Button", Button, VT_BOOL, VTS_BSTR)
    //}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

#ifndef IMPLEMENT_OLECREATE_SINGLE
// MFC will provide this macro in the future.  For now, we define it.
#define IMPLEMENT_OLECREATE_SINGLE(class_name, external_name, \
    l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
        RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
    const AFX_DATADEF GUID class_name::guid = \
        { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };
#endif

static const IID IID_ICalcDlg = 
{0x990BA900, 0xF45E, 0x11CD, { 0x8C, 0x3D, 0x00, 0xAA, 0x00, 0x4B, 0xB3, 0xB7 } };

BEGIN_INTERFACE_MAP(CCalcDlg, CDialog)
	INTERFACE_PART(CCalcDlg, IID_ICalcDlg, Dispatch)
END_INTERFACE_MAP()


// {62C4DD10-F45E-11cd-8C3D-00AA004BB3B7}
IMPLEMENT_OLECREATE_SINGLE(CCalcDlg, "mfccalc.calculator", 
    0x62c4dd10, 0xf45e, 0x11cd, 0x8c, 0x3d, 0x0, 0xaa, 0x0, 0x4b, 0xb3, 0xb7);

CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CCalcDlg::IDD, pParent)
{
    m_bAutoDelete = TRUE;       // default to auto-delete
    m_dwRegister = 0;               // not registered as active by default

    //{{AFX_DATA_INIT(CCalcDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT

    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    // Note that LoadAccelerator does not require DestroyAcceleratorTable
    m_hAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDD));

    // clear the contents of the calculator and reset state
    OnClickedClear();

    // enable this object for OLE automation
    EnableAutomation();
}   

CCalcDlg::~CCalcDlg()
{
    if (m_dwRegister != 0)
        RevokeActiveObject(m_dwRegister, NULL);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CCalcDlg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg implementation

void CCalcDlg::PerformOperation()
{
    if (m_errorState != ErrNone)
        return;

    if (m_bOperandAvail)
    {
        if (m_operator == OpNone)
            m_accum = m_operand;
        else if (m_operator == OpMultiply)
            m_accum *= m_operand;
        else if (m_operator == OpDivide)
        {
            if (m_operand == 0)
                m_errorState = ErrDivideByZero;
            else
                m_accum /= m_operand;
        }
        else if (m_operator == OpAdd)
            m_accum += m_operand;
        else if (m_operator == OpSubtract)
            m_accum -= m_operand;
    }

    m_bOperandAvail = FALSE;
    UpdateDisplay();
}

void CCalcDlg::ClickedNumber(long l)
{
    if (m_errorState != ErrNone)
        return;

    if (!m_bOperandAvail)
        m_operand = 0L;

    SetOperand(m_operand*10+l);
    UpdateDisplay();
}

void CCalcDlg::UpdateDisplay()
{
    if (GetSafeHwnd() == NULL)
        return;

    CString str;
    if (m_errorState != ErrNone)
        str.LoadString(IDS_ERROR);
    else
    {
        long lVal = (m_bOperandAvail) ? m_operand : m_accum;
        str.Format(_T("%ld"), lVal);
    }
    GetDlgItem(IDE_ACCUM)->SetWindowText(str);
    GetDlgItem(IDC_INVISIBLE_FOCUS)->SetFocus();
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
    //{{AFX_MSG_MAP(CCalcDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_COMMAND_RANGE(IDB_0, IDB_9, OnClickedNumber)
    ON_BN_CLICKED(IDB_CLEAR, OnClickedClear)
    ON_BN_CLICKED(IDB_DIVIDE, OnClickedDivide)
    ON_BN_CLICKED(IDB_EQUAL, OnClickedEqual)
    ON_BN_CLICKED(IDB_MINUS, OnClickedMinus)
    ON_BN_CLICKED(IDB_PLUS, OnClickedPlus)
    ON_BN_CLICKED(IDB_TIMES, OnClickedTimes)
    ON_EN_SETFOCUS(IDE_ACCUM, OnSetFocusAccum)
    //}}AFX_MSG_MAP
#ifdef _MAC
    ON_BN_CLICKED(IDB_CLOSE, OnCancel)
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg message handlers

BOOL CCalcDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    CString strAboutMenu;
    strAboutMenu.LoadString(IDS_ABOUTBOX);
    if (!strAboutMenu.IsEmpty())
    {
#ifdef _MAC
        // On the Macintosh, the "About..." menu item is already there.  We
        //  just need to rename it and attach it to the about command.
        pSysMenu->ModifyMenu(0, MF_BYPOSITION, IDM_ABOUTBOX, strAboutMenu);
#else
        pSysMenu->AppendMenu(MF_SEPARATOR);
        pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
#endif
    }

#ifndef _MAC
    pSysMenu->RemoveMenu(SC_MAXIMIZE, MF_BYCOMMAND);
    pSysMenu->RemoveMenu(SC_SIZE, MF_BYCOMMAND);
#endif
    
    // want focus to stay on the dialog itself (until a button is clicked)
    SetFocus();
    return FALSE;  
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcDlg::OnPaint() 
{
    if (!IsIconic())
    {
        CDialog::OnPaint();
        return;
    }

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalcDlg::OnQueryDragIcon()
{
    return (HCURSOR)m_hIcon;
}

void CCalcDlg::OnClickedNumber(UINT nID) 
{
    ASSERT(nID >= IDB_0 && nID <= IDB_9);
    ClickedNumber(nID - IDB_0);
}

void CCalcDlg::OnClickedClear() 
{
    m_operator = OpNone;
    m_operand = 0L;
    m_accum = 0L;
    m_bOperandAvail = FALSE;
    m_errorState = ErrNone;
    UpdateDisplay();
}

void CCalcDlg::OnClickedDivide() 
{
    PerformOperation();
    m_operator = OpDivide;
}

void CCalcDlg::OnClickedEqual() 
{
    PerformOperation();
    m_operator = OpNone;
}

void CCalcDlg::OnClickedMinus() 
{
    PerformOperation();
    m_operator = OpSubtract;
}

void CCalcDlg::OnClickedPlus() 
{
    PerformOperation();
    m_operator = OpAdd;
}

void CCalcDlg::OnClickedTimes() 
{
    PerformOperation();
    m_operator = OpMultiply;
}

BOOL CCalcDlg::PreTranslateMessage(MSG* pMsg) 
{
    if (m_hAccel != NULL && TranslateAccelerator(m_hWnd, m_hAccel, pMsg))
        return TRUE;
    
    return CDialog::PreTranslateMessage(pMsg);
}

void CCalcDlg::PostNcDestroy() 
{
    if (m_bAutoDelete)
        delete this;
}

void CCalcDlg::OnCancel()
{
    DestroyWindow();
}

void CCalcDlg::OnOK()
{
}

void CCalcDlg::OnSetFocusAccum() 
{
    GetDlgItem(IDC_INVISIBLE_FOCUS)->SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg automation

BOOL CCalcDlg::RegisterActive()
{
    // attempt to register as the active object for the CCalcDlg CLSID
    return RegisterActiveObject(GetInterface(&IID_IUnknown), 
        CCalcDlg::guid, NULL, &m_dwRegister) == NOERROR;
}

long CCalcDlg::GetAccum() 
{
    return m_accum;
}

void CCalcDlg::SetAccum(long nNewValue) 
{
    m_accum = nNewValue;
}

long CCalcDlg::GetOperand() 
{
    return m_operand;
}

void CCalcDlg::SetOperand(long nNewValue) 
{
    m_operand = nNewValue;
    m_bOperandAvail = TRUE;
}

short CCalcDlg::GetOperation() 
{
    return (short) m_operator;
}

void CCalcDlg::SetOperation(short nNewValue) 
{
    m_operator = (Operator)nNewValue;
}

BOOL CCalcDlg::GetVisible() 
{
    return m_hWnd != NULL && (GetStyle() & WS_VISIBLE) != 0;
}

void CCalcDlg::SetVisible(BOOL bNewValue) 
{
    if (bNewValue == GetVisible())
        return;

    if (bNewValue)
    {
        // create it if necessary
        if (m_hWnd == NULL && !Create(CCalcDlg::IDD))
            return;

        // set up as the active window for the application
        if (AfxGetThread()->m_pMainWnd == NULL)
            AfxGetThread()->m_pMainWnd = this;

        // show it
        ShowWindow(SW_SHOWNORMAL);
    }
    else
    {
        if (m_hWnd != NULL)
            ShowWindow(SW_HIDE);
    }
}

BOOL CCalcDlg::Evaluate() 
{
    OnClickedEqual();
    return m_errorState == ErrNone;
}

void CCalcDlg::Clear() 
{
    OnClickedClear();
}

void CCalcDlg::Display() 
{
    UpdateDisplay();
}

void CCalcDlg::Close() 
{
    if (m_hWnd == NULL)
    {
        AfxPostQuitMessage(0);
        return;
    }

    BOOL bAutoDelete = m_bAutoDelete;
    m_bAutoDelete = FALSE;
    DestroyWindow();
    m_bAutoDelete = bAutoDelete;
}

BOOL CCalcDlg::Button(LPCTSTR szButton) 
{
    switch (szButton[0])
    {
    case 'c':
    case 'C':
        OnClickedClear();
        break;

    case '/':
        OnClickedDivide();
        break;
    case '+':
        OnClickedPlus();
        break;
    case '-':
        OnClickedMinus();
        break;
    case '*':
        OnClickedTimes();
        break;
    case '=':
        OnClickedEqual();
        break;

    default:
        if (szButton[0] >= '0' && szButton[0] <= '9')
            ClickedNumber(szButton[0] - '0');
        else
            return FALSE;
        break;
    }
    return TRUE;
}
