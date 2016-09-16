// itemtemp.cpp
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

#include "itemtemp.h"
#include "resource.h"

#define SETRECT(rect, l, t, r, b) \
	rect.left = l; \
	rect.top = t; \
	rect.right = r; \
	rect.bottom = b;


CMyDialogTemplate::CMyDialogTemplate()
{
	// initialize the 3 dialog items

	CRect   rect(10, 10, 80, 35);  // Set default postions for the buttons
	m_rgDlgItem[IBUTTON].Initialize(CDialogItem::BUTTON, IDC_MYBUTTON, &rect, _T("Dummy Button"));
	SETRECT(rect, 100, 10, 250, 35);
	m_rgDlgItem[ISTATICTEXT].Initialize(CDialogItem::STATICTEXT, IDC_MYSTATICTEXT, &rect, _T("Static Text of your choice here."));
	SETRECT(rect, 70, 50, 250, 135);
	m_rgDlgItem[IEDITCONTROL].Initialize(CDialogItem::EDITCONTROL, IDC_MYEDITCONTROL, &rect,
		_T("This is a multiline edit control.  CMyDialogItem::DemoIt holds the essential code of this sample."));

	// now initialize the DLGTEMPLATE structure
	m_dlgTempl.cx = 280;  // 4 horizontal units are the width of one character
	m_dlgTempl.cy = 160;  // 8 vertical units are the height of one character
	m_dlgTempl.style = WS_CAPTION | WS_VISIBLE | WS_DLGFRAME | WS_POPUP | DS_MODALFRAME | DS_SETFONT;
	m_dlgTempl.dwExtendedStyle = 0;
	m_dlgTempl.x = 0;
	m_dlgTempl.y = 0;
	m_dlgTempl.cdit = 3;  // 3 dialog items in the dialog
}

void CMyDialogTemplate::DemoIt()
{
	// The first step is to allocate memory to define the dialog.  The information to be
	// stored in the allocated buffer is the following:
	//
	// 1.  DLGTEMPLATE structure
	// 2.    0x0000 (Word) indicating the dialog has no menu
	// 3.    0x0000 (Word) Let windows assign default class to the dialog
	// 4.    (Caption)  Null terminated unicode string
	// 5.    0x000B  (size of the font to be used)
	// 6.    "Arial"  (name of the typeface to be used)
	// 7.  DLGITEMTEMPLATE structure for the button  (HAS TO BE DWORD ALIGNED)
	// 8.    0x0080  to indicate the control is a button
	// 9.    (Title). Unicode null terminated string with the caption
	// 10.    0x0000   0 extra bytes of data for this control
	// 11.  DLGITEMTEMPLATE structure for the Static Text  (HAS TO BE DWORD ALIGNED)
	// 12.    0x0081 to indicate the control is static text
	// 13.   (Title). Unicode null terminated string with the text
	// 14     0x0000.  0 extra bytes of data for this control
	// 15. DLGITEMTEMPLATE structure for the Edit Control (HAS TO BE DWORD ALIGNED)
	// 16.   0x0082 to indicate an Edit control
	// 17.   (Text) - Null terminated unicode string to appear in the edit control
	// 18.   0x0000. 0 extra bytes of data for this control

	WCHAR szBoxCaption[] = L"Dialog Template Sample -  PRESS <ESC> TO CLOSE THIS DIALOG";
	WCHAR szFontName[] = L"ARIAL";

	// will first convert the control captions to UNICODE
	int     i;

	TRY  // catch memory exceptions and don't worry about allocation failures
	{
		// The following expressions have unnecessary parenthesis trying to make the
		// comments more clear.
		int nBufferSize =  sizeof(DLGTEMPLATE) + (2 * sizeof(WORD))/*menu and class*/ + sizeof(szBoxCaption);
		nBufferSize += sizeof(WORD) + sizeof(szFontName); /* font information*/

		nBufferSize = (nBufferSize + 3) & ~3;  // adjust size to make first control DWORD aligned

		for (i = 0; i < TOTALITEMS; i++)
		{
			int nItemLength = sizeof(DLGITEMTEMPLATE) + 3 * sizeof(WORD);
			nItemLength += (m_rgDlgItem[i].m_strCaption.GetLength() + 1) * sizeof(WCHAR);

			if (i != TOTALITEMS -1 )   // the last control does not need extra bytes
				nItemLength = (nItemLength + 3) & ~3;  // take into account gap so next control is DWORD aligned

			nBufferSize += nItemLength;
		}


		HLOCAL hLocal = LocalAlloc(LHND, nBufferSize);
		if (hLocal == NULL)
			AfxThrowMemoryException();

		BYTE*   pBuffer = (BYTE*)LocalLock(hLocal);
		if (pBuffer == NULL)
		{
			LocalFree(hLocal);
			AfxThrowMemoryException();
		}

		BYTE*   pdest = pBuffer;
		BYTE* pdestEnd = pdest + nBufferSize;
		// transfer DLGTEMPLATE structure to the buffer
		memcpy_s(pdest, pdestEnd - pdest, &m_dlgTempl, sizeof(DLGTEMPLATE));
		pdest += sizeof(DLGTEMPLATE);
		*(WORD*)pdest = 0; // no menu
		*(WORD*)(pdest + sizeof(WORD)) = 0;  // use default window class
		pdest += 2 * sizeof(WORD);
		memcpy_s(pdest, pdestEnd - pdest, szBoxCaption, sizeof(szBoxCaption));
		pdest += sizeof(szBoxCaption);
		*(WORD*)pdest = 11;  // font size
		pdest += sizeof(WORD);
		memcpy_s(pdest, pdestEnd - pdest, szFontName, sizeof(szFontName));
		pdest += sizeof(szFontName);

		// will now transfer the information for each one of the item templates
		for (i = 0; i < TOTALITEMS; i++)
		{
			pdest = (BYTE*)(((DWORD_PTR)pdest + 3) & ~3);  // make the pointer DWORD aligned
			memcpy_s(pdest, pdestEnd - pdest, (void *)&m_rgDlgItem[i].m_dlgItemTemplate, sizeof(DLGITEMTEMPLATE));
			pdest += sizeof(DLGITEMTEMPLATE);
			*(WORD*)pdest = 0xFFFF;  // indicating atom value
			pdest += sizeof(WORD);
			*(WORD*)pdest = (WORD)m_rgDlgItem[i].m_controltype;    // atom value for the control
			pdest += sizeof(WORD);

			// transfer the caption even when it is an empty string
			WCHAR*  pchCaption;
			int     nChars, nActualChars;

			nChars = m_rgDlgItem[i].m_strCaption.GetLength() + 1;
			pchCaption = new WCHAR[nChars];
			nActualChars = MultiByteToWideChar(CP_ACP, 0, m_rgDlgItem[i].m_strCaption, -1, pchCaption, nChars);
			ASSERT(nActualChars > 0);
			memcpy_s(pdest, pdestEnd - pdest, pchCaption, nActualChars * sizeof(WCHAR));
			pdest += nActualChars * sizeof(WCHAR);
			delete [] pchCaption;

			*(WORD*)pdest = 0;  // How many bytes in data for control
			pdest += sizeof(WORD);
		}
		ASSERT(pdest - pBuffer == nBufferSize); // just make sure we did not overrun the heap

		CDialog dlg;
		dlg.InitModalIndirect((DLGTEMPLATE*)pBuffer);
		dlg.DoModal();  // tadaaa!  this is the line everyone's been waiting for!!!

		LocalUnlock(hLocal);
		LocalFree(hLocal);
	}
	CATCH(CMemoryException, e)
	{
		MessageBox(NULL, _T("Memory allocation for dialog template failed.  Demo aborted!"),
			_T("Allocation Failure"), MB_ICONEXCLAMATION | MB_OK);
	}
	END_CATCH
}

