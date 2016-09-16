#if !defined(CTLCOMM_H__448D35FD_31CD_11D0_AE62_00C04FD7D06E__INCLUDED_)
#define CTLCOMM_H__448D35FD_31CD_11D0_AE62_00C04FD7D06E__INCLUDED_

// ctlcomm.h : main header file for the CTLCOMM application
//

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlcommApp:
// See ctlcomm.cpp for the implementation of this class
//

class CCtlcommApp : public CWinApp
{
public:
    CCtlcommApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCtlcommApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CCtlcommApp)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(CTLCOMM_H__448D35FD_31CD_11D0_AE62_00C04FD7D06E__INCLUDED)
