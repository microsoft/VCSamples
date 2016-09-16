// Swarm.cpp : implementation of the CSwarm class
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
#include "stdafx.h"
#include "Swarm.h"

COLORREF CBrightLeader::m_sColorTable[256] = { 0 };

///////////////////////////////////////////////////////////////////////
// Swarm
CSwarm::CSwarm() :
	m_pSurf(NULL)
{

}

CSwarm::~CSwarm()
{
	Destroy();
}

void CSwarm::Destroy()
{
	for (size_t i = 0; i < m_LeaderArr.GetCount(); i++)
		delete m_LeaderArr[i];

	for (size_t i = 0; i < m_LlamaArr.GetCount(); i++)
		delete m_LlamaArr[i];

	m_LeaderArr.SetCount(0);
	m_LlamaArr.SetCount(0);
	m_pSurf = NULL;
}
void CSwarm::Initialize(CSurface *pSurf, int nLeaders, int nLlamas, const CSize &size)
{
	Destroy();
	m_nWidth = size.cx;
	m_nHeight = size.cy;

	if (!m_nHeight || !m_nWidth)
		return;

	m_pSurf = pSurf;
	m_nAge = 0;
	m_nBorder = (m_nWidth + m_nHeight) / 50;
	m_LeaderArr.SetCount(nLeaders);
	m_LlamaArr.SetCount(nLlamas);

	for (int i = 0; i < nLeaders; i++) {
		m_LeaderArr[i] = GetLeader();
	}

	for (int i = 0; i < nLlamas; i++) {
		m_LlamaArr[i] = new CLlama();
		m_LlamaArr[i]->Init(this);
	}
}

CLeader *CSwarm::GetLeader()
{
	CLeader *pLeader = NULL;
	switch (Random(2)) {
	case 0:
		pLeader = new CBrightLeader();
		break;
	case 1:
		pLeader = new CHueLeader();
		break;
	}
	ASSERT(pLeader != NULL);
	pLeader->SetSwarm(this);
	return(pLeader);
}

void CSwarm::Tick()
{
	size_t nLeaderCount = m_LeaderArr.GetCount();
	size_t nLlamaCount = m_LlamaArr.GetCount();
	m_nAge++;
	// Very occasionally change a swarm type
	if ((Random() & 0x7f) == 0x7f) {
		size_t nIdx = m_nAge % nLeaderCount;
		CLeader *pLeader = GetLeader();
		pLeader->Import(m_LeaderArr[nIdx]);
		delete m_LeaderArr[nIdx];
		m_LeaderArr[nIdx] = pLeader;
	}
	// Kick a few Llamas
	size_t nKickCount = nLeaderCount;
	for (size_t i = 0; i < nKickCount; i++) {
		m_LlamaArr[Random(int(nLlamaCount))]->Kick();
	}

	for (size_t i = 0; i < nLlamaCount; i++) {
		m_LlamaArr[i]->Tick(this, m_LeaderArr);
	}

	for (size_t i = 0; i < nLeaderCount; i++) {
		m_LeaderArr[i]->Tick();
	}
}

///////////////////////////////////////////////////////////////////////
// Llama
void CLlama::Init(CSwarm *pSwarm)
{
	p1.x = p2.x = Random(max(1, (pSwarm->GetWidth())));
    p1.y = p2.y = Random(max(1, (pSwarm->GetHeight())));
    dx = dy = 0;
	m_idxLeader = (size_t)-1;
}

void CLlama::Kick()
{
	dx += DeltaRandom(3);
	dy += DeltaRandom(3);
}

void CLlama::Tick(CSwarm *pSwarm, const CLeaderArray &leaders)
{
	CPoint ptClosestDelta;
    int nClosestDist = INT_MAX;
	size_t nLeaders = leaders.GetCount();
	size_t idxClosest = 0;

    p2 = p1;
    for (size_t i = 0; i < nLeaders; i++) {
        CPoint leader(leaders[i]->p2); // pos of leader
        int nDist;
		CPoint ptRel(leader.x - p2.x, leader.y - p2.y);
        nDist = max(1, ABS(ptRel.x) + ABS(ptRel.y)); // approximation
        if (nDist < nClosestDist) {
			nClosestDist = nDist;
			idxClosest = i;
			ptClosestDelta = ptRel;
        }
    }

	CLeader *pClosest = leaders[idxClosest];
	// Did we switch leaders?
	if (idxClosest != m_idxLeader) {
		m_idxLeader = idxClosest;
		m_color = pClosest->GetInitialLlamaColor();
	}

    // Accelerate
	int acc = pClosest->GetLlamaAcc();
    dx += (ptClosestDelta.x * acc) / (nClosestDist*2);
    dy += (ptClosestDelta.y * acc) / (nClosestDist*2);

    // Speed Limit Checks
	int vel = pClosest->GetLlamaVel();
    dx = max(min(dx, vel), -vel);
    dy = max(min(dy, vel), -vel);

    // Move and bound check
    p1.x += dx;
    p1.y += dy;

    Bounce(p1.x, 0, pSwarm->GetWidth(), dx);
    Bounce(p1.y, 0, pSwarm->GetHeight(), dy);
    m_color = pClosest->GetLlamaColor(m_color);

	// Draw
	pSwarm->GetSurface()->Line(p1, p2, m_color);
}

