/************************************************************************
 *      Module:  shadow.c
 *
 ***********************************************************************/

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "shadow.h"
VOID NEAR PASCAL Draw3DLine1( HDC hDC, UINT x, UINT y, UINT nLen, UINT wFlags ) ;
VOID NEAR PASCAL DrawFrame( HDC hDC, LPRECT lprc ) ;

#define SHADOWWIDTH  1

/****************************************************************
 *  VOID WINAPI tdDraw3DCrease( HDC hDC, LPRECT lprc, UINT uiFlags )
 *
 *  Description:
 *
 *
 *
 *  Comments:
 *
 ****************************************************************/
VOID WINAPI tdDraw3DCrease( HDC hDC, LPRECT lpRect, UINT uiFlags )
{
   RECT       rc ;
   COLORREF   rgbOld ;

   rc = *lpRect ;

   if (uiFlags & DRAW3D_OUT)
	  OffsetRect( &rc, 1, 1 ) ;

   rgbOld = SetBkColor( hDC, tdGetShadowColor( GetBkColor( hDC ) ) ) ;

   DrawFrame( hDC, &rc ) ;

   if (uiFlags & DRAW3D_OUT)
	  OffsetRect( &rc, -1, -1 ) ;
   else
	  OffsetRect( &rc, 1, 1 ) ;


   SetBkColor( hDC, tdGetHighlightColor( rgbOld ) ) ;

   DrawFrame( hDC, &rc ) ;

   SetBkColor( hDC, rgbOld ) ;

} /* tdDraw3DCrease()  */

/** VOID WINAPI tdDraw3DRect( HDC, LPRECT, UINT, UINT )
 *
 *  DESCRIPTION:
 *      Draws a 3D rectangle that is shaded.  wFlags can be used to
 *      control how the rectangle looks.
 *
 *  ARGUMENTS:
 *      HDC hDC             :   Handle to the device context that will be
 *                              used to display the rectangle.
 *
 *      RECT rect           :   A rectangle describing the dimensions of
 *                              the rectangle in device coordinates.
 *
 *      UINT wShadowWidth   :   Width of the shadow in device coordinates.
 *
 *      UINT wFlags         :   The following flags may be passed to describe
 *                              the style of the rectangle:
 *
 *                              DRAW3D_IN   :   The shadow is drawn such that
 *                              the box appears to be sunk in to the screen.
 *                              This is default if 0 is passed.
 *
 *                              DRAW3D_OUT  :   The shadow is drawn such that
 *                              the box appears to be sticking out of the
 *                              screen.
 *
 *  RETURN (VOID WINAPI):
 *      The 3D looking rectangle will have been drawn into the DC.
 *
 *  NOTES:
 *
 ** cjp */

VOID WINAPI tdDraw3DRect( HDC hDC, LPRECT lpRect,
							   UINT uiShadowWidth, UINT uiFlags )
{
   /* sanity check--don't work if you don't have to! */
   if ( !uiShadowWidth || !RectVisible( hDC, lpRect ) )
	   return ;

   if (uiFlags & DRAW3D_CREASE)
   {
	  tdDraw3DCrease( hDC, lpRect, uiFlags ) ;
	  return ;
   }

   /* if width is 1 use lines instead of polygons */
   if (uiShadowWidth == 1)
   {
	  /* draw the top line */
	  Draw3DLine1( hDC, lpRect->left, lpRect->top,
					 lpRect->right - lpRect->left,
					 DRAW3D_TOPLINE | uiFlags ) ;

	  /* right line */
	  Draw3DLine1( hDC, lpRect->right, lpRect->top,
					 lpRect->bottom - lpRect->top,
					 DRAW3D_RIGHTLINE | uiFlags ) ;

	  /* bottom line */
	  Draw3DLine1( hDC, lpRect->left, lpRect->bottom,
					 lpRect->right - lpRect->left,
					 DRAW3D_BOTTOMLINE | uiFlags ) ;

	  /* left line */
	  Draw3DLine1( hDC, lpRect->left, lpRect->top,
					 lpRect->bottom - lpRect->top,
					 DRAW3D_LEFTLINE | uiFlags ) ;
   }
   else
   {
	  /* draw the top line */
	  tdDraw3DLine( hDC, lpRect->left, lpRect->top,
					 lpRect->right - lpRect->left,
					 uiShadowWidth, DRAW3D_TOPLINE | uiFlags ) ;

	  /* right line */
	  tdDraw3DLine( hDC, lpRect->right, lpRect->top,
					 lpRect->bottom - lpRect->top,
					 uiShadowWidth, DRAW3D_RIGHTLINE | uiFlags ) ;

	  /* bottom line */
	  tdDraw3DLine( hDC, lpRect->left, lpRect->bottom,
					 lpRect->right - lpRect->left,
					 uiShadowWidth, DRAW3D_BOTTOMLINE | uiFlags ) ;

	  /* left line */
	  tdDraw3DLine( hDC, lpRect->left, lpRect->top,
					 lpRect->bottom - lpRect->top,
					 uiShadowWidth, DRAW3D_LEFTLINE | uiFlags ) ;
   }
} /* Draw3DRect() */


