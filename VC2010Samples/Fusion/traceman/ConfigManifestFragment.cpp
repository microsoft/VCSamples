#include "StdAfx.h"
#include "File.h"
#include "MessageLogger.h"
#include "ConfigManifestFragment.h"
#include "AssemblyManifestFragment.h"

ConfigManifestFragment::ConfigManifestFragment(UINT nDeepLevel, SafeManifestFragment assembly) : ManifestFragment(nDeepLevel), m_assembly(assembly), 
	m_bResolvePolicy(true), m_nRedirectIdx(-1)
{
}

ConfigManifestFragment::~ConfigManifestFragment(void)
{
}

void ConfigManifestFragment::ResolveDependicies(void)
{
	if (m_bEmpty) {
		return;
	}

	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);	
		
	vector<wstring> vFiles;
	wstring sFileName(L"");

	msgLogger->IncIdent();	
	msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_CONFIG_MAN_INFO, GetName(), ToString());	
	msgLogger->Print(LOG_LEVEL_1, IDS_REDIRECTION_FROM_CONFIG, GetNewVersion());
	msgLogger->IncIdent();			
	
	if (m_bResolvePolicy) { //(apply!=no)
		bool bResolve = true;
		wstring sPolicyDir(L"");
		sFileName = m_sPolicyDir;

		if (m_nOsVersion == ManifestFragment::VISTA) {			
			sFileName += GetDirPattern(true, true, false, true, true);
			sFileName += L".manifest";
		}
		else { //WinXP case
			vector<wstring> vDirs;
			
			if (File::Find(m_sPolicyDir + GetDirPattern(true, true, false, true, true), vDirs, true)) { 
				if (1 == vDirs.size()) {
					sFileName += vDirs[0] + L"\\*.policy";
					sPolicyDir = vDirs[0] + L"\\";
				}
				else {
					msgLogger->Print(LOG_LEVEL_1, IDS_TOO_MANY_POLICY_DIRS_WINXP, sFileName);								
					bResolve = false;
				}
			}
			else { //no policy dir				
				msgLogger->Print(LOG_LEVEL_3, IDS_NO_POLICY_DIR_FOUND_WINXP, sFileName);								
				bResolve = false;
			}			
		}		

		if (bResolve) {
			msgLogger->Print(LOG_LEVEL_2, IDS_TRY_TO_RESOLVE_POLICY);			
			
			if (File::Find(sFileName, vFiles)) {
				if (ResolvePolicy(GetNewVersion(), vFiles, sPolicyDir)) {						
					msgLogger->Print(LOG_LEVEL_3, IDS_POLICY_RESOLVED);					
					return;
				}
				else {
					msgLogger->Print(LOG_LEVEL_2, IDS_NO_FILE_MATCH_FOR_POLICY, GetNewVersion(), sFileName);
					
				}
			}
			else {
				msgLogger->Print(LOG_LEVEL_2, IDS_NO_POLICY_FILE_FOUND);						
			}
		}
	}
	else {//no resolving policy set in config file		
		msgLogger->Print(LOG_LEVEL_3, IDS_RESOLVING_POLICY_DISABLED_IN_CONFIG);								
	}
	
	sFileName = m_sManifestDir;
	sFileName += GetDirPattern();
	sFileName += L".manifest";
	vFiles.clear();	

	msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_FIND_ASSEMBLY,  sFileName);		
	
	if (File::Find(sFileName, vFiles)) {	

		if (1 == vFiles.size()) {
			msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, m_sPolicyDir, vFiles[0]);

			if (m_xml->LoadFromFile(m_sPolicyDir + vFiles[0]) != S_OK) {
				msgLogger->Print(LOG_LEVEL_2, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, m_sManifestDir, vFiles[0]);				
				return;
			}
			else {
				msgLogger->Print(LOG_LEVEL_3, IDS_LOADED_MANIFEST_FOR_ASSEMBLY, m_sManifestDir, vFiles[0]);				
			}
						
			SafeManifestFragment assembly(new AssemblyManifestFragment(GetDeepLevel() + 1)); //pass the paramter of the
			assembly->ParseManifest();				
			msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_MAN_INFO, assembly->GetName(), assembly->ToString());
			m_vAssemblies.push_back(assembly);		
		}
		else {
			msgLogger->Print(LOG_LEVEL_2, IDS_TOO_MANY_ASSEMBLIES_MATCH_FOUND, sFileName);									
		}
	}
	else { 		
		sFileName = m_sSXSDir;		
		sFileName += GetDirPattern();
		
		if (File::Find(sFileName, vFiles, true)) {
			msgLogger->Print(LOG_LEVEL_1, IDS_THERE_IS_ASSEMBLY_WITHOUT_MANIFEST, sFileName);			
		}

		msgLogger->Print(LOG_LEVEL_2, IDS_ASSEMBLY_MANIFEST_DOES_NOT_EXISTS, m_sManifestDir, GetDirPattern() + L".manifest");		
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLY_FOUND, GetName());
		FindSimilarAssembly();
	}
}

