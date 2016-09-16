
# Script generated makefile, DONT edit.
#################################################################################################
# Check CFG. If CFG is not given, use  "Win32 Release" as the default. Otherwise make sure a 
# valid config is given.
#################################################################################################
!IF "$(CFG)" == ""
CFG=Win32 Release
!MESSAGE No configuration specified. Defaulting to Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" \
&& "$(CFG)" != "Win32 Debug" \
&& "$(CFG)" != "Win32 Unicode Debug" \
&& "$(CFG)" != "Win32 Unicode Release"

!MESSAGE Invalid configuration "$(CFG)" specified!
!MESSAGE Defaulting to Win32 Release.
CFG=Win32 Release
!ENDIF 

!IF  "$(CFG)" == "Win32 Release"
CONFIG=2
OUTDIR=.\Release
!ELSEIF "$(CFG)" == "Win32 Debug"
CONFIG=0
OUTDIR=.\Debug
!ELSEIF "$(CFG)" == "Win32 Unicode Release"
CONFIG=3
OUTDIR=.\URelease
!ELSEIF "$(CFG)" == "Win32 Unicode Debug"
CONFIG=1
OUTDIR=.\UDebug
!ENDIF
#################################################################################################
# Set the output dir and common exes.
#################################################################################################
!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
AIM=AutoClient.dll
AIMTYPE=dll
ROOTNAME=AutoClient
PREHEADER=AutoClient.pch
THEPRE=stdafx.h
FRES=$(ROOTNAME).res
FBSC=$(ROOTNAME).bsc
FPDB=$(ROOTNAME).pdb
FMAP=$(ROOTNAME).map
FLIB=$(ROOTNAME).lib
FIDL=_AutoClient.idl

!IF "$(AIMTYPE)" == "dll"
THREADTYPE=/MD
!ELSE
THREADTYPE=/MT
!ENDIF

!IF $(CONFIG) & 2
CONFI=$(THREADTYPE) /W3 /GX /O2 /D "NDEBUG"
DEBUG=NDEBUG
MT=MTd
GM=
!ELSE
CONFI=$(THREADTYPE)d /W3 /Gm /GX /ZI /Od /D "_DEBUG"
DEBUG=_DEBUG
MT=MT
GM=/Gm
!ENDIF

!IF $(CONFIG) & 1
UNICODE=_UNICODE
!ELSE
UNICODE=NOMEANING
!ENDIF

!IF $(CONFIG) == 2
MYSUFFIX=/FD /F0x0 /c
!ELSE
MYSUFFIX=/FD /c
!ENDIF

CPP_PROJ=/nologo $(CONFI) /D "$(UNICODE)" /D "_WINDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yu"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\"  $(MYSUFFIX)
CPP_SWITCHES=/nologo $(CONFI) /D "$(UNICODE)" /D "_WINDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yc"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(MYSUFFIX)
MTL_PROJ=/nologo /D "$(DEBUG)" /win32 
RSC_PROJ=/l 0x409 /fo"$(OUTDIR)\$(FRES)" /d "$(DEBUG)" 
BSC32_FLAGS=/nologo /o"$(OUTDIR)\$(FBSC)" 
BSC32_SBRS= \
#################################################################################################
# Project dependent stuff.
#################################################################################################

ALL : "$(OUTDIR)\$(AIM)" "$(OUTDIR)\regsvr32.trg"

CLEAN :
	del /F /Q $(OUTDIR)\*.* $(OUTDIR)\*
	

SOURCE=.\$(ROOTNAME).rc
"$(OUTDIR)\$(FRES)" : $(SOURCE) "$(OUTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)

	


SOURCE=.\AutoCtl.cpp
"$(OUTDIR)\AutoCtl.obj"	"$(OUTDIR)\$(PREHEADER)" : $(SOURCE) "$(OUTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


SOURCE=.\AutoClient.cpp
"$(OUTDIR)\AutoClient.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


SOURCE=.\StdAfx.cpp
"$(OUTDIR)\StdAfx.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"
    
LINK32_OBJS= \
	"$(OUTDIR)\AutoCtl.obj" \
	"$(OUTDIR)\AutoClient.res" \
	"$(OUTDIR)\AutoClient.obj" \
	"$(OUTDIR)\StdAfx.obj" 

LINK32_FLAGS=/nologo  /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\$(FPDB)" /map:"$(OUTDIR)\$(FMAP)" /machine:I386 /out:"$(OUTDIR)\$(AIM)" /implib:"$(OUTDIR)\$(FLIB)" /idlout:$(FIDL)
"$(OUTDIR)\$(AIM)" :: "$(OUTDIR)" CLEAN $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS)  $(LINK32_OBJS)
<<

TargetPath=$(OUTDIR)\$(AIM)


"$(OUTDIR)\regsvr32.trg" : "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
!IF $(CONFIG) & 1
!IF "$(AIMTYPE)" == "dll"
	regsvr32 /s /c "$(TargetPath)" 
!ELSE
	"$(TargetPath)" /RegServer
!ENDIF
!ENDIF
	echo regsvr32 exec. time > "$(OUTDIR)\regsvr32.trg" 
<< 

