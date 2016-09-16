// piece.cpp  : implementation file
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
#include <math.h>
#include "piece.h"

extern CSpiroView* g_pView;

//=====================================================================
//CSpiroRect Class Members


//=====================================================================
//CVector Class Members
CVector::CVector(long x, long y)
{
	m_dX = (double)x;
	m_dY = (double)y;
}

CVector::CVector(long nRadius, double dAngle)
{
	m_dX = nRadius * cos(dAngle);
	m_dY = nRadius * sin(dAngle);
}

void CVector::SetValueLengthAngle(long nRadius, double dAngle)
{
	m_dX = nRadius * cos(dAngle);
	m_dY = nRadius * sin(dAngle);
}

CVector::CVector(CPoint pt)
{
	m_dX = static_cast<double>(pt.x);
	m_dY = static_cast<double>(pt.y);
}

CVector::CVector(CVector& vector2)
{
	*this = vector2;
}

__inline CVector CVector::operator+(CVector vector2) const
{
	CVector vecSum((long)(m_dX + vector2.m_dX), (long)(m_dY + vector2.m_dY));
	return vecSum;
}

__inline CVector CVector::operator-(CVector vector2) const
{
	CVector vecDiff((long)(m_dX - vector2.m_dX), (long)(m_dY - vector2.m_dY));
	return vecDiff;
}

__inline CVector CVector::operator+=(CPoint pt)
{
	m_dX += static_cast<double>(pt.x);
	m_dY += static_cast<double>(pt.y);
	return *this;
}

__inline CVector CVector::operator+(CPoint pt) const
{
	CVector vectFinal;
	vectFinal.m_dX = m_dX + pt.x;
	vectFinal.m_dY = m_dY + pt.y;
	return vectFinal;
}

__inline CVector CVector::operator-(CPoint pt) const
{
	CVector vectFinal;
	vectFinal.m_dX = m_dX + pt.x;
	vectFinal.m_dY = m_dY + pt.y;
	return vectFinal;
}

__inline void CVector::Scale(long nNumer, long nDenom)
{
	double dFactor = (double)nNumer / (double) nDenom;
	m_dX *= dFactor;
	m_dY *= dFactor;
}

__inline CVector::operator CPoint() const
{
	CPoint ptRet(static_cast<long>(m_dX), static_cast<long>(m_dY));
	return ptRet;
}

__inline CVector& CVector::operator=(CVector& vector2)
{
	m_dX = vector2.m_dX;
	m_dY = vector2.m_dY;
	return *this;
}

__inline CVector CVector::operator=(CPoint pt)
{
	m_dX = pt.x;
	m_dY = pt.y;
	return *this;
}

double CVector::GetAngle() const
{
	if (m_dX == 0 && m_dY > 0)  // the angle is pi/2
		return PI / 2.0;

	if (m_dX == 0 && m_dY < 0)
		return 1.5 * PI;

	if (m_dX ==0 && m_dY == 0)
		return 0;

	double dAngle = atan(m_dY / m_dX);
	if (m_dY <= 0 && m_dX < 0 || m_dY > 0 && m_dX < 0)
		dAngle += PI;

	return dAngle;
}

long CVector::GetLength() const
{
	double dSqLen = m_dX * m_dX + m_dY * m_dY;
	return static_cast<long>(sqrt(dSqLen));
}

//=====================================================================
// CBasePiece class members

CBasePiece::CBasePiece(COLORREF co, bool bIsWheel) : 
						m_ptPos(0, 0)
{
	m_co = co;
	m_bIsWheel = bIsWheel;
	m_nColorCount = 1;
	m_icoCurrent = -1;
	memset(m_rgCo, 0, sizeof(m_rgCo));   // the current color is black, which is 0 anyway
}

//======================================================================
// CWheel class members
long CWheel::m_rgnRads[TOTALWHEELS] = {130, 120, 110, 100, 90, 80, 70};
COLORREF CWheel::m_rgco[TOTALWHEELS] = 
		{RGB(255, 0, 0),   // Red
		RGB(0, 0, 255),  // Blue
		RGB(255, 255, 0), // Yellow
		RGB(128, 128, 0),  // Green
		RGB(125, 0, 125),  // Purple
		RGB(128, 50, 50), // Orange??
		RGB(0, 128, 128)};   // ??

