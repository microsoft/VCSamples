// autoclik.h: defines the IDispatch classes available from AUTOCLIK.EXE
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Machine generated IDispatch driver class(es) created with MFCDSPWZ tool.

/////////////////////////////////////////////////////////////////////////////
// CAutoClik wrapper class

class CAutoClik : public COleDispatchDriver
{
// Attributes
public:
	CString GetText();
	void SetText(LPCTSTR);
	short GetX();
	void SetX(short);
	short GetY();
	void SetY(short);
	LPDISPATCH GetPosition();
	void SetPosition(LPDISPATCH);

// Operations
public:
	void RefreshWindow();
	void SetAllProps(short x, short y, LPCTSTR text);
	void ShowWindow();
};


/////////////////////////////////////////////////////////////////////////////
// CClikPoint wrapper class

class CClikPoint
{
// Attributes
public:
	short GetX();
	void SetX(short);
	short GetY();
	void SetY(short);

// Operations
public:
};
