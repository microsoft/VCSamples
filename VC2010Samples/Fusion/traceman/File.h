#pragma once

#include "stdafx.h"
#include "XMLReader.h"

class File
{
public:
	File(void);
	virtual ~File(void);

	static bool FileExists(const wstring& sFileName);
	static bool DirExists(const wstring& sFileName);	
	static bool Find(const wstring& sFileName,vector<wstring>& vResult, bool bDirs = false); 
	static bool LoadFromResource(const wstring& sFileName, int nResId, SafeXMLReader xml);	
};
