// NetAddrVerifierDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CNetAddrVerifierDlg dialog
class CNetAddrVerifierDlg : public CDialog
{
// Construction
public:
	CNetAddrVerifierDlg(CWnd* pParent = NULL);	// standard constructor
	~CNetAddrVerifierDlg();
	
	enum AddressKind
	{
		NoKind,
		AllKinds,
		IPv4,
		IPv6,
		Named
	};

	std::wstring Ipv4AddrToString(IN_ADDR &addr);
	std::wstring Ipv6AddrToString(IN6_ADDR &addr);
	DWORD ConstructAddrMask(AddressKind kind);
	BOOL Verify(AddressKind kind);
	AddressKind Revalidate();
	void Enum();
// Dialog Data
	enum { IDD = IDD_NETADDRVERIFIER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_fVista;
	CString m_strParsedAddr;


	afx_msg void OnBnClickedButton1();
	afx_msg void OnVerifyAll();
	afx_msg void OnVerifyIPv4();
	afx_msg void OnVerifyIPv6();
	afx_msg void OnVerifyNamed();

	CListCtrl m_listCtrl;

	//Vista
	CNetAddressCtrl* m_pNetAddr;
	CSplitButton* m_pValidateBtn;

	//XP
	CEdit* m_pEdit;
	CButton* m_pButton;
};
