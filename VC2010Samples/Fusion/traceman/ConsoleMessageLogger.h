#pragma once
#include "MessageLogger.h"

class ConsoleMessageLogger :
	public MessageLogger
{
public:	
	virtual ~ConsoleMessageLogger(void);

	virtual void Print(int nMessageLevel, int nMessageId, const wstring& sMsg = L"", const wstring& sMsg2 = L"", const wstring& sMsg3 = L"", const wstring& sMsg4 = L"",
				const wstring& sMsg5 = L"", const wstring& sMsg6 = L"", const wstring& sMsg7 = L"", 
					const wstring& sMsg8 = L"", const wstring& sMsg9 = L"", const wstring& sMsg10 = L""); 

	friend MessageLogger;
protected:
	ConsoleMessageLogger();
private:
	ConsoleMessageLogger(const ConsoleMessageLogger&);
	ConsoleMessageLogger &operator=(const ConsoleMessageLogger&);
};
