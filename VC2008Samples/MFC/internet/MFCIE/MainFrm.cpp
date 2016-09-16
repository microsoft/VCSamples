// This is part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "mfcie.h"
#include <wininet.h>

#include "MainFrm.h"
#include "mfcieDoc.h"
#include "mfcieVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_CBN_SELENDOK(AFX_IDW_TOOLBAR + 1,OnNewAddress)
	ON_COMMAND_RANGE(0xe00, 0xfff, OnFavorite)
	ON_COMMAND(IDOK, OnNewAddressEnter)
	ON_NOTIFY(TBN_DROPDOWN, AFX_IDW_TOOLBAR, OnDropDown)
	ON_COMMAND(ID_FAVORITES_DROPDOWN, DoNothing)
	ON_COMMAND(ID_FONT_DROPDOWN, DoNothing)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CImageList img;
	CString str;

	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndReBar.Create(this))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndToolBar.CreateEx(this))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// set up toolbar properties
	m_wndToolBar.GetToolBarCtrl().SetButtonWidth(50, 150);
	m_wndToolBar.GetToolBarCtrl().SetExtendedStyle(TBSTYLE_EX_DRAWDDARROWS);

	img.Create(IDB_HOTTOOLBAR, 22, 0, RGB(255, 0, 255));
	m_wndToolBar.GetToolBarCtrl().SetHotImageList(&img);
	img.Detach();
	img.Create(IDB_COLDTOOLBAR, 22, 0, RGB(255, 0, 255));
	m_wndToolBar.GetToolBarCtrl().SetImageList(&img);
	img.Detach();
	m_wndToolBar.ModifyStyle(0, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT);
	m_wndToolBar.SetButtons(NULL, 9);

	// set up each toolbar button
	m_wndToolBar.SetButtonInfo(0, ID_GO_BACK, TBSTYLE_BUTTON, 0);
	str.LoadString(IDS_BACK);
	m_wndToolBar.SetButtonText(0, str);
	m_wndToolBar.SetButtonInfo(1, ID_GO_FORWARD, TBSTYLE_BUTTON, 1);
	str.LoadString(IDS_FORWARD);
	m_wndToolBar.SetButtonText(1, str);
	m_wndToolBar.SetButtonInfo(2, ID_VIEW_STOP, TBSTYLE_BUTTON, 2);
	str.LoadString(IDS_STOP);
	m_wndToolBar.SetButtonText(2, str);
	m_wndToolBar.SetButtonInfo(3, ID_VIEW_REFRESH, TBSTYLE_BUTTON, 3);
	str.LoadString(IDS_REFRESH);
	m_wndToolBar.SetButtonText(3, str);
	m_wndToolBar.SetButtonInfo(4, ID_GO_START_PAGE, TBSTYLE_BUTTON, 4);
	str.LoadString(IDS_HOME);
	m_wndToolBar.SetButtonText(4, str);
	m_wndToolBar.SetButtonInfo(5, ID_GO_SEARCH_THE_WEB, TBSTYLE_BUTTON, 5);
	str.LoadString(IDS_SEARCH);
	m_wndToolBar.SetButtonText(5, str);
	m_wndToolBar.SetButtonInfo(6, ID_FAVORITES_DROPDOWN, TBSTYLE_BUTTON | TBSTYLE_DROPDOWN, 6);
	str.LoadString(IDS_FAVORITES);
	m_wndToolBar.SetButtonText(6, str);
	m_wndToolBar.SetButtonInfo(7, ID_FILE_PRINT, TBSTYLE_BUTTON, 7);
	str.LoadString(IDS_PRINT);
	m_wndToolBar.SetButtonText(7, str);
	m_wndToolBar.SetButtonInfo(8, ID_FONT_DROPDOWN, TBSTYLE_BUTTON | TBSTYLE_DROPDOWN, 8);
	str.LoadString(IDS_FONT);
	m_wndToolBar.SetButtonText(8, str);

	CRect rectToolBar;

	// set up toolbar button sizes
	m_wndToolBar.GetItemRect(0, &rectToolBar);
	m_wndToolBar.SetSizes(rectToolBar.Size(), CSize(30,20));

	// create a combo box for the address bar
	if (!m_wndAddress.Create(CBS_DROPDOWN | WS_CHILD, CRect(0, 0, 200, 120), this, AFX_IDW_TOOLBAR + 1))
	{
		TRACE0("Failed to create combobox\n");
		return -1;      // fail to create
	}

	// create the animation control
	m_wndAnimate.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 10, 10), this, AFX_IDW_TOOLBAR + 2);
	m_wndAnimate.Open(IDR_MFCAVI);

	// add the toolbar, animation, and address bar to the rebar
	m_wndReBar.AddBar(&m_wndToolBar,NULL, NULL, RBBS_GRIPPERALWAYS|RBBS_FIXEDBMP|RBBS_USECHEVRON);
	m_wndReBar.AddBar(&m_wndAnimate, NULL, NULL, RBBS_FIXEDSIZE | RBBS_FIXEDBMP);
	str.LoadString(IDS_ADDRESS);
	m_wndReBar.AddBar(&m_wndAddress, str, NULL, RBBS_FIXEDBMP | RBBS_BREAK);

	// set up min/max sizes and ideal sizes for pieces of the rebar
	REBARBANDINFO rbbi;

	rbbi.cbSize = sizeof(rbbi);
	rbbi.fMask = RBBIM_CHILDSIZE | RBBIM_IDEALSIZE | RBBIM_SIZE;
	rbbi.cxMinChild = rectToolBar.Width();
	rbbi.cyMinChild = rectToolBar.Height();
	rbbi.cx = rbbi.cxIdeal = rectToolBar.Width() * 9;
	m_wndReBar.GetReBarCtrl().SetBandInfo(0, &rbbi);
	rbbi.cxMinChild = 0;

	CRect rectAddress;

	rbbi.fMask = RBBIM_CHILDSIZE | RBBIM_IDEALSIZE;
	m_wndAddress.GetEditCtrl()->GetWindowRect(&rectAddress);
	rbbi.cyMinChild = rectAddress.Height() + 10;
	rbbi.cxIdeal = 200;
	m_wndReBar.GetReBarCtrl().SetBandInfo(2, &rbbi);

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_FIXED);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

