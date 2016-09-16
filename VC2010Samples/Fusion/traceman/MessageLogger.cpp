#include "StdAfx.h"
#include "MessageLogger.h"
#include "FileMessageLogger.h"
#include "ConsoleMessageLogger.h"

int MessageLogger::m_nLogLevel = MessageLogger::DEFAULT_LOG_LEVEL;
SafeMessageLogger MessageLogger::m_msgLogger;

MessageLogger::MessageLogger() : m_nIdent(0), m_nErrorNr(0), m_nErrorCount(0), m_bPrintErrorSummary(false)
{	
}

MessageLogger::~MessageLogger(void)
{
}

SafeMessageLogger &MessageLogger::GetInstance(int nIdent /* = 0 */, int nType /* = MessageLogger::CONSOLE_MESSAGE_HANDLER */, const wstring& sFileName) {
	
	if (m_msgLogger == NULL) {
		if (CONSOLE_MESSAGE_HANDLER == nType) {
			SafeMessageLogger consoleLogger(new ConsoleMessageLogger());

			m_msgLogger = consoleLogger;
		}
		else if(FILE_MESSAGE_HANDLER == nType) {
			SafeMessageLogger fileLogger(new FileMessageLogger(sFileName));

			m_msgLogger = fileLogger;
		}
		else {
			assert(false);
		}		

		m_msgLogger->SetLogLevel(0);
	}
	if (nIdent >= 0) {
		m_msgLogger->SetIdent(nIdent);
	}

	return m_msgLogger;	
}

void MessageLogger::Flush(void)
{
}

int MessageLogger::GetLogLevel(void)
{
	return m_nLogLevel;
}

void MessageLogger::SetLogLevel(int nLogLevel)
{
	m_nLogLevel = nLogLevel;
}

void MessageLogger::SetIdent(int nIdent)
{
	m_nIdent = nIdent;
}

void MessageLogger::IncIdent(int nIdent)
{
	m_nIdent += nIdent;
}

void MessageLogger::DecIdent(int nIdent)
{
	m_nIdent -= nIdent;
}

int MessageLogger::GetErrorNr(void)
{
	return m_nErrorNr;
}

void MessageLogger::SetErrorNr(int nErrorNr)
{
	m_nErrorNr = nErrorNr;
}

int MessageLogger::GetIdent() const
{
	return m_nIdent;
}

void MessageLogger::SummaryError(bool bSummary) 
{
	m_bPrintErrorSummary = bSummary;
}