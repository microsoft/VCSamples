// spiroDoc.cpp : implementation of the CSpiroDoc class
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
#include "spiro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CSpiroView* g_pView;

/////////////////////////////////////////////////////////////////////////////
// CFigure and CFigCommand

void CFigCommand::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_type;
		ar << m_point.x;
		ar << m_point.y;
		ar << m_ptWheelPos.x;
		ar << m_ptWheelPos.y;
		ar << m_nPenWidth;
	}
	else
	{
		DWORD	dw;

		ar >> dw; m_type = (TRACE_COMMAND)dw;
		ar >> m_point.x;
		ar >> m_point.y;
		ar >> m_ptWheelPos.x;
		ar >> m_ptWheelPos.y;
		ar >> m_nPenWidth;
	}
}

CFigure::CFigure() : m_rectBound(9000, 0, 0, 9000)
{
	m_nTotalTraces = 0;
	m_nTotalDrawn = 0;
	m_arrCommands.SetSize(0, 2000);
	m_nTracesPerColor = 0;
	m_nTracesThisColor = 0;
}

CFigure::CFigure(CFigure* pFig)
{
	ENSURE(pFig != NULL);
	m_nTotalTraces = pFig->m_nTotalTraces;
	m_nTotalDrawn = pFig->m_nTotalDrawn;
	m_nTracesPerColor = pFig->m_nTracesPerColor;
	m_nTracesThisColor = pFig->m_nTracesThisColor;
	m_rectBound = pFig->m_rectBound;
	INT_PTR nSize = pFig->m_arrCommands.GetSize();
	m_arrCommands.SetSize(nSize);
	CFigCommand figCommand;

	for (int i = 0; i < nSize; i++)
	{
		figCommand = pFig->m_arrCommands.GetAt(i);
		m_arrCommands.SetAt(i, figCommand);
	}
}

CFigure::~CFigure()
{
	m_arrCommands.RemoveAll();
}

void CFigure::AddCommand(TRACE_COMMAND com, int nWidth)
{
	ENSURE(com == SET_PEN_WIDTH);
	ENSURE(nWidth > 0);
	CFigCommand	figcom;
	figcom.m_type = com;
	figcom.m_nPenWidth = nWidth;
	m_arrCommands.SetAtGrow(m_nTotalTraces, figcom);
	ASSERT(m_arrCommands.GetUpperBound() == m_nTotalTraces);
	m_nTotalTraces++;
}

void CFigure::AddCommand(TRACE_COMMAND com, COLORREF co)
{
	ASSERT(com == CHANGE_COLOR);
	CFigCommand figcom;
	figcom.m_type = com;
	figcom.m_co = co;
	m_arrCommands.SetAtGrow(m_nTotalTraces, figcom);
	ASSERT(m_arrCommands.GetUpperBound() == m_nTotalTraces);
	m_nTotalTraces++;
}


void CFigure::AddCommand(TRACE_COMMAND com, CPoint point, 
						 CPoint ptWheelPos, double dWheelData, double dAnchorData)
{
	ASSERT(com == MOVE_TO || com == LINE_TO);
	CFigCommand figcom;
	figcom.m_type = com;
	figcom.m_point = point;
	figcom.m_ptWheelPos = ptWheelPos;
	figcom.m_dWheelData = dWheelData;
	figcom.m_dAnchorData = dAnchorData;
	m_arrCommands.SetAtGrow(m_nTotalTraces, figcom);
	ASSERT(m_arrCommands.GetUpperBound() == m_nTotalTraces);
	m_nTotalTraces++;

	// finally check if the new point grows the bounding rectangle
	m_rectBound.left = min(point.x - 2, m_rectBound.left);
	m_rectBound.right = max(point.x + 2, m_rectBound.right);
	m_rectBound.top = max(point.y + 2, m_rectBound.top);
	m_rectBound.bottom = min(point.y - 2, m_rectBound.bottom);
}

void CFigure::Clean()
{
	m_rectBound = CRect(1200, 0, 0, 18000);
	m_nTotalTraces = 0;
	m_arrCommands.RemoveAll();
	m_arrCommands.SetSize(0, 2000);
}

