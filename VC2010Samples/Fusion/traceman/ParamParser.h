#pragma once

#include "stdafx.h"

class ParamParser
{
public:
	ParamParser(void);
	virtual ~ParamParser(void);

	virtual int GetParamId() const;
	virtual std::wstring GetParamName() const;
	virtual bool IsParamSet() const;
	virtual bool IsParamCorrect() const;

	virtual std::wstring GetParamValueAsString() const;
	virtual int GetParamValueAsInt() const;

	virtual void AddParam(int nParamId, const std::wstring& sParamName, const std::wstring& sParamMatch = L"", const std::wstring& sDefault = L"");

	virtual void Parse(WCHAR **szParams, int nLen);

	virtual void Next();
	virtual bool IsNext() const;
protected:
	enum {
		PARAM_SET = 1,
		WRONG_PARAM_VALUE = 2
	};
		
	typedef struct _Param {
		int nParamId;
		std::wstring sParamName;
		std::wstring sParamMatch;
		std::wstring sDefault;
		std::wstring sValue;
		char cFlag;

		_Param(int nId, std::wstring sName, std::wstring sMatch, std::wstring sDef) {
			nParamId = nId;
			sParamName = sName;
			sParamMatch = sMatch;
			sDefault = sDef;
			sValue = L"";
			cFlag = 0;			
		}
	} Param;

	std::vector<Param> m_vParams;
	std::vector<Param>::iterator m_vParamIter;
};
