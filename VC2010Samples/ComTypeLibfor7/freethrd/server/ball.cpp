/*+==========================================================================
  File:      BALL.CPP

  Summary:   Implementation file for the COBall COM Object Class (for
             aggregatable COBall COM Objects). This module provides a free
             threaded virtual ball object. The ball has internal
             algorithms that determine its position within a bounded two
             dimensional area. No display or other GUI behavior is done in
             this ball.  It is a mathematical entity. Clients of this ball
             can command it to reset, move, and reveal its current
             position, size, and color. These last are used by a client
             that displays images of this ball. The color in particular is
             an internal property maintained by the ball that indicates
             the thread of execution that last moved this ball.

             COBall offers a main standard IUnknown interface (basic COM
             object features) and the custom IBall interface (Moving Ball
             related features).  This multiple interface COM Object Class
             is achieved via the technique of nested classes.  The
             implementation of the IBall interface is nested inside the
             COBall Class.

             This file also implements some internal C++ classes (CXForm
             and CBallThread) that provide internal support for the custom
             IBall interface.

             For a comprehensive tutorial code tour of this module's
             contents and offerings see the accompanying FRESERVE.TXT
             file. For more specific technical details on the internal
             workings see the comments dispersed throughout the module's
             source code.

  Classes:   CXForm, CBallThread, COBall.

  Functions: none.

  Origin:    4-5-96: atrent - Editor-inheritance from CAR.CPP in
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


/*---------------------------------------------------------------------------
  We include WINDOWS.H for all Win32 applications.
  We include OLE2.H because we will be making calls to the OLE Libraries.
  We include APPUTIL.H because we will be building this application using
    the convenient Virtual Window and Dialog classes and other
    utility functions in the APPUTIL Library (ie, APPUTIL.LIB).
  We include IBALL.H and BALLGUID.H for the common Ball-related Interface
    class, GUID, and CLSID specifications.
  We include SERVER.H because it has internal class declarations and
    resource ID definitions specific for this DLL.
  We include BALL.H because it has the class COBall declarations.
---------------------------------------------------------------------------*/
#include "preserve.h"
#include "ball.h"


