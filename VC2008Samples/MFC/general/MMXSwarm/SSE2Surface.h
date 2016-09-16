// SSE2Surface.h : interface of the SSE2 Specific Surface classes
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once
#include "Surface.h"

class CSSE2Surface32Intrinsic : public CSurface
{
public:
    virtual void AdjustWidth(int *pWidth);
    virtual void BlurBits(); // this is where the MMX action is
protected:
	virtual void OnCreated();
private:
	int m_qwpl;  // qwords per line
	int m_width; // number of times to iterate per line
};

class CSSE2Surface24Intrinsic : public CSurface
{
public:
    virtual void AdjustWidth(int *pWidth);
    virtual void BlurBits(); // this is where the MMX action is
protected:
	virtual void OnCreated();
private:
	int m_qwpl;  // qwords per line
	int m_width; // number of times to iterate per line
	int m_delta;
};

class CSSE2Surface16Intrinsic : public CSurface
{
public:
    virtual void AdjustWidth(int *pWidth);
    virtual void BlurBits(); // this is where the MMX action is
protected:
	virtual void OnCreated();
private:
	int m_qqwpl;  // qwords per line
	int m_width; // number of times to iterate per line
};
