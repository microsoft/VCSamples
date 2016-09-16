// threads.cpp : contains all the different GDI thread classes
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
#include "mtgdi.h"
#include "threads.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

// critical section to protect while drawing to the DC
CRITICAL_SECTION CGDIThread::m_csGDILock;

// m_hAnotherDead is used to signal that one or more threads have ended
//  (it is an auto-reset event; and starts out not signaled)
HANDLE CGDIThread::m_hAnotherDead = CreateEvent(NULL, FALSE, FALSE, NULL);

/////////////////////////////////////////////////////////////////////////////
// CGDIThread

IMPLEMENT_DYNAMIC(CGDIThread, CWinThread)

BEGIN_MESSAGE_MAP(CGDIThread, CWinThread)
	//{{AFX_MSG_MAP(CGDIThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CGDIThread::CGDIThread(CWnd* pWnd, HDC hDC)
{
	m_bAutoDelete = FALSE;
	m_pMainWnd = pWnd;
	m_pMainWnd->GetClientRect(&m_rectBorder);
	m_hDC = hDC;

	// kill event starts out in the signaled state
	m_hEventKill = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_hEventDead = CreateEvent(NULL, TRUE, FALSE, NULL);
}

// The reason we don't just get a CDC from our owner and simply use it is because
// MFC GDI objects can't be passed between threads.  So we must instead pass a
// handle and then reconvert them back to MFC objects.  The reason  for this is
// because MFC maintains a list of all GDI objects on a per thread basis.  So if
// you pass a GDI object to another thread, it won't be in the correct list
// and MFC will assert.

BOOL CGDIThread::InitInstance()
{
	// thread setup
	m_dc.Attach(m_hDC);

	// loop but check for kill notification
	while (WaitForSingleObject(m_hEventKill, 0) == WAIT_TIMEOUT)
		SingleStep();

	// thread cleanup
	m_dc.Detach();

	// avoid entering standard message loop by returning FALSE
	return FALSE;
}

void CGDIThread::Delete()
{
	// calling the base here won't do anything but it is a good habit
	CWinThread::Delete();

	// acknowledge receipt of kill notification
	VERIFY(SetEvent(m_hEventDead));
	VERIFY(SetEvent(m_hAnotherDead));
}

CGDIThread::~CGDIThread()
{
	CloseHandle(m_hEventKill);
	CloseHandle(m_hEventDead);
}

void CGDIThread::KillThread()
{
	// Note: this function is called in the context of other threads,
	//  not the thread itself.

	// reset the m_hEventKill which signals the thread to shutdown
	VERIFY(SetEvent(m_hEventKill));

	// allow thread to run at higher priority during kill process
	SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);
	WaitForSingleObject(m_hEventDead, INFINITE);
	WaitForSingleObject(m_hThread, INFINITE);

	// now delete CWinThread object since no longer necessary
	delete this;
}

void CGDIThread::UpdateBorder()
{
	// Since another thread can access this variable, we block them when we write
	// it. In this case, it is overkill since the other thread would just animate
	// in the wrong direction while reading intermediate values and finally adjust
	// itself when the new value is valid.  It is a good idea to avoid such
	// anomalies, however.

	EnterCriticalSection(&CGDIThread::m_csGDILock);
	{
		m_pMainWnd->GetClientRect(&m_rectBorder);
	}
	LeaveCriticalSection(&CGDIThread::m_csGDILock);
}

/////////////////////////////////////////////////////////////////////////////
// CBallThread

IMPLEMENT_DYNAMIC(CBallThread, CGDIThread)

BEGIN_MESSAGE_MAP(CBallThread, CGDIThread)
	//{{AFX_MSG_MAP(CBallThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CBallThread::CBallThread(CWnd* pWnd, HDC hDC, CPoint ptPos, CPoint ptVel,
	CSize Size, COLORREF color)
	: CGDIThread(pWnd,hDC)
{
	m_rectPosition.SetRect(ptPos.x,ptPos.y,ptPos.x+Size.cx,ptPos.y+Size.cx);
	m_ptVelocity = ptVel;

	CBrush brush(color);
	m_hBrush = (HBRUSH)brush.Detach();
}

