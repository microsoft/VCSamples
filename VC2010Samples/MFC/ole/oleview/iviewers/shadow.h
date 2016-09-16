/*
 * These defines are used in the uiFlags and uiStyle parameters to
 * the TDUTIL functions.
 */

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#define DRAW3D_IN           0x0100     // effect looks indented
#define DRAW3D_OUT          0x0200     // effect 'sticks out'
#define DRAW3D_CREASE       0x0400     // for that 'creased' look

#define DRAW3D_TOPLINE      0x0800
#define DRAW3D_BOTTOMLINE   0x1000
#define DRAW3D_LEFTLINE     0x2000
#define DRAW3D_RIGHTLINE    0x4000

/*
 * Very useful set of macros for dealing with the 'base' 16 colors
 */
#ifndef _RGB_H_
#define _RGB_H_
   #define RGBBLACK     RGB(0,0,0)
   #define RGBRED       RGB(128,0,0)
   #define RGBGREEN     RGB(0,128,0)
   #define RGBBLUE      RGB(0,0,128)
   #define RGBBROWN     RGB(128,128,0)
   #define RGBMAGENTA   RGB(128,0,128)
   #define RGBCYAN      RGB(0,128,128)
   #define RGBLTGRAY    RGB(192,192,192)
   #define RGBGRAY      RGB(128,128,128)
   #define RGBLTRED     RGB(255,0,0)
   #define RGBLTGREEN   RGB(0,255,0)
   #define RGBLTBLUE    RGB(0,0,255)
   #define RGBYELLOW    RGB(255,255,0)
   #define RGBLTMAGENTA RGB(255,0,255)
   #define RGBLTCYAN    RGB(0,255,255)
   #define RGBWHITE     RGB(255,255,255)
#endif

/* tdDraw3DRect()
 *
 * Draws a rectangle (non-filled) that has 3D effects.
 *
 *    lprc     Defines the rectangle in client coordinates
 *    uiWidth  Specifies the width of the lines that make up the rectangle.
 *    wFlags   Either DRAW3D_IN or DRAW3D_OUT.  May be combined with
 *             DRAW3D_CREASED (uiWidth is ignored).
 */
VOID WINAPI tdDraw3DRect( HDC hdc, LPRECT lprc, UINT uiWidth, UINT wFlags );

/* tdDraw3DLine()
 *
 * Draws a component of a 3D rectangle.  The tdDraw3DRect() function uses
 * this function to draw the rectangles.  This function is optimized
 * for speed.  For one pixel wide lines it uses ExtTextOut(), for others
 * it use Polygon() ('cause line ends are not square).
 *
 *    x, y     Defines the line in client coordinates
 *    uiWidth   Specifies the width of the lines that make up the rectangle.
 *    wFlags   May be a combination of either DRAW3D_IN or DRAW3D_OUT and
 *             DRAW3D_TOP, DRAW3D_LEFT, DRAW3D_BOTTOM, or DRAW3D_RIGHT.
 */
VOID WINAPI tdDraw3DLine( HDC hdc, UINT x, UINT y, UINT nLen, UINT uiWidth, UINT wFlags );


/* tdDrawFaceFrame()
 *
 * Draws a rectangle using the current background color.  This function
 * is useful for drawing fast rectangles (it' uses ExtTextOut() for speed).
 *
 * Restrictions are that it does not do patterned lines, or fill the
 * rectangle.  But it's a great deal faster than Rectangle().
 *
 * tdDrawRect() is really a macro that calls tdDrawFaceFrame() which
 * is mis-named.
 */
#define tdDrawRect tdDrawFaceFrame
VOID WINAPI tdDrawFaceFrame( HDC hdc, LPRECT lprc, UINT uiWidth );


/* tdDraw3DCrease()
 *
 * Draws a 3D 'crease' effect using the specified rectangle.  This
 * effect is often used for 3d group boxes.  uiFlags dictates whether
 * the crease is indented (DRAW3D_IN) or sticks out (DRAW_3DOUT).
 */
VOID WINAPI tdDraw3DCrease( HDC hdc, LPRECT lprc, UINT uiFlags ) ;

/* tdGetHighlightColor()
 *
 * TDUTIL uses the concept of a normal color, highlight color, and shadow
 * color to do it's drawing.  Both the highlight color and shadow colors
 * are derived from the normal color.  This function takes a 'normal'
 * color, and returns the appropriate highlight color.
 *
 * For example if RGBLTGRAY is passed in as rgb, RGBWHITE will be returned.
 */
COLORREF WINAPI tdGetHighlightColor( COLORREF rgb ) ;

/* tdGetShadowColor()
 *
 * TDUTIL uses the concept of a normal color, highlight color, and shadow
 * color to do it's drawing.  Both the highlight color and shadow colors
 * are derived from the normal color.  This function takes a 'normal'
 * color, and returns the appropriate shadow color.
 *
 * For example if RGBLTGRAY is passed in as rgb, RGBGRAY will be returned.
 */
COLORREF WINAPI tdGetShadowColor( COLORREF rgb ) ;
