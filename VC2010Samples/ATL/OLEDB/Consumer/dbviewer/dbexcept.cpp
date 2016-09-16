///////////////////////////////////////////////////////////////////////////
// DBEXCEPT.CPP
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "dbexcept.h"

IMPLEMENT_DYNAMIC(COLEDBException, CException)


///////////////////////////////////////////////////////////////////////////
// COLEDBException

COLEDBException::COLEDBException()
{
	m_lpUnk = NULL;
}

COLEDBException::COLEDBException(LPUNKNOWN lpUnk, const IID& iid)
{
	m_lpUnk = lpUnk;
	if (m_lpUnk != NULL)
		m_lpUnk->AddRef();
	m_iid = iid;
}

COLEDBException::~COLEDBException()
{
	if (m_lpUnk != NULL)
	{
		m_lpUnk->Release();
		m_lpUnk = NULL;
	}
}

void AFXAPI ThrowOLEDBException(LPUNKNOWN lpUnk, const IID& iid)
{
	THROW(new COLEDBException(lpUnk, iid));
}
