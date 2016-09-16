#include "StdAfx.h"
#include "traceman.h"
#include "ConsoleMessageLogger.h"

ConsoleMessageLogger::ConsoleMessageLogger()
{

}

ConsoleMessageLogger::~ConsoleMessageLogger(void)
{
	if (m_bPrintErrorSummary && GetErrorNr() > 0) {
		SetIdent(0);		
		Print(LOG_LEVEL_1, IDS_ERROR_SUMMARY, IntToStr(m_nErrorCount));
	}
}

void ConsoleMessageLogger::Print(int nMessageLevel, int nMessageId, const wstring& sMsg, const wstring& sMsg2, const wstring& sMsg3, const wstring& sMsg4,
			const wstring& sMsg5, const wstring& sMsg6, const wstring& sMsg7, const wstring& sMsg8, const wstring& sMsg9, const wstring& sMsg10)
{
	if (nMessageId > MIN_ERROR_VALUE) {
		m_nErrorCount++;
		if (GetErrorNr() < nMessageId - MIN_ERROR_VALUE) {		
			SetErrorNr(nMessageId - MIN_ERROR_VALUE);
		}
	}	

	

	if (GetLogLevel() >= nMessageLevel)  {
		WCHAR szDataBuffer[1024];
		int iRes = LoadStringW(NULL, nMessageId, szDataBuffer, 1024);

		assert(iRes <= 1024);		
		if (iRes <= 0) {
			wprintf(L"NO MSG %d with this level: %d\n", nMessageId, nMessageLevel);
			return;
		}
		
		wstring sData(L"");

		WCHAR szBuff[8];

		if (!_itow_s(nMessageLevel, szBuff, 8, 10)) {
			sData += wstring(szBuff);
		}
		sData += L"\n";

		if (!_itow_s(nMessageId, szBuff, 8, 10)) {
			sData += wstring(szBuff);
		}		
		sData += L"\n";
		sData += sMsg;
		sData += L"\n"; 
		sData += sMsg2;
		sData += L"\n";
		sData += sMsg3;
		sData += L"\n";
		sData += sMsg4;
		sData += L"\n";
		sData += sMsg5;
		sData += L"\n"; 		
		sData += sMsg6;
		sData += L"\n";
		sData += sMsg7;
		sData += L"\n";
		sData += sMsg8;
		sData += L"\n";
		sData += sMsg9; 
		sData += L"\n";
		sData += sMsg10;
		sData += L"\n";
		
		const wregex r(L"(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n(.*)\n");	

		wstring sResult = regex_replace(sData, r, wstring(szDataBuffer));		
		wstring sIdent(L"");
			
		for(int i = 0; i < m_nIdent; i++) {
			sIdent += L"  ";
		}		
		sResult = sIdent + sResult;
		sIdent = L"\n" + sIdent;

		const wregex cr(L"#CR#");	

		sResult = regex_replace(sResult, cr, sIdent);				
		wprintf(L"%s\n", sResult.c_str());
	}
}