// set up Favorites menu
	TCHAR           sz[MAX_PATH];
	TCHAR           szPath[MAX_PATH];
	HKEY            hKey;
	DWORD           dwSize;
	CMenu*          pMenu;
	LONG		lRet;

	// first get rid of bogus submenu items.
	pMenu = GetMenu()->GetSubMenu(3);
	while(pMenu->DeleteMenu(0, MF_BYPOSITION));

	// find out from the registry where the favorites are located.
	if(RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\User Shell Folders"), 0, KEY_QUERY_VALUE, &hKey) != ERROR_SUCCESS)
	{
		TRACE0("Favorites folder not found\n");
		return 0;
	}

	// Guarantee NULL-termination
	sz[sizeof(sz)-1] = '\0';
	dwSize = sizeof(sz);
	lRet = RegQueryValueEx(hKey, _T("Favorites"), NULL, NULL, (LPBYTE)sz, &dwSize);
	RegCloseKey(hKey);
	if (lRet != ERROR_SUCCESS || sz[sizeof(sz)-1] != '\0')
	{
		TRACE0("Favorites folder not found\n");
		return 0;
	}

	ExpandEnvironmentStrings(sz, szPath, sizeof(szPath));
	BuildFavoritesMenu(szPath, 0, pMenu);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = AfxRegisterWndClass(0);
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

int CMainFrame::BuildFavoritesMenu(LPCTSTR pszPath, int nStartPos, CMenu* pMenu)
{
	CString         strPath(pszPath);
	CString         strPath2;
	CString         str;
	WIN32_FIND_DATA wfd;
	HANDLE          h;
	int             nPos = 0;
	int             nEndPos = 0;
	int             nNewEndPos = 0;
	int             nLastDir = 0;
	TCHAR           buf[INTERNET_MAX_PATH_LENGTH];
	CStringArray    astrFavorites;
	CStringArray    astrDirs;
	CMenu*          pSubMenu;

	// make sure there's a trailing backslash
	if(strPath[strPath.GetLength() - 1] != _T('\\'))
		strPath += _T('\\');
	strPath2 = strPath;
	strPath += "*.*";

	// now scan the directory, first for .URL files and then for subdirectories
	// that may also contain .URL files
	h = FindFirstFile(strPath, &wfd);
	if(h != INVALID_HANDLE_VALUE)
	{
		nEndPos = nStartPos;
		do
		{
			if((wfd.dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY|FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM))==0)
			{
				str = wfd.cFileName;
				if(str.Right(4) == _T(".url"))
				{
					// an .URL file is formatted just like an .INI file, so we can
					// use GetPrivateProfileString() to get the information we want
					DWORD dwSize;
					dwSize = ::GetPrivateProfileString(_T("InternetShortcut"), _T("URL"),
									   _T(""), buf, INTERNET_MAX_PATH_LENGTH,
									   strPath2 + str);
					if (dwSize < INTERNET_MAX_PATH_LENGTH &&
					    buf[dwSize] == '\0')
					{
						str = str.Left(str.GetLength() - 4);

						// scan through the array and perform an insertion sort
						// to make sure the menu ends up in alphabetic order
						for(nPos = nStartPos ; nPos < nEndPos ; ++nPos)
						{
							if(str.CompareNoCase(astrFavorites[nPos]) < 0)
								break;
						}
						astrFavorites.InsertAt(nPos, str);
						m_astrFavoriteURLs.InsertAt(nPos, buf);
						++nEndPos;
					}
				}
			}
		} while(FindNextFile(h, &wfd));
		FindClose(h);
		// Now add these items to the menu
		for(nPos = nStartPos ; nPos < nEndPos ; ++nPos)
		{
			pMenu->AppendMenu(MF_STRING | MF_ENABLED, 0xe00 + nPos, astrFavorites[nPos]);
		}


		// now that we've got all the .URL files, check the subdirectories for more
		nLastDir = 0;
		h = FindFirstFile(strPath, &wfd);
		ASSERT(h != INVALID_HANDLE_VALUE);
		do
		{
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// ignore the current and parent directory entries
				if(lstrcmp(wfd.cFileName, _T(".")) == 0 || lstrcmp(wfd.cFileName, _T("..")) == 0)
					continue;

				for(nPos = 0 ; nPos < nLastDir ; ++nPos)
				{
					if(astrDirs[nPos].CompareNoCase(wfd.cFileName) > 0)
						break;
				}
				pSubMenu = new CMenu;
				pSubMenu->CreatePopupMenu();

				// call this function recursively.
				nNewEndPos = BuildFavoritesMenu(strPath2 + wfd.cFileName, nEndPos, pSubMenu);
				if(nNewEndPos != nEndPos)
				{
					// only intert a submenu if there are in fact .URL files in the subdirectory
					nEndPos = nNewEndPos;
					pMenu->InsertMenu(nPos, MF_BYPOSITION | MF_POPUP | MF_STRING, (UINT_PTR)pSubMenu->m_hMenu, wfd.cFileName);
					pSubMenu->Detach();
					astrDirs.InsertAt(nPos, wfd.cFileName);
					++nLastDir;
				}
				delete pSubMenu;
			}
		} while(FindNextFile(h, &wfd));
		FindClose(h);
	}
	return nEndPos;
}

