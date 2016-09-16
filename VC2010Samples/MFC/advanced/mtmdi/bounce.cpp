// bounce.cpp : Defines the class behaviors for the Bounce child window.
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
#include "mdi.h"
#include "bounce.h"
#include "mtbounce.h"

#define ABS(x) ((x) < 0? -(x) : (x) > 0? (x) : 0)

BEGIN_MESSAGE_MAP(CBounceMDIChildWnd, CMDIChildWnd)
	//{{AFX_MSG_MAP(CBounceMDIChildWnd)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USER_PREPARE_TO_CLOSE, OnPrepareToClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBounceMDIChildWnd

CMenu CBounceMDIChildWnd::menu;        // menu for all BOUNCE windows

CBounceMDIChildWnd::CBounceMDIChildWnd()
{
}

BOOL CBounceMDIChildWnd::Create(LPCTSTR szTitle, LONG style /* = 0 */,
	const RECT& rect /* = rectDefault */,
	CMDIFrameWnd* parent /* = NULL */)
{
	// Setup the shared menu
	if (menu.m_hMenu == NULL)
		menu.LoadMenu(IDR_BOUNCE);
	m_hMenuShared = menu.m_hMenu;

	if (!CMDIChildWnd::Create(NULL, szTitle, style, rect, parent))
		return FALSE;

	// The default PostNcDestroy handler will delete this CBounceMDIChildWnd
	// object when destroyed.  When Windows destroys the CBounceMDIChildWnd
	// window, it will also destroy the CBounceWnd, which is the child
	// window of the MDI child window, executing in the separate thread.
	// Finally, when the child CBounceWnd window is destroyed, the
	// CWinThread object will be automatically destroyed, as explained
	// in the comment for CBounceThread::InitInstance in mtbounce.cpp.

#pragma warning(push)
#pragma warning(disable:6014)
	CBounceThread* pBounceThread = new CBounceThread(m_hWnd);
#pragma warning(pop)

	pBounceThread->CreateThread();

	return TRUE;
}


BOOL CBounceMDIChildWnd::OnCmdMsg(UINT nID, int nCode, void* pExtra,
		AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// The default CFrameWnd::OnCmdMsg function is responsible for
	// dispatching menu commands to ON_COMMAND handlers and for
	// initializing menus and toolbars via ON_UPDATE_COMMAND_UI
	// handlers.  For the MDI child window, all such dispatching
	// and command user interface initialization are done in the
	// main application thread.  The CBounceWnd object processes
	// user interface events in a separate thread.  This override,
	// CBounceMDIChildWnd::OnCmdMsg, delegates command handling to
	// the child CBounceWnd window.  It cannot do this delegation
	// by simply calling CBounceWnd::OnCmdMsg, because doing so
	// would defeat the design of handling CBounceWnd user interface
	// events in the separate thread.  If CBounceMDIChildWnd::OnCmdMsg
	// simply called CBounceWnd::OnCmdMsg, then the command handling
	// would be processed in the same main application thread as that
	// of the MDI child window.
	//
	// A common and safe way to make a call from one thread to another
	// is to call SendMessage for a window whose message pump runs in
	// a second thread.  That is how CBounceMDIChildWnd::OnCmdMsg is
	// implemented.  All of the OnCmdMsg parameters are gathered into
	// an application-defined (but re-usable) COnCmdMsg structure,
	// that is sent by reference to the CBounceWnd window via the
	// lParam of SendMessage.


	CWnd* pBounceWnd = (CBounceWnd*)GetDlgItem(IDC_BOUNCE_WND);
	if (pBounceWnd == NULL)
		return FALSE; // child CBounceWnd not created yet.

	// It is safe to create the COnCmdMsg on the stack because
	// it will not be deleted until the SendMessage call has
	// synchronously executed.

	COnCmdMsg oncmdmsg;
	oncmdmsg.m_nID =    nID;
	oncmdmsg.m_nCode = nCode;
	oncmdmsg.m_pExtra = pExtra;
	oncmdmsg.m_pHandlerInfo = pHandlerInfo;

	// In addition to passing all of the OnCmdMsg parameters to
	// the CBounceWnd window via the SendMessage lParam, it is also
	// necessary to forward the implicit wParam originally passed
	// in the WM_COMMAND message for the menu command.  The original
	// WM_COMMAND wParam is not a parameter of OnCmdMsg, but it can
	// be obtained by calling GetCurrentMessage.  The wParam is needed by
	// the CBounceWnd::OnColor command handler to distinguish which
	// menu item, i.e., which color, was selected from the Color menu.
	//
	// The original single thread MDI sample application, the
	// CBounceWnd::OnColor command handler calls GetCurrentMessage
	// to retrieve the wParam from the WM_COMMAND message.  To satisfy
	// that implementation of CBounceWnd::OnColor, we call
	// GetCurrentMessage() and forward the wParam in the user-defined
	// WM_USER_ONCMDMSG message.  Alternatively, we could have
	// called GetMessageMsg and passed the wParam as an additional
	// member of the COnCmdMsg structure.

	return (BOOL)pBounceWnd->SendMessage(WM_USER_ONCMDMSG,
		GetCurrentMessage()->wParam, (LPARAM)&oncmdmsg);
}

