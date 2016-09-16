#include "StdAfx.h"
#include "XMLReader.h"
#include "MessageLogger.h"
#include "ManifestFragment.h"
#include "AssemblyManifestFragment.h"
#include "PublisherManifestFragment.h"

SafeXMLReader ManifestFragment::m_xml;

wstring ManifestFragment::m_sSXSDir(L"");
wstring ManifestFragment::m_sAppDir(L"");
wstring ManifestFragment::m_sPolicyDir(L"");
wstring ManifestFragment::m_sManifestDir(L"");

int ManifestFragment::m_nOsVersion = ManifestFragment::NOT_SUPPORTED;
UINT ManifestFragment::m_nMaxDeepLevel = ManifestFragment::MAX_DEEP_LEVEL;

ManifestFragment::ManifestFragment(UINT nDeepLevel) : m_nDeepLevel(nDeepLevel), m_sName(L""), m_sToken(L""),
	m_sArch(L""), m_sVersion(L""), m_sLang(L""), m_sType(L""), m_nTerminateCode(0), m_bEmpty(true)
{	
}

ManifestFragment::~ManifestFragment(void)
{
}

size_t ManifestFragment::GetAssemblyCount(void)
{
	return m_vAssemblies.size();
}

SafeManifestFragment ManifestFragment::GetAssembly(size_t iIdx)
{
	assert(iIdx >= 0 && iIdx < m_vAssemblies.size());

	return m_vAssemblies[iIdx];
}

void ManifestFragment::SetWinSxSDirectory(const wstring& sDirectory)
{
	m_sSXSDir = sDirectory;
}

void ManifestFragment::SetPolicyDirectory(const wstring& sDirectory)
{
	m_sPolicyDir = sDirectory;
}

void ManifestFragment::SetManifestDirectory(const wstring& sDirectory)
{
	m_sManifestDir = sDirectory;
}

UINT ManifestFragment::GetDeepLevel(void) const
{
	return m_nDeepLevel;
}

void ManifestFragment::SetMaxDeepLevel(UINT nDeepLevel)
{
	m_nMaxDeepLevel = nDeepLevel;
}

bool ManifestFragment::CanGoDeeper(void)
{
	return (m_nDeepLevel < m_nMaxDeepLevel);
}

wstring ManifestFragment::GetDirPattern(bool bPublicToken /* = true */, bool bArch /* = true */, bool bVersion /* = true */, bool bLang /* = true */, bool bPolicy /* = false */) const
{
	wstring sPattern(L"");

	if (bArch && !m_sArch.empty()) {		
		sPattern += m_sArch;		
	}
	else sPattern += L"*";
	
	if (bPolicy) {
		sPattern += L"_policy*";
	}
	else sPattern += L"_";	
	
	sPattern += m_sName;		
	sPattern += L"_";

	if (bPublicToken && !m_sToken.empty()) {				
		sPattern += m_sToken;
	}
	else sPattern += L"*";

	sPattern += L"_";		

	if (bVersion && !m_sVersion.empty()) {		
		sPattern += m_sVersion;
	}
	else sPattern += L"*";
	
	sPattern += L"_";

	if (m_nOsVersion == ManifestFragment::VISTA) {
		if (bLang) {		
			if (m_sLang.empty()) {
				sPattern += L"none"; //should be none ?? FIXME
			}
			else sPattern += m_sLang;		
		}
		else sPattern += L"*";

		sPattern += L"_*";	
	}
	else sPattern += L"*";	 

	return sPattern;
}

