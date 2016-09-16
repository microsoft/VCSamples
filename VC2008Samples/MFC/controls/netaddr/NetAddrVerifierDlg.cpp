// NetAddrVerifierDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetAddrVerifier.h"
#include "NetAddrVerifierDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNetAddrVerifierDlg dialog


CNetAddrVerifierDlg::CNetAddrVerifierDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetAddrVerifierDlg::IDD, pParent),
	m_pValidateBtn(NULL), m_pNetAddr(NULL), m_pEdit(NULL), m_pButton(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	OSVERSIONINFO vi;
	ZeroMemory(&vi, sizeof(OSVERSIONINFO));
	vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx(&vi);

	// check if we are running under Vista
	if (vi.dwMajorVersion >= 6)
	{
		m_fVista = TRUE;
	}
	else
	{
		m_fVista = FALSE;
	}
}

CNetAddrVerifierDlg::~CNetAddrVerifierDlg()
{
	delete m_pNetAddr;
	delete m_pValidateBtn;
	delete m_pEdit;
	delete m_pButton;
}

void CNetAddrVerifierDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CNetAddrVerifierDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ENUM_BUTTON, &CNetAddrVerifierDlg::OnBnClickedButton1)
	// Message map
	ON_BN_CLICKED(IDC_VERIFY_BUTTON, &CNetAddrVerifierDlg::OnVerifyAll)
	ON_COMMAND(ID_SPLITBUTTONMENU_VALIDATEALL, &CNetAddrVerifierDlg::OnVerifyAll)
	ON_COMMAND(ID_SPLITBUTTONMENU_VALIDATEIPV4, &CNetAddrVerifierDlg::OnVerifyIPv4)
	ON_COMMAND(ID_SPLITBUTTONMENU_VALIDATEIPV6, &CNetAddrVerifierDlg::OnVerifyIPv6)
	ON_COMMAND(ID_SPLITBUTTONMENU_VALIDATENAMED, &CNetAddrVerifierDlg::OnVerifyNamed)
END_MESSAGE_MAP()


// CNetAddrVerifierDlg message handlers

BOOL CNetAddrVerifierDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Create controls dynamically according to OS version
	DWORD dwStyle = WS_TABSTOP | WS_VISIBLE;
	DWORD dwExStyle = WS_EX_CLIENTEDGE;
	if (m_fVista)
	{
		// If we are running under Vista, create a CNetAddressCtrl and CSplitButton control
		m_pNetAddr = new CNetAddressCtrl();
		m_pValidateBtn = new CSplitButton();
		DWORD dwStyle = WS_TABSTOP | WS_VISIBLE;
		DWORD dwExStyle = WS_EX_CLIENTEDGE;
		BOOL nRet = m_pNetAddr->CreateEx(dwExStyle,
			dwStyle | WS_BORDER,
			CRect(10,10,250,40),
			this,
			IDC_ADDRESS);
		m_pNetAddr->SetFont(GetFont());
		m_pNetAddr->SetCueBanner(_T("Input address then validate"));
		nRet = m_pValidateBtn->Create(_T("Validate"),
			dwStyle,
			CRect(10, 50, 160, 90),
			this,
			IDC_VERIFY_BUTTON);
		// Attach submenu to CSplitButton
		m_pValidateBtn->SetDropDownMenu(IDR_MENU1, 0);
		m_pValidateBtn->SetFont(GetFont());
	}
	else
	{
		// If we are running under XP, create a CEdit and CButton control
		m_pEdit = new CEdit();
		m_pEdit->Create(dwStyle | WS_BORDER,
			CRect(10, 10, 250, 40),
			this,
			IDC_ADDRESS);
		m_pEdit->SetFont(GetFont());
		m_pEdit->SetCueBanner(_T("Input address then validate"));
		m_pButton = new CButton();
		m_pButton->Create(_T("Validate"),
			dwStyle | BS_TEXT | BS_PUSHBUTTON,
			CRect(10, 50, 160, 90),
			this,
			IDC_VERIFY_BUTTON);
		m_pButton->SetFont(GetFont());
	}
	// Initialize the list control
	CRect rect;
	m_listCtrl.GetClientRect(rect);
	m_listCtrl.InsertColumn(0, _T("Shares"), 0, rect.Width());

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNetAddrVerifierDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

DWORD CNetAddrVerifierDlg::ConstructAddrMask(AddressKind kind)
{
	DWORD dwAddrMask = 0;
	switch(kind) {
		case AllKinds:
			dwAddrMask |= NET_STRING_ANY_ADDRESS;
			dwAddrMask |= NET_STRING_ANY_SERVICE;
			dwAddrMask |= NET_STRING_IP_NETWORK;
			break;

		case IPv4:
			dwAddrMask |= NET_STRING_IPV4_ADDRESS;
			dwAddrMask |= NET_STRING_IPV4_SERVICE;
			dwAddrMask |= NET_STRING_IPV4_NETWORK;
			break;

		case IPv6:
			dwAddrMask |= NET_STRING_IPV6_ADDRESS;
			dwAddrMask |= NET_STRING_IPV6_SERVICE;
			dwAddrMask |= NET_STRING_IPV6_NETWORK;
			break;

		case Named:
			dwAddrMask |= NET_STRING_NAMED_ADDRESS;
			dwAddrMask |= NET_STRING_NAMED_SERVICE;
			break;
	}
	return dwAddrMask;
}

