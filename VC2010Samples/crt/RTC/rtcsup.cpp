/* 
 * Copyright (c) Microsoft Corporation.  All rights reserved.
 *
 * Demonstration of the use of the Run-Time Error Checking (RTC) API without 
 * using the C Run-Time Library (CRT).
 *
 * This file contains functions for initialization and termination of RTC,
 * along with a custom handler for RTC failures.  
 * 
 */
#include "rtcsample.h"

void
DoInitialization()
{
#ifdef __MSVC_RUNTIME_CHECKS
#	ifdef NOCRT
    _RTC_Initialize();
#	else
    // This is only necessary when using a custom RTC handler function.
	// If using a debug CRT and a custom handler is *not* designated with
	// _RTC_SetErrorFunc, then failures will be reported via _CrtDbgReport.
	_RTC_SetErrorFuncW(Catch_RTC_Failure);
#	endif
#endif
    // Do any other initialization here
	
}

void
DoTermination()
{
    // Do any other termination work here
#if defined(__MSVC_RUNTIME_CHECKS) && defined(NOCRT)
    _RTC_Terminate();
#endif
}


#ifdef __MSVC_RUNTIME_CHECKS

#include <stdarg.h>
#include <malloc.h>

#ifdef NOCRT
    // Use intrinsics, so we don't add CRT dependencies
#   pragma intrinsic(strlen)


    wchar_t *IntToString(int i)
    {
        static wchar_t buf[15];
        bool neg = i < 0;
        int pos = 14;
        buf[14] =L'\0';
        do {
            buf[--pos] = (wchar_t)(i % 10 + L'0');
            i /= 10;
        } while (i);
        if (neg)
            buf[--pos] = '-';
        return &buf[pos];
    }
#else // NOCRT is undefined
#   include <stdio.h>
#endif

int Catch_RTC_Failure(int errType, const wchar_t *file, int line, const wchar_t *module, const wchar_t *format, ...)
{
	// Prevent re-entrancy ; isn't necessary here, but if this were a
	// multi-threading program, it would be.
	static long running = 0;
	while (InterlockedExchange(&running, 1))
		Sleep(0);

    // First, get the RTC error number from the var-arg list...
    va_list vl;
    va_start(vl, format);
    _RTC_ErrorNumber rtc_errnum = va_arg(vl, _RTC_ErrorNumber);
    va_end(vl);
    
    // Build a string buffer to display in a message box
    wchar_t buf[1024];
	

#ifdef NOCRT
	wchar_t errbuf[1024];
	const char *err = _RTC_GetErrDesc(rtc_errnum);
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED | MB_ERR_INVALID_CHARS, err, -1, errbuf, 1024);
	StringCbCopyW(buf, 1024,  errbuf);
    if (line)
    {
        StringCbCatW(buf, 1024, L"\nLine #");
        StringCbCatW(buf, 1024, IntToString(line));
    }
    if (file)
    {
        StringCbCatW(buf, 1024, L"\nFile:");
        StringCbCatW(buf, 1024, file);
    }
    if (module)
    {
        StringCbCatW(buf, 1024, L"\nModule:");
        StringCbCatW(buf, 1024, module);
    }
	StringCbCatW(buf, 1024, L"\nError Type:");
	StringCbCatW(buf, 1024, IntToString(errType));
#else // NOCRT is undefined
    wchar_t buf2[1024];
    va_start(vl, format);
    vswprintf_s(buf2, 1024, format, vl);
    swprintf_s(
        buf, 1024,
        L"RTC Failure #%d (user specified type %d) occurred:\n\nModule:\t%s\nFile:\t%s\nLine:\t%d\n\nFull Message:\n%s",
        rtc_errnum,
        errType,
        module ? module : L"",
        file ? file : L"",
        line,
        buf2);
#endif

    running = 0;
#ifdef NOCRT
    StringCbCatW(buf, 1024, L"\n\nWould you like to break to the debugger?");
#else
	wcscat_s(buf, 1024, L"\n\nWould you like to break to the debugger?");
#endif
    return (MessageBoxW(NULL, buf, L"RTC Failed...", MB_YESNO) == IDYES) ? 1 : 0;
}

#ifdef NOCRT
extern "C" _RTC_error_fnW _CRT_RTC_INITW(void *, void **, int , int , int )
{
	return &Catch_RTC_Failure;
}
#endif

#endif /* rtcsamp.cpp */

