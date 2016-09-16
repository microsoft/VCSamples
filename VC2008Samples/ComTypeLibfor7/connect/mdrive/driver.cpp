// Driver.cpp : Implementation of CDriveApp and DLL registration.

#include "premdriv.h"
#include "Driver.h"

extern HDC hDrawDC;
extern unsigned int nHeight;
extern unsigned int nThreads;

LONG g_cLockCnt = 0L;
LONG g_cObjCnt = 0L;
/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CRandomEvent::put_Fire(long l)
{
    m_cs.Lock();
    foo pos;
    if (!m_mapPos.Lookup(l, pos))
    {
        m_mapPos[l] = foo();
    }
    COLORREF cr = RGB(255,255,255);
    switch (l)
    {
    case 0:
        cr = RGB(255,0,0);
        break;
    case 1:
        cr = RGB(0,255,0);
        break;
    case 2:
        cr = RGB(0,0,255);
        break;
    case 3:
        cr = RGB(255,255,0);
        break;
    case 4:
        cr = RGB(255,0,255);
        break;
    case 5:
        cr = RGB(0,255,255);
        break;
    case 6:
        cr = RGB(64,64,64);
        break;
    case 7:
        cr = RGB(128,128,128);
        break;
    case 8:
        cr = RGB(192,192,192);
        break;
    case 9:
        cr = RGB(0,0,0);
        break;
    }
    int nH = nHeight/nThreads;
    if (pos.nDir == 1)
        SetPixel(hDrawDC, m_nID, nH*l+pos.nPos, cr);
    else
        SetPixel(hDrawDC, m_nID, nH*l+pos.nPos, RGB(0,0,0));
    pos.nPos += pos.nDir;
    if (pos.nPos >= nH)
    {
        pos.nDir = -1;
        pos.nPos = nH-1;
    }
    if (pos.nPos <= -1)
    {
        pos.nDir = 1;
        pos.nPos = 0;
    }
    m_mapPos[l] = pos;
    m_cs.Unlock();
    GdiFlush();
    return S_OK;
}
