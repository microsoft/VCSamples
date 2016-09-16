#pragma once
#include "stdafx.h"

class Version
{
public:
	Version(const wstring& sVersion);
	virtual ~Version(void);
	
	static bool IsValid(const wstring& sVersion);
	static bool IsInRange(const wstring& sAssemblyVersion, const wstring& sOldVersion);
	static bool IsValidRange(const wstring& sAssemblyVersion);

	bool operator==(const Version&) const;
	bool operator<(const Version&) const;
	bool operator<=(const Version&) const;
private:
	int m_nM;
	int m_nN;
	int m_nO;
	int m_nP;
};
