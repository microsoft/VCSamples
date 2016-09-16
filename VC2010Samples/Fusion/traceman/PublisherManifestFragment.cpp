#include "StdAfx.h"

#include "File.h"
#include "Version.h"
#include "XMLReader.h"
#include "MessageLogger.h"
#include "AssemblyManifestFragment.h"
#include "PublisherManifestFragment.h"

PublisherManifestFragment::PublisherManifestFragment(UINT nDeepLevel) : ManifestFragment(nDeepLevel), 
	m_sRdcName(L""), m_sRdcVersion(L""), m_sRdcLang(L""), m_sRdcArch(L""), m_sRdcToken(L""),
	m_sRdcType(L""), m_nRedirectIdx(-1)
{
}

PublisherManifestFragment::~PublisherManifestFragment()
{

}

void PublisherManifestFragment::ResolveDependicies(void) 
{	
	if (m_bEmpty) {
		return;
	}

	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);
	
	msgLogger->IncIdent();
	vector<wstring> vFiles;

	wstring sFileName(m_sManifestDir);
	sFileName += GetDirPattern();
	sFileName += L".manifest";

	msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_FIND_ASSEMBLY, sFileName);
			
	if (File::Find(sFileName, vFiles))  { 
		
		if (1 == vFiles.size()) {
			msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, m_sManifestDir, vFiles[0]);

			if (m_xml->LoadFromFile(m_sManifestDir + vFiles[0]) != S_OK) {
				msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, ToString(), sFileName); 			
				return;
			}
			
			SafeManifestFragment assembly(new AssemblyManifestFragment(GetDeepLevel() + 1)); 			
			assembly->ParseManifest();			
			msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_MAN_INFO, assembly->GetName(), assembly->ToString());
			m_vAssemblies.push_back(assembly);
		}
		else {
			msgLogger->Print(LOG_LEVEL_2, IDS_TOO_MANY_ASSEMBLIES_MATCH_FOUND, sFileName);			
		}
	}
	else { //cannot find the library
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

void PublisherManifestFragment::ParseManifest(void) 
{	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);	
	XMLReader::NodeType nodeType = XMLReader::XML_NODE_NONE;		
	m_bEmpty = false;

	msgLogger->IncIdent();
	msgLogger->Print(LOG_LEVEL_3, IDS_PARSING_XML_ASSEMBLY_FILE);	

	int nHits = 0;
	m_vRedirect.clear();
	
	while (S_OK == m_xml->Read(&nodeType))
    {      
		wstring sTagName = m_xml->GetLocalName();
	
		if (XMLReader::XML_NODE_ELEMENT == nodeType) { //check if there is more than one definition
			if (1 == m_xml->GetDepth() && 0 == wcscmp(L"assemblyIdentity", sTagName.c_str())) {					
				SetIdentityAttr();
				nHits++;
			}

			if (3 == m_xml->GetDepth() && 0 == wcscmp(L"assemblyIdentity", sTagName.c_str())) {
				SetRdcIdentityAttr();					
			}

			if (3 == m_xml->GetDepth() && 0 == wcscmp(L"bindingRedirect", sTagName.c_str())) {
				SetRedirectAttr();										
			}						
		}		
	}
			
	if (nHits > 1) {	
		msgLogger->Print(LOG_LEVEL_1, IDS_TOO_MANY_ASSEMBLY_DEFINITION);							
	}
	else if (nHits <= 0) {
		msgLogger->Print(LOG_LEVEL_2, IDS_NO_ASSEMBLY_DEFINITION_IN_XML);		
		m_bEmpty = true;		
	}

	msgLogger->Print(LOG_LEVEL_3, IDS_XML_ASSEMBLY_PARSED);	
}

bool PublisherManifestFragment::IsValidPolicy(const wstring& sFileNameVersion)
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance();

	if (m_vRedirect.empty()) {
		msgLogger->Print(LOG_LEVEL_2, IDS_NO_ASSEMBLY_REDIRECTION);		
		return false;
	}
	
	int nHits = 0;
	
	for(UINT i = 0; i < m_vRedirect.size(); i++) {
		if (!Version::IsValid(m_vRedirect[i].sNewVersion)) {  
			msgLogger->Print(LOG_LEVEL_3, IDS_INVALID_NEW_VERSION_FORMAT, m_vRedirect[i].sNewVersion);			
		}

		if (Version::IsInRange(sFileNameVersion, m_vRedirect[i].sOldVersion)) {			
			m_nRedirectIdx = i;	
			nHits++;
		}
	}

	if (1 == nHits) {
		return true;
	}
	else if (nHits > 1) { //to many matching redirection
		msgLogger->Print(LOG_LEVEL_2, IDS_TOO_MANY_MATCHING_VERSIONS_POLICY);		
	}
	
	return false;
}

