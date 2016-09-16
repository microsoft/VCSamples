// traceman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "debug.h"
#include "traceman.h"

#include "File.h"
#include "XMLReader.h"
#include "ParamParser.h"
#include "MessageLogger.h"
#include "AssemblyManifestFragment.h"
#include "PublisherManifestFragment.h"
#include "ApplicationManifestFragment.h"

int wmain(int argc, wchar_t* argv[])
{	
	SafeMessageLogger msgLogger;
	wstring sFilter(L""); //filter mask
	wstring sOutputFile(L""); //output file name if save to file
	wstring sFormat(L""); //output format console or html
	bool bMode = false; //if dump(true) or trace(false)
	wstring sTargetName(L"");
	wstring sTargetDir(L"");
	int nResult = 0;
	bool bHelp = false;
	int nLogLevel = 2;

	if (argc > 1) { //check the params
		shared_ptr<ParamParser> param(new ParamParser());
		param->Parse(argv, argc); 

		while(param->IsNext()) { 	
			switch(param->GetParamId()) {
				case 1: //help
					if (bHelp) break;

					if (param->IsParamSet()) {
						bHelp = true;
					}		
					break;
				case 2://dump  
					if (param->IsParamSet()) {
						bMode = true;
					}
					break;
				case 3: //verbose (0-3)
					if (param->IsParamSet()) {
						nLogLevel = param->GetParamValueAsInt();					
					}
					break;
				case 4: //filter  
					if (param->IsParamSet()) {
						sFilter = param->GetParamValueAsString();																
					}
					break;
				case 5: //format //html etc.
					sFormat = param->GetParamValueAsString();
					break;
				case 6: //output //file etc
					sOutputFile = param->GetParamValueAsString();
					break;
				case 7: //regex
					if (!param->IsParamSet()) {						
						sFilter = quote_regex(sFilter);
					}
					break;
				default:
					assert(false); //some param is not defined
			}

			param->Next();
		}	
	}
	else {
		bHelp = true;
	}

	//set logger object
	if (sOutputFile.empty()) { //console
		msgLogger = MessageLogger::GetInstance(0, MessageLogger::CONSOLE_MESSAGE_HANDLER);
	}
	else { //file message logger
		msgLogger = MessageLogger::GetInstance(0, MessageLogger::FILE_MESSAGE_HANDLER, sOutputFile);		
	}

	MessageLogger::SetLogLevel(nLogLevel);

	if (bHelp) {
		msgLogger->Print(LOG_LEVEL_0, IDS_MICROSOFT_LOGO);
		msgLogger->Print(LOG_LEVEL_0, IDS_CMD_LINE_HELP_MSG);
		return IDS_CMD_LINE_HELP_MSG;	
	}  

	//check the windows version
	if (GetWinVersion() < 5) {
		msgLogger->Print(LOG_LEVEL_0, IDS_MICROSOFT_LOGO);
		msgLogger->Print(LOG_LEVEL_0, IDS_UNSUPPORTED_OPERATING_SYSTEM);		
		return IDS_UNSUPPORTED_OPERATING_SYSTEM;
	}

	ManifestFragment::SetMaxDeepLevel(MAX_ASSEMBLY_DEEP); 
	msgLogger->Print(LOG_LEVEL_1, IDS_MICROSOFT_LOGO);

	//check if XMLLite is installed on this OS
	if (NULL == LoadXMLLite()) {
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_XMLLITE_INSTALLED);
		msgLogger->Print(LOG_LEVEL_1, IDS_XMLLITE_INSTLLATION_HINT);
		return IDS_NO_XMLLITE_INSTALLED;
	}

	if (!SetSXSDirs()) { //set the winsxs dirs
		msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_SET_WINSXS_DIR);		
		return IDS_CAN_NOT_SET_WINSXS_DIR;
	}

	try {
		const wregex r(sFilter);
	} catch(...) {
		msgLogger->Print(LOG_LEVEL_1, IDS_WRONG_FILTER_EXP, sFilter);			
		return IDS_WRONG_FILTER_EXP;
	}	

	DWORD dwVersion = GetWinVersion(false);
	int nMajor = static_cast<int>(LOBYTE(LOWORD(dwVersion)));
	int nMinor = static_cast<int>(HIBYTE(LOWORD(dwVersion)));
	int nBuild = 0;

	if (dwVersion < 0x80000000)              
		nBuild = static_cast<int>(HIWORD(dwVersion));

	msgLogger->Print(LOG_LEVEL_3, IDS_OS_INFO, IntToStr(nMajor), IntToStr(nMinor), IntToStr(nBuild));		
	msgLogger->Print(LOG_LEVEL_3, IDS_SYSTEM_ARCH_INFO, GetSystemArch());

	SafeXMLReader xmlReader(new XMLReader);
	xmlReader->SetProperty(XmlReaderProperty_DtdProcessing, DtdProcessing_Prohibit);
	ManifestFragment::m_xml = xmlReader;

	if (bMode) { //dump mode
		if(0 == MessageLogger::GetLogLevel()) {
			MessageLogger::SetLogLevel(1);
		}
		
		if (sFilter.empty()) {
			sFilter = L".*";
		}

		nResult = dump(sFilter);
		msgLogger->SummaryError(true);
	}
	else { //trace mode
		sTargetName = argv[argc - 1];			
		std::wstring::size_type nPos = sTargetName.find_last_of(L"\\");
		
		if (nPos == std::wstring::npos) { //try to find real path
			WCHAR szBuff[MAX_PATH];
			
			if (GetCurrentDirectoryW(MAX_PATH, szBuff) > 0) {
				sTargetDir = wstring(szBuff) + L"\\";				
			}
		}
		else { 
			nPos++;
			sTargetDir = sTargetName.substr(0, nPos);
			sTargetName = sTargetName.substr(nPos);
		}
				
		if(!File::FileExists(sTargetDir + sTargetName)) {
			msgLogger->Print(LOG_LEVEL_1, IDS_TARGET_FILE_DOES_NOT_EXISTS, sTargetDir, sTargetName);			
			return IDS_TARGET_FILE_DOES_NOT_EXISTS;
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_TARGET_FILE_EXISTS, sTargetDir, sTargetName);						
		}

		ManifestFragment::SetAppDirectory(sTargetDir);	
		nResult = load(sTargetName);
		if (!nResult) {			
			nResult = trace(sTargetName, sFilter);	
			msgLogger->SummaryError(true);
		}	
	}

	return nResult;
}


