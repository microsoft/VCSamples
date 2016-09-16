
// UIAnimationTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UIAnimationTest.h"
#include "UIAnimationTestDlg.h"
#include "afxdialogex.h"

#include "ChildDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUIAnimationTestDlg dialog




CUIAnimationTestDlg::CUIAnimationTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUIAnimationTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUIAnimationTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_FADE, m_btnCheckFade);
    DDX_Control(pDX, IDC_CHECK_SLIDE_UP, m_btnCheckSlideUp);
    DDX_Control(pDX, IDC_CHECK_SLIDE_DOWN, m_btnCheckSlideDown);
    DDX_Control(pDX, IDC_CHECK_SLIDE_LEFT, m_btnCheckSlideLeft);
    DDX_Control(pDX, IDC_CHECK_SLIDE_RIGHT, m_btnCheckSlideRight);
    DDX_Control(pDX, IDC_CHECK_SCALE, m_btnCheckScale);
    DDX_Control(pDX, IDC_CHECK_USEBOTH, m_btnCheckUseBoth);
    DDX_Control(pDX, IDC_COMBO_DURATION, m_comboDuration);
}

BEGIN_MESSAGE_MAP(CUIAnimationTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_CHECK_FADE, OnClickedCheck)
    ON_BN_CLICKED(IDC_CHECK_SCALE, OnClickedCheck)
    ON_BN_CLICKED(IDC_CHECK_USEBOTH, OnClickedCheck)
    ON_BN_CLICKED(IDC_CHECK_SLIDE_UP, OnClickedCheckSlideUp)
    ON_BN_CLICKED(IDC_CHECK_SLIDE_DOWN, OnClickedCheckSlideDown)
    ON_BN_CLICKED(IDC_CHECK_SLIDE_LEFT, OnClickedCheckSlideLeft)
    ON_BN_CLICKED(IDC_CHECK_SLIDE_RIGHT, OnClickedCheckSlideRight)
    ON_CBN_SELCHANGE(IDC_COMBO_DURATION, OnSelchangeComboDuration)
END_MESSAGE_MAP()


// CUIAnimationTestDlg message handlers

static DWORD CALLBACK 
RCStreamInCallback(DWORD dwCookie, LPBYTE pbBuff, LONG cb, LONG *pcb)
{
   CFile* pFile = (CFile*)dwCookie;
   *pcb = pFile->Read(pbBuff, cb);
   return 0;
}


BOOL CUIAnimationTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	CWnd* pWnd = GetDlgItem(IDC_CONTROL_PLACE);
	if (pWnd->GetSafeHwnd() != NULL)
	{
		CRect rect;
		pWnd->GetWindowRect(rect);
		ScreenToClient(rect);
		pWnd->DestroyWindow();

		m_wndAnimation.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP, rect, this, IDC_CONTROL_PLACE);

        CRect rectDummy(0, 0, 1, 1);

		{
            if (m_ilIcons16.GetSafeHandle() == NULL || m_ilIcons16.GetImageCount() == 0)
            {
                m_ilIcons16.Create(16, 16, ILC_COLOR16, 0, 1);
                CBitmap bmp;
                if (bmp.LoadBitmap(IDB_ICONS_16))
                {
                    m_ilIcons16.Add(&bmp, (CBitmap*)NULL);
                }
            }

			CTreeCtrl* pWnd = new CTreeCtrl;
			pWnd->Create(WS_CHILD | WS_TABSTOP | TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT | TVS_SHOWSELALWAYS, 
				rectDummy, &m_wndAnimation, 1);
            pWnd->SetImageList(&m_ilIcons16, TVSIL_NORMAL);
            pWnd->SetImageList(&m_ilIcons16, TVSIL_STATE);

			HTREEITEM hItem = pWnd->InsertItem(_T("Root"), 0, 0);

            int nCount = m_ilIcons16.GetImageCount();
            for (int i = 1; i < nCount; i++)
            {
                CString str;
                str.Format(_T("Child %d"), i);
                pWnd->InsertItem(str, i, i, hItem);
            }

			pWnd->Expand(hItem, TVE_EXPAND);

			m_wndAnimation.AddControl(pWnd, _T("Tree View"));
		}
		{
            if (m_ilIcons32.GetSafeHandle() == NULL || m_ilIcons32.GetImageCount() == 0)
            {
                m_ilIcons32.Create(32, 32, ILC_COLOR32, 0, 1);
                CBitmap bmp;
                if (bmp.LoadBitmap(IDB_ICONS_32))
                {
                    m_ilIcons32.Add(&bmp, (CBitmap*)NULL);
                }
            }

			CListCtrl* pWnd = new CListCtrl;
			pWnd->Create(WS_CHILD | WS_TABSTOP | LVS_SHOWSELALWAYS | LVS_AUTOARRANGE | LVS_ICON, 
				rectDummy, &m_wndAnimation, 2);
            pWnd->SetExtendedStyle(LVS_EX_DOUBLEBUFFER);
            pWnd->SetImageList(&m_ilIcons32, LVSIL_NORMAL);

            int nCount = m_ilIcons32.GetImageCount();
            for (int i = 0; i < nCount; i++)
            {
                CString str;
                str.Format(_T("Item %d"), i + 1);
                pWnd->InsertItem(i, str, i);
            }

			m_wndAnimation.AddControl(pWnd, _T("List View"));
		}
		{
			CMonthCalCtrl* pWnd = new CMonthCalCtrl;
			pWnd->Create(WS_CHILD | WS_TABSTOP | LVS_LIST | LVS_SHOWSELALWAYS, 
				rectDummy, &m_wndAnimation, 3);

			m_wndAnimation.AddControl(pWnd, _T("Month Calendar"));
		}
        {
            CRichEditCtrl* pWnd = new CRichEditCtrl;
            pWnd->Create(WS_CHILD | WS_TABSTOP | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, rectDummy, &m_wndAnimation, 4);

            HINSTANCE hInstance = AfxFindResourceHandle(MAKEINTRESOURCE(IDR_RTF), _T("RTF"));
            if (hInstance != NULL)
            {
                HRSRC hResource = ::FindResource(hInstance, MAKEINTRESOURCE(IDR_RTF), _T("RTF"));
                if (hResource != NULL)
                {
                    DWORD nSize = ::SizeofResource(hInstance, hResource);
                    HGLOBAL hGlobal = ::LoadResource(hInstance, hResource);
                    if (hGlobal != NULL)
                    {
                        CMemFile mf((LPBYTE)::LockResource(hGlobal), nSize);

                        EDITSTREAM es;
                        es.dwCookie    = (DWORD)&mf;
                        es.pfnCallback = RCStreamInCallback; 
                        pWnd->StreamIn(SF_RTF, es);

                        ::UnlockResource(hGlobal);
                    }
                    ::FreeResource(hResource);
                }
            }

            m_wndAnimation.AddControl(pWnd, _T("Rich Edit"));
        }
        {
            CChildDialog* pWnd = new CChildDialog;
            pWnd->Create(CChildDialog::IDD, &m_wndAnimation);

            m_wndAnimation.AddControl(pWnd, _T("Dialog"));
        }
	}

    m_comboDuration.SetCurSel(0);
    OnSelchangeComboDuration();

    m_btnCheckFade.SetCheck(BST_CHECKED);
    m_btnCheckScale.SetCheck(BST_CHECKED);
    OnClickedCheck();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUIAnimationTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUIAnimationTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUIAnimationTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUIAnimationTestDlg::OnClickedCheckSlideUp()
{
    if (!m_wndAnimation.IsAnimationInProgress() && m_btnCheckSlideUp.GetCheck() == BST_CHECKED)
    {
        m_btnCheckSlideDown.SetCheck(BST_UNCHECKED);
    }
    OnClickedCheck();
}


