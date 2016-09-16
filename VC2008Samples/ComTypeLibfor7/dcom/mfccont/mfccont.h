// MFCCont.h : main header file for the MFCCONT application
//

#if !defined(AFX_MFCCONT_H__29DC9F76_5706_11D0_9899_00C04FD7D06E__INCLUDED_)
#define AFX_MFCCONT_H__29DC9F76_5706_11D0_9899_00C04FD7D06E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
    #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCContApp:
// See MFCCont.cpp for the implementation of this class
//

class CMFCContApp : public CWinApp
{
public:
    CMFCContApp();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMFCContApp)
    public:
    virtual BOOL InitInstance();
    //}}AFX_VIRTUAL

// Implementation

    //{{AFX_MSG(CMFCContApp)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCONT_H__29DC9F76_5706_11D0_9899_00C04FD7D06E__INCLUDED_)
