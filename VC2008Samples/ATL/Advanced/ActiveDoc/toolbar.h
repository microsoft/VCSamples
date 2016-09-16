// Toolbar.h : toolbar implementation
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include <commctrl.h>

// ID used for the separator
#define ID_SEP 0

#define BEGIN_TOOLBAR_MAP(x) public: \
	const static int* _GetToolbarEntries(int& nButtons) { \
	static const int _entries[] = {
#define TOOLBAR_BUTTON(x) x,
#define TOOLBAR_SEPARATOR() ID_SEP,
#define END_TOOLBAR_MAP() }; \
	nButtons = sizeof(_entries)/sizeof(int); \
	return _entries; }

template <class T>
class CToolbar
{
public:
	CToolbar()
//		: m_wndToolbar(TOOLBARCLASSNAME, (T*)this, 2)
	{
	}
	void SetupToolbar(IOleInPlaceUIWindow* pInPlaceUIWindow)
	{
		T* pT = static_cast<T*>(this);
		HRESULT			hr;
		HWND			hWnd;

		// Negotiate the border space for the toolbar
		if (pInPlaceUIWindow != NULL)
		{
			SetRectEmpty(&m_bw);
			pInPlaceUIWindow->SetBorderSpace(&m_bw);
		}

		// Get the frame HWND so that we can parent our toolbar correctly
		pT->m_spInPlaceFrame->GetWindow(&hWnd);

		SetRect(&m_bw, 0, 30, 0, 0);
		hr = pT->m_spInPlaceFrame->RequestBorderSpace(&m_bw);
		if (FAILED(hr))
			return;

		pT->m_spInPlaceFrame->SetBorderSpace(&m_bw);

		// Now we can create the toolbar
		CreateToolbar(hWnd);

		::SendMessage(m_wndToolbar.m_hWnd, TB_AUTOSIZE, 0, 0);
		::ShowWindow(m_wndToolbar.m_hWnd, SW_SHOW);
		// Set the window we want the toolbar to send it's messages to
		SendMessage(m_wndToolbar.m_hWnd, TB_SETPARENT, (WPARAM)pT->m_hWnd, 0);
	}
	void MoveToolbar(LPCRECT pRect = NULL)
	{
		if (m_wndToolbar.m_hWnd == NULL)
			return;

		RECT	rect;
		HRESULT hr;

		T* pT = static_cast<T*>(this);
		hr = pT->m_spInPlaceFrame->RequestBorderSpace(&m_bw);
		if (FAILED(hr))
			return;

		pT->m_spInPlaceFrame->SetBorderSpace(&m_bw);

		// Get the border if we don't have it
		if (pRect == NULL)
			pT->m_spInPlaceFrame->GetBorder(&rect);
		else
			rect = *pRect;

		rect.left   += m_bw.left;
		rect.bottom = rect.top + m_bw.top;

		// Now move the toolbar
		m_wndToolbar.MoveWindow(&rect);
	}
	void CreateToolbar(HWND hParent)
	{
		InitCommonControls();

		RECT rect;
		T* pT = static_cast<T*>(this);
		pT->m_spInPlaceFrame->GetBorder(&rect);
		
		int nLeft	= rect.left + m_bw.left;
		int nTop	= rect.top;
		int nRight	= rect.right;
		int nBottom = rect.top + m_bw.top;
		
#if 0
		m_wndToolbar.Create(hParent, &rect, NULL, 
			WS_CHILD | WS_BORDER | WS_VISIBLE | TBSTYLE_TOOLTIPS,
			0, IDR_TOOLBAR1);
#else
		m_wndToolbar.m_hWnd = CreateWindowEx(
				0,
				TOOLBARCLASSNAME,
				NULL,
				WS_CHILD | WS_BORDER | WS_VISIBLE | TBSTYLE_TOOLTIPS | 
				CCS_TOP  | CCS_NOMOVEX | CCS_NORESIZE ,
				nLeft, nTop, nRight-nLeft, nBottom-nTop,
				hParent,
				(HMENU)IDR_TOOLBAR1,
				_Module.GetResourceInstance(),
				NULL);
#endif
		AddButtons();
	}

	void AddButtons()
	{
		int nButtons;
		const int* arrID = T::_GetToolbarEntries(nButtons);
		TBBUTTON* pButton = new TBBUTTON[nButtons];
		TBADDBITMAP tbab;
		int nIndex = 0;

		// Send the TB_BUTTONSTRUCTSIZE message, which is required for
		// backward compatibility.
		SendMessage(m_wndToolbar.m_hWnd, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0);

		// Add the bitmap containing button images to the toolbar.
		tbab.hInst = _Module.GetResourceInstance();
		tbab.nID = IDR_TOOLBAR1;
		SendMessage(m_wndToolbar.m_hWnd, TB_ADDBITMAP, nButtons, (WPARAM)&tbab);

		// Loop around, adding each button to the TBBUTTON array
		for (int i = 0; i < nButtons; i++)
		{
			pButton[i].fsState   = TBSTATE_ENABLED;
			pButton[i].dwData    = 0;
			pButton[i].iString   = 0;
			if (arrID[i] != ID_SEP)
			{
				pButton[i].iBitmap   = nIndex;
				pButton[i].fsStyle   = TBSTYLE_BUTTON;
				pButton[i].idCommand = arrID[i];
				nIndex++;
			}
			else
			{
				pButton[i].fsStyle   = TBSTYLE_BUTTON|TBSTYLE_SEP;
				pButton[i].iBitmap   = 8;   // Width of separator
				pButton[i].idCommand = 0;
			}
		}

		// Add the buttons
		SendMessage(m_wndToolbar.m_hWnd, TB_ADDBUTTONS, nButtons, (LPARAM)pButton);
		delete [] pButton;
	}

	void DestroyToolbar()
	{
		if (m_wndToolbar.m_hWnd != NULL)
		{
			::DestroyWindow(m_wndToolbar.m_hWnd);
			m_wndToolbar.m_hWnd = NULL;
		}
	}

	LRESULT OnToolbarNeedText(WPARAM, LPNMHDR pnmh, BOOL&)
	{
		LPTOOLTIPTEXT lpToolTipText = (LPTOOLTIPTEXT)pnmh;
		static TCHAR szBuf[128];

		// Get the string with the same ID as the button from the resource
		LoadString(_Module.GetResourceInstance(),
			(UINT)(lpToolTipText->hdr.idFrom),
			szBuf, sizeof(szBuf)/sizeof(TCHAR));
		lpToolTipText->lpszText = szBuf;

		return 0;
	}
	
	CContainedWindow	m_wndToolbar;
	BORDERWIDTHS		m_bw;
};
