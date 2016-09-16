///////////////////////////////////////////////////////////////////////////
// DBEXCEPT.H
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

#ifndef __DBEXCEPT_H__
#define __DBEXCEPT_H__

///////////////////////////////////////////////////////////////////////////
// class COLEDBException

class COLEDBException : public CException
{
	DECLARE_DYNAMIC(COLEDBException)
public:
// Constructors and Destructors
	COLEDBException();
	COLEDBException(LPUNKNOWN lpUnk, const IID& iid);
	virtual ~COLEDBException();

// Attributes
public:
	LPUNKNOWN m_lpUnk;
	IID m_iid;
};

void AFXAPI ThrowOLEDBException(LPUNKNOWN lpUnk,
				const IID& iid);

///////////////////////////////////////////////////////////////////////////

#endif // _LATER

///////////////////////////////////////////////////////////////////////////