int trace(const std::wstring& sAppName, const wstring& sFilter) {
	SafeMessageLogger msgLogger = MessageLogger::GetInstance();	

	list<SafeManifestFragment> vAssemblies;
	bool bShow = false;
	bool bFilter = false;
	bool bLibFilter = false;

	SafeManifestFragment parentAssembly(new ApplicationManifestFragment(0, sAppName));
	parentAssembly->ParseManifest();
	
	size_t iCount = parentAssembly->GetAssemblyCount();	
	for(size_t i = 0; i < iCount; i++) {
		vAssemblies.push_back(parentAssembly->GetAssembly(i));
	}

	while(!vAssemblies.empty()) { //process the assemblies
		SafeManifestFragment assembly(vAssemblies.front()); 
		vAssemblies.pop_front();				

#ifdef VC_LIBS_FILTER		
		if (!assembly->Filter(VC_LIBS_FILTER)) {	
			bLibFilter = true;
			continue;
		}
#endif
		if (!assembly->Filter(sFilter)) {
			bFilter = true;
			continue;
		}		

		assembly->Validate();

		if (!assembly->CanGoDeeper()) {
			continue;
		}

		bShow = true;

		assembly->ResolveDependicies();
				
		
		if (assembly->GetTerminateCode() > 0) {
			return assembly->GetTerminateCode();
		}

		size_t iAssemblyCount = assembly->GetAssemblyCount();
	
		for(size_t i = 0; i < iAssemblyCount; i++) {
			vAssemblies.push_front(assembly->GetAssembly(i));
		}				
	}

	if (parentAssembly->IsEmptyManifest()) { //can't use this one
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLIES_RESOLVED); 
	}
	else if (!bShow) {		
		if (bLibFilter && !bFilter) {
			msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_NO_RESULTS); 
		}
		else {
			msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_ALL_FILTERED, sFilter);
		}
	}

	return msgLogger->GetErrorNr();
}


