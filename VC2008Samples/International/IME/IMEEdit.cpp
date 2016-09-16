/******************************************************************************\
*	IMEEdit.cpp : implementation file
*
*	This is a part of the Microsoft Source Code Samples. 
*	Copyright (c) Microsoft Corporation.
*	All rights reserved. 
*
*	This source code is only intended as a supplement to 
*	Microsoft Development Tools and/or WinHelp documentation.
*	See these sources for detailed information regarding the 
*	Microsoft samples programs.
\******************************************************************************/

#include "stdafx.h"
#include "imm.h"
#include "IMEEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Declare enum type Languages
enum LANGFLAG           
{
	DEFAULT,				
	TRADITIONAL_CHINESE,	
	JAPANESE,
	KOREAN,
	SIMPLIFIED_CHINESE
} LangFlag;  

// Define code pages 
int nCodePage[5] = {
	0,		// DEFAULT 
	950,		// TRADITIONAL CHINESE
	932,		// JAPANESE
	949,		// KOREAN 
	936			// SIMPLIFIED CHINESE
};

// Define charset
BYTE nCharSet[5] = {
	DEFAULT_CHARSET,		// Default 
	CHINESEBIG5_CHARSET,	// TRADITIONAL CHINESE
	SHIFTJIS_CHARSET,		// JAPANESE
	HANGUL_CHARSET,			// KOREAN
	GB2312_CHARSET			// SIMPLIFIED CHINESE
};

// Define Default font
char szDefaultFontName[5][19] = {
	"\x54\x00\x61\x00\x68\x00\x6F\x00\x6D\x00\x61\x00\x00\x00",					// Default font
	"\xB0\x65\x30\x7D\x0E\x66\xD4\x9A\x00\x00",									// TRADITIONAL_CHINESE font
	"\x2D\xFF\x33\xFF\x20\x00\x30\xFF\xB4\x30\xB7\x30\xC3\x30\xAF\x30\x00\x00",	// JAPANESE font
	"\x74\xAD\xBC\xB9\x00\x00",													// KOREAN font
	"\xB0\x65\x8B\x5B\x53\x4F\x00\x00"											// SIMPLIFIED_CHINESE font
};

TCHAR szEnglishFontName[5][11] = {
	_T("Tahoma"),		_T("MingLiU"),		_T("MS PGothic"), 
	_T("Gulim"),		_T("NSimSun")};

/////////////////////////////////////////////////////////////////////////////
// CIMEEdit

CIMEEdit::CIMEEdit()
{
	OSVERSIONINFO osVI;

	// Initialize buffer position
	m_xEndPos = m_xInsertPos = m_xCaretPos = 0;

	// Initialize buffer
	memset(m_szBuffer, 0, WCHARSIZE * (BUFFERSIZE + 1));

	// Initialize member variables
	m_fStat = FALSE;				// Do not show dotted underline
	m_fShowInvert = FALSE;			// Do not convert current composition string
	m_nComSize = 0;					// Clear variable for composition string size in Byte
	m_nCharSet =  DEFAULT_CHARSET;		
	m_hFont = NULL;		
	m_fIsNT = FALSE;
	m_fIsXP = FALSE;

	// Check System version 
	ZeroMemory( &osVI, sizeof( OSVERSIONINFO ) );	// Initialize the OSVERSIONINFO structure.
	osVI.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );    

	if (GetVersionEx( &osVI ))		// Get OS version Information
	{
		if( osVI.dwPlatformId == VER_PLATFORM_WIN32_NT )
		{
			m_fIsNT = TRUE;
	
			// Check the minor version.
			if(osVI.dwMinorVersion) 
				m_fIsXP = TRUE;		// Windows XP or higher version
		}
	}
	else	// if GetVersionEx function failed, try again with other function
	{
		if (GetVersion() < 0x80000000)
			m_fIsNT = TRUE;
	}
}

CIMEEdit::~CIMEEdit()
{
	if (m_hFont)
		DeleteObject(m_hFont);
}

BEGIN_MESSAGE_MAP(CIMEEdit, CEdit)
	//{{AFX_MSG_MAP(CIMEEdit)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIMEEdit message handlers

