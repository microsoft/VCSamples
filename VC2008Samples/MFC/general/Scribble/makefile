# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and Microsoft
# QuickHelp and/or WinHelp documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=SCRIBBLE
ROOT=..\..\..
OBJS=scribble.obj scribdoc.obj scribvw.obj mainfrm.obj childfrm.obj pendlg.obj \
	ipframe.obj scribitm.obj
USES_OLE=1

!if "$(PLATFORM)" == "M68K" || "$(PLATFORM)" == "MPPC"
MACPROJ=Scribble
MACSIG=SCRI
!endif

!if "$(PLATFORM)" == "M68K" || "$(PLATFORM)" == "MPPC"
GOAL: $(PROJ).exe $(MACSIG)mac.hlp
$(MACSIG)mac.hlp : hlp\$(MACSIG)mac.hpj resource.h 
	makehelp MAC ":$(MACNAME):$(PROJ) HELP"
!else

GOAL: $(PROJ).exe $(PROJ).hlp
$(PROJ).hlp : hlp\$(PROJ).hpj resource.h 
	makehelp
	if exist hlp\$(PROJ).hlp copy hlp\$(PROJ).hlp .

!endif

!include <mfcsamps.mak>
