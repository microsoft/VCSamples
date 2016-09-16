// Main.cpp : Code for executable containing the program logic
//
// Copyright (c) Microsoft Corporation.  All rights reserved.

#include "stdafx.h"
#include "Main.h"
#define MAX_LOADSTRING	100	
#define MAX_LANGNAME	255		// Maximum native language name length

// Type definitions
typedef struct LANGINFO_DEF {
	int		Count;
	LANGID	LangID;
} LANGINFO;
typedef LANGINFO *PLANGINFO;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// The title bar text
LANGID UILanguage;								// The UI language chosen by the user
HMODULE hSatDLL;								// Handle for the satellite DLL module

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Language(HWND, UINT, WPARAM, LPARAM);
int					PopulateLanguages(HWND);
LANGID				DetectLanguage(void);
HMODULE				LoadSatelliteDLL(LANGID);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE,
                     LPTSTR,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	UILanguage = DetectLanguage();
	hSatDLL = LoadSatelliteDLL(UILanguage);
	if( hSatDLL == NULL ) hSatDLL = hInstance;

	// Initialize global strings
	LoadString(hSatDLL, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hSatDLL, IDC_MAIN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hSatDLL, (LPCTSTR)IDC_MAIN);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
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
	wcex.hIcon			= LoadIcon(hSatDLL, (LPCTSTR)IDI_MAIN);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCTSTR)IDC_MAIN;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(hSatDLL, (LPCTSTR)IDI_SMALL);

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

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
	HFONT hfnt;
	LOGFONT lf;
	TCHAR szHello[MAX_LOADSTRING];

	// specify the font to use (stored in a LOGFONT structure)
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
	_tcsncpy_s(lf.lfFaceName, sizeof(lf.lfFaceName)/sizeof(TCHAR), _T("MS Shell Dlg"), 12);

	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hSatDLL, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case ID_FILE_CHOOSELANGUAGE:
			DialogBox(hSatDLL, (LPCTSTR)IDD_DIALOG, hWnd, (DLGPROC)Language);
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
		rt.top += 20;
		rt.left += 20;
		LoadString(hSatDLL, IDS_HELLO, szHello, MAX_LOADSTRING);
		DrawText(hdc, szHello, _tcslen(szHello), &rt, DT_LEFT);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM)
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

// Message handler for language selection box.
LRESULT CALLBACK Language(HWND hDlg, UINT message, WPARAM wParam, LPARAM)
{
	int		index;
	LRESULT	NewUILanguage;
	HWND	hwndCombo = GetDlgItem(hDlg,IDC_LANGUAGE);
	HWND	hMainWindow = GetParent(hDlg);
	HMENU	hNewMenu;


	switch (message)
	{
	case WM_INITDIALOG:
		PopulateLanguages(hwndCombo);
		return TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
			case IDOK:
				index = SendMessage(hwndCombo, CB_GETCURSEL, 0, 0);
				if( index != CB_ERR ) {
					NewUILanguage = SendMessage(hwndCombo, CB_GETITEMDATA, index, 0);
					if( NewUILanguage != CB_ERR && NewUILanguage != UILanguage ) {
						UILanguage = (LANGID)NewUILanguage;
						hSatDLL = LoadSatelliteDLL(UILanguage);
						if( hSatDLL == NULL ) hSatDLL = hInst;
						// Redraw the client area of the main window
						InvalidateRect(hMainWindow,NULL,TRUE);
						UpdateWindow(hMainWindow);
						// Update the caption of the main window
						LoadString(hSatDLL, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
						SendMessage(hMainWindow,WM_SETTEXT, NULL, (LPARAM)szTitle);
						// Load the localized menu
						DestroyMenu(GetMenu(hMainWindow));
						hNewMenu = LoadMenu(hSatDLL,(LPCTSTR)IDC_MAIN);
						SetMenu(hMainWindow, hNewMenu);
						DrawMenuBar(hMainWindow);
					}
				}
			case IDCANCEL:
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
		}
		break;
	}
	return FALSE;
}

