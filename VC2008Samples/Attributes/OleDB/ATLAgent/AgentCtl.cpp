// AgentCtl.cpp : Implementation of CAgentCtl
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "AgentCtl.h"
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////
// CAgentCtl

STDMETHODIMP CAgentCtl::Play()
{
	m_Instruction.MoveFirst();

	while (m_Instruction.MoveNext() == S_OK)
		ProcessInstruction(m_Instruction);

	return S_OK;
}

void CAgentCtl::ProcessInstruction(const CInstruction& instruction)
{
	USES_CONVERSION;

	if (lstrcmpi(instruction.szCommand, _T("Speak")) == 0)
		SpeakText(CComBSTR(instruction.szText));
	else if (lstrcmpi(instruction.szCommand, _T("Play")) == 0)
		m_pCharacter->Play((BSTR)CComBSTR(instruction.szText), &m_nRequestID);
	else if (lstrcmpi(instruction.szCommand, _T("Hide")) == 0)
		m_pCharacter->Hide(FALSE, &m_nRequestID);
	else if (lstrcmpi(instruction.szCommand, _T("Show")) == 0)
		m_pCharacter->Show(FALSE, &m_nRequestID);
	else if (lstrcmpi(instruction.szCommand, _T("MoveTo")) == 0)
	{
		short x, y;
#ifdef _UNICODE
		wscanf_s(instruction.szText, _T("%d, %d"), &x, &y);
#else
		sscanf_s(instruction.szText, _T("%d, %d"), &x, &y);
#endif
		m_pCharacter->MoveTo(x, y, (100-m_nSpeed)*10+100, &m_nRequestID);
	}
	else if (lstrcmpi(instruction.szCommand, _T("GestureAt")) == 0)
	{
		short x, y;
#ifdef _UNICODE
		wscanf_s(instruction.szText, _T("%d, %d"), &x, &y);
#else
		sscanf_s(instruction.szText, _T("%d, %d"), &x, &y);
#endif
		m_pCharacter->GestureAt(x, y, &m_nRequestID);
	}
}

// Override function so the COM support doesnt throw exeptions
void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo) //throw(_com_error)
{
}

STDMETHODIMP CAgentCtl::SpeakText(BSTR Text)
{
	USES_CONVERSION;
	TCHAR szText[256];

	wsprintf(szText, _T("\\spd=%d\\"), m_nSpeed+100);
	CComBSTR strText = szText;
	strText.AppendBSTR(Text);
	m_pCharacter->Show(FALSE, &m_nRequestID);
	m_pCharacter->Speak((BSTR)strText, "", &m_nRequestID);

	return S_OK;
}

STDMETHODIMP CAgentCtl::SpeakFile(BSTR FileName)
{
	USES_CONVERSION;
	HANDLE hFile = CreateFile(OLE2T(FileName), GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return Error("Couldn't open file");

	char  szBuffer[100000];
	DWORD dwBytesRead;

	m_pCharacter->Show(FALSE, &m_nRequestID);
	ReadFile(hFile, szBuffer, 99999, &dwBytesRead, NULL);
	CloseHandle(hFile);

	*(szBuffer+dwBytesRead) = 0;    // Add the NULL byte
	SpeakText((BSTR)CComBSTR(szBuffer));

	return S_OK;
}

STDMETHODIMP CAgentCtl::get_Speed(long * pVal)
{
	*pVal = m_nSpeed;

	return S_OK;
}

STDMETHODIMP CAgentCtl::put_Speed(long newVal)
{
	if (newVal > 100)
		m_nSpeed = 100;
	else if (newVal < 0)
		m_nSpeed = 0;
	else
		m_nSpeed = newVal;

	return S_OK;
}

STDMETHODIMP CAgentCtl::Animate(BSTR Animation)
{
	if (m_pCharacter != NULL)
		m_pCharacter->Play(Animation, &m_nRequestID);

	return S_OK;
}

STDMETHODIMP CAgentCtl::Stop()
{
	if (m_pCharacter != NULL)
		m_pCharacter->Stop(m_nRequestID);

	return S_OK;
}