// Draw gets the DC, the zoom information and the region occupied by the wheel component when
// animation is active.  The points under the wheel do not need to be drawn.
void CFigure::Draw(CDC* pDC, long nZoomNumer, long nZoomDenom
									, CRgn* /*prgnWheel*/, CSpiroRect* prectClip) const
{
	ENSURE(pDC != NULL);
	ENSURE(pDC->GetMapMode() == MM_SPIRO);

	if (m_nTotalDrawn == 0)
		return;

	int			nPenWidth = -1;
	COLORREF	coPen = 0;

	bool	bPrinting = pDC->IsPrinting() != 0;

	// Check if the figure is totally off the clip rectangle and return if this is the case
	if (!bPrinting)
	{
		CSpiroRect rectFig(m_rectBound);
		rectFig.Scale(nZoomNumer, nZoomDenom);  // scale the figure to compare against scaled clip rectangle
		if (!rectFig.IntersectRect(prectClip))
			return;
	}

	CPen*	pPenNew = NULL;
	CPen*	pPenOld = NULL;

	int nFirst = 0;
	int nLast = m_nTotalDrawn;

	ENSURE(g_pView != NULL && g_pView->IsKindOf(RUNTIME_CLASS(CSpiroView)));

	long	cyExtent = g_pView->GetDocument()->m_sizeExtent.cy;
	
	ENSURE(cyExtent > 0);

	pPenNew = new CPen(PS_SOLID, g_pView->m_nCurrentPenWidth, g_pView->m_coCurrentPen);
	pPenOld = pDC->SelectObject(pPenNew);

	bool bLastTrace = nLast == m_arrCommands.GetUpperBound();
	CPoint*	prgPoint = new CPoint[m_nTotalDrawn];

	CPoint		ptLast(-5000, -5000);
	CPoint		ptTest;

	int		nTotalPoints = 0;
	CFigCommand	figCommand;
	for (int i = nFirst; i <= m_nTotalDrawn; i++)
	{
		figCommand = m_arrCommands.GetAt(i);
		switch (figCommand.m_type)
		{
		case SET_PEN_WIDTH:
		case CHANGE_COLOR:
			if (nTotalPoints != 0)  // flush the accumulated lines
			{
				ENSURE(nTotalPoints > 1);
				pDC->Polyline(prgPoint, nTotalPoints);
				nTotalPoints = 0;
			}

			if (figCommand.m_type == SET_PEN_WIDTH)
				nPenWidth = figCommand.m_nPenWidth;
			else
				coPen = figCommand.m_co;
		
			ENSURE(pPenNew != NULL);
			ENSURE(pPenOld != NULL);
			VERIFY(pDC->SelectObject(pPenOld) == pPenNew);
			VERIFY(pPenNew->DeleteObject());
			pPenNew->CreatePen(PS_SOLID, nPenWidth,  coPen);

			pDC->SelectObject(pPenNew);

			break;

		case MOVE_TO:
			if (bPrinting)
				pDC->MoveTo(figCommand.m_point.x, figCommand.m_point.y);
			else
			{
				// flush the GDI line drawing command if there is any
				if (nTotalPoints != 0)  // 1 point is just a MoveTo.  Don't use it.
				{
					ENSURE(nTotalPoints > 1);
					pDC->Polyline(prgPoint, nTotalPoints);
					nTotalPoints = 0;
				}

				ptLast.x = figCommand.m_point.x * nZoomNumer / nZoomDenom;
				ptLast.y = figCommand.m_point.y * nZoomNumer / nZoomDenom;
			}
			break;

		case LINE_TO:
			if (bPrinting)
			{
				prgPoint[nTotalPoints].x = figCommand.m_point.x;
				prgPoint[nTotalPoints++].y = figCommand.m_point.y;
			}
			else
			{
				ptTest.x = figCommand.m_point.x * nZoomNumer / nZoomDenom;
				ptTest.y = figCommand.m_point.y * nZoomNumer / nZoomDenom;
						
				if (prectClip->LineInRect(ptLast, ptTest))  // line is visible and not under wheel 
					//			&& (prgnWheel == NULL || 
					//				!prgnWheel->PtInRegion(ptLast) || !prgnWheel->PtInRegion(ptTest)))
				{
					ENSURE(ptLast.x != -5000 && ptLast.y != 5000);  // there should be a MOVE_TO before
					if (nTotalPoints == 0)  // need to insert ptLast
						prgPoint[nTotalPoints++] = ptLast;

					prgPoint[nTotalPoints++] = ptTest;
				}
				else   // if not visible, add point and flush
				{
					if (nTotalPoints != 0)
					{
						ENSURE(nTotalPoints > 1);
						pDC->Polyline(prgPoint, nTotalPoints);
						nTotalPoints = 0;
					}
				}

				ptLast = ptTest;
			}
		}
	}

	if (bLastTrace)   // connect to the first point to close the picture
	{
		INT_PTR nLastItem = m_arrCommands.GetUpperBound();
		int nPasses = 0;

		for (int i = 0; i <= nLastItem && nPasses < 2; i++)
		{
			figCommand = m_arrCommands.GetAt(i);
			if (figCommand.m_type == MOVE_TO || figCommand.m_type == LINE_TO)
			{
				if (bPrinting)
				{
					prgPoint[nTotalPoints].x = figCommand.m_point.x;
					prgPoint[nTotalPoints++].y = figCommand.m_point.y;
				}
				else
				{
					if (nTotalPoints == 0)
						prgPoint[nTotalPoints++] = ptLast;

					prgPoint[nTotalPoints].x = figCommand.m_point.x * nZoomNumer / nZoomDenom;
					prgPoint[nTotalPoints++].y = figCommand.m_point.y * nZoomNumer / nZoomDenom;
				}

				// draws 2 segments at the end to avoid leaving the last pixel undrawn
				nPasses++;
			}
		}

		if (this == g_pView->GetDocument()->m_pFigureCurrent)
			g_pView->m_bDrawingDone = true;
	}

	if (nTotalPoints != 0)  // flush the accumulated lines
	{
		ENSURE(nTotalPoints >= 1);
		pDC->Polyline(prgPoint, nTotalPoints);
		nTotalPoints = 0;
	}

	ENSURE(pPenOld != NULL)		;
	pDC->SelectObject(pPenOld);
	delete pPenNew;

	CSpiroDoc* pDoc = g_pView->GetDocument();
	ENSURE(pDoc != NULL);
	delete[] prgPoint;
}