void CIMEEdit::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	TEXTMETRIC	tm;
	int			nXStart, nXEnd;
	CRect		cRect;
	HFONT		pOldFont = (HFONT)SelectObject(dc, m_hFont);
	CPen		*pPen, *pOldPen;
	wchar_t		szTempStr[BUFFERSIZE+1];
	RECT		rcBounds;

	HideCaret();

	// Fill background with white color
	GetClientRect(&rcBounds);
	dc.FillRect(&rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));

	// show text in buffer
	TextOutW(dc, X_INIT, Y_INIT, m_szBuffer, (int)wcslen(m_szBuffer));

	dc.GetTextMetrics(&tm);
	// Draw dotted line under composition string
	if ((m_fStat) && (m_dwProperty & IME_PROP_AT_CARET) && (m_nLanguage != KOREAN))
	{
		// Calculate start position of composition string and move pen to start position
		memcpy(szTempStr, m_szBuffer, WCHARSIZE * m_xInsertPos);	 
		szTempStr[m_xInsertPos] = L'\0';
		nXStart = X_INIT + GetWidthOfString(szTempStr);
		dc.MoveTo(nXStart, Y_INIT + tm.tmHeight);

		// Calculate end position of composition string and draw dotted line
		m_szComStr[m_nComSize / WCHARSIZE] = L'\0';

		if (m_nLanguage == JAPANESE)
		{
			for (int i = 0; ; i++)
			{
				if (m_dwCompCls[i] == m_nComAttrSize)
					break;
				memcpy(szTempStr, &m_szComStr[m_dwCompCls[i]], WCHARSIZE * (m_dwCompCls[i+1] - m_dwCompCls[i]));	 
				szTempStr[m_dwCompCls[i+1] - m_dwCompCls[i]] = L'\0';
				nXEnd = nXStart + GetWidthOfString(szTempStr);
				
				if (m_bComAttr[m_dwCompCls[i]] == 0x00)
					pPen = new CPen(PS_DOT, 1, RGB(0, 0, 0));	// For input characters
				else if (m_bComAttr[m_dwCompCls[i]] == 0x01)
					pPen = new CPen(PS_SOLID, 2, RGB(0, 0, 0));	// For editable phrase
				else 
					pPen = new CPen(PS_SOLID, 1, RGB(0, 0, 0));	// For converted characters

				pOldPen = dc.SelectObject(pPen);
				dc.LineTo(nXEnd - 1, Y_INIT + tm.tmHeight);
				dc.MoveTo(nXEnd + 1, Y_INIT + tm.tmHeight);
				dc.SelectObject(pOldPen);
				delete pPen;
				nXStart = nXEnd;
			}
		}
		else
		{
			nXEnd = nXStart + GetWidthOfString(m_szComStr);
			pPen = new CPen(PS_DOT, 1, RGB(0, 0, 0));
			pOldPen = dc.SelectObject(pPen);
			dc.LineTo(nXEnd, Y_INIT + tm.tmHeight);
			dc.SelectObject(pOldPen);
			delete pPen;
		}
	}

	// Invert current composition string (TRADITIONAL CHINESE and SIMPLIFIED CHINESE)
	if (m_fShowInvert)
	{
		// Calculate start position of invert string
		errno_t err;
		err = memcpy_s(szTempStr, sizeof(szTempStr) - WCHARSIZE, m_szBuffer, WCHARSIZE * m_nInvertStart);
		ASSERT(!err);
		szTempStr[m_nInvertStart] = L'\0';
		cRect.top = Y_INIT;
		cRect.left = X_INIT + GetWidthOfString(szTempStr);

		// Calculate end position of invert string
		cRect.bottom = cRect.top + tm.tmHeight;
		err = memcpy_s(szTempStr, sizeof(szTempStr) - WCHARSIZE, &m_szBuffer[m_nInvertStart], WCHARSIZE * (m_nInvertEnd - m_nInvertStart));	 
		ASSERT(!err);
		szTempStr[m_nInvertEnd - m_nInvertStart] = L'\0';
		cRect.right = cRect.left + GetWidthOfString(szTempStr);

		dc.InvertRect(cRect);  
	}

	ShowCaret();
	SelectObject(dc, pOldFont);
}

