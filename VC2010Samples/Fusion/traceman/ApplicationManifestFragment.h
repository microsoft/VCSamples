#pragma once
#include "ManifestFragment.h"

class ApplicationManifestFragment :
	public ManifestFragment
{
public:
	ApplicationManifestFragment(UINT nDeepLevel, const wstring& sAppName);
	virtual ~ApplicationManifestFragment(void);
	
	virtual void ResolveDependicies(void);
	virtual void ParseManifest(void);		
	virtual void Validate(void) ;
protected:
	virtual bool SearchLocalDir(void);
private:
	wstring m_sAppName;	
};
