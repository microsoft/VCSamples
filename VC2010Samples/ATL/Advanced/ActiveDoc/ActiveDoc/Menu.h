// menu.h : menu merging implementation
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

template <class T>
class CMenu
{
public:
	void InPlaceMenuCreate()
	{
		IOleInPlaceFrame*   pFrame;
		HRESULT             hr;
		HMENU               hOurMenu;
		OLEMENUGROUPWIDTHS  mgw;
		T* pT = static_cast<T*>(this);

		if (pT->m_spInPlaceFrame == NULL)
		{
			// We weren't given an IOleInPlaceFrame pointer, so
			// we'll have to get it ourselves.
			RECT rcPos, rcClip;
			CComPtr<IOleInPlaceUIWindow> spInPlaceUIWindow;
			pT->m_frameInfo.cb = sizeof(OLEINPLACEFRAMEINFO);
			pT->m_spInPlaceSite->GetWindowContext(&pFrame,
				&spInPlaceUIWindow, &rcPos, &rcClip, &pT->m_frameInfo);
		}
		else
			pFrame = pT->m_spInPlaceFrame;

		ZeroMemory(&mgw, sizeof(OLEMENUGROUPWIDTHS));

		// Create a blank menu and ask the container to add
		// its menus into the OLEMENUGROUPWIDTHS structure
		m_hMenuShared = ::CreateMenu();
		hr = pFrame->InsertMenus(m_hMenuShared, &mgw);
		if (FAILED(hr))
		{
			::DestroyMenu(m_hMenuShared);
			m_hMenuShared = NULL;
			return;
		}

		// Insert our menus
		hOurMenu = LoadMenu(_Module.GetResourceInstance(),
			MAKEINTRESOURCE(IDR_MAINMENU));
		MergeMenus(m_hMenuShared, hOurMenu, &mgw.width[0], 1);		

		// Send the menu to the client
		m_hOleMenu = (HMENU)OleCreateMenuDescriptor(m_hMenuShared, &mgw);
		pFrame->SetMenu(m_hMenuShared, m_hOleMenu, pT->m_hWnd);

		// If we got the IOleInPlaceFrame pointer ourselves
		// we have to release it
		if (pT->m_spInPlaceFrame == NULL)
			pFrame->Release();
	}

	void InPlaceMenuDestroy()
	{
		T* pT = static_cast<T*>(this);
		CComPtr<IOleInPlaceFrame> spInPlaceFrame;
		CComPtr<IOleInPlaceUIWindow> spInPlaceUIWindow;
		RECT rcPos, rcClip;

		// Get the clients IOleInPlaceFrame so we can ask
		// it to remove its menu
		pT->m_spInPlaceSite->GetWindowContext(&spInPlaceFrame,
			&spInPlaceUIWindow, &rcPos, &rcClip, &pT->m_frameInfo);
		if (spInPlaceFrame)
			spInPlaceFrame->SetMenu(NULL, NULL, NULL);

		OleDestroyMenuDescriptor(m_hOleMenu);
		m_hOleMenu = NULL;

		HMENU hOurMenu = LoadMenu(_Module.GetResourceInstance(),
			MAKEINTRESOURCE(IDR_MAINMENU));
		UnmergeMenus(m_hMenuShared, hOurMenu);
		DestroyMenu(hOurMenu);
	}

	void MergeMenus(HMENU hMenuShared, HMENU hMenuSource, LONG* lpMenuWidths,
		unsigned int nWidthIndex)
	{
		// Copy the popups from the pMenuSource
		int nMenuItems = GetMenuItemCount(hMenuSource);
		int nGroupWidth = 0;
		int nPosition = 0;

		// Insert at appropriate spot depending on nWidthIndex
		ATLASSERT(nWidthIndex == 0 || nWidthIndex == 1);
		if (nWidthIndex == 1)
			nPosition = (int)lpMenuWidths[0];

		for (int i = 0; i < nMenuItems; i++)
		{
			// Get the HMENU of the popup
			HMENU hMenuPopup = ::GetSubMenu(hMenuSource, i);

			// Separators move us to next group
			UINT state = GetMenuState(hMenuSource, i, MF_BYPOSITION);
			if (hMenuPopup == NULL && (state & MF_SEPARATOR) != 0)
			{
			   // Servers should not touch past 5
				ATLASSERT(nWidthIndex <= 5);
				lpMenuWidths[nWidthIndex] = nGroupWidth;
				nGroupWidth = 0;
				if (nWidthIndex < 5)
					nPosition += (int)lpMenuWidths[nWidthIndex+1];
				nWidthIndex += 2;
			}
			else
			{
				// Get the menu item text
				TCHAR szItemText[256];
				int nLen = GetMenuString(hMenuSource, i, szItemText,
					sizeof szItemText, MF_BYPOSITION);

				// Popups are handled differently than normal menu items
				if (hMenuPopup != NULL)
				{
					if (::GetMenuItemCount(hMenuPopup) != 0)
					{
						// Strip the HIBYTE because it contains a count of items
						state = LOBYTE(state) | MF_POPUP;   // Must be popup

						// Non-empty popup -- add it to the shared menu bar
						InsertMenu(hMenuShared, nPosition, state | MF_BYPOSITION,
							(UINT_PTR)hMenuPopup, szItemText);
						++nPosition;
						++nGroupWidth;
					}
				}
				else if (nLen > 0)
				{
					// only non-empty items are added
					ATLASSERT(szItemText[0] != 0);

					// here the state does not contain a count in the HIBYTE
					InsertMenu(hMenuShared, nPosition, state | MF_BYPOSITION,
						GetMenuItemID(hMenuSource, i), szItemText);
					++nPosition;
					++nGroupWidth;
				}
			}
		}
	}

	void UnmergeMenus(HMENU hMenuShared, HMENU hMenuSource)
	{
		int cOurItems = GetMenuItemCount(hMenuSource);
		int cMenuItems = GetMenuItemCount(hMenuShared);

		for (int i = cMenuItems-1; i >= 0; i--)
		{
			// Check the popup menus
			HMENU hMenuPopup = ::GetSubMenu(hMenuShared, i);
			if (hMenuPopup != NULL)
			{
				// If it is one of ours, remove it from the hMenuShared
				for (int j = 0; j < cOurItems; j++)
				{
					if (::GetSubMenu(hMenuSource, j) == hMenuPopup)
					{
						// Remove the menu from hMenuShared
						RemoveMenu(hMenuShared, i, MF_BYPOSITION);
						break;
					}
				}
			}
		}
	}

protected:
	HMENU				m_hOleMenu;
	HMENU				m_hMenuShared;
};
