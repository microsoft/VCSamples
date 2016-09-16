#pragma once
#include "afxwin.h"


// CCommandLinkCtrlPage dialog

class CCommandLinkCtrlPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CCommandLinkCtrlPage)

public:
	CCommandLinkCtrlPage();
	virtual ~CCommandLinkCtrlPage();

// Dialog Data
	enum { IDD = IDD_COMMAND_LINK_CONTROL };
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedSetButtonNote();
	afx_msg void OnBnClickedCheckElev();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CButton m_cmdbtn;
	CEdit m_editNote;
	CButton m_checkShowElev;
};