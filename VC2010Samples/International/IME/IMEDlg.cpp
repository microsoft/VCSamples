/******************************************************************************\
*	IMEDlg.cpp : implementation file
*
*	This is a part of the Microsoft Source Code Samples. 
*	Copyright (c) Microsoft Corporation.
*	All rights reserved. 
*
*	This source code is only intended as a supplement to 
*	Microsoft Development Tools and/or WinHelp documentation.
*	See these sources for detailed information regarding the 
*	Microsoft samples programs.
\******************************************************************************/


#include "stdafx.h"
#include "IMM.h"
#include "IMEEdit.h"
#include "IME.h"
#include "IMEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Declare enum type Languages
extern enum LANGFLAG
{
   ENGLISH,				
   TRADITIONAL_CHINESE,	
   JAPANESE,
   KOREAN,
   SIMPLIFIED_CHINESE
} LangFlag;  

// Flag for effective options in conversion mode 
const BOOL fConvMode[5][13] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
	{1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, 
	{1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0}};

// Flag for effective options in sentence mode 
const BOOL fSentMode[5][6] = {
	{0, 0, 0, 0, 0, 0}, 
	{0, 1, 0, 0, 0, 0}, 
	{1, 1, 1, 1, 1, 1}, 
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}};

// Conversion mode message 
const DWORD dwConvModeMsg[13] = {
	IME_CMODE_ALPHANUMERIC,		IME_CMODE_NATIVE,		IME_CMODE_KATAKANA, 
	IME_CMODE_LANGUAGE,			IME_CMODE_FULLSHAPE,	IME_CMODE_ROMAN, 
	IME_CMODE_CHARCODE,			IME_CMODE_HANJACONVERT, IME_CMODE_SOFTKBD, 
	IME_CMODE_NOCONVERSION,		IME_CMODE_EUDC,			IME_CMODE_SYMBOL, 
	IME_CMODE_FIXED};

// Sentence mode message 
const DWORD dwSentModeMsg[6] = {
	IME_SMODE_NONE,			IME_SMODE_PLAURALCLAUSE,	IME_SMODE_SINGLECONVERT,	
	IME_SMODE_AUTOMATIC,	IME_SMODE_PHRASEPREDICT,	IME_SMODE_CONVERSATION };

const TCHAR szEnglishFontName[5][11] = {
	_T("Tahoma"),		_T("MingLiU"),		_T("MS PGothic"), 
	_T("Gulim"),		_T("NSimSun")};


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
// CIMEDlg dialog

CIMEDlg::CIMEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIMEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIMEDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSelectedID = 0;
}

void CIMEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIMEDlg)
	DDX_Control(pDX, IDC_COMBO_FONT, m_FontList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIMEDlg, CDialog)
	//{{AFX_MSG_MAP(CIMEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_IME_ENABLE, OnRadioImeEnable)
	ON_BN_CLICKED(IDC_RADIO_IME_DISABLE, OnRadioImeDisable)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_CBN_SELCHANGE(IDC_COMBO_FONT, OnSelchangeComboFont)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SETINPUTLANG, OnSetInputLang)
	ON_MESSAGE(WM_SETMODE, OnSetIME)
	ON_MESSAGE(WM_RESETMODE, OnReSetIME)
	ON_MESSAGE(WM_TOGGLE, OnToggleJPNIME)
	ON_COMMAND_RANGE(IDC_CHECK_IME_CMODE_ALPHANUMERIC, IDC_CHECK_IME_SMODE_CONVERSATION, OnChangeOption)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIMEDlg message handlers