void CFigure::GetBoundingRect(CRect* pRect) const
{
	ENSURE(pRect != NULL);
	*pRect = m_rectBound;
}

void CFigure::Serialize(CArchive& ar)
{
	DWORD			dw;
	CFigCommand		figCommand;

	if (ar.IsStoring())
	{
		dw = m_nTotalDrawn; ar << dw;
		dw = m_nTotalTraces; ar << dw;
		dw = m_rectBound.left; ar << dw;
		dw = m_rectBound.right; ar << dw;
		dw = m_rectBound.top; ar << dw;
		dw = m_rectBound.bottom; ar << dw;
		dw = (DWORD)(m_arrCommands.GetUpperBound() + 1);
		ar << dw;
		for (int i = 0; i < (int)dw; i++)
		{
			figCommand = m_arrCommands.GetAt(i);
			figCommand.Serialize(ar);
		}
	}
	else
	{
		ar >> dw; m_nTotalDrawn = dw;
		ar >> dw; m_nTotalTraces = dw;
		ar >> dw; m_rectBound.left = dw;
		ar >> dw; m_rectBound.right = dw;
		ar >> dw; m_rectBound.top = dw;
		ar >> dw; m_rectBound.bottom = dw;
		ar >> dw;
		for (int i = 0; i < (int)dw; i++)
		{
			figCommand.Serialize(ar);
			m_arrCommands.SetAtGrow(i, figCommand);
		}
	}
}

