// piece.h  : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef INC_PIECE_H
#define INC_PIECE_H

#define PI	3.14159265359

class CSpiroView;  // forward declaration

class CSpiroRect : public CRect
{
public:
	CSpiroRect(int l = 0, int t = 0, int r = 0, int b = 0)
	{
		SetRect(l, t, r, b);
	}

	CSpiroRect(CRect rect)
	{
		SetRect(rect.left, rect.top, rect.right, rect.bottom);
	}

	void Scale(long nNumer, long nDenom)
	{
		// *= operator is not used to avoid precision errors
		SetRect(left * nNumer / nDenom, top * nNumer / nDenom,
						right * nNumer / nDenom, bottom * nNumer / nDenom);
	}

	bool CSpiroRect::LineInRect(CPoint pt1, CPoint pt2) const
	{
		return !((pt1.x < left && pt2.x < left) || 
			(pt1.x > right && pt2.x > right) ||
			(pt1.y < bottom && pt2.y < bottom) ||
			(pt1.y > top && pt2.y > top));
	}

	// intersectrect works with MM_SPIRO mapping mode while the windows API uses MM_TEXT mode.
	bool CSpiroRect::IntersectRect(CRect* prect) const
	{
		// invert the top and bottom values and call the windows api
		CRect	rect1(this);
		CRect	rect2(prect);
		rect1.NormalizeRect();
		rect2.NormalizeRect();
		return rect1.IntersectRect(&rect1, &rect2) != 0;
	}
};

class CVector   // vectors in order to solve angle problems easily
{
public:
	double	m_dX;  // the internal representation is x and y
	double	m_dY;

public:
	CVector(long nRad, double dAngle);
	CVector(long x = 0, long y = 0);
	CVector(CPoint pt);
	CVector(CVector& vecClone);

	CVector	operator+(CVector vector2) const;
	CVector	operator-(CVector vector2) const;
	CVector	operator+(CPoint pt) const;
	CVector	operator-(CPoint pt) const;
	CVector	operator+=(CPoint pt);
	CVector&	operator=(CVector& vector2);
	CVector	operator=(CPoint pt);
	
	void SetValueLengthAngle(long nRadius, double dAngle);

	CVector CVector::operator-=(CPoint pt)
	{
		m_dX -= static_cast<double>(pt.x);
		m_dY -= static_cast<double>(pt.y);
		return *this;
	}

	operator	CPoint() const;
	double		GetAngle() const;
	long		GetLength() const;
	void		Scale(long nNumer, long nDenom);
};

#define HIT_PEN_LOCATION	1
#define HIT_NOTHING			0

class CBasePiece
{
public:
	COLORREF	m_co;
	CPoint		m_ptPos;
	bool		m_bIsWheel;  // is the piece an anchor or a wheel?
	COLORREF	m_rgCo[6];   // colors to be used while drawing current pattern
	int			m_nColorCount;  // total colors stored in m_rgCo
	int			m_icoCurrent;  // index to the current pen color 

	// Constructor, destructor
	CBasePiece(COLORREF co, bool bIsWheel = false);

	// member functions
	virtual void Draw(CDC* pDC, long nZoomNumer, long nZoomDenom) const = 0;

	  // gets bounding rect for the piece.
	virtual void GetBoundingRect(CSpiroRect* prect, long nZoomNumer, long nZoomDenom) const = 0;
	virtual bool IsWheel() const {return m_bIsWheel;}
	virtual void SetPosition(CPoint pt) = 0;

	// allow to set position using a contact point as reference.
	virtual void SetPosition(CPoint pt, double dAngle) = 0;
	virtual void GetContactPosition(CPoint poing, long nZoomNumer, long nZoomDenom,
							CPoint& ptContact, double& dAngle) = 0;

	// get the region occupied by the piece in device coords
	virtual void GetDevPieceRgn(CDC* pDC, CRgn* pRgn, 
						long nZoomNumer, long nZoomDenom, bool bInflate) const = 0;

		// Get the piece region in logical coordinates.
	virtual void GetLogPieceRgn(CRgn* pRgn, long nZoomNumer, long nZoomDenom) const = 0;

	virtual void GetPenLocation(CPoint* pPoint) const = 0;
	virtual void GetPenRect(CRect* pRect) const = 0;
	virtual bool SetPenLocation(CSpiroView* pView, CDC* pDC, CPoint point, 
						long nZoomNumer, long nZoomDenom) = 0;


	virtual int HitTest(CDC* pDC, CPoint point, //point in device coords
				long nZoomNumer, long nZoomDenom) const = 0; 

	virtual double GetPerimeter() const = 0;

	// calculates change in angle for wheel piece on every trace.
	virtual void SetAngleDelta(long nDistance, bool bReverse) = 0;

	// advance one trace on the drawing.  deltaX and deltaY indicaate to the
	// wheel what the displacement on the anchor was.
	virtual void AdvanceTrace(CPoint& ptContact, double& dAngle, 
								double& dAngleExtra, bool bMove = true) = 0;

	virtual long GetCycleError() const = 0;  // get cycle error for drawing

	// pieces having inside areas, like a normal ring, must tell the wheel to 
	// rotate clockwise when the wheel is used inside the anchor's hole.
	virtual bool ReverseWheelDirection() const = 0;
	virtual double GetFigData() const = 0;
	virtual void SetFigData(double dData) = 0;
	virtual void MovePiece(CSpiroView* pView, CPoint point, double dWheelData,
						long nZoomNumer, long nZoomDenom) = 0;

