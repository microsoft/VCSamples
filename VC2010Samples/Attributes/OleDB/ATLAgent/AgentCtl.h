// AgentCtl.h : Declaration of the CAgentCtl
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __AGENTCTL_H_
#define __AGENTCTL_H_

#include "resource.h"       // main symbols

// Macro Helpers
#define _M2STR(x) #x
#define M2STR(x) _M2STR(x)

// Change the directory names here if you have installed the Microsoft Agent
// files into a different location.  You can also pass the agent and character
// locations in using #defines
#ifndef AGENT_PATH
#import "C:\windows\msagent\agentsvr.exe" no_namespace
#else
#import M2STR(AGENT_PATH) no_namespace
#endif

#ifndef AGENT_CHAR
#define AGENT_CHARACTER "C:\\windows\\msagent\\chars\\merlin.acs"
#else
#define AGENT_CHARACTER M2STR(AGENT_CHAR)
#endif

[ object,
  uuid(1F78E174-786E-427D-8940-060F6D35AA5E),
  dual,
  helpstring("IAgentCtl Interface"),
  pointer_default(unique)
]
__interface IAgentCtl : IDispatch
{
	[id(1), helpstring("method Play")] HRESULT Play();
	[id(2), helpstring("method SpeakFile")] HRESULT SpeakFile([in] BSTR FileName);
	[id(3), helpstring("method SpeakText")] HRESULT SpeakText([in] BSTR Text);
	[propget, id(4), helpstring("property Speed")] HRESULT Speed([out, retval] long *pVal);
	[propput, id(4), helpstring("property Speed")] HRESULT Speed([in] long newVal);
	[id(5), helpstring("method Animate")] HRESULT Animate([in] BSTR Animation);
	[id(6), helpstring("method Stop")] HRESULT Stop();
};

// Accessor to bring back the instructions from the database
[
	//db_source("Provider=MSDASQL.1;Persist Security Info=False;Data Source=Agent;Extended Properties=\"DSN=Agent;DBQ=Agent;DriverId=281;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;\";Initial Catalog=Agent"),
	db_source("DSN=Agent"),
	db_table("Instruction")
]
class CInstruction
{
public:
	[db_column(ordinal="2")] TCHAR   szCommand[11];
	[db_column(ordinal="3")] TCHAR   szText[256];
};

/////////////////////////////////////////////////////////////////////////////
// CAgentCtl

[ coclass,
  uuid(9DFE0778-9727-45FD-8C2A-D1BC4299F177),
  helpstring("AgentCtl Class"),
  progid("AtlAgent.AtlAgentAttrib.1"),
  vi_progid("AtlAgent.AtlAgentAttrib"),
  default("IAgentCtl")
]
class ATL_NO_VTABLE CAgentCtl :
	public IAgentCtl,
	public IObjectSafetyImpl<CAgentCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CAgentCtl()
	{
		m_nSpeed = 10;
	}
	HRESULT FinalConstruct()
	{
		HRESULT hr = InitializeAgent();
		if (FAILED(hr))
		{
			TCHAR szText[129];
			wsprintf(szText, _T("Couldn't start Agent (0x%X)"), hr);
			MessageBox(NULL, szText, _T("ATLAgent"), 0);
			return hr;
		}

		hr = m_Instruction.OpenDataSource();
		if (FAILED(hr))
		{
			TCHAR szText[129];
			wsprintf(szText, _T("Couldn't open Agent database (0x%X)"), hr);
			MessageBox(NULL, szText, _T("ATLAgent"), 0);
		}
		m_Instruction.OpenRowset(m_Instruction);
		return hr;
	}
	HRESULT InitializeAgent()
	{
		HRESULT hr;
		long    lCharID;
		CComPtr<IDispatch>  pdCharacter;
		hr = m_pAgent.CreateInstance(__uuidof(AgentServer));
		if (FAILED(hr))
			return hr;

		hr = m_pAgent->Load(AGENT_CHARACTER, &lCharID, &m_nRequestID);
		if (FAILED(hr))
			return hr;

		hr = m_pAgent->GetCharacter(lCharID, &pdCharacter);
		if (FAILED(hr))
			return hr;

		return pdCharacter.QueryInterface(&m_pCharacter);
	}


// IAgentCtl
public:
	STDMETHOD(Stop)();
	STDMETHOD(Animate)(/*[in]*/ BSTR Animation);
	STDMETHOD(get_Speed)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Speed)(/*[in]*/ long newVal);
	STDMETHOD(SpeakText)(BSTR Text);
	STDMETHOD(SpeakFile)(BSTR FileName);
	STDMETHOD(Play)();
	void ProcessInstruction(const CInstruction& instruction);

	// Microsoft Agent stuff
	IAgentPtr           m_pAgent;
	IAgentCharacterPtr  m_pCharacter;
	long                m_nSpeed;
	long                m_nRequestID;
	// DTL stuff
	CInstruction        m_Instruction;
};

#endif //__AGENTCTL_H_