void CUIAnimationTestDlg::OnClickedCheckSlideDown()
{
    if (!m_wndAnimation.IsAnimationInProgress() && m_btnCheckSlideDown.GetCheck() == BST_CHECKED)
    {
        m_btnCheckSlideUp.SetCheck(BST_UNCHECKED);
    }
    OnClickedCheck();
}


void CUIAnimationTestDlg::OnClickedCheckSlideLeft()
{
    if (!m_wndAnimation.IsAnimationInProgress() && m_btnCheckSlideLeft.GetCheck() == BST_CHECKED)
    {
        m_btnCheckSlideRight.SetCheck(BST_UNCHECKED);
    }
    OnClickedCheck();
}


void CUIAnimationTestDlg::OnClickedCheckSlideRight()
{
    if (!m_wndAnimation.IsAnimationInProgress() && m_btnCheckSlideRight.GetCheck() == BST_CHECKED)
    {
        m_btnCheckSlideLeft.SetCheck(BST_UNCHECKED);
    }
    OnClickedCheck();
}


void CUIAnimationTestDlg::OnClickedCheck()
{
    DWORD type = 
        (m_btnCheckFade.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeFade : 0) |
        (m_btnCheckSlideUp.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeSlideUp : 0) |
        (m_btnCheckSlideDown.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeSlideDown : 0) |
        (m_btnCheckSlideLeft.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeSlideLeft : 0) |
        (m_btnCheckSlideRight.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeSlideRight : 0) |
        (m_btnCheckScale.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeScale : 0) |
        (m_btnCheckUseBoth.GetCheck() == BST_CHECKED ? CUIAnimationWnd::e_AnimationTypeBoth : 0);

    m_wndAnimation.SetAnimationType(CUIAnimationWnd::e_AnimationSelect, type);
    DWORD typeSet = m_wndAnimation.GetAnimationType(CUIAnimationWnd::e_AnimationSelect);
    if (typeSet != type)
    {
        m_btnCheckFade.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeFade) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckSlideUp.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeSlideUp) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckSlideDown.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeSlideDown) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckSlideLeft.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeSlideLeft) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckSlideRight.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeSlideRight) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckScale.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeScale) ? BST_CHECKED : BST_UNCHECKED);
        m_btnCheckUseBoth.SetCheck((typeSet & CUIAnimationWnd::e_AnimationTypeBoth) ? BST_CHECKED : BST_UNCHECKED);
    }
}


void CUIAnimationTestDlg::OnSelchangeComboDuration()
{
    double duration = (m_comboDuration.GetCurSel() + 1) * 0.5;

    m_wndAnimation.SetAnimationDuration(CUIAnimationWnd::e_AnimationSelect, duration);
    double durationSet = m_wndAnimation.GetAnimationDuration(CUIAnimationWnd::e_AnimationSelect);
    if (durationSet != duration)
    {
        m_comboDuration.SetCurSel((int)(durationSet / 0.5) - 1);
    }
}
