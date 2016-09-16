// ChildView.cpp : implementation of the CChildView class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#include "stdafx.h"
#include "MMXSwarm.h"
#include "ChildView.h"

#include "MMXSurface.h"
#include "SSE2Surface.h"
#include "Swarm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_WM_SIZE()
    ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
    ON_COMMAND(ID_FILE_SAVE, OnFileSave)
    ON_COMMAND(ID_VIEW_PAUSE_BLUR, OnViewPauseBlur)
    ON_COMMAND(ID_VIEW_PAUSE_SWARM, OnViewPauseSwarm)
    ON_COMMAND(ID_VIEW_PAUSE_BLIT, OnViewPauseBlit)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PAUSE_BLUR, OnUpdatePauseBlur)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PAUSE_SWARM, OnUpdatePauseSwarm)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PAUSE_BLIT, OnUpdatePauseBlit)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PAUSE_BLUR, OnUpdatePauseBlur)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PAUSE_SWARM, OnUpdatePauseSwarm)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_PAUSE_BLIT, OnUpdatePauseBlit)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_FPS, OnUpdateFPS)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_RESOLUTION, OnUpdateResolution)
	ON_COMMAND_RANGE(IDD_16BIT_MMXINTRINSICS, IDD_32BIT_GENERICCBLUR, OnImageFormats)
	ON_UPDATE_COMMAND_UI_RANGE(IDD_16BIT_MMXINTRINSICS, IDD_32BIT_GENERICCBLUR, OnUpdateImageFormats)
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

CChildView::CChildView()
{
	m_pSurface = NULL;
	m_dwTickStart = ::GetTickCount();
	m_nFrameCounter = 0;
	m_nFilterLoad = 0;
	m_nFilterSave = 0;
	m_bSizeChanged = false;
	m_bPauseBlur = false;
	m_bPauseSwarm = false;
	m_bPauseBlit = false;
	m_bTimerPopped = false;
	m_eSurf = eNone;
}

CChildView::~CChildView()
{
	delete m_pSurface;
}

