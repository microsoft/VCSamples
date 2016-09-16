#include "StdAfx.h"
#include "File.h"
#include "XMLReader.h"
#include "MessageLogger.h"
#include "ConfigManifestFragment.h"
#include "AssemblyManifestFragment.h"
#include "ApplicationManifestFragment.h"

ApplicationManifestFragment::ApplicationManifestFragment(UINT nDeepLevel, const wstring& sAppName) : 
	ManifestFragment(nDeepLevel), m_sAppName(sAppName)
{
}

ApplicationManifestFragment::~ApplicationManifestFragment(void)
{
}

void ApplicationManifestFragment::Validate(void) 
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);		
	msgLogger->Print(LOG_LEVEL_1, IDS_CR);	

	ManifestFragment::Validate();
}

void ApplicationManifestFragment::ResolveDependicies(void) 
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);		
	msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_APP_MAN_INFO, GetName(), ToString());	
	msgLogger->IncIdent();	
	
	wstring sFileName = m_sAppDir;	
	sFileName += m_sAppName;

	const wregex r(L".*\\.exe", wregex::icase);

	if (!regex_match(m_sAppName, r)) { //dll case		
		sFileName += L".2";
	}
	sFileName += L".config";
	
	if (File::FileExists(sFileName)) { //config file		
		if (S_OK == m_xml->LoadFromFile(sFileName)) { //FIXME
			SafeConfigManfiestFragment assembly(new ConfigManifestFragment(GetDeepLevel() + 1, shared_from_this()));

			msgLogger->Print(LOG_LEVEL_2, IDS_CONFIG_FILE, assembly->GetRedirection());								
			assembly->ParseManifest();			

			msgLogger->SetIdent(GetDeepLevel() * 2 + 1);
			if (assembly->IsInConfig()) { 				
				m_vAssemblies.push_back(assembly); 
				msgLogger->Print(LOG_LEVEL_2, IDS_REDIRECTED_BY_CONFIG, assembly->GetRedirection());								
				return;
			}
			else {						
				msgLogger->Print(LOG_LEVEL_2, IDS_NO_MATCH_IN_CONFIG_FILE, sFileName);								
			}			
		}
		else {			
			msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, sFileName); 			
		}
	}

	msgLogger->DecIdent(2);
	vector<wstring> vFiles;		

	bool bFind = false;
	bool bResolvePolicy = true;
	wstring sPolicyDir(L"");
	
	sFileName = m_sPolicyDir;	
	
	if (m_nOsVersion == ManifestFragment::VISTA) { 		
		sFileName += GetDirPattern(true, true, false, true, true);
		sFileName += L".manifest";
	}
	else { //WinXP 	
		vector<wstring> vDirs;
			
		if (File::Find(m_sPolicyDir + GetDirPattern(true, true, false, true, true), vDirs, true)) { 
			if (1 == vDirs.size()) {
				sFileName += vDirs[0] + L"\\*.policy";
				sPolicyDir = vDirs[0] + L"\\";
			}
			else {
				msgLogger->Print(LOG_LEVEL_1, IDS_TOO_MANY_POLICY_DIRS_WINXP, sFileName);												
				bResolvePolicy = false;
			}
		}
		else { //no policy dir				            
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_POLICY_DIR_FOUND_WINXP, sFileName);										
			bResolvePolicy = false;
		}			
	}

	if (bResolvePolicy) {
		bFind = File::Find(sFileName, vFiles);
				
		msgLogger->SetIdent(GetDeepLevel() * 2 + 1);		
		msgLogger->Print(LOG_LEVEL_2, IDS_TRY_TO_RESOLVE_POLICY, GetName(),sFileName); 
		
		if (bFind) {
			if (ResolvePolicy(GetVersion(), vFiles, sPolicyDir)) {			
				msgLogger->Print(LOG_LEVEL_3, IDS_POLICY_RESOLVED, sFileName);								
				return;
			}
			else { //no matching
				msgLogger->Print(LOG_LEVEL_2, IDS_NO_FILE_MATCH_FOR_POLICY, GetVersion(), sFileName);							
			}	
		}
		else {
			msgLogger->Print(LOG_LEVEL_2, IDS_NO_POLICY_FILE_FOUND); 		
		}
	}
		
	sFileName = m_sManifestDir;		
	sFileName += GetDirPattern();
	sFileName += L".manifest";

	msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_FIND_ASSEMBLY, sFileName);			

	vFiles.clear();
	bFind = File::Find(sFileName, vFiles);

	if (bFind) {
		if (vFiles.size() == 1) {
			msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, m_sManifestDir, vFiles[0]);

			sFileName = m_sManifestDir + vFiles[0];

			if (S_OK == m_xml->LoadFromFile(m_sManifestDir + vFiles[0])) {
				SafeManifestFragment assembly(new AssemblyManifestFragment(GetDeepLevel() + 1));
				assembly->ParseManifest();		
				msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_MAN_INFO, assembly->GetName(), assembly->ToString());
				m_vAssemblies.push_back(assembly);
			}
			else {				
				msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, sFileName);
			}
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
		msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_FIND_LOCAL_ASSEMBLIES);				
		
		if (!SearchLocalDir()) {						
			msgLogger->Print(LOG_LEVEL_2, IDS_NO_LOCAL_ASSEMBLIES_FOUND, ToString());		
			msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLY_FOUND, GetName());
			//try to find some similar assemblies (last hope)
			FindSimilarAssembly();			
		}
	}		
}