// The reason we don't just store the CBrush from our owner and simply use it is
// because MFC GDI objects can't be passed between threads.  So we must instead
// pass a handle and then reconvert them back to MFC objects.  The reason for
// this is because MFC maintains a list of all GDI objects on a per thread basis.
// So if you pass a GDI object to another thread, it won't be in the correct
// list and MFC will assert.

BOOL CBallThread::InitInstance()
{
	m_brush.Attach(m_hBrush);

	return CGDIThread::InitInstance();
}

void CBallThread::SingleStep()
{
	m_rectPosition.OffsetRect(m_ptVelocity);

	if (m_rectPosition.top<m_rectBorder.top)
		m_ptVelocity.y = (m_ptVelocity.y>0) ? m_ptVelocity.y : -m_ptVelocity.y;

	if (m_rectPosition.bottom>m_rectBorder.bottom)
		m_ptVelocity.y = (m_ptVelocity.y>0) ? -m_ptVelocity.y : m_ptVelocity.y;

	if (m_rectPosition.left<m_rectBorder.left)
		m_ptVelocity.x = (m_ptVelocity.x>0) ? m_ptVelocity.x : -m_ptVelocity.x;

	if (m_rectPosition.right>m_rectBorder.right)
		m_ptVelocity.x = (m_ptVelocity.x>0) ? -m_ptVelocity.x : m_ptVelocity.x;

	// Since all threads share the same HDC it is necessary
	// to block all other threads while we render in the HDC
	EnterCriticalSection(&CGDIThread::m_csGDILock);
	{
		CBrush* oldbrush;

		oldbrush = m_dc.SelectObject(&m_brush);
		m_dc.Ellipse(m_rectPosition);
		m_dc.SelectObject(oldbrush);

		// Win32 optimizes GDI calls by collecting them in a batch
		// and then thunking the whole batch at once on a per
		// thread basis.  Since we share an HDC with multiple
		// threads, we must flush the batch before yielding to
		// other threads that will adjust the HDC.  To see what
		// I mean, comment out the GdiFlush() function call and
		// watch the results.
		GdiFlush();
	}
	LeaveCriticalSection(&CGDIThread::m_csGDILock);
}

/////////////////////////////////////////////////////////////////////////////
//
// CRectThread
//
/////////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC(CRectThread, CGDIThread)

BEGIN_MESSAGE_MAP(CRectThread, CCmdTarget)
	//{{AFX_MSG_MAP(CRectThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CRectThread::CRectThread(CWnd* pWnd, HDC hDC, CPoint ptPos, CPoint ptVel,
	CSize Size, COLORREF color) : CGDIThread(pWnd, hDC)
{
	m_rectPosition.SetRect(ptPos.x ,ptPos.y, ptPos.x+Size.cx, ptPos.y+Size.cy);
	m_ptVelocity = ptVel;

	CBrush brush(color);
	m_hBrush = (HBRUSH)brush.Detach();
}

BOOL CRectThread::InitInstance()
{
	m_brush.Attach(m_hBrush);

	return CGDIThread::InitInstance();
}

void CRectThread::SingleStep()
{
	m_rectPosition.OffsetRect(m_ptVelocity);

	if (m_rectPosition.top<m_rectBorder.top)
		m_ptVelocity.y = (m_ptVelocity.y>0) ? m_ptVelocity.y : -m_ptVelocity.y;

	if (m_rectPosition.bottom>m_rectBorder.bottom)
		m_ptVelocity.y = (m_ptVelocity.y>0) ? -m_ptVelocity.y : m_ptVelocity.y;

	if (m_rectPosition.left<m_rectBorder.left)
		m_ptVelocity.x = (m_ptVelocity.x>0) ? m_ptVelocity.x : -m_ptVelocity.x;

	if (m_rectPosition.right>m_rectBorder.right)
		m_ptVelocity.x = (m_ptVelocity.x>0) ? -m_ptVelocity.x : m_ptVelocity.x;

	// Since all threads share the same HDC it is necessary
	// to block all other threads while we render in the HDC
	EnterCriticalSection(&CGDIThread::m_csGDILock);
	{
		CBrush* oldbrush;

		oldbrush = m_dc.SelectObject(&m_brush);
		m_dc.Rectangle(m_rectPosition);
		m_dc.SelectObject(oldbrush);

		// Win32 optimizes GDI calls by collecting them in a batch
		// and then thunking the whole batch at once on a per
		// thread basis.  Since we share an HDC with multiple
		// threads, we must flush the batch before yielding to
		// other threads that will adjust the HDC.  To see what
		// I mean, comment out the GdiFlush() function call and
		// watch the results.
		GdiFlush();
	}
	LeaveCriticalSection(&CGDIThread::m_csGDILock);
}

