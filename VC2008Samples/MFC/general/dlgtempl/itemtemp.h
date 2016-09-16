// itemtemp.h

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef INC_ITEMTEMP_H
#define INC_ITEMTEMP_H

// if you change the value for TOTALITEMS, make sure that the allocations
// in CMyDialogTemplate::DemoIt remain consistent with your changes.  Otherwise you might
// end up corrupting the heap.

#define TOTALITEMS  3

#define IBUTTON         0
#define IEDITCONTROL    1
#define ISTATICTEXT     2

// There is no reason to derive a class from CObject because in this specific
// sample application there will be no serialization.
class CDialogItem
{
public:
	// define the enum with values to match whatever DLGITEMTEMPLATE requires

	DLGITEMTEMPLATE  m_dlgItemTemplate;

	enum            controltype {BUTTON = 0x0080, EDITCONTROL, STATICTEXT};
	controltype     m_controltype;
	CString         m_strCaption;

public:
	CDialogItem(enum controltype cType);  // default constructor will fill in default values
	CDialogItem() {};  // default constructor, not to be called directly

	void Initialize(enum controltype cType, UINT nID, CRect* prect = NULL, LPCTSTR pszCaption = NULL);
};

class CMyDialogTemplate
{
public:

	DLGTEMPLATE m_dlgTempl;
	CDialogItem m_rgDlgItem[3];  // the 3 controls to be inserted

	CMyDialogTemplate();
	void DemoIt();  // build the template and run it.
};

#endif