void ConfigManifestFragment::ParseManifest(void)
{		
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);	
	msgLogger->IncIdent();
	
	XMLReader::NodeType nodeType = XMLReader::XML_NODE_NONE;	
	m_bEmpty = true;
	
	int nHits = 0;
	wstring sName(L"");
	wstring sArch(L"");
	wstring sToken(L"");
	wstring sVersion(L"");
	m_bResolvePolicy = true;
	m_vRedirect.clear();
	
	msgLogger->Print(LOG_LEVEL_3, IDS_PARSING_XML_CONFIG_FILE);	
	
	while (S_OK == m_xml->Read(&nodeType))
    {      
		wstring sTagName = m_xml->GetLocalName();

		if (XMLReader::XML_NODE_ELEMENT == nodeType) {	

			if (3 == m_xml->GetDepth() && 0 == wcscmp(L"publisherPolicy", sTagName.c_str())) {
				m_xml->MoveToAttributeByName(L"apply");
				if (0 == wcscmp(m_xml->GetValue().c_str(), L"no")) {
					m_bResolvePolicy = false;
				}				
			}
		
			if (4 == m_xml->GetDepth() && 0 == wcscmp(L"assemblyIdentity", sTagName.c_str())) {					
				m_xml->MoveToAttributeByName(L"name");				
				sName = m_xml->GetValue();

				m_xml->MoveToAttributeByName(L"processorArchitecture");
				sArch = m_xml->GetValue();

				m_xml->MoveToAttributeByName(L"publicKeyToken");
				sToken = m_xml->GetValue();

				//add if equal
				if (sName == m_assembly->GetName() &&					
					sToken == m_assembly->GetToken() &&						
						sArch == m_assembly->GetArch()) {	
					
					if (0 == nHits) {
						SetIdentityAttr();												
					}
					nHits++;					
				}				
			}			

			if (4 == m_xml->GetDepth() && 0 == wcscmp(L"bindingRedirect", sTagName.c_str())) {				
				SetRedirectAttr();			
			}	
		}		
	}
	
	if (nHits == 1) {
		if (m_vRedirect.empty()) { //no redirections defined
			msgLogger->Print(LOG_LEVEL_2, IDS_NO_ASSEMBLY_REDIRECTION);
		}
		else { //find redirection
			vector<RedirectVer>::iterator iter = m_vRedirect.begin();

			for(UINT i = 0; i < m_vRedirect.size(); i++) {
				if (Version::IsInRange(m_assembly->GetVersion(), m_vRedirect[i].sOldVersion))  {					
					m_nRedirectIdx = i;
					m_bEmpty = false;
					break;
				}
			}

			if (m_bEmpty && !m_vRedirect.empty()) { //no matching version
				msgLogger->Print(LOG_LEVEL_2, IDS_ASSEMBLY_IS_NOT_IN_VERISION_RANGE, m_assembly->GetVersion(), GetRedirection());				
			}
		}
	}
	else if (nHits > 1) {
		msgLogger->Print(LOG_LEVEL_2, IDS_TOO_MANY_ASSEMBLY_DEFINITION);			
	}
	msgLogger->Print(LOG_LEVEL_3, IDS_XML_CONFIG_PARSED);
}

void ConfigManifestFragment::Validate(void) 
{	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);	
	
	if (!GetVersion().empty()) {
		msgLogger->Print(LOG_LEVEL_1, IDS_VERSION_TAG_FORBIDDEN_IN_CONFIG, GetName());
	}

	vector<RedirectVer>::const_iterator iter = m_vRedirect.begin();

	for(; iter != m_vRedirect.end(); ++iter) {
		if (!Version::IsValidRange((*iter).sOldVersion)) {
			msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_VERSION_RANGE, GetName(), (*iter).sOldVersion); 		
		}
	}	
}

wstring ConfigManifestFragment::GetDirPattern(bool bPublicToken, bool bArch, bool bVersion, bool bLang, bool bPolicy) const
{
	wstring sPattern(L"");

	if (bArch  && !m_sArch.empty()) {
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

	if (bVersion && !GetNewVersion().empty()) {				
		sPattern += GetNewVersion();
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
	else {
		sPattern += L"*";	
	}

	return sPattern;
}

bool ConfigManifestFragment::IsInConfig(void) const
{
	return !m_bEmpty;	
}

wstring ConfigManifestFragment::GetOldVersion(void) const
{	
	assert(m_nRedirectIdx >= 0 && m_nRedirectIdx < static_cast<int>(m_vRedirect.size()));

	return m_vRedirect[m_nRedirectIdx].sOldVersion;
}

wstring ConfigManifestFragment::GetNewVersion(void) const
{	
	assert(m_nRedirectIdx >= 0 && m_nRedirectIdx < static_cast<int>(m_vRedirect.size()));

	return m_vRedirect[m_nRedirectIdx].sNewVersion;
}

void ConfigManifestFragment::SetRedirectAttr(void)
{
	wstring sOldVersion(L"");
	wstring sNewVersion(L"");

	if (S_OK == m_xml->MoveToAttributeByName(L"oldVersion")) {
		sOldVersion = m_xml->GetValue();
	}

	if (S_OK == m_xml->MoveToAttributeByName(L"newVersion")) {
		sNewVersion = m_xml->GetValue();	
	}

	m_vRedirect.push_back(RedirectVer(sOldVersion, sNewVersion));
}

wstring ConfigManifestFragment::ToString(void) const
{
	wstring sMsg(L"");

	if (MessageLogger::GetLogLevel() > 0) {
		sMsg += L"  Processor architecture: ";
		sMsg += m_sArch;
		
		vector<RedirectVer>::const_iterator iter = m_vRedirect.begin();

		for(; iter != m_vRedirect.end(); ++iter) {
			sMsg += L"#CR#  Redirection: ";
			sMsg += (*iter).sOldVersion;
			sMsg += L" => ";
			sMsg += (*iter).sNewVersion;
		}	
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


wstring ConfigManifestFragment::GetRedirection() const
{
	wstring sResult(L"");	
	vector<RedirectVer>::const_iterator iter = m_vRedirect.begin();

	for(; iter != m_vRedirect.end(); ++iter) {
		sResult += (*iter).sOldVersion;
		sResult += L" => ";
		sResult += (*iter).sNewVersion;
		sResult += L", ";
	}

	if (sResult.size() > 2) {
		sResult = sResult.substr(0, sResult.length() - 2);
	}

	return sResult;
}