bool ManifestFragment::ResolvePolicy(const wstring& sVersion, vector<wstring>& vFiles, const wstring& sPolicyDir)
{
	assert(!vFiles.empty());
	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2 + 3);		
	vector<wstring>::iterator iter = vFiles.begin();
	SafePublisherManifestFragment pubAssembly;

	sort(vFiles.begin(), vFiles.end(), ManifestFragment::SortByVersionInPath);	

	if (iter != vFiles.end()) { //most recent policy
		msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, m_sPolicyDir + sPolicyDir, *iter);				
		
		if (S_OK != m_xml->LoadFromFile(m_sPolicyDir + sPolicyDir + *iter)) { 
			msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, m_sPolicyDir + sPolicyDir, *iter);					
		}
		else {
			SafePublisherManifestFragment assembly(new PublisherManifestFragment(GetDeepLevel() + 1));		
			assembly->ParseManifest();	

			if (assembly->IsValidPolicy(sVersion)) {
				msgLogger->Print(LOG_LEVEL_2, IDS_VALID_MOST_RECENT_POLICY_FOUND, assembly->GetVersion());			
				pubAssembly = assembly;		
			} 
			else {					
				msgLogger->Print(LOG_LEVEL_2, IDS_MOST_RECENT_POLICY_NOT_MATCH, assembly->GetVersion(), GetVersion(), assembly->GetRedirection());						
			}
			msgLogger->Print(LOG_LEVEL_3, IDS_SEPARATE);
		}

		++iter;
	}
	
	for(; iter != vFiles.end(); ++iter) {			
		msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, m_sPolicyDir + sPolicyDir, *iter);			

		if (S_OK != m_xml->LoadFromFile(m_sPolicyDir + sPolicyDir + *iter)) { 
			msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, m_sPolicyDir + sPolicyDir, *iter);		
			continue;
		}
				
		SafePublisherManifestFragment assembly(new PublisherManifestFragment(GetDeepLevel() + 1));		
		assembly->ParseManifest();	
			
		if (assembly->IsValidPolicy(sVersion)) {
			msgLogger->Print(LOG_LEVEL_2, IDS_VALID_POLICY_FOUND, assembly->GetVersion());						
		} //should we inform about not valid policy
		else {					
			msgLogger->Print(LOG_LEVEL_2, IDS_NO_MATCHING_POLICY, assembly->GetVersion(), assembly->GetRedirection());						
		}
		msgLogger->Print(LOG_LEVEL_3, IDS_SEPARATE);						
	}

	msgLogger->DecIdent(2);
	if (NULL == pubAssembly) {
		return false;
	}

    msgLogger->Print(LOG_LEVEL_1, IDS_FINAL_POLICY_RESOLVED, pubAssembly->GetVersion());	
	msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_POLICY_MAN_INFO, pubAssembly->GetName(), pubAssembly->ToString());	
	m_vAssemblies.push_back(pubAssembly);
	return true;
}

void ManifestFragment::Validate(void) 
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);
	
	if (!Version::IsValid(GetVersion())) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_VERSION_FORMAT, GetVersion(), GetName()); 		
	}

	if (0 != wcscmp(L"win32", GetType().c_str())) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_TYPE_VALUE_FOR_ASSEMBLY, GetName()); 		
	}
	
	const wregex r(L"[0-9a-fA-F]*");
	if (!regex_match(GetToken(), r)) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_TOKEN, GetName()); 		
	}			
}


wstring ManifestFragment::ToString(void) const
{
	wstring sMsg(L"");

	if (MessageLogger::GetLogLevel() > 0) {
		sMsg += L"  Version: ";
		sMsg += m_sVersion;		
		sMsg += L"#CR#  Processor architecture: ";
		sMsg += m_sArch;
	}

	if (MessageLogger::GetLogLevel() > 1) {
		sMsg += L"#CR#  PublicToken: ";
		sMsg += m_sToken;
	}

	if (MessageLogger::GetLogLevel() > 2) {
		sMsg += L"#CR#  Language: ";
		sMsg += (m_sLang.empty() ? L"none" : m_sLang);
	}

	return sMsg;
}

wstring ManifestFragment::GetName(void) const
{
	return m_sName;
}

wstring ManifestFragment::GetToken(void) const
{
	return m_sToken;
}

wstring ManifestFragment::GetArch(void) const
{
	return m_sArch;
}

wstring ManifestFragment::GetVersion(void) const
{
	return m_sVersion;
}

wstring ManifestFragment::GetLang(void) const
{
	return m_sLang;
}

wstring ManifestFragment::GetType(void) const
{
	return m_sType;
}

