#pragma once
#include "afxwin.h"
// CPagerCtrlPage dialog

class CPagerCtrlPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CPagerCtrlPage)

public:
	CPagerCtrlPage();
	virtual ~CPagerCtrlPage();

// Dialog Data
	enum { IDD = IDD_PAGER_CONTROL };
public:
	virtual BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnCbnSelchangeBackColor();
	afx_msg void OnBnClickedSetButtonSize();
	afx_msg void CPagerCtrlPage::OnCalcSize(NMHDR * pNotifyStruct, LRESULT * result);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

private:
	CPagerCtrl m_pagerctrl;
	CToolBar m_toolbar;
	CComboBox m_comboColor;
	CSliderCtrl m_sliderBorderSize;
	CStatic m_staticBorderSize;
	int m_nSize;
};