// Populates the list of languages in the selection dialog
// according to the subdirectories named with decimal LCID
int PopulateLanguages(HWND hwndCombo) {
	TCHAR				CurrentDirectory[MAX_PATH];
	int					AvailableLangID;
	TCHAR				AvailableLangName[MAX_LANGNAME];
	WIN32_FIND_DATA		FindFileData;
	HANDLE				hDir;
	int					i = 0;
	int					j;
	int					CurrentIndex = 0;

	// Retrieve the current directory name
	if( GetCurrentDirectory(MAX_PATH, CurrentDirectory)) {
		if( _tcsclen(CurrentDirectory) < MAX_PATH-4 )
			_tcscat_s(CurrentDirectory, sizeof(CurrentDirectory)/sizeof(TCHAR), _T("\\*.*"));
	}
	else
		return 0;

	// Loop through all directories and populate the drop-down list for the
	// language selection
	hDir = FindFirstFile(CurrentDirectory, &FindFileData);
	if( hDir == INVALID_HANDLE_VALUE ) {
		FindClose(hDir);
		return 0;
	}
	SendMessage(hwndCombo, CB_RESETCONTENT, 0, 0);
	do {
		if( FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) {
			AvailableLangID = _ttoi(FindFileData.cFileName);
			if( AvailableLangID ) {
				if( GetLocaleInfo(AvailableLangID,LOCALE_SNATIVELANGNAME,AvailableLangName,MAX_LANGNAME)) {
					CurrentIndex = SendMessage(hwndCombo, CB_ADDSTRING, 0, (LPARAM)AvailableLangName);
					SendMessage(hwndCombo, CB_SETITEMDATA, (WPARAM)CurrentIndex, (LPARAM)AvailableLangID);
					i++;
				}
			}
		}
	} while ( FindNextFile(hDir, &FindFileData) );
	FindClose(hDir);
	// To set the current selection we have to loop through the combo box
	// because the addition sorted the combo box alphabetically
	for(j=0 ; j<=i ; j++) {
		if( UILanguage == SendMessage(hwndCombo, CB_GETITEMDATA, j, 0) )
			SendMessage(hwndCombo, CB_SETCURSEL, (WPARAM)j, 0);
	}
	return i;

}

// Loads the satellite DLL specified for the language DesiredLanguage
HMODULE		LoadSatelliteDLL(LANGID DesiredLanguage) {
	TCHAR		BaseDirectory[MAX_PATH];
	TCHAR		SatellitePath[MAX_PATH];
	TCHAR		buffer[100];
	HMODULE		hDLL;

	// Get the base directory for the satellite DLL search
	if( GetCurrentDirectory(MAX_PATH, BaseDirectory)) {
		_tcscat_s(BaseDirectory, sizeof(BaseDirectory)/sizeof(TCHAR), _T("\\"));
	}
	else
		return NULL;

	// First try to load the library with the fully specified language
	_tcscpy_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), BaseDirectory);
	_itot_s(DesiredLanguage,buffer, sizeof(buffer)/sizeof(TCHAR), 10);
	_tcscat_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), buffer);
	_tcscat_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), _T("\\Satellite.dll"));
	hDLL = LoadLibrary(SatellitePath);
	if( hDLL )
		return hDLL;
	else {   // try the primary language ID
		_tcscpy_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), BaseDirectory);
		DesiredLanguage = PRIMARYLANGID(DesiredLanguage);
		_itot_s(DesiredLanguage,buffer,sizeof(buffer)/sizeof(TCHAR),10);
		_tcscat_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), buffer);
		_tcscat_s(SatellitePath, sizeof(SatellitePath)/sizeof(TCHAR), _T("\\Satellite.dll"));
		hDLL = LoadLibrary(SatellitePath);
		if( hDLL )
			return hDLL;
		else
			return NULL;
	}
}

// The following functions contain code to
// detect the language in which the initial
// user interface should be displayed

