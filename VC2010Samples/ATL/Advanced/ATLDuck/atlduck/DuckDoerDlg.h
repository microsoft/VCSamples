// DuckDoerDlg.h : Declaration of the CDuckDoerDlg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __DUCKDOERDLG_H_
#define __DUCKDOERDLG_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDuckDoerDlg
class CDuckDoer;

class CDuckDoerDlg :
	public CDialogImpl<CDuckDoerDlg>
{
public:
	CDuckDoerDlg();
	~CDuckDoerDlg();

	enum { IDD = IDD_DUCKDOERDLG };

BEGIN_MSG_MAP(CDuckDoerDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_ID_HANDLER(IDOK, OnOK)
	COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	COMMAND_ID_HANDLER(IDC_QUACK, OnQuack)
	COMMAND_ID_HANDLER(IDC_FLAP, OnFlap)
	COMMAND_ID_HANDLER(IDC_WALK, OnWalk)
	COMMAND_ID_HANDLER(IDC_PADDLE, OnPaddle)
END_MSG_MAP()

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnWalk(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnQuack(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnPaddle(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnFlap(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

public:
	void SetOwner(CDuckDoer* pObject){m_pObject = pObject;}
	void RecalcListboxExtent(LPCTSTR lpszEntry, BOOL bAdded = TRUE);

protected:
	CDuckDoer*  m_pObject;
	int         m_xListboxExtentMax;

public:
};

#endif //__DUCKDOERDLG_H_
