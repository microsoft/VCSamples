// PropDlg.h : Declaration of the CPropDlg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __PROPDLG_H_
#define __PROPDLG_H_

#include "resource.h"       // main symbols
#include "commctrl.h"
#include "firewnd.h"

class CFireWnd;
/////////////////////////////////////////////////////////////////////////////
// CPropDlg
class CPropDlg :
	public CDialogImpl<CPropDlg>
{

public:


	CPropDlg(CFireWnd* p);
	~CPropDlg();

	enum { IDD = IDD_PROPDLG };

BEGIN_MSG_MAP(CPropDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_EDIT1, EN_CHANGE, OnPropertyChanged)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	COMMAND_ID_HANDLER(IDC_APPLY, OnApply)
	NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnSelChanged)
	NOTIFY_CODE_HANDLER(TVN_SELCHANGING, OnSelChanging)
END_MSG_MAP()

// Message/Notification handlers
	LRESULT OnSelChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnSelChanging(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnPropertyChanged(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnApply(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

	void Apply();
	HWND m_hTreeViewCtl;
	HWND m_hSettingCtl;
	HWND m_hSetting;
	long m_nDecay;
	long m_nFlammability;
	long m_nMaxHeat;
	long m_nSpreadRate;
	long m_nSize;
	long m_nSmoothness;
	long m_nDistribution;
	long m_nChaos;

	int m_nCurSel;

	CFireWnd* m_Display;
};

#endif //__PROPDLG_H_
