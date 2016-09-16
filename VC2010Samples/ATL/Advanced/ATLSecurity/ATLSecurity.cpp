// ATLSecurity.cpp
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// ATLSecurity.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

LPCTSTR g_szDefaultFile = _T("\\\\.\\A:");
CAtlArray<CString> g_aObjects;

enum ExamineAccessToken {
	ExamineAccessTokenDefault,
	ExamineAccessTokenYes,
	ExamineAccessTokenNo
};
ExamineAccessToken g_eat = ExamineAccessTokenDefault;

enum ExamineObjectType
{
	ExamineObjectTypeDefault, // file
	ExamineObjectTypeFile,
	ExamineObjectTypeRegkey,
	ExamineObjectTypeService,
	ExamineObjectTypeKernel,
	ExamineObjectTypePrinter
};

ExamineObjectType g_eot = ExamineObjectTypeDefault;

// logging methods

int g_indent = 0;

class CIndent
{
public:
	CIndent() { g_indent++; }
	~CIndent() { g_indent--; }
};

void Log(LPCTSTR szFormat, ...)
{
	CString strMessage;

	va_list argList;
	va_start( argList, szFormat );
	strMessage.FormatV( szFormat, argList );
	va_end( argList );

	CString strIndent(' ', g_indent*2);

	_tprintf(_T("%s%s\n"), (LPCTSTR)strIndent, (LPCTSTR)strMessage);
	ATLTRACE(_T("%s%s\n"), (LPCTSTR)strIndent, (LPCTSTR)strMessage);
}

bool DisplayHelp()
{
	CPath path;
	if (!::GetModuleFileName(NULL, CStrBufA(path, MAX_PATH), MAX_PATH))
		return false;
	path.StripPath();

	CString str;
	str.FormatMessage(
		_T("Checks the security descriptor on a named object.\n")
		_T("\n")
		_T("Usage: %1 [-?] [-at|-no_at] [-file|-regkey|-service|-kernel|-printer] [objectname]*\n")
		_T("  -?        Display this help message\n")
		_T("  -at       Examine the process access token (default)\n")
		_T("  -no_at    Don't examine the process access token\n")
		_T("  -file     objectname is the name of a file to examine (default)\n")
		_T("  -regkey   objectname is the name of a registry key to examine\n")
		_T("  -service  objectname is the name of a service to examine\n")
		_T("  -kernel   objectname is the name of a kernel object to examine\n")
		_T("            these can be semaphores, events, mutexes, waitable timers, and file mappings\n")
		_T("  -printer  objectname is the name of a printer to examine\n")
		_T("  objectname defaults to \\\\.\\A:\n")
		_T("Example: %1 C:\\boot.ini\n")
		_T("\n")
		_T("Note: \\\\.\\A: is not the same as A:\n")
		_T("Checking \\\\.\\A: checks access to the floppy drive,\n")
		_T("Checking A: checks access to the root directory"),
		path);
	Log(str);

	return false;
}

bool ParseCommandLine(int argc, LPTSTR argv[])
{
	for (int i=1; i<argc; i++)
	{
		LPCTSTR szOption = argv[i];
		if (szOption[0] == '-' || szOption[0] == '/')
		{
			szOption++;
			if (strcmp(szOption, "?") == 0)
				return DisplayHelp();
			else if (_stricmp(szOption, "at") == 0)
			{
				if (g_eat != ExamineAccessTokenDefault)
					return DisplayHelp();
				g_eat = ExamineAccessTokenYes;
			}
			else if (_stricmp(szOption, "no_at") == 0)
			{
				if (g_eat != ExamineAccessTokenDefault)
					return DisplayHelp();
				g_eat = ExamineAccessTokenNo;
			}
			else if (_stricmp(szOption, "file") == 0)
			{
				if (g_eot != ExamineObjectTypeDefault)
					return DisplayHelp();
				g_eot = ExamineObjectTypeFile;
			}
			else if (_stricmp(szOption, "regkey") == 0)
			{
				if (g_eot != ExamineObjectTypeDefault)
					return DisplayHelp();
				g_eot = ExamineObjectTypeRegkey;
			}
			else if (_stricmp(szOption, "service") == 0)
			{
				if (g_eot != ExamineObjectTypeDefault)
					return DisplayHelp();
				g_eot = ExamineObjectTypeService;
			}
			else if (_stricmp(szOption, "kernel") == 0)
			{
				if (g_eot != ExamineObjectTypeDefault)
					return DisplayHelp();
				g_eot = ExamineObjectTypeKernel;
			}
			else if (_stricmp(szOption, "printer") == 0)
			{
				if (g_eot != ExamineObjectTypeDefault)
					return DisplayHelp();
				g_eot = ExamineObjectTypePrinter;
			}
		}
		else
			g_aObjects.Add(szOption);
	}

	return true;
}