void CIMEEdit::OnSetFocus(CWnd*) 
{
	CreateSolidCaret(1,FONT_WIDTH);		

	// Set Caret position
	ShowCaretOnView();	

	ShowCaret();

}

void CIMEEdit::OnKillFocus(CWnd*) 
{
	HIMC	hIMC;
	
	HideCaret();

	// Delete Ghost Caret
	Invalidate();

	// If composition is not finished, complete the composition string
	if ((m_fStat) && (m_nLanguage != KOREAN))
	{
		hIMC = ImmGetContext(this->m_hWnd);
		if (hIMC) 
		{
			ImmNotifyIME(hIMC, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
			ImmReleaseContext(this->m_hWnd,hIMC);
		}
	}	
}

/*****************************************************************************\
* Function: ShowCaretOnView
*
* Calculate caret position and re-display Caret
\*****************************************************************************/
void CIMEEdit::ShowCaretOnView()
{
	wchar_t *szTmpStr = new(wchar_t[m_xCaretPos + 1]);
	errno_t err;

	HideCaret();

	// Calculate position of caret and set caret position
	err = memcpy_s(szTmpStr, WCHARSIZE * m_xCaretPos, m_szBuffer, WCHARSIZE * (m_xCaretPos));
	ASSERT(!err);
	szTmpStr[m_xCaretPos] = L'\0';
	SetCaretPos(CPoint(X_INIT + GetWidthOfString(szTmpStr), Y_INIT));
	ShowCaret();
	
	// If IME property does not have IME_PROP_AT_CARET, change the position of
	// composition window
	if (!(m_dwProperty & IME_PROP_AT_CARET) )
		SetCompositionWindowPos();

	delete [] szTmpStr;
}

/*****************************************************************************\
* Function: GetWidthOfString
*
* Calculate string width in pixel 
*
* Arguments:
*	LPCTSTR szStr - string 
\*****************************************************************************/
int CIMEEdit::GetWidthOfString(wchar_t *szStr)
{
	SIZE		Size;
	CClientDC	dc(this);
	HFONT		pOld = (HFONT)SelectObject(dc, m_hFont);

	GetTextExtentPoint32W(dc, szStr, (int)wcslen(szStr), &Size);

	SelectObject(dc, pOld);

	return Size.cx;
}

/*****************************************************************************\
* Function: OnImeStartComposition
*
* Receive WM_IME_STARTCOMPOSITION message and start composition
*
* Arguments:
*	WPARAM wParam - not used
*	LPARAM lParam - not used
\*****************************************************************************/
void CIMEEdit::OnImeStartComposition(WPARAM, LPARAM)
{
	// Check buffer. If full, clear buffer 
	if (m_xEndPos >= (BUFFERSIZE-1))	// Check buffer 
		ClearBuffer();

	// If Korean char set, change the caret 
	if (m_nLanguage == KOREAN)		
	{
		CreateSolidCaret(FONT_WIDTH, FONT_HEIGHT);	// Create wide Caret
		ShowCaret();
	}

	// Backup string buffer 
	memcpy(m_szBackup, m_szBuffer, WCHARSIZE * (BUFFERSIZE+1));
}

/*****************************************************************************\
* Function: OnImeStartComposition
*
* Receive WM_IME_COMPOSITION message and composition string
*
* Arguments:
*	WPARAM wParam - DBCS character representing the latest change to the 
*					composition string
*	LPARAM lParam - Change flag
\*****************************************************************************/
BOOL CIMEEdit::OnImeComposition(WPARAM, LPARAM lParam)
{
	HIMC	hIMC;
	int		i, nTmpInc;

	hIMC = ImmGetContext(this->m_hWnd);
	if (hIMC == NULL) 
		return TRUE;

	// Restore string buffer
	if (m_fStat)
		memcpy(m_szBuffer, m_szBackup, WCHARSIZE * (BUFFERSIZE+1));

	if (lParam & GCS_RESULTSTR)
	{
		m_fShowInvert = FALSE;

		// Get result string
		m_nComSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, (LPVOID)m_szComStr, WCHARSIZE * (BUFFERSIZE+1));

		if (m_nComSize > 0)
		{
			// Insert composition string to string buffer
			nTmpInc = InsertCompStr();

			// Move insert/caret position and increase end position
			memcpy(m_szBackup, m_szBuffer, WCHARSIZE * (BUFFERSIZE+1));
			m_xEndPos += nTmpInc;
			m_xInsertPos += nTmpInc;
			m_xCaretPos = m_xInsertPos;
		}
	}
	else if (lParam & GCS_COMPSTR)
	{
		// if IME property does not have IME_PROP_AT_CARET, ignore level 3 feature
		if (!(m_dwProperty & IME_PROP_AT_CARET) )
			return FALSE;

		// Get composition string
		m_nComSize = ImmGetCompositionStringW(hIMC, GCS_COMPSTR, (LPVOID)m_szComStr, WCHARSIZE * (BUFFERSIZE+1));
		if (m_nLanguage != KOREAN)
		{
			// Get composition attribute and cursor position in composition string
			if (lParam & GCS_COMPATTR)
				m_nComAttrSize = ImmGetCompositionStringW(hIMC, GCS_COMPATTR, m_bComAttr, sizeof(m_bComAttr));

			if (lParam & GCS_CURSORPOS)
				m_nComCursorPos = ImmGetCompositionStringW(hIMC, GCS_CURSORPOS, NULL, 0);

			if (lParam & GCS_COMPCLAUSE)
				ImmGetCompositionStringW(hIMC, GCS_COMPCLAUSE, m_dwCompCls,sizeof(m_dwCompCls));
			
			if ((m_nLanguage == TRADITIONAL_CHINESE) || (m_nLanguage == SIMPLIFIED_CHINESE && !m_fIsXP))
			{
				m_fShowInvert = TRUE;
				nTmpInc = 0;
				for (i = m_nComCursorPos; i < (int)m_nComAttrSize; i++)
				{
					if (m_bComAttr[i] == 1)
						nTmpInc++;
					else
						break;
				}
				m_nInvertStart = m_xInsertPos + m_nComCursorPos;
				m_nInvertEnd = m_nInvertStart + nTmpInc;
			}
 		}
		if (m_nComSize > 0)
		{
			// Insert composition string to string buffer
			nTmpInc = InsertCompStr();
		
			// Move caret position
			if (m_nLanguage != KOREAN)
			{
				if (m_nLanguage == JAPANESE)
					m_xCaretPos = m_xInsertPos + m_nComSize / WCHARSIZE;
				else
					m_xCaretPos = m_xInsertPos + m_nComCursorPos;
			}
		}
	}
	else
	{
		// No composition string
		m_nComSize = 0;
	}

	ImmReleaseContext(this->m_hWnd, hIMC);

	ShowCaretOnView();
	Invalidate();	
	return TRUE;
}

