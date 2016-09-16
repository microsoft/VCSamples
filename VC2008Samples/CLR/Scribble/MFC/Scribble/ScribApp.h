#pragma once
// ScribApp.h : interface of the MyScribDoc & MyScribApp classes
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
/////////////////////////////////////////////////////////////////////////////

#ifdef _MANAGED

#include "ScribDoc.h"

using namespace System;
using namespace System::Drawing;
using namespace ScribbleApp;

ref class MyScribDoc : public IScribbleDoc
{
public:
	MyScribDoc(CScribbleDoc * scribDoc);
	virtual void DrawLine(Point ^ p1, Point ^ p2);
	virtual void SetPenColor(Color c);
	virtual Color GetPenColor();
private:
	CScribbleDoc * m_ScribDoc;
};

ref class MyScribApp : public IScribbleApp
{
public:
	MyScribApp(CScribbleDoc * scribDoc);
	virtual IScribbleDoc ^ GetDocument();
private:
	MyScribDoc ^ m_ScribDoc;
};

#endif