bool SetSXSDirs() 
{
	DWORD dwVer = GetWinVersion();
	
	if (dwVer >= 5) { //vista an higher		
		WCHAR szBuff[MAX_PATH];

		if (!GetSystemWindowsDirectoryW(szBuff ,MAX_PATH)) {
			return false;
		}

		wstring sWinPath(szBuff);		

		if (dwVer == 5) { //set for winXP and 2k3			
			ManifestFragment::SetOsType(ManifestFragment::WINXP);
			ManifestFragment::SetWinSxSDirectory(sWinPath + L"\\winsxs\\");
			ManifestFragment::SetPolicyDirectory(sWinPath + L"\\winsxs\\Policies\\");
			ManifestFragment::SetManifestDirectory(sWinPath + L"\\winsxs\\Manifests\\");
		}
		else { //set for vista and higher
			ManifestFragment::SetOsType(ManifestFragment::VISTA);
			ManifestFragment::SetWinSxSDirectory(sWinPath + L"\\winsxs\\");
			ManifestFragment::SetPolicyDirectory(sWinPath + L"\\winsxs\\Manifests\\");
			ManifestFragment::SetManifestDirectory(sWinPath + L"\\winsxs\\Manifests\\");
		}
		return true;
	}
	else { //there should not be this situation
		assert(false);
		return false;
	}
}

int dump(const wstring& sFilter) 
{
	bool bLibFilter = false;
	bool bShow = false;
	bool bFilter = false;
	SafeMessageLogger msgLogger = MessageLogger::GetInstance();	

	msgLogger->Print(LOG_LEVEL_2, IDS_DUMP_WINSXS_DIR);

	vector<wstring> vFiles;
	vector<wstring>::iterator iter;
		
	if (!File::Find(ManifestFragment::GetManifestDirectory() + L"*.manifest" ,vFiles)) {
		msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_NO_MANIFESTS_FOUND);		
		return IDS_DUMP_NO_MANIFESTS_FOUND;
	}

	if (ManifestFragment::GetOsType() == ManifestFragment::WINXP) {
		msgLogger->Print(LOG_LEVEL_2, IDS_DUMP_WINXP_WINSXS_POLICY);

		vector<wstring> vPolicyDirs;
		vector<wstring>::iterator iter;

		if (!File::Find(ManifestFragment::GetPolicyDirectory() + L"*" , vPolicyDirs, true)) { //FIXME
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_POLICY_FILE_FOUND_IN_WINSXS);			
		}

		for(iter = vPolicyDirs.begin(); iter != vPolicyDirs.end(); ++iter) {
			vector<wstring> vPolicyFiles;

			if (File::Find(ManifestFragment::GetPolicyDirectory() + (*iter) + L"\\*.policy", vPolicyFiles)) {
				vector<wstring>::iterator fileIter = vPolicyFiles.begin();

				for(; fileIter != vPolicyFiles.end(); ++fileIter) {
					vFiles.push_back(*iter + L"\\" + *fileIter);
				}
			}
			else { //empty policy directory				
				msgLogger->Print(LOG_LEVEL_2, IDS_EMPTY_POLICY_DIR_WINXP, ManifestFragment::GetPolicyDirectory(), *iter);			
			}
		}
	}	
	else { //check policies for winxp
		vector<wstring> vFake;

		if (!File::Find(ManifestFragment::GetPolicyDirectory() + L"*policy*.manifest", vFake)) {
			msgLogger->Print(LOG_LEVEL_3, IDS_NO_POLICY_FILE_FOUND_IN_WINSXS);			
		}
	}

	SafeManifestFragment assembly(new AssemblyManifestFragment(0));
	SafeManifestFragment publisherAssembly(new PublisherManifestFragment(0));

	for(iter = vFiles.begin(); iter != vFiles.end(); ++iter) {				
	
#ifdef VC_LIBS_FILTER	
		const wregex vcr(VC_LIBS_FILTER, wregex::icase);
	
		if (!regex_match(*iter, vcr)) {			
				bLibFilter = true;
				continue;
		}
#endif
		if (!sFilter.empty()) {				
			const wregex r(sFilter, wregex::icase);

			if (!regex_match(*iter, r)) {
				bFilter = true;
				continue;
			}
		} 

		const wregex policyRegex(L".*policy.*", wregex::icase);

		msgLogger->SetIdent(1);
		if (regex_match(*iter, policyRegex)) { 					
			msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, ManifestFragment::GetPolicyDirectory(), *iter);		
			
			if (S_OK != ManifestFragment::m_xml->LoadFromFile(ManifestFragment::GetPolicyDirectory() + *iter)) {
				msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, ManifestFragment::GetPolicyDirectory(), *iter);				
			}
			else {	
				publisherAssembly->ParseManifest();				
				msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_ASSEMBLY_INFO, publisherAssembly->ToString(), publisherAssembly->GetName());
				publisherAssembly->Validate();					
			}			
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, ManifestFragment::GetManifestDirectory(), *iter);		

			if (S_OK != ManifestFragment::m_xml->LoadFromFile(ManifestFragment::GetManifestDirectory() + *iter)) { 
				msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, ManifestFragment::GetManifestDirectory(), *iter);				
			}
			else {									
				assembly->ParseManifest();										
				msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_ASSEMBLY_INFO, assembly->ToString(), assembly->GetName());				
				assembly->Validate();								
			}	
		}	
		msgLogger->Print(LOG_LEVEL_1, IDS_CR);	
		bShow = true;
	}

	if (vFiles.empty()) { 
		msgLogger->Print(LOG_LEVEL_1, IDS_NO_ASSEMBLIES_IN_WINSXS); 
	}
	else if (!bShow) {		
		if (bLibFilter && !bFilter) {
			msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_NO_RESULTS); 
		}
		else {
			msgLogger->Print(LOG_LEVEL_1, IDS_DUMP_ALL_FILTERED, sFilter);
		}
	}

	msgLogger->Print(LOG_LEVEL_2, IDS_DUMP_WINSXS_DIR_ENDED);	
	return false;
}