/*****************************************************************************\
* Function: OnImeEndComposition
*
* Receive WM_IME_ENDCOMPOSITION message and finish composition
*
* Arguments:
*	WPARAM wParam - not used 
*	LPARAM lParam - not used
\*****************************************************************************/
void CIMEEdit::OnImeEndComposition(WPARAM, LPARAM)
{
	// Turn off invert flag
	m_fShowInvert = FALSE;

	// If Korean char set, change the caret to normal style
	if (m_nLanguage == KOREAN)		
		CreateSolidCaret(1,FONT_WIDTH);		

	ShowCaret();
}

/*****************************************************************************\
* Function: InsertCompStr
*
* Insert composition string to string buffer
*
* Arguments:
*	WPARAM wParam - not used 
*	LPARAM lParam - not used
*
* return value:
*	Size of composition string in TCHAR 
\*****************************************************************************/
int CIMEEdit::InsertCompStr()
{
	HIMC	hIMC;
	int		nTmpPos, nTmpInc;
	wchar_t	szTmpStr[BUFFERSIZE+1];
	errno_t err;

	// Backup sub-string after insert position 
	nTmpPos = m_xEndPos - m_xInsertPos;
	err = memcpy_s(szTmpStr, sizeof(szTmpStr) - WCHARSIZE, &m_szBuffer[m_xInsertPos], WCHARSIZE * nTmpPos);
	ASSERT(!err);
	szTmpStr[nTmpPos] = L'\0';

	// Check buffer overflow
	if ((m_nComSize % 2) != 0)
		m_nComSize++;
	nTmpInc = m_nComSize / WCHARSIZE;

	if ((m_xEndPos + nTmpInc) < 0)
		return 0;

	if ((m_xEndPos + nTmpInc) >= BUFFERSIZE)
	{
		if (m_xInsertPos > 0)
		{
			// Delete sub-string before insert position
			memcpy(m_szBackup, szTmpStr, WCHARSIZE * (BUFFERSIZE+1));
			ClearBuffer();
			m_xEndPos = nTmpPos;
		}
		else
		{
			// Cancel composition string 
			hIMC = ImmGetContext(this->m_hWnd);
			if (hIMC) 
			{
				ImmNotifyIME(hIMC, NI_COMPOSITIONSTR, CPS_CANCEL, 0);
				ImmReleaseContext(this->m_hWnd,hIMC);
				ClearBuffer();
			}
		}
	}

	// Copy composition string to string buffer
	err = memcpy_s(&m_szBuffer[m_xInsertPos], sizeof(m_szBuffer) - (m_xInsertPos+1)*WCHARSIZE, m_szComStr, m_nComSize);
	ASSERT(!err);

	// Restore sub-string after insert position
	err = memcpy_s(&m_szBuffer[m_xInsertPos+nTmpInc], sizeof(m_szBuffer) - (m_xInsertPos+nTmpInc+1)*WCHARSIZE, szTmpStr, WCHARSIZE * nTmpPos);
	ASSERT(!err);
	m_szBuffer[m_xEndPos + nTmpInc] = L'\0';

	return nTmpInc;
}