BOOL CBounceMDIChildWnd::DestroyWindow()
{
	OnPrepareToClose();

	return CMDIChildWnd::DestroyWindow();
}

LRESULT CBounceMDIChildWnd::OnPrepareToClose(WPARAM, LPARAM)
{
	// Wait for the bounce thread to auto-destroy its CWinThread object
	// before continuing.  This avoids a possible false memory leak
	// detection in debug mode when exiting the application.  The false
	// memory leak might be reported if the main application thread
	// terminates sooner than the bounce thread auto-destroys its own
	// CWinThread object.  See also comments for CBounceWnd::OnNcDestroy.

	CWnd* pBounceWnd = (CBounceWnd*)GetDlgItem(IDC_BOUNCE_WND);
	pBounceWnd->SendMessage(WM_USER_PREPARE_TO_CLOSE);

	WaitForSingleObject(CBounceThread::m_hEventBounceThreadKilled, INFINITE);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CBounceWnd

BEGIN_MESSAGE_MAP(CBounceWnd, CWnd)
	//{{AFX_MSG_MAP(CBounceWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_UPDATE_COMMAND_UI(IDM_RED, OnUpdateColor)
	ON_COMMAND(IDM_BLACK, OnColor)
	ON_COMMAND(IDM_CUSTOM, OnCustomColor)
	ON_UPDATE_COMMAND_UI(IDM_SLOW, OnUpdateSlow)
	ON_COMMAND(IDM_SLOW, OnSlow)
	ON_UPDATE_COMMAND_UI(IDM_FAST, OnUpdateFast)
	ON_COMMAND(IDM_FAST, OnFast)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_RED, OnColor)
	ON_COMMAND(IDM_GREEN, OnColor)
	ON_COMMAND(IDM_BLUE, OnColor)
	ON_COMMAND(IDM_WHITE, OnColor)
	ON_UPDATE_COMMAND_UI(IDM_WHITE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_GREEN, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_CUSTOM, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLUE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(IDM_BLACK, OnUpdateColor)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USER_ONCMDMSG, OnDelegatedCmdMsg)
	ON_MESSAGE(WM_USER_PREPARE_TO_CLOSE, OnPrepareToClose)
END_MESSAGE_MAP()

IMPLEMENT_DYNAMIC(CBounceWnd, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CBounceWnd creation

BOOL CBounceWnd::Create(LPCTSTR szTitle, LONG style, const RECT& rect, CWnd* parent)
{
	// Register a custom WndClass and create a window.
	// This must be done because CBounceWnd has a custom cursor, and
	//  no icon.
	LPCTSTR lpszBounceClass =
		AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW,
			LoadCursor(NULL, IDC_UPARROW),
			(HBRUSH)(COLOR_WINDOW+1),
			NULL);

	return CWnd::Create(lpszBounceClass, szTitle, style, rect, parent,
		IDC_BOUNCE_WND);
}

CBounceWnd::CBounceWnd()
{
	m_nIDColor = IDM_BLACK;
	m_clrBall = RGB(0,0,0);
	m_bFastSpeed = FALSE;
}