int load(const wstring& sAppName) 
{	
	SafeMessageLogger msgLogger = MessageLogger::GetInstance(0);		
	wstring sFileName = sAppName;
	bool bExeFile = false;

	const wregex rext(L".*\\.manifest|.*\\.exe|.*\\.dll", wregex::icase);

	if (!regex_match(sAppName, rext)) {
		msgLogger->Print(LOG_LEVEL_1, IDS_WRONG_EXTENSION, ManifestFragment::GetAppDirectory(), sAppName);
		return IDS_WRONG_EXTENSION;
	}

	const wregex rex(L".*\\.exe", wregex::icase);
	if (regex_match(sAppName, rex)) {
		bExeFile = true;
	}
	else {
		sFileName += L".2";
	}

	const wregex r(L".*\\.manifest", wregex::icase);

	if (regex_match(sAppName, r)) {
		msgLogger->Print(LOG_LEVEL_3, IDS_ASSEMBLY_MANIFEST_FILE, ManifestFragment::GetAppDirectory(), sAppName);		
		
		if (S_OK != ManifestFragment::m_xml->LoadFromFile(ManifestFragment::GetAppDirectory() + sAppName)) {			
			msgLogger->Print(LOG_LEVEL_1, IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE, ManifestFragment::GetAppDirectory(), sAppName);		
			return IDS_CAN_NOT_LOAD_MANIFEST_FROM_FILE;
		}	
	}
	else {		
		bool bExternalExists = false;
		bool bInternalExists = false;

		if (File::FileExists(ManifestFragment::GetAppDirectory() + sFileName + L".manifest")) {
			bExternalExists = true;
		}

		if (File::LoadFromResource(ManifestFragment::GetAppDirectory() + sAppName, (bExeFile ? 1 : 2), ManifestFragment::m_xml)) {
			bInternalExists = true;
		}
		
		if (5 == GetWinVersion()) { //depending on the system
			msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_LOAD_EXTERNAL_MANIFEST, ManifestFragment::GetAppDirectory(), sFileName);

			if (bExternalExists && bInternalExists) {
				msgLogger->Print(LOG_LEVEL_2, IDS_WINXP_ORDER_MANIFEST_WARNING, ManifestFragment::GetAppDirectory(), sFileName, sAppName);
				msgLogger->Print(LOG_LEVEL_1, IDS_USING_EXTERNAL_MAN, ManifestFragment::GetAppDirectory() + sFileName);
			}
			else if (!bExternalExists && !bInternalExists) {
				msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES_HINT);
				//try to load manifest with switched id
				if (File::LoadFromResource(ManifestFragment::GetAppDirectory() + sAppName, (bExeFile ? 2 : 1), ManifestFragment::m_xml)) {					
					msgLogger->Print(LOG_LEVEL_1, IDS_WRONG_SWITCHED_RES_ID, ManifestFragment::GetAppDirectory(), sFileName);					
					return IDS_WRONG_SWITCHED_RES_ID;
				}

				//try to load from another id
				msgLogger->Print(LOG_LEVEL_1, IDS_NO_EXTERNAL_INTERNAL_MAN_FOUND, ManifestFragment::GetAppDirectory(), sFileName, sAppName);					
				return IDS_NO_EXTERNAL_INTERNAL_MAN_FOUND;
			}
			else if (bExternalExists) {
				//load external one
				if (S_OK != ManifestFragment::m_xml->LoadFromFile(ManifestFragment::GetAppDirectory() + sFileName + L".manifest")) {
					msgLogger->Print(LOG_LEVEL_1, IDS_CANNOT_LOAD_EXTERNAL_MAN, ManifestFragment::GetAppDirectory(), sFileName);					
					return IDS_CANNOT_LOAD_EXTERNAL_MAN;
				}
				else msgLogger->Print(LOG_LEVEL_1, IDS_LOADED_EXTERNAL_MANIFEST_FILE, ManifestFragment::GetAppDirectory(), sAppName);
			}
			else if (bInternalExists) { //Internal one
				msgLogger->Print(LOG_LEVEL_1, IDS_USING_EMBEDED_MAN_ONLY, ManifestFragment::GetAppDirectory() + sAppName);					
			}
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_TRY_TO_LOAD_MANIFEST_FROM_RES, ManifestFragment::GetAppDirectory(), sAppName);			

			if (bExternalExists && bInternalExists) { //two manifest
				msgLogger->Print(LOG_LEVEL_2, IDS_TWO_MANIFEST_FOUND, ManifestFragment::GetAppDirectory(), sFileName, sAppName);
				msgLogger->Print(LOG_LEVEL_1, IDS_USING_EMBEDED_MAN, ManifestFragment::GetAppDirectory(), sFileName, sAppName);
			}
			else if (!bExternalExists && !bInternalExists) {
				msgLogger->Print(LOG_LEVEL_3, IDS_CAN_NOT_LOAD_MANIFEST_FROM_RES_HINT);
				//try to load manifest with switched id
				if (File::LoadFromResource(ManifestFragment::GetAppDirectory() + sAppName, (bExeFile ? 2 : 1), ManifestFragment::m_xml)) {					
					msgLogger->Print(LOG_LEVEL_1, IDS_WRONG_SWITCHED_RES_ID, ManifestFragment::GetAppDirectory(), sFileName);					
					return IDS_WRONG_SWITCHED_RES_ID;
				}

				msgLogger->Print(LOG_LEVEL_1, IDS_NO_EXTERNAL_INTERNAL_MAN_FOUND, ManifestFragment::GetAppDirectory(), sFileName, sAppName);					
				return IDS_NO_EXTERNAL_INTERNAL_MAN_FOUND;
			}
			else if (bInternalExists) { //internal exists				
				msgLogger->Print(LOG_LEVEL_1, IDS_USING_EMBEDED_MAN_ONLY, ManifestFragment::GetAppDirectory() + sAppName);					
			}
			else if (bExternalExists) {
				//load external one
				if (S_OK != ManifestFragment::m_xml->LoadFromFile(ManifestFragment::GetAppDirectory() + sFileName + L".manifest")) {
					msgLogger->Print(LOG_LEVEL_1, IDS_CANNOT_LOAD_EXTERNAL_MAN, ManifestFragment::GetAppDirectory(), sFileName);					
					return IDS_CANNOT_LOAD_EXTERNAL_MAN;
				}
				else msgLogger->Print(LOG_LEVEL_1, IDS_LOADED_EXTERNAL_MANIFEST_FILE, ManifestFragment::GetAppDirectory(), sAppName);					
			}	
		}

		if (File::FileExists(ManifestFragment::GetAppDirectory() + sFileName + L".config")) { //config file exists		
			msgLogger->Print(LOG_LEVEL_2, IDS_CONFIG_FILE_FOUND, ManifestFragment::GetAppDirectory() + sFileName + L".config");
		}
		else {
			msgLogger->Print(LOG_LEVEL_3, IDS_CONFIG_FILE_DOES_NOT_EXIST, ManifestFragment::GetAppDirectory() + sFileName + L".config"); 		
		}
	}
	return 0;
}