/** VOID WINAPI tdDraw3DLine( HDC hDC, UINT x, UINT y, UINT nLen,
 *
 *  DESCRIPTION:
 *      Draws a 3D line that can be used to make a 3D box.
 *
 *  ARGUMENTS:
 *      HDC hDC             :   Handle to the device context that will be
 *                              used to display the 3D line.
 *
 *      UINT x, y           :   Coordinates of the beginning of the line.
 *                              These coordinates are in device UINTs and
 *                              represent the _outside_ most point. Horiz-
 *                              ontal lines are drawn from left to right and
 *                              vertical lines are drawn from top to bottom.
 *
 *      UINT uiShadowWidth   :   Width of the shadow in device coordinates.
 *
 *      UINT  uiFlags        :   The following flags may be passed to
 *                              describe the style of the 3D line:
 *
 *                              DRAW3D_IN   :   The shadow is drawn such that
 *                              the box appears to be sunk in to the screen.
 *                              This is default if 0 is passed.
 *
 *                              DRAW3D_OUT  :   The shadow is drawn such that
 *                              the box appears to be sticking out of the
 *                              screen.
 *
 *                              DRAW3D_TOPLINE, _BOTTOMLINE, _LEFTLINE, and
 *                              _RIGHTLINE  :   Specifies that a "top",
 *                              "Bottom", "Left", or"Right" line is to be
 *                              drawn.
 *
 *  RETURN (VOID WINAPI):
 *      The line will have been drawn into the DC.
 *
 *  NOTES:
 *
 ** cjp */

VOID WINAPI tdDraw3DLine( HDC hDC, UINT x, UINT y, UINT uiLen,
							   UINT uiShadowWidth, UINT uiFlags )
{
   HBRUSH  hBrush ;
   BOOL    fDark ;
   POINT   Point[ 4 ] ;         /* define a polgon with 4 points    */

   /* if width is zero, don't do nothin'! */
   if ( !uiShadowWidth )
	   return ;

   /* if width is 1 use lines instead of polygons */
   if (uiShadowWidth == 1)
   {
	  Draw3DLine1( hDC, x, y, uiLen, uiFlags ) ;
	  return ;
   }

   /* define shape of polygon--origin is always the same */
   Point[0].x = x ;
   Point[0].y = y ;

   /*  To do this we'll simply draw a polygon with four sides, using
	*  the appropriate brush.  I dare you to ask me why this isn't a
	*  switch/case!
	*/
   if ( uiFlags & DRAW3D_TOPLINE )
   {
	   /* across to right */
	   Point[1].x = x + uiLen - (uiShadowWidth == 1 ? 1 : 0) ;
	   Point[1].y = y ;

	   /* down/left */
	   Point[2].x = x + uiLen - uiShadowWidth ;
	   Point[2].y = y + uiShadowWidth ;

	   /* accross to left */
	   Point[3].x = x + uiShadowWidth ;
	   Point[3].y = y + uiShadowWidth ;

	   /* select 'dark' brush if 'in'--'light' for 'out' */
	   fDark = ( uiFlags & DRAW3D_IN ) ? TRUE : FALSE ;
   }

   /* possibly the bottom? */
   else if ( uiFlags & DRAW3D_BOTTOMLINE )
   {
	   /* across to right */
	   Point[1].x = x + uiLen ;
	   Point[1].y = y ;

	   /* up/left */
	   Point[2].x = x + uiLen - uiShadowWidth ;
	   Point[2].y = y - uiShadowWidth ;

	   /* accross to left */
	   Point[3].x = x + uiShadowWidth ;
	   Point[3].y = y - uiShadowWidth ;

	   /* select 'light' brush if 'in' */
	   fDark = ( uiFlags & DRAW3D_IN ) ? FALSE : TRUE ;
   }

   /* ok, it's gotta be left? */
   else if ( uiFlags & DRAW3D_LEFTLINE )
   {
	   /* down */
	   Point[1].x = x ;
	   Point[1].y = y + uiLen - (uiShadowWidth == 1 ? 1 : 0) ;

	   /* up/right */
	   Point[2].x = x + uiShadowWidth ;
	   Point[2].y = y + uiLen - uiShadowWidth ;

	   /* down */
	   Point[3].x = x + uiShadowWidth ;
	   Point[3].y = y + uiShadowWidth ;

	   /* select 'dark' brush if 'in'--'light' for 'out' */
	   fDark = ( uiFlags & DRAW3D_IN ) ? TRUE : FALSE ;
   }

   /* well maybe it's for the right side? */
   else if ( uiFlags & DRAW3D_RIGHTLINE )
   {
	   /* down */
	   Point[1].x = x ;
	   Point[1].y = y + uiLen ;

	   /* up/left */
	   Point[2].x = x - uiShadowWidth ;
	   Point[2].y = y + uiLen - uiShadowWidth ;

	   /* up */
	   Point[3].x = x - uiShadowWidth ;
	   Point[3].y = y + uiShadowWidth ;

	   /* select 'light' brush if 'in' */
	   fDark = ( uiFlags & DRAW3D_IN ) ? FALSE : TRUE ;
   }
   else
		return ;

   /* select NULL_PEN for no borders */
   SelectObject( hDC, GetStockObject( NULL_PEN ) ) ;

   /* select the appropriate color for the fill */
   hBrush = CreateSolidBrush( GetNearestColor( hDC, fDark ?
							  tdGetShadowColor( GetBkColor( hDC ) ) :
							  tdGetHighlightColor( GetBkColor( hDC ) ) ) ) ;

   hBrush = (HBRUSH)SelectObject( hDC, hBrush ) ;

   Polygon( hDC, (LPPOINT)Point, 4 ) ;

   /* restore what we killed */
   hBrush = (HBRUSH)SelectObject( hDC, hBrush ) ;

   DeleteObject( hBrush ) ;

} /*tdDraw3DLine() */



