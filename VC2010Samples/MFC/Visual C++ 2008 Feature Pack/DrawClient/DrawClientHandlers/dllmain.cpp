// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "DrawClientHandlers_i.h"
#include "dllmain.h"

CDrawClientHandlersModule _AtlModule;

class CDrawClientHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDrawClientHandlersApp, CWinApp)
END_MESSAGE_MAP()

CDrawClientHandlersApp theApp;

BOOL CDrawClientHandlersApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CDrawClientHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
