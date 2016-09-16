// util.h

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _UTIL_H_
#define _UTIL_H_

/// Utilities
#define RCF_NORMAL      0x0000
#define RCF_ITALIC      0x0001
#define RCF_UNDERLINE   0x0002
#define RCF_STRIKEOUT   0x0004
#define RCF_BOLD        0x0008
#define RCF_NODEFAULT   0x0010
#define RCF_TRUETYPEONLY 0x0011

void ErrorMessage( const CString& str, HRESULT hr ) ;

CFont *ReallyCreateFont( HDC hDC, LPTSTR lpszFace, LPTSTR lpszStyle, UINT nPointSize, UINT uiFlags ) ;

LPTSTR FAR PASCAL PointerToNthField(LPTSTR lpszString, int nField, TCHAR chDelimiter) ;

LONG WINAPI ParseOffNumber( LPTSTR FAR *lplp, LPINT lpConv ) ;

void WINAPI DlgCenter( HWND hwndCenter, HWND hwndWithin, BOOL fClient ) ;
void bmColorTranslateDC( CDC* pdcMem, BITMAP *pBM, COLORREF rgbOld,  COLORREF rgbNew ) ;
void bmColorTranslate( CBitmap* pbmSrc, COLORREF rgbNew ) ;
CBitmap* bmLoadAndTranslate( UINT id, COLORREF rgb );
void DrawListBoxBitmap( CDC* pdc, CBitmap *pbmt, int x,  int y ) ;
int WINAPI GetTextMetricsCorrectly( HDC hDC, LPTEXTMETRIC lpTM ) ;

typedef struct FAR tagCOLUMNSTRUCT
{
   int   nLeft ;       // starting x position of the column
   int   nRight ;      // ending x position of the column
   UINT  uiFlags ;      // format flags

} COLUMNSTRUCT, *PCOLUMNSTRUCT, FAR *LPCOLUMNSTRUCT ;

void WINAPI ColumnTextOut( CDC* pDC, int nX, int nY, CString* pStr,
							int cColumns, LPCOLUMNSTRUCT rgColumns ) ;
LPTSTR HRtoString( HRESULT hr ) ;
LPTSTR VTtoString( VARTYPE vt ) ;

VOID WINAPI StripFilespec( LPTSTR lpszPath ) ;
VOID WINAPI AddBackslash( LPTSTR lpszPath, int nSize ) ;

#endif