void CBounceWnd::OnDestroy()
{
	// The following code forces a condition where the exiting application will
	// report a memory leak of the bounce CWinThread object if the application
	// does not wait for the bounce thread to auto-destroy its CWinThread object.
	// See also CMDIChildBounceWnd::OnNcDestroy.

#ifdef _DEBUG
	TRACE0("This is an intentional 1-second delay in terminating the bounce thread\n");
	Sleep(1000);
#endif
	CWnd::OnDestroy();
}

// Set up the ball parameters and start a timer.
int CBounceWnd::OnCreate(LPCREATESTRUCT /* p */)
{
	if (!SetTimer(1, 100 /*start slow*/, NULL))
	{
		MessageBox(_T("Not enough timers available for this window."),
				_T("MDI:Bounce"), MB_ICONEXCLAMATION | MB_OK);

		// signal creation failure...
		return -1;
	}

	CDC* pDC = GetDC();
	m_ptPixel.x = pDC->GetDeviceCaps(ASPECTX);
	m_ptPixel.y = pDC->GetDeviceCaps(ASPECTY);
	ReleaseDC(pDC);

	// Note that we could call MakeNewBall here (which should be called
	// whenever the ball's speed, color or size has been changed), but the
	// OnSize member function is always called after the OnCreate. Since
	// the OnSize member has to call MakeNewBall anyway, we don't here.

	return 0;
}

// MakeNewBall:
// Whenever a parameter changes which would affect the speed or appearance
// of the ball, call this to regenerate the ball bitmap.
//
void CBounceWnd::MakeNewBall()
{
	m_sizeTotal.cx = (m_sizeRadius.cx + ABS(m_sizeMove.cx)) << 1;
	m_sizeTotal.cy = (m_sizeRadius.cy + ABS(m_sizeMove.cy)) << 1;

	if (m_bmBall.m_hObject != NULL)
		m_bmBall.DeleteObject();        // get rid of old bitmap

	CClientDC dc(this);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);

	m_bmBall.CreateCompatibleBitmap(&dc, m_sizeTotal.cx, m_sizeTotal.cy);
	ASSERT(m_bmBall.m_hObject != NULL);

	CBitmap* pOldBitmap = dcMem.SelectObject(&m_bmBall);

	// draw a rectangle in the background (window) color
	CRect rect(0, 0, m_sizeTotal.cx, m_sizeTotal.cy);
	CBrush brBackground(::GetSysColor(COLOR_WINDOW));
	dcMem.FillRect(rect, &brBackground);

	CBrush brCross(HS_DIAGCROSS, 0L);
	CBrush* pOldBrush = dcMem.SelectObject(&brCross);

	dcMem.SetBkColor(m_clrBall);
	dcMem.Ellipse(ABS(m_sizeMove.cx), ABS(m_sizeMove.cy),
		m_sizeTotal.cx - ABS(m_sizeMove.cx),
		m_sizeTotal.cy - ABS(m_sizeMove.cy));

	dcMem.SelectObject(pOldBrush);
	dcMem.SelectObject(pOldBitmap);
	dcMem.DeleteDC();
}

// The ball's size and displacement change according to the window size.
void CBounceWnd::OnSize(UINT nType, int cx, int cy)
{
	LONG lScale;

	m_ptCenter.x = cx >> 1;
	m_ptCenter.y = cy >> 1;
	m_ptCenter.x += cx >> 3; // make the ball a little off-center

	lScale = min((LONG)cx * m_ptPixel.x,
		(LONG)cy * m_ptPixel.y) >> 4;
	m_sizeRadius.cx = (int)(lScale / m_ptPixel.x);
	m_sizeRadius.cy = (int)(lScale / m_ptPixel.y);
	m_sizeMove.cx = max(1, m_sizeRadius.cy >> 2);
	m_sizeMove.cy = max(1, m_sizeRadius.cy >> 2);

	MakeNewBall();

	CWnd::OnSize(nType, cx, cy);
}

/////////////////////////////////////////////////////////////////////////////
// CBounceWnd commands