std::wstring CNetAddrVerifierDlg::Ipv4AddrToString(IN_ADDR &addr)
{
	std::wstringstream msg;
	msg <<	addr.S_un.S_un_b.s_b1 << "." <<
			addr.S_un.S_un_b.s_b2 << "." <<
			addr.S_un.S_un_b.s_b3 << "." <<
			addr.S_un.S_un_b.s_b4;
	return msg.str();
}

std::wstring CNetAddrVerifierDlg::Ipv6AddrToString(IN6_ADDR &addr)
{
	// need to print out the address by bytes (in hex) for the correct order
	std::wstringstream msg;
	msg.flags(std::ios::hex);
	msg.fill('0');
	msg << std::setw(2) << addr.u.Byte[0];
	msg << std::setw(2) << addr.u.Byte[1];
	for (int i = 1; i < 8; i++)
	{
		msg << "::" << std::setw(2) << addr.u.Byte[i * 2];
		msg << std::setw(2) << addr.u.Byte[i * 2 + 1];
	}
	return msg.str();
}

BOOL CNetAddrVerifierDlg::Verify(AddressKind kind)
{
	// Update member variables with dialog data
	UpdateData(TRUE);
	if (m_fVista == TRUE)
	{
		// Create the structs necessary to store the address
		NET_ADDRESS_INFO nfo;
		NC_ADDRESS addr;
		addr.pAddrInfo = &nfo;

		// Construct and set the proper mask from the user's settings
		m_pNetAddr->SetAllowType(ConstructAddrMask(kind));

		// Verify the address entered in the form
		HRESULT res = m_pNetAddr->GetAddress(&addr);

		// If the verification failed, show the error tooltip
		if (res != S_OK)
		{
			m_strParsedAddr = "";
			m_pNetAddr->DisplayErrorTip();
		}
		else
		{
			std::wstringstream msg;
			switch(addr.pAddrInfo->Format)
			{
				case NET_ADDRESS_DNS_NAME:
					msg << addr.pAddrInfo->NamedAddress.Address;
					break;
				case NET_ADDRESS_IPV4:
					msg << Ipv4AddrToString(
						addr.pAddrInfo->Ipv4Address.sin_addr);
					break;
				case NET_ADDRESS_IPV6:
					msg << Ipv6AddrToString(
						addr.pAddrInfo->Ipv6Address.sin6_addr);
					break;
			}
			m_strParsedAddr = msg.str().c_str();
			m_pNetAddr->ShowBalloonTip(_T("Verification succeeded!"), m_strParsedAddr);
			return TRUE;
		}
	}
	else // Running on XP
	{
		CString str;
		// Get string from EDIT contrl
		GetDlgItemTextW(IDC_ADDRESS, str.GetBufferSetLength(256), 256);
		str.ReleaseBuffer();
		if (!str.IsEmpty()) // Validate Address
		{
			this->m_strParsedAddr = str;
			m_pEdit->ShowBalloonTip(_T("Verification succeeded!"), m_strParsedAddr);
			return TRUE;
		}
		else
		{
			// Show a similar balloon tip as NetAddressControl
			m_pEdit->ShowBalloonTip(_T(""), _T("The network address entered is invalid"));
		}
	}
	return FALSE;
}

void CNetAddrVerifierDlg::Enum()
{
	m_listCtrl.DeleteAllItems();
	PSHARE_INFO_0 BufPtr, p;
	NET_API_STATUS res;
	DWORD er=0, tr=0, resume=0, i;
	do // begin do
	{
		res = NetShareEnum(m_strParsedAddr.GetBuffer(), 0, (LPBYTE *) &BufPtr, -1, &er, &tr, &resume);
		// If the call succeeds,
		if(res == ERROR_SUCCESS || res == ERROR_MORE_DATA)
		{
			p = BufPtr;
			// Loop through the entries;
			//  print retrieved data.
			for(i=1;i<=er;i++)
			{
				CString str(p->shi0_netname);
				m_listCtrl.InsertItem(0, str);
				p++;
			}
			// Free the allocated buffer.
			NetApiBufferFree(BufPtr);
		}
		else
		{
			AfxMessageBox(_T("Cannot connect to server"), MB_OK | MB_ICONEXCLAMATION);
		}
	}
	while (res==ERROR_MORE_DATA);// Continue to call NetShareEnum while there are more entries
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNetAddrVerifierDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNetAddrVerifierDlg::OnBnClickedButton1()
{
	// Enum Share
	if (Verify(AllKinds) == TRUE)
		Enum();
}

void CNetAddrVerifierDlg::OnVerifyAll()
{
	Verify(AllKinds);
}

void CNetAddrVerifierDlg::OnVerifyIPv4()
{
	// Verify IPv4 Address
	Verify(IPv4);
}

void CNetAddrVerifierDlg::OnVerifyIPv6()
{
	// Verify IPv6 Address
	Verify(IPv6);
}

void CNetAddrVerifierDlg::OnVerifyNamed()
{
	// Verify DNS Address
	Verify(Named);
}
