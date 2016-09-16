#include "StdAfx.h"
#include "Version.h"

Version::Version(const wstring& sVersion) : m_nM(0), m_nN(0), m_nO(0), m_nP(0)
{
	const wregex rex(L"([0-9]{1,5})\\.([0-9]{1,5})\\.([0-9]{1,5})\\.([0-9]{1,5})");
	std::tr1::wsmatch m;

	if (regex_match(sVersion, m, rex)) {
		m_nM = _wtoi(wstring(m[1]).c_str());
		m_nN = _wtoi(wstring(m[2]).c_str());
		m_nO = _wtoi(wstring(m[3]).c_str());
		m_nP = _wtoi(wstring(m[4]).c_str());
	}
}

Version::~Version(void)
{
}

bool Version::IsValid(const wstring& sVersion)
{		
	const wregex r(L"([1-9][0-9]{0,4})\\.([1-9][0-9]{0,4}|0)\\.([1-9][0-9]{0,4}|0)\\.([1-9][0-9]{0,4}|0)");
	
	return regex_match(sVersion, r);		
}

bool Version::operator==(const Version& ver) const 
{
	if (m_nM == ver.m_nM && m_nN == ver.m_nN && m_nO == ver.m_nO && m_nP == ver.m_nP) return true;
	else return false;
}

bool Version::operator<(const Version& ver) const 
{
	if (m_nM == ver.m_nM) {
		if (m_nN == ver.m_nN) {
			if (m_nO == ver.m_nO) {
				return (m_nP < ver.m_nP);
			}
			else return (m_nO < ver.m_nO);
		}
		else return (m_nN < ver.m_nN);
	}
	else return (m_nM < ver.m_nM);
}

bool Version::operator<=(const Version& ver) const
{
	return this->operator <(ver) || this->operator ==(ver);
}

bool Version::IsInRange(const wstring& sAssemblyVersion, const wstring& sOldVersion)
{
	wstring sHigh = sOldVersion;
	Version assemblyVersion(sAssemblyVersion);

	std::string::size_type pos = sHigh.find(L"-");

	if (pos != std::wstring::npos) {			
		Version lowVersion(sHigh.substr(0, pos));
		Version highVersion(sHigh.substr(pos + 1));

		if (lowVersion <= assemblyVersion && assemblyVersion <= highVersion) {			
			return true;
		}
	}
	else {
		Version aHightVer(sHigh);
		
		if (assemblyVersion == aHightVer) {
			return true;
		}
	}

	return false;
}

bool Version::IsValidRange(const wstring& sAssemblyVersion) 
{	
	std::string::size_type pos = sAssemblyVersion.find(L"-");

	if (pos != std::wstring::npos) {
		return true;
	}
	else {
		Version lowVersion(sAssemblyVersion.substr(0, pos));
		Version highVersion(sAssemblyVersion.substr(pos + 1));

		if (lowVersion <= highVersion) {
			return true;
		}
	}
	return false;
}
