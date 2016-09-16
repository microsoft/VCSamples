// Swarm.h : Defines the interfaces for the swarm motion classes.
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

class CLeader;
class CLlama;

typedef CAtlArray<CLlama *>  CLlamaArray;
typedef CAtlArray<CLeader *> CLeaderArray;

class CSwarm
{
public:
	CSwarm();
	~CSwarm();

	void Initialize(CSurface *pSurface, int nLeaders, int nLlamas, const CSize &size);
	void Tick();

	// Properties
	int GetHeight() const		{ return(m_nHeight); }
	int GetWidth() const		{ return(m_nWidth); }
	int GetBorder() const		{ return(m_nBorder); }
	int GetAge() const 			{ return(m_nAge); }
 
	size_t GetLlamaCount() const	{ return(m_LlamaArr.GetCount()); }
	size_t GetLeaderCount() const	{ return(m_LeaderArr.GetCount()); }
	CSurface *GetSurface() const	{ return(m_pSurf); }

private:
	// Implementation
	void Destroy();
	CLeader *GetLeader();

	// Data
	int m_nHeight;
	int m_nWidth;
	int m_nBorder; // How close the the edge can leaders go.
	int m_nAge;    // How old is the swarm.
	CLeaderArray m_LeaderArr;
	CLlamaArray  m_LlamaArr;
	CSurface *m_pSurf;
};

struct CRoamer
{
	virtual ~CRoamer() { } // Virtual destructors for derived classes
	void Bounce(long &value, const int lower, const int upper, int &vel);
	static int DeltaRandom(int i) { return(Random(i) - i/2); }
	CPoint p1;	// front
	CPoint p2;	// back
	int dx, dy;	// velocity
};

class CLlama : public CRoamer
{
public:
	void Init(CSwarm *pSwarm);
	void Kick();
	void Tick(CSwarm *pSwarm, const CLeaderArray &Leaders);

private:
	COLORREF m_color;
	size_t	 m_idxLeader; // index of the current leader
};

class CLeader : public CRoamer
{
public:
	CLeader();
	virtual void SetSwarm(CSwarm *pSwarm);

	virtual void Tick();
	virtual COLORREF GetLlamaColor(COLORREF oldColor) = 0;
	virtual COLORREF GetInitialLlamaColor() = 0;

	int GetLlamaAcc() const { return(m_nLlamaAcc); }
	int GetLlamaVel() const { return(m_nLlamaVel); }

	void Import(const CLeader *pRHS);
protected:
	static COLORREF HSB(BYTE H, BYTE S, BYTE B);
	int m_nMyAcc;
	int m_nMyVel;
	int m_nLlamaAcc;
	int m_nLlamaVel;

private:
	CSwarm *m_pSwarm;
};

// Cycle all bright hues
class CBrightLeader : public CLeader
{
public:
	CBrightLeader();
	virtual void Tick();
	virtual COLORREF GetLlamaColor(COLORREF oldColor);
	virtual COLORREF GetInitialLlamaColor();
private:
	static COLORREF m_sColorTable[256];
	int m_nColorCounter;
};

// Cycle through one hue
class CHueLeader : public CLeader
{
public:
	CHueLeader();
	virtual void Tick();
	virtual COLORREF GetLlamaColor(COLORREF oldColor);
	virtual COLORREF GetInitialLlamaColor();
private:
	COLORREF m_ColorTable[256];
	int m_nColorCounter;
};

///////////////////////////////////////////////////////////////////////
inline void CRoamer::Bounce(long &value, const int lower, const int upper, int &vel)
{
    if (value < lower) {
        vel *= -1;
        value = lower;
    }
    else if (value >= upper) {
        vel *= -1;
        value = upper-1;
    }
}
