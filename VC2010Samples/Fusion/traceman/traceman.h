#pragma once

#include "stdafx.h"
#include "debug.h"

int trace(const wstring& sAppName, const wstring& sFilter);
int load(const wstring& sAppName);
int dump(const wstring& sFilter);
bool SetSXSDirs();
DWORD GetWinVersion(bool bMinor = true);
HMODULE LoadXMLLite();

bool is_special_regex(const wchar_t c);
wstring quote_regex(const wstring& sFilter);
wstring IntToStr(int iValue);
wstring GetSystemArch();