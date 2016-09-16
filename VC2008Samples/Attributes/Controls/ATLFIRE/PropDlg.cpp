// PropDlg.cpp : Implementation of CPropDlg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "PropDlg.h"
#include <commctrl.h>
#include <stdlib.h>
#include "firewnd.h"

/////////////////////////////////////////////////////////////////////////////
// CPropDlg

CPropDlg::CPropDlg(CFireWnd* p):
	m_Display(p),
	m_hSetting(0),
	m_hSettingCtl(0),
	m_hTreeViewCtl(0),
	m_nChaos(0),
	m_nDecay(0),
	m_nDistribution(0),
	m_nMaxHeat(0),
	m_nSmoothness(0),
	m_nSpreadRate(0)
{
}

CPropDlg::~CPropDlg()
{
}

LRESULT CPropDlg::OnSelChanging(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	ATLTRACE(_T("CPropDlg::OnSelChanging()\n"));
	Apply();
	return 0;
}

LRESULT CPropDlg::OnPropertyChanged(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	ATLTRACE(_T("CPropDlg::OnPropertyChanged()\n"));
	const int getLen = 127;
	_TCHAR buf[128] = _T("");
	_TCHAR *bufend;

	int nVal = 0;
	switch(m_nCurSel)
	{
	case 0: // Fire
		break;
	case 1: // Decay
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nDecay )
		{
			m_nDecay = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 2: // Flammability
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nFlammability )
		{
			m_nFlammability = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 3: // Maximum Heat
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nMaxHeat )
		{
			m_nMaxHeat = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 4: // Spread Rate
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nSpreadRate )
		{
			m_nSpreadRate = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 5: // Size
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nSize )
		{
			m_nSize = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 6: // Smoothness
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nSmoothness )
		{
			m_nSmoothness = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 7: // Distribution
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nDistribution )
		{
			m_nDistribution = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	case 8: // Chaos
		GetDlgItemText(IDC_EDIT1, buf, getLen);
		nVal = _tcstol(buf,&bufend,10);
		if( nVal != m_nChaos )
		{
			m_nChaos = nVal;
			::EnableWindow(GetDlgItem(IDC_APPLY),TRUE);
		}
		break;
	}
	return 0;
}

LRESULT CPropDlg::OnSelChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
	ATLTRACE(_T("CPropDlg::OnSelChanged()\n"));
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pnmh;
	TCHAR buf[128] = _T("");
	::EnableWindow(GetDlgItem(IDC_APPLY), FALSE);

	m_nCurSel = (int)pNMTreeView->itemNew.lParam;

	switch(m_nCurSel)
	{
	case 0: // Fire
		SetDlgItemText(IDC_EDIT1,_T(""));
		::EnableWindow(m_hSetting,FALSE);
		::EnableWindow(m_hSettingCtl,FALSE);
		break;
	case 1: // Decay
		_itot_s(m_nDecay,buf,128, 10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(1,100));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 2: // Flammability
		_itot_s(m_nFlammability,buf,128, 10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(1,399));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 3: // Maximum Heat
		_itot_s(m_nMaxHeat,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(0,223));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 4: // Spread Rate
		_itot_s(m_nSpreadRate,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(1,100));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 5: // Size
		_itot_s(m_nSize,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(1,m_Display->bmSize.cx - 1));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 6: // Smoothness
		_itot_s(m_nSmoothness,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(0,5));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 7: // Distribution
		_itot_s(m_nDistribution,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(0,10));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	case 8: // Chaos
		_itot_s(m_nChaos,buf,128,10);
		SetDlgItemText(IDC_EDIT1,buf);
		::SendMessage(m_hSettingCtl,UDM_SETRANGE, 0, MAKELONG(1,100));
		::EnableWindow(m_hSettingCtl,TRUE);
		::EnableWindow(m_hSetting,TRUE);
		break;
	}

	return 0;
}

LRESULT CPropDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	m_nDecay        = m_Display->m_nDecay;
	m_nFlammability = m_Display->m_nFlammability;
	m_nMaxHeat      = m_Display->m_nMaxHeat;
	m_nSpreadRate   = m_Display->m_nSpreadRate;
	m_nSize         = m_Display->m_nSize;
	m_nSmoothness   = m_Display->m_nSmoothness;
	m_nDistribution = m_Display->m_nDistribution;
	m_nChaos        = m_Display->m_nChaos;

	m_hTreeViewCtl = GetDlgItem(IDC_TREE1);
	m_hSettingCtl = GetDlgItem(IDC_SPIN1);
	m_hSetting = GetDlgItem(IDC_EDIT1);

	TV_INSERTSTRUCT TreeCtrlItem;

	TreeCtrlItem.hParent = TVI_ROOT;
	TreeCtrlItem.hInsertAfter = TVI_LAST;
	TreeCtrlItem.item.mask = TVIF_TEXT | TVIF_PARAM;
	TreeCtrlItem.item.pszText = _T("Fire");
	TreeCtrlItem.item.lParam = 0;
	HTREEITEM hTreeItem1 = TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);


	TreeCtrlItem.hParent = hTreeItem1;
	TreeCtrlItem.item.pszText = _T("Decay");
	TreeCtrlItem.item.lParam = 1;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Flammability");
	TreeCtrlItem.item.lParam = 2;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Maximum Heat");
	TreeCtrlItem.item.lParam = 3;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Spread Rate");
	TreeCtrlItem.item.lParam = 4;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Size");
	TreeCtrlItem.item.lParam = 5;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.hParent = TVI_ROOT;
	TreeCtrlItem.item.pszText = _T("Render");
	TreeCtrlItem.item.lParam = 0;
	HTREEITEM hTreeItem2 = TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.hParent = hTreeItem2;
	TreeCtrlItem.item.pszText = _T("Smoothness");
	TreeCtrlItem.item.lParam = 6;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Distribution");
	TreeCtrlItem.item.lParam = 7;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeCtrlItem.item.pszText = _T("Chaos");
	TreeCtrlItem.item.lParam = 8;
	TreeView_InsertItem(m_hTreeViewCtl, &TreeCtrlItem);

	TreeView_Expand(m_hTreeViewCtl, hTreeItem1,TVE_EXPAND);
	TreeView_Expand(m_hTreeViewCtl, hTreeItem2,TVE_EXPAND);

	return 1;  // Let the system set the focus
}

LRESULT CPropDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	Apply();
	EndDialog(wID);
	return 0;
}

LRESULT CPropDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	EndDialog(wID);
	return 0;
}

LRESULT CPropDlg::OnApply(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	Apply();
	return 0;
}

void CPropDlg::Apply()
{
	m_Display->m_nDecay         = m_nDecay;
	m_Display->m_nFlammability  = m_nFlammability;
	m_Display->m_nMaxHeat       = m_nMaxHeat;
	m_Display->m_nSpreadRate    = m_nSpreadRate;
	m_Display->m_nSize          = m_nSize;
	m_Display->m_nSmoothness    = m_nSmoothness;
	m_Display->m_nDistribution  = m_nDistribution;
	m_Display->m_nChaos         = m_nChaos;

	::EnableWindow(GetDlgItem(IDC_APPLY), FALSE);
}
