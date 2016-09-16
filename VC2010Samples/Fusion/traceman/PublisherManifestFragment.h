#pragma once
#include "ManifestFragment.h"

class PublisherManifestFragment :
	public ManifestFragment
{
public:
	PublisherManifestFragment(UINT nDeepLevel);
	virtual ~PublisherManifestFragment(void);

	virtual void SetRdcIdentityAttr(void);
	virtual void SetRedirectAttr(void);

	virtual void ResolveDependicies(void);	
	virtual void ParseManifest(void);	
	virtual void Validate(void);

	virtual bool IsValidPolicy(const wstring& sAssemblyVersion);	
	virtual wstring GetRdcName(void) const;
	virtual wstring GetRdcToken(void) const;
	virtual wstring GetRdcVersion(void) const;
	virtual wstring GetRdcArch(void) const;
	virtual wstring GetRdcType(void) const;
	virtual wstring GetRdcLang(void) const;
	virtual wstring GetOldVersion(void) const;
	virtual wstring GetNewVersion(void) const;
	virtual wstring ToString() const;
	virtual wstring GetRedirection() const;
	virtual bool IsOverlapping(SafePublisherManifestFragment& assembly);
protected:	
	virtual wstring GetDirPattern(bool bPublicToken = true, bool bArch = true, bool bVersion = true, bool bLang = true, bool bPolicy = false) const;

	wstring m_sRdcName;
	wstring m_sRdcVersion;
	wstring m_sRdcLang;
	wstring m_sRdcArch;
	wstring m_sRdcToken;
	wstring m_sRdcType;	
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
	int m_nRedirectIdx;	
};
