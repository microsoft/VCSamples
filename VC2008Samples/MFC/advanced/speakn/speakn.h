// speakn.h : Declares the class interfaces for the SpeakN application.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "resource.h"       // resource IDs

/////////////////////////////////////////////////////////////////////////////
// CSpeakNDlg:
//   The main user interface to this application is just one big dialog

class CSpeakNDlg : public CDialog
{
// Constructors
public:
	CSpeakNDlg(BOOL bNoPen);
	BOOL LoadLesson(LPCTSTR lpLessonName);

	//{{AFX_DATA(CSpeakNDlg)
	enum { IDD = IDD_PENDIALOG };
	CButton m_buttonNext;
	//}}AFX_DATA

// Operations
	void        AdvanceLesson();

// Attributes (the current question/lesson)
	// current question (from resource)
	CString         m_targetWord;           // target word (upper case)
	CString         m_targetRes;

	// resource containing a list of target words and associated bitmap names, in ANSI
	LPCSTR         m_lpszNextQuestion; // empty string => done

// Implementation
protected:
	void DoDataExchange(CDataExchange* pDX);

	BOOL m_bNoPen;      // TRUE => no PenWindows (run less functional)
	BOOL m_bNoAnswerCheck;  // TRUE => disable test for answer

	// special controls
	CFont           m_biggerFont;
	CBitmapButton   m_pictureButton; // main bitmap done as a special button
	CBitmapButton   m_replayButton; // bitmap button for replay sound

	// normal Windows controls
	CStatic&    StatusFace()    // face which smiles or frowns
					{ return *(CStatic*)GetDlgItem(IDC_STATUS_FACE); }
	CStatic&    PromptText()    // prompt area
					{ return *(CStatic*)GetDlgItem(IDC_PROMPT_TEXT); }

	void        SetAnswerText(LPCTSTR lpsz);
	CEdit&      InputEdit()     // user input for answer text
								//  (a normal Edit or a Pen Boxed Edit)
					{ return *(CEdit*)GetDlgItem(IDC_INPUT_EDIT); }

	// message handlers
	//{{AFX_MSG(CSpeakNDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnReplaySound();
	afx_msg void OnUpdateStatus();
	virtual void OnOK();        // Guess
	virtual void OnGiveUp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CSpeakNApp:

class CSpeakNApp : public CWinApp
{
public:
	BOOL InitInstance();
};

/////////////////////////////////////////////////////////////////////////////