BOOL CIMEDlg::OnInitDialog()
{
	CClientDC	dc(this);
	LOGFONT lf;

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
	
	// Use subclass to get WM_INPUTLANGCHANGE/WM_IME_NOTIFY message
	m_IMEEdit.SubclassDlgItem(IDC_IME_EDIT, this);

	// Check "IME Enable" button as a defult setting
	CheckDlgButton(IDC_RADIO_IME_ENABLE, BST_CHECKED);


	// Get current keyboard layout and enable/disable the check boxes
	m_IMEEdit.SetFont(0, NULL);

	// Get font names in system
	if (dc)
	{
		memset(&lf, 0, sizeof(LOGFONT));
		lf.lfCharSet = DEFAULT_CHARSET;

		::EnumFontFamiliesEx(dc, &lf, (FONTENUMPROC) EnumFontFamExProc, (LPARAM) &m_FontList, NULL);
	}

	OnSetInputLang(0L, 0L);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIMEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIMEDlg::OnPaint() 
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
HCURSOR CIMEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*****************************************************************************\
* Function: OnSetInputLang
*
* Receive WM_INPUTLANGCHANGE message from testing window and set language and
* create font
*
* Arguments:
*	WPARAM wParam - do not use
*	LPARAM lParam - do not use
\*****************************************************************************/
LRESULT CIMEDlg::OnSetInputLang(WPARAM, LPARAM)
{
	HWND	hWnd; 

	// Enable effective options 
	SetOption();

	// Get default setting in IME and display default setting
	hWnd = GetDlgItem(IDC_IME_EDIT)->m_hWnd;
	if (hWnd && IsWindow(hWnd))
	{
		// Get IME status and set conversion mode options in sample
		GetIMEMode(hWnd);
		::SetFocus(hWnd);
	}

#ifdef _UNICODE
	if (m_FontList.SelectString(0, m_IMEEdit.m_szWFontName) == CB_ERR)
#else
	if (m_FontList.SelectString(0, m_IMEEdit.m_szMBFontName) == CB_ERR)
#endif
		m_FontList.SelectString(0, szEnglishFontName[m_IMEEdit.m_nLanguage]);

	return 0L;
}

/*****************************************************************************\
* Function: SetOption
*
* Enable/Disable each check box using keyboard ID
*
* Arguments:
*   WORD wID - Keyboard ID
\*****************************************************************************/
void CIMEDlg::SetOption()
{
	int nID;

	// Enable/Disable check boxes of conversion mode
	for (nID = IDC_CHECK_IME_CMODE_ALPHANUMERIC; nID <= IDC_CHECK_IME_SMODE_CONVERSATION; nID++)
	{
		((CButton*)GetDlgItem(nID))->SetCheck(0);
		GetDlgItem(nID)->EnableWindow(fConvMode[m_IMEEdit.m_nLanguage][nID - IDC_CHECK_IME_CMODE_ALPHANUMERIC]);	
	} 

	// Enable/Disable check boxes of sentence mode
	for (nID = IDC_CHECK_IME_SMODE_NONE; nID <= IDC_CHECK_IME_SMODE_CONVERSATION; nID++)
	{
		((CButton*)GetDlgItem(nID))->SetCheck(0);
		GetDlgItem(nID)->EnableWindow(fSentMode[m_IMEEdit.m_nLanguage][nID - IDC_CHECK_IME_SMODE_NONE]);	
	}
}

/*****************************************************************************\
* Function: GetIMEMode
*
* Set IME mode of IME window and set options in sample
*
* Arguments:
*	HWND hWnd - handle of testing window
\*****************************************************************************/
void CIMEDlg::GetIMEMode(HWND hWnd)
{
	HIMC	hImc;
	UINT	nID;
	DWORD	dwConvMode, dwSentMode;

	// Get input context
	hImc = ImmGetContext(hWnd);
	if (hImc)
	{
		// Get current IME status
		ImmGetConversionStatus(hImc, &dwConvMode, &dwSentMode);
		if (m_IMEEdit.m_nLanguage == JAPANESE)
		{
			if (ImmGetOpenStatus(hImc))
				dwConvMode |= 1;
			else
				dwConvMode &= ~1;
		}

		// Change conversion mode options in sample
		for (nID = IDC_CHECK_IME_CMODE_NATIVE; nID <= IDC_CHECK_IME_CMODE_FIXED; nID++)
		{
			if (fConvMode[m_IMEEdit.m_nLanguage][nID - IDC_CHECK_IME_CMODE_ALPHANUMERIC])
			{
				// IME_CMODE_LANGUAGE option is a combination option 
				if (nID == IDC_CHECK_IME_CMODE_LANGUAGE)	
					((CButton*)GetDlgItem(nID))->SetCheck( (dwConvMode & dwConvModeMsg[1]) && (dwConvMode & dwConvModeMsg[2]));
				else
					((CButton*)GetDlgItem(nID))->SetCheck(dwConvMode & dwConvModeMsg[nID - IDC_CHECK_IME_CMODE_ALPHANUMERIC]);
				// IME_CMODE_ALPHANUMERIC and IME_CMODE_NATIVE are toggle options
				if (nID == IDC_CHECK_IME_CMODE_NATIVE)	
					((CButton*)GetDlgItem(IDC_CHECK_IME_CMODE_ALPHANUMERIC))->SetCheck(!(dwConvMode & dwConvModeMsg[nID - IDC_CHECK_IME_CMODE_ALPHANUMERIC]));
			}
		}

		// Change sentence mode options in sample
		// Set IME_SMODE_NONE option first. 
		if ((fSentMode[m_IMEEdit.m_nLanguage][0]) && (dwSentMode == IME_SMODE_NONE))
			((CButton*)GetDlgItem(IDC_CHECK_IME_SMODE_NONE))->SetCheck(1);
		else
			((CButton*)GetDlgItem(IDC_CHECK_IME_SMODE_NONE))->SetCheck(0);

		// Set other convseion option. If IME_SMODE_NONE is actived, other options are ignored
		for (nID = IDC_CHECK_IME_SMODE_PLAURALCLAUSE; nID <= IDC_CHECK_IME_SMODE_CONVERSATION; nID++)
		{
			if ((fSentMode[m_IMEEdit.m_nLanguage][nID - IDC_CHECK_IME_SMODE_NONE]) && (dwSentMode != IDC_CHECK_IME_SMODE_NONE))
				((CButton*)GetDlgItem(nID))->SetCheck(dwSentMode & dwSentModeMsg[nID - IDC_CHECK_IME_SMODE_NONE]);
		}

		// Release input context
		ImmReleaseContext(hWnd, hImc);
	}
}

/*****************************************************************************\
* Function: OnChangeOption
*
* Change the IME mode when user chick the check box
*
* Arguments:
*   UINT nID - ID of check box
\*****************************************************************************/
void CIMEDlg::OnChangeOption(UINT nID)
{
	// Set focus on edit window
	::SetFocus(GetDlgItem(IDC_IME_EDIT)->m_hWnd);
	
	// Save selected option
	m_nSelectedID = nID;
	
	// For Soft keyboard in Japanese Win98, OnSetIME must be called when edit 
	// window get focus
	if ((m_IMEEdit.m_nLanguage != JAPANESE) || m_IMEEdit.m_fIsNT)
		OnSetIME(0, 0);
}

/*****************************************************************************\
* Function: SetIMEMode
*
* Set IME mode
*
* Arguments:
*	HWND hWnd - handle testing window
*	DWORD dwNewConvMode - Option to change conversion mode
*	DWORD dwNewSentMode - Option to change sentence mode
*	BOOL fFlag - Turn on passed option if TRUE. Else turn off the option
\*****************************************************************************/
void CIMEDlg::SetIMEMode(HWND hWnd, DWORD dwNewConvMode, DWORD dwNewSentMode, BOOL fFlag)
{
	HIMC	hImc;
	DWORD	dwConvMode, dwSentMode;
	BOOL	fRet;

	// Get input context
	hImc = ImmGetContext(hWnd);
	if (hImc)
	{
		// Get current IME status
		ImmGetConversionStatus(hImc, &dwConvMode, &dwSentMode);

		// Change IME status using passed option
		if (fFlag)
		{
			fRet = ImmSetConversionStatus(hImc, dwConvMode | dwNewConvMode, dwSentMode | dwNewSentMode);
			if ((m_IMEEdit.m_nLanguage == JAPANESE) && (dwNewConvMode & IME_CMODE_NATIVE))
				ImmSetOpenStatus(hImc, fFlag);
 
		}
		else
		{
			ImmSetConversionStatus(hImc, dwConvMode & ~dwNewConvMode, dwSentMode & ~dwNewSentMode);
			if ((m_IMEEdit.m_nLanguage == JAPANESE) && (dwNewConvMode & IME_CMODE_NATIVE))
				ImmSetOpenStatus(hImc, fFlag);
		}

		// Release input context
		ImmReleaseContext(hWnd, hImc);
	}
}

/*****************************************************************************\
* Function: OnSetIME
*
* Receive WM_INT_NOTIFY(IMN_SETCOMPOSITIONWINDOW) message from testing window
* or called when option changed
*
* Arguments:
*	WPARAM wParam - notification command
*	LPARAM lParam - command-specific data
\*****************************************************************************/
LRESULT CIMEDlg::OnSetIME(WPARAM, LPARAM)
{
	HWND	hWnd; 
	BOOL	fFlag;

	// Check saved option
	if (m_nSelectedID)
	{
		hWnd = GetDlgItem(IDC_IME_EDIT)->m_hWnd;

		if (hWnd && IsWindow(hWnd))
		{
			// Get check box status
			fFlag = ((CButton*)GetDlgItem(m_nSelectedID))->GetCheck();

			// Set conversion mode options in sample
			if (m_nSelectedID < IDC_CHECK_IME_SMODE_NONE)
			{	
				// IME_CMODE_ALPHANUMERIC and IME_CMODE_NATIVE are toggle options
				if (m_nSelectedID == IDC_CHECK_IME_CMODE_ALPHANUMERIC)
					SetIMEMode(hWnd, dwConvModeMsg[1], 0, !fFlag);
				else
					SetIMEMode(hWnd, dwConvModeMsg[m_nSelectedID - IDC_CHECK_IME_CMODE_ALPHANUMERIC], 0, fFlag);
			}
			// Set sentense mode options in sample
			else if (m_nSelectedID == IDC_CHECK_IME_SMODE_NONE)
			{
				// To set IME_SMODE_NONE, conversion mode must be 0 
				SetIMEMode(hWnd, 0, ~dwSentModeMsg[m_nSelectedID - IDC_CHECK_IME_SMODE_NONE], !fFlag);
			}
			else
				SetIMEMode(hWnd, 0, dwSentModeMsg[m_nSelectedID - IDC_CHECK_IME_SMODE_NONE], fFlag);

			// Get IME status and set conversion mode options in sample
			GetIMEMode(hWnd);
		}
		m_nSelectedID = 0;			
	}

	return 0L;
}

/*****************************************************************************\
* Function: OnReSetIME
*
* Receive WM_INT_NOTIFY(IMN_SETCONVERSIONMODE, IMN_SETSENTENCEMODE) message 
* from testing window
*
* Arguments:
*	WPARAM wParam - notification command
*	LPARAM lParam - command-specific data
\*****************************************************************************/
LRESULT CIMEDlg::OnReSetIME(WPARAM, LPARAM)
{
	HWND	hWnd; 

	// Synchronize IME option with IME window
	hWnd = GetDlgItem(IDC_IME_EDIT)->m_hWnd;
	if (hWnd && IsWindow(hWnd))
	{
		// Get IME status and set conversion mode options in sample
		GetIMEMode(hWnd);
		::SetFocus(hWnd);
	}

	return 0L;
}

/*****************************************************************************\
* Function: OnToggleJPNIME
*
* Set Open status for Japanese IME
*
* Arguments:
*	WPARAM wParam - notification command
*	LPARAM lParam - command-specific data
\*****************************************************************************/
LRESULT CIMEDlg::OnToggleJPNIME(WPARAM, LPARAM)
{
	HIMC	hImc;

	if (m_IMEEdit.m_nLanguage != JAPANESE)
		return 0L;

	// Get input context
	hImc = ImmGetContext(this->m_hWnd);
	if (hImc)
	{
		if (ImmGetOpenStatus(hImc))
		{
			((CButton*)GetDlgItem(IDC_CHECK_IME_CMODE_NATIVE))->SetCheck(1);
			((CButton*)GetDlgItem(IDC_CHECK_IME_CMODE_ALPHANUMERIC))->SetCheck(0);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_IME_CMODE_NATIVE))->SetCheck(0);
			((CButton*)GetDlgItem(IDC_CHECK_IME_CMODE_ALPHANUMERIC))->SetCheck(1);
		}

		// Release input context
		ImmReleaseContext(this->m_hWnd, hImc);
	}

	return 0L;
}