CDialogItem::CDialogItem(enum CDialogItem::controltype ctrlType)
{
	m_controltype = ctrlType;
}


void CDialogItem::Initialize(enum controltype ctrltype, UINT nID, CRect* prect, LPCTSTR lpszCaption)
{
	// first fill in the type, location and size of the control
	m_controltype = ctrltype;
	if (prect != NULL)
	{
		// disable warning on conversion from long to short
#pragma warning(disable : 4244)
		m_dlgItemTemplate.x = prect->left;
		m_dlgItemTemplate.y = prect->top;
		m_dlgItemTemplate.cx = prect->Width();
		m_dlgItemTemplate.cy = prect->Height();
#pragma warning(default : 4244)
	}
	else
	{
		m_dlgItemTemplate.x = 0;
		m_dlgItemTemplate.y = 0;
		m_dlgItemTemplate.cx = 10;  // some useless default
		m_dlgItemTemplate.cy = 10;
	}
#pragma warning(disable : 4244)
	m_dlgItemTemplate.dwExtendedStyle = 0;
	m_dlgItemTemplate.id = nID;
#pragma warning(default : 4244)

	// the styles below are hard coded.  In a real life application you might want to use variables to
	// define the sytle.
	switch(m_controltype)
	{
	case BUTTON:
		m_dlgItemTemplate.style = WS_CAPTION | WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_PUSHBUTTON;
		break;
	case EDITCONTROL:
		m_dlgItemTemplate.style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_MULTILINE | ES_LEFT;
		break;
	case STATICTEXT:
		m_dlgItemTemplate.style = WS_CHILD | WS_VISIBLE | SS_LEFT;
		break;
	default:
		ASSERT(FALSE);  // should never get here, anyway.
	}

	m_strCaption = (lpszCaption != NULL)? lpszCaption : _T("");
}
