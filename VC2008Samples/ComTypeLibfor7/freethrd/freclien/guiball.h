/*+==========================================================================
  File:      GUIBALL.H

  Summary:   Include file for the CGuiBall C++ class. A GuiBall is a C++
             object that uses three independent worker threads to display
             a moving and bouncing ball in the client area of a designated
             window.  It is anchored to the Windows GUI (Graphical User
             Interface) environment. This GuiBall object continuously
             paints a ball image based on data it obtains from a virtual
             ball object. This virtual ball object is instantiated as a
             COM object (a COBall) in a separate In-process server,
             FRESERVE.

             GuiBall launches three threads which all continuously and
             asynchronously command the ball to move. GuiBall itself
             provides methods to initialize the GuiBall, paint the ball
             image, and restart the motion.

             For a comprehensive tutorial code tour of GUIBALL's contents
             and offerings see the accompanying FRECLIEN.TXT file. For more
             specific technical details on the internal workings see the
             comments dispersed throughout the GUIBALL source code.

  Classes:   CThreadInitData, CGuiBall

  Origin:    4-5-96: atrent - Created for OLE Tutorial Code Samples.
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

#if !defined(GUIBALL_H)
#define GUIBALL_H

#if defined(__cplusplus)


// Here are constants for the delays in millisecons that control
// the incremental motion of the ball and how often a snapshot of
// the ball image is painted.
enum { BALL_PAINT_DELAY  = 30, BALL_MOVE_DELAY = 100 };

// A small utility struct providing an encapsulation of data needed when
// worker threads are initialized.
struct CThreadInitData
{
  HWND     m_hWnd;
  IBallPtr m_pIBall;
  DWORD    m_nDelay;
};


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    CGuiBall

  Summary:  Class to encapsulate the displayable Graphical User
            Interface GUI Ball object.

  Methods:  CGuiBall
              Constructor.
            ~CGuiBall
              Destructor.
            BOOL Init(HWND hWnd);
              Initialize the GuiBall.
            void PaintBall(void);
              Paint one image of the Ball.
            void Restart(void);
              Restart the process including clear window, move ball to
              start position, restart motion.
            void PaintWin(void);
              Repaint the window but don't restart motion.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class CGuiBall
{
  private:
    HWND     m_hWnd;
    IBallPtr m_pIBall;
    COLORREF m_crColor;

    // Pointers to thread init data structures.
    CThreadInitData m_BallThreadData1;
    CThreadInitData m_BallThreadData2;
    CThreadInitData m_BallThreadData3;

  public:
    // Some member variables to store thread ids.
    DWORD m_dwBallThread1;
    DWORD m_dwBallThread2;
    DWORD m_dwBallThread3;

    // An array of handles to the ball threads.
    HANDLE m_hBallThreads[3];

    CGuiBall(void);
    ~CGuiBall(void);
    BOOL Init(HWND hWnd);
    void PaintBall(void);
    void Restart(void);
    void PaintWin(void);
};


#endif // __cplusplus

#endif
