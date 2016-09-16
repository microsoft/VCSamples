// Scribble.h : main header file for the SCRIBBLE application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "ScribDoc.h"
#include "ScribApp.h"

#ifdef _MANAGED

#include <vcclr.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace localhost;

#endif

/////////////////////////////////////////////////////////////////////////////
// CScribbleApp:
// See Scribble.cpp for the implementation of this class
//

class CScribbleApp : public CWinApp
{
public:
	CScribbleApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScribbleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CScribbleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void ExecutePlugin(CScribbleDoc * pScribDoc, UINT pluginMenuID);
	void AddRectangle(CScribbleDoc * pScribDoc, int posX, int posY, int width, int height);
	void AddCircle(CScribbleDoc * pScribDoc, int posX, int posY, int radius);
private:
	void LoadPlugins();
	void AddWebServiceMenu();
private:

#ifdef _MANAGED
	void AddShape(CScribbleDoc * pScribDoc, Shape^ pShape, int posX, int posY);

	gcroot< Dictionary<UINT, IScribblePlugin ^> ^ > m_pluginMap;
	gcroot< ScribbleWSClass ^> m_webService;
#endif
};

/////////////////////////////////////////////////////////////////////////////
