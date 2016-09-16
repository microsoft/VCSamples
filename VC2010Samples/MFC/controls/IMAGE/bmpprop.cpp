// BmpProp.cpp : implementation file
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
#include "image.h"
#include "BmpProp.h"
#include "ImageCtl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CBitmapProperty, CDataPathProperty)

/////////////////////////////////////////////////////////////////////////////
// CBitmapProperty

CBitmapProperty::CBitmapProperty(COleControl* pControl) : CDataPathProperty(pControl),
	m_dlState(dlNone)
{
}

CBitmapProperty::~CBitmapProperty()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CBitmapProperty, CDataPathProperty)
	//{{AFX_MSG_MAP(CBitmapProperty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif  // 0

/////////////////////////////////////////////////////////////////////////////
// CBitmapProperty member functions

void CBitmapProperty::OnDataAvailable(DWORD dwSize, DWORD bscfFlag)
{
	if (bscfFlag & BSCF_FIRSTDATANOTIFICATION)
		ResetData();

	CDataPathProperty::OnDataAvailable(dwSize, bscfFlag);

	if (dwSize <= m_cbRead)
		return;
	else
		dwSize -= m_cbRead;
	m_cbRead += dwSize;

	BOOL bContinue = m_dlState != dlDone;
	while (bContinue)
	{
		switch (m_dlState)
		{
		case dlNone:
			// Try to read the bitmapfileheader.
			{
				BITMAPFILEHEADER bmfh;
				if (ReadStruct(dwSize, &bmfh, sizeof(bmfh)))
				{
					ASSERT(bmfh.bfType == ('B' | ('M' << 8)));
					m_dlState = dlFileHeader;
				}
				else
				{
					bContinue = FALSE;
					break;
				}
			}
			break;

		case dlFileHeader:
			// Try to read the bitmapinfoheader.
			if (ReadStruct(dwSize, &m_bmInfo.bmiHeader, sizeof(m_bmInfo.bmiHeader)))
			{
				// Now we know the image size.
				m_BitmapSize.cx = m_bmInfo.bmiHeader.biWidth;
				m_BitmapSize.cy = m_bmInfo.bmiHeader.biHeight;
				ASSERT_KINDOF(CImageCtrl, GetControl());
				((CImageCtrl*)GetControl())->InformSize();

				m_dlState = dlInfoHeader;
			}
			else
			{
				bContinue = FALSE;
				break;
			}
			break;

		case dlInfoHeader:
			// Read the color table.
			if (ReadStruct(dwSize, &m_bmInfo.bmiColors,
				sizeof(RGBQUAD) * ((int)(1 << m_bmInfo.bmiHeader.biBitCount))))
			{
				// Create the bitmap.
				CWindowDC screenDC(NULL);
				m_Bitmap.CreateCompatibleBitmap(&screenDC, m_BitmapSize.cx, m_BitmapSize.cy);

				m_dlState =  dlColorTable;
			}
			else
			{
				bContinue = FALSE;
				break;
			}
			break;

		case dlColorTable:
			// Read some pels.
			{
				BYTE* pb = NULL;
				int nLines = ReadArray(dwSize, (void **)&pb,
					((((m_bmInfo.bmiHeader.biBitCount * m_BitmapSize.cx) + 31) / 32) * 4),
						m_BitmapSize.cy - m_nScanLine);
				if (nLines > 0)
				{
					CWindowDC screenDC(NULL);
					CDC dc;
					dc.CreateCompatibleDC(&screenDC);
					CBitmap* pBitmap;

					pBitmap = dc.SelectObject(&m_Bitmap);
					SetDIBits(dc.m_hDC, (HBITMAP)m_Bitmap.m_hObject, m_nScanLine, nLines,
								 pb, &m_bmInfo, DIB_RGB_COLORS);

					m_nScanLine += nLines;
					GetControl()->InvalidateControl(NULL);
				}
				else
				{
					bContinue = FALSE;
					break;
				}

				delete [] pb;

				if (m_nScanLine == m_BitmapSize.cy)
					m_dlState = dlDone;
			}
			break;
		}; //switch

		bContinue = bContinue && (m_dlState != dlDone);
	} //while

	ASSERT_KINDOF(CImageCtrl, GetControl());
	((CImageCtrl*)GetControl())->InformDlStatus(m_dlState);
}

void CBitmapProperty::ResetData()
{
	CDataPathProperty::ResetData();
	m_dlState = dlNone;
	if (m_Bitmap.m_hObject != NULL)
		m_Bitmap.DeleteObject();

	m_CacheFile.SetLength(0);
	m_nScanLine = 0;
	m_cbRead = 0;
}

DWORD AfxTransferFileContent(CFile* pFrom, CFile* pTo, DWORD dwAmount)
{
	BYTE buff[1024];
	DWORD dwRead = 0;
	DWORD dwActual = 1; // bogus value to enter the loop
	while ((dwAmount > 0) && (dwActual > 0))
	{
		dwActual = pFrom->Read(buff, min(dwAmount, 1024));
		pTo->Write(buff, dwActual);

		dwAmount -= dwActual;
		dwRead += dwActual;
	}
	return dwRead;
}

BOOL CBitmapProperty::ReadStruct(DWORD& rdwSize, void* pb, int cLen)
{
	// Cache contents.
	AfxTransferFileContent(this, &m_CacheFile, rdwSize);
	rdwSize = 0;

	// Do we have enough data yet?
#pragma warning(disable:4244)
	int cCache = m_CacheFile.GetLength();
	if (cCache >= cLen)
	{
		m_CacheFile.SeekToBegin();
		VERIFY(m_CacheFile.Read(pb, cLen) == (UINT)cLen);

		// Is there more?
		if (cCache > cLen)
		{
			CMemFile memFile;
			AfxTransferFileContent(&m_CacheFile, &memFile, cCache - cLen);
			m_CacheFile.SetLength(0);
			memFile.SeekToBegin();
			AfxTransferFileContent(&memFile, &m_CacheFile, cCache - cLen);
		}
		else
		{
			m_CacheFile.SetLength(0);
		}

		return TRUE;
	}
	else
	{
		return FALSE;
	}
#pragma warning(default:4244)
}

int CBitmapProperty::ReadArray(DWORD& rdwSize, void** pb, int cElem, int cMax)
{
	// Cache contents.
	AfxTransferFileContent(this, &m_CacheFile, rdwSize);
	rdwSize = 0;
	int nElems = 0;

	// Do we have enough data yet?
#pragma warning(disable:4244)
	int cCache = m_CacheFile.GetLength();
#pragma warning(default:4244)
	if (cCache >= cElem)
	{
		m_CacheFile.SeekToBegin();

		nElems = min(cCache / cElem, cMax);
		int cSize = nElems * cElem;
		ASSERT(cSize <= cCache);

		*pb = new BYTE[cSize];
		ASSERT(m_CacheFile.Read(*pb, cSize) == (UINT)cSize);

		// Is there more?
		if (cCache > cSize)
		{
			CMemFile memFile;
			AfxTransferFileContent(&m_CacheFile, &memFile, cCache - cSize);
			m_CacheFile.SetLength(0);
			memFile.SeekToBegin();
			AfxTransferFileContent(&memFile, &m_CacheFile, cCache - cSize);
		}
		else
		{
			m_CacheFile.SetLength(0);
		}
	}

	return nElems;
}