// functions to examine/dump specific types of objects

struct Mapping
{
	DWORD dwValue;
	LPCSTR szName;
};

Mapping mapGenericAccess[] = {
	// standard access rights
	{DELETE,									_T("Delete")},
	{READ_CONTROL,								_T("Read Control")},
	{WRITE_DAC,									_T("Write Dacl")},
	{WRITE_OWNER,								_T("Write Owner")},
	{SYNCHRONIZE,								_T("Synchronize")},

	// misc access rights
	{ACCESS_SYSTEM_SECURITY,					_T("Access SACL")},
	{MAXIMUM_ALLOWED,							_T("Maximum Allowed")},

	// generic access rights
	{GENERIC_READ,								_T("Generic Read")},
	{GENERIC_WRITE,								_T("Generic Write")},
	{GENERIC_EXECUTE,							_T("Generic Execute")},
	{GENERIC_ALL,								_T("Generic All")},

	{0,											NULL}
};

Mapping mapFileAccess[] = {
	// specific access rights for files
	{FILE_READ_DATA|FILE_LIST_DIRECTORY,		_T("Read Data/List Directory")},
	{FILE_WRITE_DATA|FILE_ADD_FILE,				_T("Write Data/Add File")},
	{FILE_APPEND_DATA|FILE_ADD_SUBDIRECTORY,	_T("Append Data/Add Subdirectory")},
	{FILE_READ_EA,								_T("Read Extended Attributes")},
	{FILE_WRITE_EA,								_T("Write Extended Attributes")},
	{FILE_EXECUTE|FILE_TRAVERSE,				_T("Execute/Traverse")},
	{FILE_DELETE_CHILD,							_T("Delete Child")},
	{FILE_READ_ATTRIBUTES,						_T("Read Attributes")},
	{FILE_WRITE_ATTRIBUTES,						_T("Write Attributes")},

	{0,											NULL},

	{FILE_GENERIC_READ,							_T("File Generic Read")},
	{FILE_GENERIC_WRITE,						_T("File Generic Write")},
	{FILE_GENERIC_EXECUTE,						_T("File Generic Execute")},
	{FILE_ALL_ACCESS,							_T("File Generic All Access")},

	{0,											NULL}
};

Mapping mapRegkeyAccess[] = {
	{KEY_QUERY_VALUE,							_T("Query Value")},
	{KEY_SET_VALUE,								_T("Set Value")},
	{KEY_CREATE_SUB_KEY,						_T("Create Subkey")},
	{KEY_ENUMERATE_SUB_KEYS,					_T("Enumerate Subkey")},
	{KEY_NOTIFY,								_T("Notify")},
	{KEY_CREATE_LINK,							_T("Create Link")},

	{0,											NULL},

	{KEY_READ,									_T("Key Generic Read")},
	{KEY_WRITE,									_T("Key Generic Write")},
	{KEY_EXECUTE,								_T("Key Generic Execute")},
	{KEY_ALL_ACCESS,							_T("Key Generic All Access")},

	{0,											NULL}
};

Mapping mapServiceAccess[] = {
	{SERVICE_QUERY_CONFIG,						_T("Query Config")},
	{SERVICE_CHANGE_CONFIG,						_T("Change Config")},
	{SERVICE_QUERY_STATUS,						_T("Query Status")},
	{SERVICE_ENUMERATE_DEPENDENTS,				_T("Enumerate Dependents")},
	{SERVICE_START,								_T("Start")},
	{SERVICE_STOP,								_T("Stop")},
	{SERVICE_PAUSE_CONTINUE,					_T("Pause Control")},
	{SERVICE_INTERROGATE,						_T("Interrogate")},
	{SERVICE_USER_DEFINED_CONTROL,				_T("User Defined Control")},

	{0,											NULL},

	{SERVICE_ALL_ACCESS,						_T("Service Generic All Access")},

	{0,											NULL}
};

