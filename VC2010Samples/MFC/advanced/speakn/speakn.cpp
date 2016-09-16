// speakn.cpp : Defines the class behaviors for the SpeakN application.
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

#include "speakn.h"
#include <mmsystem.h>

/////////////////////////////////////////////////////////////////////////////
// Sound helpers

static void PlaySound(LPCTSTR lpszSound)
{
	HRSRC hRes; // resource handle to wave file
	HGLOBAL hData;
	BOOL bOk = FALSE;
	if ((hRes = ::FindResource(AfxGetResourceHandle(), lpszSound,
	  _T("sound"))) != NULL &&
	  (hData = ::LoadResource(AfxGetResourceHandle(), hRes)) != NULL)
	{
		// found the resource, play it
		bOk = sndPlaySound((LPCTSTR)::LockResource(hData),
			SND_MEMORY|SND_SYNC|SND_NODEFAULT);
		FreeResource(hData);
	}
	if (!bOk)
	{
		static BOOL bReported = FALSE;
		if (!bReported)
		{
			AfxMessageBox(IDS_CANNOT_PLAY_SOUND);
			bReported = TRUE;       // once please
		}
	}
}

inline static void PlaySound(UINT nIDS)
	{ PlaySound(MAKEINTRESOURCE(nIDS)); }

/////////////////////////////////////////////////////////////////////////////
// CSpeakNDlg

CSpeakNDlg::CSpeakNDlg(BOOL bNoPen)
	: CDialog(bNoPen ? IDD_NOPENDIALOG : CSpeakNDlg::IDD)
{
	//{{AFX_DATA_INIT(CSpeakNDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_bNoPen = bNoPen;
	m_lpszNextQuestion = NULL;
	m_bNoAnswerCheck = FALSE;
}

BEGIN_MESSAGE_MAP(CSpeakNDlg, CDialog)
	//{{AFX_MSG_MAP(CSpeakNDlg)
	ON_COMMAND(IDC_REPLAY_SOUND, OnReplaySound)
	ON_COMMAND(IDC_GIVE_UP, OnGiveUp)
	ON_COMMAND(IDC_PICTURE, OnReplaySound)
	ON_EN_CHANGE(IDC_INPUT_EDIT, OnUpdateStatus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSpeakNDlg::LoadLesson(LPCTSTR lpLessonName)
{
	// load lesson from resource
	HRSRC hRes; // resource handle to lesson data
	HGLOBAL hData;
	if ((hRes = ::FindResource(AfxGetResourceHandle(), lpLessonName,
	  _T("lesson"))) == NULL ||
	  (hData = ::LoadResource(AfxGetResourceHandle(), hRes)) == NULL)
		return FALSE;
	m_lpszNextQuestion = (LPCSTR)::LockResource(hData);
	return TRUE;
}

void CSpeakNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpeakNDlg)
	DDX_Control(pDX, IDOK, m_buttonNext);
	//}}AFX_DATA_MAP
}


BOOL CSpeakNDlg::OnInitDialog()
{
	UpdateData(FALSE); // call DoDataExchange to initialize m_buttonNext
	m_buttonNext.EnableWindow(FALSE);

	ASSERT(m_targetWord.IsEmpty());     // not started yet

	// set the font of the prompt text to something bigger
	LOGFONT logfont;
	memset(&logfont, 0, sizeof(logfont));
	logfont.lfHeight = 40;
	logfont.lfWeight = FW_BOLD;
	CString szFont;
	szFont.LoadString(IDS_FONT_NAME);           // TrueType font
	_tcscpy_s(logfont.lfFaceName, LF_FACESIZE, szFont);
	VERIFY(m_biggerFont.CreateFontIndirect(&logfont));
	PromptText().SetFont(&m_biggerFont);
	InputEdit().SetFont(&m_biggerFont);

	// load the bitmaps for bitmap buttons
	VERIFY(m_replayButton.AutoLoad(IDC_REPLAY_SOUND, this));
	InputEdit().ShowWindow(FALSE);      // start with input disabled

	// load initial picture
	VERIFY(m_pictureButton.SubclassDlgItem(IDC_PICTURE, this));
	VERIFY(m_pictureButton.LoadBitmaps(_T("intro"), NULL, NULL));

	// Make the dialog visible, and update
	ShowWindow(TRUE);       // SHOW_OPENWINDOW
	UpdateWindow();

	PlaySound(IDSOUND_WELCOME);
	AdvanceLesson();
	return FALSE;       // focus already set
}

void CSpeakNDlg::OnReplaySound()
{
	InputEdit().SetFocus();
	PlaySound(m_targetRes);
}

