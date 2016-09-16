// ScribApp.cpp : implementation of the CScribbleDoc class
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
#include "ScribApp.h"

#ifdef _MANAGED

MyScribDoc::MyScribDoc(CScribbleDoc * scribDoc)
{
	m_ScribDoc = scribDoc;
}

void
MyScribDoc::DrawLine(Point ^ p1, Point ^ p2)
{
	CStroke * pStroke = m_ScribDoc->NewStroke();

	pStroke->m_pointArray.Add(CPoint(p1->X, p1->Y));
	pStroke->m_pointArray.Add(CPoint(p2->X, p2->Y));
	pStroke->FinishStroke();

	m_ScribDoc->UpdateAllViews(NULL, 0L, pStroke);
}

void
MyScribDoc::SetPenColor(Color c)
{
	m_ScribDoc->SetPenColor(RGB(c.R, c.G, c.B));
}

Color
MyScribDoc::GetPenColor()
{
	return Color::FromArgb(m_ScribDoc->GetPenColor());
}

MyScribApp::MyScribApp(CScribbleDoc * scribDoc)
{
	m_ScribDoc = gcnew MyScribDoc(scribDoc);
}

IScribbleDoc ^
MyScribApp::GetDocument()
{
	return m_ScribDoc;
}

#endif