// kernel objects can be semaphore, event, mutex, waitable timer, and file mapping
Mapping mapKernelAccess[] = {
	{TIMER_QUERY_STATE|FILE_MAP_COPY|MUTEX_MODIFY_STATE,
												_T("Query State (timer, event)/Modify State (mutex)/Copy on Write (mapping)")},
	{TIMER_MODIFY_STATE|SEMAPHORE_MODIFY_STATE|EVENT_MODIFY_STATE|FILE_MAP_WRITE,
												_T("Modify State (timer, semaphore, event)/Write (mapping)")},
	{FILE_MAP_READ,								_T("Read (mapping)")},

	{0,											NULL},

	{TIMER_ALL_ACCESS|SEMAPHORE_ALL_ACCESS|EVENT_ALL_ACCESS,
												_T("All Access (timer, semaphore, event)")},
	{FILE_MAP_ALL_ACCESS,						_T("All Access (mapping)")},

	{0,											NULL}
};

Mapping mapPrinterAccess[] = {
	{SERVER_ACCESS_ADMINISTER,					_T("Administer Print Server")},
	{SERVER_ACCESS_ENUMERATE,					_T("Enumerate Print Server")},
	{PRINTER_ACCESS_ADMINISTER,					_T("Administer Printer")},
	{PRINTER_ACCESS_USE,						_T("Use Printer")},
	{JOB_ACCESS_ADMINISTER,						_T("Administer Job")},

	{0,											NULL},

	{SERVER_READ,								_T("Print Server Read")},
	{SERVER_WRITE,								_T("Print Server Write")},
	{SERVER_EXECUTE,							_T("Print Server Execute")},
	{SERVER_ALL_ACCESS,							_T("Print Server All Access")},
	{PRINTER_READ,								_T("Printer Read")},
	{PRINTER_WRITE,								_T("Printer Write")},
	{PRINTER_EXECUTE,							_T("Printer Execute")},
	{PRINTER_ALL_ACCESS,						_T("Printer All Access")},
	{JOB_READ,									_T("Job Read")},
	{JOB_WRITE,									_T("Job Write")},
	{JOB_EXECUTE,								_T("Job Execute")},
	{JOB_ALL_ACCESS,							_T("Job All Access")},

	{0,											NULL}
};

void DumpSid(CSid& sid)
{
	CIndent scope;

	Log(_T("Account Name: %s"), sid.AccountName());
	Log(_T("Domain: %s"), sid.Domain());
	Log(_T("SID: %s"), sid.Sid());
}

void DumpAccessMask(ACCESS_MASK access, Mapping* pAccessMappings)
{
	ACCESS_MASK remaining = access;

	CIndent scope;

	// examine the standard and generic bits that are set.
	Mapping* pAccess = mapGenericAccess;
	while (pAccess->szName)
	{
		if (remaining & pAccess->dwValue)
		{
			remaining &= ~pAccess->dwValue;
			Log(pAccess->szName);
		}
		pAccess++;
	}

	// examine the specific bits that are set
	pAccess = pAccessMappings;
	while (pAccess->szName)
	{
		if (remaining & pAccess->dwValue)
		{
			remaining &= ~pAccess->dwValue;
			Log(pAccess->szName);
		}
		pAccess++;
	}

	pAccess++;

	// take a look at the mappings for generic rights.
	// the generic bits should not have been set in the DACL
	// we got. instead, the specific and standard rights they map
	// to should have been set. now see which of the generic rights we
	// really have
	while (pAccess->szName)
	{
		// we must have all off the bits that map to the generic
		// right in order to have that right
		if ((access & pAccess->dwValue) == pAccess->dwValue)
			Log(pAccess->szName);
		pAccess++;
	}

	if (remaining)
		Log(_T("Unknown Access Mask: %8.8X"), remaining);
}

