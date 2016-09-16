#pragma once
#include "ManifestFragment.h"

class ConfigManifestFragment :
	public ManifestFragment
{
public:
	ConfigManifestFragment(UINT mDeepLevel, SafeManifestFragment assembly);
	virtual ~ConfigManifestFragment(void);

	virtual void ResolveDependicies(void);	
	virtual void ParseManifest(void);
	virtual void Validate(void);

	virtual bool IsInConfig(void) const;
	virtual wstring GetOldVersion(void) const;
	virtual wstring GetNewVersion(void) const;
	virtual wstring ToString() const;
	virtual wstring GetRedirection() const;	

	virtual void SetRedirectAttr(void);
protected:
	virtual wstring GetDirPattern(bool bPublicToken = true, bool bArch = true, bool bVersion = true, bool bLang = true, bool bPolicy = false) const;
private:
	typedef struct _RedirectVer {
		wstring sOldVersion;
		wstring sNewVersion;
		_RedirectVer(const wstring& _sOldVersion, const wstring& _sNewVersion) {
			sOldVersion = _sOldVersion;
			sNewVersion = _sNewVersion;
		}
	} RedirectVer;

	vector<RedirectVer> m_vRedirect;
	SafeManifestFragment m_assembly;
	int m_nRedirectIdx;
	bool m_bResolvePolicy;
};