void ManifestFragment::SetIdentityAttr()
{	
	if (S_OK == m_xml->MoveToAttributeByName(L"name")) {
		m_sName = m_xml->GetValue();
	}
	else m_sName = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"version")) {
		m_sVersion = m_xml->GetValue();
	}
	else m_sVersion = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"type")) {
		m_sType = m_xml->GetValue();
	}
	else m_sType = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"language")) {
		m_sLang = m_xml->GetValue();
	}
	else m_sLang = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"processorArchitecture")) {
		m_sArch = m_xml->GetValue();
	}
	else m_sArch = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"publicKeyToken")) {
		m_sToken = m_xml->GetValue();
	}
	else m_sToken = L"";
}


bool ManifestFragment::SortByVersion(const SafeManifestFragment& fAsm, const SafeManifestFragment& sAsm) 
{
	Version fVersion(fAsm->GetVersion());		
	Version sVersion(sAsm->GetVersion());
		
	return !(fVersion < sVersion);
}

bool ManifestFragment::SortByVersionInPath(const wstring& fFile, const wstring& sFile) 
{
	wstring sFirstVer(L"");
	wstring sSecVer(L"");

	wsmatch m;

	if (m_nOsVersion == ManifestFragment::VISTA) {
		const wregex r(L".*_.*_.*_([0-9]{1,5}\\.[0-9]{1,5}\\.[0-9]{1,5}\\.[0-9]{1,5})_.*_.*\\..*");

		if (regex_match(fFile, m, r)) {
			sFirstVer = wstring(m[1]);
		}

		if (regex_match(sFile, m, r)) {
			sSecVer = wstring(m[1]);
		}
	}
	else {
		const wregex r(L"([0-9]{1,5}\\.[0-9]{1,5}\\.[0-9]{1,5}\\.[0-9]{1,5})\\..*");

		if (regex_match(fFile, m, r)) {
			sFirstVer = wstring(m[1]);
		}

		if (regex_match(sFile, m, r)) {
			sSecVer = wstring(m[1]);
		}
	}
	
	Version fVersion(sFirstVer);		
	Version sVersion(sSecVer);
		
	return !(fVersion < sVersion);
}

