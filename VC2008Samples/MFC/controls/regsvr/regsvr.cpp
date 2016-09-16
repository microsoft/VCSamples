// regsvr.cpp : Program to invoke OLE self-registration on a DLL.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include <windows.h>
#include <ole2.h>
#include <tchar.h>
#include <malloc.h>
#include <stdio.h>
#include "resource.h"

#define FAIL_ARGS   1
#define FAIL_OLE    2
#define FAIL_LOAD   3
#define FAIL_ENTRY  4
#define FAIL_REG    5

const TCHAR _szAppName[] = _T("RegSvr32");
const char _szDllRegSvr[] = "DllRegisterServer";
const char _szDllUnregSvr[] = "DllUnregisterServer";
HINSTANCE _hInstance;

BOOL _bSilent;
BOOL _bConsole;

#define SafePutts(string) ((stdout >= 0) ? _putts(string) : 0)

void
FormatString2(
	LPTSTR lpszOut,
	int nOutSize,
	LPCTSTR lpszFormat,
	LPCTSTR lpsz1,
	LPCTSTR lpsz2
	)
{
	LPCTSTR pchSrc = lpszFormat;
	LPTSTR pchDest = lpszOut;
	while (*pchSrc != '\0') {
		if (pchSrc[0] == '%' && (pchSrc[1] >= '1' && pchSrc[1] <= '2')) {
			_tcscpy_s(pchDest, nOutSize, (LPCTSTR)(pchSrc[1] == '1' ? lpsz1 : lpsz2));
			pchDest += lstrlen(pchDest);
			pchSrc += 2;
		} else {
			if (_istlead(*pchSrc))
				*pchDest++ = *pchSrc++; // copy first of 2 bytes
			*pchDest++ = *pchSrc++;
		}
	}
	*pchDest = '\0';
}

#define MAX_STRING 1024

void
DisplayMessage(
	UINT ids,
	LPCTSTR pszArg1 = NULL,
	LPCTSTR pszArg2 = NULL,
	BOOL bUsage = FALSE,
	BOOL bInfo = FALSE
	)
{
	if (_bSilent && !_bConsole)
		return;

	TCHAR szFmt[MAX_STRING];
	LoadString(_hInstance, ids, szFmt, MAX_STRING);

	TCHAR szText[MAX_STRING];
	FormatString2(szText, MAX_STRING, szFmt, pszArg1, pszArg2);
	if (bUsage) {
		int cch = (int)_tcslen(szText);
		LoadString(_hInstance, IDS_USAGE, szText + cch, MAX_STRING - cch);
	}

	if (! _bSilent)
		MessageBox(NULL, szText, _szAppName,
			MB_TASKMODAL | (bInfo ? MB_ICONINFORMATION : MB_ICONEXCLAMATION));

	if (_bConsole) {
		TCHAR szMessage[MAX_STRING];
		FormatString2(szMessage, MAX_STRING, _T("%1: %2\n"), _szAppName, szText);
		SafePutts(szMessage);
	}
}

inline void
Usage(
	UINT ids,
	LPCTSTR pszArg1 = NULL,
	LPCTSTR pszArg2 = NULL
	)
{
	DisplayMessage(ids, pszArg1, pszArg2, TRUE);
}

inline void
Info(
	UINT ids,
	LPCTSTR pszArg1 = NULL,
	LPCTSTR pszArg2 = NULL
	)
{
	DisplayMessage(ids, pszArg1, pszArg2, FALSE, TRUE);
}

