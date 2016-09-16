// Random.h : Declaration of the CRandom
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "connres.h"       // main symbols

[ object,
  uuid(B8903D31-78AD-4AB4-A543-D1405EE5C6BF),
  dual,
  helpstring("IRandom Interface"),
  pointer_default(unique)
]
__interface IRandom : IDispatch
{
	HRESULT Start([out]long* pnID);
	HRESULT Stop([in]long nID);
	HRESULT StopAll();
};

[ uuid(6E890B4C-3E95-4728-BED1-6C48FFB1071D),
  dual,
  helpstring("IRandomEvent Interface"),
  pointer_default(unique)
]
__interface IRandomEvent : IDispatch
{
	[id(0)] HRESULT Fire([in]long nID);
};

/////////////////////////////////////////////////////////////////////////////
// CRandom

const int nMaxSessions = 10;
[ coclass,
  uuid(0DC9A419-477C-453E-861E-F0DE3EB3E1DE),
  helpstring("Random Attrib Class"),
  progid("Connect.ConnectAttrib.1"),
  vi_progid("Connect.ConnectAttrib"),
  default("IRandom"),
  support_error_info("IRandom"),
  event_source(com)
]
class CRandom :
	public IRandom
{
public:
	CRandom()
	{
		memset(m_rsArray, 0, nMaxSessions*sizeof(RandomSessionData));
	}
	~CRandom();

__event __interface IRandomEvent;

// IRandom
	STDMETHOD(Start)(long* pnID);
	STDMETHOD(Stop)(long nID);
	STDMETHOD(StopAll)();



	// info associated to each session
	struct RandomSessionData
	{
		CRandom* pRandom;
		HANDLE m_hEvent;
		HANDLE m_hThread;
		int m_nID;
	};
protected:

	RandomSessionData m_rsArray[nMaxSessions];
	void CreateRandomSession(RandomSessionData& rs);

	_ThreadModel::AutoCriticalSection m_cs;
};