void ManifestFragment::FindSimilarAssembly(void)
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2 + 3);	
	int nLogLevel = msgLogger->GetLogLevel();
	
	wstring sAssembly = m_sManifestDir;
	sAssembly += GetDirPattern(true, true, false, false, false);
	sAssembly += L".manifest";

	msgLogger->Print(LOG_LEVEL_1, IDS_CR);
	msgLogger->Print(LOG_LEVEL_2, IDS_TRY_TO_FIND_SIMILAR_ASSEMBLIES, m_sManifestDir, sAssembly);
	
	vector<wstring> vFiles;	
	vector<SafeManifestFragment> vAssemblies;
	vector<wstring>::iterator iter;

	if (File::Find(sAssembly, vFiles)) { //try to find some assemblies
		assert(!vFiles.empty());
		
		for(iter = vFiles.begin(); iter != vFiles.end(); ++iter) {
			msgLogger->SetIdent(GetDeepLevel() * 2 + 4);
			msgLogger->Print(LOG_LEVEL_2, IDS_FOUND_SIMILAR_ASSEMBLY_FILE, *iter);	

			if (S_OK == m_xml->LoadFromFile(m_sManifestDir + *iter)) {
				msgLogger->SetLogLevel(0);
				
				SafeManifestFragment assembly(new AssemblyManifestFragment(GetDeepLevel() + 1));

				assembly->ParseManifest();
				vAssemblies.push_back(assembly);
				msgLogger->SetLogLevel(nLogLevel);
			}
		}		
	}
	else {
		msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_FIND_SIMILAR_ASSEMBLIES);		
	}

	if (!vAssemblies.empty()) {
		sort(vAssemblies.begin(), vAssemblies.end(), ManifestFragment::SortByVersion);	

		msgLogger->Print(LOG_LEVEL_1, IDS_LATEST_ASSEMBLY, vAssemblies[0]->GetName(), vAssemblies[0]->ToString());	
	}

	vFiles.clear();

	msgLogger->SetIdent(GetDeepLevel() * 2 + 3);	
	msgLogger->Print(LOG_LEVEL_2, IDS_TRY_TO_FIND_SIMILAR_ASSEMBLY_POLICY, m_sPolicyDir, sAssembly);

	sAssembly = m_sPolicyDir;
	sAssembly += GetDirPattern(true, true, false, false, true);

	if (m_nOsVersion == ManifestFragment::VISTA) {				
		sAssembly += L".manifest";

		if (!File::Find(sAssembly, vFiles)) { //try to find similar policy files to our lib
			msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_FIND_SIMILAR_ASSEMBLY_POLICY);	
		}
	}	
	else { 
		vector<wstring> vDirs;

		if (File::Find(sAssembly, vDirs, true)) {				
			vector<wstring>::iterator dirIter = vDirs.begin();

			for(; dirIter != vDirs.end(); ++dirIter) {
				vector<wstring> vPolicyFiles;

				if (File::Find(m_sPolicyDir + (*dirIter) + L"\\*.policy", vPolicyFiles)) {
					vector<wstring>::iterator policyIter = vPolicyFiles.begin();

					for(; policyIter != vPolicyFiles.end(); ++policyIter) {
						vFiles.push_back(*dirIter + L"\\" + *policyIter);
					}
				}
				else {
					msgLogger->Print(LOG_LEVEL_1, IDS_NO_POLICY_DIR_FOUND_WINXP, m_sPolicyDir + *iter);			
				}
			}
		}
		else {
			msgLogger->Print(LOG_LEVEL_1, IDS_NO_POLICY_FILE_FOUND_IN_WINSXS);	
		}
	}
	
	vAssemblies.clear();	

	for(iter = vFiles.begin(); iter != vFiles.end(); ++iter) {	
		msgLogger->SetIdent(GetDeepLevel() * 2 + 4);
		msgLogger->Print(LOG_LEVEL_2, IDS_FOUND_SIMILAR_ASSEMBLY_POLICY_FILE, *iter);	

		if (S_OK == m_xml->LoadFromFile(m_sPolicyDir + *iter)) {
			msgLogger->SetLogLevel(0);
			
			SafeManifestFragment pubAssembly(new PublisherManifestFragment(GetDeepLevel() + 1));

			pubAssembly->ParseManifest();
			vAssemblies.push_back(pubAssembly);
			msgLogger->SetLogLevel(nLogLevel);
		}
	}	

	if(!vAssemblies.empty()) { //latest policy
		sort(vAssemblies.begin(), vAssemblies.end(), ManifestFragment::SortByVersion);	

		msgLogger->Print(LOG_LEVEL_1, IDS_LATEST_POLICY, vAssemblies[0]->GetName(), vAssemblies[0]->ToString());	
	}	
}

bool ManifestFragment::Filter(const wstring& sFilter)
{
	if (sFilter.empty()) {
		return true;
	}

	const wregex r(sFilter, wregex::icase);

	wstring sStr(m_sArch);
	sStr += L"_" + m_sName;
	sStr += L"_" + m_sToken;
	sStr += L"_" + m_sVersion;
	sStr += L"_" + m_sLang;

	if (regex_match(sStr, r)) {
		return true;
	}
	else {
		return false;
	}
}

void ManifestFragment::SetOsType(int nOsType)
{
	m_nOsVersion = nOsType;
}

void ManifestFragment::Terminate(int nTerminateCode)
{
	m_nTerminateCode = nTerminateCode;
}

int ManifestFragment::GetTerminateCode(void)
{
	return m_nTerminateCode;
}

wstring ManifestFragment::GetPolicyDirectory(void)
{
	return m_sPolicyDir;
}

wstring ManifestFragment::GetManifestDirectory(void)
{
	return m_sManifestDir;
}

int ManifestFragment::GetOsType(void)
{
	return m_nOsVersion;
}

bool ManifestFragment::IsEmptyManifest(void)
{
	return m_bEmpty;
}

void ManifestFragment::SetAppDirectory(const wstring& sDirectory)
{
	m_sAppDir = sDirectory;
}

wstring ManifestFragment::GetAppDirectory(void)
{
	return m_sAppDir;
}


bool ManifestFragment::EqualName(const SafeManifestFragment& a, const SafeManifestFragment& b) 
{
	return a->GetName() == b->GetName();
}

bool ManifestFragment::SortByName(const SafeManifestFragment& a, const SafeManifestFragment& b)
{
	return (wcscmp(a->GetName().c_str(), b->GetName().c_str()) > 0);	
}

