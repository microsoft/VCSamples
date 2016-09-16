
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>

#include "custview.h"

#include "TimeAddIn.h"

// Helper routine that converts a system time into ASCII

static HRESULT FormatDateTime( SYSTEMTIME *pSystemTime, char *pResult, size_t max )
{
    GetDateFormat( GetThreadLocale(), DATE_SHORTDATE, pSystemTime, NULL, pResult, (int)max );
    size_t len = _tcslen( pResult );
    if ( (max - len) < 2 )
        return E_FAIL;      // if not enough room in buffer
    pResult[ len ] = ' ';
    len++;
    GetTimeFormat( GetThreadLocale(), TIME_NOSECONDS, pSystemTime, NULL, pResult + len, (int)(max - len) );
    return S_OK;
}

ADDIN_API HRESULT AddIn_SystemTime( DWORD dwAddress, DEBUGHELPER *pHelper, int nBase, BOOL bUniStrings, char *pResult, size_t max, DWORD reserved )
{
    SYSTEMTIME SysTime;
    DWORD nGot;

    // read system time from debuggee memory space
    if (pHelper->ReadDebuggeeMemoryEx(pHelper, pHelper->GetRealAddress(pHelper), sizeof(SysTime), &SysTime, &nGot) != S_OK)
        return E_FAIL;
    if (nGot != sizeof(SysTime))
        return E_FAIL;

    return FormatDateTime( &SysTime, pResult, max );
}

ADDIN_API HRESULT AddIn_FileTime( DWORD dwAddress, DEBUGHELPER *pHelper, int nBase, BOOL bUniStrings, char *pResult, size_t max, DWORD reserved )
{
    FILETIME FileTime;
    SYSTEMTIME SysTime;
    DWORD nGot;

    // read file time from debuggee memory space
    if (pHelper->ReadDebuggeeMemoryEx(pHelper, pHelper->GetRealAddress(pHelper), sizeof(FileTime), &FileTime, &nGot) != S_OK)
        return E_FAIL;
    if (nGot != sizeof(FileTime))
        return E_FAIL;

    // convert to SystemTime
    if (!FileTimeToSystemTime( &FileTime, &SysTime ))
        return E_FAIL;

    return FormatDateTime( &SysTime, pResult, max );
}

