// This is a part of the Microsoft Foundation Classes C++ library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#include "stdafx.h"
#include "InfoDlg.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

CInfoDlg::CInfoDlg(CImage &image) : CDialog(CInfoDlg::IDD)
{
	m_pImage = &image;
}

// override the CDialog::OnInitDialog method
BOOL CInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CStatic* pInfo;
	char buffer[12];

	// display original size
	int width, height; 
	pInfo = (CStatic*) GetDlgItem(IDC_IMAGESIZE);
	width = m_pImage->GetWidth();
	height = m_pImage->GetHeight();
	sprintf_s(buffer, 12, "%i x %i",m_pImage->GetWidth(),m_pImage->GetHeight());
	pInfo->SendMessage(WM_SETTEXT,0,(LPARAM)buffer); 

	// display bit depth
	pInfo = (CStatic*) GetDlgItem(IDC_BITDEPTH);
	sprintf_s(buffer, 12, "%i-bit",m_pImage->GetBPP());
	pInfo->SendMessage(WM_SETTEXT,0,(LPARAM)buffer);

	// display DIB section info
	pInfo = (CStatic*) GetDlgItem(IDC_DIBSECTION);
	if (m_pImage->IsDIBSection()) {
		sprintf_s(buffer, 12, "Yes");
	} else {
		sprintf_s(buffer, 12, "No");
	}
	pInfo->SendMessage(WM_SETTEXT,0,(LPARAM)buffer);

	// display indexed info
	pInfo = (CStatic*) GetDlgItem(IDC_INDEXED);
	if (m_pImage->IsIndexed()) {
		sprintf_s(buffer, 12, "Yes");
	} else {
		sprintf_s(buffer, 12, "No");
	}
	pInfo->SendMessage(WM_SETTEXT,0,(LPARAM)buffer);

	// display pitch
	pInfo = (CStatic*) GetDlgItem(IDC_PITCH);
	sprintf_s(buffer, 12, "%i bytes",m_pImage->GetPitch());
	pInfo->SendMessage(WM_SETTEXT,0,(LPARAM)buffer);

	return TRUE;

}


BEGIN_MESSAGE_MAP(CInfoDlg,CDialog)
END_MESSAGE_MAP()