void CSpeakNDlg::OnOK()
{
	// check results
	CString result;
	InputEdit().GetWindowText(result);
	if (result != m_targetWord)
	{
		PlaySound(IDSOUND_INCORRECT);
		AfxMessageBox(IDS_TRY_AGAIN);
		return;
	}
	PlaySound(IDSOUND_CORRECT);
	AdvanceLesson();
}

void CSpeakNDlg::OnGiveUp()
{
	PlaySound(IDSOUND_GIVEUP);
	SetAnswerText(m_targetWord);        // show answer
	OnReplaySound();
	AdvanceLesson();
}

void CSpeakNDlg::SetAnswerText(LPCTSTR lpsz)
{
	// setting the window text for an edit control will cause EN_CHANGE
	//  control notifications, so we lock them out while setting the
	//  text programmatically
	ASSERT(!m_bNoAnswerCheck);
	m_bNoAnswerCheck = TRUE;
	InputEdit().SetWindowText(lpsz);
	m_bNoAnswerCheck = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Advancing to the next lesson

void CSpeakNDlg::AdvanceLesson()
{
	if (*m_lpszNextQuestion == '\0')
	{
		// out of questions
		PlaySound(IDSOUND_GOODBYE);
		EndDialog(IDOK);
		return;
	}

// The lesson resource consists of several pairs of words (that the user guesses)
// and bitmap resource names.  The words and resource names are stored in the
// resource as ANSI text.  This text must be converted to UNICODE.

#ifdef _UNICODE
	TCHAR szT[20];
	int nLen;
	nLen = strlen(m_lpszNextQuestion);
	mbstowcs(szT, m_lpszNextQuestion, nLen);
	szT[nLen] = 0;
	m_targetWord = szT;
	m_lpszNextQuestion += nLen + 1;

	nLen = strlen(m_lpszNextQuestion);
	mbstowcs(szT, m_lpszNextQuestion, nLen);
	szT[nLen] = 0;
	m_targetRes = szT;
	m_lpszNextQuestion += nLen + 1;
#else
	m_targetWord = m_lpszNextQuestion;
	m_lpszNextQuestion += m_targetWord.GetLength() + 1;

	m_targetRes = m_lpszNextQuestion;
	m_lpszNextQuestion += m_targetRes.GetLength() + 1;
#endif

	m_targetWord.MakeUpper();
	m_targetRes.MakeUpper();

	PlaySound(IDSOUND_QUESTION);

	// draw the picture (bitmap with the same name as the target)
	if (!m_pictureButton.LoadBitmaps(m_targetRes))
	{
		AfxMessageBox(IDS_PICTURE_UNAVAILABLE);
		VERIFY(m_pictureButton.LoadBitmaps(_T("intro"), NULL, NULL));
			// go back to the initial bitmap
	}
	m_pictureButton.Invalidate(TRUE);

	SetAnswerText(_T(""));
	InputEdit().ShowWindow(TRUE);

	OnUpdateStatus();               // set appropriate face
	OnReplaySound();                // ask question

	if (*m_lpszNextQuestion == '\0')
	{
		CString strDone;
		strDone.LoadString(IDS_DONE);
		m_buttonNext.SetWindowText(strDone);
	}
}

/////////////////////////////////////////////////////////////////////////////
// Happy face status indicator

void CSpeakNDlg::OnUpdateStatus()
{
	CString result;
	InputEdit().GetWindowText(result);

	UINT nIDI = IDI_FACE_NEUTRAL;       // default
	if (result == m_targetWord)
	{
		m_buttonNext.EnableWindow();
		nIDI = IDI_FACE_HAPPIER;        // exact match
	}
	else
	{
		m_buttonNext.EnableWindow(FALSE);
		if (result.IsEmpty())
			nIDI = IDI_FACE_NEUTRAL;        // not started yet
		else
		{
			nIDI = (_tcsncmp(m_targetWord, result, _tcslen(result)) == 0?
				IDI_FACE_HAPPY : IDI_FACE_SAD);
		}
	}

	HICON hNew = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(nIDI));
	ASSERT(hNew != NULL);
	::DestroyIcon(StatusFace().SetIcon(hNew));
	UpdateWindow();                 // draw everything now

	if (m_bNoAnswerCheck)
		return;     // don't update

	if (nIDI == IDI_FACE_HAPPIER)
	{
		// exact match - automatic advance
		OnReplaySound();
		PlaySound(IDSOUND_CORRECT);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSpeakNApp

BOOL CSpeakNApp::InitInstance()
{
	BOOL bNoPen = TRUE;  // no pen-aware controls

	// Creates a simple dialog and do it
	CSpeakNDlg mainDlg(bNoPen);
	if (!mainDlg.LoadLesson(_T("SAMPLE1")))
		return FALSE;
	m_pMainWnd = &mainDlg;
	mainDlg.DoModal();

	// that's all, quit app
	::PostQuitMessage(0);
	return TRUE;
}

CSpeakNApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