	virtual void SetWheelMode(bool bWheel = true) = 0;
#ifdef _DEBUG
	virtual long GetInternalRadius() const { return 0;}
#endif
};

#define TOTALWHEELS		7
#define STEP_DISTANCE	10

class  CWheel : public CBasePiece
{
public:

	// Data Members
	static long	m_rgnRads[TOTALWHEELS];   // Array with sizes of wheels to be used.
	static COLORREF m_rgco[TOTALWHEELS];
	static COLORREF m_rgcoPattern[TOTALWHEELS];

	long		m_nRadius;  // radius of the wheel	
	COLORREF	m_coPattern;  // color of the pattern drawn on the wheel
	double		m_angleCurrent;  // current angle of rotation of the wheel
	double		m_anglePen;		// current angle of pen in the wheel
	double		m_dAngleCorrection;  // adjustment to make Figure close perfectly
	long		m_nPenRadius;	// distance from the center to the pen

	double		m_angleDelta;   // this is the change in angle for every trace.
	
	// Constructor, destructor
	CWheel(long nRadius, COLORREF co, COLORREF coPattern);

	// Member functions

	virtual void Draw(CDC* pDC, long nZoomNumer, long nZoomDenom) const;
	virtual void GetBoundingRect(CSpiroRect* prect, long nZoomNumer, long nZoomDenom) const;
	virtual void SetPosition(CPoint pt);  // pt is the drop location from mouse click

	//overload to set position using contact point as reference
	virtual void SetPosition(CPoint pt, double dAngle);

	virtual void GetDevPieceRgn(CDC* pDC, CRgn* pRgn, 
						long nZoomNumer, long nZoomDenom, bool bInflate) const;

	// Get the piece region in logical coordinates.
	virtual void GetLogPieceRgn(CRgn* pRgn, long nZoomNumer, long nZoomDenom) const;

	//GetContactPosition is given by an anchor to indicate the point of contact
	//with the anchor and the angle at which the wheel should be moving away from
	// the anchor.  Used for positioning wheels on an anchor.
	virtual void GetContactPosition(CPoint point, long nZoomNumer, long nZoomDenom,
								CPoint& ptContact, double& dAngle);

	virtual void GetPenLocation(CPoint* pPoint) const;
	virtual void GetPenRect(CRect* prect) const;
	virtual bool SetPenLocation(CSpiroView* pView, CDC* pDC, CPoint point,
								long nZoomNumer, long nZoomDenom);

	virtual int HitTest(CDC* pDC, CPoint point, long nZoomNumer, long nZoomDenom) const;
	virtual double GetPerimeter() const;

	// calculates change in angle for wheel piece on every trace.
	virtual void SetAngleDelta(long nDistance, bool bReverse);

	// advance one trace on the drawing.  deltaX and deltaY indicaate to the
	// wheel what the displacement on the anchor was.
	virtual void AdvanceTrace(CPoint& ptContact, double& dAngle,
									double& dAngleExtra, bool bMove = true);

	virtual long GetCycleError() const;
	virtual bool ReverseWheelDirection() const;
	virtual double GetFigData() const;
	virtual void SetFigData(double dData);
	virtual void MovePiece(CSpiroView* pView, CPoint point, double dWheelData,
						long nZoomNumer, long nZoomDenom);

	virtual void SetWheelMode(bool bWheel = true);
};

#define  TOTALRINGS	4
#define  RINGWIDTH	25   // make every ring .35 inches wide.

class CRing : public CWheel
{
public:
	// Data Members
	static long m_rgnRads[TOTALRINGS];  // external radius of the ring
	static COLORREF m_rgco[TOTALRINGS];  // array of colors for the different rings

	long	m_nRadiusInt;
	bool	m_bWheelInside;

	// Constructor, destructor
	CRing(long nRadiusIn, long nRadiusOut, 
					COLORREF co, COLORREF coPattern = 0);

	// Member functions
	virtual void Draw(CDC* pDC, long nZoomNumer, long nZoomDenom) const;
	void GetInnerRect(CSpiroRect* pRect, long nZoomNumer, long nZoomDenom) const;

	// Get the piece rgn in device coordinates
	virtual void GetDevPieceRgn(CDC* pDC, CRgn* pRgn, 
					long nZoomNumer, long nZoomDenom, bool bInflate) const;

	// Get the piece region in logical coordinates.
	virtual void GetLogPieceRgn(CRgn* pRgn, long nZoomNumer, long nZoomDenom) const;

	virtual void GetContactPosition(CPoint point, long nZoomNumer, long nZoomDenom,
											CPoint& ptContact, double& dAngle);

	virtual double GetPerimeter() const;

	// calculates change in angle for wheel piece on every trace.
	virtual void SetAngleDelta(long nDistance, bool bReverse);

	// advance one trace on the drawing.  deltaX and deltaY indicaate to the
	// wheel what the displacement on the anchor was.
	virtual void AdvanceTrace(CPoint& ptContact, double& dAngle, 
											double& dAngleExtra, bool bMove = true);

	virtual long GetCycleError() const;
	virtual bool ReverseWheelDirection() const;

#ifdef _DEBUG
	virtual long GetInternalRadius() const {return m_nRadiusInt;}
#endif
};

#endif //INC_PIE_H