DWORD GetWinVersion(bool bMinor) 
{
	typedef DWORD (WINAPI *VersionFunc)(VOID);
	DWORD dwVersion = 0;

	HINSTANCE hInst = ::GetModuleHandleA("KERNEL32.DLL");
	
	if (NULL == hInst) {
		return 0;
	}

	VersionFunc pfVersion = reinterpret_cast<VersionFunc>(GetProcAddress(hInst, "GetVersion"));

	if (NULL == pfVersion) {
		return false;
	}
	
	dwVersion = (*pfVersion)();

	return (bMinor ? (DWORD)(LOBYTE(LOWORD(dwVersion))) : dwVersion);
}


HMODULE LoadXMLLite() 
{
	typedef HRESULT (STDAPICALLTYPE *XMLReaderFunc)(__in REFIID riid, __out void ** ppvObject, __in_opt IMalloc * pMalloc);
	
	HMODULE hLib = LoadLibraryExA("XMLLITE.DLL", NULL, NULL);
	if (NULL == hLib) {		
		return NULL;
	}
	
	HINSTANCE hInst = ::GetModuleHandleA("XMLLITE.DLL");
	
	if (NULL == hInst) {
		return NULL;
	}

	XMLReaderFunc pfReader = reinterpret_cast<XMLReaderFunc>(GetProcAddress(hInst, "CreateXmlReader"));

	if (NULL == pfReader) {
		return NULL;
	}

	return hLib;
}