wstring PublisherManifestFragment::GetDirPattern(bool bPublicToken /* = true */, bool bArch /* = true */, bool bVersion /* = true */, bool bLang /* = true */, bool bPolicy /* = false */) const
{
	wstring sPattern(L"");

	if (bArch && !m_sRdcArch.empty()) {
		sPattern += m_sRdcArch;
	}
	else sPattern += L"*";

	if (bPolicy) {
		sPattern += L"_policy*";
	}
	else sPattern += L"_";	
	
	sPattern += m_sRdcName;		
	sPattern += L"_";

	if (bPublicToken && !m_sRdcToken.empty()) {		
		sPattern += m_sRdcToken;		
	}
	else sPattern += L"*";

	sPattern += L"_";		

	if (bVersion && !GetNewVersion().empty()) {
		sPattern += GetNewVersion();
	}
	else sPattern += L"*";
	
	sPattern += L"_";

	if (bLang && m_nOsVersion == ManifestFragment::VISTA) {		
		if (m_sRdcLang.empty()) {
			sPattern += L"none"; //should be none ?? FIXME
		}
		else sPattern += m_sRdcLang;		
	}
	else sPattern += L"*";

	sPattern += L"_*";	
	return sPattern;
}

wstring PublisherManifestFragment::GetRdcName(void) const
{
	return m_sRdcName;
}

wstring PublisherManifestFragment::GetRdcToken(void) const
{
	return m_sRdcToken;
}

wstring PublisherManifestFragment::GetRdcVersion(void) const
{
	return m_sRdcVersion;
}

wstring PublisherManifestFragment::GetRdcArch(void) const
{
	return m_sRdcArch;
}

wstring PublisherManifestFragment::GetRdcType(void) const
{
	return m_sRdcType;
}

wstring PublisherManifestFragment::GetRdcLang(void) const
{
	return m_sRdcLang;
}

wstring PublisherManifestFragment::GetOldVersion(void) const
{	
	assert(m_nRedirectIdx >= 0 && m_nRedirectIdx < static_cast<int>(m_vRedirect.size()));

	return m_vRedirect[m_nRedirectIdx].sOldVersion;
}

wstring PublisherManifestFragment::GetNewVersion(void) const
{	
	assert(m_nRedirectIdx >= 0 && m_nRedirectIdx < static_cast<int>(m_vRedirect.size()));

	return m_vRedirect[m_nRedirectIdx].sNewVersion;
}

void PublisherManifestFragment::SetRdcIdentityAttr(void)
{	
	if (S_OK == m_xml->MoveToAttributeByName(L"name")) {
		m_sRdcName = m_xml->GetValue();
	}
	else m_sRdcName = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"version")) {
		m_sRdcVersion = m_xml->GetValue();
	}
	else m_sRdcVersion = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"type")) {
		m_sRdcType = m_xml->GetValue();
	}
	else m_sRdcType = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"language")) {
		m_sRdcLang = m_xml->GetValue();
	}
	else m_sRdcLang = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"processorArchitecture")) {
		m_sRdcArch = m_xml->GetValue();
	}
	else m_sRdcArch = L"";

	if (S_OK == m_xml->MoveToAttributeByName(L"publicKeyToken")) {
		m_sRdcToken = m_xml->GetValue();
	}
	else m_sRdcToken = L"";
}

void PublisherManifestFragment::SetRedirectAttr(void)
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

wstring PublisherManifestFragment::ToString(void) const
{
	wstring sMsg(L"");

	if (MessageLogger::GetLogLevel() > 0) {
		sMsg += L"  Processor architecture: ";
		sMsg += m_sArch;
		sMsg += L"#CR#  Version: ";
		sMsg += GetVersion();

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

void PublisherManifestFragment::Validate(void) 
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);
	
	if (!Version::IsValid(GetVersion())) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_VERSION_FORMAT, GetVersion(), GetName()); 		
	}
	
	vector<RedirectVer>::const_iterator iter = m_vRedirect.begin();

	for(; iter != m_vRedirect.end(); ++iter) {
		if (!Version::IsValidRange((*iter).sOldVersion)) {
			msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_VERSION_RANGE, GetName(), (*iter).sOldVersion); 		
		}
	}	

	if (0 != wcscmp(L"win32-policy", GetType().c_str())) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_TYPE_VALUE_FOR_POLICY, GetName()); 		
	}

	const wregex r(L"[0-9a-fA-F]*");
	if (!regex_match(GetToken(), r)) {
		msgLogger->Print(LOG_LEVEL_1, IDS_INVALID_TOKEN, GetName()); 		
	}	
}

bool PublisherManifestFragment::IsOverlapping(SafePublisherManifestFragment& assembly)
{
	vector<RedirectVer>::iterator iter = m_vRedirect.begin();
	vector<RedirectVer>::iterator inner = assembly->m_vRedirect.begin();
	
	for( ;iter != m_vRedirect.end(); ++iter) {
		
		for(; inner != assembly->m_vRedirect.end(); ++inner) {
			wstring sOut = (*inner).sOldVersion;
			std::string::size_type pos = sOut.find(L"-");

			if (std::string::npos == pos) {
				if (Version::IsInRange(sOut, (*iter).sOldVersion)) {
					return true;
				}
			}
			else {
				if (Version::IsInRange(sOut.substr(0, pos), (*iter).sOldVersion) ||
						Version::IsInRange(sOut.substr(pos + 1), (*iter).sOldVersion)) {
					return true;
				}
			}
		}	
	}
		
	return false;		
}

wstring PublisherManifestFragment::GetRedirection() const
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