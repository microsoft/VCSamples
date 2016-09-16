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

/////////////////////////////////////////////////////////////////////////////
// CRemoteCalcDlg wrapper class

class CRemoteCalcDlg : public COleDispatchDriver
{
// Attributes
public:
	long GetAccum();
	void SetAccum(long);
	long GetOperand();
	void SetOperand(long);
	short GetOperation();
	void SetOperation(short);
	BOOL GetVisible();
	void SetVisible(BOOL);

// Operations
public:
	BOOL Evaluate();
	void Clear();
	void Display();
	void Close();
	BOOL Button(LPCTSTR szButton);
};