void CMainFrame::OnFavorite(UINT nID)
{
	((CMfcieView*)GetActiveView())->Navigate2(m_astrFavoriteURLs[nID-0xe00], 0, NULL);
}

void CMainFrame::SetAddress(LPCTSTR lpszUrl)
{
	// This is called when the browser has completely loaded the new location,
	// so make sure the text in the address bar is up to date and stop the
	// animation.
	m_wndAddress.SetWindowText(lpszUrl);
	m_wndAnimate.Stop();
	m_wndAnimate.Seek(0);
}

void CMainFrame::StartAnimation()
{
	// Start the animation.  This is called when the browser begins to
	// navigate to a new location
#pragma warning(disable : 4245)
	m_wndAnimate.Play(0, -1, -1);
#pragma warning(default : 4245)
}

void CMainFrame::OnNewAddress()
{
	// gets called when an item in the Address combo box is selected
	// just navigate to the newly selected location.
	CString str;

	m_wndAddress.GetLBText(m_wndAddress.GetCurSel(), str);
	((CMfcieView*)GetActiveView())->Navigate2(str, 0, NULL);
}

void CMainFrame::OnNewAddressEnter()
{
	// gets called when an item is entered manually into the edit box portion
	// of the Address combo box.
	// navigate to the newly selected location and also add this address to the
	// list of addresses in the combo box.
	CString str;

	m_wndAddress.GetEditCtrl()->GetWindowText(str);
	((CMfcieView*)GetActiveView())->Navigate2(str, 0, NULL);

	COMBOBOXEXITEM item;

	item.mask = CBEIF_TEXT;
	item.iItem = -1;
	item.pszText = (LPTSTR)(LPCTSTR)str;
	m_wndAddress.InsertItem(&item);
}

void CMainFrame::DoNothing()
{
	// this is here only so that the toolbar buttons for the dropdown menus
	// will have a callback, and thus will not be disabled.
}

void CMainFrame::OnDropDown(NMHDR* pNotifyStruct, LRESULT* pResult)
{
	// this function handles the dropdown menus from the toolbar
	NMTOOLBAR* pNMToolBar = (NMTOOLBAR*)pNotifyStruct;
	CRect rect;

	// translate the current toolbar item rectangle into screen coordinates
	// so that we'll know where to pop up the menu
	m_wndToolBar.GetToolBarCtrl().GetRect(pNMToolBar->iItem, &rect);
	rect.top = rect.bottom;
	::ClientToScreen(pNMToolBar->hdr.hwndFrom, &rect.TopLeft());
	if(pNMToolBar->iItem == ID_FONT_DROPDOWN)
	{
		CMenu menu;
		CMenu* pPopup;

		// the font popup is stored in a resource
		menu.LoadMenu(IDR_FONT_POPUP);
		pPopup = menu.GetSubMenu(0);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, rect.left, rect.top + 1, AfxGetMainWnd());
	}
	else if(pNMToolBar->iItem == ID_FAVORITES_DROPDOWN)
	{
		CMenu* pPopup;

		// for the favorties popup, just steal the menu from the main window
		pPopup = GetMenu()->GetSubMenu(3);
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, rect.left, rect.top + 1, AfxGetMainWnd());
	}
	*pResult = TBDDRET_DEFAULT;
}
