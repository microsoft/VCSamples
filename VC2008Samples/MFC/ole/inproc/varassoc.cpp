// varassoc.cpp : implementation file
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
#include "inproc.h"
#include "varassoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc

IMPLEMENT_DYNCREATE(CVariantAssoc, CCmdTarget)

CVariantAssoc::CVariantAssoc()
{
	EnableAutomation();

	// To keep the application running as long as an OLE automation
	//  object is active, the constructor calls AfxOleLockApp.

	AfxOleLockApp();
}

CVariantAssoc::~CVariantAssoc()
{
	// To terminate the application when all objects created with
	//  with OLE automation, the destructor calls AfxOleUnlockApp.

	AfxOleUnlockApp();
}

void CVariantAssoc::OnFinalRelease()
{
	// When the last reference for an automation object is released
	//  OnFinalRelease is called.  This implementation deletes the
	//  object.  Add additional cleanup required for your object before
	//  deleting it from memory.

	delete this;
}

BEGIN_MESSAGE_MAP(CVariantAssoc, CCmdTarget)
	//{{AFX_MSG_MAP(CVariantAssoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CVariantAssoc, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CVariantAssoc)
	DISP_PROPERTY_EX(CVariantAssoc, "Key", GetKey, SetNotSupported, VT_VARIANT)
	DISP_PROPERTY_EX(CVariantAssoc, "Value", GetValue, SetNotSupported, VT_VARIANT)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// {84E099E0-F9F6-11cd-8C3D-00AA004BB3B7}
static const IID IID_IVariantAssoc = { 0x84e099e0, 0xf9f6, 0x11cd,
	{ 0x8c, 0x3d, 0x0, 0xaa, 0x0, 0x4b, 0xb3, 0xb7 } };

// Note: we add support for IID_IVariantAssoc to support typesafe binding
// from VBA.  This IID must match the GUID that is attached to the
// dispinterface in the .ODL file.

BEGIN_INTERFACE_MAP(CVariantAssoc, CCmdTarget)
	INTERFACE_PART(CVariantAssoc, IID_IVariantAssoc, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc message handlers

VARIANT CVariantAssoc::GetKey()
{
	COleVariant varResult = m_varKey;
	return varResult.Detach();
}

VARIANT CVariantAssoc::GetValue()
{
	COleVariant varResult = m_varValue;
	return varResult.Detach();
}
