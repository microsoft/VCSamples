# makefile - Handy makefile for command-line use
#
# Usage:
#   nmake [options] [all|clean]
#
# Options:
#   DEBUG=0     Build retail version
#   DEBUG=1     Build debug version (default)
#   UNICODE=0   Build ANSI/DBCS version (default)
#   UNICODE=1   Build Unicode version

# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

!ifndef UNICODE
UNICODE=0
!endif

!ifndef DEBUG
DEBUG=1
!endif

!if "$(UNICODE)" == "1"
!if "$(DEBUG)" == "1"
all:
		nmake -f Time.mak CFG="Time - Win32 Unicode Debug"
clean:
		@-if exist UniDebug\*.* echo y | erase UniDebug\*.*
!else
all:
		nmake -f Time.mak CFG="Time - Win32 Unicode Release"
clean:
		@-if exist UniRelease\*.* echo y | erase UniRelease\*.*
!endif
!else
!if "$(DEBUG)" == "1"
all:
		nmake -f Time.mak CFG="Time - Win32 Debug"
clean:
	@-if exist Debug\*.* echo y | erase Debug\*.*
!else
all:
		nmake -f Time.mak CFG="Time - Win32 Release"
clean:
	@-if exist Release\*.* echo y | erase Release\*.*
!endif
!endif
