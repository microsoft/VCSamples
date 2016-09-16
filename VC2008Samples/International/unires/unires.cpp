// unires.cpp : Defines the entry point for the application.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// Remark: This sample only runs on Windows 2000 or higher and requires
// language support for all languages to be installed (see in the Control Panel, under
// Regional Options "Language settings for the system")
//

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100
#define MAX_LANGUAGES 50

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// The title bar text

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(HINSTANCE hInstance,
                      HINSTANCE ,
                      LPTSTR     ,
                      int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_UNIRES, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_UNIRES);

	// Main message loop:

	BOOL bRet;
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) 
	{
			if(bRet == -1) {
					return -1;
			}

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_UNIRES);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_UNIRES);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VSCROLL,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szUnicode[MAX_LANGUAGES][MAX_LOADSTRING];
	LOGFONT lf;
	HFONT hfnt;
	TEXTMETRIC tm;
	int i;
	const int nLang = 41;
	SCROLLINFO si; 
	static int yClient;     // height of client area 
	static int yChar;       // vertical scrolling unit 
	static int yPos = 0;        // current vertical scrolling position 
	static int yMax;        // maximum vertical scrolling position 
	int yInc;               // vertical scrolling increment 
	int FirstLine, LastLine;
 
	// Load all the string resources	 
	// Arabic
	LoadString(hInst, IDS_UNICODE_ARA, szUnicode[0], MAX_LOADSTRING);
	// Basque
	LoadString(hInst, IDS_UNICODE_EUQ, szUnicode[1], MAX_LOADSTRING);
	// Bulgarian
	LoadString(hInst, IDS_UNICODE_BGR, szUnicode[2], MAX_LOADSTRING);
	// Catalan
	LoadString(hInst, IDS_UNICODE_CAT, szUnicode[3], MAX_LOADSTRING);
	// Chinese (Simplified)
	LoadString(hInst, IDS_UNICODE_CHS, szUnicode[4], MAX_LOADSTRING);
	// Chinese (Traditional)
	LoadString(hInst, IDS_UNICODE_CHT, szUnicode[5], MAX_LOADSTRING);
	// Croatian
	LoadString(hInst, IDS_UNICODE_HRV, szUnicode[6], MAX_LOADSTRING);
	// Czech
	LoadString(hInst, IDS_UNICODE_CSY, szUnicode[7], MAX_LOADSTRING);
	// Danish
	LoadString(hInst, IDS_UNICODE_DAN, szUnicode[8], MAX_LOADSTRING);
	// Dutch
	LoadString(hInst, IDS_UNICODE_NLD, szUnicode[9], MAX_LOADSTRING);
	// English
	LoadString(hInst, IDS_UNICODE_ENU, szUnicode[10], MAX_LOADSTRING);
	// Estonian
	LoadString(hInst, IDS_UNICODE_ETI, szUnicode[11], MAX_LOADSTRING);
	// Farsi
	LoadString(hInst, IDS_UNICODE_FAR, szUnicode[12], MAX_LOADSTRING);
	// Finnish
	LoadString(hInst, IDS_UNICODE_FIN, szUnicode[13], MAX_LOADSTRING);
	// French
	LoadString(hInst, IDS_UNICODE_FRA, szUnicode[14], MAX_LOADSTRING);
	// German
	LoadString(hInst, IDS_UNICODE_DEU, szUnicode[15], MAX_LOADSTRING);
	// Greek
	LoadString(hInst, IDS_UNICODE_ELL, szUnicode[16], MAX_LOADSTRING);
	// Hebrew
	LoadString(hInst, IDS_UNICODE_HEB, szUnicode[17], MAX_LOADSTRING);
	// Hindi
	LoadString(hInst, IDS_UNICODE_HIN, szUnicode[18], MAX_LOADSTRING);
	// Hungarian
	LoadString(hInst, IDS_UNICODE_HUN, szUnicode[19], MAX_LOADSTRING);
	// Icelandic
	LoadString(hInst, IDS_UNICODE_ISL, szUnicode[20], MAX_LOADSTRING);
	// Irish
	LoadString(hInst, IDS_UNICODE_IRL, szUnicode[21], MAX_LOADSTRING);
	// Italian
	LoadString(hInst, IDS_UNICODE_ITA, szUnicode[22], MAX_LOADSTRING);
	// Japanese
	LoadString(hInst, IDS_UNICODE_JPN, szUnicode[23], MAX_LOADSTRING);
	// Korean
	LoadString(hInst, IDS_UNICODE_KOR, szUnicode[24], MAX_LOADSTRING);
	// Marathi
	LoadString(hInst, IDS_UNICODE_MAR, szUnicode[25], MAX_LOADSTRING);
	// Norwegian
	LoadString(hInst, IDS_UNICODE_NOR, szUnicode[26], MAX_LOADSTRING);
	// Occitan
	LoadString(hInst, IDS_UNICODE_OCT, szUnicode[27], MAX_LOADSTRING);
	// Polish
	LoadString(hInst, IDS_UNICODE_PLK, szUnicode[28], MAX_LOADSTRING);
	// Portuguese
	LoadString(hInst, IDS_UNICODE_PTG, szUnicode[29], MAX_LOADSTRING);
	// Romanian
	LoadString(hInst, IDS_UNICODE_ROM, szUnicode[30], MAX_LOADSTRING);
	// Russian
	LoadString(hInst, IDS_UNICODE_RUS, szUnicode[31], MAX_LOADSTRING);
	// Serbian
	LoadString(hInst, IDS_UNICODE_SRB, szUnicode[32], MAX_LOADSTRING);
	// Slovenian
	LoadString(hInst, IDS_UNICODE_SLV, szUnicode[33], MAX_LOADSTRING);
	// Spanish (Modern Sort)
	LoadString(hInst, IDS_UNICODE_ESN, szUnicode[34], MAX_LOADSTRING);
	// Swedish
	LoadString(hInst, IDS_UNICODE_SVE, szUnicode[35], MAX_LOADSTRING);
	// Tamil
	LoadString(hInst, IDS_UNICODE_TAM, szUnicode[36], MAX_LOADSTRING);
	// Thai
	LoadString(hInst, IDS_UNICODE_THA, szUnicode[37], MAX_LOADSTRING);
	// Turkish
	LoadString(hInst, IDS_UNICODE_TRK, szUnicode[38], MAX_LOADSTRING);
	// Vietnamese
	LoadString(hInst, IDS_UNICODE_VIT, szUnicode[39], MAX_LOADSTRING);
	// Yiddish
	LoadString(hInst, IDS_UNICODE_JII, szUnicode[40], MAX_LOADSTRING);

	// specify the Unicode font to use (stored in a LOGFONT structure)
	lf.lfHeight = 20;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = FW_DONTCARE;
	lf.lfItalic = FALSE;
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = FALSE;
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = FF_DONTCARE;
	_tcsncpy_s(lf.lfFaceName, sizeof(lf.lfFaceName)/sizeof(TCHAR), L"MS Shell Dlg", 12);

	switch (message) 
	{
		
		case WM_CREATE : 
 
			// Get the handle to the client area's device context. 
			hdc = GetDC (hWnd); 
 
			// Create the font from the LOGFONT structure
			hfnt = CreateFontIndirect(&lf); 
			SelectObject(hdc, hfnt);

			// Extract font dimensions from the text metrics. 
 			GetTextMetrics (hdc, &tm); 
			yChar = tm.tmHeight + tm.tmExternalLeading;
	 
			// Free the device context. 
			ReleaseDC (hWnd, hdc); 
 
			return 0; 

		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;

		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			RECT rt;
			GetClientRect(hWnd, &rt);
			hfnt = CreateFontIndirect(&lf); 
			SelectObject(hdc, hfnt);
			
				FirstLine = max (0, yPos + ps.rcPaint.top/yChar - 1); 
			LastLine = min (nLang, yPos + ps.rcPaint.bottom/yChar); 
 
			for (i = FirstLine;i < LastLine;i++) 
			{ 
				rt.top = yChar * (1 - yPos + i); 
				rt.bottom = rt.top+yChar;
				
				TCHAR szLangStr[MAX_LOADSTRING];
				wmemcpy(szLangStr, (wchar_t *) (szUnicode+i), MAX_LOADSTRING); 
				DrawText(hdc, szLangStr, (int) _tcslen(szLangStr), &rt, DT_CENTER); 
			} 
 

			EndPaint(hWnd, &ps);
			break;

		case WM_SIZE: 
 
			// Retrieve the height of the client area. 
			yClient = HIWORD (lParam); 
 
			// Determine the maximum vertical scrolling position. 
			// The two is added for extra space below the lines 
			// of text. 
			yMax = nLang+2; 

			// Make sure the current vertical scrolling position 
			// does not exceed the maximum. 
			yPos = min (yPos, yMax); 
 
			// Adjust the vertical scrolling range and scroll box 
			// position to reflect the new yMax and yPos values. 
			si.cbSize = sizeof(si); 
			si.fMask  = SIF_RANGE | SIF_PAGE | SIF_POS; 
			si.nMin   = 0; 
			si.nMax   = yMax; 
			si.nPage  = (yClient / yChar) + 1; 
			si.nPos   = yPos; 
			SetScrollInfo(hWnd, SB_VERT, &si, TRUE); 
			return 0;

		case WM_VSCROLL:
			switch(LOWORD (wParam)) 
			{ 
				// User clicked the shaft above the scroll box. 
				case SB_PAGEUP: 
					 yInc = -yClient/yChar; 
					 break; 
 
				// User clicked the shaft below the scroll box. 
 				case SB_PAGEDOWN: 
					 yInc = yClient/yChar; 
					 break; 
 
				// User clicked the top arrow. 
 				case SB_LINEUP: 
					 yInc = -1; 
					 break; 
 
				// User clicked the bottom arrow. 
 				case SB_LINEDOWN: 
					 yInc = 1; 
					 break; 
 
				// User dragged the scroll box. 
 				case SB_THUMBPOSITION: 
					 yInc = HIWORD(wParam) - yPos; 
					 break; 
 
				default: 
					 yInc = 0; 
 
			} 
 
			// If applying the vertical scrolling increment does not 
			// take the scrolling position out of the scrolling range, 
			// increment the scrolling position, adjust the position 
			// of the scroll box, and update the window. UpdateWindow 
			// sends the WM_PAINT message. 
			 
			yInc = max(-yPos, min(yInc, yMax-yPos-yClient/yChar));
			if(yInc)
			{ 
				yPos += yInc; 
				ScrollWindowEx(hWnd, 0, -yChar*yInc, 
					(CONST RECT *) NULL, (CONST RECT *) NULL, 
					(HRGN) NULL, (LPRECT) NULL, SW_INVALIDATE|SW_ERASE); 
				si.cbSize = sizeof(si); 
				si.fMask  = SIF_POS; 
				si.nPos   = yPos; 
				SetScrollInfo(hWnd, SB_VERT, &si, TRUE); 
				UpdateWindow (hWnd); 
			} 
 
			return 0; 
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM )
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