/*****************************************************************************\
* Function: OnRadioImeEnable
*
* Event of "IME Enable" button 
\*****************************************************************************/
void CIMEDlg::OnRadioImeEnable() 
{
	HWND hWnd; 

	hWnd = GetDlgItem(IDC_IME_EDIT)->m_hWnd;
	if (hWnd && IsWindow(hWnd))
	{
		// Enable IME
		if (m_hImc)
		{
			// Associate the input context with testing window
			ImmAssociateContext(hWnd, m_hImc);
			m_hImc = NULL;
		}

		// Synchronize the current setting in sample and IME window
		OnReSetIME(0, 0);

		::SetFocus(hWnd);
	}	
}

/*****************************************************************************\
* Function: OnRadioImeEnable
*
* Event of "IME Disable" button 
\*****************************************************************************/
void CIMEDlg::OnRadioImeDisable() 
{
	HWND	hWnd; 

	hWnd = GetDlgItem(IDC_IME_EDIT)->m_hWnd;
	if (hWnd && IsWindow(hWnd))
	{
		// Get input context for backup. 
		m_hImc = ImmGetContext(hWnd);

		// Remove association the testing 
		if (m_hImc)
			ImmAssociateContext(hWnd, NULL);

		// Release input context
		ImmReleaseContext(hWnd, m_hImc);
		::SetFocus(hWnd);
	}	
}

