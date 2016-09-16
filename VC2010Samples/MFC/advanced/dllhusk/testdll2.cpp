// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#include "resource.h"       // main symbols
#include "testres2.h"       // symbols unique to this DLL

#include "testdll2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Initialization of MFC Extension DLL

#include "afxdllx.h"    // standard MFC Extension DLL routines

static AFX_EXTENSION_MODULE NEAR extensionDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		// Extension DLL one-time initialization - do not allocate memory here,
		//   use the TRACE or ASSERT macros or call MessageBox
		if (!AfxInitExtensionModule(extensionDLL, hInstance))
			return 0;

		// Other initialization could be done here, as long as
		// it doesn't result in direct or indirect calls to AfxGetApp.
		// This extension DLL doesn't need to access the app object
		// but to be consistent with testdll1.dll, this DLL requires
		// explicit initialization as well (see below).

		// This allows for greater flexibility later in development.
	}
	return 1;   // ok
}

// Exported DLL initialization is run in context of running application
extern "C" void WINAPI InitTestDLL2()
{
	// create a new CDynLinkLibrary for this app
	#pragma warning(push)
	#pragma warning(disable:6014) //silence prefast warning because CDynLinkLibrary is cleaned up elsewhere
	new CDynLinkLibrary(extensionDLL);
	#pragma warning(pop)
	// nothing more to do
}

/////////////////////////////////////////////////////////////////////////////
// class CListOutputFrame

IMPLEMENT_DYNAMIC(CListOutputFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CListOutputFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CListOutputFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CListOutputFrame::CListOutputFrame()
{
	m_ppThis = NULL;        // backpointer
	// do nothing now (two-phase create)
}

CListOutputFrame::~CListOutputFrame()
{
	// clear backpointer
	if (m_ppThis != NULL)
	{
		ASSERT(*m_ppThis == this);
		*m_ppThis = NULL;
	}
}

BOOL CListOutputFrame::Create(LPCTSTR lpszWindowName,
	DWORD dwStyle, const RECT& rect, CMDIFrameWnd* pParentWnd)
{
	// we want to load a specific menu from this DLL
	HINSTANCE hInstOld = AfxGetResourceHandle();
	AfxSetResourceHandle(extensionDLL.hModule);
	if (!m_menu.LoadMenu(IDR_LISTOUTPUT))
	{
		// restore the old resource chain and return error
		AfxSetResourceHandle(hInstOld);
		return FALSE;
	}
	AfxSetResourceHandle(hInstOld); // restore the old resource chain

	// when the list output frame window is active, use this menu
	m_hMenuShared = m_menu.m_hMenu;

	// create the CMDIChildWnd, listbox created in OnCreate
	return CMDIChildWnd::Create(NULL, lpszWindowName,
		dwStyle, rect, pParentWnd);
}


int CListOutputFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create dialog bar at top of the frame window (it is a toolbar)
	if (!m_dlgBar.Create(this, IDD_DIALOGBAR1, WS_CHILD|CBRS_TOP,
			AFX_IDW_TOOLBAR))
	{
		TRACE(_T("Failed to create toolbar for CListOutputFrame\n"));
		return -1;
	}

	// create listbox as main pane (will fill rest of frame window)
	if (!m_listBox.Create(WS_CHILD | WS_VISIBLE|
		LBS_NOTIFY | LBS_NOINTEGRALHEIGHT |
		WS_VSCROLL | LBS_DISABLENOSCROLL | WS_BORDER,
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST))
	{
		TRACE(_T("Failed to create listbox for CListOutputFrame\n"));
		return -1;
	}
	m_listBox.SetFont(m_dlgBar.GetFont());
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME);
	m_listBox.ModifyStyle(0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME);

	return 0; // creation ok
}

void CListOutputFrame::Clear()
{
	ASSERT(m_listBox.m_hWnd != NULL);       // must be created
	m_listBox.ResetContent();
}

void CListOutputFrame::AddString(LPCTSTR lpszItem)
{
	ASSERT(m_listBox.m_hWnd != NULL);       // must be created
	int nIndex;
	if ((nIndex = m_listBox.AddString(lpszItem)) < 0)
		AfxThrowMemoryException();
	m_listBox.SetCurSel(nIndex);    // make last line visible
}

/////////////////////////////////////////////////////////////////////////////
// Edit commands

void CListOutputFrame::OnEditClear()
{
	Clear();
}

void CListOutputFrame::OnEditCut()
{
	OnEditCopy();
	Clear();
}

void CListOutputFrame::OnEditCopy()
{
	if (!OpenClipboard())
	{
		AfxMessageBox(_T("Failed to open clipboard"));
		return;
	}
	if (!::EmptyClipboard())
	{
		AfxMessageBox(_T("Failed to empty clipboard"));
		::CloseClipboard();
		return;
	}

	// copy the current listbox contents to the clipboard as text
	HGLOBAL hTextData = GetTextData();
	if (hTextData == NULL ||
#ifndef _UNICODE
		::SetClipboardData(CF_TEXT, hTextData) == NULL)
#else
		::SetClipboardData(CF_UNICODETEXT, hTextData) == NULL)
#endif
	{
		AfxMessageBox(_T("Failed to set clipboard data"));
		::CloseClipboard();
		return;
	}
	if (!::CloseClipboard())
		AfxMessageBox(_T("Failed to close clipboard"));
}

HGLOBAL CListOutputFrame::GetTextData()
{
	// first find out how much space we need
	int nLines = m_listBox.GetCount();
	long cbTotal = 0;
	int i;
	for (i = 0; i < nLines; i++)
		cbTotal += m_listBox.GetTextLen(i) + 2;     // CR/LF for each line
	cbTotal += 1;   // for end '\0'

	// allocate a (shared) global memory block for the data
	HGLOBAL hData = ::GlobalAlloc(GMEM_DDESHARE, cbTotal*sizeof(TCHAR));
	if (hData == NULL)
		return NULL;        // NULL for memory failure

	// now copy the strings, terminate each with CR/LF
	LPTSTR lpOut = (LPTSTR)::GlobalLock(hData);
	ENSURE(lpOut != NULL);
	for (i = 0; i < nLines; i++)
	{
		m_listBox.GetText(i, lpOut);
		lpOut += lstrlen(lpOut)*sizeof(TCHAR);   // skip new string
		*lpOut++ = 0xD; // CR
		*lpOut++ = 0xA; // LF
	}
	*lpOut = '\0';
	ASSERT(lpOut + 1 == (LPCTSTR)GlobalLock(hData) + cbTotal);

	return hData;
}

/////////////////////////////////////////////////////////////////////////////
