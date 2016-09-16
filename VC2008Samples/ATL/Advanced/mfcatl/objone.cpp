// ObjOne.cpp : implementation file
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "premfcat.h"
#include "MfcAtl.h"
#include "ObjOne.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CObjectOne

IMPLEMENT_DYNCREATE(CObjectOne, CCmdTarget)

CObjectOne::CObjectOne()
{
	EnableAutomation();

	// To keep the application running as long as an OLE automation
	//  object is active, the constructor calls AfxOleLockApp.

	AfxOleLockApp();
}

CObjectOne::~CObjectOne()
{
	// To terminate the application when all objects created with
	//  with OLE automation, the destructor calls AfxOleUnlockApp.

	AfxOleUnlockApp();
}


void CObjectOne::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CObjectOne, CCmdTarget)
	//{{AFX_MSG_MAP(CObjectOne)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CObjectOne, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CObjectOne)
	DISP_FUNCTION(CObjectOne, "SayHello", SayHello, VT_BSTR, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IObjectOne to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .ODL file.

// {5D0CE84F-D909-11CF-91FC-00A0C903976F}
static const IID IID_IObjectOne =
{ 0x5d0ce84f, 0xd909, 0x11cf, { 0x91, 0xfc, 0x0, 0xa0, 0xc9, 0x3, 0x97, 0x6f } };

BEGIN_INTERFACE_MAP(CObjectOne, CCmdTarget)
	INTERFACE_PART(CObjectOne, IID_IObjectOne, Dispatch)
END_INTERFACE_MAP()

// {5D0CE850-D909-11CF-91FC-00A0C903976F}
IMPLEMENT_OLECREATE(CObjectOne, "MfcAtl.ObjectOne", 0x5d0ce850, 0xd909, 0x11cf, 0x91, 0xfc, 0x0, 0xa0, 0xc9, 0x3, 0x97, 0x6f)

/////////////////////////////////////////////////////////////////////////////
// CObjectOne message handlers

BSTR CObjectOne::SayHello()
{
	return SysAllocString(OLESTR("Hello from Object One!"));
}
