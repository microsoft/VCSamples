#pragma once
#include "stdafx.h"
#include "debug.h"
#include "traceman.h"

#include "File.h"
#include "Version.h"
#include "XMLReader.h"


class ManifestFragment : public enable_shared_from_this<ManifestFragment> 
{
public:	
	enum {
		MAX_DEEP_LEVEL = 6 //how deep should look for assemblies
	};	

	enum OsType {
		NOT_SUPPORTED = 0,
		VISTA = 1,
		WINXP = 2
	};
	
	virtual ~ManifestFragment(void);	
	
	virtual size_t GetAssemblyCount(void);
	virtual SafeManifestFragment GetAssembly(size_t iIdx);

	virtual void ResolveDependicies(void) = 0;	
	virtual void ParseManifest(void) = 0;
	virtual void Validate(void);	

	static void SetWinSxSDirectory(const wstring& sDirectory);
	static void SetPolicyDirectory(const wstring& sDirectory);
	static void SetManifestDirectory(const wstring& sDirectory);	
	static void SetAppDirectory(const wstring& sDirectory);
	static void SetMaxDeepLevel(UINT nDeepLevel);

	virtual bool CanGoDeeper(void);			
	virtual wstring ToString(void) const;

	virtual wstring GetName(void) const;
	virtual wstring GetToken(void) const;
	virtual wstring GetArch(void) const;
	virtual wstring GetVersion(void) const;
	virtual wstring GetLang(void) const;
	virtual wstring GetType(void) const;
	
	virtual void SetIdentityAttr(void);
	virtual void FindSimilarAssembly(void);
	virtual bool IsEmptyManifest(void);

	virtual bool Filter(const wstring& sFilter);
	static void SetOsType(int nOsType);

	virtual int GetTerminateCode(void);

	static bool EqualName(const SafeManifestFragment& a, const SafeManifestFragment& b);
	static bool SortByName(const SafeManifestFragment& a, const SafeManifestFragment& b);
		
	static bool SortByVersion(const SafeManifestFragment& fAsm, const SafeManifestFragment& sAsm);
	static bool SortByVersionInPath(const wstring& fFile, const wstring& sFile);

	static wstring GetPolicyDirectory(void);	
	static wstring GetManifestDirectory(void);
	static wstring GetAppDirectory(void);
	static int GetOsType(void);

	static SafeXMLReader m_xml;
protected:	
	ManifestFragment(UINT nDeepLevel);

	virtual UINT GetDeepLevel(void) const;

	virtual bool ResolvePolicy(const wstring& sVersion, vector<wstring>& vFiles, const wstring& sPolicyDir = L"");	
	virtual wstring GetDirPattern(bool bPublicToken = true, bool bArch = true, bool bVersion = true, bool bLang = true, bool bPolicy = false) const;
	virtual void Terminate(int nResult);

	vector<SafeManifestFragment> m_vAssemblies;		

	static wstring m_sSXSDir;
	static wstring m_sPolicyDir;
	static wstring m_sManifestDir;
	static wstring m_sAppDir;
	static int m_nOsVersion;

	wstring m_sName;
	wstring m_sToken;
	wstring m_sArch;
	wstring m_sVersion;
	wstring m_sLang;
	wstring m_sType;
	bool m_bEmpty;
private:	
	UINT m_nDeepLevel;
	static UINT m_nMaxDeepLevel;	
	int m_nTerminateCode;	
};