LRESULT CBounceWnd::OnDelegatedCmdMsg(WPARAM, LPARAM lParam)
{
	COnCmdMsg* pOnCmdMsg = (COnCmdMsg*)lParam;
	return CWnd::OnCmdMsg(pOnCmdMsg->m_nID, pOnCmdMsg->m_nCode, pOnCmdMsg->m_pExtra,
			pOnCmdMsg->m_pHandlerInfo);
}

LRESULT CBounceWnd::OnPrepareToClose(WPARAM, LPARAM)
{
	DestroyWindow();
	return 0;
}

void CBounceWnd::OnUpdateColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nIDColor);
}

void CBounceWnd::OnColor()
{
	m_nIDColor = LOWORD(GetCurrentMessage()->wParam);
	m_clrBall = colorArray[m_nIDColor - IDM_BLACK];

	// Force the client area text to be repainted in the new color
	MakeNewBall();
	Invalidate();
}

void CBounceWnd::OnCustomColor()
{
	CColorDialog dlgColor(m_clrBall);
	if (dlgColor.DoModal() == IDOK)
	{
		m_clrBall = dlgColor.GetColor();
		m_nIDColor = IDM_CUSTOM;
		MakeNewBall();
		Invalidate();
	}
}

// Change the ball's speed
void CBounceWnd::ChangeSpeed()
{
	// re-create the timer
	KillTimer(1);
	if (!SetTimer(1, m_bFastSpeed ? 0 : 100, NULL))
	{
		MessageBox(_T("Not enough timers available for this window."),
				_T("MDI:Bounce"), MB_ICONEXCLAMATION | MB_OK);
		DestroyWindow();
	}
}

// Animate the ball.
void CBounceWnd::OnTimer(UINT_PTR /* wParam */)
{
	if (m_bmBall.m_hObject == NULL)
		return;     // no bitmap for the ball

	CRect rcClient;
	GetClientRect(rcClient);

	CClientDC dc(this);
	CBitmap* pbmOld = NULL;

	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	pbmOld = dcMem.SelectObject(&m_bmBall);

	dc.BitBlt(m_ptCenter.x - m_sizeTotal.cx / 2,
			m_ptCenter.y - m_sizeTotal.cy / 2,
			m_sizeTotal.cx, m_sizeTotal.cy,
			&dcMem, 0, 0, SRCCOPY);

	m_ptCenter += m_sizeMove;

	if ((m_ptCenter.x + m_sizeRadius.cx >= rcClient.right) ||
		(m_ptCenter.x - m_sizeRadius.cx <= 0))
	{
		m_sizeMove.cx = -m_sizeMove.cx;
	}

	if ((m_ptCenter.y + m_sizeRadius.cy >= rcClient.bottom) ||
		(m_ptCenter.y - m_sizeRadius.cy <= 0))
	{
		m_sizeMove.cy = -m_sizeMove.cy;
	}

	dcMem.SelectObject(pbmOld);
	dcMem.DeleteDC();
}

void CBounceWnd::OnUpdateSlow(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!m_bFastSpeed);
}

void CBounceWnd::OnSlow()
{
	m_bFastSpeed = FALSE;
	ChangeSpeed();
}

void CBounceWnd::OnUpdateFast(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bFastSpeed);
}

void CBounceWnd::OnFast()
{
	m_bFastSpeed = TRUE;
	ChangeSpeed();
}

void CBounceMDIChildWnd::OnSize(UINT nType, int cx, int cy)
{
	CMDIChildWnd::OnSize(nType, cx, cy);

	CWnd* pBounceWnd = GetDlgItem(IDC_BOUNCE_WND);
	if (pBounceWnd == NULL)
		return; // child CBounceWnd not created yet

	CRect rect;
	GetClientRect(&rect);
	pBounceWnd->SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(),
		SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);
}

void CBounceWnd::OnLButtonDown(UINT, CPoint point)
{
	Invalidate();

	CRect rcClient;
	GetClientRect(rcClient);

	point.x = min(point.x, rcClient.right - 2*m_sizeRadius.cx);
	point.x = max(point.x, 2*m_sizeRadius.cx);
	point.y = min(point.y, rcClient.bottom - 2*m_sizeRadius.cx);
	point.y = max(point.y, 2*m_sizeRadius.cy);

	m_ptCenter = point;
}
