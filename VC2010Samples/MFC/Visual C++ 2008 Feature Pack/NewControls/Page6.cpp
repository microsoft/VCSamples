// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "NewControls.h"
#include "Page6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SHCNF_ACCEPT_INTERRUPTS 0x0001
#define SHCNF_ACCEPT_NON_INTERRUPTS 0x0002

UINT UWM_CHANGE_SYSTEM_ICON = ::RegisterWindowMessage(_T("UWM_CHANGE_SYSTEM_ICON"));

/////////////////////////////////////////////////////////////////////////////
// CPage6 property page

IMPLEMENT_DYNCREATE(CPage6, CMFCPropertyPage)

CPage6::CPage6() : CMFCPropertyPage(CPage6::IDD)
{
	m_strSelectedFolder = _T("c:\\");
	m_ulChangeIconNotifyID = 0;
}

CPage6::~CPage6()
{
}

void CPage6::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndShellList);
	DDX_Control(pDX, IDC_TREE1, m_wbdShellTree);
	DDX_Text(pDX, IDC_SELECTED_FOLDER, m_strSelectedFolder);
}

BEGIN_MESSAGE_MAP(CPage6, CMFCPropertyPage)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SELECT_FOLDER, OnSelectFolder)
	ON_REGISTERED_MESSAGE(UWM_CHANGE_SYSTEM_ICON, OnChangeSystemIcon)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage6 message handlers

void CPage6::OnSelectFolder()
{
	if (theApp.GetShellManager()->BrowseForFolder(m_strSelectedFolder, this, m_strSelectedFolder))
	{
		UpdateData(FALSE);
	}
}

BOOL CPage6::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	m_wbdShellTree.Expand(m_wbdShellTree.GetRootItem(), TVE_EXPAND);
	m_wbdShellTree.SetRelatedList(&m_wndShellList);

	LPITEMIDLIST ppidl;
	if (SHGetSpecialFolderLocation(GetSafeHwnd(),CSIDL_BITBUCKET, &ppidl) != NOERROR)
	{
		return 0;
	}

	SHChangeNotifyEntry scnIDL;
	scnIDL.pidl = ppidl;
	scnIDL.fRecursive = TRUE;

	m_ulChangeIconNotifyID = SHChangeNotifyRegister(m_hWnd, SHCNF_ACCEPT_INTERRUPTS | SHCNF_ACCEPT_NON_INTERRUPTS, SHCNE_ALLEVENTS,  UWM_CHANGE_SYSTEM_ICON, 1, &scnIDL);

	return TRUE;  // return TRUE unless you set the focus to a control
}

LRESULT CPage6::OnChangeSystemIcon(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);
	if ((lParam == SHCNE_CREATE) || (lParam == SHCNE_DELETE))
	{
		if (m_wndShellList.IsDesktop())
		{
			int nSortColumn = m_wndShellList.GetHeaderCtrl().GetSortColumn();
			int nSortState = m_wndShellList.GetHeaderCtrl().GetColumnState(nSortColumn);
			m_wndShellList.Refresh();
			m_wbdShellTree.Refresh();
			m_wndShellList.Sort(nSortColumn, nSortState == 1 ? TRUE : FALSE);
		}
	}
	return TRUE;
}

void CPage6::OnDestroy()
{
	if (m_ulChangeIconNotifyID != 0)
	{
		SHChangeNotifyDeregister(m_ulChangeIconNotifyID);
	}
	CMFCPropertyPage::OnDestroy();
}
