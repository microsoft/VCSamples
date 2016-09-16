#include "StdAfx.h"
#include "File.h"
#include "XMLReader.h"
#include "MessageLogger.h"
#include "PublisherManifestFragment.h"
#include "AssemblyManifestFragment.h"

AssemblyManifestFragment::AssemblyManifestFragment(UINT nDeepLevel, bool bLocal) : ManifestFragment(nDeepLevel), m_bLocal(bLocal)
{
}

AssemblyManifestFragment::~AssemblyManifestFragment(void)
{
}

void AssemblyManifestFragment::ResolveDependicies(void) 
{
	//if you want to resolve assemblies dependicies 
}

/*
	Future options:
	TODO check the hash of the files if nobody has changed them	
*/
void AssemblyManifestFragment::Validate(void)
{
	ManifestFragment::Validate();
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2 + 2);		
	vector<wstring> vDirs;

	wstring sBaseLibDir(m_sSXSDir);
	wstring sDirPattern(L"");

	if (m_bLocal) {
		sBaseLibDir = m_sAppDir;
		sDirPattern = m_sName;
	}
	else sDirPattern = GetDirPattern();
		
	if (File::Find(sBaseLibDir + sDirPattern, vDirs, true)) {
		if (vDirs.size() != 1) {
			msgLogger->Print(LOG_LEVEL_1, IDS_TOO_MANY_ASSEMBLY_DIRS, sBaseLibDir + sDirPattern);		
			return;
		}

		size_t iMaxSize = m_vFiles.size();

		for(size_t i = 0; i < iMaxSize; i++) {
			wstring file(sBaseLibDir + vDirs[0] + L"\\" + m_vFiles[i].sFileName);
		
			if (File::FileExists(sBaseLibDir + vDirs[0] + L"\\" + m_vFiles[i].sFileName)) {
				msgLogger->Print(LOG_LEVEL_3, IDS_DLL_FILE_EXISTS, m_vFiles[i].sFileName, m_vFiles[i].sHash,
							m_vFiles[i].sHashAlg, sBaseLibDir + vDirs[0] + L"\\");												
			}
			else {				
				msgLogger->Print(LOG_LEVEL_1, IDS_DLL_FILE_NOT_EXISTS, m_vFiles[i].sFileName, m_vFiles[i].sHash,
						m_vFiles[i].sHashAlg, sBaseLibDir + vDirs[0] + L"\\");								
			}

			if (0 != wcscmp(L"SHA1", m_vFiles[i].sHashAlg.c_str())) {
				msgLogger->Print(LOG_LEVEL_3, IDS_HASH_ALG_RECOMMENDATION);				
			}
		}

		if (m_vFiles.empty()) {
			msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLY_FILES);		
		}
	}
	else {	
		msgLogger->Print(LOG_LEVEL_1, IDS_ASSEMBLY_DIR_NOT_EXISTS, sBaseLibDir, sDirPattern);				
	}	
}

void AssemblyManifestFragment::ParseManifest(void) 
{	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(GetDeepLevel() * 2);
	XMLReader::NodeType nodeType = XMLReader::XML_NODE_NONE;
	m_bEmpty = false;

	msgLogger->IncIdent();
	msgLogger->Print(LOG_LEVEL_3, IDS_PARSING_XML_ASSEMBLY_FILE); 	

	int nHits = 0;
	m_vFiles.clear();
	
	while (S_OK == m_xml->Read(&nodeType))
    {      
		wstring sTagName = m_xml->GetLocalName();	
		
		if (XMLReader::XML_NODE_ELEMENT == nodeType) {	
								
				if (1 == m_xml->GetDepth() && 0 == wcscmp(L"assemblyIdentity", sTagName.c_str())) {
					SetIdentityAttr();
					nHits++;
				}				

				if (1 == m_xml->GetDepth() && 0 == wcscmp(L"file", sTagName.c_str())) {	
					wstring sName(L"");
					wstring sHashAlg(L"");
					wstring sHash(L"");

					if (S_OK == m_xml->MoveToAttributeByName(L"name")) {
						sName = m_xml->GetValue();						
					}

					if (S_OK == m_xml->MoveToAttributeByName(L"hashalg")) {
						sHashAlg = m_xml->GetValue();
					}
					
					if (S_OK == m_xml->MoveToAttributeByName(L"hash")) {
						sHash = m_xml->GetValue();
					}
					
					m_vFiles.push_back(FileInfo(sName, sHash, sHashAlg));
				}				
		}	//end of if	
	}	//end of while
		
	if (nHits == 0) {
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLY_DEFINITION_IN_XML);				
		m_bEmpty = true;
	}
	else if (nHits > 1) {
		msgLogger->Print(LOG_LEVEL_2, IDS_TOO_MANY_ASSEMBLY_DEFINITION);				
	}

	msgLogger->Print(LOG_LEVEL_3, IDS_XML_ASSEMBLY_PARSED);	
}

wstring AssemblyManifestFragment::ToString(void) const
{
	wstring sResult = ManifestFragment::ToString();

	if (MessageLogger::GetLogLevel() > 1) {

		vector<wstring> vDirs;
		wstring sBaseLibDir(m_sSXSDir);
		wstring sDirPattern(L"");

		if (m_bLocal) {
			sBaseLibDir = m_sAppDir;
			sDirPattern = m_sName;
		}
		else sDirPattern = GetDirPattern();
		
		if (File::Find(sBaseLibDir + sDirPattern, vDirs, true)) {
			sResult += L"#CR#  Path: ";	
			sResult += sBaseLibDir + vDirs[0] + L"\\";			
		}		
	}

	if (MessageLogger::GetLogLevel() > 2) {

		vector<FileInfo>::const_iterator iter = m_vFiles.begin();

		for(; iter != m_vFiles.end(); ++iter) {
			sResult += L"#CR#  File: ";
			sResult += (*iter).sFileName;	
			sResult += L" HashAlg: ";
			sResult += ((*iter).sHashAlg.empty() ? L"empty" : (*iter).sHashAlg);
			sResult += L" Hash: ";
			sResult += ((*iter).sHash.empty() ? L"empty" : (*iter).sHash);			
		}
	}
	return sResult;
}