void CIMEEdit::OnChar(UINT nChar, UINT, UINT) 
{
	int		nTmpDec;
	wchar_t wChar, szTmpStr[BUFFERSIZE+1];
	errno_t err;

	// Check current stat
	if (m_fStat)
		return;

	switch(nChar)
	{
		// Return key
		case _T('\r') :	
				// Delete sub-string before insert position
				err = memcpy_s(m_szBuffer, sizeof(m_szBuffer) - WCHARSIZE, &m_szBuffer[m_xInsertPos], WCHARSIZE * (m_xEndPos - m_xInsertPos));
				ASSERT(!err);
				m_xEndPos = m_xEndPos - m_xInsertPos;
				m_xInsertPos = m_xCaretPos = 0;
				m_szBuffer[m_xEndPos] = L'\0';
				break;

		// Back space key
		case _T('\b') :		
				// Delete one char
				if(m_xInsertPos == 0) break;
				nTmpDec = GetCombinedCharLength(m_xInsertPos-1);
				err = memcpy_s(&m_szBuffer[m_xInsertPos-nTmpDec], sizeof(m_szBuffer) -(m_xInsertPos-nTmpDec+1)*WCHARSIZE, &m_szBuffer[m_xInsertPos], WCHARSIZE * (m_xEndPos - m_xInsertPos));
				ASSERT(!err);
				m_xEndPos -= nTmpDec;
				m_xInsertPos -= nTmpDec;
				m_xCaretPos -= nTmpDec;
				m_szBuffer[m_xEndPos] = L'\0';
				break;

		default :

				if (nChar < TCHAR(0x20))
					break;
#ifdef _UNICODE
				wChar = nChar;
#else
				MultiByteToWideChar(m_nCodePage, 0, (char *)&nChar, 1, &wChar, 2);
#endif
				// Check buffer overflow
				if(m_xEndPos > (BUFFERSIZE-1) )	
					ClearBuffer();

				// insert char to string buffer
				err = memcpy_s(szTmpStr, sizeof(szTmpStr) - WCHARSIZE, &m_szBuffer[m_xInsertPos], WCHARSIZE * (m_xEndPos - m_xInsertPos));
				ASSERT(!err);
				m_szBuffer[m_xInsertPos] = wChar;
				err = memcpy_s(&m_szBuffer[m_xInsertPos+1], sizeof(m_szBuffer) - (m_xInsertPos+1+1)*WCHARSIZE,  szTmpStr, WCHARSIZE * (m_xEndPos - m_xInsertPos));
				ASSERT(!err);
				m_xEndPos++;
				m_xInsertPos++;
				m_xCaretPos++;
				//if(m_xEndPos > (BUFFERSIZE-1) ) above ensures that there will be no buffer overrun in the following line
				#pragma warning (suppress: 6386) 
				m_szBuffer[m_xEndPos] = L'\0';
				break;
	}

	ShowCaretOnView();
	Invalidate();

}

void CIMEEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	int		nTmpDec;
	errno_t err;

	// Do not accept char during composition if IME property does not have IME_PROP_AT_CARET
	if (!(m_dwProperty & IME_PROP_AT_CARET) && m_fStat)
		return;

	switch(nChar)
	{
		// Left arrow key
		case VK_LEFT:
			if(m_xInsertPos == 0) 
				break;
			m_xInsertPos -= GetCombinedCharLength(m_xInsertPos-1);
			m_xCaretPos = m_xInsertPos;
			ShowCaretOnView();
			break;

		// Right arrow key
		case VK_RIGHT:
			if(m_xInsertPos == m_xEndPos) break;
			m_xInsertPos +=  GetCombinedCharLength(m_xInsertPos);
			m_xCaretPos =  m_xInsertPos;
			ShowCaretOnView();
			break;

		// Delete key
		case VK_DELETE:
			if ((m_xInsertPos == m_xEndPos) || (m_xEndPos > BUFFERSIZE)) break;
			nTmpDec = GetCombinedCharLength(m_xInsertPos);
			err = memcpy_s(&m_szBuffer[m_xInsertPos], sizeof(m_szBuffer) - (m_xInsertPos+1)*WCHARSIZE, &m_szBuffer[m_xInsertPos+nTmpDec], WCHARSIZE * (m_xEndPos - m_xInsertPos - nTmpDec));
			ASSERT(!err);
			m_xEndPos -= nTmpDec;
			m_szBuffer[m_xEndPos] = L'\0';
			Invalidate();
			break;

		// Home key
		case VK_HOME:
			if (m_xInsertPos == 0) break;
			m_xInsertPos = m_xCaretPos = 0;
			ShowCaretOnView();
			break;

		// End key
		case VK_END:
			if (m_xInsertPos == m_xEndPos) break;
			m_xInsertPos = m_xCaretPos = m_xEndPos;
			ShowCaretOnView();
			break;
	}
	
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}


