#pragma once

#include "stdafx.h"

class MessageLogger
{
public:
	enum MessageLoggerType {
		NONE_MESSAGE_HANDLER = 0,
		CONSOLE_MESSAGE_HANDLER,
		FILE_MESSAGE_HANDLER		
	};

	enum {
		DEFAULT_LOG_LEVEL = 0
	};
		
	virtual ~MessageLogger(void);
	static SafeMessageLogger &GetInstance(int nIdent = -1, int type = MessageLogger::CONSOLE_MESSAGE_HANDLER, const wstring& sFileName = L"");

	virtual void Print(int nMessageLevel, int nMessageId, const wstring& sMsg = L"", const wstring& sMsg2 = L"", const wstring& sMsg3 = L"", const wstring& sMsg4 = L"",
							const wstring& sMsg5 = L"", const wstring& sMsg6 = L"", const wstring& sMsg7 = L"", 
								const wstring& sMsg8 = L"", const wstring& sMsg9 = L"", const wstring& sMsg10 = L"") = 0; 

	virtual void Flush(void);		

	static int GetLogLevel(void);	
	static void SetLogLevel(int nLogLevel);	
	virtual void SetIdent(int nIdent);

	virtual void IncIdent(int nIdent = 1);
	virtual void DecIdent(int nIdent = 1);
	virtual int GetErrorNr(void);
	virtual void SetErrorNr(int nErrorNr);
	virtual int GetIdent() const;
	virtual void SummaryError(bool bSummary = true) ;

protected:
	MessageLogger();	

	static SafeMessageLogger m_msgLogger;
	int m_nIdent;
	int m_nErrorCount;
	bool m_bPrintErrorSummary;
private:
	MessageLogger(const MessageLogger&);
	MessageLogger &operator=(const MessageLogger&);

	static int m_nLogLevel;		
	int m_nErrorNr;
};
