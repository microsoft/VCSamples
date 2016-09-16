#pragma once
#include "afxcmn.h"
#include "afxwin.h"

// CNetAddressCtrlPage dialog
class CNetAddressCtrlPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CNetAddressCtrlPage)

public:
	CNetAddressCtrlPage();
	virtual ~CNetAddressCtrlPage();

// Dialog Data
	enum { IDD = IDD_NETWORK_ADDRESS_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButtonValidate();
    afx_msg void OnEnChangeNetaddress();
    virtual BOOL OnInitDialog();

private:
    CNetAddressCtrl m_netaddrctrl;
    CListBox m_listbox;
};