void DumpAceType(BYTE type)
{
	static Mapping mapTypes[] = {
		{ACCESS_ALLOWED_ACE_TYPE, _T("Access Allowed")},
		{ACCESS_ALLOWED_OBJECT_ACE_TYPE, _T("Access Allowed Object")},
		{ACCESS_DENIED_ACE_TYPE, _T("Access Denied")},
		{ACCESS_DENIED_OBJECT_ACE_TYPE, _T("Access Denied Object")},
		{SYSTEM_AUDIT_ACE_TYPE, _T("System Audit")},
		{SYSTEM_AUDIT_OBJECT_ACE_TYPE, _T("System Audit Object")},
		{0, NULL}
	};

	CIndent scope;

	Mapping* pTypes = mapTypes;

	while (pTypes->szName && pTypes->dwValue != type)
		pTypes++;

	if (pTypes->szName)
		Log(pTypes->szName);
	else
		Log(_T("Unknown type %d"), type);
}

void DumpAceFlags(BYTE flags)
{
	static Mapping mapFlags[] = {
		{CONTAINER_INHERIT_ACE, _T("Container Inherit")},
		{INHERIT_ONLY_ACE, _T("Inherit Only")},
		{INHERITED_ACE, _T("Inherited")},
		{NO_PROPAGATE_INHERIT_ACE, _T("Non-propagated Inherit")},
		{OBJECT_INHERIT_ACE, _T("Object Inherit")},
		{FAILED_ACCESS_ACE_FLAG, _T("Audit Failed Attempts")},
		{SUCCESSFUL_ACCESS_ACE_FLAG, _T("Audit Successful Attempts")},
		{0, NULL}
	};

	CIndent scope;

	Mapping* pFlags = mapFlags;

	while (pFlags->szName)
	{
		if (flags & pFlags->dwValue)
		{
			flags &= ~pFlags->dwValue;
			Log(pFlags->szName);
		}
		pFlags++;
	}

	if (flags)
		Log(_T("Unknown flags: %8.8X"), flags);
}

void DumpAce(CSid& sid,
			 ACCESS_MASK mask,
			 BYTE type,
			 BYTE flags,
			 GUID guidObjectType,
			 GUID guidInheritedObjectType,
			 Mapping* pAccessMappings)
{
	CIndent scope;

	Log(_T("Sid:"));
	DumpSid(sid);

	Log(_T("Mask:"));
	DumpAccessMask(mask, pAccessMappings);

	Log(_T("Type:"));
	DumpAceType(type);

	Log(_T("Flags:"));
	DumpAceFlags(flags);

	if (!InlineIsEqualGUID(GUID_NULL, guidObjectType))
	{
		Log(_T("Object Type:"));

		CStringW str;
		if (StringFromGUID2(guidObjectType, CStrBufW(str, 128), 128))
			Log(CW2CT(str));
		else
			Log(_T("Failure converting GUID to String"));
	}

	if (!InlineIsEqualGUID(GUID_NULL, guidInheritedObjectType))
	{
		Log(_T("Inherited Object Type:"));

		CStringW str;
		if (StringFromGUID2(guidInheritedObjectType, CStrBufW(str, 128), 128))
			Log(CW2CT(str));
		else
			Log(_T("Failure converting GUID to String"));
	}
}

void DumpAcl(CAcl& acl, Mapping* pAccessMappings)
{
	CIndent scope;

	if (acl.IsNull())
		Log(_T("ACL is NULL"));
	else if (acl.IsEmpty())
		Log(_T("ACL is Empty"));
	else
	{
		Log(_T("Ace Count: %d"), acl.GetAceCount());

		for (UINT i=0; i<acl.GetAceCount(); i++)
		{
			CSid sid;
			ACCESS_MASK mask;
			BYTE type;
			BYTE flags;
			GUID guidObjectType;
			GUID guidInheritedObjectType;

			Log(_T("Ace %d:"), i);
			acl.GetAclEntry(i, &sid, &mask, &type, &flags, &guidObjectType, &guidInheritedObjectType);
			DumpAce(sid, mask, type, flags, guidObjectType, guidInheritedObjectType, pAccessMappings);
		}
	}
}

