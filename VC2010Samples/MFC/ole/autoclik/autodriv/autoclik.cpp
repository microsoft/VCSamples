// Machine generated IDispatch wrapper class(es) created with ClassWizard
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "autoclik.h"

/////////////////////////////////////////////////////////////////////////////
// CAutoClik properties

CString CAutoClik::GetText()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CAutoClik::SetText(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

short CAutoClik::GetX()
{
	short result;
	GetProperty(0x2, VT_I2, (void*)&result);
	return result;
}

void CAutoClik::SetX(short propVal)
{
	SetProperty(0x2, VT_I2, propVal);
}

short CAutoClik::GetY()
{
	short result;
	GetProperty(0x3, VT_I2, (void*)&result);
	return result;
}

void CAutoClik::SetY(short propVal)
{
	SetProperty(0x3, VT_I2, propVal);
}

LPDISPATCH CAutoClik::GetPosition()
{
	LPDISPATCH result;
	GetProperty(0x4, VT_DISPATCH, (void*)&result);
	return result;
}

void CAutoClik::SetPosition(LPDISPATCH propVal)
{
	SetProperty(0x4, VT_DISPATCH, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoClik operations

void CAutoClik::RefreshWindow()
{
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CAutoClik::SetAllProps(short x, short y, LPCTSTR text)
{
	static BYTE BASED_CODE parms[] =
		VTS_I2 VTS_I2 VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 x, y, text);
}

void CAutoClik::ShowWindow()
{
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
/////////////////////////////////////////////////////////////////////////////
// CClikPoint properties

short CClikPoint::GetX()
{
	short result;
	GetProperty(0x1, VT_I2, (void*)&result);
	return result;
}

void CClikPoint::SetX(short propVal)
{
	SetProperty(0x1, VT_I2, propVal);
}

short CClikPoint::GetY()
{
	short result;
	GetProperty(0x2, VT_I2, (void*)&result);
	return result;
}

void CClikPoint::SetY(short propVal)
{
	SetProperty(0x2, VT_I2, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CClikPoint operations