wstring strtolower(wstring str)
{
	const size_t nLen = str.length();
	
	for(size_t i = 0; i < nLen; i++) {
		str[i] = std::tolower(str[i], std::locale());
	}

	return str;
}


wstring quote_regex(const wstring& sFilter) 
{
    vector<wchar_t> v;

    for (wstring::const_iterator i = sFilter.begin(); i != sFilter.end(); ++i) {
        wchar_t c = *i;

		if ('*' == c) {
			v.push_back('.');
		}
		else if ('?' == c) {
			c = '.';
		}
        else if (is_special_regex(c)) {
            v.push_back('\\');
        }

        v.push_back(c);
    }

    return wstring(v.begin(), v.end());
}


bool is_special_regex(const wchar_t c) {
    switch (c) {
        case '.': case '*': case '+': case '?': case '|':
        case '^': case '$': case '(': case ')': case '[':
        case ']': case '{': case '}': case '\\':
            return true;

        default:
            return false;
    }
}


wstring IntToStr(int iValue)
{
	WCHAR szBuff[8];

	if (!_itow_s(iValue, szBuff, 8, 10)) {
		return wstring(szBuff);
	}
	else return wstring(L"");
}
		
wstring GetSystemArch() 
{
	typedef DWORD (WINAPI *SystemInfoFunc)(LPSYSTEM_INFO lpSystemInfo);
	SYSTEM_INFO sysInfo;
	
	HINSTANCE hInst = ::GetModuleHandleA("KERNEL32.DLL");
	
	if (NULL == hInst) {
		return wstring(L"");
	}

	SystemInfoFunc pfVersion = reinterpret_cast<SystemInfoFunc>(GetProcAddress(hInst, "GetSystemInfo"));

	if (NULL == pfVersion) {
		return wstring(L"");
	}

	(*pfVersion)(&sysInfo);

	if (PROCESSOR_ARCHITECTURE_AMD64 == sysInfo.wProcessorArchitecture) {
		return wstring(L"amd64");
	}
	else if (PROCESSOR_ARCHITECTURE_IA64 == sysInfo.wProcessorArchitecture) {
		return wstring(L"ia64");
	}
	else if (PROCESSOR_ARCHITECTURE_INTEL == sysInfo.wProcessorArchitecture) {
		return wstring(L"x86");
	}
	else {
		return wstring(L"unknow");
	}
}

		
