# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

!ifndef DEBUG
DEBUG=1
!endif

!if "$(DEBUG)" == "1"
all:
	nmake -f regsvr32.mak CFG="RegSvr32 - Win32 Debug"
clean:
	if exist windebug\*.* rm -f windebug\*.*
!else
all:
	nmake -f regsvr32.mak CFG="RegSvr32 - Win32 Release"
clean:
	if exist winrel\*.* rm -f winrel\*.*
!endif