void DumpSecurityDescriptor(CSecurityDesc& sd, SECURITY_INFORMATION si, Mapping* pAccessMappings)
{
	CIndent scope;

	CSid sidOwner;
	CSid sidGroup;
	CDacl dacl;
	CSacl sacl;
	bool bPresent = false;
	bool bDefaulted = false;

	if (LOBYTE(LOWORD(::GetVersion())) >= 5)
	{
		// only works on Windows 2000 or greater
		CString strSD;
		if (sd.ToString(&strSD, si))
			Log(_T("%s"), (LPCTSTR)strSD);
	}

	if ((si & OWNER_SECURITY_INFORMATION) && sd.GetOwner(&sidOwner, &bDefaulted))
	{
		Log(_T("Owner: %s"),
			bDefaulted ? _T("[Defaulted]") : _T(""));
		DumpSid(sidOwner);
	}

	if ((si & GROUP_SECURITY_INFORMATION) && sd.GetGroup(&sidGroup, &bDefaulted))
	{
		Log(_T("Group: %s"),
			bDefaulted ? _T("[Defaulted]") : _T(""));
		DumpSid(sidGroup);
	}

	if ((si & DACL_SECURITY_INFORMATION) && sd.GetDacl(&dacl, &bPresent, &bDefaulted))
	{
		Log(_T("Dacl: %s %s"),
			bPresent ? _T("") : _T("[Not Present]"),
			bDefaulted ? _T("[Defaulted]") : _T(""));
		DumpAcl(dacl, pAccessMappings);
	}

	if ((si & SACL_SECURITY_INFORMATION) && sd.GetSacl(&sacl, &bPresent, &bDefaulted))
	{
		Log(_T("Sacl: %s %s"),
			bPresent ? _T("") : _T("[Not Present]"),
			bDefaulted ? _T("[Defaulted]") : _T(""));
		DumpAcl(sacl, pAccessMappings);
	}
}

void DumpSecurityDescriptor(LPCTSTR szObject, SE_OBJECT_TYPE type, Mapping* pAccessMappings)
{
	CSecurityDesc sd;
	SECURITY_INFORMATION si =
		OWNER_SECURITY_INFORMATION |
		GROUP_SECURITY_INFORMATION |
		DACL_SECURITY_INFORMATION |
		SACL_SECURITY_INFORMATION;

	if (!AtlGetSecurityDescriptor(szObject, type, &sd))
	{
		CIndent scope;

		si =
			OWNER_SECURITY_INFORMATION |
			GROUP_SECURITY_INFORMATION |
			DACL_SECURITY_INFORMATION;
		if (!AtlGetSecurityDescriptor(szObject, type, &sd, si))
		{
			Log(_T("Could not retrieve security descriptor"));
			return;
		}
		Log(_T("Could not retrieve SACL"));
	}

	DumpSecurityDescriptor(sd, si, pAccessMappings);
}

void DumpGroupAttributes(DWORD attrs)
{
	static Mapping mapAttributes[] = {
		{SE_GROUP_MANDATORY, _T("Mandatory")},
		{SE_GROUP_ENABLED_BY_DEFAULT, _T("Enabled By Default")},
		{SE_GROUP_ENABLED, _T("Enabled")},
		{SE_GROUP_OWNER, _T("Owner")},
		{SE_GROUP_LOGON_ID, _T("Logon Id")},
		{0, NULL}
	};

	CIndent scope;

	Mapping* pAttrs = mapAttributes;

	while (pAttrs->szName)
	{
		if (attrs & pAttrs->dwValue)
		{
			attrs &= ~pAttrs->dwValue;
			Log(pAttrs->szName);
		}
		pAttrs++;
	}

	if (attrs)
		Log(_T("Unknown attributes: %8.8X"), attrs);
}

void DumpGroups(CTokenGroups& groups)
{
	CIndent scope;

	CSid::CSidArray sids;
	CAtlArray<DWORD> attrs;

	groups.GetSidsAndAttributes(&sids, &attrs);

	ATLASSERT(groups.GetCount() == sids.GetCount());
	ATLASSERT(groups.GetCount() == attrs.GetCount());

	Log(_T("Group Count: %d"), groups.GetCount());
	for (UINT i=0; i<groups.GetCount(); i++)
	{
		Log(_T("Group %d:"), i);
		Log(_T("Sid:"));
		DumpSid(sids[i]);
		Log(_T("Attributes:"));
		DumpGroupAttributes(attrs[i]);
	}
}

