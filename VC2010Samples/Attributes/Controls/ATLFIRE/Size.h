// Size.h: interface for the CSize class.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#if !defined(AFX_SIZE_H__479B29F2_9A2C_11D0_B696_00A0C903487A__INCLUDED_)
#define AFX_SIZE_H__479B29F2_9A2C_11D0_B696_00A0C903487A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CSize : public tagSIZE
{
public:
	CSize(){ cx = cy = 0;}
	CSize(int initCX, int initCY);
	CSize(SIZE initSize);
	CSize(POINT initPt);
	CSize(DWORD dwSize);

	// Operations
	BOOL operator==(SIZE size) const;
	BOOL operator!=(SIZE size) const;
	void operator+=(SIZE size);
	void operator-=(SIZE size);

	// Operators returning CSize values
	CSize operator+(SIZE size) const;
	CSize operator-(SIZE size) const;
	CSize operator-() const;

	// dtor
	virtual ~CSize(){}

};

inline CSize::CSize(int initCX, int initCY)
{ cx = initCX; cy = initCY; }
inline CSize::CSize(SIZE initSize)
{ *(SIZE*)this = initSize; }
inline CSize::CSize(POINT initPt)
{ *(POINT*)this = initPt; }
inline CSize::CSize(DWORD dwSize)
{
	cx = (short)LOWORD(dwSize);
	cy = (short)HIWORD(dwSize);
}
inline BOOL CSize::operator==(SIZE size) const
{ return (cx == size.cx && cy == size.cy); }
inline BOOL CSize::operator!=(SIZE size) const
{ return (cx != size.cx || cy != size.cy); }
inline void CSize::operator+=(SIZE size)
{ cx += size.cx; cy += size.cy; }
inline void CSize::operator-=(SIZE size)
{ cx -= size.cx; cy -= size.cy; }
inline CSize CSize::operator+(SIZE size) const
{ return CSize(cx + size.cx, cy + size.cy); }
inline CSize CSize::operator-(SIZE size) const
{ return CSize(cx - size.cx, cy - size.cy); }
inline CSize CSize::operator-() const
{ return CSize(-cx, -cy); }

#endif // !defined(AFX_SIZE_H__479B29F2_9A2C_11D0_B696_00A0C903487A__INCLUDED_)