/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnFileOpen()
{
	CImage image;
	CString strFilter;
	CString strAllFilePrompt;
	CSimpleArray<GUID> aguidFileTypes;
	HRESULT hResult;
	INT_PTR nResult;

	if (m_pSurface == NULL)
		return;
	VERIFY(strAllFilePrompt.LoadString(IDS_ALL_IMAGES));
	hResult = image.GetImporterFilterString(strFilter, aguidFileTypes, strAllFilePrompt);
	if(FAILED(hResult))	{
		CString fmt;
		fmt.Format(IDS_ERROR_GETEXPORTERFILTER, hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
		return;
	}

	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	dlg.m_ofn.nFilterIndex = m_nFilterLoad;

	nResult = dlg.DoModal();
	if(nResult != IDOK) {
		return;
	}

	m_nFilterLoad = dlg.m_ofn.nFilterIndex;
	hResult = image.Load(dlg.GetFileName());
	ASSERT(SUCCEEDED(hResult));
	if (SUCCEEDED(hResult)) {
		m_pSurface->Import(image);
		// Stop the weird effects
		m_bPauseBlur = true;
		m_bPauseSwarm = true;
	}
}

void CChildView::OnFileSave()
{
	CString strFilter;
	CSimpleArray<GUID> aguidFileTypes;
	CImage *pImage;
	CString fmt;
	HRESULT hResult;
	INT_PTR nResult;

	pImage = m_pSurface->GetImage();
	ASSERT(pImage != NULL);
	hResult = pImage->GetExporterFilterString( strFilter, aguidFileTypes );
	if(FAILED(hResult)) {
		fmt.Format(IDS_ERROR_GETEXPORTERFILTER, hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
		return;
	}

	CFileDialog dlg(FALSE, NULL, NULL, 
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, strFilter);
	dlg.m_ofn.nFilterIndex = m_nFilterSave;

	nResult = dlg.DoModal();
	if( nResult != IDOK ) {
		return;
	}
	m_nFilterSave = dlg.m_ofn.nFilterIndex;
	GUID guid = m_nFilterSave > 0 ? aguidFileTypes[m_nFilterSave-1] : GUID(GUID_NULL);
	CString strFileName = dlg.GetPathName();
	if (dlg.GetFileExt().IsEmpty()) {
		if (strFileName[strFileName.GetLength()-1] == '.') {
			strFileName = strFileName.Left(strFileName.GetLength()-1);
		}
		CString strExt;
		if (m_nFilterSave == 0) {
			strExt = _T(".jpg"); // default to JPEG
		}
		else {
			// Look up the first extension in the filters
			int nCount = (m_nFilterSave*2)-1;
			int nLeft = 0;
			while (nCount) {
				if (strFilter[nLeft++] == '|') {
					nCount--;
				}
			}
			ASSERT(nLeft < strFilter.GetLength());
			strExt = strFilter.Tokenize(_T(";|"), nLeft).MakeLower();
			strExt = ::PathFindExtension(strExt);
		}
		strFileName += strExt;
	}

	hResult = pImage->Save(strFileName, guid);
	if(FAILED(hResult)) {
		fmt.Format(IDS_ERROR_SAVE, hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
	}
}

void CChildView::OnImageFormats(UINT nID)
{
	ASSERT((nID >= IDD_16BIT_MMXINTRINSICS) && (nID <= IDD_32BIT_GENERICCBLUR));
	m_eSurf = ESurface(nID);
	CreateSurface();
}

void CChildView::OnViewPauseBlur()
{
	m_bPauseBlur = !m_bPauseBlur;
}

void CChildView::OnViewPauseSwarm()
{
	m_bPauseSwarm = !m_bPauseSwarm;
}

void CChildView::OnViewPauseBlit()
{
	m_bPauseBlit = !m_bPauseBlit;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// Do not call CWnd::OnPaint() for painting messages
	if (m_pSurface != NULL)
		m_pSurface->BlitBits();
}

BOOL CChildView::OnIdle(LONG /*lCount*/)
{
	BOOL bContinue = FALSE;
	if (m_pSurface == NULL)
		return(FALSE);
	
	// Debugging helper for blur
	// m_pSurface->Line(CPoint(160, 120), CPoint(160, 0), RGB(255, 128, 128));
	// m_pSurface->Line(CPoint(80, 60), CPoint(240, 60), RGB(128, 128, 255));

    if (::GetAsyncKeyState(VK_SHIFT) & 0x8000) {
        m_pSurface->RandomLine((int)Random() << 15 | Random());
		bContinue = TRUE;
    }
    if (::GetAsyncKeyState(VK_DELETE) & 0x8000) {
        m_pSurface->ClearBits();
		bContinue = TRUE;
    }
    if (::GetAsyncKeyState(VK_SPACE) & 0x8000) {
        m_pSurface->RandomBits();
		bContinue = TRUE;
    }
	if (::GetAsyncKeyState(VK_UP) & 0x8000) {
		m_pSurface->ShiftBits();
		bContinue = TRUE;
	}

	// The guts...
	if (!m_bPauseBlur) {
		m_pSurface->BlurBits();
		bContinue = TRUE;
	}

	if (!m_bPauseSwarm) {
		m_swarm.Tick();
		bContinue = TRUE;
	}

	if (bContinue) {
		m_nFrameCounter++;
		if (!m_bPauseBlit) {
			m_pSurface->BlitBits();
		}
	}
	::GdiFlush();
    return(bContinue);
}

BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// Add your message handler code here and/or call default
    if (nHitTest == HTCLIENT) {
        SetCursor(LoadCursor(NULL, IDC_CROSS));
        return(TRUE);
    }
	
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}

void CChildView::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
    if (m_hWnd && cx && cy) {
        TRACE("OnSize: width == %d, height == %d\n", cx, cy);

		// Initialize screen format
		// First time init with an hwnd
		if (m_eSurf == eNone) {
			CClientDC dc(this);
			int pixels;
			bool bWarnDepth = false;
			bool bWarnDebug = false;

			SetTimer(m_kTimerID, m_kTimerDelay, NULL);
			pixels = dc.GetDeviceCaps(BITSPIXEL) * dc.GetDeviceCaps(PLANES);
			switch (pixels) {
				case 16:
					m_eSurf = IsSSE2() ? e16BitSSE2Intrin :
						IsMMX() ? e16BitMMXIntrin : e16BitGeneric;
					break;
				case 24:
					m_eSurf =  IsSSE2() ? e24BitSSE2Intrin :
						IsMMX() ? e24BitMMXIntrin : e24BitGeneric;
					break;
				case 32:
					m_eSurf =  IsSSE2() ? e32BitSSE2Intrin :
						IsMMX() ? e32BitMMXIntrin : e32BitGeneric;
					break;
				default:
					bWarnDepth = true;
					m_eSurf =  IsSSE2() ? e32BitSSE2Intrin :
						IsMMX() ? e32BitMMXIntrin : e32BitGeneric;
					break;
			}
#ifdef _DEBUG
			bWarnDebug = true;
#endif
			if (bWarnDepth || bWarnDebug) {
				CString fmt;
				if (bWarnDepth) {
					fmt.LoadString(IDS_WARNING_BITDEPTH);
				}
				if (bWarnDepth && bWarnDebug) {
					fmt += "\n";
				}
				if (bWarnDebug) {
					CString temp;
					temp.LoadString(IDS_WARNING_DEBUG);
					fmt += temp;
				}
				::AfxMessageBox(fmt, MB_ICONINFORMATION);
			}

		}

		m_bSizeChanged = true;
		CreateSurface();
    }
}

void CChildView::CreateSurface()
{
	int nBits = 0;

	delete m_pSurface;
	m_pSurface = NULL;

	switch (m_eSurf) {
		case e16BitSSE2Intrin:
			nBits = 16;
			m_pSurface = new CSSE2Surface16Intrinsic();
			break;
		case e16BitMMXIntrin:
			nBits = 16;
			m_pSurface = new CMMXSurface16Intrinsic();
			break;
		case e16BitGeneric:
			nBits = 16;
			m_pSurface = new CSurface();
			break;
		case e24BitSSE2Intrin:
			nBits = 24;
			m_pSurface = new CSSE2Surface24Intrinsic();
			break;
		case e24BitMMXIntrin:
			nBits = 24;
			m_pSurface = new CMMXSurface24Intrinsic();
			break;
		case e24BitGeneric:
			nBits = 24;
			m_pSurface = new CSurface();
			break;
		case e32BitSSE2Intrin:
			nBits = 32;
			m_pSurface = new CSSE2Surface32Intrinsic();
			break;
		case e32BitMMXIntrin:
			nBits = 32;
			m_pSurface = new CMMXSurface32Intrinsic();
			break;
		case e32BitGeneric:
			nBits = 32;
			m_pSurface = new CSurface();
			break;
		default:
			ASSERT(FALSE);
			break;

	}
	ASSERT(m_pSurface != NULL);
	m_pSurface->Create(this, nBits);
    m_pSurface->ClearBits();

	CRect cRect;
	GetClientRect(&cRect);
	int numLeaders = max(2, (cRect.Width()*cRect.Height())>>16);
	int numLlamas = numLeaders*35;
	m_swarm.Initialize(m_pSurface, numLeaders, numLlamas, cRect.Size());
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	nIDEvent;
	ASSERT(nIDEvent == m_kTimerID);
	// This only exists to kick the UI handler for fps.
	m_bTimerPopped = true;
}

void CChildView::OnUpdateFPS(CCmdUI* pCmdUI)
{
	if (!m_bTimerPopped) // Only update on regular intervals
		return;

    DWORD dwStop = max(m_dwTickStart+1, ::GetTickCount());
    CString fmt;
    fmt.Format(_T("%d fps"), (m_nFrameCounter*1000L)/(dwStop-m_dwTickStart));

	m_nFrameCounter = 0;
	m_bTimerPopped = false;
    m_dwTickStart = dwStop;

	pCmdUI->SetText(fmt);
	pCmdUI->Enable(TRUE);
}

void CChildView::OnUpdatePauseBlur(CCmdUI* pCmdUI)
{
	if (pCmdUI->m_nID == ID_INDICATOR_PAUSE_BLUR) {
		pCmdUI->Enable(m_bPauseBlur ? FALSE : TRUE);
	}
	else {
		ASSERT(pCmdUI->m_nID == ID_VIEW_PAUSE_BLUR);
		pCmdUI->SetCheck(m_bPauseBlur ? 1 : 0);
		pCmdUI->Enable(TRUE);
	}
}

void CChildView::OnUpdatePauseSwarm(CCmdUI* pCmdUI)
{
	if (pCmdUI->m_nID == ID_INDICATOR_PAUSE_SWARM) {
		pCmdUI->Enable(m_bPauseSwarm ? FALSE : TRUE);
	}
	else {
		ASSERT(pCmdUI->m_nID == ID_VIEW_PAUSE_SWARM);
		pCmdUI->SetCheck(m_bPauseSwarm ? 1 : 0);
		pCmdUI->Enable(TRUE);
	}
}

void CChildView::OnUpdatePauseBlit(CCmdUI* pCmdUI)
{
	if (pCmdUI->m_nID == ID_INDICATOR_PAUSE_BLIT) {
		pCmdUI->Enable(m_bPauseBlit ? FALSE : TRUE);
	}
	else {
		ASSERT(pCmdUI->m_nID == ID_VIEW_PAUSE_BLIT);
		pCmdUI->SetCheck(m_bPauseBlit ? 1 : 0);
		pCmdUI->Enable(TRUE);
	}
}

void CChildView::OnUpdateResolution(CCmdUI* pCmdUI)
{
	if (m_bSizeChanged) {
		CString str;
		str.Format(_T("%dx%d"), m_pSurface->GetVisibleWidth(), m_pSurface->GetVisibleHeight());
		pCmdUI->SetText(str);
		m_bSizeChanged = false;
	}
	pCmdUI->Enable(TRUE);
}

void CChildView::OnUpdateImageFormats(CCmdUI* pCmdUI)
{
	BOOL bEnable = TRUE;

	switch (pCmdUI->m_nID) {
		case IDD_16BIT_MMXINTRINSICS:
		case IDD_24BIT_MMXINTRINSICS:
		case IDD_32BIT_MMXINTRINSICS:
			bEnable = IsMMX();
			break;
		case IDD_16BIT_SSE2INTRINSICS:
		case IDD_24BIT_SSE2INTRINSICS:
		case IDD_32BIT_SSE2INTRINSICS:
			bEnable = IsSSE2();
			break;
		default:
			break;
	}
	if (ESurface(pCmdUI->m_nID) == m_eSurf)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);

	pCmdUI->Enable(bEnable);
}

BOOL CChildView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return(TRUE);
}

void CChildView::OnDestroy(void)
{
	CWnd::OnDestroy();
	KillTimer(m_kTimerID);
}