void DumpPrivilegeAttributes(DWORD attrs)
{
	static Mapping mapAttributes[] = {
		{SE_PRIVILEGE_ENABLED_BY_DEFAULT, _T("Enabled By Default")},
		{SE_PRIVILEGE_ENABLED, _T("Enabled")},
		{SE_PRIVILEGE_USED_FOR_ACCESS, _T("Used For Access")},
		{0, NULL}
	};

	CIndent scope;

	Mapping* pAttrs = mapAttributes;

	while (pAttrs->szName)
	{
		if (attrs & pAttrs->dwValue)
		{
			attrs &= ~pAttrs->dwValue;
			Log(pAttrs->szName);
		}
		pAttrs++;
	}

	if (attrs)
		Log(_T("Unknown attributes: %8.8X"), attrs);
}

void DumpPrivileges(CTokenPrivileges& priv)
{
	CIndent scope;

	CTokenPrivileges::CNames names;
	CTokenPrivileges::CNames dnames;
	CTokenPrivileges::CAttributes attrs;
	
	priv.GetNamesAndAttributes(&names, &attrs);
	priv.GetDisplayNames(&dnames);

	ATLASSERT(priv.GetCount() == names.GetCount());
	ATLASSERT(priv.GetCount() == dnames.GetCount());
	ATLASSERT(priv.GetCount() == attrs.GetCount());

	Log(_T("Privilege Count: %d"), priv.GetCount());
	for (UINT i=0; i<priv.GetCount(); i++)
	{
		Log(_T("Privilege %d:"), i);
		Log(_T("Name: %s"), (LPCTSTR)names[i]);
		Log(_T("Display Name: %s"), (LPCTSTR)dnames[i]);
		Log(_T("Attributes:"));
		DumpPrivilegeAttributes(attrs[i]);
	}
}

CString GetTokenType(TOKEN_TYPE& type)
{
	if (type == TokenPrimary)
		return _T("Primary Token");
	if (type == TokenImpersonation)
		return _T("Impersonation Token");

	CString str;
	str.Format(_T("Unknown %d"), type);
	return str;
}

CString GetImpersonationLevel(SECURITY_IMPERSONATION_LEVEL& sil)
{
	if (sil == SecurityAnonymous)
		return _T("Anonymous");
	if (sil == SecurityIdentification)
		return _T("Identification");
	if (sil == SecurityImpersonation)
		return _T("Impersonation");
	if (sil == SecurityDelegation)
		return _T("Delegation");

	CString str;
	str.Format(_T("Unknown %d"), sil);
	return str;
}

void DumpStatistics(TOKEN_STATISTICS& stats)
{
	CIndent scope;

	Log(_T("TokenId: 0x%.8x%.8x"), stats.TokenId.HighPart, stats.TokenId.LowPart);
	Log(_T("AuthenticationId: 0x%.8x%.8x"), stats.AuthenticationId.HighPart, stats.AuthenticationId.LowPart);
	Log(_T("ExpirationTime: (not supported in this release of Windows NT)"));
	Log(_T("TokenType: %s"), (LPCTSTR)GetTokenType(stats.TokenType));
	Log(_T("ImpersonationLevel: %s"), (LPCTSTR)GetImpersonationLevel(stats.ImpersonationLevel));
	Log(_T("DynamicCharged: %ld"), stats.DynamicCharged);
	Log(_T("DynamicAvailable: %ld"), stats.DynamicAvailable);
	Log(_T("GroupCount: %d"), stats.GroupCount);
	Log(_T("PrivilegeCount: %d"), stats.PrivilegeCount);
	Log(_T("ModifiedId: 0x%.8x%.8x"), stats.ModifiedId.HighPart, stats.ModifiedId.LowPart);
}

