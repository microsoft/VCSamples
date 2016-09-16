// Surface.h : Defines the interface of a DIB surface for swarm
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

#include <AtlImage.h>

template<class T> T ABS(T x) { return(x < 0 ? -x : x); }

class CSurface
{
public:
	CSurface() :
		m_pSrcWnd(NULL), m_hDestDC(NULL),
		m_wndHeight(0), m_wndWidth(0), m_nBitDepth(0), m_nByteDepth(0)
	{ }

	virtual ~CSurface()
	{ Destroy(); }

	void Create(CWnd *pWnd, int nBitDepth); // this is stored internally
	void Destroy();

	void Import(const CImage &image);

    void ClearBits();
    void StripeBits();
    void RandomBits();
    void ShiftBits();
    void BlitBits();
    virtual void BlurBits(); // this is where the MMX action is

    void Line(const CPoint &p1, const CPoint &p2, COLORREF c);
    void RandomLine(COLORREF c);

	// These methods compensate for m_kDelta
    void PointColor(int x, int y, COLORREF c);
    COLORREF PointColor(int x, int y) const;
	BYTE *GetPixelAddress(int x, int y) const
	{ return((BYTE*)m_image.GetPixelAddress(x, y+m_kDeltaY)); }

	bool IsNull() const
	{ return(m_image.IsNull()); }
	int GetVisibleWidth() const
	{ return(m_wndWidth); }
	int GetVisibleHeight() const
	{ return(m_wndHeight); }
	int GetPitch() const
	{ return(m_image.GetPitch()); }
	int GetBitDepth() const
	{ return(m_nBitDepth); }
	int GetByteDepth() const
	{ return(m_nByteDepth); }

	CImage *GetImage()
	{ return(&m_image); }

// Implementation
protected:
	virtual void AdjustWidth(int * /*pWidth */)	{}
	virtual void OnCreated() {}

	static const int m_kDeltaX = 1;
	static const int m_kDeltaY = 1;
private:
	CWnd *m_pSrcWnd;
   	HDC m_hDestDC;
	CImage m_image;
	int m_nByteDepth;
	int m_nBitDepth;
	int m_wndWidth;
	int m_wndHeight;
};

inline void CSurface::PointColor(int x, int y, COLORREF c)
{
	// m_image.SetPixel() call ::SetPixel() which is too slow
	// since it has to work with all DCs.

	BYTE *p = (BYTE*)m_image.GetPixelAddress(x, y+m_kDeltaY);
	if (m_nBitDepth == 16) {
		*(WORD *)p = (WORD)(((c&0xf80000) >> 19) | ((c&0xf800) >> 6) | ((c&0xf8) << 7));
	}
	else {
	    *p++ = GetBValue(c);
    	*p++ = GetGValue(c);
    	*p = GetRValue(c);
	}
}

// Somewhat poor form - for performance reasons these
// come back with R and B exchanged.
inline COLORREF CSurface::PointColor(int x, int y) const
{ 
	// m_image.GetPixel() calls ::GetPixel() which is too slow
	// since it has to work for all types of DCs.
	if (m_nBitDepth == 16) {
	    COLORREF c = (COLORREF)*(WORD*)m_image.GetPixelAddress(x, y+m_kDeltaY);
	    return((c&0x7c00) << 9 | (c&0x3e0) << 6 | (c&0x1f) << 3);		
	}
	else {
		return(*(COLORREF*)(m_image.GetPixelAddress(x, y+m_kDeltaY))); 
	}
}
