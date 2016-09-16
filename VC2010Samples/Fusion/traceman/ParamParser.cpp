#include "StdAfx.h"
#include "ParamParser.h"

ParamParser::ParamParser(void)
{
	AddParam(1, L"h");
	AddParam(1, L"\\?");
	AddParam(2, L"dump");	
	AddParam(3, L"verbose", L"0|1|2|3", L"2");
	AddParam(3, L"v", L"0|1|2|3", L"2");
	AddParam(4, L"filter", L".*");
	AddParam(4, L"f", L".*");
	AddParam(5, L"format", L".*");
	AddParam(6, L"output", L".*");		
	AddParam(7, L"regex");
}

ParamParser::~ParamParser(void)
{
}

std::wstring ParamParser::GetParamValueAsString() const
{
	return m_vParamIter->sValue;
}

int ParamParser::GetParamValueAsInt() const
{
	return _wtoi(m_vParamIter->sValue.c_str());
}

int ParamParser::GetParamId() const
{
	return m_vParamIter->nParamId;
}

void ParamParser::AddParam(int nParamId, const std::wstring& sParamName, const std::wstring& sParamMatch, const std::wstring& sDefault)
{
	m_vParams.push_back(Param(nParamId, sParamName, sParamMatch, sDefault));
}

bool ParamParser::IsParamSet() const 
{
	return (m_vParamIter->cFlag & ParamParser::PARAM_SET ? true : false);
}

bool ParamParser::IsParamCorrect() const 
{
	return (m_vParamIter->cFlag & ParamParser::WRONG_PARAM_VALUE ? false : true);
}

void ParamParser::Parse(WCHAR **szParams, int nLen) 
{
	assert(szParams != NULL);

	std::vector<Param>::iterator iter = m_vParams.begin();

	for(; iter != m_vParams.end(); ++iter) { 
		int nSetPos = -1;

		std::wstring sPattern(L"[-/]{1,1}");
		sPattern += iter->sParamName;

		if (!iter->sParamMatch.empty()) {
			sPattern += L":.*";
		}

		const wregex r(sPattern);
		
		for(int i = 0; i < nLen; i++) {
			if (regex_match(wstring(szParams[i]), r)) {				
				nSetPos = i;
				break;
			}
		}

		if (nSetPos >= 0) { //set in commnad line
			if (!iter->sParamMatch.empty()) {
				sPattern = L"[-/]{1,1}";
				sPattern += iter->sParamName;
				sPattern += L":(";
				sPattern += iter->sParamMatch;
				sPattern += L")";

				const wregex rex(sPattern);
				wsmatch m;

				wstring sParamExp(szParams[nSetPos]);

				if (regex_match(sParamExp, m, rex)) {					
					iter->sValue = wstring(m[1]);					
				}
				else {
					iter->cFlag |= ParamParser::WRONG_PARAM_VALUE;
					iter->sValue = iter->sDefault;
				}
			}			
			iter->cFlag |= ParamParser::PARAM_SET;
		}
		else { //take default value
			iter->sValue = iter->sDefault;
		}
	}

	m_vParamIter = m_vParams.begin();
}

bool ParamParser::IsNext() const
{
	return (m_vParamIter != m_vParams.end());
}

void ParamParser::Next() 
{
	++m_vParamIter;
}

std::wstring ParamParser::GetParamName() const
{
	return m_vParamIter->sParamName;
}