/*****************************************************************************\
* Function: SetFont
*
* Receive WM_INPUTLANGCHANGE message from IME window
* 
* This sample determines the font and code page used for Ansi-Unicode conversion
* by the keyboard layout so that you can try four different IMEs for all East 
* Asian languages without changing font nor codepage. It's not a requirement for 
* support of IME Level 3
*
* Arguments:
*	HKL  hKeyboardLayout - Specifies the character set of the new keyboard layout
*	wchar_t *szSelectedFont - Font name. 
\*****************************************************************************/
void CIMEEdit::SetFont(HKL  hKeyboardLayout, LPCTSTR szSelectedFont)
{
	if (szSelectedFont)		
	{
		// Apply selected font 
#ifdef _UNICODE
		wcscpy_s(m_szWFontName, wcslen(szSelectedFont)+1, szSelectedFont);
		WideCharToMultiByte(m_nCodePage, 0, m_szWFontName, -1, (char *)m_szMBFontName, 50, NULL, NULL);
#else
		strcpy_s(m_szMBFontName, strlen(szSelectedFont)+1, szSelectedFont);
		MultiByteToWideChar(m_nCodePage, 0, (char *)szSelectedFont, (int)strlen(szSelectedFont)+1, m_szWFontName, 50);
#endif
	}
	else
	{
		// Check keyboard layout
		if (hKeyboardLayout == 0)
			hKeyboardLayout = GetKeyboardLayout(0);
		
		

		switch (LOWORD(hKeyboardLayout))
		{
			// Traditional Chinese 
			case LID_TRADITIONAL_CHINESE:	
				m_nLanguage = TRADITIONAL_CHINESE;
   				break;

			// Japanese
			case LID_JAPANESE:				
				m_nLanguage = JAPANESE;
				break;

			// Korean
			case LID_KOREAN:				
				m_nLanguage = KOREAN;
				break;

			// Simplified Chinese
			case LID_SIMPLIFIED_CHINESE:	
				m_nLanguage = SIMPLIFIED_CHINESE;
				break;

			default:
				m_nLanguage = DEFAULT;
				break;
		}
		
		// Set code page and charset
		if (m_nLanguage)
			m_nCodePage = nCodePage[m_nLanguage];
		else
			m_nCodePage = GetACP();
		m_nCharSet = nCharSet[m_nLanguage];		

		size_t jdh = wcslen((wchar_t *)szDefaultFontName[m_nLanguage]);
		// Apply default font
		wcscpy_s(m_szWFontName, wcslen((wchar_t *)szDefaultFontName[m_nLanguage])+1, (wchar_t *)szDefaultFontName[m_nLanguage]);
		WideCharToMultiByte(m_nCodePage, 0, m_szWFontName, -1, (char *)m_szMBFontName, 50, NULL, NULL);

		// Get IME property
		m_dwProperty = ImmGetProperty(hKeyboardLayout, IGP_PROPERTY );
	}

	// delete current font
	if (m_hFont)
		DeleteObject(m_hFont);

	// Create font
	if (m_fIsNT)
		m_hFont = CreateFontW(FONT_WIDTH, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, m_nCharSet, 
					 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_DONTCARE, m_szWFontName);
	else
		m_hFont = CreateFontA(FONT_WIDTH, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, m_nCharSet, 
					 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_DONTCARE, m_szMBFontName);
	
	// If fail to create selected or default font, create default font
	if (!m_hFont)
	{
		// Apply default font
		wcscpy_s(m_szWFontName, wcslen((wchar_t *)szDefaultFontName[DEFAULT])+1, (wchar_t *)szDefaultFontName[DEFAULT]);
		WideCharToMultiByte(m_nCodePage, 0, m_szWFontName, -1, (char *)m_szMBFontName, 50, NULL, NULL);

		if (m_fIsNT)
			m_hFont = CreateFontW(FONT_WIDTH, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, m_nCharSet, 
						 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_DONTCARE, m_szWFontName);
		else
			m_hFont = CreateFontA(FONT_WIDTH, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, m_nCharSet, 
						 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_DONTCARE, m_szMBFontName);
	}

	ShowCaretOnView();
	Invalidate();
}

/*****************************************************************************\
* Function: GetCombinedCharLength
*
* Get the length of combined character. 
*
* This implementation only support Surrogate. You need to handle Combined 
* characters as necessary.  
*
* return value:
*	If UNICODE, 
*		2 if surrogate char, else return 1
*	If not UNICODE
*		2 if DBCS char, else return 1
\*****************************************************************************/
int CIMEEdit::GetCombinedCharLength(int nTmpPos) 
{
	int	i, nRet = 1;

	// Check surrogate char
	for (i = 0; i <= nTmpPos; i++)
	{
		if ((0xD800 <= m_szBuffer[i]) && (m_szBuffer[i] <= 0xDBFF))
		{
			nRet = 2;
			++i;
		}
		else
			nRet = 1;
	}

	return nRet;
}

/*****************************************************************************\
* Function: ClearBuffer
*
* Clear string buffer
\*****************************************************************************/
void CIMEEdit::ClearBuffer()
{
	memset(m_szBuffer, 0, WCHARSIZE * (BUFFERSIZE + 1));
	m_xEndPos = m_xInsertPos = m_xCaretPos = 0;
}