/*****************************************************************************\
* Function: OnSelchangeComboFont
*
* Event of changing font 
\*****************************************************************************/
void CIMEDlg::OnSelchangeComboFont() 
{	
	CString	szFontName;

	// Get selected font name and set font
	m_FontList.GetLBText(m_FontList.GetCurSel(), szFontName);
	m_IMEEdit.SetFont(0, (LPCTSTR)szFontName);
	
	::SetFocus(GetDlgItem(IDC_IME_EDIT)->m_hWnd);		
}

/*****************************************************************************\
* Function: EnumFamScreenCallBackEx
*
* Event of changing font 
\*****************************************************************************/
BOOL CALLBACK AFX_EXPORT CIMEDlg::EnumFontFamExProc(ENUMLOGFONTEX* pelf,
	NEWTEXTMETRICEX*, int FontType, LPVOID pThis)
{
	// don't put in non-printer raster fonts
	if (FontType & TRUETYPE_FONTTYPE)
	{
		if (((CComboBox *) (pThis))->FindString(0, (LPCTSTR) pelf->elfLogFont.lfFaceName) == CB_ERR)
			((CComboBox *) (pThis))->AddString( (LPCTSTR) pelf->elfLogFont.lfFaceName);
	}
	return 1;
}

void CIMEDlg::OnOk() 
{
	PostQuitMessage(0);	
}
