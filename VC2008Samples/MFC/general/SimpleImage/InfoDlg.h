// This is a part of the Microsoft Foundation Classes C++ library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef __INFODLG_H__
#define __INFODLG_H__

#include "resource.h"
#include <afxstr.h>
#include <atlimage.h>

// CInfoDlg class

class CInfoDlg : public CDialog
{
// Implementation
public:
	CInfoDlg(CImage &image);
	// Dialog data
	enum { IDD = IDD_INFODLG };
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	CImage* m_pImage;
};

#endif
