// NetAddressCtrlPage.cpp : implementation file
//

#include "stdafx.h"

#include "CmnCtrl3.h"
#include "NetAddressCtrlPage.h"

static const struct
{
    DWORD   dwNetString;
    LPCTSTR lpszDisplay;
} netStrings[] = 
{
    { NET_STRING_IPV4_ADDRESS, _T("NET_STRING_IPV4_ADDRESS") },
    { NET_STRING_IPV4_SERVICE, _T("NET_STRING_IPV4_SERVICE") },
    { NET_STRING_IPV4_NETWORK, _T("NET_STRING_IPV4_NETWORK") },

    { NET_STRING_IPV6_ADDRESS, _T("NET_STRING_IPV6_ADDRESS") },
    { NET_STRING_IPV6_ADDRESS_NO_SCOPE, _T("NET_STRING_IPV6_ADDRESS_NO_SCOPE") },
    { NET_STRING_IPV6_SERVICE, _T("NET_STRING_IPV6_SERVICE") },
    { NET_STRING_IPV6_SERVICE_NO_SCOPE, _T("NET_STRING_IPV6_SERVICE_NO_SCOPE") },
    { NET_STRING_IPV6_NETWORK, _T("NET_STRING_IPV6_NETWORK") },

    { NET_STRING_NAMED_ADDRESS, _T("NET_STRING_NAMED_ADDRESS") },
    { NET_STRING_NAMED_SERVICE, _T("NET_STRING_NAMED_SERVICE") },

    { NET_STRING_IP_ADDRESS, _T("NET_STRING_IP_ADDRESS") },
    { NET_STRING_IP_ADDRESS_NO_SCOPE, _T("NET_STRING_IP_ADDRESS_NO_SCOPE") },
    { NET_STRING_IP_SERVICE, _T("NET_STRING_IP_SERVICE") },
    { NET_STRING_IP_SERVICE_NO_SCOPE, _T("NET_STRING_IP_SERVICE_NO_SCOPE") },
    { NET_STRING_IP_NETWORK, _T("NET_STRING_IP_NETWORK") },

    { NET_STRING_ANY_ADDRESS, _T("NET_STRING_ANY_ADDRESS") },
    { NET_STRING_ANY_ADDRESS_NO_SCOPE, _T("NET_STRING_ANY_ADDRESS_NO_SCOPE") },
    { NET_STRING_ANY_SERVICE, _T("NET_STRING_ANY_SERVICE") },
    { NET_STRING_ANY_SERVICE_NO_SCOPE, _T("NET_STRING_ANY_SERVICE_NO_SCOPE") },
};

static LPCTSTR szCue = _T("Enter the address here then validate");

// CNetAddressCtrlPage dialog

IMPLEMENT_DYNAMIC(CNetAddressCtrlPage, CPropertyPage)

CNetAddressCtrlPage::CNetAddressCtrlPage()
: CPropertyPage(CNetAddressCtrlPage::IDD)
{
}

CNetAddressCtrlPage::~CNetAddressCtrlPage()
{
}

void CNetAddressCtrlPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_NETADDRESS, m_netaddrctrl);
    DDX_Control(pDX, IDC_LIST_NETSTRINGS, m_listbox);
}

BEGIN_MESSAGE_MAP(CNetAddressCtrlPage, CPropertyPage)
    ON_BN_CLICKED(IDC_BUTTON_VALIDATE, &CNetAddressCtrlPage::OnBnClickedButtonValidate)
    ON_EN_CHANGE(IDC_NETADDRESS, &CNetAddressCtrlPage::OnEnChangeNetaddress)
END_MESSAGE_MAP()

// CNetAddressCtrlPage message handlers

void CNetAddressCtrlPage::OnBnClickedButtonValidate()
{
    // Get selected Address Types
    int nCount = m_listbox.GetSelCount();
    int *selectedItems = new int[nCount];
    m_listbox.GetSelItems(nCount, selectedItems);

    // Prepare the mask
    DWORD dwAddrMask = 0;
    for (int i = 0; i < nCount; i++)
        dwAddrMask |= netStrings[selectedItems[i]].dwNetString;

    delete[] selectedItems;

    NET_ADDRESS_INFO nfo;
    NC_ADDRESS addr;
    addr.pAddrInfo = &nfo;

    // Validate
    m_netaddrctrl.SetAllowType(dwAddrMask);
    HRESULT hr = m_netaddrctrl.GetAddress(&addr);

    if (hr == S_OK)
        ::MessageBox(m_hWnd, _T("Succeeded!"), _T("Validation"), 0);
    else
        m_netaddrctrl.DisplayErrorTip();
}

BOOL CNetAddressCtrlPage::OnInitDialog()
{
    CPropertyPage::OnInitDialog();

    // Display the cue
    m_netaddrctrl.SetCueBanner(szCue, TRUE);

    // Fill in all the NET_STRINGs
    for (int i = 0; i < _countof(netStrings); i++)
        m_listbox.AddString(netStrings[i].lpszDisplay);

    return TRUE;
}

void CNetAddressCtrlPage::OnEnChangeNetaddress()
{
    CString text;
    int len = m_netaddrctrl.LineLength(0);
    m_netaddrctrl.GetLine(0, text.GetBuffer(len), len);
    text.ReleaseBuffer(len);

    // Display the cue if the input is empty
    if (text.GetLength() == 0)
        m_netaddrctrl.SetCueBanner(szCue, TRUE);
}
