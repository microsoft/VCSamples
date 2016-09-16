// shapeobj.h : interface of the CShape class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

enum SHAPE_STYLE
{
	rectangle,
	rounded_rectangle,
	ellipse,
};

enum SHAPE_COLOR_ENUM
{
	black,
	red,
	green,
	blue,
};

struct SHAPE_COLOR
{
	SHAPE_COLOR_ENUM e;
	operator COLORREF() const;
	const SHAPE_COLOR& operator = (COLORREF colorref);
	operator int() const;
	const SHAPE_COLOR& operator = (int n);
};

class CShape : public CObject
{
public:
	CShape();
	CShape(SHAPE_COLOR_ENUM colorenum, SHAPE_STYLE shapestyle, CRect& rect);
	DECLARE_SERIAL(CShape)

	SHAPE_COLOR m_shapecolor;
	SHAPE_STYLE m_shapestyle;
	CRect       m_rect;

	void Draw(CDC* pDC, BOOL bSelected);
	virtual void Serialize(CArchive& ar);
};