bool CFigure::MoveFigure(CPoint ptCorner, CSpiroDoc* pDoc)
{
	pDoc->SetModifiedFlag();

	// does the user want to remove the picture from the drawing?
	if (ptCorner.x > pDoc->m_sizeExtent.cx || ptCorner.y < 0)
	{
		delete this;
		return false;  // figure was deleted
	}

	CSize	sizeOffset(ptCorner.x - m_rectBound.left + 2, ptCorner.y - m_rectBound.top + 2);
	m_rectBound.OffsetRect(sizeOffset);  //LO_ENGLISH METRICS USED

	CFigCommand	figCommand;
	INT_PTR iLast = m_arrCommands.GetUpperBound();
	for (int i = 0; i <= iLast; i++)
	{
		figCommand = m_arrCommands.GetAt(i);
		if (figCommand.m_type != LINE_TO && figCommand.m_type != MOVE_TO)
			continue;

		figCommand.m_point.Offset(sizeOffset);
		m_arrCommands.SetAt(i, figCommand);
	}

	iLast = pDoc->m_arrPFigures.GetUpperBound() + 1;
	pDoc->m_arrPFigures.SetAtGrow(iLast, this);
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroDoc

IMPLEMENT_DYNCREATE(CSpiroDoc, CDocument)

BEGIN_MESSAGE_MAP(CSpiroDoc, CDocument)
	//{{AFX_MSG_MAP(CSpiroDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpiroDoc construction/destruction

CSpiroDoc::CSpiroDoc() : m_sizeExtent(1100, 1700)
{
	m_bThickPen = false;
	m_pFigureCurrent = new CFigure();
}

CSpiroDoc::~CSpiroDoc()
{
	delete m_pFigureCurrent;
	INT_PTR nLast = m_arrPFigures.GetUpperBound();
	CFigure* pFig;

	for (int i = 0; i <= nLast; i++)
	{
		pFig = (CFigure*)m_arrPFigures.GetAt(i);
		ENSURE(pFig != NULL);
		delete pFig;
	}

	m_arrPFigures.RemoveAll();
}

BOOL CSpiroDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_bThickPen = false;
	if (m_pFigureCurrent == NULL)
		m_pFigureCurrent = new CFigure();
	else
		m_pFigureCurrent->Clean();

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSpiroDoc serialization

void CSpiroDoc::Serialize(CArchive& ar)
{
	DWORD	dw;

	if (ar.IsStoring())
	{
		dw = m_sizeExtent.cx;
		ar << dw;	// store the extent
		dw = m_sizeExtent.cy;
		ar << dw;
		dw = (DWORD)(m_arrPFigures.GetUpperBound() + 1);
		ar << dw;  // number of fixed figures
		for (int i = 0; i < (int)dw; i++)
		{
			CFigure* pFig = (CFigure*)m_arrPFigures.GetAt(i);
			ENSURE(pFig != NULL);
			pFig->Serialize(ar);
		}

		m_pFigureCurrent->Serialize(ar);
	}
	else
	{
		ar >> dw;
		m_sizeExtent.cx = dw;
		ar >> dw;
		m_sizeExtent.cy = dw;
		ar >> dw;  // count of figures
		CFigure* pFig;

		for (int i = 0; i < (int)dw; i ++)
		{
			pFig = new CFigure();
			pFig->Serialize(ar);
			m_arrPFigures.SetAtGrow(i, pFig);
		}

		m_pFigureCurrent = new CFigure();
		m_pFigureCurrent->Serialize(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroDoc diagnostics

#ifdef _DEBUG
void CSpiroDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSpiroDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpiroDoc commands

// this function is called when the figure is made permanent and is transfered
// to the array of figures inside the document.
void CSpiroDoc::TransferCurrentFigure()
{
	ENSURE(m_pFigureCurrent != NULL);
	if (m_pFigureCurrent->m_nTotalDrawn == 0)  // the figure is empty
	{
		m_pFigureCurrent->Clean();
		return;
	}

	ENSURE(g_pView != NULL);
	// if there is an anchor, set the angle of the anchor
	if (g_pView->m_pAnchor != NULL)
	{
		CFigCommand	figCommand;

		int i;
		for (i = m_pFigureCurrent->m_nTotalDrawn - 1; i >= 0; i--)
		{
			figCommand = m_pFigureCurrent->m_arrCommands.GetAt(i);
			if (figCommand.m_type == MOVE_TO || figCommand.m_type == LINE_TO)
			{
				g_pView->m_pAnchor->SetFigData(figCommand.m_dAnchorData);
				break;
			}
		}
		
		ENSURE(i != -1);
	}

	INT_PTR nIndex = m_arrPFigures.GetUpperBound() + 1;
	ENSURE(m_pFigureCurrent != NULL);
	m_arrPFigures.SetAtGrow(nIndex, m_pFigureCurrent);
	m_pFigureCurrent = new CFigure();
	g_pView->m_bDrawingDone = false;
}

void CSpiroDoc::DeleteContents() 
{
	INT_PTR nLast = m_arrPFigures.GetUpperBound();
	CFigure* pFig;

	POSITION pos = GetFirstViewPosition();
	CSpiroView* pView;
	
	if (pos != NULL)  // on shut down the view has been destroyed already
	{
		pView = (CSpiroView*)GetNextView(pos);
		ENSURE(pView != NULL && pView->IsKindOf(RUNTIME_CLASS(CSpiroView)));
		delete pView->m_pAnchor;
		delete pView->m_pWheel;
		pView->m_pAnchor = NULL;
		pView->m_pWheel = NULL;
	}

	for (int i = 0; i <= nLast; i++)
	{
		pFig = (CFigure*)m_arrPFigures.GetAt(i);
		delete pFig;
	}

	m_arrPFigures.RemoveAll();
	delete m_pFigureCurrent;
	m_pFigureCurrent = NULL;

	CDocument::DeleteContents();
}
