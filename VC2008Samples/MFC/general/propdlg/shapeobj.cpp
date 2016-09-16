// shapeobj.cpp
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
#include "propdlg.h"

#include "shapeobj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_SERIAL(CShape, CObject, 0)

CShape::CShape()
{
	m_shapecolor = black;
	m_shapestyle = rectangle;
	m_rect = CRect(0,0,0,0);
}

CShape::CShape(SHAPE_COLOR_ENUM colorenum, SHAPE_STYLE shapestyle,
	CRect& rect)
	: m_shapestyle(shapestyle), m_rect(rect)
{
	m_shapecolor.e = colorenum;
}

void CShape::Draw(CDC* pDC, BOOL bSelected)
{
	CPen* pPenOld = NULL;
	CPen penNew;
	if (bSelected)
	{
		penNew.CreatePen(PS_DOT, 1, RGB(0,0,0));
		pPenOld = pDC->SelectObject(&penNew);
	}

	CBrush brushNew((COLORREF)m_shapecolor);
	CBrush* pBrushOld = pDC->SelectObject(&brushNew);
	switch (m_shapestyle)
	{
		case rectangle:
			pDC->Rectangle(m_rect);
			break;
		case rounded_rectangle:
			pDC->RoundRect(m_rect,
				CPoint(m_rect.Width()/8, m_rect.Height()/8));
			break;
		case ellipse:
			pDC->Ellipse(m_rect);
			break;
	}

	pDC->SelectObject(pBrushOld);
	if (pPenOld != NULL)
		pDC->SelectObject(pPenOld);
}

void CShape::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)m_shapecolor.e;
		ar << (WORD)m_shapestyle;
		ar << m_rect;
	}
	else
	{
		WORD n;
		ar >> n;
		m_shapecolor.e = (SHAPE_COLOR_ENUM)n;
		ar >> n;
		m_shapestyle = (SHAPE_STYLE)n;
		ar >> m_rect;
	}
}


SHAPE_COLOR::operator COLORREF() const
{
	switch (e)
	{
		case black: return RGB(0,0,0);
		case red: return RGB(255,0,0);
		case green: return RGB(0,255,0);
		case blue: return RGB(0,0,255);
	}
	ASSERT(FALSE);
	return 0;
}

const SHAPE_COLOR& SHAPE_COLOR::operator = (COLORREF colorref)
{
	switch (colorref)
	{
		case RGB(0,0,0): e = black; break;
		case RGB(255,0,0): e =  red; break;
		case RGB(0,255,0): e = green; break;
		case RGB(0,0,255): e = blue; break;
	}
	ASSERT(FALSE);
	e = black;
	return *this;
}

SHAPE_COLOR::operator int() const
{
	return (int)e;
};

const SHAPE_COLOR& SHAPE_COLOR::operator = (int n)
{
	e = (SHAPE_COLOR_ENUM)n;
	return *this;
};