///////////////////////////////////////////////////////////////////////
// Leader
CLeader::CLeader()
{
	m_nMyAcc = 5;
	m_nMyVel = 10;
	m_nLlamaAcc = 5; // this is scaled back 1/2 when used
	m_nLlamaVel = 12;
}

void CLeader::SetSwarm(CSwarm *pSwarm)
{
	m_pSwarm = pSwarm;
	int nBorder = m_pSwarm->GetBorder();
	p1.x = p2.x = nBorder + Random(max(1, (m_pSwarm->GetWidth() - 2*nBorder)));
    p1.y = p2.y = nBorder + Random(max(1, (m_pSwarm->GetHeight() - 2*nBorder)));
    dx = dy = 0;
}

void CLeader::Import(const CLeader *pRHS)
{
	m_pSwarm = pRHS->m_pSwarm;
	p1 = pRHS->p1;
	p2 = pRHS->p2;
	dx = pRHS->dx;
	dy = pRHS->dy;
}

void CLeader::Tick()
{
    p2 = p1;

    // accelerate the leader
    dx += DeltaRandom(m_nMyAcc);
    dy += DeltaRandom(m_nMyAcc);

    // Speed Limit Checks
    dx = max(min(dx, m_nMyVel), -m_nMyVel);
    dy = max(min(dy, m_nMyVel), -m_nMyVel);

    // Move
    p1.x += dx;
    p1.y += dy;

    // Bounce Checks
	int nBorder = m_pSwarm->GetBorder();
	int nHeight = m_pSwarm->GetHeight();
	int nWidth = m_pSwarm->GetWidth();
    Bounce(p1.x, nBorder, nWidth-nBorder-1, dx);
    Bounce(p1.y, nBorder, nHeight-nBorder-1, dy);

	// Draw
	m_pSwarm->GetSurface()->Line(p1, p2, RGB(255,255,255));
}

COLORREF CLeader::HSB(BYTE H, BYTE S, BYTE B)
{
    unsigned char p, q, t;

    int i = (int) H * 6 / 256;
    float s = ((float) S) / (float) 255.0;
    float f = ((float) (H * 6 - i * 256)) / (float) 255.0;
    p = (BYTE) (B * (1.0 - s));
    q = (BYTE) (B * (1.0 - (s * f)));
    t = (BYTE) (B * (1.0 - (s * (1.0 - f))));
    switch (i) {
    case 0:
        return RGB(B, t, p);
    case 1:
        return RGB(q, B, p);
    case 2:
        return RGB(p, B, t);
    case 3:
        return RGB(p, q, B);
    case 4:
        return RGB(t, p, B);
    case 5:
        return RGB(B, p, q);
    }

    // should never reach here
    ASSERT(FALSE);
    return RGB(255, 255, 255);
}

///////////////////////////////////////////////////////////////////////
// BrightLeader
CBrightLeader::CBrightLeader()
{
	if (m_sColorTable[0] == 0) { // 1 time init
		for (int i = 0; i <= 255; i++) {
		    m_sColorTable[i] = HSB((BYTE)i, 255, 255);
		}
	}
	m_nColorCounter = Random(256);
}

void CBrightLeader::Tick()
{
	if (++m_nColorCounter > 255)
		m_nColorCounter = 0;
	__super::Tick();
}

COLORREF CBrightLeader::GetLlamaColor(COLORREF /*oldColor*/)
{
	return(m_sColorTable[m_nColorCounter]);
}

COLORREF CBrightLeader::GetInitialLlamaColor()
{
	return(m_sColorTable[m_nColorCounter]);
}

///////////////////////////////////////////////////////////////////////
// HueLeader
CHueLeader::CHueLeader()
{
	BYTE hue = (BYTE)Random(256);
    for (int i = 0; i <= 127; i++) {
		int j = min(i+32, 127);
        m_ColorTable[i] = HSB(hue, 255, (BYTE)j*2);
    }
    for (int i = 128; i <= 255; i++) {
		int j = max(i-32, 128);
        m_ColorTable[i] = HSB(hue, 255, (BYTE)(511-j*2));
    }
	m_nColorCounter = Random(256);
}

void CHueLeader::Tick()
{
	if (++m_nColorCounter > 255)
		m_nColorCounter = 0;
	__super::Tick();
}

COLORREF CHueLeader::GetLlamaColor(COLORREF /*oldColor*/)
{
	return(m_ColorTable[m_nColorCounter]);
}

COLORREF CHueLeader::GetInitialLlamaColor()
{
	return(m_ColorTable[m_nColorCounter]);
}

