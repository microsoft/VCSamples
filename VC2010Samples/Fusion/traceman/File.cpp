#include "StdAfx.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include "File.h"

File::File(void)
{
}

File::~File(void)
{
}

bool File::FileExists(const wstring& sFileName)
{
   struct __stat64 buf;  
   int iResult = _wstat64( sFileName.c_str() , &buf);
   
   return (0 == iResult ? true : false);
}

bool File::DirExists(const wstring& sFileName)
{  
   struct __stat64 buf;  
   int iResult = _wstat64( sFileName.c_str() , &buf);
   
   if (0 == iResult) {	    
	   return (buf.st_mode & _S_IFDIR ? true : false);
   }
   else return false;   
}

bool File::Find(const wstring& sFileName, vector<wstring>& vResult, bool bDirs)
{
	bool bFound = false;
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFileW(sFileName.c_str(), &findFileData);

	if (INVALID_HANDLE_VALUE == hFind ) {
		return false;
	}
	else {
		if ((true == bDirs && (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) || 
				(false == bDirs && !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))) 
		{
			if (0 != wcscmp(findFileData.cFileName, L".") && 
					0 != wcscmp(findFileData.cFileName, L".."))
			{
				vResult.push_back(wstring(findFileData.cFileName));				
				bFound = true;				
			}			
		}	
	}

	while(FindNextFileW(hFind, &findFileData)) {
		if (0 == wcscmp(findFileData.cFileName, L"..") || 
				0 == wcscmp(findFileData.cFileName, L"."))
		{
			continue;
		}

		if ((true == bDirs && (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) || 
				(false == bDirs && !(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))) 
		{
			vResult.push_back(wstring(findFileData.cFileName));		
			bFound = true;				
		}
	}

	FindClose(hFind);
	return bFound;
}


bool File::LoadFromResource(const wstring& sFileName, int nResId, SafeXMLReader xml)
{
	HMODULE hLib = LoadLibraryExW(sFileName.c_str(), NULL, LOAD_LIBRARY_AS_DATAFILE);
	if (NULL == hLib) return false;

	HRSRC hResourceInfo = FindResourceExW(hLib, RT_MANIFEST, MAKEINTRESOURCE(nResId) ,0);
	if (NULL == hResourceInfo) return false;

	HGLOBAL hGlobal = ::LoadResource(hLib, hResourceInfo);
	bool bResult = true;

	if (NULL == hGlobal) {
		bResult = false;			
	}
	else {
		int nResSize = SizeofResource(hLib, hResourceInfo);	
		LPVOID pResValue = LockResource(hGlobal);

		if (pResValue != NULL) {
			if (S_OK != xml->LoadFromBuffer(reinterpret_cast<const BYTE *>(pResValue), nResSize)) {
				bResult = false;	
			}
		}
		else bResult = false;
	}

	FreeLibrary(hLib);

	return bResult;
}