BOOL CALLBACK EnumLangProc(HANDLE, LPCTSTR, LPCTSTR,
						   WORD wIDLanguage, LONG_PTR lParam)
{
    PLANGINFO LangInfo;

    LangInfo = (PLANGINFO) lParam;
    LangInfo->Count++;
    LangInfo->LangID  = wIDLanguage;

    return (TRUE);        // continue enumeration
}

// Detects the language of ntdll.dll with some specific processing for 
// the Hongkong SAR version
LANGID GetNTDLLNativeLangID()
{

    LANGINFO LangInfo;
	LPCTSTR Type = (LPCTSTR) ((LPVOID)((WORD)16));
    LPCTSTR Name = (LPCTSTR) 1;

    ZeroMemory(&LangInfo,sizeof(LangInfo));
    
    // Get the HModule for ntdll.
    HMODULE hMod = GetModuleHandle(_T("ntdll.dll"));
    if (hMod==NULL) {
        return(0);
    }

    BOOL result = EnumResourceLanguages(hMod, Type, Name, (ENUMRESLANGPROC)EnumLangProc, (LONG_PTR) &LangInfo);
    
    if (!result || (LangInfo.Count > 2) || (LangInfo.Count < 1) ) {
        return (0);
    }
    
    return (LangInfo.LangID);
}

// Checks if NT4 system is Hongkong SAR version
BOOL IsHongKongVersion()
{
    HMODULE hMod;
    BOOL bRet=FALSE;
	typedef BOOL (WINAPI *IMMRELEASECONTEXT)(HWND,HIMC);
    IMMRELEASECONTEXT pImmReleaseContext;

    hMod = LoadLibrary(_T("imm32.dll"));
    if (hMod) {
        pImmReleaseContext = (IMMRELEASECONTEXT)GetProcAddress(hMod,"ImmReleaseContext");
        if (pImmReleaseContext) {
            bRet = pImmReleaseContext(NULL,NULL);
        }
        FreeLibrary(hMod);
    }
    return (bRet);
}

// This function detects a correct initial UI language for all
// platforms (Win9x, ME, NT4, Windows 2000, Windows XP)
LANGID DetectLanguage() {

#define MAX_KEY_BUFFER	80

	OSVERSIONINFO		VersionInfo;
	LANGID				uiLangID = 0;
	HKEY				hKey;
	DWORD				Type, BuffLen = MAX_KEY_BUFFER;
	TCHAR				LangKeyValue[MAX_KEY_BUFFER];


	VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if( !GetVersionEx(&VersionInfo) )
		return(0);

	switch( VersionInfo.dwPlatformId ) {
		// On Windows NT, Windows 2000 or higher
		case VER_PLATFORM_WIN32_NT:
			if( VersionInfo.dwMajorVersion >= 5)   // Windows 2000 or higher
				uiLangID = GetUserDefaultUILanguage();
			else {   // for NT4 check the language of ntdll.dll
				uiLangID = GetNTDLLNativeLangID();   
				if (uiLangID == 1033) {		// special processing for Honkong SAR version of NT4
					if (IsHongKongVersion()) {
						uiLangID = 3076;
					}
				}
			}
			break;
		// On Windows 98 or Windows ME
		case VER_PLATFORM_WIN32_WINDOWS:
			// Open the registry key for the UI language
			if( RegOpenKeyEx(HKEY_CURRENT_USER,_T("Default\\Control Panel\\Desktop\\ResourceLocale"), 0,
				KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS ) {
				// Get the type of the default key
				if( RegQueryValueEx(hKey, NULL, NULL, &Type, NULL, NULL) == ERROR_SUCCESS 
					&& Type == REG_SZ ) {
					// Read the key value
					if( RegQueryValueEx(hKey, NULL, NULL, &Type, (LPBYTE)LangKeyValue, &BuffLen) 
						== ERROR_SUCCESS ) {
						uiLangID = (LANGID)_ttoi(LangKeyValue);
					}
				}
				RegCloseKey(hKey);
			}				
			break;
	}

    if (uiLangID == 0) {
        uiLangID = GetUserDefaultLangID();
    }
    // Return the found language ID.
    return (uiLangID);
}