# makefile - Handy makefile for command-line use
#
# Usage:
#   nmake [options] [all|clean]
#
# Options:
#   WIN32=0     Build 16-bit version (default)
#   WIN32=1     Build 32-bit version
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

!ifndef WIN32
WIN32=1
!endif

!ifndef UNICODE
UNICODE=0
!endif

!ifndef DEBUG
DEBUG=1
!endif

!if "$(WIN32)" == "1"
!if "$(UNICODE)" == "1"
!if "$(DEBUG)" == "1"
all:
	nmake -f Localize.mak CFG="Localize - Win32 Unicode Debug" NO_EXTERNAL_DEPS="1"

clean:
	@-if exist UniDebug\*.* echo y | erase  UniDebug\*.*
!else
all:
	nmake -f Localize.mak CFG="Localize - Win32 Unicode Release" NO_EXTERNAL_DEPS="1"
clean:
	@-if exist UniRelease\*.* echo y | erase  UniRelease\*.*
!endif
!else
!if "$(DEBUG)" == "1"
all:
	nmake -f Localize.mak CFG="Localize - Win32 Debug" NO_EXTERNAL_DEPS="1"
	nmake -f Locresde.mak CFG="Locresde - Win32 Debug" NO_EXTERNAL_DEPS="1"
	nmake -f Locresfr.mak CFG="Locresfr - Win32 Debug" NO_EXTERNAL_DEPS="1"
clean:
	@-if exist Debug\. echo y | erase  Debug\*.*
!else
all:
	nmake -f Localize.mak CFG="Localize - Win32 Release" NO_EXTERNAL_DEPS="1"
	nmake -f Locresde.mak CFG="Locresde - Win32 Release" NO_EXTERNAL_DEPS="1"
	nmake -f Locresfr.mak CFG="Locresfr - Win32 Release" NO_EXTERNAL_DEPS="1"
clean:
	@-if exist Release\. echo y | erase  Release\*.*
!endif
!endif
!else
all:
	nmake -f Localize.mak DEBUG=$(DEBUG) NO_EXTERNAL_DEPS="1"
clean:
	@-if exist *.sbr erase *.sbr
	@-if exist *.pdb erase *.pdb
	@-if exist *.pch erase *.pch
	@-if exist *.obj erase *.obj
	@-if exist *.res erase *.res
	@-if exist *.dll erase *.dll
	@-if exist *.bsc erase *.bsc
	@-if exist *.lib erase *.lib
	@-if exist msvc.bnd erase msvc.bnd
	@-if exist tlb16\*.tlb erase tlb16\*.tlb
!endif