COLORREF CWheel::m_rgcoPattern[TOTALWHEELS] = {
		RGB(128, 0, 0),  // Red
		RGB(255, 255, 0), //Yellow
		RGB(0, 0, 255), // Blue
		RGB(255, 255, 0),   // Yellow
		RGB(255, 255, 0),  // Yellow
		RGB(0, 0, 255),  // Blue
		RGB(255, 0, 0) };

CWheel::CWheel(long nRadius, COLORREF co, COLORREF coPattern) : 
				CBasePiece(co)
{
	ASSERT(TOTALWHEELS == elementsof(m_rgco));
	ASSERT(TOTALWHEELS == elementsof(m_rgnRads));

	m_nPenRadius = 0;
	m_angleCurrent = m_bIsWheel? 0 : PI / 2.0;
	m_dAngleCorrection = 0;
	m_anglePen = 0;
	m_nRadius = nRadius;
	m_coPattern = coPattern;
	m_angleDelta = 0;
}

/* Draw will drw the piece at the current location including the pattern 
	which is for now a happy face. */				
void CWheel::Draw(CDC* pDC, long nZoomNumer, long nZoomDenom) const
{
	ENSURE(pDC != NULL);
	// First find if the bounding rectangle is visible at all in the DC

	CSpiroRect rect;
	GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
	if (!pDC->RectVisible(&rect))
		return;

	CRgn rgn;
	VERIFY(rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
	CBrush brush(m_co);
	pDC->FillRgn(&rgn, &brush);

	// Now draw the pattern.  (happy face)
	// First draw the smile at half the radius distance.
	long nRadSmile = m_nRadius * 5 / 8;
	double dAngle = m_bIsWheel? m_angleCurrent : 0;
	double dAngleStart = dAngle + PI * 9 / 8;  

	int ptsInPen = max(m_nRadius * 100 * nZoomNumer / 12 / 72 / nZoomDenom, 1);
	CPen	pen(PS_SOLID /*| PS_ENDCAP_ROUND*/, ptsInPen, m_coPattern);
	CPen*	pPenOld = pDC->SelectObject(&pen);

	  // rectangle to draw smile arc
	rect.SetRect(m_ptPos.x - nRadSmile, m_ptPos.y + nRadSmile, m_ptPos.x + nRadSmile, m_ptPos.y - nRadSmile);
	rect.Scale(nZoomNumer, nZoomDenom);

	CVector	vecStart(nRadSmile, dAngleStart);
	vecStart += m_ptPos;
	vecStart.Scale(nZoomNumer, nZoomDenom);
	CVector vecFinish(nRadSmile, dAngleStart + PI * 3.0 / 4.0);
	vecFinish += m_ptPos;
	vecFinish.Scale(nZoomNumer, nZoomDenom);

	pDC->Arc(&rect, (CPoint)vecStart, (CPoint)vecFinish);  // draw smile
	pDC->SelectObject(pPenOld);  // set the default black pen

	// finished drawing the smile for the happy face, now draw the eyes.
	CBrush brushPat(m_coPattern);
	CBrush* pBrushOld = pDC->SelectObject(&brushPat);

	nRadSmile = nRadSmile * 3 / 4;  // using += would lose precision
	vecStart.SetValueLengthAngle(nRadSmile, dAngle + 3.0 * PI / 4.0);
	vecStart += m_ptPos;
	vecStart.Scale(nZoomNumer, nZoomDenom);

	long	nRadEye = m_nRadius * nZoomNumer / nZoomDenom / 12; 

	for (int i = 0; i < 2; i++)
	{
		rect.SetRect(((CPoint)vecStart).x - nRadEye, ((CPoint)vecStart).y + nRadEye, 
							((CPoint)vecStart).x + nRadEye, ((CPoint)vecStart).y - nRadEye);

		pDC->Ellipse(&rect);

		if (i == 0)
		{
			vecStart.SetValueLengthAngle(nRadSmile, dAngle + PI / 4.0);
			vecStart += m_ptPos;
			vecStart.Scale(nZoomNumer, nZoomDenom);
		}
	}

	pDC->SelectObject(pBrushOld);
	brushPat.DeleteObject();

	// now draw the pen location if the wheel is not an anchor
	if (m_bIsWheel)
	{
		ASSERT(m_icoCurrent >= -1 && m_icoCurrent < elementsof(m_rgCo));
		int		ico = max(m_icoCurrent, 0);
		CSpiroRect secondRect;
		GetPenRect(&secondRect);
		rect.Scale(nZoomNumer, nZoomDenom);
		brushPat.CreateSolidBrush(m_rgCo[ico]);
		pDC->SelectObject(&brushPat);
		pen.DeleteObject();
		pen.CreatePen(PS_SOLID, 1, m_coPattern);
		pDC->SelectObject(&pen);
		pDC->Ellipse(&rect);
	}

	// clean up and we're done
	pDC->SelectObject(pPenOld);
	pDC->SelectObject(pBrushOld);
}

/* GetBoundingRect returns the rectangle sorrounding the piece */
void CWheel::GetBoundingRect(CSpiroRect* pRect, long nZoomNumer, long nZoomDenom) const
{
	ENSURE(pRect != NULL);
	pRect->SetRect((m_ptPos.x - m_nRadius) * nZoomNumer / nZoomDenom,
						(m_ptPos.y + m_nRadius) * nZoomNumer / nZoomDenom,
						(m_ptPos.x + m_nRadius) * nZoomNumer / nZoomDenom,
						(m_ptPos.y - m_nRadius) * nZoomNumer / nZoomDenom);
}

void CWheel::SetPosition(CPoint pt)
{
	m_ptPos.x = pt.x;
	m_ptPos.y = pt.y - m_nRadius;
}

// overload used to set the position of the piece based on a contact position
// and an angle provided by an anchor.
void CWheel::SetPosition(CPoint point, double dAngle)
{
	ASSERT(m_nRadius > 0);
	ASSERT(m_bIsWheel);  // this routine should never execute for anchors
	CVector	vecCenter(m_nRadius, dAngle);
	vecCenter += point;  // add the point in logical coordinates.
	m_ptPos = (CPoint)vecCenter;
}

// Gets the region used by the piece, in CLIENT coordinates.
// Due to off by one errors in some drivers, it is necessary to inflate the
// region before invalidating to make sure a piece is erased completely
void CWheel::GetDevPieceRgn(CDC* pDC, CRgn* pRgn, 
					long nZoomNumer, long nZoomDenom, bool bInflate) const
{
	ENSURE(pDC != NULL);
	CSpiroRect	rect;
	GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
	pDC->LPtoDP(&rect);  // convert to client coords
	if (bInflate)  // cover off by one errors in region invalidation in Windows
		rect.InflateRect(10, 10);   

	ENSURE(pRgn != NULL);
	VERIFY(pRgn->CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
}

void CWheel::GetLogPieceRgn(CRgn* pRgn, long nZoomNumer, long nZoomDenom) const
{
	CSpiroRect	rect;
	GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
	ENSURE(pRgn != NULL);
	VERIFY(pRgn->CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
}

void CWheel::GetContactPosition(CPoint, long, long,	
										CPoint& ptContact, double& dAngle)
{
	ptContact.x = m_ptPos.x;
	ptContact.y = m_ptPos.y + m_nRadius;
	dAngle = PI / 2.0;
	m_angleCurrent = dAngle;
}

// SetPenLocation receives the point in logical coordinates without scaling.
// The DC and the zoom ratio is provided only for the purpose of invalidating
// the rectangles where the pen was and where it moves to.
bool CWheel::SetPenLocation(CSpiroView* pView, CDC* pDC, CPoint point, 
									long nZoomNumer, long nZoomDenom)
{
	if (point != CPoint(0, 0))
	{
		CSpiroRect	rectPen;
		GetPenRect(&rectPen);
		point.x -= m_ptPos.x;
		point.y -= m_ptPos.y;
		CVector vect(point);  // easier to compute angle using vector
		long nNewPenRadius = vect.GetLength();
		if (nNewPenRadius < m_nRadius - PENMARKERSIZE - 1)
		{
			m_anglePen = vect.GetAngle() - m_angleCurrent;
			m_nPenRadius = nNewPenRadius;

			// invalidate the old location of the pen
			rectPen.Scale(nZoomNumer, nZoomDenom);
			pDC->LPtoDP(&rectPen);
			pView->InvalidateRect(&rectPen, FALSE);

			// now invalidate the new location of the pen
			GetPenRect(&rectPen);
			rectPen.Scale(nZoomNumer, nZoomDenom);
			pDC->LPtoDP(&rectPen);
			pView->InvalidateRect(&rectPen, FALSE);
			return true;
		}

		return false;  // if the new pen location is off the wheel don't change anything
	}

	//default value.
	m_anglePen = PI / 2.0;
	m_nPenRadius = m_nRadius * 3 / 4;
	return true;
}

void CWheel::GetPenRect(CRect* pRect) const
{
	CVector	vectPosPen(m_nPenRadius, m_anglePen + m_angleCurrent);
	vectPosPen += m_ptPos;
	CPoint ptPen = (CPoint)vectPosPen;

	pRect->SetRect(ptPen.x - PENMARKERSIZE, ptPen.y + PENMARKERSIZE, // working in loenglish, so add
						ptPen.x + PENMARKERSIZE, ptPen.y - PENMARKERSIZE);
}

int CWheel::HitTest(CDC* pDC, CPoint point, long nZoomNumer, long nZoomDenom) const
{
	ENSURE(pDC != NULL);
	CSpiroRect rectPen;
	GetPenRect(&rectPen);
	rectPen.Scale(nZoomNumer, nZoomDenom);

	// convert the pen rectangle to device coordinates.
	pDC->LPtoDP(&rectPen);
	if (rectPen.PtInRect(point))
	{
		return HIT_PEN_LOCATION;
	}

	return HIT_NOTHING;
}

__inline double CWheel::GetPerimeter() const
{
	return 2.0 * PI * (double)m_nRadius;
}

__inline void CWheel::SetAngleDelta(long nDistance, bool bReverse)
{
	// according to physics, w * r = d, and so w = d / r.
	ASSERT(m_nRadius > 0);
	ASSERT(nDistance > 0);
	m_angleDelta = (bReverse? -1.0 : 1.0) * (double)nDistance / m_nRadius;

	ASSERT(m_angleDelta != 0);
}

__inline void CWheel::AdvanceTrace(CPoint& ptContact, double& dAngle, double& dAngleExtra, bool bMove)
{
	ASSERT(m_angleDelta != 0);

	if (m_bIsWheel)
	{
		CVector vecPos = ptContact;
		vecPos += CVector(m_nRadius, dAngle);  // new position for the wheel
		if (bMove)
		{
			m_ptPos = (CPoint)vecPos;
			m_angleCurrent += m_angleDelta + dAngleExtra;
		}
	}
	else  // code when wheel behaves like an anchor
	{  
		if (bMove)
		{
			m_angleCurrent += m_angleDelta + m_dAngleCorrection;
		}

		CVector vecAfter(m_nRadius, m_angleCurrent);
		vecAfter += m_ptPos;
		ptContact = (CPoint)vecAfter;
		dAngle = m_angleCurrent;
		dAngleExtra = m_angleDelta + m_dAngleCorrection;
	}
}

__inline void CWheel::GetPenLocation(CPoint* pPoint) const
{
	ASSERT(m_bIsWheel);
	ASSERT(m_nPenRadius > 0);
	CVector	vecPen(m_nPenRadius, m_anglePen + m_angleCurrent);
	vecPen += m_ptPos;  // move relative to the location of the wheel
	*pPoint = (CPoint)vecPen;
}

long CWheel::GetCycleError() const
{
	// Calculate the distance for the cycle error to be 6 degrees 
	// which means (PI / 30) * radius
	return (long)(PI * (double)m_nRadius / 30.0);   
}

__inline bool CWheel::ReverseWheelDirection() const
{
	return false;
}

__inline double CWheel::GetFigData() const
{
	return m_angleCurrent;
}

__inline void CWheel::SetFigData(double dData)
{
	m_angleCurrent = dData;
}

// The following routine is called during the drawing process to create the animation
// effect.  It moves the wheel from one position to the next.
void CWheel::MovePiece(CSpiroView* pView, CPoint point, double dWheelData,
							long nZoomNumer, long nZoomDenom)
{
	ENSURE(pView != NULL);
	if (point == m_ptPos && dWheelData == m_angleCurrent)
		return;

	// First invalidate the current rectangle for the wheel and then the new position
	CSpiroRect rect;
	CDC* pDC = pView->GetDC();
	ENSURE(pDC != NULL);
	pView->OnPrepareDC(pDC);

	for (int i= 0; i < 2; i++)
	{
		GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
		pDC->LPtoDP(&rect);
		pView->InvalidateRect(&rect);
		m_ptPos = point;
		m_angleCurrent = dWheelData;
	}

	pView->ReleaseDC(pDC);
}

void CWheel::SetWheelMode(bool bWheel)
{
	m_bIsWheel = bWheel;
	if (m_bIsWheel)
		m_angleCurrent = 0;
}

//=============================================================================
// CRing member functions

long CRing::m_rgnRads[TOTALRINGS] = {250, 220, 180, 150};
COLORREF CRing::m_rgco[TOTALRINGS] = 
		{RGB(255, 0, 0), 
		RGB(0, 0, 255),
		RGB(255, 255, 0),
		RGB(200, 200, 0)};

CRing::CRing(long nRadiusIn, long nRadiusOut, COLORREF co, COLORREF coPattern) :
		CWheel(nRadiusOut, co, coPattern)
{
	ASSERT(TOTALRINGS == elementsof(m_rgnRads));
	ASSERT(TOTALRINGS == elementsof(m_rgco));
	m_nRadiusInt = nRadiusIn;
	m_bWheelInside = false;
	m_angleCurrent = PI / 2.0;  // initial angle is always pi/2 for a ring
}

void CRing::Draw(CDC* pDC, long nZoomNumer, long nZoomDenom) const
{
	ENSURE(pDC != NULL);
	ASSERT(pDC->GetMapMode() == MM_SPIRO);  // make sure the mapping mode is right
	ASSERT(m_nRadiusInt > 0 && m_nRadius > m_nRadiusInt);

	CSpiroRect	rectOut;
	GetBoundingRect(&rectOut, nZoomNumer, nZoomDenom);
	if (!pDC->RectVisible(&rectOut))
		return;

	CRgn	rgnRing;
	VERIFY(rgnRing.CreateEllipticRgn(rectOut.left, rectOut.top, 
									rectOut.right, rectOut.bottom));

	CSpiroRect		rectIn;
	GetInnerRect(&rectIn, nZoomNumer, nZoomDenom);
	CRgn	rgnInnerRing;
	VERIFY(rgnInnerRing.CreateEllipticRgn(rectIn.left, rectIn.top, 
										rectIn.right, rectIn.bottom));

	//define the region for the ring itself
	VERIFY(rgnRing.CombineRgn(&rgnRing, &rgnInnerRing, RGN_DIFF) != ERROR);

	CBrush	brush(m_co);  // get ready to draw the ring.
	pDC->FillRgn(&rgnRing, &brush);  // draw the ring

	double	dSpace = PI / 30.0;
	CVector	vectWork;
	CPen	pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen*	pPenOld(NULL);  // Initialize to avoid compiler warnings.

	for (int i = 0; i < 60; i++)
	{
		if (i % 5 == 0)
			pPenOld = pDC->SelectObject(&pen);

		vectWork = m_ptPos;
		vectWork += CVector(m_nRadiusInt, dSpace * (double)i + PI / 2.0);
		CPoint ptStart = (CPoint)vectWork;
		vectWork += CVector(m_nRadius - m_nRadiusInt, dSpace * (double)i + PI / 2.0);
		CPoint ptEnd = (CPoint)vectWork;
		pDC->MoveTo(ptStart.x * nZoomNumer / nZoomDenom, ptStart.y * nZoomNumer / nZoomDenom);
		pDC->LineTo(ptEnd.x * nZoomNumer / nZoomDenom, ptEnd.y * nZoomNumer / nZoomDenom);
		
		if (i % 5 == 0)
			pDC->SelectObject(pPenOld);
	}
}									   

void CRing::GetInnerRect(CSpiroRect* pRect, long nZoomNumer, long nZoomDenom) const
{
	pRect->left = (m_ptPos.x - m_nRadiusInt) * nZoomNumer / nZoomDenom;
	pRect->right = (m_ptPos.x + m_nRadiusInt) * nZoomNumer / nZoomDenom;
	pRect->top = (m_ptPos.y + m_nRadiusInt) * nZoomNumer / nZoomDenom;
	pRect->bottom = (m_ptPos.y - m_nRadiusInt) * nZoomNumer / nZoomDenom;
}

// returns the region occupied by the piece in CLIENT coordinates.
void CRing::GetDevPieceRgn(CDC* pDC, CRgn* pRgn, 
						long nZoomNumer, long nZoomDenom, bool bInflate) const
{
	ENSURE(pDC != NULL);
	ENSURE(pRgn != NULL);
	CSpiroRect	rect;
	GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
	pDC->LPtoDP(&rect);  // convert to client coordinates
	if (bInflate)
		rect.InflateRect(5, 5);

	VERIFY(pRgn->CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));

	CSpiroRect rectInner;
	GetInnerRect(&rectInner, nZoomNumer, nZoomDenom);
	pDC->LPtoDP(&rectInner);
	if (bInflate)
		rectInner.DeflateRect(5, 5);  // cover for bug where region is not repainted properly

	CRgn	rgnInner;
	VERIFY(rgnInner.CreateEllipticRgn(rectInner.left, rectInner.top, 
								rectInner.right, rectInner.bottom));
	
	VERIFY(pRgn->CombineRgn(pRgn, &rgnInner, RGN_DIFF) != ERROR);
}

// returns the region occupied by the piece in CLIENT coordinates.
void CRing::GetLogPieceRgn(CRgn* pRgn, long nZoomNumer, long nZoomDenom) const
{
	CSpiroRect	rect;
	GetBoundingRect(&rect, nZoomNumer, nZoomDenom);
	ENSURE(pRgn != NULL);
	VERIFY(pRgn->CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
	int nWidth = (m_nRadius - m_nRadiusInt) * nZoomNumer / nZoomDenom;
	rect.DeflateRect(nWidth, -nWidth);
	CRgn	rgnInner;
	VERIFY(rgnInner.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
	VERIFY(pRgn->CombineRgn(pRgn, &rgnInner, RGN_DIFF) != ERROR);
}


// called by a wheel to find the initial position of contact with the anchor
// point is the point IN LOGICAL COORDS where the user clicked to anchor the wheel
void CRing::GetContactPosition(CPoint point, long nZoomNumer, long nZoomDenom,
							   CPoint& ptContact, double& dAngle)
{
	CSpiroRect	rect;
	GetInnerRect(&rect, nZoomNumer, nZoomDenom);
	ptContact.x = m_ptPos.x;
	CRgn	rgnInner;
	VERIFY(rgnInner.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom));
	if (rgnInner.PtInRegion(point))  // anchor wheel inside the ring
	{
		ptContact.y = m_ptPos.y + m_nRadiusInt;
		dAngle = 3.0 * PI / 2.0;
		m_angleCurrent = PI / 2.0;  // GetContactPosition always resets the current angle
		m_bWheelInside = true;
		return;
	}

	ptContact.y = m_ptPos.y + m_nRadius;
	dAngle = PI / 2.0;
	m_angleCurrent = dAngle;
	m_bWheelInside = false;
}

__inline double CRing::GetPerimeter() const
{
	return (m_bWheelInside? (double)m_nRadiusInt : 
								(double)m_nRadius) * 2.0 * PI;
}
	
__inline void CRing::SetAngleDelta(long nDistance, bool)
{
	ASSERT(nDistance > 0);
	ASSERT(m_nRadiusInt > 0 && m_nRadius > 0);
	m_angleDelta = (double)nDistance / 
						(double)(m_bWheelInside? m_nRadiusInt : m_nRadius);

	ASSERT(m_angleDelta != 0);
}

__inline void CRing::AdvanceTrace(CPoint& ptContact, double& dAngle, double& dAngleExtra, bool bMove)
{
	ASSERT(!m_bIsWheel);  // rings do not work as wheels in this implementation
	ASSERT(m_angleDelta != 0);

	if (!m_bWheelInside)  // on the external use, behaves like a common wheel
	{
		CWheel::AdvanceTrace(ptContact, dAngle, dAngleExtra, bMove);
		return;
	}

	
	if (bMove)
	{
		m_angleCurrent += m_angleDelta + m_dAngleCorrection;
	}

	CVector vecAfter(m_nRadiusInt, m_angleCurrent);
	vecAfter += m_ptPos;
	ptContact = (CPoint)vecAfter;
	dAngle = m_angleCurrent + PI;
	dAngleExtra = m_angleDelta + m_dAngleCorrection;   // positive is fine since wheel spins in negative direction
}

long CRing::GetCycleError() const
{
	// Calculate the error to be the distance in the circumference for a 6 degree
	// error, which is (PI / 30) * radius
	if (!m_bWheelInside)
		return CWheel::GetCycleError();

	return (long)(PI * (double)m_nRadiusInt / 30.0);
}

__inline bool CRing::ReverseWheelDirection() const
{
	return m_bWheelInside;
}