/****************************************************************
 *  COLORREF WINAPI tdGetHighLightColor( COLORREF rgb )
 *
 *  Description:
 *
 *    This function returns the highlight color that corresponds
 *    to the given rgb value.  If there is no "high intensity"
 *    color that matches, white is used (or yellow if the color
 *    is white).
 *
 *  Comments:
 *
 ****************************************************************/
COLORREF WINAPI tdGetHighlightColor( COLORREF rgb )
{
   BYTE  cRed, cGreen, cBlue ;

	#if _MFC_VER >= 0x0300
		if (rgb == GetSysColor( COLOR_BTNFACE ))
			return GetSysColor( COLOR_BTNHIGHLIGHT ) ;
	#endif

   if (rgb == RGBLTRED     ||
	   rgb == RGBLTGREEN   ||
	   rgb == RGBLTBLUE    ||
	   rgb == RGBLTMAGENTA ||
	   rgb == RGBLTCYAN    ||
	   rgb == RGBLTGRAY    ||
	   rgb == RGBYELLOW)
	  return RGBWHITE ;

   if (rgb == RGBWHITE)
	  return RGBLTGRAY ;

   if (rgb == RGBBLACK || rgb == RGBGRAY)
	  return RGBLTGRAY ;

   cRed = (BYTE)(rgb & 0x000000FF) ;

   cGreen = (BYTE)((rgb & 0x0000FF00) >> 8) ;

   cBlue = (BYTE)((rgb & 0x00FF0000) >> 16) ;

   if (cRed == 128)
	  cRed += 64 ;

   if (cGreen == 128)
	  cGreen += 64 ;

   if (cBlue == 128)
	  cBlue += 64 ;

   return RGB( cRed, cGreen, cBlue ) ;

} /* tdGetHighlightColor()  */


/****************************************************************
 *  COLORREF WINAPI tdGetShadowColor( COLORREF rgb )
 *
 *  Description:
 *
 *    Returns an appropriate shadow color for the given rgb.
 *
 *  Comments:
 *
 ****************************************************************/
COLORREF WINAPI tdGetShadowColor( COLORREF rgb )
{
	if (rgb == GetSysColor( COLOR_BTNFACE ))
		return GetSysColor( COLOR_BTNSHADOW ) ;

   BYTE  cRed, cGreen, cBlue ;

   if (rgb == RGBBLACK)
	  return RGBGRAY ;

   if (rgb == RGBRED     ||
	   rgb == RGBGREEN   ||
	   rgb == RGBBLUE    ||
	   rgb == RGBBROWN   ||
	   rgb == RGBMAGENTA ||
	   rgb == RGBCYAN    ||
	   rgb == RGBWHITE   ||
	   rgb == RGBGRAY)
	  return RGBBLACK ;

   if (rgb == RGBLTGRAY)
	  return RGBGRAY ;

   cRed = (BYTE)(rgb & 0x000000FF) ;

   cGreen = (BYTE)((rgb & 0x0000FF00) >> 8) ;

   cBlue = (BYTE)((rgb & 0x00FF0000) >> 16) ;

   if (cRed > 128)
	  cRed -= 64 ;

   if (cGreen > 128)
	  cGreen -= 64 ;

   if (cBlue > 128)
	  cBlue -= 64 ;

   return RGB( cRed, cGreen, cBlue ) ;
} /* tdGetShadowColor()  */


