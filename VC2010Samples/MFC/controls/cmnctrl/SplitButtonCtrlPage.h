#pragma once

#include "commctrl.h"
#include "afxwin.h"

// CSplitButton dialog

class CSplitButtonCtrlPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSplitButtonCtrlPage)

public:
	CSplitButtonCtrlPage();
	virtual ~CSplitButtonCtrlPage();

// Dialog Data
	enum { IDD = IDD_SPLIT_BUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

public:
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedSetMenu1();
	afx_msg void OnBnClickedSetMenu2();
	afx_msg void OnBnClickedSetSize();
	afx_msg void OnLbnSelchangeListStyle();
	afx_msg void OnBnClickedSplitButton();
	afx_msg void OnBnClickedCheckState();

private:
	CSplitButton m_splitButton;
	CListBox m_listSplitStyle;
	CImageList m_image;
	CButton m_checkState;
	UINT m_xSize;
	UINT m_ySize;
};
