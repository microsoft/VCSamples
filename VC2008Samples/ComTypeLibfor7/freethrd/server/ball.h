/*+==========================================================================
  File:      BALL.H

  Summary:   Include file for the aggregatable COBall COM object class.

             COBall offers a main standard IUnknown interface (basic COM
             object features) and the custom IBall interface (moving
             ball-related features).  This multiple interface COM Object
             Class is achieved via the technique of nested classes.  The
             implementation of the IBall interface is nested inside of the
             COBall Class.

             This file also declares some internal C++ classes (CXForm and
             CBallThread) that provide internal support for the custom
             IBall interface.

             For a comprehensive tutorial code tour of this module's
             contents and offerings see the accompanying FRESERVE.TXT file.
             For more specific technical details on the internal workings
             see the comments dispersed throughout the module's source code.

  Functions:

  Classes:   CXForm, CBallThread, COBall.

  Origin:    4-5-96: atrent - Editor-inheritance from CAR.H in
             the DLLSERVE OLE Tutorial Code Sample. Also borrows from
             the GDIDEMO sample in the Win32 samples of the Win32 SDK.

----------------------------------------------------------------------------
  This file is part of the Microsoft OLE Tutorial Code Samples.

  Copyright (c) Microsoft Corporation, 1996.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
==========================================================================+*/

#if !defined(BALL_H)
#define BALL_H

#ifdef __cplusplus

enum { MAX_BALLTHREADS = 64, BALL_MOVE_SKEW = 5 };


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CXForm

  Summary:  A utility class with methods for performing point
            transformations on points that represent space/location in two
            dimensions.

  Methods:  Clear
              Clears the transformation matrix.
            Scale
              Set transformation to multiply by a scale factor.
            Trans
              Perform transformation.
            Point
              Get point.
            CXForm
              Constructor.
            ~CXForm
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CXForm
{
  private:
    int XForm[3][3];

  public:
    CXForm(void) {};
    ~CXForm(void) {};
    void Clear(void);
    void Scale(int xScale, int yScale);
    void Trans(int xTrans, int yTrans);
    void Point(POINT* pPoint);
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CBallThread

  Summary:  A class for simple objects used to store properties of threads.
            An array of these is used to remember the threads that came
            visiting the CBall object.

  Methods:  CBallThread
              Constructor.
            ~CBallThread
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CBallThread
{
  public:
    DWORD Id;
    COLORREF Color;

    CBallThread(void) {};
    ~CBallThread(void) {};
};


/*O+O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O
  ObjectClass: COBall

  Summary:     COM object class for COBall COM objects.  COM objects of
               this class offer IBall interface features, Reset, Move, and
               GetBall. The mulitple interfaces on this COM object are
               constructed via the nested interface classes technique.

  Interfaces:  IUnknown
                 Standard interface providing COM object features.
               IBall
                 Basic Ball operation features.

  Aggregation: Yes, COBall COM Objects are aggregatable by passing
               a non-NULL pUnkOuter IUnknown pointer into the constructor.
O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O-O*/
class COBall : public IUnknown, public CThreaded
{
  public:
    // Main Object Constructor & Destructor.
    COBall(IUnknown* pUnkOuter, CServer* pServer);
    ~COBall(void);

    // IUnknown methods. Main object, non-delegating.
    STDMETHODIMP         QueryInterface(REFIID, PPVOID);
    STDMETHODIMP_(ULONG) AddRef(void);
    STDMETHODIMP_(ULONG) Release(void);

  private:
    // We declare nested class interface implementations here.

    class CImpIBall : public IBall, public CThreaded
    {
      public:
        // Interface Implementation Constructor & Destructor.
        CImpIBall(COBall* pBackObj, IUnknown* pUnkOuter);
        ~CImpIBall(void);

        // IUnknown methods.
        STDMETHODIMP         QueryInterface(REFIID, PPVOID);
        STDMETHODIMP_(ULONG) AddRef(void);
        STDMETHODIMP_(ULONG) Release(void);

        // IBall methods.
        STDMETHODIMP   Reset(RECT* pNewRect, short nBallSize);
        STDMETHODIMP   get_Ball(POINT* pOrg, POINT* pExt, COLORREF* pcrColor);
        STDMETHODIMP   Move(BOOL bAlive, BOOL* bRet);

      private:
        // Data private to this COBall interface implementation of IBall.
        COBall*      m_pBackObj;     // Parent Object back pointer.
        IUnknown*    m_pUnkOuter;    // Outer unknown for Delegation.

        // The following private data and methods constitute the working
        // heart of COBall as an actual application object.
        BOOL         m_bAlive;
        RECT         m_WinRect;
        int          m_nWidth;
        int          m_nHeight;
        int          m_xDirection;
        int          m_yDirection;
        BOOL         m_bNewPosition;
        int          m_xPosition;
        int          m_yPosition;
        short        m_xSkew;
        short        m_ySkew;
        COLORREF     m_crColor;
        CXForm       m_XForm;
        CBallThread  m_aBallThreads[MAX_BALLTHREADS];

        // Private methods for internal use.
        void GetDimensions(POINT*);
        void SetDimensions(int,int);
        void GetDirection(POINT*);
        void SetDirection(int,int);
        void GetPosition(POINT*);
        void SetPosition(int,int);
        void CheckBounce(void);
        void FindThread(void);
    };

    // Make the otherwise private and nested IBall interface implementation
    // a friend to COM object instantiations of this selfsame COBall
    // COM object class.
    friend CImpIBall;

    // Private data of COBall COM objects.

    // Nested IBall implementation instantiation.  This IBall interface
    // is instantiated inside this COBall object as a native interface.
    CImpIBall        m_ImpIBall;

    // Main Object reference count.
    ULONG            m_cRefs;

    // Outer unknown (aggregation & delegation).
    IUnknown*        m_pUnkOuter;

    // Pointer to this component server's control object.
    CServer*         m_pServer;
};

typedef COBall* PCOBall;

#endif // __cplusplus


#endif // BALL_H
