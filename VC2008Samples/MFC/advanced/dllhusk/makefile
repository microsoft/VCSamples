# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

AFXDLL=1
EXTRA_LIBS=testdll1.lib testdll2.lib

goal: $(EXTRA_LIBS) testdll1.dll testdll2.dll dllhusk.exe

PROJ=DLLHUSK
OBJS=dllhusk.obj mainfrm.obj
!if "$(PLATFORM)" == "M68K" || "$(PLATFORM)" == "MPPC"
MACPROJ=DLLHusk
MACSIG=DLLH
!endif

!include <mfcsamps.mak>

clean::
	if exist *.dll erase *.dll

#############################################################################
# Common rules and values for building MFC Extension DLLs

DLL_CPPFLAGS=/D_WINDLL /D_AFXEXT /W3
DLL_LINKFLAGS=/dll
!if "$(DEBUG)" == "0"
DLL_CPPFLAGS=$(DLL_CPPFLAGS) /O1 /MD
DLL_LINKFLAGS=$(DLL_LINKFLAGS) /debug:none
!else
DLL_CPPFLAGS=$(DLL_CPPFLAGS) /D_DEBUG /Od /Z7 /MDd
DLL_LINKFLAGS=$(DLL_LINKFLAGS) /debug /debugtype:cv
!endif
!if "$(UNICODE)" != "1"
DLL_CPPFLAGS=$(DLL_CPPFLAGS) /D_MBCS
!else
DLL_CPPFLAGS=$(DLL_CPPFLAGS) /D_UNICODE
!endif
!if "$(MACOS)" == "1"
DLL_LINKFLAGS=$(DLL_LINKFLAGS) /mac:init=WlmConnectionInit
DLL_LINKFLAGS=$(DLL_LINKFLAGS) /mac:type=shlb /mac:creator=cfmg
DLL_CPPFLAGS=$(DLL_CPPFLAGS) /D_MAC
DLL_MRCFLAGS=/DARCHITECTURE=$(ARCHITECTURE)
!endif

RFLAGS=$(RFLAGS) /D_AFXDLL

#############################################################################
# Special rules for building TESTDLL1

!if "$(MACOS)" == "1"
TESTDLL1_RESOURCES=testdll1.rsc tdll1mac.rsc
!else
TESTDLL1_RESOURCES=testdll1.res
!endif

testdll1.obj: testdll1.cpp testdll1.h
	cl $(DLL_CPPFLAGS) /c testdll1.cpp

tdll1mac.rsc: testdll.r
	mrc $(DLL_MRCFLAGS) /DLIBNAME=\"testdll1.dll\" /o tdll1mac.rsc testdll.r

testdll1.dll testdll1.lib: testdll1.obj $(TESTDLL1_RESOURCES)
	link $(DLL_LINKFLAGS) /out:testdll1.dll /map:testdll1.map \
# REVIEW_ERICSC: can remove .def file once dllexport works
!if "$(MACOS)" == "1"
	/def:testdll1.def \
!endif
	/implib:testdll1.lib testdll1.obj $(TESTDLL1_RESOURCES)

#############################################################################
# Special rules for building TESTDLL2

!if "$(MACOS)" == "1"
TESTDLL2_RESOURCES=testdll2.rsc tdll2mac.rsc
!else
TESTDLL2_RESOURCES=testdll2.res
!endif

testdll2.obj: testdll2.cpp testdll2.h
	cl $(DLL_CPPFLAGS) /c testdll2.cpp

tdll2mac.rsc: testdll.r
	mrc $(DLL_MRCFLAGS) /DLIBNAME=\"testdll2.dll\" /o tdll2mac.rsc testdll.r

testdll2.dll testdll2.lib: testdll2.obj $(TESTDLL2_RESOURCES)
	link $(DLL_LINKFLAGS) /out:testdll2.dll /map:testdll2.map \
# REVIEW_ERICSC: can remove .def file once dllexport works
!if "$(MACOS)" == "1"
	/def:testdll2.def \
!endif
	/implib:testdll2.lib testdll2.obj $(TESTDLL2_RESOURCES)

#############################################################################