#ifdef _UNICODE
int wmain(int argc, WCHAR *argv[])
#else // !_UNICODE
int main(int argc, char *argv[])
#endif
{
	int iReturn = 0;
	HRESULT (STDAPICALLTYPE * lpDllEntryPoint)(void);

	BOOL bVisualC = FALSE;
	BOOL bUnregister = FALSE;
	LPCSTR pszDllEntryPoint = _szDllRegSvr;
	LPTSTR ptszDllEntryPoint = NULL;
	LPCTSTR pszDllName = NULL;
	LPCTSTR pszTok;
	size_t EntryPointSize = 0;

	_hInstance = ::GetModuleHandle(NULL);

	// Parse command line arguments.
	int iTok;
	for (iTok = 1; iTok < argc; iTok++) {
		pszTok = argv[iTok];

		if ((pszTok[0] == '-') || (pszTok[0] == '/')) {
			switch (pszTok[1]) {
				case 'v':
				case 'V':
					bVisualC = TRUE;
					break;

				case 's':
				case 'S':
					_bSilent = TRUE;
					break;

				case 'u':
				case 'U':
					bUnregister = TRUE;
					pszDllEntryPoint = _szDllUnregSvr;
					break;

				case 'c':
				case 'C':
					_bConsole = TRUE;
					break;

				default:
					Usage(IDS_UNRECOGNIZEDFLAG, pszTok);
					return FAIL_ARGS;
			}
		} else {
			if (pszDllName == NULL) {
				pszDllName = pszTok;
				break;
			} else {
				Usage(IDS_EXTRAARGUMENT, pszTok);
				return FAIL_ARGS;
			}
		}
	}

	if (pszDllEntryPoint != NULL) {
		EntryPointSize = (1 + strlen(pszDllEntryPoint)) * (sizeof(TCHAR));
		ptszDllEntryPoint = (TCHAR *)_malloca(EntryPointSize); // _malloca may allocate memory on the heap, so we need to call _freea to clean the heap if used
#ifdef _UNICODE
		swprintf_s(ptszDllEntryPoint, EntryPointSize, _T("%hs"), pszDllEntryPoint);
#else // !_UNICODE
		strcpy_s(ptszDllEntryPoint, EntryPointSize, pszDllEntryPoint);
#endif
	}

	if (pszDllName == NULL) {
		if (bVisualC)
			DisplayMessage(IDS_NOPROJECT);
		else
			Usage(IDS_NODLLNAME);
		_freea(ptszDllEntryPoint);
		return FAIL_ARGS;
	}

	// Initialize OLE.
	if (FAILED(OleInitialize(NULL))) {
		DisplayMessage(IDS_OLEINITFAILED);
		_freea(ptszDllEntryPoint);
		return FAIL_OLE;
	}

	SetErrorMode(SEM_FAILCRITICALERRORS);       // Make sure LoadLib fails.
	for (; iTok < argc; iTok++) {
		pszDllName = argv[iTok];

		// Load the library.
		HINSTANCE hLib = LoadLibraryEx(pszDllName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);

		if (hLib < (HINSTANCE)HINSTANCE_ERROR) {
			TCHAR szError[12];
			_stprintf_s(szError, 12, _T("0x%08lx"), GetLastError());
			DisplayMessage(IDS_LOADLIBFAILED, pszDllName, szError);
			iReturn = FAIL_LOAD;
			goto CleanupOle;
		}

		// Find the entry point.
		(FARPROC&)lpDllEntryPoint = GetProcAddress(hLib, pszDllEntryPoint);

		if (lpDllEntryPoint == NULL) {
			TCHAR szExt[_MAX_EXT];
			_tsplitpath_s(pszDllName, NULL, 0, NULL, 0, NULL, 0, szExt, _MAX_EXT);

			if ((_tcsicmp(szExt, _T(".dll")) != 0) && (_tcsicmp(szExt, _T(".ocx")) != 0))
				DisplayMessage(IDS_NOTDLLOROCX, pszDllName, ptszDllEntryPoint);
			else
				DisplayMessage(IDS_NOENTRYPOINT, pszDllName, ptszDllEntryPoint);

			iReturn = FAIL_ENTRY;
			goto CleanupLibrary;
		}

		// Call the entry point.
		if (FAILED((*lpDllEntryPoint)())) {
			DisplayMessage(IDS_CALLFAILED, ptszDllEntryPoint, pszDllName);
			iReturn = FAIL_REG;
			goto CleanupLibrary;
		}

		Info(IDS_CALLSUCCEEDED, ptszDllEntryPoint, pszDllName);

CleanupLibrary:
		FreeLibrary(hLib);
	}

CleanupOle:
	OleUninitialize();
	_freea(ptszDllEntryPoint);
	return iReturn;
}