/////////////////////////////////////////////////////////////////////////////
// CLineThread

IMPLEMENT_DYNAMIC(CLineThread, CGDIThread)

BEGIN_MESSAGE_MAP(CLineThread, CCmdTarget)
	//{{AFX_MSG_MAP(CLineThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CLineThread::CLineThread(CWnd* pWnd, HDC hDC, CPoint ptPos1, CPoint ptVel1,
	CPoint ptVel2, CSize Size, COLORREF color) : CGDIThread(pWnd, hDC)
{
	m_ptPosition1 = ptPos1;
	m_ptPosition2 = ptPos1 + Size;
	m_ptVelocity1 = ptVel1;
	m_ptVelocity2 = ptVel2;

	CPen pen(PS_SOLID, 1, color);
	m_hPen = (HPEN)pen.Detach();
}

BOOL CLineThread::InitInstance()
{
	m_pen.Attach(m_hPen);

	return CGDIThread::InitInstance();
}

void CLineThread::SingleStep()
{
	m_ptPosition1.Offset(m_ptVelocity1);
	m_ptPosition2.Offset(m_ptVelocity2);

	if (m_ptPosition1.y<m_rectBorder.top)
		m_ptVelocity1.y = (m_ptVelocity1.y>0) ? m_ptVelocity1.y : -m_ptVelocity1.y;
	else if (m_ptPosition1.y>m_rectBorder.bottom)
		m_ptVelocity1.y = (m_ptVelocity1.y>0) ? -m_ptVelocity1.y : m_ptVelocity1.y;

	if (m_ptPosition2.y<m_rectBorder.top)
		m_ptVelocity2.y = (m_ptVelocity2.y>0) ? m_ptVelocity2.y : -m_ptVelocity2.y;
	else if (m_ptPosition2.y>m_rectBorder.bottom)
		m_ptVelocity2.y = (m_ptVelocity2.y>0) ? -m_ptVelocity2.y : m_ptVelocity2.y;

	if (m_ptPosition1.x<m_rectBorder.left)
		m_ptVelocity1.x = (m_ptVelocity1.x>0) ? m_ptVelocity1.x : -m_ptVelocity1.x;
	else if (m_ptPosition1.x>m_rectBorder.right)
		m_ptVelocity1.x = (m_ptVelocity1.x>0) ? -m_ptVelocity1.x : m_ptVelocity1.x;

	if (m_ptPosition2.x<m_rectBorder.left)
		m_ptVelocity2.x = (m_ptVelocity2.x>0) ? m_ptVelocity2.x : -m_ptVelocity2.x;
	else if (m_ptPosition2.x>m_rectBorder.right)
		m_ptVelocity2.x = (m_ptVelocity2.x>0) ? -m_ptVelocity2.x : m_ptVelocity2.x;

	// Since all threads share the same HDC it is necessary
	// to block all other threads while we render in the HDC
	EnterCriticalSection(&CGDIThread::m_csGDILock);
	{
		CPen* oldpen;

		oldpen = m_dc.SelectObject(&m_pen);
		m_dc.MoveTo(m_ptPosition1);
		m_dc.LineTo(m_ptPosition2);
		m_dc.SelectObject(oldpen);
		// Win32 optimizes GDI calls by collecting them in a batch
		// and then thunking the whole batch at once on a per
		// thread basis.  Since we share an HDC with multiple
		// threads, we must flush the batch before yielding to
		// other threads that will adjust the HDC.  To see what
		// I mean, comment out the GdiFlush() function call and
		// watch the results.
		GdiFlush();
	}
	LeaveCriticalSection(&CGDIThread::m_csGDILock);
}
