// Driver.h : Declaration of the CDriver
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "mdrivres.h"       // main symbols
#include <afxtempl.h>

/////////////////////////////////////////////////////////////////////////////
// Drive
struct foo
{
	foo() {nPos = 0;nDir=1;}
	int nPos;
	int nDir;
};

class CDriver :
	public IDispatchImpl<IRandomEvent, &IID_IRandomEvent, &LIBID_CONNECTLib>,
	public CComObjectRoot
{
public:
	CDriver() {}
BEGIN_COM_MAP(CDriver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IRandomEvent)
END_COM_MAP()

// IRandomEvent
	STDMETHOD(Fire)(long l);
	int m_nID;
	CMap<long, long, foo, foo> m_mapPos;
	_ThreadModel::AutoCriticalSection m_cs;
public:
};