void ApplicationManifestFragment::ParseManifest()
{	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);
	msgLogger->IncIdent();

	XMLReader::NodeType nodeType = XMLReader::XML_NODE_NONE;	
	m_bEmpty = false;

	msgLogger->Print(LOG_LEVEL_3, IDS_PARSING_XML_ASSEMBLY_FILE);
		
	while (S_OK == m_xml->Read(&nodeType))
    {      
		wstring sTagName = m_xml->GetLocalName();

		if (XMLReader::XML_NODE_ELEMENT == nodeType) {	
			if (3 == m_xml->GetDepth() && 0 == wcscmp(L"assemblyIdentity", sTagName.c_str())) {					
				SafeManifestFragment assembly(new ApplicationManifestFragment(GetDeepLevel() + 1, m_sAppName));						
				assembly->SetIdentityAttr();		
				m_vAssemblies.push_back(assembly);						
				msgLogger->Print(LOG_LEVEL_3, IDS_XML_APP_FOUDED_ASSEMBLY, assembly->GetName());				
			}
		}		
	}

	if (m_vAssemblies.empty()) {
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLY_DEFINITIONS_IN_APP);		
		m_bEmpty = true;
	}

	//inform about duplicate names definitions in manifest file
	vector<SafeManifestFragment> vFake(m_vAssemblies);		
	sort(vFake.begin(), vFake.end(), ManifestFragment::SortByName);	
	vector<SafeManifestFragment>::iterator iter = unique(vFake.begin(), vFake.end(), ManifestFragment::EqualName);

	if (iter != vFake.end()) {
		msgLogger->Print(LOG_LEVEL_1, IDS_APP_THE_SAME_ASSEMBLIES_DEFINED);		
	}

	msgLogger->Print(LOG_LEVEL_3, IDS_XML_ASSEMBLY_PARSED);		
}


bool ApplicationManifestFragment::SearchLocalDir(void)
{
	SafeMessageLogger msgLogger = MessageLogger::GetInstance();

	msgLogger->IncIdent();

	wstring sAssembly(m_sAppDir);
	sAssembly += GetName();
	sAssembly += L".dll";

	bool bLoaded = false;

	if (File::FileExists(sAssembly)) { 		
		msgLogger->Print(LOG_LEVEL_2, IDS_LOCAL_DLL_FOUND, sAssembly);
		
		if (File::LoadFromResource(sAssembly, 2, m_xml)) {
			msgLogger->Print(LOG_LEVEL_3, IDS_MANIFEST_LOADED_FROM_RES, sAssembly);			
			bLoaded = true;
		}
		else {
			msgLogger->Print(LOG_LEVEL_2, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES, sAssembly);					
			msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES_HINT);	
		}
	}
	else {
		msgLogger->Print(LOG_LEVEL_3, IDS_NO_LOCAL_DLL_FOUND, sAssembly);		
	}
	
	if (!bLoaded) {
		sAssembly = m_sAppDir;
		sAssembly += GetName();
		sAssembly += L".manifest";

		if (File::FileExists(sAssembly))  {
			msgLogger->Print(LOG_LEVEL_2, IDS_LOCAL_MANIFEST_FOUND, sAssembly);
			
			if (S_OK != m_xml->LoadFromFile(sAssembly)) {
				msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, sAssembly);				
				return false;
			}	

			bLoaded = true;
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_LOCAL_MANIFEST_FOUND, sAssembly);			
		}
	}
	
	if (!bLoaded) {
		sAssembly = m_sAppDir;
		sAssembly += GetName();
		sAssembly += L"\\";
		sAssembly += GetName();
		sAssembly += L".dll";

		if (File::FileExists(sAssembly)) {		
			msgLogger->Print(LOG_LEVEL_2, IDS_LOCAL_DLL_FOUND, sAssembly);
			
			if (File::LoadFromResource(sAssembly, 2, m_xml)) {
				msgLogger->Print(LOG_LEVEL_3, IDS_MANIFEST_LOADED_FROM_RES, sAssembly);				
				bLoaded = true;
			}
			else {
				msgLogger->Print(LOG_LEVEL_2, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES, sAssembly);				
				msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES_HINT);	
			}
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_LOCAL_DLL_FOUND, sAssembly);			
		}
	}

	if (!bLoaded) {
		sAssembly = m_sAppDir;
		sAssembly += GetName();
		sAssembly += L"\\";
		sAssembly += GetName();
		sAssembly += L".manifest";

		if (File::FileExists(sAssembly))  {
			msgLogger->Print(LOG_LEVEL_2, IDS_LOCAL_MANIFEST_FOUND, sAssembly);
			
			if (S_OK != m_xml->LoadFromFile(sAssembly)) {
				msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, sAssembly);						
				return false;
			}	

			bLoaded = true;
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_LOCAL_MANIFEST_FOUND, sAssembly);
		}
	}

	msgLogger->DecIdent();

	if (!bLoaded) {
		return false;
	}

	//parse assembly manifest
	SafeManifestFragment assembly(new AssemblyManifestFragment(GetDeepLevel() + 1, true));	
	assembly->ParseManifest();

	if (m_sVersion != assembly->GetVersion() ||
			m_sName != assembly->GetName() ||
				m_sToken != assembly->GetToken() ||
					m_sArch != assembly->GetArch()) {
	

		msgLogger->Print(LOG_LEVEL_3, IDS_LOCAL_ASSEMBLY_DONT_MATCH, assembly->GetName(), assembly->GetVersion(), assembly->GetArch(), assembly->GetToken());
		return false;
	}
					
	msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_MAN_INFO, assembly->GetName(), assembly->ToString());
	m_vAssemblies.push_back(assembly);

	return true;
}