/*
 *====================================================================
 *  Internal functions
 *====================================================================
 */

/****************************************************************
 *  VOID NEAR PASCAL
 *   Draw3DLine1( HDC hDC, UINT x, UINT y, UINT uiLen, UINT uiFlags )
 *
 *  Description:
 *
 *    Does the same thing astdDraw3DLine but for single width lines.
 *
 *  Comments:
 *
 ****************************************************************/
VOID NEAR PASCAL
   Draw3DLine1( HDC hDC, UINT x, UINT y, UINT uiLen, UINT uiFlags )
{
   BOOL    fDark ;
   RECT    rc ;
   COLORREF   rgbOld ;

   if ( uiFlags & DRAW3D_TOPLINE )
   {
	  rc.left = x ;
	  rc.right = rc.left + uiLen - 1 ;
	  rc.top = y ;
	  rc.bottom = y + 1 ;

	  fDark = ( uiFlags & DRAW3D_IN ) ? TRUE : FALSE ;
   }

   /* possibly the bottom? */
   else if ( uiFlags & DRAW3D_BOTTOMLINE )
   {
	  rc.left = x ;
	  rc.right = rc.left + uiLen - 1 ;
	  rc.top = y - 1 ;
	  rc.bottom = y ;

	  fDark = ( uiFlags & DRAW3D_IN ) ? FALSE : TRUE ;
   }

   /* ok, it's gotta be left? */
   else if ( uiFlags & DRAW3D_LEFTLINE )
   {
	  rc.left = x ;
	  rc.right = x + 1 ;
	  rc.top = y ;
	  rc.bottom = y + uiLen ;

	  fDark = ( uiFlags & DRAW3D_IN ) ? TRUE : FALSE ;
   }

   /* well maybe it's for the right side? */
   else if ( uiFlags & DRAW3D_RIGHTLINE )
   {
	  rc.left = x - 1 ;
	  rc.right = x ;
	  rc.top = y ;
	  rc.bottom = y + uiLen ;

	  fDark = ( uiFlags & DRAW3D_IN ) ? FALSE : TRUE ;
   }

   /* bad drugs? */
   else return ;

   /* select the appropriate color for the fill */
   if ( fDark )
	  rgbOld = SetBkColor( hDC,
			   GetNearestColor( hDC, tdGetShadowColor( GetBkColor( hDC ) ) ) ) ;
   else
	  rgbOld = SetBkColor( hDC,
			   GetNearestColor( hDC, tdGetHighlightColor( GetBkColor( hDC ) ) ) ) ;

   /* finally, draw the dern thing */

   ExtTextOut( hDC, x, y, ETO_OPAQUE, &rc, NULL, 0, NULL ) ;

   SetBkColor( hDC, rgbOld ) ;

} /* Draw3DLine1()  */

VOID NEAR PASCAL DrawFrame( HDC hDC, LPRECT lprc )
{
   RECT    rc1 ;

   /* perform CopyRect w/o bloody windows style overhead */
   rc1 = *lprc ;

   /* top */
   rc1.top = lprc->top ;
   rc1.left = lprc->left ;
   rc1.bottom = lprc->top + 1 ;
   rc1.right = lprc->right ;

   /* blast it out */
   ExtTextOut( hDC, rc1.left, rc1.top, ETO_OPAQUE, &rc1, NULL, 0, NULL ) ;

   /* right */
   rc1.left = lprc->right - 1 ;
   rc1.bottom = lprc->bottom ;

   /* blast this part now */
   ExtTextOut( hDC, rc1.left, rc1.top, ETO_OPAQUE, &rc1, NULL, 0, NULL ) ;

   /* left */
   rc1.left = lprc->left ;
   rc1.right = lprc->left + 1 ;

   /* and another part */
   ExtTextOut( hDC, rc1.left, rc1.top, ETO_OPAQUE, &rc1, NULL, 0, NULL ) ;

   /* bottom */
   rc1.right = lprc->right ;
   rc1.top = lprc->bottom - 1 ;

   /* finish it off */
   ExtTextOut( hDC, rc1.left, rc1.top, ETO_OPAQUE, &rc1, NULL, 0, NULL ) ;

} /* DrawFaceFrame() */


/************************************************************************
 * End of File: shadow.c
 ***********************************************************************/
