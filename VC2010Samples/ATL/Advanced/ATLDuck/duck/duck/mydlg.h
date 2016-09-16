// mydlg.h: Declaration of CMyDlg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef INC_MAINDLG_H
#define INC_MAINDLG_H

#include "stdafx.h"
#include "duckint.h"
class CMyDlg : public CDialogImpl<CMyDlg>
{
	BEGIN_MSG_MAP(CMyDlg)
		COMMAND_HANDLER(IDC_CREATEDODUCK, BN_CLICKED, OnCreateDoDuck)
		COMMAND_HANDLER(IDC_DESTROYDODUCK, BN_CLICKED, OnDestroyDoDuck)
		COMMAND_HANDLER(IDC_ADVISE, BN_CLICKED, OnAdvise)
		COMMAND_HANDLER(IDC_UNADVISE, BN_CLICKED, OnUnadvise)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	END_MSG_MAP()

	enum {IDD = IDD_MAINDLG};

	CMyDlg();
	~CMyDlg();

protected:

	static BOOL m_bOleInitialized;
	DWORD m_dwCookie;
	IConnectionPoint*   m_pIDuckConnectionPoint; // IConnectionPoint interface pointer to IDuck interface
	CDuckInt*           m_pDuckInt;  //interface to be used by the connection point

	LRESULT OnCreateDoDuck(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);
	LRESULT OnDestroyDoDuck(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnAdvise(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);
	LRESULT OnUnadvise(WORD wNotifyCode, WORD wID, HWND hwndCtl, BOOL& bHandled);

//implementation
	void DoMyIToA(DWORD dwNumber, LPTSTR lpszResult);
};

#endif