/*---------------------------------------------------------------------------
  COBall's implementation of its internal utility class CXForm.
---------------------------------------------------------------------------*/


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CXForm::Clear

  Summary:  Clears and initializes the transformation matrix.

  Args:     void

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void CXForm::Clear(void)
{
  int Row,Col;

  for(Row=0; Row < 3; Row++)
    for(Col=0; Col < 3; Col++)
      if(Row == Col)
        XForm[Row][Col] = 1;
      else
        XForm[Row][Col] = 0;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CXForm::Scale

  Summary:  Method to allow setting the transformation to multiply
            by a scale factor.

  Args:     int xScale
              x Scale factor.
            int yScale
              y Scale factor.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void CXForm::Scale(int xScale, int yScale)
{
  int idx;

  for(idx=0; idx < 3; idx++)
  {
    XForm[idx][0] = XForm[idx][0] * xScale;
    XForm[idx][1] = XForm[idx][1] * yScale;
  }

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CXForm::Trans

  Summary:  Perform the transform uing the internal matrix.

  Args:     int xTrans
              x coordinate.
            int yTrans
              y coordinate.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void CXForm::Trans(int xTrans, int yTrans)
{
  XForm[2][0] = XForm[2][0] + xTrans;
  XForm[2][1] = XForm[2][1] + yTrans;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CXForm::Point

  Summary:  Transform a point.

  Args:     POINT* pPoint
              Pointer to the point.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void CXForm::Point(POINT* pPoint)
{
  int x,y;

  x = (XForm[0][0] * pPoint->x) + (XForm[1][0] * pPoint->y) + XForm[2][0];
  y = (XForm[0][1] * pPoint->x) + (XForm[1][1] * pPoint->y) + XForm[2][1];

  pPoint->x = x;
  pPoint->y = y;

  return;
}


/*---------------------------------------------------------------------------
  COBall's implementation of its main COM object class including
  Constructor, Destructor, QueryInterface, AddRef, and Release.
---------------------------------------------------------------------------*/

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::COBall

  Summary:  COBall Constructor. Note the member initializer:
            "m_ImpIBall(this, pUnkOuter)" which is used to pass the 'this'
            and pUnkOuter pointers of this constructor function to the
            constructor in the instantiation of the implementation of the
            CImpIBall interface (which is nested inside this present
            COBall Object Class).

  Args:     IUnknown* pUnkOuter,
              Pointer to the the outer Unknown.  NULL means this COM Object
              is not being Aggregated.  Non NULL means it is being created
              on behalf of an outside COM object that is reusing it via
              aggregation.
            CServer* pServer)
              Pointer to the server's control object.

  Modifies: m_cRefs, m_pUnkOuter, m_pServer.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
COBall::COBall(
  IUnknown* pUnkOuter,
  CServer* pServer) :
  m_ImpIBall(this, pUnkOuter)
{
  // Zero the COM object's reference count.
  m_cRefs = 0;

  // No AddRef necessary if non-NULL, as we're nested.
  m_pUnkOuter = pUnkOuter;

  // Assign the pointer to the server control object.
  m_pServer = pServer;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::~COBall

  Summary:  COBall Destructor.

  Args:     void

  Modifies: .

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
COBall::~COBall(void)
{
  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::QueryInterface

  Summary:  QueryInterface of the COBall non-delegating
            IUnknown implementation.

  Args:     REFIID riid,
              [in] GUID of the Interface being requested.
            PPVOID ppv)
              [out] Address of the caller's pointer variable that will
              receive the requested interface pointer.

  Modifies: .

  Returns:  HRESULT
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP COBall::QueryInterface(
               REFIID riid,
               PPVOID ppv)
{
  HRESULT hr = E_NOINTERFACE;

  if (OwnThis())
  {
    *ppv = NULL;

    if (IID_IUnknown == riid)
      *ppv = this;
    else if (IID_IBall == riid)
      *ppv = &m_ImpIBall;

    if (NULL != *ppv)
    {
      // We've handed out a pointer to the interface so obey the COM rules
      // and AddRef the reference count.
      ((LPUNKNOWN)*ppv)->AddRef();
      hr = NOERROR;
    }

    UnOwnThis();
  }

  return (hr);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::AddRef

  Summary:  AddRef of the COBall non-delegating IUnknown implementation.

  Args:     void

  Modifies: m_cRefs.

  Returns:  ULONG
              New value of m_cRefs (COM object's reference count).
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) COBall::AddRef(void)
{
  ULONG cRefs = 0;

  if (OwnThis())
  {
    cRefs = ++m_cRefs;

    UnOwnThis();
  }

  return cRefs;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::Release

  Summary:  Release of the COBall non-delegating IUnknown implementation.

  Args:     void

  Modifies: m_cRefs.

  Returns:  ULONG
              New value of m_cRefs (COM object's reference count).
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) COBall::Release(void)
{
  ULONG cRefs = 0;

  if (OwnThis())
  {
    cRefs = --m_cRefs;

    if (0 == cRefs)
    {
      // We've reached a zero reference count for this COM object.
      // So we tell the server housing to decrement its global object
      // count so that the server will be unloaded if appropriate.
      if (NULL != m_pServer)
        m_pServer->ObjectsDown();

      // We artificially bump the main ref count to prevent reentrancy
      // via the main object destructor.  Not really needed in this
      // COBall but a good practice because we are aggregatable and
      // may at some point in the future add something entertaining like
      // some Releases to the COBall destructor. We relinquish thread
      // ownership of this object before deleting it--a good practice.
      m_cRefs++;
      UnOwnThis();
      delete this;
    }
    else
      UnOwnThis();
  }

  return cRefs;
}


/*---------------------------------------------------------------------------
  COBall's nested implementation of the IBall interface including
  Constructor, Destructor, QueryInterface, AddRef, Release, Reset, Move,
  and GetBall. This interface implementation also has internal methods
  that are not particulary intended for outside clients: GetDimensions,
  SetDimensions, GetDirection, SetDirection, GetPosition, SetPostion,
  CheckBounce, and FindThread. The IBall interface only provides client
  access to the IUnknown methods and the Reset, Move, and GetBall methods.
---------------------------------------------------------------------------*/

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::CImpIBall

  Summary:  Constructor for the CImpIBall interface instantiation.

  Args:     COBall* pBackObj,
              Back pointer to the parent outer object.
            IUnknown* pUnkOuter
              Pointer to the outer Unknown.  For delegation.

  Modifies: m_pBackObj, m_pUnkOuter.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
COBall::CImpIBall::CImpIBall(
  COBall* pBackObj,
  IUnknown* pUnkOuter)
{
  size_t i;
  BYTE r=128, g=128, b=128;

  // Init the Back Object Pointer to point to the parent object.
  m_pBackObj = pBackObj;

  // Init the CImpIBall interface's delegating Unknown pointer.  We use
  // the Back Object pointer for IUnknown delegation here if we are not
  // being aggregated.  If we are being aggregated we use the supplied
  // pUnkOuter for IUnknown delegation.  In either case the pointer
  // assignment requires no AddRef because the CImpIBall lifetime is
  // quaranteed by the lifetime of the parent object in which
  // CImpIBall is nested.
  if (NULL == pUnkOuter)
    m_pUnkOuter = pBackObj;
  else
    m_pUnkOuter = pUnkOuter;

  // Now initialize the Ball application entity data.
  m_bAlive       = TRUE;
  m_xDirection   = 0;
  m_yDirection   = 0;
  m_bNewPosition = FALSE;
  m_xPosition    = 0;
  m_yPosition    = 0;
  m_nWidth       = 30;
  m_nHeight      = 30;
  m_xSkew        = BALL_MOVE_SKEW;
  m_ySkew        = BALL_MOVE_SKEW;
  m_crColor      = RGB(0,0,0);

  // Clear point transformation array.
  m_XForm.Clear();

  // Init BallThread array--init colors and clear thread Ids.
  // The BallThreads are the threads that contend to move and/or
  // paint the ball object.
  for (i = 0; i < MAX_BALLTHREADS; i++)
    m_aBallThreads[i].Id = 0;
  m_aBallThreads[0].Color = RGB(0  ,  0,255);  // Blue
  m_aBallThreads[1].Color = RGB(255,  0,  0);  // Red
  m_aBallThreads[2].Color = RGB(0  ,255,  0);  // Green
  m_aBallThreads[3].Color = RGB(0  ,  0,  0);  // Black
  m_aBallThreads[4].Color = RGB(255,  0,255);  // Purple
  m_aBallThreads[5].Color = RGB(0  ,255,255);  // Aqua
  m_aBallThreads[6].Color = RGB(255,255,  0);  // Brown
  int mBalls = MAX_BALLTHREADS;
  
  if ( mBalls > 8)
    for (i=7; i<MAX_BALLTHREADS; i++)
    {
      // Fill the remainder with some random colors.
      m_aBallThreads[i].Color = RGB(r,g,b);
      r = (BYTE) lRandom() % 255;
      g = (BYTE) lRandom() % 255;
      b = (BYTE) lRandom() % 255;
    }

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::~CImpIBall

  Summary:  Destructor for the CImpIBall interface instantiation.

  Args:     void

  Modifies: .

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
COBall::CImpIBall::~CImpIBall(void)
{
  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::GetDimensions

  Summary:  Internal utility method to get the ball x,y dimensions.

  Args:     POINT* pDimension
              Pointer to the point that will contain the dimensions.

  Modifies: *pDimension.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::GetDimensions(POINT* pDimension)
{
  pDimension->x = m_nWidth;
  pDimension->y = m_nHeight;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::SetDimensions

  Summary:  Internal utility method to set the ball x,y dimensions.

  Args:     int nWidth
              New Ball width.
            int nHeight
              New Ball Height.

  Modifies: .

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::SetDimensions(int nWidth, int nHeight)
{
  m_nWidth  = nWidth;
  m_nHeight = nHeight;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::GetDirection

  Summary:  Internal utility method to get the ball direction.

  Args:     POINT* pDirection
              Pointer to the Point that will contain the x,y direction
              data.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::GetDirection(POINT* pDirection)
{
  pDirection->x = m_xDirection;
  pDirection->y = m_yDirection;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::SetDirection

  Summary:  Internal utility method to set the ball direction.

  Args:     int xDirection
              x coordinate of the new direction.
            int yDirection
              y coordinate of the new direction.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::SetDirection(int xDirection, int yDirection)
{
  m_xDirection = xDirection;
  m_yDirection = yDirection;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::GetPosition

  Summary:  Internal utility method to get current the ball position.

  Args:     POINT* pPosition
              Pointer to the Point that is the position.

  Modifies: *pPostion.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::GetPosition(POINT* pPosition)
{
  POINT Org;

  Org.x = 0;
  Org.y = 0;
  m_XForm.Point(&Org);

  pPosition->x = Org.x;
  pPosition->y = Org.y;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::SetPosition

  Summary:  Internal utility method to set current the ball position.

  Args:     int x
              x-coordinate of new position.
            int y
              y-coordinate of new position.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::SetPosition(int x, int y)
{
  m_bNewPosition = TRUE;
  m_xPosition    = x;
  m_yPosition    = y;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::CheckBounce

  Summary:  Internal utility method to check the current ball position,
            dimension, and direction data and determine if the ball has
            hit the internal WinRect bounding rectangle. If it has then
            the ball data is recalculated to achieve a "bounce" effect
            for the ball as it moves.

  Args:     void

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::CheckBounce(void)
{
  POINT Pos, Dir, Dim;
  int   xNewPos, yNewPos, xNewDir, yNewDir;

  GetPosition(&Pos);
  GetDirection(&Dir);
  GetDimensions(&Dim);

  // Check each edge of the client rectangle.  If the ball goes past the
  // boundries, reset its position and direction to give it a "bounce"
  // effect the next time it is displayed.
  xNewDir = Dir.x;
  yNewDir = Dir.y;
  xNewPos = Pos.x + Dir.x;
  yNewPos = Pos.y + Dir.y;

  if(xNewPos < m_WinRect.left)
  {
    xNewDir = ((lRandom() % m_xSkew) + m_xSkew);
    SetPosition(m_WinRect.left, Pos.y);
  }
  if((xNewPos + Dim.x) > m_WinRect.right)
  {
    xNewDir = -(((int)lRandom() % m_xSkew) + m_xSkew);
    SetPosition(m_WinRect.right - Dim.x, Pos.y);
  }
  if(yNewPos < m_WinRect.top)
  {
    yNewDir = ((lRandom() % m_ySkew) + m_ySkew);
    SetPosition(Pos.x, m_WinRect.top);
  }
  if((yNewPos + Dim.y) > m_WinRect.bottom)
  {
    yNewDir = -(((int)lRandom() % m_ySkew) + m_ySkew);
    SetPosition(Pos.x, m_WinRect.bottom - Dim.y);
  }

  SetDirection(xNewDir, yNewDir);

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::FindThread

  Summary:  Internal utility method to Find the thread that is now
            executing this code. If the executing thread is not already in
            the Thread array remember the new Thread's Id and add it to the
            array. This in effect assigns the thread a color that can be
            used for tutorial display of which thread is executing on the
            ball object.

  Args:     void

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void COBall::CImpIBall::FindThread(void)
{
  BOOL bFound = FALSE;
  DWORD dwTId = GetCurrentThreadId();
  size_t i = 0;

  while(!bFound && i<MAX_BALLTHREADS)
  {
    if (m_aBallThreads[i].Id == 0)
    {
      // Found empty slot. This simple array logic allows no empty holes.
      m_aBallThreads[i].Id = dwTId;
      bFound = TRUE;
    }
    else
    {
      if (m_aBallThreads[i].Id == dwTId)
      {
        // Found previous visiting thread--use its assigned color.
        m_crColor = m_aBallThreads[i].Color;
        bFound = TRUE;
      }
      else
      {
        i++;
        if (i >= MAX_BALLTHREADS)
        {
          // Thread array is full--use a gray color for all other
          // excess visiting threads.
          m_crColor = RGB(127,127,127);
          bFound = TRUE;
        }
      }
    }
  }

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::QueryInterface

  Summary:  The QueryInterface IUnknown member of this IBall interface
            implementation that delegates to m_pUnkOuter, whatever it is.

  Args:     REFIID riid,
              [in] GUID of the Interface being requested.
            PPVOID ppv)
              [out] Address of the caller's pointer variable that will
              receive the requested interface pointer.

  Modifies: .

  Returns:  HRESULT
              Returned by the delegated outer QueryInterface call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP COBall::CImpIBall::QueryInterface(
               REFIID riid,
               PPVOID ppv)
{
  // Delegate this call to the outer object's QueryInterface.
  return m_pUnkOuter->QueryInterface(riid, ppv);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::AddRef

  Summary:  The AddRef IUnknown member of this IBall interface
            implementation that delegates to m_pUnkOuter, whatever it is.

  Args:     void

  Modifies: .

  Returns:  ULONG
              Returned by the delegated outer AddRef call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) COBall::CImpIBall::AddRef(void)
{
  // Delegate this call to the outer object's AddRef.
  return m_pUnkOuter->AddRef();
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::Release

  Summary:  The Release IUnknown member of this IBall interface
            implementation that delegates to m_pUnkOuter, whatever it is.

  Args:     void

  Modifies: .

  Returns:  ULONG
              Returned by the delegated outer Release call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) COBall::CImpIBall::Release(void)
{
  // Delegate this call to the outer object's Release.
  return m_pUnkOuter->Release();
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::Reset

  Summary:  The Reset member method of the IBall interface implementation.
            Called by outside clients of a COBall object to reset the
            virtual ball. It is restored to the upper left corner.

  Args:     RECT* pNewRect,
              Pointer to a RECT structure. Tells the COBall the bounding
              rectangle within which the ball can move.
            short nBallSize,
              The size of the ball in pixels. nBallSize == Width == Height
              meaning that a circle is assumed.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP COBall::CImpIBall::Reset(
               RECT* pNewRect,
               short nBallSize)
{
  HRESULT hr = E_FAIL;
  int nDim, xDirection, yDirection;

  if (OwnThis())
  {
    // Find the thread who is executing this and remember its color.
    FindThread();

    m_xSkew = m_ySkew = BALL_MOVE_SKEW;
    m_WinRect.left = pNewRect->left;
    m_WinRect.top = pNewRect->top;
    m_WinRect.right = pNewRect->right;
    m_WinRect.bottom = pNewRect->bottom;
    nDim = nBallSize ? nBallSize : max(5, m_WinRect.right / 13);
    SetDimensions(nDim, nDim);
    SetPosition(0, 0);
    xDirection = ((lRandom() % m_xSkew) + m_xSkew);
    yDirection = ((lRandom() % m_ySkew) + m_ySkew);
    SetDirection(xDirection, yDirection);

    hr = NOERROR;

    UnOwnThis();
  }

  return hr;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::Move

  Summary:  The Move member method of this IBall interface implementation.
            Called by outside clients of a COBall object to advance the
            "motion" of this COBall virtual ball entity.

  Args:     BOOL bAlive
              TRUE means stay alive; FALSE means don't move but die.

  Modifies: m_bAlive.

  Returns:  BOOL
              TRUE means the move was done and the ball is still alive.
              FALSE means the move was not done and the ball has been
              killed.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP COBall::CImpIBall::Move(BOOL bAlive, BOOL* bRet)
{
  *bRet = FALSE;

  if (OwnThis())
  {
    if (bAlive)
    {
      // Find thread that is now executing this code. Remember its Id and
      // assign it a color. If this thread previously visited here then
      // use its remembered values. In any case, set a color value in
      // m_crColor of its existing or newly assigned color.
      FindThread();

      // Ask the Ball if it has hit any of the edges of the current window
      // rectangle. If so, it will recalculate its position and direction to
      // achieve a "bounce" effect in its motion the next time it is painted.
      CheckBounce();

      // Calculate and set new ball position.
      if(m_bNewPosition)
      {
        m_bNewPosition = FALSE;
        m_XForm.Clear();
        m_XForm.Trans(m_xPosition, m_yPosition);
      }
      else
        m_XForm.Trans(m_xDirection, m_yDirection);
    }
    else
      m_bAlive = FALSE;

    *bRet = m_bAlive;

    UnOwnThis();
  }

  return S_OK;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   COBall::CImpIBall::GetBall

  Summary:  The GetBall member method of this IBall interface
            implementation. Called by outside clients of a COBall object
            to get the necessary data on the moving ball to enable GUI
            display of an actual image of this virtual ball. This COBall
            is a data entity only that is kept alive by client threads
            that call Move. A GUI client can independently call GetBall
            to allow it to display some visual representation of the Ball.

  Args:     POINT* pOrg,
              Pointer to a point that will contain the current origin
              position of the ball.
            POINT* pExt,
              Pointer to a point that will contain the current extent
              size of the ball.
            COLORREF* pcrColor)
              Pointer to a COLORREF that will contain the current color
              of the ball. This color is determined by the last thread
              that was executing in the ball before this call is made.

  Modifies: ...

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP COBall::CImpIBall::get_Ball(
       POINT* pOrg,
       POINT* pExt,
       COLORREF* pcrColor)
{
  HRESULT hr = E_FAIL;

  if (OwnThis())
  {
    *pcrColor = m_crColor;

    pOrg->x = 0;
    pOrg->y = 0;
    m_XForm.Point(pOrg);
    pExt->x = m_nWidth;
    pExt->y = m_nHeight;
    m_XForm.Point(pExt);

    hr = NOERROR;

    UnOwnThis();
  }

  return hr;
}
