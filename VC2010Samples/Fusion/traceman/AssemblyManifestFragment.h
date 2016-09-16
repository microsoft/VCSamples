#pragma once
#include "stdafx.h"
#include "debug.h"

#include "Version.h"
#include "XMLReader.h"
#include "ManifestFragment.h"

class AssemblyManifestFragment : public ManifestFragment
{
public:	
	AssemblyManifestFragment(UINT nDeepLevel, bool bLocal = false);
	virtual ~AssemblyManifestFragment(void);
	
	virtual void ResolveDependicies(void);	
	virtual void ParseManifest(void);
	virtual void Validate(void);
	virtual wstring ToString(void) const;
private:	
	typedef struct _FileInfo {
		wstring sFileName;
		wstring sHash;
		wstring sHashAlg;

		_FileInfo(const wstring& _sFileName, const wstring& _sHash, const wstring& _sHashAlg) {
			sFileName = _sFileName;
			sHash = _sHash;
			sHashAlg = _sHashAlg;
		}
	} FileInfo;

	vector<FileInfo> m_vFiles;	
	bool m_bLocal;
};

