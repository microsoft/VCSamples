# This is a part of the Active Template Library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Active Template Library Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Active Template Library product.

!ifndef DEBUG
DEBUG=1
!endif

TARGETNAME=AtlTraceTool8
TARGETTYPE=EXE

AFXDLL=1

RCFILE=TraceTool.rc
HELPFILE=hlp\TraceTool.hpj

!include <atlcommon.mak>

OBJS=$(D)\stdafx.obj $(D)\tracetool.obj $(D)\tracetooldlg.obj
LIBS=$(LIBS) ole32.lib oleaut32.lib advapi32.lib user32.lib gdi32.lib kernel32.lib

!include <atltarg.mak>