void DumpAccessToken(CAccessToken& at)
{
	CIndent scope;

	CSid sidUser;
	if (!at.GetUser(&sidUser))
		Log(_T("Failure retrieving User from Token"));
	else
	{
		Log(_T("User:"));
		DumpSid(sidUser);
	}

	CTokenGroups groups;
	if (!at.GetGroups(&groups))
		Log(_T("Failure retrieving Groups from Token"));
	else
	{
		Log(_T("Groups:"));
		DumpGroups(groups);
	}

	CTokenPrivileges priv;
	if (!at.GetPrivileges(&priv))
		Log(_T("Failure retrieving Privileges from Token"));
	else
	{
		Log(_T("Privileges:"));
		DumpPrivileges(priv);
	}

	CSid sidOwner;
	if (!at.GetOwner(&sidOwner))
		Log(_T("Failure retrieving Owner from Token"));
	else
	{
		Log(_T("Default Owner:"));
		DumpSid(sidOwner);
	}

	CSid sidPrimaryGroup;
	if (!at.GetOwner(&sidPrimaryGroup))
		Log(_T("Failure retrieving Primary Group from Token"));
	else
	{
		Log(_T("Primary Group:"));
		DumpSid(sidPrimaryGroup);
	}

	CDacl dacl;
	if (!at.GetDefaultDacl(&dacl))
		Log(_T("Failure retrieving Default Dacl from Token"));
	else
	{
		Log(_T("Default Dacl:"));
		DumpAcl(dacl, mapGenericAccess);
	}

	TOKEN_SOURCE source;
	if (!at.GetSource(&source))
		Log(_T("Failure retrieving Source from Token"));
	else
	{
		Log(_T("Source:"));
		Log(_T("Source Name: %.8s"), CString(source.SourceName));
		Log(_T("Source Identifier: 0x%.8x%.8x"), source.SourceIdentifier.HighPart, source.SourceIdentifier.LowPart);
	}

	TOKEN_TYPE type;
	if (!at.GetType(&type))
		Log(_T("Failure retrieving Type from Token"));
	else
		Log(_T("Type: %s"), (LPCTSTR)GetTokenType(type));
	
	if (type == TokenImpersonation)
	{
		SECURITY_IMPERSONATION_LEVEL sil;
		if (!at.GetImpersonationLevel(&sil))
			Log(_T("Failure retrieving Impersonation Level from Token"));
		else
			Log(_T("Impersonation Level: %s"), (LPCTSTR)GetImpersonationLevel(sil));
	}

	TOKEN_STATISTICS stats;
	if (!at.GetStatistics(&stats))
		Log(_T("Failure retrieving Statistics from Token"));
	else
	{
		Log(_T("Statistics:"));
		DumpStatistics(stats);
	}
}

#ifdef _UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
    if (GetVersion() & 0x80000000)
    {
		_tprintf(_T("This application only runs on Windows NT/2000 or later"));
		return 0;
    }

	if (!ParseCommandLine(argc, argv))
		return 0;

	if (g_eat != ExamineAccessTokenNo)
	{
		CAccessToken at;
		if (!at.GetProcessToken(TOKEN_READ | TOKEN_QUERY_SOURCE))
			Log(_T("Could not open process token"));
		else
		{
			Log(_T("Process Access Token:"));
			DumpAccessToken(at);
		}
	}

	for (size_t i=0; i<g_aObjects.GetCount(); i++)
	{
		Log(_T("Security Descriptor for object %s:"), (LPCTSTR)g_aObjects[i]);
		switch (g_eot)
		{
		case ExamineObjectTypeDefault:
		case ExamineObjectTypeFile:
			DumpSecurityDescriptor(g_aObjects[i], SE_FILE_OBJECT, mapFileAccess);
			break;
		case ExamineObjectTypeRegkey:
			DumpSecurityDescriptor(g_aObjects[i], SE_REGISTRY_KEY, mapRegkeyAccess);
			break;
		case ExamineObjectTypeService:
			DumpSecurityDescriptor(g_aObjects[i], SE_SERVICE, mapServiceAccess);
			break;
		case ExamineObjectTypeKernel:
			DumpSecurityDescriptor(g_aObjects[i], SE_KERNEL_OBJECT, mapKernelAccess);
			break;
		case ExamineObjectTypePrinter:
			DumpSecurityDescriptor(g_aObjects[i], SE_PRINTER, mapPrinterAccess);
			break;
		default:
			ATLASSERT(FALSE);
		}
	}

	return 0;
}