/*****************************************************************************\
* Function: SetCandiDateWindowPos
*
* Set candidate window position for Japanese/Korean IME
\*****************************************************************************/
void CIMEEdit::SetCandiDateWindowPos() 
{
	HIMC		hIMC;
	CClientDC	dc(this);
	TEXTMETRIC	tm;
	CANDIDATEFORM Candidate;
	errno_t err;
	
	hIMC = ImmGetContext(this->m_hWnd);
	if (hIMC) 
	{
		dc.GetTextMetrics(&tm);
		
		Candidate.dwIndex = 0;
		Candidate.dwStyle = CFS_FORCE_POSITION;

		if (m_nLanguage == JAPANESE) 
		{
			// Set candidate window position near editable character
			wchar_t *szTmpStr = new(wchar_t[m_xInsertPos + m_nComCursorPos + 1]);

			err = memcpy_s(szTmpStr, WCHARSIZE* (m_xInsertPos + m_nComCursorPos), m_szBuffer, WCHARSIZE * (m_xInsertPos + m_nComCursorPos));	 
			ASSERT(!err);
			szTmpStr[m_xInsertPos + m_nComCursorPos] = L'\0';
			Candidate.ptCurrentPos.x = X_INIT + GetWidthOfString(szTmpStr);
		}
		else
		{
			// Set candidate window position near caret position
			CPoint		point;

			point = GetCaretPos();
			Candidate.ptCurrentPos.x = point.x;
		}
		Candidate.ptCurrentPos.y = Y_INIT + tm.tmHeight + 1;
		ImmSetCandidateWindow(hIMC, &Candidate);

		ImmReleaseContext(this->m_hWnd,hIMC);
	}
}

/*****************************************************************************\
* Function: SetCompositionWindowPos
*
* Set composition window position for Traditional Chinese IME
\*****************************************************************************/
void CIMEEdit::SetCompositionWindowPos() 
{
	HIMC		hIMC;
    CPoint		point;
    COMPOSITIONFORM Composition;

	hIMC = ImmGetContext(this->m_hWnd);
	if (hIMC) 
	{
		// Set composition window position near caret position
		point = GetCaretPos();
		Composition.dwStyle = CFS_POINT;
		Composition.ptCurrentPos.x = point.x;
		Composition.ptCurrentPos.y = point.y;
		ImmSetCompositionWindow(hIMC, &Composition);

		ImmReleaseContext(this->m_hWnd,hIMC);
	}
}

LRESULT CIMEEdit::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message)
	{
		// Change the setting if input language is changed
		case WM_INPUTLANGCHANGE:
			ClearBuffer();

			// Create new font for changed input language
			SetFont((HKL) lParam, NULL);
			Invalidate();
			ShowCaretOnView();

			// Send message for change the IME mode
			::PostMessage(GetParent()->m_hWnd, WM_SETINPUTLANG, 0L, 0L);
			break;

		// Start composition
		case WM_IME_STARTCOMPOSITION:
			// Trun on composition flag
			m_fStat = TRUE;

			// if IME property does not have IME_PROP_AT_CARET, ignore level 3 feature
			if (!(m_dwProperty & IME_PROP_AT_CARET) )
				break;

			OnImeStartComposition(wParam, lParam);			
			return 0l;

		// Composotion char
		case WM_IME_COMPOSITION:

			if (OnImeComposition(wParam, lParam))
				return 0l;
			// Call CEdit::WinProc to show composition window
			break;
		// End conposition
		case WM_IME_ENDCOMPOSITION:

			// Turn off composition flag
			m_fStat = FALSE;

			// if IME property does not have IME_PROP_AT_CARET, ignore level 3 feature
			if (!(m_dwProperty & IME_PROP_AT_CARET) )
				break;

			OnImeEndComposition(wParam, lParam);			
			return 0l;

		case WM_IME_NOTIFY:
			switch (wParam)
			{
				// Set candidate window position
				case IMN_OPENCANDIDATE:
					if (m_nLanguage == JAPANESE)
						SetCandiDateWindowPos();
					break;

				// To detect the change of IME mode 
				case IMN_SETCONVERSIONMODE:
				case IMN_SETSENTENCEMODE:
					::PostMessage(GetParent()->m_hWnd, WM_RESETMODE, wParam, lParam);
					break;

				// To detect the toggling of Japanese IME
				case IMN_SETOPENSTATUS:   
					::PostMessage(GetParent()->m_hWnd, WM_TOGGLE, wParam, lParam);
					break;
			}	
			break;

		case WM_IME_SETCONTEXT:
			// Except IME mode control in Japanese Win9x, dose not need to send this message
			if ((m_nLanguage ==  JAPANESE) && !m_fIsNT) 				
			{
				::PostMessage(GetParent()->m_hWnd, WM_SETMODE, wParam, lParam);
			}
			break;
	}		
	return CEdit::WindowProc(message, wParam, lParam);
}
