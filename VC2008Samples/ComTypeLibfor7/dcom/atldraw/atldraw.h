// ATLDraw.h : main header file for the ATLDRAW application
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.
//

#ifndef __AFXWIN_H__
    #error include 'preatldr.h' before including this file for PCH
#endif

#include "atldres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CATLDrawApp:
// See ATLDraw.cpp for the implementation of this class
//

class CATLDrawApp : public CWinApp
{
public:
    CATLDrawApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CATLDrawApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CATLDrawApp)
    afx_msg void OnAppAbout();
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
