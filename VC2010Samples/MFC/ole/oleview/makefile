# makefile - Handy makefile for command-line use
#
# Usage:
#   nmake [options] [all|clean]
#
# Options:
#   DEBUG=0     Build retail version
#   DEBUG=1     Build debug version (default)

# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.


PROJ=OLEVIEW
OBJS=doc.obj        mainfrm.obj    obj_vw.obj     oleview.obj    regview.obj    shadow.obj    \
	 util.obj       view.obj

USES_OLE=1
!include <mfcsamps.mak>
# Review: non standard resoure filename
#!if "$(DEBUG)" == "1"
#all:
#        nmake -f oleview.mak CFG="oleview - Win32 Debug"
#clean:
#   @-if exist Debug\*.* echo y | erase Debug\*.*
#!else
#all:
#        nmake -f oleview.mak CFG="oleview - Win32 Release"
#clean:
#   @-if exist Release\*.* echo y | erase Release\*.*
#!endif
