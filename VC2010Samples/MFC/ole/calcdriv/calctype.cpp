// Machine generated IDispatch driver class(es) created with ClassWizard.
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
#include "calctype.h"

/////////////////////////////////////////////////////////////////////////////
// CRemoteCalcDlg properties

long CRemoteCalcDlg::GetAccum()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void CRemoteCalcDlg::SetAccum(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

long CRemoteCalcDlg::GetOperand()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void CRemoteCalcDlg::SetOperand(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

short CRemoteCalcDlg::GetOperation()
{
	short result;
	GetProperty(0x3, VT_I2, (void*)&result);
	return result;
}

void CRemoteCalcDlg::SetOperation(short propVal)
{
	SetProperty(0x3, VT_I2, propVal);
}

BOOL CRemoteCalcDlg::GetVisible()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CRemoteCalcDlg::SetVisible(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CRemoteCalcDlg operations

BOOL CRemoteCalcDlg::Evaluate()
{
	BOOL result;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

void CRemoteCalcDlg::Clear()
{
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CRemoteCalcDlg::Display()
{
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CRemoteCalcDlg::Close()
{
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL CRemoteCalcDlg::Button(LPCTSTR szButton)
{
	BOOL result;
	static BYTE BASED_CODE parms[] =
		VTS_BSTR;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		szButton);
	return result;
}
